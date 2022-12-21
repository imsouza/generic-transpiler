#ifndef _TOKENS_HPP
#define _TOKENS_HPP

#include <boost/phoenix/operator.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/unordered_map.hpp>
#include <iostream>

enum TOKENS { 
  EQUAL_t,
  LT_t,
  GT_t,
  ASSIGN_t,
  SEMICOLON_t,
  LP_t,
  RP_t,
  LB_t,
  RB_t,
  QUOT_t,
  IF_t,
  ELSE_t,
  FOR_t,
  IN_t,
  RANGE_t,
  PRINT_t
};

const char* getToken[] = {
  "==",
  "<",
  ">",
  "=",
  ";",
  "(",
  ")",
  "{",
  "}",
  "\"",
  "if",
  "else",
  "for",
  "in",
  "range",
  "print"
};

#endif