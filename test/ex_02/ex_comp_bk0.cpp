/**
 * Aluno: joilnen leite
 */
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
struct Preprocess : qi::grammar<Iterator, std::vector<std::string>(), Skipper> {
    Preprocess() : Preprocess::base_type{codigo} {
        for_instrucao = qi::string("for");
        if_instrucao = qi::string("if");
        while_instrucao = qi::string("while");
        // codigo = *variavel_inteira | *if_instrucao | *for_instrucao;
        codigo = *for_instrucao || *if_instrucao || *while_instrucao;
    }

    qi::rule<Iterator, std::string(), Skipper> for_instrucao;
    qi::rule<Iterator, std::string(), Skipper> if_instrucao;
    qi::rule<Iterator, std::string(), Skipper> while_instrucao;
    qi::rule<Iterator, std::vector<std::string>(), Skipper> codigo;
};

template <typename Iterator, typename Skipper>
struct pytoc_grammar : qi::grammar<Iterator,
  std::vector<std::string>(), Skipper> {
    pytoc_grammar() : pytoc_grammar::base_type{codigo} {
        variavel_inteira = lexeme[qi::char_ >> *qi::alnum];
        atribuicao =  variavel_inteira >> lit('=') >> qi::int_ >> lit(';');
        for_instrucao = qi::string("for") >> '(' >> range_expressao >> ')' >> '{' >> *atribuicao || *if_instrucao >> '}';
        range_expressao = variavel_inteira >> qi::string("in") >> qi::string("range") >> '('  >> qi::int_ >> ')';
        if_instrucao = qi::string("if") >> '(' >> comp_expressao >> ')' >> '{' >> *atribuicao  >> '}';
        comp_expressao = variavel_inteira >> '<' >> qi::int_;
        // codigo = *variavel_inteira | *if_instrucao | *for_instrucao;
        codigo = *atribuicao || *for_instrucao || *if_instrucao;
    }

    qi::rule<Iterator, std::string(), Skipper> variavel_inteira;
    qi::rule<Iterator, std::string(), Skipper> atribuicao;
    qi::rule<Iterator, std::string(), Skipper> for_instrucao;
    qi::rule<Iterator, std::string(), Skipper> if_instrucao;
    qi::rule<Iterator, std::string(), Skipper> comp_expressao;
    qi::rule<Iterator, std::string(), Skipper> range_expressao;
    qi::rule<Iterator, std::string(), Skipper> print_funcao;
    qi::rule<Iterator, std::vector<std::string>(), Skipper> codigo;
};

int main()
{
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
