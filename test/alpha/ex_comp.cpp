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

std::vector<boost::variant<int, std::string, bool>> traduzido;
ofstream ofs;
ofstream codEmCpp;

void imprimeFor(std::string &a) {
    cout << "FOR: " << a << "\n"; 
    codEmCpp << a << "\n"; 

    ofs << "<for>\n";
    ofs << a << "\n"; 
    ofs << "</for>\n";
}

void imprimeChar(const char a) {
    cout << "CH: " << a << "\n"; 
    codEmCpp << a << "\n"; 
}

void imprimeInt(const int a) {
    cout << "INT: " << a << "\n"; 
    codEmCpp << a << "\n"; 
}

void imprimeAtrib(std::string &a) {
    cout << "ATR: int " << a << "\n";
    codEmCpp << a << "\n"; 

    ofs << "<atrib>\n";
    ofs << a << "\n"; 
    ofs << "</atrib>\n";
}

void imprimeIf(std::string &a) {
    cout << "IF: " << a << "\n";
    codEmCpp << a << "\n"; 

    ofs << "<if>\n";
    ofs << a << "\n"; 
    ofs << "</if>\n";
}

void imprimeElse(std::string &a) {
    cout << "ELSE: " << a << "\n";
    codEmCpp << a << "\n"; 

    ofs << "<else>\n";
    ofs << a << "\n"; 
    ofs << "</else>\n";
}

void imprimeVar(std::string &a) {
    cout << "VAR: int " << a << "\n";
    codEmCpp << "int " << a << "\n";

    ofs << "<var>\n";
    ofs << a << "\n"; 
    ofs << "</var>\n";
}

std::string rangeTmp;
void imprimeRangeP0(std::string &a) {
    rangeTmp = a;
    cout << "int " << a << " = 0; ";
    codEmCpp << "int " << a << " = 0; ";

    ofs << "<range>\n";
    ofs << "int " << a << " = 0; ";
}

void imprimeRangeP1(int &a) {
    cout << rangeTmp << " < " << a << "; " << rangeTmp << "++";
    codEmCpp << rangeTmp << " < " << a << "; " << rangeTmp << "++";

    ofs << rangeTmp << " < " << a << "; " << rangeTmp << "++";
    ofs << "</range>\n";

    rangeTmp.clear();
}

void imprimeCompVar(std::string &a) {
    cout << "COMP: " << a << "\n";
    codEmCpp << a << "\n";

    ofs << "<comp>\n";
    ofs << a << "\n"; 
    ofs << "</comp>\n";

    a.clear();
}

void imprimePrintFunc(std::vector<char> &a) {
    stringstream ss;
    for (auto &i : a) { ss << i; }
    cout << "PRINT: " << ss.str() << " ";
    codEmCpp << "cout << \"" << ss.str() << "\";\n";

    ofs << "<print>\n";
    ofs << ss.str() << " ";
    ofs << "</print>\n";
}

void imprimePrintFuncVar(std::string &a) {
    cout << "PRINT VAR: " << a << "\n";
    codEmCpp <<  a << "\n";
}

template <typename Iterator, typename Skipper>
class PyToCpp : public qi::grammar<Iterator, std::vector<std::string>(), Skipper> {

    qi::rule<Iterator, std::string(), Skipper> VARIAVEL_INTEIRA;
    qi::rule<Iterator, std::string(), Skipper> ATRIBUICAO;
    qi::rule<Iterator, std::string(), Skipper> FOR_INSTRUCAO;
    qi::rule<Iterator, std::string(), Skipper> IF_INSTRUCAO;
    qi::rule<Iterator, std::string(), Skipper> ELSEIF_INSTRUCAO;
    qi::rule<Iterator, std::string(), Skipper> ELSE_INSTRUCAO;
    qi::rule<Iterator, std::string(), Skipper> COMP_EXPRESSAO;
    qi::rule<Iterator, std::string(), Skipper> RANGE_EXPRESSAO;
    qi::rule<Iterator, std::string(), Skipper> PRINT_FUNCAO;
    qi::rule<Iterator, std::vector<std::string>(), Skipper> CODIGO;

    public:

