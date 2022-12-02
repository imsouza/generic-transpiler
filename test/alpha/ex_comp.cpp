/**
 * Aluno: joilnen leite
 */
#define BOOST_SPIRIT_DEBUG
#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
using namespace boost::spirit;
namespace qi = boost::spirit::qi;
namespace phoenix = boost::phoenix;

using phoenix::ref;

std::vector<boost::variant<int, std::string, bool>> traduzido;

void addToOutput(boost::variant<int, std::string, bool> &t) {
    traduzido.emplace_back(t);
}

void imprimeFor(std::string &a) {
    cout << "FOR: " << a << "\n"; 
}

void imprimeChar(const char a) {
    cout << "CH: " << a << "\n"; 
}

void imprimeInt(const int a) {
    cout << "INT: " << a << "\n"; 
}

void imprimeAtrib(std::string &a) {
    cout << "ATR: int " << a << "\n";
}

void imprimeIf(std::string &a) {
    cout << "IF: " << a << "\n";
}

void imprimeVar(std::string &a) {
    cout << "VAR: int " << a << "\n";
}

std::string rangeTmp;
void imprimeRangeP0(std::string &a) {
    rangeTmp = a;
    cout << "int " << a << " = 0; ";
}

void imprimeRangeP1(int &a) {
    cout << rangeTmp << " < " << a << "; " << rangeTmp << "++";
}

template <typename Iterator, typename Skipper>
class PyToCpp : public qi::grammar<Iterator, std::vector<std::string>(), Skipper> {

    qi::rule<Iterator, std::string(), Skipper> VARIAVEL_INTEIRA;
    qi::rule<Iterator, std::string(), Skipper> ATRIBUICAO;
    qi::rule<Iterator, std::string(), Skipper> FOR_INSTRUCAO;
    qi::rule<Iterator, std::string(), Skipper> IF_INSTRUCAO;
    qi::rule<Iterator, std::string(), Skipper> COMP_EXPRESSAO;
    qi::rule<Iterator, std::string(), Skipper> RANGE_EXPRESSAO;
    qi::rule<Iterator, std::string(), Skipper> PRINT_FUNCAO;
    qi::rule<Iterator, std::vector<std::string>(), Skipper> CODIGO;

    public:

        PyToCpp() : PyToCpp::base_type{CODIGO} {

            VARIAVEL_INTEIRA = lexeme[qi::char_ >> *qi::alnum];

            /** atribuicao regra */
            ATRIBUICAO = (VARIAVEL_INTEIRA >> 
                    qi::char_('=') >> 
                    qi::alnum >> 
                    qi::char_(';'));

            /** for regra */
            FOR_INSTRUCAO %=   qi::string("for")[&imprimeFor] >>
                qi::char_('(')[&imprimeChar] >>
                RANGE_EXPRESSAO >> qi::char_(')')[&imprimeChar] >>
                qi::char_('{')[&imprimeChar] >>
                *FOR_INSTRUCAO >> *ATRIBUICAO >> *FOR_INSTRUCAO || *ATRIBUICAO >>
                qi::char_('}')[&imprimeChar];

            RANGE_EXPRESSAO =  VARIAVEL_INTEIRA[imprimeRangeP0] >>
                qi::string("in") >> qi::string("range") >>
                '(' >> qi::int_[imprimeRangeP1] >> ')';

            /** if regra */
            IF_INSTRUCAO %= qi::string("if")[&imprimeIf] >>
                qi::char_('(')[&imprimeChar] >>
                COMP_EXPRESSAO >>
                qi::char_(')')[&imprimeChar] >>
                qi::char_('{')[&imprimeChar] >>
                *FOR_INSTRUCAO >> *IF_INSTRUCAO || *ATRIBUICAO >>
                qi::char_('}')[&imprimeChar];

            /** comparacao regra */
            COMP_EXPRESSAO = (VARIAVEL_INTEIRA >> lit('<') >> qi::int_) |
                             (VARIAVEL_INTEIRA >> lit('>') >> qi::int_) |
                             (VARIAVEL_INTEIRA >> qi::string("==") >> 
                              qi::int_);

            CODIGO = *ATRIBUICAO[&imprimeVar] ||
                     (*FOR_INSTRUCAO || *IF_INSTRUCAO) ||
                     (*IF_INSTRUCAO || *FOR_INSTRUCAO);
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

