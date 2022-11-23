/**
 * Aluno: joilnen leite
 */
#include <boost/spirit/include/qi.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stringview>

using namespace std;
using namespace boost::spirit;

class Preprocessa {
    stringstream buffer;
    stringview sv {"arquivo_intermediario_00.i"};
    Preprocessa() {}
    public:
        static Preprocessa &getSingleton() {
            static Preprocessa pp;
            return pp;
        }
        virtual ~Preprocessa() {}
        void le(istream &i) {

        }
};

template <typename Iterator, typename Skipper>
struct pytoc_grammar : qi::grammar<Iterator,
  std::vector<std::string>(), Skipper> {
    pytoc_grammar() : pytoc_grammar::base_type{codigo} {

        variavel_inteira = qi::word >> lit('=') >> qi::int_ >> lit(';');
        for_instrucao = qi::string("for") >> '(' >> range_expressao >> ')' >> '{' >> *variavel_inteira || *if_instrucao >> '}';
        range_expressao = qi::word >> qi::string("in") >> qi::string("range") >> '('  >> qi::int_ >> ')';
        if_instrucao = qi::string("if") >> '(' >> comp_expressao >> ')' >> '{' >> *variavel_inteira  >> '}';
        comp_expressao = qi::word >> '<' >> qi::int_;
        // codigo = *variavel_inteira | *if_instrucao | *for_instrucao;
        codigo = *variavel_inteira || *for_instrucao || *if_instrucao;
    }

    qi::rule<Iterator, std::string(), Skipper> variavel_inteira;
    qi::rule<Iterator, std::string(), Skipper> for_instrucao;
    qi::rule<Iterator, std::string(), Skipper> if_instrucao;
    qi::rule<Iterator, std::string(), Skipper> comp_expressao;
    qi::rule<Iterator, std::string(), Skipper> range_expressao;
    qi::rule<Iterator, std::string(), Skipper> print_funcao;
    qi::rule<Iterator, boost::variant<int, bool>(), Skipper> valor;
    qi::rule<Iterator, std::vector<std::string>(), Skipper>
        codigo;
};

int main()
{
    static Preprocessa &pp = Preprocessa::getSingleton();
    pp.le(cin);
    for (std::string s; std::getline(std::cin, s);) {
        auto it = s.begin();
        pytoc_grammar<std::string::iterator, ascii::space_type> g;
        std::vector<std::string> v;
        if (qi::phrase_parse(it, s.end(), g, ascii::space, v)) {
            for (const auto& elem : v)
                std::cout << elem << "\n";
        }
        if (it != std::end(s))
            std::cerr << "Erro em " << *it << "\n";
    }
}

