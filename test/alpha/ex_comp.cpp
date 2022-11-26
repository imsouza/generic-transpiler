/**
 * Aluno: joilnen leite
 */
#define BOOST_SPIRIT_DEBUG
#include <boost/spirit/include/qi.hpp>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
using namespace boost::spirit;

template <typename Iterator, typename Skipper>
class PyToCpp : public qi::grammar<Iterator, std::vector<std::string>(), Skipper> {
    qi::rule<Iterator, std::string(), Skipper> VARIAVEL_INTEIRA;
    qi::rule<Iterator, std::string(), Skipper> ATRIBUICAO;
    qi::rule<Iterator, std::string(), Skipper> FOR_INSTRUCAO;
    qi::rule<Iterator, std::string(), Skipper> FOR_INSTRUCAO_REC;
    qi::rule<Iterator, std::string(), Skipper> IF_INSTRUCAO;
    qi::rule<Iterator, std::string(), Skipper> IF_INSTRUCAO_REC;
    qi::rule<Iterator, std::string(), Skipper> COMP_EXPRESSAO;
    qi::rule<Iterator, std::string(), Skipper> RANGE_EXPRESSAO;
    qi::rule<Iterator, std::string(), Skipper> PRINT_FUNCAO;
    qi::rule<Iterator, std::vector<std::string>(), Skipper> CODIGO;

    public:

        PyToCpp() : PyToCpp::base_type{CODIGO} {
            VARIAVEL_INTEIRA = lexeme[qi::char_ >> *qi::alnum];
            ATRIBUICAO =       VARIAVEL_INTEIRA >> lit('=') >> qi::int_ >> lit(';');
            FOR_INSTRUCAO %=   qi::string("for") >> lit('(') >> RANGE_EXPRESSAO >> ')' >> lit('{') >> *FOR_INSTRUCAO >> *ATRIBUICAO >> *FOR_INSTRUCAO || *ATRIBUICAO >> lit('}');
            RANGE_EXPRESSAO =  VARIAVEL_INTEIRA >> qi::string("in") >> qi::string("range") >> lit('(')  >> qi::int_ >> lit(')');
            IF_INSTRUCAO_REC = qi::string("if") >> lit('(') >> COMP_EXPRESSAO >> lit(')') >> lit('{') >> *ATRIBUICAO >> lit('}');
            IF_INSTRUCAO %=     qi::string("if") >> lit('(') >> COMP_EXPRESSAO >> lit(')') >> lit('{') >> *FOR_INSTRUCAO >> *IF_INSTRUCAO || *ATRIBUICAO >> lit('}');
            COMP_EXPRESSAO = (VARIAVEL_INTEIRA >> lit('<') >> qi::int_) |
                             (VARIAVEL_INTEIRA >> lit('>') >> qi::int_) |
                             (VARIAVEL_INTEIRA >> qi::string("==") >> 
                              qi::int_);
            CODIGO =         *ATRIBUICAO || *FOR_INSTRUCAO || *IF_INSTRUCAO;
        }
};

int main()
{
    std::stringstream ss;
    for (std::string s; std::getline(std::cin, s);) {
        ss << s;
    }
    cout << ss.str() << "\n";

    auto&& s = ss.str();
    auto it = s.begin();
    PyToCpp<std::string::iterator, ascii::space_type> g;
    std::vector<std::string> v;
    if (qi::phrase_parse(it, s.end(), g, ascii::space, v)) {
        for (const auto& elem : v)
            std::cout << elem << "\n";
    }
    if (it != std::end(s))
        std::cerr << "Erro em " << *it << "\n";
}

