#ifndef SCANNER_H
#define SCANNER_H

#if !defined(yyFlexLexerOnce)
#undef yyFlexLexer
#define yyFlexLexer                                                            \
  JsonPath_FlexLexer // the trick with prefix; no namespace here :(
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL                                                                \
  JsonPath::Parser::symbol_type JsonPath::Scanner::get_next_token()

#include "parser.hpp" // this is needed for symbol_type

namespace JsonPath {

class Interpreter;

class Scanner : public yyFlexLexer {
public:
  Scanner(Interpreter &driver) : m_driver(driver) {}
  virtual ~Scanner() {}
  virtual JsonPath::Parser::symbol_type get_next_token();

private:
  Interpreter &m_driver;
};

} // namespace JsonPath

#endif