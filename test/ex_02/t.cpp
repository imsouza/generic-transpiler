#define BOOST_SPIRIT_DEBUG

#include <boost/fusion/adapted.hpp>
#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;

struct line { int x1, y1, x2, y2, color, width, capstyle, dashstyle, dashlength, dashspace; };
struct box { int x, y, width, height, color, line_width, capstyle, dashstyle, dashlength, dashspace, filltype, fillwidth, angle1, pitch1, angle2, pitch2; };
struct circle { int x, y, radius, color, line_width, capstyle, dashstyle, dashlength; };
struct text { int x, y, color, size, visibility, show_name_value, angle, alignment, num_lines;
    std::vector<std::string> lines;
};

struct composite_component;
using element_t = boost::variant<line, box, circle, text, boost::recursive_wrapper<composite_component>>;

struct element {
    // ...
    element_t element;
};

struct composite_component {
    int x;
    int y;
    std::string basename;
    std::vector<element> elements;
};

struct document { std::vector<element> elements; };

BOOST_FUSION_ADAPT_STRUCT(line, x1, y1, x2, y2, color, width, capstyle, dashstyle, dashlength, dashspace)
BOOST_FUSION_ADAPT_STRUCT(box, x, y, width, height, color, line_width, capstyle, dashstyle, dashlength, dashspace, filltype, fillwidth, angle1, pitch1, angle2, pitch2)
BOOST_FUSION_ADAPT_STRUCT(circle, x, y, radius, color, line_width, capstyle, dashstyle, dashlength)
BOOST_FUSION_ADAPT_STRUCT(text, x, y, color, size, visibility, show_name_value, angle, alignment, num_lines, lines)
BOOST_FUSION_ADAPT_STRUCT(composite_component, x, y, basename, elements)
BOOST_FUSION_ADAPT_STRUCT(element, element)
BOOST_FUSION_ADAPT_STRUCT(document, elements)

template <typename Iterator>
struct document_parser : qi::grammar<Iterator, document()> {
    document_parser() : document_parser::base_type{start_}
    {
        using namespace qi;

        line_              = 'L' >> auto_;
        box_               = 'B' >> auto_;
        circle_            = 'S' >> auto_;
        // text            = 'T' >> ...;
        element_           = (line_ | box_ | circle_ | composite_element_) >> eol;
        elements_          = -skip(space) [ '[' >> skip(blank) [*element_] >> ']' ];
        composite_element_ = 'C' >> int_ >> int_ >> lexeme[+graph] >> elements_;
        document_          = +element_ >> eoi;
        start_ = skip(blank) [ document_ ];
        BOOST_SPIRIT_DEBUG_NODES((document_)(element_)(composite_element_)(elements_)(line_)(box_)(circle_));
    }
  private:
    qi::rule<Iterator, document()> start_;
    qi::rule<Iterator, document(),             qi::blank_type> document_;
    qi::rule<Iterator, element(),              qi::blank_type> element_;
    qi::rule<Iterator, line(),                 qi::blank_type> line_;
    qi::rule<Iterator, box(),                  qi::blank_type> box_;
    qi::rule<Iterator, circle(),               qi::blank_type> circle_;
    qi::rule<Iterator, composite_component(),  qi::blank_type> composite_element_;
    qi::rule<Iterator, std::vector<element>(), qi::blank_type> elements_;
};

int main(int, char **)
{
    document_parser<std::string::const_iterator> parser;
    const std::string text = "L 1 2 3 4 5 6 7 8 9\n"
        "C 10 10 FOO\n"
        "[\n"
        "L 10 20 30 40 50 60 70 80 90 100\n]";
    document doc;
    auto r = qi::parse(std::cbegin(text), std::cend(text), parser, doc);
    std::cout << r ? "OK\n" : "FALHA\n";

    return 0;
}

