#ifndef GENERIC_HPP
#define GENERIC_HPP

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

#include "../headers/xml.hpp"
#include "../headers/tokens.hpp"

using namespace std;
using namespace boost::spirit;
namespace qi = boost::spirit::qi;

template <typename Iterator, typename Skipper>
class GnToCpp : public qi::grammar<Iterator, std::vector<std::string>(), Skipper> {
  qi::rule<Iterator, std::string(), Skipper> INTEGER;
  qi::rule<Iterator, std::string(), Skipper> ASSIGNMENT;
  qi::rule<Iterator, std::string(), Skipper> FOR;
  qi::rule<Iterator, std::string(), Skipper> IF;
  qi::rule<Iterator, std::string(), Skipper> ELSEIF;
  qi::rule<Iterator, std::string(), Skipper> ELSE;
  qi::rule<Iterator, std::string(), Skipper> COMPARISON;
  qi::rule<Iterator, std::string(), Skipper> EXPRESSION;
  qi::rule<Iterator, std::string(), Skipper> PRINT;
  qi::rule<Iterator, std::vector<std::string>(), Skipper> CODE;

  public:
    GnToCpp() : GnToCpp::base_type{CODE} {
      INTEGER = lexeme[qi::char_ >> *qi::alnum];

      ASSIGNMENT = (INTEGER 
      >> qi::char_(getToken[ASSIGN_t]) 
      >> +qi::alnum 
      >> qi::char_(getToken[SEMICOLON_t]))
      ;


      FOR = qi::string(getToken[FOR_t])[&displayFor] 
      >> qi::char_(getToken[LP_t])[&displayChar] 
      >> EXPRESSION 
      >> qi::char_(getToken[RP_t])[&displayChar] 
      >> qi::char_(getToken[LB_t])[&displayChar] 
      >> *FOR 
      >> *ASSIGNMENT[&displayVar] 
      >> *FOR 
      |  *ASSIGNMENT 
      >> qi::char_(getToken[RB_t])[&displayChar]
      ;


      EXPRESSION = INTEGER[displayRangeP0] 
      >> qi::string(getToken[IN_t]) 
      >> qi::string(getToken[RANGE_t]) 
      >> getToken[LP_t]
      >> qi::int_[displayRangeP1] 
      >> getToken[RP_t]
      ;


      IF %= qi::string(getToken[IF_t])[&displayIf] 
      >> qi::char_(getToken[LP_t])[&displayChar] 
      >> COMPARISON 
      >> qi::char_(getToken[RP_t])[&displayChar] 
      >> qi::char_(getToken[LB_t])[&displayChar] 
      >> *FOR 
      >> *IF 
      |  *ASSIGNMENT[&displayVar] 
      >> qi::char_(getToken[RB_t])[&displayChar]
      ;

    
      ELSEIF = qi::string(getToken[ELSE_t]) 
      >> IF
      ;

      
      ELSE = qi::string(getToken[ELSE_t])[&displayElse] 
      >> -qi::string(getToken[IF_t]) 
      >> qi::char_(getToken[LB_t])[&displayChar] 
      >> *ASSIGNMENT[&displayVar] 
      >> (*ASSIGNMENT[&displayVar] 
      | *FOR 
      | *IF 
      | *ELSEIF) 
      >> qi::char_(getToken[RB_t])[&displayChar]
      ;
      
      
      COMPARISON = (INTEGER[&displayCompVar] 
      >> qi::char_(getToken[LT_t])[&displayChar] 
      >> qi::int_[&displayInt]) 
      | (INTEGER[&displayCompVar] 
      >> qi::char_(getToken[GT_t])[&displayChar] 
      >> qi::int_[&displayInt]) 
      | (INTEGER[&displayCompVar] 
      >> qi::string(getToken[EQUAL_t])[&displayCompVar]  
      >> qi::int_[&displayInt])
      ;

      
      PRINT = qi::string(getToken[PRINT_t]) 
      >> qi::char_(getToken[LP_t]) 
      >> qi::char_(getToken[QUOT_t]) 
      >> (*qi::alnum)[&displayPrintFunc] 
      >> qi::char_(getToken[QUOT_t]) 
      >> qi::char_(getToken[RP_t]) 
      >> qi::char_(getToken[SEMICOLON_t])
      ;

      
      CODE = *ASSIGNMENT[&displayVar] 
      || (*FOR 
      || *IF 
      >> (*ELSEIF 
      || *ELSE 
      || *PRINT)) 
      | (*IF 
      >> (*ELSEIF 
      || *ELSE) 
      || *FOR) 
      || *PRINT 
      || (*IF 
      >> *ELSE)
      ;
    }
};

#endif