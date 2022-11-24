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
            FOR_INSTRUCAO_REC =    qi::string("for") >> '(' >> RANGE_EXPRESSAO >> ')' >> '{' >> *ATRIBUICAO >> '}';
            FOR_INSTRUCAO =    qi::string("for") >> '(' >> RANGE_EXPRESSAO >> ')' >> '{' >> *ATRIBUICAO >> '}';
            RANGE_EXPRESSAO = VARIAVEL_INTEIRA >> qi::string("in") >> qi::string("range") >> '('  >> qi::int_ >> ')';
            IF_INSTRUCAO_REC = qi::string("if") >> '(' >> COMP_EXPRESSAO >> ')' >> '{' >> *ATRIBUICAO >> '}';
            IF_INSTRUCAO =     qi::string("if") >> '(' >> COMP_EXPRESSAO >> ')' >> '{' >> *IF_INSTRUCAO_REC || *ATRIBUICAO >> '}';
            COMP_EXPRESSAO = (VARIAVEL_INTEIRA >> '<' >> qi::int_) |
                             (VARIAVEL_INTEIRA >> '>' >> qi::int_) |
                             (VARIAVEL_INTEIRA >> qi::string("==") >> 
                              qi::int_);
            CODIGO =        *ATRIBUICAO || *FOR_INSTRUCAO || *IF_INSTRUCAO;
        }
};

int main()
{
    for (std::string s; std::getline(std::cin, s);) {
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
}

