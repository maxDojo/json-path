%{
	#include <iostream>
	#include <cstdlib>
	#include "scanner.h"
	#include "interpreter.h"
	#include "parser.hpp"
	#include "location.hh"

	using namespace std;

	#define yyterminate() JsonPath::Parser::make_END(JsonPath::location());

	#define YY_USER_ACTION m_driver.increaseLocation(yyleng);
%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="Scanner"
%option prefix="JsonPath_"

%%


[A-Za-z_][A-Za-z0-9_ ]+      { 
                // cout << "Scanner: identifier [" << yytext << "]" << endl;
                return JsonPath::Parser::make_IDENTIFIER(yytext, JsonPath::location( /* put location data here if you want */ )); 
            }
["].+["]    { 
                string content (yytext);
                content.erase(0, 1);
                content.erase(content.size() - 1);
                // cout << "Scanner: identifier [" << content << "]" << endl;
                return JsonPath::Parser::make_IDENTIFIER(content.c_str(), JsonPath::location()); 
            }
            
\(          {
                // cout << "Scanner: '('" << endl;
                return JsonPath::Parser::make_LP(JsonPath::location());
            }
            
\)          { 
                // cout << "Scanner: ')'" << endl;
                return JsonPath::Parser::make_RP(JsonPath::location());
            }

\?\(         { 
                // cout << "Scanner: '(?'" << endl;
                return JsonPath::Parser::make_LPF(JsonPath::location());
            }
            
\[          {
                // cout << "Scanner: '['" << endl;
                return JsonPath::Parser::make_LSB(JsonPath::location());
            }
            
\]          { 
                // cout << "Scanner: ']'" << endl;
                return JsonPath::Parser::make_RSB(JsonPath::location());
            }

@.          {
                // cout << "Scanner: '@.'" << endl;
                return JsonPath::Parser::make_CURR_DIR(JsonPath::location());
            }

,           {
                // cout << "Scanner: ','" << endl;
                return JsonPath::Parser::make_COMMA(JsonPath::location());
            }

:           {
                // cout << "Scanner: ':'" << endl;
                return JsonPath::Parser::make_COLON(JsonPath::location());
            }

\*          {
                // cout << "Scanner: '*'" << endl;
                return JsonPath::Parser::make_AST(JsonPath::location());
            }
            
\>           { 
                // cout << "Scanner: '>'" << endl;
                return JsonPath::Parser::make_GT(yytext, JsonPath::location());
            }
            
\<           { 
                // cout << "Scanner: '<'" << endl;
                return JsonPath::Parser::make_LT(yytext, JsonPath::location());
            }

\-           {
                // cout << "Scanner: '-'" << endl;
                return JsonPath::Parser::make_SUB(yytext, JsonPath::location());
            }

[\n\t ]     {
                //cout << "Scanner: whitechar (ignored)" << endl;
            }

[0-9]+ {
                // cout << "Scanner: decimal number: " << yytext << endl;
                // uint64_t number = strtoull(yytext, 0, 10);
                return JsonPath::Parser::make_INDEX(yytext, JsonPath::location());
            }

\.          {
                return JsonPath::Parser::make_DOT(JsonPath::location());
            }

\$        {
                return JsonPath::Parser::make_START(JsonPath::location());
            }

.           { 
                // cout << "Scanner: unknown character [" << yytext << "]" << endl; 
            }
            
<<EOF>>     { return yyterminate(); }


%%
