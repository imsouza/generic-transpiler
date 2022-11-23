#include <boost/spirit/include/qi.hpp>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <fstream>

#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

using namespace std;
using namespace boost::spirit;

template <typename Iterator, typename Skipper>
struct Preprocess : qi::grammar<Iterator, std::vector<std::string>(), Skipper> {
	Preprocess() : Preprocess::base_type{CODE} {
		FOR 	= qi::string("for");
		IF 		= qi::string("if");
		WHILE = qi::string("while");
		CODE 	= *FOR || *IF || *WHILE;
	}

	qi::rule<Iterator, std::string(), Skipper> FOR;
	qi::rule<Iterator, std::string(), Skipper> IF;
	qi::rule<Iterator, std::string(), Skipper> WHILE;
	qi::rule<Iterator, std::vector<std::string>(), Skipper> CODE;
};


template <typename Iterator, typename Skipper>
struct pytoc_grammar : qi::grammar<Iterator, std::vector<std::string>(), Skipper> {
	pytoc_grammar() : pytoc_grammar::base_type{CODE} {
		INTEGER = lexeme[qi::char_ >> *qi::alnum] >> lit('=') >> qi::int_ >> lit(';');
		FOR 		= qi::string("for") >> '(' >> RANGE >> ')' >> '{' >> *INTEGER || *IF >> '}';
		RANGE 	= qi::word >> qi::string("in") >> qi::string("range") >> '('  >> qi::int_ >> ')';
		IF 			= qi::string("if") >> '(' >> EXPR >> ')' >> '{' >> *INTEGER  >> '}';
		EXPR 		= qi::word >> '<' >> qi::int_;
		CODE 		= *INTEGER || *FOR || *IF;
	}

	qi::rule<Iterator, std::string(), Skipper> INTEGER;
	qi::rule<Iterator, std::string(), Skipper> FOR;
	qi::rule<Iterator, std::string(), Skipper> IF;
	qi::rule<Iterator, std::string(), Skipper> EXPR;
	qi::rule<Iterator, std::string(), Skipper> RANGE;
	qi::rule<Iterator, std::string(), Skipper> PRINT;
	qi::rule<Iterator, boost::variant<int, bool>(), Skipper> VALUE;
	qi::rule<Iterator, std::vector<std::string>(), Skipper> CODE;
};


int main() {
	if (system("CLS")) system("clear");

	std::cout << "------------ INPUT CODE ------------\n";

	for (std::string s; std::getline(std::cin, s);) {
		auto it = s.begin();
		pytoc_grammar<std::string::iterator, ascii::space_type> g;
		std::vector<std::string> v;

		if (qi::phrase_parse(it, s.end(), g, ascii::space, v)) {
			for (const auto& elem : v) {
				std::cout << elem << "\n";
			}
		}

		if (s == "qt") {
			exit(0);
		}

		if (it != std::end(s)) {
			std::cerr << "[!] Error in " << *it << "\n";
		}
	}

	return EXIT_SUCCESS;
}

