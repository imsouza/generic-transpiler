#define BOOST_SPIRIT_DEBUG
#include <boost/fusion/adapted.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/karma.hpp>
// #include <boost/spirit/include/phoenix.hpp>

namespace qi    = boost::spirit::qi;
namespace karma = boost::spirit::karma;
namespace phx   = boost::phoenix;

typedef boost::variant<int, std::string> Value;
typedef std::pair<Value, Value> Range;
typedef std::pair<std::string, Range> Iteration;

typedef Iteration attr_t;

template <typename It, typename Skipper = qi::space_type>
    struct parser : qi::grammar<It, attr_t(), Skipper>
{
    parser() : parser::base_type(start)
    {
        using namespace qi;

        genericString %= lexeme[+(char_("a-zA-Z"))];// variable e.g. c
        intRule %= int_;
        commandString %= lexeme[*(char_ - '}')];
        value = intRule | genericString;
        range = value >> ':' >> value;
        forLoop %= lit("for")
                >> '(' >> genericString >> '=' >> range >> ')' 
                >> '{'
                >>      (forLoop | commandString)
                >> '}';

        start = forLoop;

        BOOST_SPIRIT_DEBUG_NODES(
                (start)(intRule)(genericString)(commandString)(forLoop)(value)(range)
                 );
    }

  private:
    qi::rule<It, std::string(), Skipper> genericString, commandString;
    qi::rule<It, int(), Skipper> intRule;
    qi::rule<It, Value(), Skipper> value;
    qi::rule<It, Range(), Skipper> range;
    qi::rule<It, attr_t(), Skipper> forLoop, start;
};

bool doParse(const std::string& input)
{
    typedef std::string::const_iterator It;
    auto f(begin(input)), l(end(input));

    parser<It, qi::space_type> p;
    attr_t data;

    try
    {
        bool ok = qi::phrase_parse(f,l,p,qi::space,data);
        if (ok)   
        {
            std::cout << "parse success\n";
        }
        else      std::cerr << "parse failed: '" << std::string(f,l) << "'\n";

        if (f!=l) std::cerr << "trailing unparsed: '" << std::string(f,l) << "'\n";
        return ok;
    } catch(const qi::expectation_failure<It>& e)
    {
        std::string frag(e.first, e.last);
        std::cerr << e.what() << "'" << frag << "'\n";
    }

    return false;
}

int main()
{
    bool ok = doParse(
            "for(loop = 1:10) {\n"
            "   for(inner = 1:10) {\n"
            "   }\n"
            "}"
            );
    return ok? 0 : 255;
}