        PyToCpp() : PyToCpp::base_type{CODIGO} {

            /** variavel */
            VARIAVEL_INTEIRA = lexeme[qi::char_ >> *qi::alnum];

            /** atribuicao regra */
            ATRIBUICAO = (VARIAVEL_INTEIRA >> 
                qi::char_('=') >> 
                +qi::alnum >> 
                qi::char_(';'))
            ;

            /** for regra */
            FOR_INSTRUCAO =   qi::string("for")[&imprimeFor] >>
                qi::char_('(')[&imprimeChar] >>
                RANGE_EXPRESSAO >> qi::char_(')')[&imprimeChar] >>
                qi::char_('{')[&imprimeChar] >>
                *FOR_INSTRUCAO >> 
                *ATRIBUICAO[&imprimeVar] >> *FOR_INSTRUCAO |
                *ATRIBUICAO >>
                qi::char_('}')[&imprimeChar]
            ;

            /** range expressao */
            RANGE_EXPRESSAO =  VARIAVEL_INTEIRA[imprimeRangeP0] >>
                qi::string("in") >> qi::string("range") >>
                '(' >> qi::int_[imprimeRangeP1] >> ')'
            ;

            /** if regra */
            IF_INSTRUCAO %= qi::string("if")[&imprimeIf] >>
                qi::char_('(')[&imprimeChar] >>
                COMP_EXPRESSAO >>
                qi::char_(')')[&imprimeChar] >>
                qi::char_('{')[&imprimeChar] >>
                *FOR_INSTRUCAO >> *IF_INSTRUCAO |
                *ATRIBUICAO[&imprimeVar] >>
                qi::char_('}')[&imprimeChar]
            ;

            /** else if instrucao */
            ELSEIF_INSTRUCAO = qi::string("else") >>
                IF_INSTRUCAO;

            /** else instrucao */
            ELSE_INSTRUCAO = qi::string("else")[&imprimeElse] >> -qi::string("if") >>
            qi::char_('{')[&imprimeChar] 
            >> *ATRIBUICAO[&imprimeVar] >> (*ATRIBUICAO[&imprimeVar] | *FOR_INSTRUCAO | *IF_INSTRUCAO | *ELSEIF_INSTRUCAO) >>
            qi::char_('}')[&imprimeChar]
            ;
            
            /** comparacao regra */
            COMP_EXPRESSAO = (VARIAVEL_INTEIRA[&imprimeCompVar] >>
                qi::char_('<')[&imprimeChar] >>
                qi::int_[&imprimeInt]) |
                (VARIAVEL_INTEIRA[&imprimeCompVar] >>
                qi::char_('>')[&imprimeChar] >>
                qi::int_[&imprimeInt]) |
                (VARIAVEL_INTEIRA[&imprimeCompVar] >>
                qi::string("==")[&imprimeCompVar]  >> 
                qi::int_[&imprimeInt])
            ;

            /** print function */
            PRINT_FUNCAO = qi::string("print") >>
                qi::char_('(') >> qi::char_('"') >>
                (*qi::alnum)[&imprimePrintFunc] >>
                qi::char_('"') >> qi::char_(')') >> qi::char_(';')
                //     // [&imprimePrintFunc] >>
                // qi::char_('"') >> qi::char_(',') >>
                // VARIAVEL_INTEIRA /*[&imprimePrintFuncVar]*/ >>
                // qi::char_(')') >> qi::char_(';')
            ;

            /** codigo geral */
            CODIGO = *ATRIBUICAO[&imprimeVar] ||
                (*FOR_INSTRUCAO || *IF_INSTRUCAO >>
                (*ELSEIF_INSTRUCAO || *ELSE_INSTRUCAO ||
                 *PRINT_FUNCAO)) |
                (*IF_INSTRUCAO >> (*ELSEIF_INSTRUCAO ||
                *ELSE_INSTRUCAO) || *FOR_INSTRUCAO) ||
                *PRINT_FUNCAO ||
                (*IF_INSTRUCAO >> *ELSE_INSTRUCAO);
        }
};

int main()
{
    ofs.open("arvore.xml");
    codEmCpp.open("codigo_em_cpp.cpp");
    codEmCpp << "#include <iostream>\nusing namespace std;\n int main() {\n";
    ofs << "<arvore>\n";
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
    ofs << "</arvore>\n";
    codEmCpp << "\nreturn 0;\n}\n";
    codEmCpp.close();
    ofs.close();
}

