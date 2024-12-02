/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 5 "grammar.y"
 #include "../compiler/nodes.hpp" 

#line 52 "grammar.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    STR = 259,                     /* STR  */
    FLOAT = 260,                   /* FLOAT  */
    BOOL = 261,                    /* BOOL  */
    DATETIME = 262,                /* DATETIME  */
    CHAR = 263,                    /* CHAR  */
    ID = 264,                      /* ID  */
    NOTHING = 265,                 /* NOTHING  */
    ENDL = 266,                    /* ENDL  */
    ME_KW = 267,                   /* ME_KW  */
    MYBASE_KW = 268,               /* MYBASE_KW  */
    MYCLASS_KW = 269,              /* MYCLASS_KW  */
    IF_KW = 270,                   /* IF_KW  */
    NEW_KW = 271,                  /* NEW_KW  */
    BYTE_KW = 272,                 /* BYTE_KW  */
    SBYTE_KW = 273,                /* SBYTE_KW  */
    USHORT_KW = 274,               /* USHORT_KW  */
    SHORT_KW = 275,                /* SHORT_KW  */
    UINTEGER_KW = 276,             /* UINTEGER_KW  */
    INTEGER_KW = 277,              /* INTEGER_KW  */
    ULONG_KW = 278,                /* ULONG_KW  */
    LONG_KW = 279,                 /* LONG_KW  */
    BOOLEAN_KW = 280,              /* BOOLEAN_KW  */
    DATE_KW = 281,                 /* DATE_KW  */
    CHAR_KW = 282,                 /* CHAR_KW  */
    STRING_KW = 283,               /* STRING_KW  */
    DECIMAL_KW = 284,              /* DECIMAL_KW  */
    SINGLE_KW = 285,               /* SINGLE_KW  */
    DOUBLE_KW = 286,               /* DOUBLE_KW  */
    OBJECT_KW = 287,               /* OBJECT_KW  */
    REDIM_KW = 288,                /* REDIM_KW  */
    THEN_KW = 289,                 /* THEN_KW  */
    END_KW = 290,                  /* END_KW  */
    ELSE_KW = 291,                 /* ELSE_KW  */
    ELSEIF_KW = 292,               /* ELSEIF_KW  */
    SELECT_KW = 293,               /* SELECT_KW  */
    CASE_KW = 294,                 /* CASE_KW  */
    TO_KW = 295,                   /* TO_KW  */
    FOR_KW = 296,                  /* FOR_KW  */
    EACH_KW = 297,                 /* EACH_KW  */
    WHILE_KW = 298,                /* WHILE_KW  */
    NEXT_KW = 299,                 /* NEXT_KW  */
    IN_KW = 300,                   /* IN_KW  */
    UNTIL_KW = 301,                /* UNTIL_KW  */
    LOOP_KW = 302,                 /* LOOP_KW  */
    DO_KW = 303,                   /* DO_KW  */
    STEP_KW = 304,                 /* STEP_KW  */
    AS_KW = 305,                   /* AS_KW  */
    CALL_KW = 306,                 /* CALL_KW  */
    GOTO_KW = 307,                 /* GOTO_KW  */
    CONTINUE_KW = 308,             /* CONTINUE_KW  */
    EXIT_KW = 309,                 /* EXIT_KW  */
    STOP_KW = 310,                 /* STOP_KW  */
    RETURN_KW = 311,               /* RETURN_KW  */
    STATIC_KW = 312,               /* STATIC_KW  */
    DIM_KW = 313,                  /* DIM_KW  */
    CONST_KW = 314,                /* CONST_KW  */
    OF_KW = 315,                   /* OF_KW  */
    FUNCTION_KW = 316,             /* FUNCTION_KW  */
    SUB_KW = 317,                  /* SUB_KW  */
    BYREF_KW = 318,                /* BYREF_KW  */
    BYVAL_KW = 319,                /* BYVAL_KW  */
    PARAMARRAY_KW = 320,           /* PARAMARRAY_KW  */
    OPTIONAL_KW = 321,             /* OPTIONAL_KW  */
    PRIVATE_KW = 322,              /* PRIVATE_KW  */
    PROTECTED_KW = 323,            /* PROTECTED_KW  */
    PUBLIC_KW = 324,               /* PUBLIC_KW  */
    SHARED_KW = 325,               /* SHARED_KW  */
    CLASS_KW = 326,                /* CLASS_KW  */
    STRUCT_KW = 327,               /* STRUCT_KW  */
    INHERITS_KW = 328,             /* INHERITS_KW  */
    READONLY_KW = 329,             /* READONLY_KW  */
    ERASE_KW = 330,                /* ERASE_KW  */
    CBOOL_KW = 331,                /* CBOOL_KW  */
    CBYTE_KW = 332,                /* CBYTE_KW  */
    CSBYTE_KW = 333,               /* CSBYTE_KW  */
    CUSHORT_KW = 334,              /* CUSHORT_KW  */
    CSHORT_KW = 335,               /* CSHORT_KW  */
    CINTEGER_KW = 336,             /* CINTEGER_KW  */
    CUINTEGER_KW = 337,            /* CUINTEGER_KW  */
    CLONG_KW = 338,                /* CLONG_KW  */
    CULONG_KW = 339,               /* CULONG_KW  */
    CDATE_KW = 340,                /* CDATE_KW  */
    CCHAR_KW = 341,                /* CCHAR_KW  */
    CSTRING_KW = 342,              /* CSTRING_KW  */
    CDECIMAL_KW = 343,             /* CDECIMAL_KW  */
    CSINGLE_KW = 344,              /* CSINGLE_KW  */
    CDOUBLE_KW = 345,              /* CDOUBLE_KW  */
    COBJECT_KW = 346,              /* COBJECT_KW  */
    CTYPE_KW = 347,                /* CTYPE_KW  */
    END_FUNCTION = 348,            /* END_FUNCTION  */
    END_SELECT = 349,              /* END_SELECT  */
    END_IF = 350,                  /* END_IF  */
    END_SUB = 351,                 /* END_SUB  */
    END_WHILE = 352,               /* END_WHILE  */
    ADD_ASSIGN = 353,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 354,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 355,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 356,              /* DIV_ASSIGN  */
    FLOORDIV_ASSIGN = 357,         /* FLOORDIV_ASSIGN  */
    EXP_ASSIGN = 358,              /* EXP_ASSIGN  */
    STRCAT_ASSIGN = 359,           /* STRCAT_ASSIGN  */
    LSHIFT_ASSIGN = 360,           /* LSHIFT_ASSIGN  */
    RSHIFT_ASSIGN = 361,           /* RSHIFT_ASSIGN  */
    BARE_NEW = 362,                /* BARE_NEW  */
    XOR = 363,                     /* XOR  */
    OR = 364,                      /* OR  */
    OR_ELSE = 365,                 /* OR_ELSE  */
    AND = 366,                     /* AND  */
    AND_ALSO = 367,                /* AND_ALSO  */
    NOT = 368,                     /* NOT  */
    NEQ = 369,                     /* NEQ  */
    LEQ = 370,                     /* LEQ  */
    GEQ = 371,                     /* GEQ  */
    IS = 372,                      /* IS  */
    ISNOT = 373,                   /* ISNOT  */
    LIKE = 374,                    /* LIKE  */
    LSHIFT = 375,                  /* LSHIFT  */
    RSHIFT = 376,                  /* RSHIFT  */
    MOD = 377,                     /* MOD  */
    UMINUS = 378,                  /* UMINUS  */
    UPLUS = 379                    /* UPLUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 181 "grammar.y"

    long long int Int;
    std::string * Str;
    bool Bool;
    double Float;
    DateTime * DateTime;
    std::string * Id;
    char Char;

    node * Unknown;

    expr_node * Expr;
    stmt_node * Stmt;
    struct_node * Struct;
    type_node * Type;
    program_node * EntryPoint;
    typed_value * Var;

    block * Block;
    procedure_node * Procedure;
    field_node * Field;
    redim_clause_node * RedimNode;

    list<node *>* UnknownBody;
    list<expr_node *> * ExprList;
    list<redim_clause_node*>* Redim;
    list<std::string>* IdList;
    list<type_node *> * TypeList;
    list<typed_value*>* Vars;

#line 224 "grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
