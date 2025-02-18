%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"
%defines
%define api.parser.class { Parser }

%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define api.namespace { JsonPath }
%code requires
{
    #include <iostream>
    #include <string>
    #include <vector>
    #include <stdint.h>
    #include "command.h"

    using namespace std;

    namespace JsonPath {
        class Scanner;
        class Interpreter;
    }
}

// Bison calls yylex() function that must be provided by us to suck tokens
// from the scanner. This block will be placed at the beginning of IMPLEMENTATION file (cpp).
// We define this function here (function! not method).
// This function is called only inside Bison, so we make it static to limit symbol visibility for the linker
// to avoid potential linking conflicts.
%code top
{
    #include <iostream>
    #include "scanner.h"
    #include "parser.hpp"
    #include "interpreter.h"
    #include "location.hh"
    
    // yylex() arguments are defined in parser.y
    static JsonPath::Parser::symbol_type yylex(JsonPath::Scanner &scanner, JsonPath::Interpreter &driver) {
        return scanner.get_next_token();
    }
    
    // you can accomplish the same thing by inlining the code using preprocessor
    // x and y are same as in above static function
    // #define yylex(x, y) scanner.get_next_token()
    
    using namespace JsonPath;

}

%lex-param { JsonPath::Scanner &scanner }
%lex-param { JsonPath::Interpreter &driver }
%parse-param { JsonPath::Scanner &scanner }
%parse-param { JsonPath::Interpreter &driver }
%locations
%define parse.trace
%define parse.error verbose

%define api.token.prefix {TOKEN_}

%token END 0 "end of file"
%token <std::string> IDENTIFIER  "string" INDEX "number" GT ">" LT "<" SUB "-";
%token LP "left par" RP "right par";
%token LSB "left square brac" RSB "right square brac";
%token DOT "dot";
%token START "start";
%token COMMA "commma";
%token COLON "colon";
%token AST "*" LPF "filter parenthesis" CURR_DIR "current directory (@.)";

%type< JsonPath::Command > body path selector filter csv query squery sfilter;
%type<std::string> op;


%start program

%%

program: {
    driver.switchInputStream(driver._jsonpath);
        driver.clear();
    }
    | program jsonpath_exp {
        // driver.showCommands();
        driver.evaluate();
    }
    | program END
    ;

jsonpath_exp: 
    | START
    | START body
    | body;

body:
    |   path { driver.addCommand($1); }
    |   selector { driver.addCommand($1); }
    |   body path   {
                        driver.addCommand($1);
                        driver.addCommand($2);
                    }
    |   body selector   {
                            driver.addCommand($1);
                            driver.addCommand($2);
                        }
    ;

path:
    IDENTIFIER              {
                                std::vector<string> arguments {$1};
                                $$ = Command(0, arguments);
                            }
    | DOT IDENTIFIER        {
                                std::vector<string> arguments {$2};
                                $$ = Command(0, arguments);
                            }
    | DOT AST               {
                                vector<string> arguments;
                                $$ = Command (9, arguments);
                            }
    | path DOT IDENTIFIER   {
                                Command cmd = $1;
                                if (cmd.id() == 0) {
                                cmd.addArg($3);
                                $$ = cmd;
                                } else {
                                    vector<string> arguments {$3};
                                    $$ = Command(0, arguments);
                                }
                            }
    | path DOT selector     {
                                driver.addCommand($1);
                                $$ = $3;}
    ;
    
selector: 
    | LSB IDENTIFIER RSB    {
                                int id = 10;
                                std::vector<string> arguments {$2};
                                $$ = Command(id, arguments);
                            }
    | LSB INDEX RSB         {
                                int id = 11;
                                std::vector<string> arguments {$2};
                                $$ = Command(id, arguments);
                            }
    | LSB csv RSB           {
                                $$ = $2;
                            }
    | LSB COLON INDEX RSB   {
                                vector<string> arguments {$3};
                                $$ = Command(13, arguments);
                            }
    | LSB AST RSB           {
                                vector<string> arguments;
                                $$ = Command (19, arguments);
                            }
    | LSB RSB               {
                                vector<string> arguments;
                                $$ = Command (19, arguments);
                            }
    | LSB filter RSB        {$$ = $2;}
    | LSB sfilter RSB       {$$ = $2;}
    ;

csv: IDENTIFIER COMMA IDENTIFIER    {
        std::vector <string> arguments {$1, $3};
        $$ = Command(12, arguments);
    }
    | INDEX COMMA INDEX {
        vector<string> arguments {$1, $3};
        $$ = Command(14, arguments);
    }
    | csv COMMA INDEX {
        Command cmd = $1;
        cmd.addArg($3);
        $$ = cmd;
    }
    | csv COMMA IDENTIFIER {
        Command cmd = $1;
        cmd.addArg($3);
        $$ = cmd;
    }

filter: LP query RP {
        $$ = $2;
    }
    ;

sfilter: LPF squery RP {
        $$ = $2;
    }

squery: CURR_DIR IDENTIFIER {
        vector<string> arguments {$2};
        $$ = Command (20, arguments);
    }
    | squery op INDEX {
        Command cmd = $1;
        cmd.addArg($2);
        cmd.addArg($3);
        $$ = cmd;
    }
    ;

query: CURR_DIR IDENTIFIER {
        vector<string> arguments {$2};
        $$ = Command (30, arguments);
    }
    | query op INDEX {
        Command cmd = $1;
        cmd.addArg($2);
        cmd.addArg($3);
        $$ = cmd;
    }
    ;

op: SUB { $$ = $1; }
    | GT { $$ = $1; }
    | LT { $$ = $1; }
    ;

%%

// Bison expects us to provide implementation - otherwise linker complains
void JsonPath::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
	
        /* cout << "Error: " << message << endl << "Error location: " << driver.location() << endl; */
}
