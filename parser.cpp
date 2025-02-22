// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

// "%code top" blocks.
#line 32 "parser.y"

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


#line 58 "parser.cpp"




#include "parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 9 "parser.y"
namespace  JsonPath  {
#line 157 "parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
   Parser :: Parser  (JsonPath::Scanner &scanner_yyarg, JsonPath::Interpreter &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_number_type
   Parser ::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 22: // body
      case 23: // path
      case 24: // selector
      case 25: // csv
      case 26: // filter
      case 27: // sfilter
      case 28: // squery
      case 29: // query
        value.YY_MOVE_OR_COPY<  JsonPath::Command  > (YY_MOVE (that.value));
        break;

      case 3: // "string"
      case 4: // "number"
      case 5: // ">"
      case 6: // "<"
      case 7: // "-"
      case 30: // op
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 22: // body
      case 23: // path
      case 24: // selector
      case 25: // csv
      case 26: // filter
      case 27: // sfilter
      case 28: // squery
      case 29: // query
        value.move<  JsonPath::Command  > (YY_MOVE (that.value));
        break;

      case 3: // "string"
      case 4: // "number"
      case 5: // ">"
      case 6: // "<"
      case 7: // "-"
      case 30: // op
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 22: // body
      case 23: // path
      case 24: // selector
      case 25: // csv
      case 26: // filter
      case 27: // sfilter
      case 28: // squery
      case 29: // query
        value.copy<  JsonPath::Command  > (that.value);
        break;

      case 3: // "string"
      case 4: // "number"
      case 5: // ">"
      case 6: // "<"
      case 7: // "-"
      case 30: // op
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 22: // body
      case 23: // path
      case 24: // selector
      case 25: // csv
      case 26: // filter
      case 27: // sfilter
      case 28: // squery
      case 29: // query
        value.move<  JsonPath::Command  > (that.value);
        break;

      case 3: // "string"
      case 4: // "number"
      case 5: // ">"
      case 6: // "<"
      case 7: // "-"
      case 30: // op
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 22: // body
      case 23: // path
      case 24: // selector
      case 25: // csv
      case 26: // filter
      case 27: // sfilter
      case 28: // squery
      case 29: // query
        yylhs.value.emplace<  JsonPath::Command  > ();
        break;

      case 3: // "string"
      case 4: // "number"
      case 5: // ">"
      case 6: // "<"
      case 7: // "-"
      case 30: // op
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 80 "parser.y"
         {
    driver.switchInputStream(driver._jsonpath);
        driver.clear();
    }
#line 688 "parser.cpp"
    break;

  case 3:
#line 84 "parser.y"
                           {
        // driver.showCommands();
        driver.evaluate();
    }
#line 697 "parser.cpp"
    break;

  case 10:
#line 97 "parser.y"
             { driver.addCommand(yystack_[0].value.as <  JsonPath::Command  > ()); }
#line 703 "parser.cpp"
    break;

  case 11:
#line 98 "parser.y"
                 { driver.addCommand(yystack_[0].value.as <  JsonPath::Command  > ()); }
#line 709 "parser.cpp"
    break;

  case 12:
#line 99 "parser.y"
                    {
                        driver.addCommand(yystack_[1].value.as <  JsonPath::Command  > ());
                        driver.addCommand(yystack_[0].value.as <  JsonPath::Command  > ());
                    }
#line 718 "parser.cpp"
    break;

  case 13:
#line 103 "parser.y"
                        {
                            driver.addCommand(yystack_[1].value.as <  JsonPath::Command  > ());
                            driver.addCommand(yystack_[0].value.as <  JsonPath::Command  > ());
                        }
#line 727 "parser.cpp"
    break;

  case 14:
#line 110 "parser.y"
                            {
                                std::vector<string> arguments {yystack_[0].value.as < std::string > ()};
                                yylhs.value.as <  JsonPath::Command  > () = Command(0, arguments);
                            }
#line 736 "parser.cpp"
    break;

  case 15:
#line 114 "parser.y"
                            {
                                std::vector<string> arguments {yystack_[0].value.as < std::string > ()};
                                yylhs.value.as <  JsonPath::Command  > () = Command(0, arguments);
                            }
#line 745 "parser.cpp"
    break;

  case 16:
#line 118 "parser.y"
                            {
                                vector<string> arguments;
                                yylhs.value.as <  JsonPath::Command  > () = Command (9, arguments);
                            }
#line 754 "parser.cpp"
    break;

  case 17:
#line 122 "parser.y"
                            {
                                Command cmd = yystack_[2].value.as <  JsonPath::Command  > ();
                                if (cmd.id() == 0) {
                                cmd.addArg(yystack_[0].value.as < std::string > ());
                                yylhs.value.as <  JsonPath::Command  > () = cmd;
                                } else {
                                    vector<string> arguments {yystack_[0].value.as < std::string > ()};
                                    yylhs.value.as <  JsonPath::Command  > () = Command(0, arguments);
                                }
                            }
#line 769 "parser.cpp"
    break;

  case 18:
#line 132 "parser.y"
                            {
                                driver.addCommand(yystack_[2].value.as <  JsonPath::Command  > ());
                                yylhs.value.as <  JsonPath::Command  > () = yystack_[0].value.as <  JsonPath::Command  > ();}
#line 777 "parser.cpp"
    break;

  case 20:
#line 138 "parser.y"
                            {
                                int id = 10;
                                std::vector<string> arguments {yystack_[1].value.as < std::string > ()};
                                yylhs.value.as <  JsonPath::Command  > () = Command(id, arguments);
                            }
#line 787 "parser.cpp"
    break;

  case 21:
#line 143 "parser.y"
                            {
                                int id = 11;
                                std::vector<string> arguments {yystack_[1].value.as < std::string > ()};
                                yylhs.value.as <  JsonPath::Command  > () = Command(id, arguments);
                            }
#line 797 "parser.cpp"
    break;

  case 22:
#line 148 "parser.y"
                            {
                                yylhs.value.as <  JsonPath::Command  > () = yystack_[1].value.as <  JsonPath::Command  > ();
                            }
#line 805 "parser.cpp"
    break;

  case 23:
#line 151 "parser.y"
                            {
                                vector<string> arguments {yystack_[1].value.as < std::string > ()};
                                yylhs.value.as <  JsonPath::Command  > () = Command(13, arguments);
                            }
#line 814 "parser.cpp"
    break;

  case 24:
#line 155 "parser.y"
                            {
                                vector<string> arguments;
                                yylhs.value.as <  JsonPath::Command  > () = Command (19, arguments);
                            }
#line 823 "parser.cpp"
    break;

  case 25:
#line 159 "parser.y"
                            {
                                vector<string> arguments;
                                yylhs.value.as <  JsonPath::Command  > () = Command (19, arguments);
                            }
#line 832 "parser.cpp"
    break;

  case 26:
#line 163 "parser.y"
                            {yylhs.value.as <  JsonPath::Command  > () = yystack_[1].value.as <  JsonPath::Command  > ();}
#line 838 "parser.cpp"
    break;

  case 27:
#line 164 "parser.y"
                            {yylhs.value.as <  JsonPath::Command  > () = yystack_[1].value.as <  JsonPath::Command  > ();}
#line 844 "parser.cpp"
    break;

  case 28:
#line 167 "parser.y"
                                    {
        std::vector <string> arguments {yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()};
        yylhs.value.as <  JsonPath::Command  > () = Command(12, arguments);
    }
#line 853 "parser.cpp"
    break;

  case 29:
#line 171 "parser.y"
                        {
        vector<string> arguments {yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()};
        yylhs.value.as <  JsonPath::Command  > () = Command(14, arguments);
    }
#line 862 "parser.cpp"
    break;

  case 30:
#line 175 "parser.y"
                      {
        Command cmd = yystack_[2].value.as <  JsonPath::Command  > ();
        cmd.addArg(yystack_[0].value.as < std::string > ());
        yylhs.value.as <  JsonPath::Command  > () = cmd;
    }
#line 872 "parser.cpp"
    break;

  case 31:
#line 180 "parser.y"
                           {
        Command cmd = yystack_[2].value.as <  JsonPath::Command  > ();
        cmd.addArg(yystack_[0].value.as < std::string > ());
        yylhs.value.as <  JsonPath::Command  > () = cmd;
    }
#line 882 "parser.cpp"
    break;

  case 32:
#line 186 "parser.y"
                    {
        yylhs.value.as <  JsonPath::Command  > () = yystack_[1].value.as <  JsonPath::Command  > ();
    }
#line 890 "parser.cpp"
    break;

  case 33:
#line 191 "parser.y"
                       {
        yylhs.value.as <  JsonPath::Command  > () = yystack_[1].value.as <  JsonPath::Command  > ();
    }
#line 898 "parser.cpp"
    break;

  case 34:
#line 195 "parser.y"
                            {
        vector<string> arguments {yystack_[0].value.as < std::string > ()};
        yylhs.value.as <  JsonPath::Command  > () = Command (20, arguments);
    }
#line 907 "parser.cpp"
    break;

  case 35:
#line 199 "parser.y"
                      {
        Command cmd = yystack_[2].value.as <  JsonPath::Command  > ();
        cmd.addArg(yystack_[1].value.as < std::string > ());
        cmd.addArg(yystack_[0].value.as < std::string > ());
        yylhs.value.as <  JsonPath::Command  > () = cmd;
    }
#line 918 "parser.cpp"
    break;

  case 36:
#line 207 "parser.y"
                           {
        vector<string> arguments {yystack_[0].value.as < std::string > ()};
        yylhs.value.as <  JsonPath::Command  > () = Command (30, arguments);
    }
#line 927 "parser.cpp"
    break;

  case 37:
#line 211 "parser.y"
                     {
        Command cmd = yystack_[2].value.as <  JsonPath::Command  > ();
        cmd.addArg(yystack_[1].value.as < std::string > ());
        cmd.addArg(yystack_[0].value.as < std::string > ());
        yylhs.value.as <  JsonPath::Command  > () = cmd;
    }
#line 938 "parser.cpp"
    break;

  case 38:
#line 219 "parser.y"
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 944 "parser.cpp"
    break;

  case 39:
#line 220 "parser.y"
         { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 950 "parser.cpp"
    break;

  case 40:
#line 221 "parser.y"
         { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 956 "parser.cpp"
    break;


#line 960 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char  Parser ::yypact_ninf_ = -11;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
     -11,    24,   -11,   -11,     6,     3,     1,   -11,     1,    -5,
     -11,    30,    32,   -10,   -11,    16,    14,     8,    34,    20,
      22,   -11,   -11,     1,    -5,   -11,     2,   -11,    44,   -11,
      31,    46,    23,    39,   -11,    48,    33,   -11,    -1,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
      49,   -11,   -11,   -11,    50,   -11,   -11,   -11,   -11
  };

  const signed char
   Parser ::yydefact_[] =
  {
       2,     0,     4,    14,     0,     0,     6,     3,     8,    10,
      11,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,    15,    16,     7,    12,    13,    19,    20,     0,    21,
       0,     0,     0,     0,    24,     0,     0,    22,     0,    26,
      27,    17,    18,    28,    29,    36,    39,    40,    38,    32,
       0,    23,    34,    33,     0,    31,    30,    37,    35
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -11,   -11,   -11,    51,    -7,    -8,   -11,   -11,   -11,   -11,
     -11,    19
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,     1,     7,     8,     9,    10,    18,    19,    20,    36,
      32,    50
  };

  const signed char
   Parser ::yytable_[] =
  {
      25,    24,    55,    56,     3,    41,    21,    26,    31,    11,
      12,     4,     4,     5,    13,    25,    24,    14,    42,    22,
      33,    15,    16,    17,     2,    34,    35,     3,    46,    47,
      48,    39,    49,    40,     4,    44,     5,     6,    46,    47,
      48,    27,    53,    29,    28,    37,    30,    43,    38,    45,
      51,    52,     0,    57,    58,    54,     0,    23
  };

  const signed char
   Parser ::yycheck_[] =
  {
       8,     8,     3,     4,     3,     3,     3,    12,    18,     3,
       4,    10,    10,    12,     8,    23,    23,    11,    26,    16,
       4,    15,    16,    17,     0,    11,    18,     3,     5,     6,
       7,    11,     9,    11,    10,     4,    12,    13,     5,     6,
       7,    11,     9,    11,    14,    11,    14,     3,    14,     3,
      11,     3,    -1,     4,     4,    36,    -1,     6
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    20,     0,     3,    10,    12,    13,    21,    22,    23,
      24,     3,     4,     8,    11,    15,    16,    17,    25,    26,
      27,     3,    16,    22,    23,    24,    12,    11,    14,    11,
      14,    18,    29,     4,    11,    18,    28,    11,    14,    11,
      11,     3,    24,     3,     4,     3,     5,     6,     7,     9,
      30,    11,     3,     9,    30,     3,     4,     4,     4
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    19,    20,    20,    20,    21,    21,    21,    21,    22,
      22,    22,    22,    22,    23,    23,    23,    23,    23,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    25,    25,
      25,    25,    26,    27,    28,    28,    29,    29,    30,    30,
      30
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     0,     2,     2,     0,     1,     2,     1,     0,
       1,     1,     2,     2,     1,     2,     2,     3,     3,     0,
       3,     3,     3,     4,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     2,     3,     1,     1,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"string\"", "\"number\"",
  "\">\"", "\"<\"", "\"-\"", "\"left par\"", "\"right par\"",
  "\"left square brac\"", "\"right square brac\"", "\"dot\"", "\"start\"",
  "\"commma\"", "\"colon\"", "\"*\"", "\"filter parenthesis\"",
  "\"current directory (@.)\"", "$accept", "program", "jsonpath_exp",
  "body", "path", "selector", "csv", "filter", "sfilter", "squery",
  "query", "op", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    80,    80,    84,    88,    91,    92,    93,    94,    96,
      97,    98,    99,   103,   110,   114,   118,   122,   132,   137,
     138,   143,   148,   151,   155,   159,   163,   164,   167,   171,
     175,   180,   186,   191,   195,   199,   207,   211,   219,   220,
     221
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 9 "parser.y"
} //  JsonPath 
#line 1383 "parser.cpp"

#line 224 "parser.y"


// Bison expects us to provide implementation - otherwise linker complains
void JsonPath::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
	
        /* cout << "Error: " << message << endl << "Error location: " << driver.location() << endl; */
}
