#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <fstream>

#include "../headers/generic.hpp"
#include "../headers/tokens.hpp"
#include "../headers/xml.hpp"

using namespace std;
using namespace boost::spirit;
namespace qi = boost::spirit::qi;

ofstream ofs;
ofstream codeInCpp;
std::string rangeTmp;

void 
displayFor(std::string &a) {
  cout << "FOR: " << a << "\n"; 
  codeInCpp << a << "\n"; 
  ofs << "<for>\n";
  ofs << a << "\n"; 
  ofs << "</for>\n";
}


void 
displayChar(const char a) {
  cout << "CH: " << a << "\n"; 
  codeInCpp << a << "\n"; 
}


void 
displayInt(const int a) {
  cout << "INT: " << a << "\n"; 
  codeInCpp << a << "\n"; 
}


void 
displayAtrib(std::string &a) {
  cout << "ATR: int " << a << "\n";
  codeInCpp << a << "\n"; 
  ofs << "<atrib>\n";
  ofs << a << "\n"; 
  ofs << "</atrib>\n";
}


void 
displayIf(std::string &a) {
  cout << "IF: " << a << "\n";
  codeInCpp << a << "\n"; 
  ofs << "<if>\n";
  ofs << a << "\n"; 
  ofs << "</if>\n";
}


void 
displayElse(std::string &a) {
  cout << "ELSE: " << a << "\n";
  codeInCpp << a << "\n"; 
  ofs << "<else>\n";
  ofs << a << "\n"; 
  ofs << "</else>\n";
}


void 
displayVar(std::string &a) {
  cout << "VAR: int " << a << "\n";
  codeInCpp << "int " << a << "\n";
  ofs << "<var>\n";
  ofs << a << "\n"; 
  ofs << "</var>\n";
}


void 
displayRangeP0(std::string &a) {
  rangeTmp = a;
  cout << "int " << a << " = 0; ";
  codeInCpp << "int " << a << " = 0; ";
  ofs << "<range>\n";
  ofs << "int " << a << " = 0; ";
}


void 
displayRangeP1(int &a) {
  cout << rangeTmp << " < " << a << "; " << rangeTmp << "++";
  codeInCpp << rangeTmp << " < " << a << "; " << rangeTmp << "++";
  ofs << rangeTmp << " < " << a << "; " << rangeTmp << "++";
  ofs << "</range>\n";
  rangeTmp.clear();
}


void 
displayCompVar(std::string &a) {
  cout << "COMP: " << a << "\n";
  codeInCpp << a << "\n";
  ofs << "<comp>\n";
  ofs << a << "\n"; 
  ofs << "</comp>\n";
  a.clear();
}


void 
displayPrintFunc(std::vector<char> &a) {
  stringstream ss;
  for (auto &i : a) { ss << i; }
  cout << "PRINT: " << ss.str() << " ";
  codeInCpp << "cout << \"" << ss.str() << "\";\n";
  ofs << "<print>\n";
  ofs << ss.str() << " ";
  ofs << "</print>\n";
}


void 
displayPrintFuncVar(std::string &a) {
  cout << "PRINT VAR: " << a << "\n";
  codeInCpp <<  a << "\n";
}


int
main() {
  ofs.open("../tree/tree.xml");
  codeInCpp.open("../output/output.cpp");
  codeInCpp << "#include <iostream>\nusing namespace std;\n int main() {\n";
  ofs << "<tree>\n";

  std::stringstream ss;

  for (std::string s; std::getline(std::cin, s);) {
      ss << s;
  }

  cout << ss.str() << "\n";

  auto&& s = ss.str();
  auto it = s.begin();

  GnToCpp<std::string::iterator, ascii::space_type> g;
  std::vector<std::string> v;

  if (qi::phrase_parse(it, s.end(), g, ascii::space, v)) {
    for (const auto& elem : v)
      std::cout << elem << "\n";
  }

  if (it != std::end(s))
    std::cerr << "[!] Error in " << *it << "\n";

  ofs << "</tree>\n";
  codeInCpp << "\nreturn 0;\n}\n";
  codeInCpp.close();
  ofs.close();

  return EXIT_SUCCESS;
}
