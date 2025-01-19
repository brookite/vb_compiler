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
#line 191 "grammar.y"

    enum class IntType {
        LONG_MOD, INT_MOD, SHORT_MOD, NO_SPEC
    };

    struct IntLiteral {
        long long int Int;
        IntType type;
        bool isUnsigned = false;

        IntLiteral() : Int(0), type(IntType::INT_MOD) {}

        IntLiteral(long long int num, IntType type, bool isUnsigned) : Int(num), type(type), isUnsigned(isUnsigned) {}
    };

    enum class FloatType {
        DECIMAL_MOD, FLOAT_MOD, DOUBLE_MOD, NO_SPEC
    };

    struct FloatLiteral {
        double Float;
        FloatType type;

        FloatLiteral() : Float(0.0), type(FloatType::DOUBLE_MOD) {}

        FloatLiteral(double Float, FloatType type) : Float(Float), type(type) {}
    };

#line 80 "grammar.tab.h"

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
    PRESERVE_KW = 296,             /* PRESERVE_KW  */
    FOR_KW = 297,                  /* FOR_KW  */
    EACH_KW = 298,                 /* EACH_KW  */
    WHILE_KW = 299,                /* WHILE_KW  */
    NEXT_KW = 300,                 /* NEXT_KW  */
    IN_KW = 301,                   /* IN_KW  */
    UNTIL_KW = 302,                /* UNTIL_KW  */
    LOOP_KW = 303,                 /* LOOP_KW  */
    DO_KW = 304,                   /* DO_KW  */
    STEP_KW = 305,                 /* STEP_KW  */
    AS_KW = 306,                   /* AS_KW  */
    CALL_KW = 307,                 /* CALL_KW  */
    GOTO_KW = 308,                 /* GOTO_KW  */
    CONTINUE_KW = 309,             /* CONTINUE_KW  */
    EXIT_KW = 310,                 /* EXIT_KW  */
    STOP_KW = 311,                 /* STOP_KW  */
    RETURN_KW = 312,               /* RETURN_KW  */
    STATIC_KW = 313,               /* STATIC_KW  */
    DIM_KW = 314,                  /* DIM_KW  */
    CONST_KW = 315,                /* CONST_KW  */
    OF_KW = 316,                   /* OF_KW  */
    FUNCTION_KW = 317,             /* FUNCTION_KW  */
    SUB_KW = 318,                  /* SUB_KW  */
    BYREF_KW = 319,                /* BYREF_KW  */
    BYVAL_KW = 320,                /* BYVAL_KW  */
    PARAMARRAY_KW = 321,           /* PARAMARRAY_KW  */
    OPTIONAL_KW = 322,             /* OPTIONAL_KW  */
    PRIVATE_KW = 323,              /* PRIVATE_KW  */
    PROTECTED_KW = 324,            /* PROTECTED_KW  */
    PUBLIC_KW = 325,               /* PUBLIC_KW  */
    SHARED_KW = 326,               /* SHARED_KW  */
    CLASS_KW = 327,                /* CLASS_KW  */
    STRUCT_KW = 328,               /* STRUCT_KW  */
    INHERITS_KW = 329,             /* INHERITS_KW  */
    READONLY_KW = 330,             /* READONLY_KW  */
    ERASE_KW = 331,                /* ERASE_KW  */
    CBOOL_KW = 332,                /* CBOOL_KW  */
    CBYTE_KW = 333,                /* CBYTE_KW  */
    CSBYTE_KW = 334,               /* CSBYTE_KW  */
    CUSHORT_KW = 335,              /* CUSHORT_KW  */
    CSHORT_KW = 336,               /* CSHORT_KW  */
    CINTEGER_KW = 337,             /* CINTEGER_KW  */
    CUINTEGER_KW = 338,            /* CUINTEGER_KW  */
    CLONG_KW = 339,                /* CLONG_KW  */
    CULONG_KW = 340,               /* CULONG_KW  */
    CDATE_KW = 341,                /* CDATE_KW  */
    CCHAR_KW = 342,                /* CCHAR_KW  */
    CSTRING_KW = 343,              /* CSTRING_KW  */
    CDECIMAL_KW = 344,             /* CDECIMAL_KW  */
    CSINGLE_KW = 345,              /* CSINGLE_KW  */
    CDOUBLE_KW = 346,              /* CDOUBLE_KW  */
    COBJECT_KW = 347,              /* COBJECT_KW  */
    CTYPE_KW = 348,                /* CTYPE_KW  */
    END_FUNCTION = 349,            /* END_FUNCTION  */
    END_SELECT = 350,              /* END_SELECT  */
    END_IF = 351,                  /* END_IF  */
    END_SUB = 352,                 /* END_SUB  */
    END_WHILE = 353,               /* END_WHILE  */
    ADD_ASSIGN = 354,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 355,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 356,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 357,              /* DIV_ASSIGN  */
    FLOORDIV_ASSIGN = 358,         /* FLOORDIV_ASSIGN  */
    EXP_ASSIGN = 359,              /* EXP_ASSIGN  */
    STRCAT_ASSIGN = 360,           /* STRCAT_ASSIGN  */
    LSHIFT_ASSIGN = 361,           /* LSHIFT_ASSIGN  */
    RSHIFT_ASSIGN = 362,           /* RSHIFT_ASSIGN  */
    NEW = 363,                     /* NEW  */
    XOR = 364,                     /* XOR  */
    OR = 365,                      /* OR  */
    OR_ELSE = 366,                 /* OR_ELSE  */
    AND = 367,                     /* AND  */
    AND_ALSO = 368,                /* AND_ALSO  */
    NOT = 369,                     /* NOT  */
    EQ = 370,                      /* EQ  */
    NEQ = 371,                     /* NEQ  */
    LEQ = 372,                     /* LEQ  */
    GEQ = 373,                     /* GEQ  */
    IS = 374,                      /* IS  */
    ISNOT = 375,                   /* ISNOT  */
    LIKE = 376,                    /* LIKE  */
    LSHIFT = 377,                  /* LSHIFT  */
    RSHIFT = 378,                  /* RSHIFT  */
    MOD = 379,                     /* MOD  */
    UMINUS = 380,                  /* UMINUS  */
    UPLUS = 381                    /* UPLUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 220 "grammar.y"

    IntLiteral * Int;
    std::string * Str;
    bool Bool;
    FloatLiteral * Float;
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

#line 254 "grammar.tab.h"

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
