/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "grammar.y"

#include <string>
#include "grammar_handler.cpp"
#include "../compiler/dot.hpp"

extern int yylineno;
extern FILE* yyin;
extern char* yytext;
extern int yydebug;
extern bool new_stmt;

int yyparse();
int yylex();
void yyrestart(FILE * file);

void yyerror(char const* s) {
    fprintf(stderr, "\033[31mSyntaxError: %s on line %d, text: %s\n", s, yylineno, yytext);
    fprintf(stderr, "\033[0m");
    yyrestart(yyin);
    if (!PARSER_DEBUG && !DEBUG) exit(1);
}

bool PARSER_DEBUG = false;
bool DEBUG = false;

program_node * program = nullptr;


#line 100 "grammar.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_STR = 4,                        /* STR  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_BOOL = 6,                       /* BOOL  */
  YYSYMBOL_DATETIME = 7,                   /* DATETIME  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NOTHING = 10,                   /* NOTHING  */
  YYSYMBOL_ENDL = 11,                      /* ENDL  */
  YYSYMBOL_ME_KW = 12,                     /* ME_KW  */
  YYSYMBOL_MYBASE_KW = 13,                 /* MYBASE_KW  */
  YYSYMBOL_MYCLASS_KW = 14,                /* MYCLASS_KW  */
  YYSYMBOL_IF_KW = 15,                     /* IF_KW  */
  YYSYMBOL_NEW_KW = 16,                    /* NEW_KW  */
  YYSYMBOL_BYTE_KW = 17,                   /* BYTE_KW  */
  YYSYMBOL_SBYTE_KW = 18,                  /* SBYTE_KW  */
  YYSYMBOL_USHORT_KW = 19,                 /* USHORT_KW  */
  YYSYMBOL_SHORT_KW = 20,                  /* SHORT_KW  */
  YYSYMBOL_UINTEGER_KW = 21,               /* UINTEGER_KW  */
  YYSYMBOL_INTEGER_KW = 22,                /* INTEGER_KW  */
  YYSYMBOL_ULONG_KW = 23,                  /* ULONG_KW  */
  YYSYMBOL_LONG_KW = 24,                   /* LONG_KW  */
  YYSYMBOL_BOOLEAN_KW = 25,                /* BOOLEAN_KW  */
  YYSYMBOL_DATE_KW = 26,                   /* DATE_KW  */
  YYSYMBOL_CHAR_KW = 27,                   /* CHAR_KW  */
  YYSYMBOL_STRING_KW = 28,                 /* STRING_KW  */
  YYSYMBOL_DECIMAL_KW = 29,                /* DECIMAL_KW  */
  YYSYMBOL_SINGLE_KW = 30,                 /* SINGLE_KW  */
  YYSYMBOL_DOUBLE_KW = 31,                 /* DOUBLE_KW  */
  YYSYMBOL_OBJECT_KW = 32,                 /* OBJECT_KW  */
  YYSYMBOL_REDIM_KW = 33,                  /* REDIM_KW  */
  YYSYMBOL_THEN_KW = 34,                   /* THEN_KW  */
  YYSYMBOL_END_KW = 35,                    /* END_KW  */
  YYSYMBOL_ELSE_KW = 36,                   /* ELSE_KW  */
  YYSYMBOL_ELSEIF_KW = 37,                 /* ELSEIF_KW  */
  YYSYMBOL_SELECT_KW = 38,                 /* SELECT_KW  */
  YYSYMBOL_CASE_KW = 39,                   /* CASE_KW  */
  YYSYMBOL_TO_KW = 40,                     /* TO_KW  */
  YYSYMBOL_FOR_KW = 41,                    /* FOR_KW  */
  YYSYMBOL_EACH_KW = 42,                   /* EACH_KW  */
  YYSYMBOL_WHILE_KW = 43,                  /* WHILE_KW  */
  YYSYMBOL_NEXT_KW = 44,                   /* NEXT_KW  */
  YYSYMBOL_IN_KW = 45,                     /* IN_KW  */
  YYSYMBOL_UNTIL_KW = 46,                  /* UNTIL_KW  */
  YYSYMBOL_LOOP_KW = 47,                   /* LOOP_KW  */
  YYSYMBOL_DO_KW = 48,                     /* DO_KW  */
  YYSYMBOL_STEP_KW = 49,                   /* STEP_KW  */
  YYSYMBOL_AS_KW = 50,                     /* AS_KW  */
  YYSYMBOL_CALL_KW = 51,                   /* CALL_KW  */
  YYSYMBOL_GOTO_KW = 52,                   /* GOTO_KW  */
  YYSYMBOL_CONTINUE_KW = 53,               /* CONTINUE_KW  */
  YYSYMBOL_EXIT_KW = 54,                   /* EXIT_KW  */
  YYSYMBOL_STOP_KW = 55,                   /* STOP_KW  */
  YYSYMBOL_RETURN_KW = 56,                 /* RETURN_KW  */
  YYSYMBOL_STATIC_KW = 57,                 /* STATIC_KW  */
  YYSYMBOL_DIM_KW = 58,                    /* DIM_KW  */
  YYSYMBOL_CONST_KW = 59,                  /* CONST_KW  */
  YYSYMBOL_OF_KW = 60,                     /* OF_KW  */
  YYSYMBOL_FUNCTION_KW = 61,               /* FUNCTION_KW  */
  YYSYMBOL_SUB_KW = 62,                    /* SUB_KW  */
  YYSYMBOL_BYREF_KW = 63,                  /* BYREF_KW  */
  YYSYMBOL_BYVAL_KW = 64,                  /* BYVAL_KW  */
  YYSYMBOL_PARAMARRAY_KW = 65,             /* PARAMARRAY_KW  */
  YYSYMBOL_OPTIONAL_KW = 66,               /* OPTIONAL_KW  */
  YYSYMBOL_PRIVATE_KW = 67,                /* PRIVATE_KW  */
  YYSYMBOL_PROTECTED_KW = 68,              /* PROTECTED_KW  */
  YYSYMBOL_PUBLIC_KW = 69,                 /* PUBLIC_KW  */
  YYSYMBOL_SHARED_KW = 70,                 /* SHARED_KW  */
  YYSYMBOL_CLASS_KW = 71,                  /* CLASS_KW  */
  YYSYMBOL_STRUCT_KW = 72,                 /* STRUCT_KW  */
  YYSYMBOL_INHERITS_KW = 73,               /* INHERITS_KW  */
  YYSYMBOL_READONLY_KW = 74,               /* READONLY_KW  */
  YYSYMBOL_ERASE_KW = 75,                  /* ERASE_KW  */
  YYSYMBOL_CBOOL_KW = 76,                  /* CBOOL_KW  */
  YYSYMBOL_CBYTE_KW = 77,                  /* CBYTE_KW  */
  YYSYMBOL_CSBYTE_KW = 78,                 /* CSBYTE_KW  */
  YYSYMBOL_CUSHORT_KW = 79,                /* CUSHORT_KW  */
  YYSYMBOL_CSHORT_KW = 80,                 /* CSHORT_KW  */
  YYSYMBOL_CINTEGER_KW = 81,               /* CINTEGER_KW  */
  YYSYMBOL_CUINTEGER_KW = 82,              /* CUINTEGER_KW  */
  YYSYMBOL_CLONG_KW = 83,                  /* CLONG_KW  */
  YYSYMBOL_CULONG_KW = 84,                 /* CULONG_KW  */
  YYSYMBOL_CDATE_KW = 85,                  /* CDATE_KW  */
  YYSYMBOL_CCHAR_KW = 86,                  /* CCHAR_KW  */
  YYSYMBOL_CSTRING_KW = 87,                /* CSTRING_KW  */
  YYSYMBOL_CDECIMAL_KW = 88,               /* CDECIMAL_KW  */
  YYSYMBOL_CSINGLE_KW = 89,                /* CSINGLE_KW  */
  YYSYMBOL_CDOUBLE_KW = 90,                /* CDOUBLE_KW  */
  YYSYMBOL_COBJECT_KW = 91,                /* COBJECT_KW  */
  YYSYMBOL_CTYPE_KW = 92,                  /* CTYPE_KW  */
  YYSYMBOL_END_FUNCTION = 93,              /* END_FUNCTION  */
  YYSYMBOL_END_SELECT = 94,                /* END_SELECT  */
  YYSYMBOL_END_IF = 95,                    /* END_IF  */
  YYSYMBOL_END_SUB = 96,                   /* END_SUB  */
  YYSYMBOL_END_WHILE = 97,                 /* END_WHILE  */
  YYSYMBOL_ADD_ASSIGN = 98,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 99,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 100,               /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 101,               /* DIV_ASSIGN  */
  YYSYMBOL_FLOORDIV_ASSIGN = 102,          /* FLOORDIV_ASSIGN  */
  YYSYMBOL_EXP_ASSIGN = 103,               /* EXP_ASSIGN  */
  YYSYMBOL_STRCAT_ASSIGN = 104,            /* STRCAT_ASSIGN  */
  YYSYMBOL_LSHIFT_ASSIGN = 105,            /* LSHIFT_ASSIGN  */
  YYSYMBOL_RSHIFT_ASSIGN = 106,            /* RSHIFT_ASSIGN  */
  YYSYMBOL_NEW = 107,                      /* NEW  */
  YYSYMBOL_XOR = 108,                      /* XOR  */
  YYSYMBOL_OR = 109,                       /* OR  */
  YYSYMBOL_OR_ELSE = 110,                  /* OR_ELSE  */
  YYSYMBOL_AND = 111,                      /* AND  */
  YYSYMBOL_AND_ALSO = 112,                 /* AND_ALSO  */
  YYSYMBOL_NOT = 113,                      /* NOT  */
  YYSYMBOL_EQ = 114,                       /* EQ  */
  YYSYMBOL_NEQ = 115,                      /* NEQ  */
  YYSYMBOL_LEQ = 116,                      /* LEQ  */
  YYSYMBOL_GEQ = 117,                      /* GEQ  */
  YYSYMBOL_118_ = 118,                     /* '<'  */
  YYSYMBOL_119_ = 119,                     /* '>'  */
  YYSYMBOL_IS = 120,                       /* IS  */
  YYSYMBOL_ISNOT = 121,                    /* ISNOT  */
  YYSYMBOL_LIKE = 122,                     /* LIKE  */
  YYSYMBOL_LSHIFT = 123,                   /* LSHIFT  */
  YYSYMBOL_RSHIFT = 124,                   /* RSHIFT  */
  YYSYMBOL_125_ = 125,                     /* '&'  */
  YYSYMBOL_126_ = 126,                     /* '+'  */
  YYSYMBOL_127_ = 127,                     /* '-'  */
  YYSYMBOL_MOD = 128,                      /* MOD  */
  YYSYMBOL_129_ = 129,                     /* '\\'  */
  YYSYMBOL_130_ = 130,                     /* '/'  */
  YYSYMBOL_131_ = 131,                     /* '*'  */
  YYSYMBOL_UMINUS = 132,                   /* UMINUS  */
  YYSYMBOL_UPLUS = 133,                    /* UPLUS  */
  YYSYMBOL_134_ = 134,                     /* '^'  */
  YYSYMBOL_135_ = 135,                     /* '.'  */
  YYSYMBOL_136_ = 136,                     /* '('  */
  YYSYMBOL_137_ = 137,                     /* ')'  */
  YYSYMBOL_138_ = 138,                     /* '{'  */
  YYSYMBOL_139_ = 139,                     /* '}'  */
  YYSYMBOL_140_ = 140,                     /* '='  */
  YYSYMBOL_141_ = 141,                     /* ':'  */
  YYSYMBOL_142_ = 142,                     /* ','  */
  YYSYMBOL_YYACCEPT = 143,                 /* $accept  */
  YYSYMBOL_program = 144,                  /* program  */
  YYSYMBOL_program_member = 145,           /* program_member  */
  YYSYMBOL_endl_list = 146,                /* endl_list  */
  YYSYMBOL_opt_endl_list = 147,            /* opt_endl_list  */
  YYSYMBOL_stmt_endl = 148,                /* stmt_endl  */
  YYSYMBOL_opt_endl = 149,                 /* opt_endl  */
  YYSYMBOL_kw = 150,                       /* kw  */
  YYSYMBOL_expr = 151,                     /* expr  */
  YYSYMBOL_cast_target = 152,              /* cast_target  */
  YYSYMBOL_collection_initializer = 153,   /* collection_initializer  */
  YYSYMBOL_member_access_member = 154,     /* member_access_member  */
  YYSYMBOL_expr_list = 155,                /* expr_list  */
  YYSYMBOL_stmt = 156,                     /* stmt  */
  YYSYMBOL_redim_clause = 157,             /* redim_clause  */
  YYSYMBOL_redim_clause_list = 158,        /* redim_clause_list  */
  YYSYMBOL_if_stmt = 159,                  /* if_stmt  */
  YYSYMBOL_else_if_stmts = 160,            /* else_if_stmts  */
  YYSYMBOL_select_stmt = 161,              /* select_stmt  */
  YYSYMBOL_case_condition_branch = 162,    /* case_condition_branch  */
  YYSYMBOL_case_condition_branches = 163,  /* case_condition_branches  */
  YYSYMBOL_case_else_stmt = 164,           /* case_else_stmt  */
  YYSYMBOL_case_stmts = 165,               /* case_stmts  */
  YYSYMBOL_while_stmt = 166,               /* while_stmt  */
  YYSYMBOL_for_stmt = 167,                 /* for_stmt  */
  YYSYMBOL_for_loop_variable = 168,        /* for_loop_variable  */
  YYSYMBOL_foreach_stmt = 169,             /* foreach_stmt  */
  YYSYMBOL_do_while_stmt = 170,            /* do_while_stmt  */
  YYSYMBOL_do_until_stmt = 171,            /* do_until_stmt  */
  YYSYMBOL_opt_block = 172,                /* opt_block  */
  YYSYMBOL_block = 173,                    /* block  */
  YYSYMBOL_variable_name = 174,            /* variable_name  */
  YYSYMBOL_array_modifier = 175,           /* array_modifier  */
  YYSYMBOL_var_declarator = 176,           /* var_declarator  */
  YYSYMBOL_var_declaration = 177,          /* var_declaration  */
  YYSYMBOL_type_name = 178,                /* type_name  */
  YYSYMBOL_simple_type_name = 179,         /* simple_type_name  */
  YYSYMBOL_primitive_type = 180,           /* primitive_type  */
  YYSYMBOL_type_list = 181,                /* type_list  */
  YYSYMBOL_id_list = 182,                  /* id_list  */
  YYSYMBOL_function_signature = 183,       /* function_signature  */
  YYSYMBOL_sub_signature = 184,            /* sub_signature  */
  YYSYMBOL_function_declaration = 185,     /* function_declaration  */
  YYSYMBOL_sub_declaration = 186,          /* sub_declaration  */
  YYSYMBOL_opt_procedure_modifiers = 187,  /* opt_procedure_modifiers  */
  YYSYMBOL_function_parameters = 188,      /* function_parameters  */
  YYSYMBOL_function_parameter = 189,       /* function_parameter  */
  YYSYMBOL_class_declaration = 190,        /* class_declaration  */
  YYSYMBOL_generic_param_list = 191,       /* generic_param_list  */
  YYSYMBOL_opt_structure_body = 192,       /* opt_structure_body  */
  YYSYMBOL_structure_body = 193,           /* structure_body  */
  YYSYMBOL_structure_member = 194,         /* structure_member  */
  YYSYMBOL_field_declaration = 195         /* field_declaration  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4918

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  344
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  699

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   380


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   125,     2,
     136,   137,   131,   126,   142,   127,   135,   130,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   141,     2,
     118,   140,   119,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   129,     2,   134,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   138,     2,   139,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   120,   121,   122,   123,   124,   128,   132,
     133
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   249,   249,   250,   253,   256,   257,   260,   261,   264,
     265,   268,   269,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   452,   453,   456,
     457,   460,   461,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   499,   502,   503,   506,
     507,   508,   509,   510,   511,   514,   515,   516,   519,   520,
     523,   524,   525,   526,   529,   530,   533,   536,   537,   538,
     539,   542,   543,   546,   547,   548,   549,   552,   553,   556,
     557,   560,   561,   564,   565,   568,   569,   572,   573,   576,
     577,   580,   581,   585,   586,   587,   588,   591,   592,   596,
     597,   598,   599,   600,   601,   604,   605,   606,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   627,   628,   631,   632,   635,   636,
     637,   638,   639,   640,   643,   644,   645,   648,   649,   652,
     653,   656,   657,   660,   661,   664,   665,   668,   669,   670,
     671,   674,   677,   678,   681,   682,   685,   686,   687,   690,
     691,   692,   693,   694,   695
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "INT", "STR", "FLOAT", "BOOL",
  "DATETIME", "CHAR", "ID", "NOTHING", "ENDL", "ME_KW", "MYBASE_KW",
  "MYCLASS_KW", "IF_KW", "NEW_KW", "BYTE_KW", "SBYTE_KW", "USHORT_KW",
  "SHORT_KW", "UINTEGER_KW", "INTEGER_KW", "ULONG_KW", "LONG_KW",
  "BOOLEAN_KW", "DATE_KW", "CHAR_KW", "STRING_KW", "DECIMAL_KW",
  "SINGLE_KW", "DOUBLE_KW", "OBJECT_KW", "REDIM_KW", "THEN_KW", "END_KW",
  "ELSE_KW", "ELSEIF_KW", "SELECT_KW", "CASE_KW", "TO_KW", "FOR_KW",
  "EACH_KW", "WHILE_KW", "NEXT_KW", "IN_KW", "UNTIL_KW", "LOOP_KW",
  "DO_KW", "STEP_KW", "AS_KW", "CALL_KW", "GOTO_KW", "CONTINUE_KW",
  "EXIT_KW", "STOP_KW", "RETURN_KW", "STATIC_KW", "DIM_KW", "CONST_KW",
  "OF_KW", "FUNCTION_KW", "SUB_KW", "BYREF_KW", "BYVAL_KW",
  "PARAMARRAY_KW", "OPTIONAL_KW", "PRIVATE_KW", "PROTECTED_KW",
  "PUBLIC_KW", "SHARED_KW", "CLASS_KW", "STRUCT_KW", "INHERITS_KW",
  "READONLY_KW", "ERASE_KW", "CBOOL_KW", "CBYTE_KW", "CSBYTE_KW",
  "CUSHORT_KW", "CSHORT_KW", "CINTEGER_KW", "CUINTEGER_KW", "CLONG_KW",
  "CULONG_KW", "CDATE_KW", "CCHAR_KW", "CSTRING_KW", "CDECIMAL_KW",
  "CSINGLE_KW", "CDOUBLE_KW", "COBJECT_KW", "CTYPE_KW", "END_FUNCTION",
  "END_SELECT", "END_IF", "END_SUB", "END_WHILE", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "FLOORDIV_ASSIGN",
  "EXP_ASSIGN", "STRCAT_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "NEW",
  "XOR", "OR", "OR_ELSE", "AND", "AND_ALSO", "NOT", "EQ", "NEQ", "LEQ",
  "GEQ", "'<'", "'>'", "IS", "ISNOT", "LIKE", "LSHIFT", "RSHIFT", "'&'",
  "'+'", "'-'", "MOD", "'\\\\'", "'/'", "'*'", "UMINUS", "UPLUS", "'^'",
  "'.'", "'('", "')'", "'{'", "'}'", "'='", "':'", "','", "$accept",
  "program", "program_member", "endl_list", "opt_endl_list", "stmt_endl",
  "opt_endl", "kw", "expr", "cast_target", "collection_initializer",
  "member_access_member", "expr_list", "stmt", "redim_clause",
  "redim_clause_list", "if_stmt", "else_if_stmts", "select_stmt",
  "case_condition_branch", "case_condition_branches", "case_else_stmt",
  "case_stmts", "while_stmt", "for_stmt", "for_loop_variable",
  "foreach_stmt", "do_while_stmt", "do_until_stmt", "opt_block", "block",
  "variable_name", "array_modifier", "var_declarator", "var_declaration",
  "type_name", "simple_type_name", "primitive_type", "type_list",
  "id_list", "function_signature", "sub_signature", "function_declaration",
  "sub_declaration", "opt_procedure_modifiers", "function_parameters",
  "function_parameter", "class_declaration", "generic_param_list",
  "opt_structure_body", "structure_body", "structure_member",
  "field_declaration", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-524)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-334)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,    38,    33,  -524,    42,    12,  -524,  -524,  -524,    49,
    -524,   -18,    68,  -524,    41,    -9,    24,  -524,  -524,    26,
      28,    36,     8,  -524,  -524,    35,    55,    11,  -524,  -524,
      98,    41,    39,   100,   -26,   104,   -21,    42,   104,    42,
     104,   104,   105,   106,    42,    42,    47,  -524,    42,    91,
     116,  -524,    -3,    13,  -524,    42,   261,  4562,    49,    42,
      49,    42,    42,   -20,    -4,  1162,  1298,  -524,    41,    62,
      42,    68,    29,  -524,  4562,    49,    34,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,     5,    50,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,    17,    58,    76,   345,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
      86,  4562,  4562,  4562,    68,    68,  4083,    87,  -524,    49,
      49,    49,   261,    68,    68,  4698,  4562,  3474,    40,  4562,
      31,  4562,    44,    30,  3610,   104,   104,  4562,    42,  3681,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  2114,  -524,
      42,  2250,   114,  -524,    41,   153,  -524,   972,    68,  4562,
      68,  4826,  4826,    68,    92,    93,    68,   755,   -41,   -41,
    4562,   890,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,  4826,    68,    68,  -524,    27,
      32,    68,  3265,  4215,  -524,     1,  4562,  1013,   117,   159,
      45,  1013,  4562,  4562,  2386,  1013,    42,    42,    42,    42,
      42,    42,    42,    49,  1013,    42,    42,  4083,     2,    49,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    42,  -524,    49,    42,   103,   192,  -524,    57,   -29,
    4083,    94,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,  -524,
    -524,  -524,  -524,  -524,  -524,  -524,  -524,  4562,    68,    68,
    4562,   972,  -524,     9,  4562,  4562,  4562,  4562,  4562,  4562,
    4562,  4562,  4562,  4562,  4562,  4562,  4562,  4562,  4562,  4562,
    4562,  4562,  4562,  4562,  4562,  4562,  4562,  -524,  3746,  4562,
     183,   184,    14,  -524,  -524,    14,  4562,    42,    68,    68,
      49,  1013,    52,   261,    68,    68,  1434,  1013,  1013,   188,
    3202,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    68,    49,  4562,  4562,  4562,  4562,  4562,  4562,
    4562,  4562,  4562,  3882,  4562,    49,    49,  -524,   166,  -524,
     398,  -524,  -524,  3807,  3338,  4018,  3943,   101,   113,  4350,
    4484,  4484,   755,   755,    53,    53,    53,    53,    53,    53,
      53,    53,   265,   265,   443,    -7,    -7,     6,    61,   -41,
     -41,   -33,  -524,     9,   972,   261,   261,   104,   102,   118,
     344,  2386,  3746,  4562,    52,  4154,  -524,   215,  -524,   162,
    -524,   212,  4562,    42,  2522,  2386,  2386,    37,  4562,  1013,
    1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,    42,     9,
    1013,  -524,   122,  -524,  -524,    15,    68,   398,   124,     9,
     124,     9,    68,  -524,  -524,   128,   130,  -524,  -524,  -524,
     218,  -524,    22,  3202,     9,  -524,   177,    42,    90,  -524,
    -524,    42,  3610,  3535,    49,    42,   227,   228,  4562,  4562,
      49,  4083,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,   140,    49,    68,    68,   157,  4562,    15,  -524,
     158,  -524,   161,   261,  -524,  -524,   261,    42,  4562,    42,
      25,   163,    42,  2386,  4562,  2386,    49,  4290,  1013,  4562,
      49,    42,    42,  1013,  1013,    42,   236,   398,   165,   697,
     167,   124,   124,    68,  -524,  1570,  3400,    49,    42,    42,
      16,    49,  -524,  1013,  3202,  1013,  2386,   732,    49,    49,
      49,    49,    49,   398,  -524,    68,    68,   168,   172,  -524,
    -524,   173,    42,  2658,    42,  1706,    49,  2386,  2386,   255,
    4562,  1842,    15,   174,  4562,  -524,    68,  -524,    49,    42,
    2386,    42,  2794,  3202,   258,    42,  1013,    42,  2930,   176,
    -524,   972,  4426,    49,  3202,    49,    42,    42,    49,  1978,
      49,    42,  -524,   179,   124,     9,    49,    49,    42,  3066,
      49,  -524,  -524,   180,    49,    42,   124,    49,  -524
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,     7,     0,     1,     3,     5,     8,
       4,     5,    12,    10,   322,     0,     0,     6,    11,     0,
       0,     0,   321,   336,   337,     0,     0,   322,   334,   338,
       0,   322,     0,     0,   269,     0,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,   306,    12,    12,   270,     0,     0,     0,   341,     0,
     344,     0,     0,   313,   316,     0,     0,   328,   322,     0,
       0,    12,     0,   272,     0,   340,   279,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   274,   281,    94,    95,    97,    98,    99,
     100,    96,   101,   102,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,     0,     0,     0,    12,    12,   275,     0,   170,   343,
     339,   342,     0,    12,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   198,   199,   205,   200,   201,   203,   204,     0,   206,
       0,     0,     0,   330,   322,     0,   331,    12,    12,     0,
      12,     0,     0,    12,   155,   165,    12,   143,   141,   142,
       0,     0,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,     0,    12,    12,   312,     0,
       0,    12,     0,     0,   227,     0,     0,     0,   257,     0,
       0,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   217,     0,     0,     0,   191,     0,   318,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,     0,   268,   320,     0,     0,     0,   307,     0,     0,
     276,     0,   189,    13,    15,    16,    14,    17,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    60,    58,
      59,    61,    62,    63,    64,    65,    66,    67,    69,    70,
      68,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,   190,   153,   154,     0,    12,    12,
       0,    12,   188,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     311,   326,    12,   323,   315,    12,     0,     0,    12,    12,
     196,     0,   250,     0,    12,    12,     0,     0,     0,     0,
     266,   193,   220,   221,   219,   225,   223,   224,   222,   218,
     277,   278,    12,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   317,   319,   327,     0,   271,
       0,   282,   284,     0,     0,     0,     0,     0,     0,   137,
     136,   135,   133,   134,   129,   130,   131,   132,   128,   127,
     144,   145,   139,   140,   126,   120,   121,   138,   124,   123,
     122,   125,   147,    12,    12,     0,     0,     0,     0,     0,
      12,   235,     0,     0,   250,     0,   244,   247,   248,     0,
     258,     0,     0,     0,     0,   265,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,    12,
       0,   329,   285,   304,   287,    12,    12,     0,   156,    12,
     166,    12,    12,   119,   187,     0,     0,   310,   325,   324,
     309,   314,     0,   235,    12,   228,     0,     0,     0,   245,
     249,     0,     0,     0,   252,     0,     0,     0,     0,     0,
     202,   192,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   195,     0,   207,    12,    12,     0,     0,    12,   158,
       0,   168,     0,     0,   146,   148,     0,     0,     0,     0,
       0,     0,     0,   265,     0,   241,   238,     0,     0,     0,
     251,     0,     0,     0,     0,   146,     0,     0,   280,    12,
       0,   157,   167,    12,   308,     0,     0,   234,     0,     0,
     146,   239,   246,     0,   240,     0,   265,     0,   262,   264,
     261,   263,   194,     0,   305,    12,    12,     0,   160,   159,
     169,     0,     0,     0,     0,     0,   233,   243,   265,     0,
       0,     0,    12,     0,     0,   151,    12,   149,   232,     0,
     237,     0,     0,   242,     0,     0,     0,     0,     0,     0,
     283,    12,     0,   230,   236,   231,     0,     0,   260,     0,
     254,     0,   286,     0,   161,    12,   229,   259,     0,     0,
     253,   150,   163,     0,   256,     0,   162,   255,   164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -524,  -524,   301,    -5,  -524,   302,   119,  -524,   558,  -524,
    -523,  -141,  -195,  -106,  -174,  -524,  -524,  -223,  -524,  -153,
    -524,  -150,  -143,  -524,  -524,   120,  -524,  -524,  -524,  -488,
     -56,  -226,  -524,   -19,  -524,  -137,  -255,   -93,  -499,  -524,
    -524,  -524,  -524,  -524,  -524,   123,  -131,  -524,  -524,   -30,
    -524,   331,  -524
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     9,    10,    15,   457,   364,   169,   147,
     148,   365,   258,   170,   234,   235,   171,   542,   172,   496,
     497,   498,   499,   173,   174,   240,   175,   176,   177,   419,
     420,    36,    54,    37,   179,    93,   523,    94,   525,    52,
      44,    45,    23,    24,    25,   402,   403,     4,    16,    26,
      27,    28,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    49,    39,   401,   401,   579,   373,   581,    18,   178,
     181,    31,     8,     8,   195,   228,    55,   556,   557,    59,
      18,    61,    62,    11,    18,    18,    18,  -226,   578,    56,
     152,   450,    58,     6,    60,    11,    34,    34,   182,    65,
      66,    34,     8,    68,     1,    34,  -333,     5,     8,   238,
      75,   366,    17,     8,   149,    -9,   150,   151,   587,   588,
      17,   618,   588,    17,    30,   184,    40,    41,   249,    20,
      21,   250,   272,   251,   242,   272,  -332,   243,   252,    18,
     558,    22,   239,   559,   397,   246,    33,   247,   639,   640,
      46,   495,   248,   224,   225,   226,    42,    43,    35,    20,
      21,     8,   225,   226,     1,   622,    38,    48,   451,    51,
      53,    22,    50,    34,    63,    64,   153,   589,    67,    57,
     619,   220,   221,   222,   223,    70,    69,   224,   225,   226,
     594,    19,   154,   183,   652,   221,   222,   223,   649,    71,
     224,   225,   226,   409,   432,   189,   255,   256,    12,   275,
      73,   432,   191,    13,   276,   244,   487,   575,  -226,   253,
     664,   692,   277,   259,   400,    13,   186,   413,   238,   404,
     188,    72,    74,   698,   447,   273,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   415,   190,   224,   225,   226,
     185,   222,   223,   192,   449,   224,   225,   226,   202,   203,
     204,   205,   206,   483,   207,   208,   209,   210,   211,   212,
     213,   214,   193,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   196,   227,   224,   225,   226,   448,   368,   369,
     410,   452,   412,   485,   486,   507,   416,   521,   533,   540,
     421,   422,   423,   424,   425,   426,   427,   428,   519,   429,
     430,   431,   534,   433,   495,   541,   551,   552,   574,   529,
     531,   401,   145,   200,   201,   584,   445,   585,   586,   446,
      76,   592,   229,   230,   601,   602,   500,   605,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   608,   611,   633,   544,   612,   665,
     620,   635,   677,     7,   638,   655,   278,   279,   656,   281,
     657,   670,   367,   682,   272,   370,   691,   696,    32,   545,
     590,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   549,   398,   399,   550,   537,   538,
     406,   546,   634,   405,   194,    18,   539,   524,    47,   414,
     504,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     217,   218,   219,   220,   221,   222,   223,     0,   272,   224,
     225,   226,   491,     0,     0,     0,   494,   522,     0,     0,
       0,     0,   505,   506,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,   524,   543,     0,   272,     0,     0,
       0,     0,     0,     0,     0,     0,   613,     0,     0,   614,
       0,     0,   202,   203,   204,   205,   206,     0,   207,   208,
     209,   210,   211,   212,   213,   214,     0,   215,   216,   217,
     218,   219,   220,   221,   222,   223,     0,   685,   224,   225,
     226,     0,     0,     0,     0,     0,   526,   454,   455,     0,
       0,     0,   458,     0,     0,     0,     0,     0,   554,     0,
       0,     0,   560,     0,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   524,   573,     0,     0,   272,     0,
       0,   488,     0,     0,   489,     0,     0,   492,   493,     0,
       0,     0,     0,   501,   502,     0,     0,   272,     0,   624,
     524,     0,   593,   595,     0,     0,   596,   597,     0,     0,
     600,   508,     0,     0,     0,     0,   272,   272,     0,   643,
       0,     0,   272,     0,     0,     0,     0,     0,   272,   218,
     219,   220,   221,   222,   223,     0,     0,   224,   225,   226,
       0,     0,   615,   272,   617,     0,     0,   621,     0,   662,
       0,   663,     0,   626,     0,   668,   628,   629,   630,   631,
     632,     0,   535,   536,   674,     0,     0,     0,     0,     0,
       0,     0,     0,   645,   646,   146,     0,     0,   647,     0,
     648,     0,   651,   689,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,   658,   572,   660,
       0,     0,     0,     0,   576,   577,     0,     0,   580,     0,
     582,   583,     0,     0,   673,     0,   675,     0,     0,     0,
     678,   679,   680,   591,     0,     0,     0,     0,     0,     0,
       0,   686,   687,     0,     0,     0,   690,     0,     0,     0,
       0,     0,     0,   694,     0,     0,     0,     0,     0,     0,
     697,     0,     0,   606,   607,     0,     0,   610,     0,   197,
     198,   199,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,   232,   233,   237,     0,   241,     0,   245,
       0,     0,   254,     0,     0,   257,     0,     0,   637,     0,
       0,     0,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,   280,     0,     0,
       0,     0,     0,     0,   653,   654,     0,     0,   371,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   669,     0,     0,     0,   672,     0,     0,     0,     0,
       0,   650,     0,     0,     0,     0,     0,     0,     0,     0,
     683,     0,     0,     0,   411,     0,     0,     0,     0,     0,
     417,   418,     0,     0,   693,   202,   203,   204,   205,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,     0,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     0,
       0,   224,   225,   226,     0,     0,     0,     0,     0,   636,
     202,   203,   204,   205,   206,     0,   207,   208,   209,   210,
     211,   212,   213,   214,     0,   215,   216,   217,   218,   219,
     220,   221,   222,   223,     0,     0,   224,   225,   226,   207,
     208,   209,   210,   211,   212,   213,   214,     0,   215,   216,
     217,   218,   219,   220,   221,   222,   223,     0,     0,   224,
     225,   226,     0,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,   453,     0,     0,   456,     0,
       0,     0,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,     0,   257,   484,     0,     0,
       0,     0,     0,     0,   490,     0,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    18,     0,     0,     0,     0,     0,     0,
       0,     0,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   257,   520,   141,     0,     0,     0,     0,     0,     0,
       0,     0,   257,   257,     0,     0,   142,   143,     0,     0,
       0,     0,     0,     0,     8,     0,   144,     0,   145,   372,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,   233,     0,   548,     0,     0,     0,     0,     0,     0,
     553,     0,     0,     0,     0,     0,   561,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,   203,   204,   205,   206,     0,   207,   208,   209,   210,
     211,   212,   213,   214,     0,   215,   216,   217,   218,   219,
     220,   221,   222,   223,     0,     0,   224,   225,   226,     0,
     598,     0,     0,     0,     0,     0,   603,   604,     0,     0,
       0,   202,   203,   204,   205,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,   609,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     0,   616,   224,   225,   226,
       0,     0,   623,     0,     0,   625,     0,   627,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,    17,   103,   104,   105,   155,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   156,     0,     0,     0,     0,
     157,     0,     0,   158,     0,   159,     0,     0,   666,     0,
     160,     0,   671,   161,     0,   162,   163,     0,   164,     0,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,   167,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
     145,    95,    96,    97,    98,    99,   100,   101,   102,    17,
     103,   104,   105,   155,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   156,     0,     0,     0,     0,   157,     0,     0,   158,
       0,   159,     0,     0,     0,     0,   160,     0,     0,   161,
       0,   162,   163,     0,   164,     0,   165,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,   145,    95,    96,    97,
      98,    99,   100,   101,   102,    17,   103,   104,   105,   155,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   156,     0,     0,
       0,     0,   157,     0,     0,   158,     0,   159,     0,     0,
       0,     0,   160,     0,     0,   161,     0,   162,   163,     0,
     164,     0,   165,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,   145,    95,    96,    97,    98,    99,   100,   101,
     102,    17,   103,   104,   105,   155,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   156,     0,     0,     0,     0,   157,     0,
       0,   158,     0,   159,     0,     0,     0,     0,   160,     0,
       0,   161,     0,   162,   163,     0,   164,     0,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   642,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,   145,    95,
      96,    97,    98,    99,   100,   101,   102,    17,   103,   104,
     105,   155,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   156,
       0,     0,     0,     0,   157,     0,     0,   158,     0,   159,
       0,     0,     0,     0,   160,     0,     0,   161,     0,   162,
     163,     0,   164,     0,   165,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   661,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,   145,    95,    96,    97,    98,    99,
     100,   101,   102,    17,   103,   104,   105,   155,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   156,     0,     0,     0,     0,
     157,     0,     0,   158,     0,   159,   667,     0,     0,     0,
     160,     0,     0,   161,     0,   162,   163,     0,   164,     0,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
     145,    95,    96,    97,    98,    99,   100,   101,   102,    17,
     103,   104,   105,   155,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   156,     0,     0,     0,     0,   157,     0,     0,   158,
       0,   159,   688,     0,     0,     0,   160,     0,     0,   161,
       0,   162,   163,     0,   164,     0,   165,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,   145,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,   104,   105,   155,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   156,     0,     0,
       0,     0,   157,     0,     0,   158,     0,   159,     0,     0,
       0,     0,   160,     0,     0,   161,     0,   162,   163,     0,
     164,     0,   165,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,   145,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,   104,   105,   155,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   156,     0,     0,     0,     0,   157,     0,
       0,   158,     0,   159,     0,     0,     0,     0,   160,     0,
       0,   161,     0,   162,   163,     0,   164,     0,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,   274,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,   145,    95,
      96,    97,    98,    99,   100,   101,   102,    17,   103,   104,
     105,   155,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   156,
       0,     0,     0,     0,   157,     0,     0,   158,     0,   159,
       0,     0,     0,     0,   160,     0,     0,   161,     0,   162,
     163,     0,   164,     0,   165,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,   145,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,   104,   105,   155,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   156,     0,     0,     0,     0,
     157,     0,     0,   158,     0,   159,     0,     0,     0,     0,
     160,     0,     0,   161,     0,   162,   163,     0,   164,     0,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
     145,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   105,   155,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   156,     0,     0,     0,     0,   157,     0,     0,   158,
       0,   159,     0,     0,     0,     0,   160,     0,     0,   161,
       0,   162,   163,     0,   164,     0,   165,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   659,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,   145,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,   104,   105,   155,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   156,     0,     0,
       0,     0,   157,     0,     0,   158,     0,   159,     0,     0,
       0,     0,   160,     0,     0,   161,     0,   162,   163,     0,
     164,     0,   165,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   676,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,   145,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,   104,   105,   155,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   156,     0,     0,     0,     0,   157,     0,
       0,   158,     0,   159,   681,     0,     0,     0,   160,     0,
       0,   161,     0,   162,   163,     0,   164,     0,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,   145,    95,
      96,    97,    98,    99,   100,   101,   102,     0,   103,   104,
     105,   155,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   156,
       0,     0,     0,     0,   157,     0,     0,   158,     0,   159,
     695,     0,     0,     0,   160,     0,     0,   161,     0,   162,
     163,     0,   164,     0,   165,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,   145,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,   104,   105,   155,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   156,     0,     0,     0,     0,
     157,     0,     0,   158,     0,   159,     0,     0,     0,     0,
     160,     0,     0,   161,     0,   162,   163,     0,   164,     0,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,   407,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
     145,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,     0,   215,   216,
     217,   218,   219,   220,   221,   222,   223,     0,   527,   224,
     225,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,   644,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   528,   145,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,   202,   203,
     204,   205,   206,   236,   207,   208,   209,   210,   211,   212,
     213,   214,     0,   215,   216,   217,   218,   219,   220,   221,
     222,   223,     0,     0,   224,   225,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,   145,    95,    96,    97,    98,    99,   100,   101,
     102,     8,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,     0,   215,   216,
     217,   218,   219,   220,   221,   222,   223,     0,     0,   224,
     225,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,   145,    95,
      96,    97,    98,    99,   100,   101,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   260,
     261,   262,   263,   264,   265,   266,   267,   268,     0,   202,
     203,   204,   205,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,     0,   215,   216,   217,   218,   219,   220,
     221,   222,   223,     0,     0,   224,   225,   269,     0,     0,
       0,   270,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   482,   145,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   202,   203,   204,   205,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,     0,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     0,
       0,   224,   225,   226,     0,     0,     0,     0,     0,   526,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   518,
     145,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   202,   203,   204,   205,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     0,     0,   224,   225,   226,
       0,     0,     0,     0,     0,   532,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   530,   145,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
     547,   202,   203,   204,   205,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     0,     0,   224,   225,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,   145,    95,    96,    97,    98,    99,   100,   101,
     102,    17,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,     0,   215,   216,
     217,   218,   219,   220,   221,   222,   223,     0,     0,   224,
     225,   408,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,   145,    95,
      96,    97,    98,    99,   100,   101,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   203,
     204,   205,   206,     0,   207,   208,   209,   210,   211,   212,
     213,   214,     0,   215,   216,   217,   218,   219,   220,   221,
     222,   223,     0,     0,   224,   225,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   684,   145,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   205,   206,     0,   207,   208,
     209,   210,   211,   212,   213,   214,     0,   215,   216,   217,
     218,   219,   220,   221,   222,   223,     0,     0,   224,   225,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
     145,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,   231,   282,   145,     0,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363
};

static const yytype_int16 yycheck[] =
{
       5,    31,    21,   229,   230,   528,   201,   530,    11,    65,
      66,    16,    11,    11,   107,   152,    35,   505,   506,    38,
      11,    40,    41,    11,    11,    11,    11,    11,   527,    50,
      50,    60,    37,     0,    39,    11,     9,     9,    68,    44,
      45,     9,    11,    48,    71,     9,    35,     9,    11,     9,
      55,   192,    11,    11,    59,    73,    61,    62,    36,    37,
      11,    36,    37,    11,    73,    70,    58,    59,    38,    58,
      59,    41,   178,    43,    43,   181,    35,    46,    48,    11,
      43,    70,    42,    46,   225,    41,    60,    43,   611,   612,
      35,    39,    48,   134,   135,   136,    61,    62,    70,    58,
      59,    11,   135,   136,    71,   593,    70,     9,   137,     9,
     136,    70,    73,     9,     9,     9,   136,    95,    71,   140,
      95,   128,   129,   130,   131,     9,    35,   134,   135,   136,
      40,    12,   136,    71,   633,   129,   130,   131,   626,   142,
     134,   135,   136,   142,   142,   140,   165,   166,   136,    35,
     137,   142,   135,   141,   184,   160,   142,   142,   142,   164,
     648,   684,     9,   168,   137,   141,   137,    50,     9,   137,
     136,    52,    53,   696,    71,   180,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   140,   136,   134,   135,   136,
      71,   130,   131,   135,   137,   134,   135,   136,   108,   109,
     110,   111,   112,   398,   114,   115,   116,   117,   118,   119,
     120,   121,   136,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   136,   136,   134,   135,   136,    35,   136,   136,
     235,   137,   237,    50,    50,    47,   241,    71,   137,   137,
     245,   246,   247,   248,   249,   250,   251,   252,   443,   254,
     255,   256,   139,   258,    39,   137,    94,    45,   136,   454,
     455,   487,   138,   144,   145,   137,   271,   137,    50,   274,
       9,    94,   153,   154,    47,    47,   413,   137,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   137,   137,    60,   492,   137,    44,
     137,   136,    44,     2,   137,   137,   187,   188,   136,   190,
     137,   137,   193,   137,   420,   196,   137,   137,    16,   493,
     543,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   497,   226,   227,   497,   485,   486,
     231,   494,   607,   230,     9,    11,   487,   450,    27,   239,
     416,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     125,   126,   127,   128,   129,   130,   131,    -1,   504,   134,
     135,   136,   407,    -1,    -1,    -1,   411,     9,    -1,    -1,
      -1,    -1,   417,   418,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,   527,   491,    -1,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,   586,
      -1,    -1,   108,   109,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   672,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,   142,   368,   369,    -1,
      -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,   503,    -1,
      -1,    -1,   507,    -1,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   607,   520,    -1,    -1,   624,    -1,
      -1,   402,    -1,    -1,   405,    -1,    -1,   408,   409,    -1,
      -1,    -1,    -1,   414,   415,    -1,    -1,   643,    -1,   595,
     633,    -1,   547,   548,    -1,    -1,   551,   552,    -1,    -1,
     555,   432,    -1,    -1,    -1,    -1,   662,   663,    -1,   615,
      -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,   674,   126,
     127,   128,   129,   130,   131,    -1,    -1,   134,   135,   136,
      -1,    -1,   587,   689,   589,    -1,    -1,   592,    -1,   645,
      -1,   647,    -1,   598,    -1,   651,   601,   602,   603,   604,
     605,    -1,   483,   484,   660,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   618,   619,    57,    -1,    -1,   623,    -1,
     625,    -1,   627,   679,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,   642,   519,   644,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,   529,    -1,
     531,   532,    -1,    -1,   659,    -1,   661,    -1,    -1,    -1,
     665,   666,   667,   544,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   676,   677,    -1,    -1,    -1,   681,    -1,    -1,    -1,
      -1,    -1,    -1,   688,    -1,    -1,    -1,    -1,    -1,    -1,
     695,    -1,    -1,   574,   575,    -1,    -1,   578,    -1,   141,
     142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,   155,   156,   157,    -1,   159,    -1,   161,
      -1,    -1,   164,    -1,    -1,   167,    -1,    -1,   609,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   635,   636,    -1,    -1,   200,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   652,    -1,    -1,    -1,   656,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     671,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,    -1,   685,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,   367,    -1,    -1,   370,    -1,
      -1,    -1,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,    -1,   398,   399,    -1,    -1,
      -1,    -1,    -1,    -1,   406,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   454,   455,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,   136,    -1,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     492,   493,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,    -1,
     552,    -1,    -1,    -1,    -1,    -1,   558,   559,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   577,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   588,   134,   135,   136,
      -1,    -1,   594,    -1,    -1,   597,    -1,   599,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    43,    -1,    -1,   650,    -1,
      48,    -1,   654,    51,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     672,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    53,    54,    -1,    56,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    53,    54,    -1,
      56,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    53,    54,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    53,
      54,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    53,    54,    -1,    56,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    53,    54,    -1,
      56,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    53,    54,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    53,
      54,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    53,    54,    -1,    56,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    53,    54,    -1,
      56,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    53,    54,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    53,
      54,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,   108,   109,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    60,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,   108,   109,
     110,   111,   112,    39,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   108,   109,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,   134,   135,   136,    -1,    -1,
      -1,   140,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   108,   109,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      36,   108,   109,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   108,   109,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,     9,   138,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,   144,   145,   190,     9,     0,   145,    11,   146,
     147,    11,   136,   141,   146,   148,   191,    11,    11,   149,
      58,    59,    70,   185,   186,   187,   192,   193,   194,   195,
      73,   146,   148,    60,     9,    70,   174,   176,    70,   176,
      58,    59,    61,    62,   183,   184,    35,   194,     9,   192,
      73,     9,   182,   136,   175,   176,    50,   140,   146,   176,
     146,   176,   176,     9,     9,   146,   146,    71,   146,    35,
       9,   142,   149,   137,   149,   146,     9,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   178,   180,     3,     4,     5,     6,     7,
       8,     9,    10,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,   113,   126,   127,   136,   138,   151,   152,   153,   146,
     146,   146,    50,   136,   136,    15,    33,    38,    41,    43,
      48,    51,    53,    54,    56,    58,    59,    75,    93,   151,
     156,   159,   161,   166,   167,   169,   170,   171,   173,   177,
      96,   173,   192,    71,   146,   149,   137,   151,   136,   140,
     136,   135,   135,   136,     9,   180,   136,   151,   151,   151,
     149,   149,   108,   109,   110,   111,   112,   114,   115,   116,
     117,   118,   119,   120,   121,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   134,   135,   136,   136,   178,   149,
     149,   136,   151,   151,   157,   158,    39,   151,     9,    42,
     168,   151,    43,    46,   146,   151,    41,    43,    48,    38,
      41,    43,    48,   146,   151,   176,   176,   151,   155,   146,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   136,
     140,    93,   156,   146,    96,    35,   192,     9,   149,   149,
     151,   149,     9,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   150,   154,   154,   149,   136,   136,
     149,   151,   139,   155,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   154,   149,   149,
     137,   174,   188,   189,   137,   188,   149,    34,   136,   142,
     146,   151,   146,    50,   168,   140,   146,   151,   151,   172,
     173,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   142,   146,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   146,   146,    71,    35,   137,
      60,   137,   137,   151,   149,   149,   151,   149,   149,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   137,   155,   151,    50,    50,   142,   149,   149,
     151,   146,   149,   149,   146,    39,   162,   163,   164,   165,
     178,   149,   149,    97,   173,   146,   146,    47,   149,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   137,   155,
     151,    71,     9,   179,   180,   181,   142,    60,   137,   155,
     137,   155,   142,   137,   139,   149,   149,   178,   178,   189,
     137,   137,   160,   173,   155,   157,   165,    36,   151,   162,
     164,    94,    45,   151,   146,    97,   172,   172,    43,    46,
     146,   151,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   149,   146,   136,   142,   149,   149,   181,   153,
     149,   153,   149,   149,   137,   137,    50,    36,    37,    95,
     160,   149,    94,   146,    40,   146,   146,   146,   151,    40,
     146,    47,    47,   151,   151,   137,   149,   149,   137,   151,
     149,   137,   137,   178,   178,   146,   151,   146,    36,    95,
     137,   146,   172,   151,   173,   151,   146,   151,   146,   146,
     146,   146,   146,    60,   179,   136,   142,   149,   137,   153,
     153,   149,    95,   173,    34,   146,   146,   146,   146,   172,
      49,   146,   181,   149,   149,   137,   136,   137,   146,    95,
     146,    95,   173,   173,   172,    44,   151,    44,   173,   149,
     137,   151,   149,   146,   173,   146,    95,    44,   146,   146,
     146,    44,   137,   149,   137,   155,   146,   146,    44,   173,
     146,   137,   153,   149,   146,    44,   137,   146,   153
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   143,   144,   144,   145,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   157,   158,   158,   159,
     159,   159,   159,   159,   159,   160,   160,   160,   161,   161,
     162,   162,   162,   162,   163,   163,   164,   165,   165,   165,
     165,   166,   166,   167,   167,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   171,   172,   172,   173,   173,   174,
     174,   175,   175,   176,   176,   176,   176,   177,   177,   178,
     178,   178,   178,   178,   178,   179,   179,   179,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   181,   181,   182,   182,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   185,   185,   186,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   190,
     190,   191,   192,   192,   193,   193,   194,   194,   194,   195,
     195,   195,   195,   195,   195
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     2,     0,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     2,     2,     4,     4,     6,     4,     6,     9,
      12,     9,     3,     3,     3,     2,     5,     7,     6,     8,
       8,    11,    13,    12,    14,     2,     5,     7,     6,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     1,
       1,     1,     4,     3,     7,     5,     3,     3,     1,     1,
       1,     1,     5,     1,     1,     1,     1,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     1,     4,    11,
      10,    10,     9,     8,     7,     0,     6,     5,     6,     7,
       4,     3,     6,     5,     1,     2,     4,     1,     1,     2,
       0,     6,     5,    11,    10,    13,    12,     1,     3,    11,
      10,     7,     7,     7,     7,     0,     1,     1,     2,     1,
       2,     5,     2,     1,     3,     3,     5,     3,     3,     1,
       7,     1,     4,    10,     4,     1,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     4,     9,     7,
       7,     5,     4,     2,     7,     5,     2,     6,     5,     6,
       5,     1,     0,     1,     3,     3,     1,     9,     6,    10,
       7,     6,     0,     1,     1,     2,     1,     1,     1,     4,
       4,     3,     4,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: program_member  */
#line 249 "grammar.y"
                                            {parser_print("program_member -> program"); program = create_program(); program->nodes->add((yyvsp[0].Struct)); (yyval.EntryPoint) = program;}
#line 2953 "grammar.tab.cpp"
    break;

  case 3: /* program: program program_member  */
#line 250 "grammar.y"
                                            {parser_print("program program_member -> program"); program->nodes->add((yyvsp[0].Struct)); (yyval.EntryPoint) = program;}
#line 2959 "grammar.tab.cpp"
    break;

  case 4: /* program_member: class_declaration opt_endl_list  */
#line 253 "grammar.y"
                                                        {parser_print("class_declaration -> program_member"); (yyval.Struct) = (yyvsp[-1].Struct);}
#line 2965 "grammar.tab.cpp"
    break;

  case 5: /* endl_list: ENDL  */
#line 256 "grammar.y"
                                               { parser_print("ENDL -> endl_list");}
#line 2971 "grammar.tab.cpp"
    break;

  case 6: /* endl_list: endl_list ENDL  */
#line 257 "grammar.y"
                                               { parser_print("endl_list ENDL -> endl_list");}
#line 2977 "grammar.tab.cpp"
    break;

  case 9: /* stmt_endl: ENDL  */
#line 264 "grammar.y"
                                               { parser_print("ENDL -> stmt_endl");}
#line 2983 "grammar.tab.cpp"
    break;

  case 10: /* stmt_endl: ':'  */
#line 265 "grammar.y"
                                               { parser_print("':' -> stmt_endl");}
#line 2989 "grammar.tab.cpp"
    break;

  case 11: /* opt_endl: ENDL  */
#line 268 "grammar.y"
                                               { parser_print("ENDL -> opt_endl");}
#line 2995 "grammar.tab.cpp"
    break;

  case 12: /* opt_endl: %empty  */
#line 269 "grammar.y"
                                               { parser_print("empty -> opt_endl"); }
#line 3001 "grammar.tab.cpp"
    break;

  case 13: /* kw: ME_KW  */
#line 272 "grammar.y"
                                        {(yyval.Expr) = create_id("Me");}
#line 3007 "grammar.tab.cpp"
    break;

  case 14: /* kw: IF_KW  */
#line 273 "grammar.y"
                                        {(yyval.Expr) = create_id("If");}
#line 3013 "grammar.tab.cpp"
    break;

  case 15: /* kw: MYBASE_KW  */
#line 274 "grammar.y"
                                        {(yyval.Expr) = create_id("MyBase");}
#line 3019 "grammar.tab.cpp"
    break;

  case 16: /* kw: MYCLASS_KW  */
#line 275 "grammar.y"
                                        {(yyval.Expr) = create_id("MyClass");}
#line 3025 "grammar.tab.cpp"
    break;

  case 17: /* kw: NEW_KW  */
#line 276 "grammar.y"
                                        {(yyval.Expr) = create_id("New");}
#line 3031 "grammar.tab.cpp"
    break;

  case 18: /* kw: REDIM_KW  */
#line 277 "grammar.y"
                                        {(yyval.Expr) = create_id("ReDim");}
#line 3037 "grammar.tab.cpp"
    break;

  case 19: /* kw: THEN_KW  */
#line 278 "grammar.y"
                                        {(yyval.Expr) = create_id("Then");}
#line 3043 "grammar.tab.cpp"
    break;

  case 20: /* kw: END_KW  */
#line 279 "grammar.y"
                                        {(yyval.Expr) = create_id("End");}
#line 3049 "grammar.tab.cpp"
    break;

  case 21: /* kw: ELSE_KW  */
#line 280 "grammar.y"
                                        {(yyval.Expr) = create_id("Else");}
#line 3055 "grammar.tab.cpp"
    break;

  case 22: /* kw: ELSEIF_KW  */
#line 281 "grammar.y"
                                        {(yyval.Expr) = create_id("ElseIf");}
#line 3061 "grammar.tab.cpp"
    break;

  case 23: /* kw: SELECT_KW  */
#line 282 "grammar.y"
                                        {(yyval.Expr) = create_id("Select");}
#line 3067 "grammar.tab.cpp"
    break;

  case 24: /* kw: CASE_KW  */
#line 283 "grammar.y"
                                        {(yyval.Expr) = create_id("Case");}
#line 3073 "grammar.tab.cpp"
    break;

  case 25: /* kw: TO_KW  */
#line 284 "grammar.y"
                                        {(yyval.Expr) = create_id("To");}
#line 3079 "grammar.tab.cpp"
    break;

  case 26: /* kw: FOR_KW  */
#line 285 "grammar.y"
                                        {(yyval.Expr) = create_id("For");}
#line 3085 "grammar.tab.cpp"
    break;

  case 27: /* kw: EACH_KW  */
#line 286 "grammar.y"
                                        {(yyval.Expr) = create_id("Each");}
#line 3091 "grammar.tab.cpp"
    break;

  case 28: /* kw: WHILE_KW  */
#line 287 "grammar.y"
                                        {(yyval.Expr) = create_id("While");}
#line 3097 "grammar.tab.cpp"
    break;

  case 29: /* kw: NEXT_KW  */
#line 288 "grammar.y"
                                        {(yyval.Expr) = create_id("Next");}
#line 3103 "grammar.tab.cpp"
    break;

  case 30: /* kw: IN_KW  */
#line 289 "grammar.y"
                                        {(yyval.Expr) = create_id("In");}
#line 3109 "grammar.tab.cpp"
    break;

  case 31: /* kw: UNTIL_KW  */
#line 290 "grammar.y"
                                        {(yyval.Expr) = create_id("Until");}
#line 3115 "grammar.tab.cpp"
    break;

  case 32: /* kw: LOOP_KW  */
#line 291 "grammar.y"
                                        {(yyval.Expr) = create_id("Loop");}
#line 3121 "grammar.tab.cpp"
    break;

  case 33: /* kw: DO_KW  */
#line 292 "grammar.y"
                                        {(yyval.Expr) = create_id("Do");}
#line 3127 "grammar.tab.cpp"
    break;

  case 34: /* kw: STEP_KW  */
#line 293 "grammar.y"
                                        {(yyval.Expr) = create_id("Step");}
#line 3133 "grammar.tab.cpp"
    break;

  case 35: /* kw: AS_KW  */
#line 294 "grammar.y"
                                        {(yyval.Expr) = create_id("As");}
#line 3139 "grammar.tab.cpp"
    break;

  case 36: /* kw: CALL_KW  */
#line 295 "grammar.y"
                                        {(yyval.Expr) = create_id("Call");}
#line 3145 "grammar.tab.cpp"
    break;

  case 37: /* kw: GOTO_KW  */
#line 296 "grammar.y"
                                        {(yyval.Expr) = create_id("GoTo");}
#line 3151 "grammar.tab.cpp"
    break;

  case 38: /* kw: CONTINUE_KW  */
#line 297 "grammar.y"
                                        {(yyval.Expr) = create_id("Continue");}
#line 3157 "grammar.tab.cpp"
    break;

  case 39: /* kw: EXIT_KW  */
#line 298 "grammar.y"
                                        {(yyval.Expr) = create_id("Exit");}
#line 3163 "grammar.tab.cpp"
    break;

  case 40: /* kw: STOP_KW  */
#line 299 "grammar.y"
                                        {(yyval.Expr) = create_id("Stop");}
#line 3169 "grammar.tab.cpp"
    break;

  case 41: /* kw: RETURN_KW  */
#line 300 "grammar.y"
                                        {(yyval.Expr) = create_id("Return");}
#line 3175 "grammar.tab.cpp"
    break;

  case 42: /* kw: BYTE_KW  */
#line 301 "grammar.y"
                                        {(yyval.Expr) = create_id("Byte");}
#line 3181 "grammar.tab.cpp"
    break;

  case 43: /* kw: SBYTE_KW  */
#line 302 "grammar.y"
                                        {(yyval.Expr) = create_id("SByte");}
#line 3187 "grammar.tab.cpp"
    break;

  case 44: /* kw: USHORT_KW  */
#line 303 "grammar.y"
                                        {(yyval.Expr) = create_id("UShort");}
#line 3193 "grammar.tab.cpp"
    break;

  case 45: /* kw: SHORT_KW  */
#line 304 "grammar.y"
                                        {(yyval.Expr) = create_id("Short");}
#line 3199 "grammar.tab.cpp"
    break;

  case 46: /* kw: UINTEGER_KW  */
#line 305 "grammar.y"
                                        {(yyval.Expr) = create_id("UInteger");}
#line 3205 "grammar.tab.cpp"
    break;

  case 47: /* kw: INTEGER_KW  */
#line 306 "grammar.y"
                                        {(yyval.Expr) = create_id("Integer");}
#line 3211 "grammar.tab.cpp"
    break;

  case 48: /* kw: ULONG_KW  */
#line 307 "grammar.y"
                                        {(yyval.Expr) = create_id("ULong");}
#line 3217 "grammar.tab.cpp"
    break;

  case 49: /* kw: LONG_KW  */
#line 308 "grammar.y"
                                        {(yyval.Expr) = create_id("Long");}
#line 3223 "grammar.tab.cpp"
    break;

  case 50: /* kw: BOOLEAN_KW  */
#line 309 "grammar.y"
                                        {(yyval.Expr) = create_id("Boolean");}
#line 3229 "grammar.tab.cpp"
    break;

  case 51: /* kw: DATE_KW  */
#line 310 "grammar.y"
                                        {(yyval.Expr) = create_id("Date");}
#line 3235 "grammar.tab.cpp"
    break;

  case 52: /* kw: CHAR_KW  */
#line 311 "grammar.y"
                                        {(yyval.Expr) = create_id("Char");}
#line 3241 "grammar.tab.cpp"
    break;

  case 53: /* kw: STRING_KW  */
#line 312 "grammar.y"
                                        {(yyval.Expr) = create_id("String");}
#line 3247 "grammar.tab.cpp"
    break;

  case 54: /* kw: DECIMAL_KW  */
#line 313 "grammar.y"
                                        {(yyval.Expr) = create_id("Decimal");}
#line 3253 "grammar.tab.cpp"
    break;

  case 55: /* kw: SINGLE_KW  */
#line 314 "grammar.y"
                                        {(yyval.Expr) = create_id("Single");}
#line 3259 "grammar.tab.cpp"
    break;

  case 56: /* kw: DOUBLE_KW  */
#line 315 "grammar.y"
                                        {(yyval.Expr) = create_id("Double");}
#line 3265 "grammar.tab.cpp"
    break;

  case 57: /* kw: OBJECT_KW  */
#line 316 "grammar.y"
                                        {(yyval.Expr) = create_id("Object");}
#line 3271 "grammar.tab.cpp"
    break;

  case 58: /* kw: DIM_KW  */
#line 317 "grammar.y"
                                        {(yyval.Expr) = create_id("Dim");}
#line 3277 "grammar.tab.cpp"
    break;

  case 59: /* kw: CONST_KW  */
#line 318 "grammar.y"
                                        {(yyval.Expr) = create_id("Const");}
#line 3283 "grammar.tab.cpp"
    break;

  case 60: /* kw: STATIC_KW  */
#line 319 "grammar.y"
                                        {(yyval.Expr) = create_id("Static");}
#line 3289 "grammar.tab.cpp"
    break;

  case 61: /* kw: OF_KW  */
#line 320 "grammar.y"
                                        {(yyval.Expr) = create_id("Of");}
#line 3295 "grammar.tab.cpp"
    break;

  case 62: /* kw: FUNCTION_KW  */
#line 321 "grammar.y"
                                        {(yyval.Expr) = create_id("Function");}
#line 3301 "grammar.tab.cpp"
    break;

  case 63: /* kw: SUB_KW  */
#line 322 "grammar.y"
                                        {(yyval.Expr) = create_id("Sub");}
#line 3307 "grammar.tab.cpp"
    break;

  case 64: /* kw: BYREF_KW  */
#line 323 "grammar.y"
                                        {(yyval.Expr) = create_id("ByRef");}
#line 3313 "grammar.tab.cpp"
    break;

  case 65: /* kw: BYVAL_KW  */
#line 324 "grammar.y"
                                        {(yyval.Expr) = create_id("ByVal");}
#line 3319 "grammar.tab.cpp"
    break;

  case 66: /* kw: PARAMARRAY_KW  */
#line 325 "grammar.y"
                                        {(yyval.Expr) = create_id("ParamArray");}
#line 3325 "grammar.tab.cpp"
    break;

  case 67: /* kw: OPTIONAL_KW  */
#line 326 "grammar.y"
                                        {(yyval.Expr) = create_id("Optional");}
#line 3331 "grammar.tab.cpp"
    break;

  case 68: /* kw: PUBLIC_KW  */
#line 327 "grammar.y"
                                        {(yyval.Expr) = create_id("Public");}
#line 3337 "grammar.tab.cpp"
    break;

  case 69: /* kw: PRIVATE_KW  */
#line 328 "grammar.y"
                                        {(yyval.Expr) = create_id("Private");}
#line 3343 "grammar.tab.cpp"
    break;

  case 70: /* kw: PROTECTED_KW  */
#line 329 "grammar.y"
                                        {(yyval.Expr) = create_id("Protected");}
#line 3349 "grammar.tab.cpp"
    break;

  case 71: /* kw: SHARED_KW  */
#line 330 "grammar.y"
                                        {(yyval.Expr) = create_id("Shared");}
#line 3355 "grammar.tab.cpp"
    break;

  case 72: /* kw: CLASS_KW  */
#line 331 "grammar.y"
                                        {(yyval.Expr) = create_id("Class");}
#line 3361 "grammar.tab.cpp"
    break;

  case 73: /* kw: STRUCT_KW  */
#line 332 "grammar.y"
                                        {(yyval.Expr) = create_id("Struct");}
#line 3367 "grammar.tab.cpp"
    break;

  case 74: /* kw: INHERITS_KW  */
#line 333 "grammar.y"
                                        {(yyval.Expr) = create_id("Inherits");}
#line 3373 "grammar.tab.cpp"
    break;

  case 75: /* kw: READONLY_KW  */
#line 334 "grammar.y"
                                        {(yyval.Expr) = create_id("Readonly");}
#line 3379 "grammar.tab.cpp"
    break;

  case 76: /* kw: ERASE_KW  */
#line 335 "grammar.y"
                                        {(yyval.Expr) = create_id("Erase");}
#line 3385 "grammar.tab.cpp"
    break;

  case 77: /* kw: CBOOL_KW  */
#line 336 "grammar.y"
                                        {(yyval.Expr) = create_id("CBool");}
#line 3391 "grammar.tab.cpp"
    break;

  case 78: /* kw: CBYTE_KW  */
#line 337 "grammar.y"
                                        {(yyval.Expr) = create_id("CByte");}
#line 3397 "grammar.tab.cpp"
    break;

  case 79: /* kw: CSBYTE_KW  */
#line 338 "grammar.y"
                                        {(yyval.Expr) = create_id("CSByte");}
#line 3403 "grammar.tab.cpp"
    break;

  case 80: /* kw: CUSHORT_KW  */
#line 339 "grammar.y"
                                        {(yyval.Expr) = create_id("CUShort");}
#line 3409 "grammar.tab.cpp"
    break;

  case 81: /* kw: CSHORT_KW  */
#line 340 "grammar.y"
                                        {(yyval.Expr) = create_id("CShort");}
#line 3415 "grammar.tab.cpp"
    break;

  case 82: /* kw: CINTEGER_KW  */
#line 341 "grammar.y"
                                        {(yyval.Expr) = create_id("CInteger");}
#line 3421 "grammar.tab.cpp"
    break;

  case 83: /* kw: CUINTEGER_KW  */
#line 342 "grammar.y"
                                        {(yyval.Expr) = create_id("CUInteger");}
#line 3427 "grammar.tab.cpp"
    break;

  case 84: /* kw: CLONG_KW  */
#line 343 "grammar.y"
                                        {(yyval.Expr) = create_id("CLong");}
#line 3433 "grammar.tab.cpp"
    break;

  case 85: /* kw: CULONG_KW  */
#line 344 "grammar.y"
                                        {(yyval.Expr) = create_id("CULong");}
#line 3439 "grammar.tab.cpp"
    break;

  case 86: /* kw: CDATE_KW  */
#line 345 "grammar.y"
                                        {(yyval.Expr) = create_id("CDate");}
#line 3445 "grammar.tab.cpp"
    break;

  case 87: /* kw: CCHAR_KW  */
#line 346 "grammar.y"
                                        {(yyval.Expr) = create_id("CChar");}
#line 3451 "grammar.tab.cpp"
    break;

  case 88: /* kw: CSTRING_KW  */
#line 347 "grammar.y"
                                        {(yyval.Expr) = create_id("CString");}
#line 3457 "grammar.tab.cpp"
    break;

  case 89: /* kw: CDECIMAL_KW  */
#line 348 "grammar.y"
                                        {(yyval.Expr) = create_id("CDecimal");}
#line 3463 "grammar.tab.cpp"
    break;

  case 90: /* kw: CSINGLE_KW  */
#line 349 "grammar.y"
                                        {(yyval.Expr) = create_id("CSingle");}
#line 3469 "grammar.tab.cpp"
    break;

  case 91: /* kw: CDOUBLE_KW  */
#line 350 "grammar.y"
                                        {(yyval.Expr) = create_id("CDouble");}
#line 3475 "grammar.tab.cpp"
    break;

  case 92: /* kw: COBJECT_KW  */
#line 351 "grammar.y"
                                        {(yyval.Expr) = create_id("CObject");}
#line 3481 "grammar.tab.cpp"
    break;

  case 93: /* kw: CTYPE_KW  */
#line 352 "grammar.y"
                                        {(yyval.Expr) = create_id("CType");}
#line 3487 "grammar.tab.cpp"
    break;

  case 94: /* expr: INT  */
#line 355 "grammar.y"
                                                 {parser_print("INT -> expr"); (yyval.Expr) = create_int((yyvsp[0].Int));}
#line 3493 "grammar.tab.cpp"
    break;

  case 95: /* expr: STR  */
#line 356 "grammar.y"
                                                 {parser_print("STR-> expr"); (yyval.Expr) = create_string((yyvsp[0].Str));}
#line 3499 "grammar.tab.cpp"
    break;

  case 96: /* expr: ID  */
#line 357 "grammar.y"
                                                 {parser_print("ID -> expr"); (yyval.Expr) = create_id((yyvsp[0].Id));}
#line 3505 "grammar.tab.cpp"
    break;

  case 97: /* expr: FLOAT  */
#line 358 "grammar.y"
                                                 {parser_print("FLOAT -> expr"); (yyval.Expr) = create_float((yyvsp[0].Float));}
#line 3511 "grammar.tab.cpp"
    break;

  case 98: /* expr: BOOL  */
#line 359 "grammar.y"
                                                 {parser_print("BOOL -> expr"); (yyval.Expr) = create_bool((yyvsp[0].Bool));}
#line 3517 "grammar.tab.cpp"
    break;

  case 99: /* expr: DATETIME  */
#line 360 "grammar.y"
                                                 {parser_print("DATETIME -> expr"); (yyval.Expr) = create_datetime((yyvsp[0].DateTime));}
#line 3523 "grammar.tab.cpp"
    break;

  case 100: /* expr: CHAR  */
#line 361 "grammar.y"
                                                 {parser_print("CHAR -> expr"); (yyval.Expr) = create_char((yyvsp[0].Char));}
#line 3529 "grammar.tab.cpp"
    break;

  case 101: /* expr: NOTHING  */
#line 362 "grammar.y"
                                                 {parser_print("NOTHING -> expr"); (yyval.Expr) = create_nothing();}
#line 3535 "grammar.tab.cpp"
    break;

  case 102: /* expr: ME_KW  */
#line 363 "grammar.y"
                                                 {parser_print("ME_KW -> expr"); (yyval.Expr) = create_me();}
#line 3541 "grammar.tab.cpp"
    break;

  case 103: /* expr: BYTE_KW  */
#line 364 "grammar.y"
                                                {(yyval.Expr) = create_id("Byte");}
#line 3547 "grammar.tab.cpp"
    break;

  case 104: /* expr: SBYTE_KW  */
#line 365 "grammar.y"
                                                {(yyval.Expr) = create_id("SByte");}
#line 3553 "grammar.tab.cpp"
    break;

  case 105: /* expr: USHORT_KW  */
#line 366 "grammar.y"
                                                {(yyval.Expr) = create_id("UShort");}
#line 3559 "grammar.tab.cpp"
    break;

  case 106: /* expr: SHORT_KW  */
#line 367 "grammar.y"
                                                {(yyval.Expr) = create_id("Short");}
#line 3565 "grammar.tab.cpp"
    break;

  case 107: /* expr: UINTEGER_KW  */
#line 368 "grammar.y"
                                                {(yyval.Expr) = create_id("UInteger");}
#line 3571 "grammar.tab.cpp"
    break;

  case 108: /* expr: INTEGER_KW  */
#line 369 "grammar.y"
                                                {(yyval.Expr) = create_id("Integer");}
#line 3577 "grammar.tab.cpp"
    break;

  case 109: /* expr: ULONG_KW  */
#line 370 "grammar.y"
                                                {(yyval.Expr) = create_id("ULong");}
#line 3583 "grammar.tab.cpp"
    break;

  case 110: /* expr: LONG_KW  */
#line 371 "grammar.y"
                                                {(yyval.Expr) = create_id("Long");}
#line 3589 "grammar.tab.cpp"
    break;

  case 111: /* expr: BOOLEAN_KW  */
#line 372 "grammar.y"
                                                {(yyval.Expr) = create_id("Boolean");}
#line 3595 "grammar.tab.cpp"
    break;

  case 112: /* expr: DATE_KW  */
#line 373 "grammar.y"
                                                {(yyval.Expr) = create_id("Date");}
#line 3601 "grammar.tab.cpp"
    break;

  case 113: /* expr: CHAR_KW  */
#line 374 "grammar.y"
                                                {(yyval.Expr) = create_id("Char");}
#line 3607 "grammar.tab.cpp"
    break;

  case 114: /* expr: STRING_KW  */
#line 375 "grammar.y"
                                                {(yyval.Expr) = create_id("String");}
#line 3613 "grammar.tab.cpp"
    break;

  case 115: /* expr: DECIMAL_KW  */
#line 376 "grammar.y"
                                                {(yyval.Expr) = create_id("Decimal");}
#line 3619 "grammar.tab.cpp"
    break;

  case 116: /* expr: SINGLE_KW  */
#line 377 "grammar.y"
                                                {(yyval.Expr) = create_id("Single");}
#line 3625 "grammar.tab.cpp"
    break;

  case 117: /* expr: DOUBLE_KW  */
#line 378 "grammar.y"
                                                {(yyval.Expr) = create_id("Double");}
#line 3631 "grammar.tab.cpp"
    break;

  case 118: /* expr: OBJECT_KW  */
#line 379 "grammar.y"
                                                {(yyval.Expr) = create_id("Object");}
#line 3637 "grammar.tab.cpp"
    break;

  case 119: /* expr: '(' opt_endl expr opt_endl ')'  */
#line 380 "grammar.y"
                                                 {(yyval.Expr) = (yyvsp[-2].Expr);}
#line 3643 "grammar.tab.cpp"
    break;

  case 120: /* expr: expr '+' opt_endl expr  */
#line 381 "grammar.y"
                                                 {parser_print("expr + opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::AddOp);}
#line 3649 "grammar.tab.cpp"
    break;

  case 121: /* expr: expr '-' opt_endl expr  */
#line 382 "grammar.y"
                                                 {parser_print("expr - opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::SubOp);}
#line 3655 "grammar.tab.cpp"
    break;

  case 122: /* expr: expr '*' opt_endl expr  */
#line 383 "grammar.y"
                                                 {parser_print("expr * opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::MulOp);}
#line 3661 "grammar.tab.cpp"
    break;

  case 123: /* expr: expr '/' opt_endl expr  */
#line 384 "grammar.y"
                                                 {parser_print("expr / opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::DivOp);}
#line 3667 "grammar.tab.cpp"
    break;

  case 124: /* expr: expr '\\' opt_endl expr  */
#line 385 "grammar.y"
                                                  {parser_print("expr \\ opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::FloorDivOp);}
#line 3673 "grammar.tab.cpp"
    break;

  case 125: /* expr: expr '^' opt_endl expr  */
#line 386 "grammar.y"
                                                  {parser_print("expr ^ opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::ExpOp);}
#line 3679 "grammar.tab.cpp"
    break;

  case 126: /* expr: expr '&' opt_endl expr  */
#line 387 "grammar.y"
                                                  {parser_print("expr & opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::StrConcatOp);}
#line 3685 "grammar.tab.cpp"
    break;

  case 127: /* expr: expr '>' opt_endl expr  */
#line 388 "grammar.y"
                                                  {parser_print("expr > opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::GtOp);}
#line 3691 "grammar.tab.cpp"
    break;

  case 128: /* expr: expr '<' opt_endl expr  */
#line 389 "grammar.y"
                                                  {parser_print("expr < opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::LtOp);}
#line 3697 "grammar.tab.cpp"
    break;

  case 129: /* expr: expr EQ opt_endl expr  */
#line 390 "grammar.y"
                                                  {parser_print("expr = opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::EqOp);}
#line 3703 "grammar.tab.cpp"
    break;

  case 130: /* expr: expr NEQ opt_endl expr  */
#line 391 "grammar.y"
                                                  {parser_print("expr NEQ expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::NeqOp);}
#line 3709 "grammar.tab.cpp"
    break;

  case 131: /* expr: expr LEQ opt_endl expr  */
#line 392 "grammar.y"
                                                  {parser_print("expr LEQ expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::LteOp);}
#line 3715 "grammar.tab.cpp"
    break;

  case 132: /* expr: expr GEQ opt_endl expr  */
#line 393 "grammar.y"
                                                  {parser_print("expr GEQ expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::GteOp);}
#line 3721 "grammar.tab.cpp"
    break;

  case 133: /* expr: expr AND opt_endl expr  */
#line 394 "grammar.y"
                                                  {parser_print("expr AND expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::AndOp);}
#line 3727 "grammar.tab.cpp"
    break;

  case 134: /* expr: expr AND_ALSO opt_endl expr  */
#line 395 "grammar.y"
                                                  {parser_print("expr AND_ALSO expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::AndAlsoOp);}
#line 3733 "grammar.tab.cpp"
    break;

  case 135: /* expr: expr OR_ELSE opt_endl expr  */
#line 396 "grammar.y"
                                                  {parser_print("expr OR_ELSE expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::OrElseOp);}
#line 3739 "grammar.tab.cpp"
    break;

  case 136: /* expr: expr OR opt_endl expr  */
#line 397 "grammar.y"
                                                  {parser_print("expr OR expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::OrOp);}
#line 3745 "grammar.tab.cpp"
    break;

  case 137: /* expr: expr XOR opt_endl expr  */
#line 398 "grammar.y"
                                                  {parser_print("expr XOR expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::XorOp);}
#line 3751 "grammar.tab.cpp"
    break;

  case 138: /* expr: expr MOD opt_endl expr  */
#line 399 "grammar.y"
                                                  {parser_print("expr MOD expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::ModOp);}
#line 3757 "grammar.tab.cpp"
    break;

  case 139: /* expr: expr LSHIFT opt_endl expr  */
#line 400 "grammar.y"
                                                  {parser_print("expr LSHIFT expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::LshiftOp);}
#line 3763 "grammar.tab.cpp"
    break;

  case 140: /* expr: expr RSHIFT opt_endl expr  */
#line 401 "grammar.y"
                                                  {parser_print("expr RSHIFT expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::RshiftOp);}
#line 3769 "grammar.tab.cpp"
    break;

  case 141: /* expr: '+' expr  */
#line 402 "grammar.y"
                                                  {parser_print("+ expr -> expr"); (yyval.Expr) = create_unary((yyvsp[0].Expr), expr_type::UnaryPlusOp);}
#line 3775 "grammar.tab.cpp"
    break;

  case 142: /* expr: '-' expr  */
#line 403 "grammar.y"
                                                  {parser_print("- expr -> expr"); (yyval.Expr) = create_unary((yyvsp[0].Expr), expr_type::UnaryMinusOp);}
#line 3781 "grammar.tab.cpp"
    break;

  case 143: /* expr: NOT expr  */
#line 404 "grammar.y"
                                                  {parser_print("Not expr"); (yyval.Expr) = create_unary((yyvsp[0].Expr), expr_type::NotOp);}
#line 3787 "grammar.tab.cpp"
    break;

  case 144: /* expr: expr IS opt_endl expr  */
#line 405 "grammar.y"
                                                  {parser_print("expr Is opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::IsOp);}
#line 3793 "grammar.tab.cpp"
    break;

  case 145: /* expr: expr ISNOT opt_endl expr  */
#line 406 "grammar.y"
                                                  {parser_print("expr IsNot opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::IsNotOp);}
#line 3799 "grammar.tab.cpp"
    break;

  case 146: /* expr: expr '(' opt_endl expr_list opt_endl ')'  */
#line 407 "grammar.y"
                                                  {parser_print("expr(expr_list) -> expr"); (yyval.Expr) = create_call_expr((yyvsp[-5].Expr), (yyvsp[-2].ExprList));}
#line 3805 "grammar.tab.cpp"
    break;

  case 147: /* expr: expr '(' opt_endl ')'  */
#line 408 "grammar.y"
                                                      {parser_print("expr() -> expr"); (yyval.Expr) = create_call_expr((yyvsp[-3].Expr));}
#line 3811 "grammar.tab.cpp"
    break;

  case 148: /* expr: cast_target '(' opt_endl expr opt_endl ')'  */
#line 409 "grammar.y"
                                                  {parser_print("cast_target (expr) -> expr"); (yyval.Expr) = create_cast((yyvsp[-5].Type), (yyvsp[-2].Expr));}
#line 3817 "grammar.tab.cpp"
    break;

  case 149: /* expr: CTYPE_KW '(' opt_endl expr ',' opt_endl type_name opt_endl ')'  */
#line 410 "grammar.y"
                                                                                    {parser_print("cast_target (expr) -> expr"); (yyval.Expr) = create_cast((yyvsp[-2].Type), (yyvsp[-5].Expr));}
#line 3823 "grammar.tab.cpp"
    break;

  case 150: /* expr: IF_KW '(' opt_endl expr ',' opt_endl expr ',' opt_endl expr opt_endl ')'  */
#line 411 "grammar.y"
                                                                                    {parser_print("if(expr, expr, expr) -> expr"); (yyval.Expr) = create_if_expr((yyvsp[-8].Expr), (yyvsp[-5].Expr), (yyvsp[-2].Expr));}
#line 3829 "grammar.tab.cpp"
    break;

  case 151: /* expr: IF_KW '(' opt_endl expr ',' opt_endl expr opt_endl ')'  */
#line 412 "grammar.y"
                                                                                    {parser_print("if(expr, expr) -> expr"); (yyval.Expr) = create_if_expr((yyvsp[-5].Expr), (yyvsp[-2].Expr));}
#line 3835 "grammar.tab.cpp"
    break;

  case 152: /* expr: expr '.' member_access_member  */
#line 413 "grammar.y"
                                                  {parser_print("expr . member_access_member -> expr"); (yyval.Expr) = create_member_access((yyvsp[-2].Expr), (yyvsp[0].Expr));}
#line 3841 "grammar.tab.cpp"
    break;

  case 153: /* expr: MYBASE_KW '.' member_access_member  */
#line 414 "grammar.y"
                                                  {parser_print("my_base . member_access_member -> expr"); (yyval.Expr) = create_mybase_access((yyvsp[0].Expr));}
#line 3847 "grammar.tab.cpp"
    break;

  case 154: /* expr: MYCLASS_KW '.' member_access_member  */
#line 415 "grammar.y"
                                                  {parser_print("my_base . member_access_member -> expr"); (yyval.Expr) = create_myclass_access((yyvsp[0].Expr));}
#line 3853 "grammar.tab.cpp"
    break;

  case 155: /* expr: NEW_KW ID  */
#line 416 "grammar.y"
                                                               {parser_print("NEW_KW ID -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[0].Id)));}
#line 3859 "grammar.tab.cpp"
    break;

  case 156: /* expr: NEW_KW ID '(' opt_endl ')'  */
#line 417 "grammar.y"
                                                           {parser_print("NEW_KW ID '(' opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-3].Id)));}
#line 3865 "grammar.tab.cpp"
    break;

  case 157: /* expr: NEW_KW ID '(' opt_endl expr_list opt_endl ')'  */
#line 418 "grammar.y"
                                                                   {parser_print("NEW_KW ID '(' opt_endl expr_list opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-5].Id)), (yyvsp[-2].ExprList));}
#line 3871 "grammar.tab.cpp"
    break;

  case 158: /* expr: NEW_KW ID '(' opt_endl ')' collection_initializer  */
#line 419 "grammar.y"
                                                                   {parser_print("NEW_KW ID '(' opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr(create_type(datatype_type::UserType, (yyvsp[-4].Id)), (yyvsp[0].ExprList));}
#line 3877 "grammar.tab.cpp"
    break;

  case 159: /* expr: NEW_KW ID '(' opt_endl expr_list opt_endl ')' collection_initializer  */
#line 420 "grammar.y"
                                                                                       {parser_print("NEW_KW ID '(' opt_endl expr_list opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr(create_type(datatype_type::UserType, (yyvsp[-6].Id)), (yyvsp[-3].ExprList), (yyvsp[0].ExprList));}
#line 3883 "grammar.tab.cpp"
    break;

  case 160: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')'  */
#line 421 "grammar.y"
                                                                                           {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-6].Id), (yyvsp[-2].TypeList)));}
#line 3889 "grammar.tab.cpp"
    break;

  case 161: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')'  */
#line 422 "grammar.y"
                                                                                       {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-9].Id), (yyvsp[-5].TypeList)));}
#line 3895 "grammar.tab.cpp"
    break;

  case 162: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl expr_list opt_endl ')'  */
#line 423 "grammar.y"
                                                                                                             {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl expr_list opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-11].Id), (yyvsp[-7].TypeList)), (yyvsp[-2].ExprList));}
#line 3901 "grammar.tab.cpp"
    break;

  case 163: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')' collection_initializer  */
#line 424 "grammar.y"
                                                                                                             {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr(create_type(datatype_type::UserType, (yyvsp[-10].Id), (yyvsp[-6].TypeList)), (yyvsp[0].ExprList));}
#line 3907 "grammar.tab.cpp"
    break;

  case 164: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl expr_list opt_endl ')' collection_initializer  */
#line 425 "grammar.y"
                                                                                                                                 {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl expr_list opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr(create_type(datatype_type::UserType, (yyvsp[-12].Id), (yyvsp[-8].TypeList)), (yyvsp[-3].ExprList), (yyvsp[0].ExprList));}
#line 3913 "grammar.tab.cpp"
    break;

  case 165: /* expr: NEW_KW primitive_type  */
#line 426 "grammar.y"
                                            {parser_print("NEW_KW primitive_type -> expr"); (yyval.Expr) = create_new_expr((yyvsp[0].Type));}
#line 3919 "grammar.tab.cpp"
    break;

  case 166: /* expr: NEW_KW primitive_type '(' opt_endl ')'  */
#line 427 "grammar.y"
                                                         {parser_print("NEW_KW primitive_type '(' opt_endl ')'-> expr"); (yyval.Expr) = create_new_expr((yyvsp[-3].Type));}
#line 3925 "grammar.tab.cpp"
    break;

  case 167: /* expr: NEW_KW primitive_type '(' opt_endl expr_list opt_endl ')'  */
#line 428 "grammar.y"
                                                                               {parser_print("NEW_KW primitive_type '(' opt_endl expr_list opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr((yyvsp[-5].Type), (yyvsp[-2].ExprList));}
#line 3931 "grammar.tab.cpp"
    break;

  case 168: /* expr: NEW_KW primitive_type '(' opt_endl ')' collection_initializer  */
#line 429 "grammar.y"
                                                                               {parser_print("NEW_KW primitive_type '(' opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr((yyvsp[-4].Type), (yyvsp[0].ExprList));}
#line 3937 "grammar.tab.cpp"
    break;

  case 169: /* expr: NEW_KW primitive_type '(' opt_endl expr_list opt_endl ')' collection_initializer  */
#line 430 "grammar.y"
                                                                                                   {parser_print("NEW_KW primitive_type '(' opt_endl expr_list opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr((yyvsp[-6].Type), (yyvsp[-3].ExprList), (yyvsp[0].ExprList));}
#line 3943 "grammar.tab.cpp"
    break;

  case 170: /* expr: collection_initializer  */
#line 431 "grammar.y"
                             {parser_print("collection_initializer -> expr"); (yyval.Expr) = create_array_literal((yyvsp[0].ExprList));}
#line 3949 "grammar.tab.cpp"
    break;

  case 171: /* cast_target: CBOOL_KW  */
#line 434 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Boolean);}
#line 3955 "grammar.tab.cpp"
    break;

  case 172: /* cast_target: CBYTE_KW  */
#line 435 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Byte);}
#line 3961 "grammar.tab.cpp"
    break;

  case 173: /* cast_target: CSBYTE_KW  */
#line 436 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::SByte);}
#line 3967 "grammar.tab.cpp"
    break;

  case 174: /* cast_target: CUSHORT_KW  */
#line 437 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::UShort);}
#line 3973 "grammar.tab.cpp"
    break;

  case 175: /* cast_target: CSHORT_KW  */
#line 438 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Short);}
#line 3979 "grammar.tab.cpp"
    break;

  case 176: /* cast_target: CINTEGER_KW  */
#line 439 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Integer);}
#line 3985 "grammar.tab.cpp"
    break;

  case 177: /* cast_target: CUINTEGER_KW  */
#line 440 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::UInteger);}
#line 3991 "grammar.tab.cpp"
    break;

  case 178: /* cast_target: CLONG_KW  */
#line 441 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Long);}
#line 3997 "grammar.tab.cpp"
    break;

  case 179: /* cast_target: CULONG_KW  */
#line 442 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::ULong);}
#line 4003 "grammar.tab.cpp"
    break;

  case 180: /* cast_target: CDATE_KW  */
#line 443 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Date);}
#line 4009 "grammar.tab.cpp"
    break;

  case 181: /* cast_target: CCHAR_KW  */
#line 444 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Char);}
#line 4015 "grammar.tab.cpp"
    break;

  case 182: /* cast_target: CSTRING_KW  */
#line 445 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::String);}
#line 4021 "grammar.tab.cpp"
    break;

  case 183: /* cast_target: CDECIMAL_KW  */
#line 446 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Decimal);}
#line 4027 "grammar.tab.cpp"
    break;

  case 184: /* cast_target: CSINGLE_KW  */
#line 447 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Single);}
#line 4033 "grammar.tab.cpp"
    break;

  case 185: /* cast_target: CDOUBLE_KW  */
#line 448 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Double);}
#line 4039 "grammar.tab.cpp"
    break;

  case 186: /* cast_target: COBJECT_KW  */
#line 449 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Object, "Object");}
#line 4045 "grammar.tab.cpp"
    break;

  case 187: /* collection_initializer: '{' opt_endl expr_list opt_endl '}'  */
#line 452 "grammar.y"
                                                                    {parser_print("{ opt_endl expr_list opt_endl } -> collection_initializer"); (yyval.ExprList) = (yyvsp[-2].ExprList);}
#line 4051 "grammar.tab.cpp"
    break;

  case 188: /* collection_initializer: '{' opt_endl '}'  */
#line 453 "grammar.y"
                                                                    {parser_print("{ opt_endl } -> collection_initializer"); (yyval.ExprList) = create_expr_list();}
#line 4057 "grammar.tab.cpp"
    break;

  case 189: /* member_access_member: ID  */
#line 456 "grammar.y"
                                        {parser_print("ID -> member_access_member"); (yyval.Expr) = create_id((yyvsp[0].Id));}
#line 4063 "grammar.tab.cpp"
    break;

  case 190: /* member_access_member: kw  */
#line 457 "grammar.y"
                                        {parser_print("kw -> member_access_member"); (yyval.Expr) = (yyvsp[0].Expr);}
#line 4069 "grammar.tab.cpp"
    break;

  case 191: /* expr_list: expr  */
#line 460 "grammar.y"
                                            {parser_print("expr -> expr_list"); (yyval.ExprList) = create_expr_list(); (yyval.ExprList)->add((yyvsp[0].Expr));}
#line 4075 "grammar.tab.cpp"
    break;

  case 192: /* expr_list: expr_list ',' opt_endl expr  */
#line 461 "grammar.y"
                                            {parser_print("expr_list ',' opt_endl expr -> expr_list"); (yyval.ExprList) = (yyvsp[-3].ExprList); (yyval.ExprList)->add((yyvsp[0].Expr));}
#line 4081 "grammar.tab.cpp"
    break;

  case 193: /* stmt: CALL_KW expr endl_list  */
#line 464 "grammar.y"
                                                    {parser_print("CALL_KW expr endl_list -> stmt"); (yyval.Stmt) = create_call_stmt((yyvsp[-1].Expr)); new_stmt = true;}
#line 4087 "grammar.tab.cpp"
    break;

  case 194: /* stmt: expr '(' opt_endl expr_list opt_endl ')' endl_list  */
#line 465 "grammar.y"
                                                               {parser_print("expr(expr_list) -> stmt"); (yyval.Stmt) = create_call_stmt((yyvsp[-6].Expr), (yyvsp[-3].ExprList));}
#line 4093 "grammar.tab.cpp"
    break;

  case 195: /* stmt: expr '(' opt_endl ')' endl_list  */
#line 466 "grammar.y"
                                                                   {parser_print("expr() -> stmt"); (yyval.Stmt) = create_call_stmt((yyvsp[-4].Expr), create_expr_list());}
#line 4099 "grammar.tab.cpp"
    break;

  case 196: /* stmt: REDIM_KW redim_clause_list endl_list  */
#line 467 "grammar.y"
                                                    {parser_print("REDIM_KW redim_clause_list endl_list -> stmt"); (yyval.Stmt) = create_redim((yyvsp[-1].Redim)); new_stmt = true;}
#line 4105 "grammar.tab.cpp"
    break;

  case 197: /* stmt: ERASE_KW expr_list endl_list  */
#line 468 "grammar.y"
                                                    {parser_print("ERASE_KW expr_list endl_list -> stmt"); (yyval.Stmt) = create_erase((yyvsp[-1].ExprList)); new_stmt = true;}
#line 4111 "grammar.tab.cpp"
    break;

  case 198: /* stmt: if_stmt  */
#line 469 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 4117 "grammar.tab.cpp"
    break;

  case 199: /* stmt: select_stmt  */
#line 470 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 4123 "grammar.tab.cpp"
    break;

  case 200: /* stmt: for_stmt  */
#line 471 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 4129 "grammar.tab.cpp"
    break;

  case 201: /* stmt: foreach_stmt  */
#line 472 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 4135 "grammar.tab.cpp"
    break;

  case 202: /* stmt: DO_KW endl_list opt_block LOOP_KW endl_list  */
#line 473 "grammar.y"
                                                    {parser_print("DO_KW endl_list opt_block LOOP_KW endl_list"); (yyval.Stmt) = create_do_infinite_loop((yyvsp[-2].Block)); new_stmt = true;}
#line 4141 "grammar.tab.cpp"
    break;

  case 203: /* stmt: do_while_stmt  */
#line 474 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 4147 "grammar.tab.cpp"
    break;

  case 204: /* stmt: do_until_stmt  */
#line 475 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 4153 "grammar.tab.cpp"
    break;

  case 205: /* stmt: while_stmt  */
#line 476 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 4159 "grammar.tab.cpp"
    break;

  case 206: /* stmt: var_declaration  */
#line 477 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 4165 "grammar.tab.cpp"
    break;

  case 207: /* stmt: expr '=' opt_endl expr endl_list  */
#line 478 "grammar.y"
                                                    {parser_print("expr '=' opt_endl expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::Assign); new_stmt = true; }
#line 4171 "grammar.tab.cpp"
    break;

  case 208: /* stmt: expr ADD_ASSIGN opt_endl expr endl_list  */
#line 479 "grammar.y"
                                                    {parser_print("expr ADD_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::AddAssign); new_stmt = true;}
#line 4177 "grammar.tab.cpp"
    break;

  case 209: /* stmt: expr SUB_ASSIGN opt_endl expr endl_list  */
#line 480 "grammar.y"
                                                    {parser_print("expr SUB_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::SubAssign); new_stmt = true;}
#line 4183 "grammar.tab.cpp"
    break;

  case 210: /* stmt: expr MUL_ASSIGN opt_endl expr endl_list  */
#line 481 "grammar.y"
                                                    {parser_print("expr MUL_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::MulAssign); new_stmt = true;}
#line 4189 "grammar.tab.cpp"
    break;

  case 211: /* stmt: expr DIV_ASSIGN opt_endl expr endl_list  */
#line 482 "grammar.y"
                                                    {parser_print("expr DIV_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::DivAssign); new_stmt = true;}
#line 4195 "grammar.tab.cpp"
    break;

  case 212: /* stmt: expr FLOORDIV_ASSIGN opt_endl expr endl_list  */
#line 483 "grammar.y"
                                                    {parser_print("expr FLOORDIV_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::FloorDivAssign); new_stmt = true;}
#line 4201 "grammar.tab.cpp"
    break;

  case 213: /* stmt: expr EXP_ASSIGN opt_endl expr endl_list  */
#line 484 "grammar.y"
                                                    {parser_print("expr EXP_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::ExpAssign); new_stmt = true;}
#line 4207 "grammar.tab.cpp"
    break;

  case 214: /* stmt: expr STRCAT_ASSIGN opt_endl expr endl_list  */
#line 485 "grammar.y"
                                                    {parser_print("expr STRCAT_ASSIGN expr endl_list -> stmt");(yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::StrConcatAssign); new_stmt = true;}
#line 4213 "grammar.tab.cpp"
    break;

  case 215: /* stmt: expr LSHIFT_ASSIGN opt_endl expr endl_list  */
#line 486 "grammar.y"
                                                    {parser_print("expr LSHIFT_ASSIGN expr endl_list -> stmt");(yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::LshiftAssign); new_stmt = true;}
#line 4219 "grammar.tab.cpp"
    break;

  case 216: /* stmt: expr RSHIFT_ASSIGN opt_endl expr endl_list  */
#line 487 "grammar.y"
                                                    {parser_print("expr RSHIFT_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::RshiftAssign); new_stmt = true;}
#line 4225 "grammar.tab.cpp"
    break;

  case 217: /* stmt: RETURN_KW endl_list  */
#line 488 "grammar.y"
                                                    {parser_print("RETURN_KW endl_list -> stmt"); (yyval.Stmt) = create_return(); new_stmt = true;}
#line 4231 "grammar.tab.cpp"
    break;

  case 218: /* stmt: RETURN_KW expr endl_list  */
#line 489 "grammar.y"
                                                    {parser_print("RETURN_KW expr endl_list -> stmt"); (yyval.Stmt) = create_return((yyvsp[-1].Expr)); new_stmt = true;}
#line 4237 "grammar.tab.cpp"
    break;

  case 219: /* stmt: CONTINUE_KW DO_KW endl_list  */
#line 490 "grammar.y"
                                                    {parser_print("CONTINUE_KW DO_KW endl_list -> stmt"); (yyval.Stmt) = create_continue(stmt_type::ContinueDo); new_stmt = true;}
#line 4243 "grammar.tab.cpp"
    break;

  case 220: /* stmt: CONTINUE_KW FOR_KW endl_list  */
#line 491 "grammar.y"
                                                    {parser_print("CONTINUE_KW FOR_KW endl_list -> stmt"); (yyval.Stmt) = create_continue(stmt_type::ContinueFor); new_stmt = true;}
#line 4249 "grammar.tab.cpp"
    break;

  case 221: /* stmt: CONTINUE_KW WHILE_KW endl_list  */
#line 492 "grammar.y"
                                                    {parser_print("CONTINUE_KW WHILE_KW endl_list -> stmt"); (yyval.Stmt) = create_continue(stmt_type::ContinueWhile); new_stmt = true;}
#line 4255 "grammar.tab.cpp"
    break;

  case 222: /* stmt: EXIT_KW DO_KW endl_list  */
#line 493 "grammar.y"
                                                    {parser_print("EXIT_KW DO_KW endl_list -> stmt"); (yyval.Stmt) = create_exit(stmt_type::ExitDo); new_stmt = true;}
#line 4261 "grammar.tab.cpp"
    break;

  case 223: /* stmt: EXIT_KW FOR_KW endl_list  */
#line 494 "grammar.y"
                                                    {parser_print("EXIT_KW FOR_KW endl_list -> stmt"); (yyval.Stmt) = create_exit(stmt_type::ExitFor); new_stmt = true;}
#line 4267 "grammar.tab.cpp"
    break;

  case 224: /* stmt: EXIT_KW WHILE_KW endl_list  */
#line 495 "grammar.y"
                                                    {parser_print("EXIT_KW WHILE_KW endl_list -> stmt");(yyval.Stmt) = create_exit(stmt_type::ExitWhile); new_stmt = true;}
#line 4273 "grammar.tab.cpp"
    break;

  case 225: /* stmt: EXIT_KW SELECT_KW endl_list  */
#line 496 "grammar.y"
                                                    {parser_print("EXIT_KW SELECT_KW endl_list -> stmt");(yyval.Stmt) = create_exit(stmt_type::ExitSelect); new_stmt = true;}
#line 4279 "grammar.tab.cpp"
    break;

  case 226: /* redim_clause: expr '(' opt_endl expr_list opt_endl ')'  */
#line 499 "grammar.y"
                                                                       { parser_print("expr '(' opt_endl expr_list opt_endl ')' -> redim_clause"); (yyval.RedimNode) = create_redim_clause((yyvsp[-5].Expr), (yyvsp[-2].ExprList)); }
#line 4285 "grammar.tab.cpp"
    break;

  case 227: /* redim_clause_list: redim_clause  */
#line 502 "grammar.y"
                                                                     { parser_print("redim_clause -> redim_clause_list"); (yyval.Redim) = create_redim_clause_list(); (yyval.Redim)->add((yyvsp[0].RedimNode)); }
#line 4291 "grammar.tab.cpp"
    break;

  case 228: /* redim_clause_list: redim_clause_list ',' opt_endl redim_clause  */
#line 503 "grammar.y"
                                                                     { parser_print("redim_clause_list ',' opt_endl redim_clause -> redim_clause_list"); (yyval.Redim) = (yyvsp[-3].Redim); (yyval.Redim)->add((yyvsp[0].RedimNode)); }
#line 4297 "grammar.tab.cpp"
    break;

  case 229: /* if_stmt: IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list block END_IF endl_list  */
#line 506 "grammar.y"
                                                                                                                        { parser_print("IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list block END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-9].Expr), (yyvsp[-6].Block), (yyvsp[-5].Block), (yyvsp[-2].Block)); }
#line 4303 "grammar.tab.cpp"
    break;

  case 230: /* if_stmt: IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list block END_IF endl_list  */
#line 507 "grammar.y"
                                                                                                                            { parser_print("IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list block END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-8].Expr), nullptr, (yyvsp[-5].Block), (yyvsp[-2].Block)); }
#line 4309 "grammar.tab.cpp"
    break;

  case 231: /* if_stmt: IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list END_IF endl_list  */
#line 508 "grammar.y"
                                                                                                                            { parser_print("IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-8].Expr), (yyvsp[-5].Block), (yyvsp[-4].Block), nullptr); }
#line 4315 "grammar.tab.cpp"
    break;

  case 232: /* if_stmt: IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list END_IF endl_list  */
#line 509 "grammar.y"
                                                                                                                            { parser_print("IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-7].Expr), nullptr, (yyvsp[-4].Block), nullptr); }
#line 4321 "grammar.tab.cpp"
    break;

  case 233: /* if_stmt: IF_KW expr THEN_KW endl_list block else_if_stmts END_IF endl_list  */
#line 510 "grammar.y"
                                                                                                                        { parser_print("IF_KW expr THEN_KW endl_list block else_if_stmts END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-6].Expr), (yyvsp[-3].Block), (yyvsp[-2].Block), nullptr); }
#line 4327 "grammar.tab.cpp"
    break;

  case 234: /* if_stmt: IF_KW expr THEN_KW endl_list else_if_stmts END_IF endl_list  */
#line 511 "grammar.y"
                                                                                                                            { parser_print("IF_KW expr THEN_KW endl_list else_if_stmts END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-5].Expr), nullptr, (yyvsp[-2].Block), nullptr); }
#line 4333 "grammar.tab.cpp"
    break;

  case 235: /* else_if_stmts: %empty  */
#line 514 "grammar.y"
                                                                               { parser_print("empty -> else_if_stmts"); (yyval.Block) = create_block(); }
#line 4339 "grammar.tab.cpp"
    break;

  case 236: /* else_if_stmts: else_if_stmts ELSEIF_KW expr THEN_KW endl_list block  */
#line 515 "grammar.y"
                                                                               { parser_print("else_if_stmts ELSEIF_KW expr THEN_KW endl_list block -> else_if_stmts"); (yyval.Block) = (yyvsp[-5].Block); (yyval.Block)->add(create_elseif((yyvsp[-3].Expr), (yyvsp[0].Block))); }
#line 4345 "grammar.tab.cpp"
    break;

  case 237: /* else_if_stmts: else_if_stmts ELSEIF_KW expr THEN_KW endl_list  */
#line 516 "grammar.y"
                                                                                           { parser_print("else_if_stmts ELSEIF_KW expr THEN_KW endl_list -> else_if_stmts"); (yyval.Block) = (yyvsp[-4].Block); (yyval.Block)->add(create_elseif((yyvsp[-2].Expr), nullptr)); }
#line 4351 "grammar.tab.cpp"
    break;

  case 238: /* select_stmt: SELECT_KW expr endl_list case_stmts END_SELECT endl_list  */
#line 519 "grammar.y"
                                                                                         { parser_print("SELECT_KW expr endl_list case_stmts END_SELECT endl_list -> select_stmt"); (yyval.Stmt) = create_select_stmt((yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4357 "grammar.tab.cpp"
    break;

  case 239: /* select_stmt: SELECT_KW CASE_KW expr endl_list case_stmts END_SELECT endl_list  */
#line 520 "grammar.y"
                                                                                         { parser_print("SELECT_KW CASE_KW expr endl_list case_stmts END_SELECT endl_list -> select_stmt"); (yyval.Stmt) = create_select_stmt((yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4363 "grammar.tab.cpp"
    break;

  case 240: /* case_condition_branch: CASE_KW expr endl_list block  */
#line 523 "grammar.y"
                                                                                         { parser_print("CASE_KW expr endl_list block -> case_condition_branch"); (yyval.Stmt) = create_case_condition_branch((yyvsp[-2].Expr), (yyvsp[0].Block)); }
#line 4369 "grammar.tab.cpp"
    break;

  case 241: /* case_condition_branch: CASE_KW expr endl_list  */
#line 524 "grammar.y"
                                                                                                             { parser_print("CASE_KW expr endl_list -> case_condition_branch"); (yyval.Stmt) = create_case_condition_branch((yyvsp[-1].Expr), nullptr); }
#line 4375 "grammar.tab.cpp"
    break;

  case 242: /* case_condition_branch: CASE_KW expr TO_KW expr endl_list block  */
#line 525 "grammar.y"
                                                                                         { parser_print("CASE_KW expr TO_KW expr endl_list block -> case_condition_branch"); (yyval.Stmt) = create_case_range_branch((yyvsp[-4].Expr), (yyvsp[-2].Expr), (yyvsp[0].Block)); }
#line 4381 "grammar.tab.cpp"
    break;

  case 243: /* case_condition_branch: CASE_KW expr TO_KW expr endl_list  */
#line 526 "grammar.y"
                                                                                                             { parser_print("CASE_KW expr TO_KW expr endl_list -> case_condition_branch"); (yyval.Stmt) = create_case_range_branch((yyvsp[-3].Expr), (yyvsp[-1].Expr), nullptr); }
#line 4387 "grammar.tab.cpp"
    break;

  case 244: /* case_condition_branches: case_condition_branch  */
#line 529 "grammar.y"
                                                                                 { parser_print("case_condition_branch -> case_condition_branches"); (yyval.Block) = create_block(); }
#line 4393 "grammar.tab.cpp"
    break;

  case 245: /* case_condition_branches: case_condition_branches case_condition_branch  */
#line 530 "grammar.y"
                                                                                 { parser_print("case_condition_branches case_condition_branch -> case_condition_branches"); (yyval.Block) = (yyvsp[-1].Block); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4399 "grammar.tab.cpp"
    break;

  case 246: /* case_else_stmt: CASE_KW ELSE_KW endl_list opt_block  */
#line 533 "grammar.y"
                                                                                 { parser_print("CASE_KW ELSE_KW endl_list opt_block -> case_else_stmt"); (yyval.Stmt) = create_case_else_stmt((yyvsp[0].Block)); }
#line 4405 "grammar.tab.cpp"
    break;

  case 247: /* case_stmts: case_condition_branches  */
#line 536 "grammar.y"
                                                                                 { parser_print("case_condition_branches -> case_stmts"); (yyval.Block) = (yyvsp[0].Block); }
#line 4411 "grammar.tab.cpp"
    break;

  case 248: /* case_stmts: case_else_stmt  */
#line 537 "grammar.y"
                                                                                 { parser_print("case_else_stmt -> case_stmts"); (yyval.Block) = create_block(); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4417 "grammar.tab.cpp"
    break;

  case 249: /* case_stmts: case_condition_branches case_else_stmt  */
#line 538 "grammar.y"
                                                                                 { parser_print("case_condition_branches case_else_stmt -> case_stmts"); (yyval.Block) = (yyvsp[-1].Block); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4423 "grammar.tab.cpp"
    break;

  case 250: /* case_stmts: %empty  */
#line 539 "grammar.y"
                                                                                 { parser_print("empty -> case_stmts"); (yyval.Block) = create_block();}
#line 4429 "grammar.tab.cpp"
    break;

  case 251: /* while_stmt: WHILE_KW expr endl_list block END_WHILE endl_list  */
#line 542 "grammar.y"
                                                                                 { parser_print("WHILE_KW expr endl_list block END_WHILE endl_list -> while_stmt"); (yyval.Stmt) = create_while_stmt((yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4435 "grammar.tab.cpp"
    break;

  case 252: /* while_stmt: WHILE_KW expr endl_list END_WHILE endl_list  */
#line 543 "grammar.y"
                                                                                 { parser_print("WHILE_KW expr endl_list END_WHILE endl_list -> while_stmt"); (yyval.Stmt) = create_while_stmt((yyvsp[-3].Expr), create_block()); }
#line 4441 "grammar.tab.cpp"
    break;

  case 253: /* for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list block NEXT_KW endl_list  */
#line 546 "grammar.y"
                                                                                                                                { parser_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list block NEXT_KW endl_list -> for_stmt"); (yyval.Stmt) = create_for_stmt((yyvsp[-9].Var)->type, (yyvsp[-9].Var)->varName, (yyvsp[-6].Expr), (yyvsp[-4].Expr), create_int(1), (yyvsp[-2].Block)); }
#line 4447 "grammar.tab.cpp"
    break;

  case 254: /* for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list NEXT_KW endl_list  */
#line 547 "grammar.y"
                                                                                                                                { parser_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list NEXT_KW endl_list -> for_stmt"); (yyval.Stmt) = create_for_stmt((yyvsp[-8].Var)->type, (yyvsp[-8].Var)->varName, (yyvsp[-5].Expr), (yyvsp[-3].Expr), create_int(1), create_block()); }
#line 4453 "grammar.tab.cpp"
    break;

  case 255: /* for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list block NEXT_KW endl_list  */
#line 548 "grammar.y"
                                                                                                                                { parser_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list block NEXT_KW endl_list -> for_stmt"); (yyval.Stmt) = create_for_stmt((yyvsp[-11].Var)->type, (yyvsp[-11].Var)->varName, (yyvsp[-8].Expr), (yyvsp[-6].Expr), (yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4459 "grammar.tab.cpp"
    break;

  case 256: /* for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list NEXT_KW endl_list  */
#line 549 "grammar.y"
                                                                                                                                        { parser_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list NEXT_KW endl_list -> for_stmt"); (yyval.Stmt) = create_for_stmt((yyvsp[-10].Var)->type, (yyvsp[-10].Var)->varName, (yyvsp[-7].Expr), (yyvsp[-5].Expr), (yyvsp[-3].Expr), create_block()); }
#line 4465 "grammar.tab.cpp"
    break;

  case 257: /* for_loop_variable: ID  */
#line 552 "grammar.y"
                                                      { parser_print("ID -> for_loop_variable"); (yyval.Var) = create_var_declarator((yyvsp[0].Id)); }
#line 4471 "grammar.tab.cpp"
    break;

  case 258: /* for_loop_variable: ID AS_KW type_name  */
#line 553 "grammar.y"
                                                      { parser_print("ID AS_KW type_name -> for_loop_variable"); (yyval.Var) = create_var_declarator((yyvsp[0].Type), (yyvsp[-2].Id)); }
#line 4477 "grammar.tab.cpp"
    break;

  case 259: /* foreach_stmt: FOR_KW EACH_KW for_loop_variable opt_endl IN_KW endl_list expr endl_list opt_block NEXT_KW endl_list  */
#line 556 "grammar.y"
                                                                                                                              { parser_print("FOR_KW EACH_KW for_loop_variable opt_endl IN_KW endl_list expr endl_list opt_block NEXT_KW endl_list -> foreach_stmt"); (yyval.Stmt) = create_foreach_stmt((yyvsp[-8].Var)->type, (yyvsp[-8].Var)->varName, (yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4483 "grammar.tab.cpp"
    break;

  case 260: /* foreach_stmt: FOR_KW EACH_KW for_loop_variable opt_endl IN_KW expr endl_list opt_block NEXT_KW endl_list  */
#line 557 "grammar.y"
                                                                                                                              { parser_print("FOR_KW EACH_KW for_loop_variable opt_endl IN_KW expr endl_list opt_block NEXT_KW endl_list -> foreach_stmt"); (yyval.Stmt) = create_foreach_stmt((yyvsp[-7].Var)->type, (yyvsp[-7].Var)->varName, (yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4489 "grammar.tab.cpp"
    break;

  case 261: /* do_while_stmt: DO_KW endl_list opt_block LOOP_KW WHILE_KW expr endl_list  */
#line 560 "grammar.y"
                                                                                                                              { parser_print("DO_KW endl_list opt_block LOOP_KW WHILE_KW expr endl_list -> do_while_stmt"); (yyval.Stmt) = create_do_while_stmt((yyvsp[-4].Block), (yyvsp[-1].Expr)); }
#line 4495 "grammar.tab.cpp"
    break;

  case 262: /* do_while_stmt: DO_KW WHILE_KW expr endl_list opt_block LOOP_KW endl_list  */
#line 561 "grammar.y"
                                                                                                                              { parser_print("DO_KW WHILE_KW expr endl_list opt_block LOOP_KW endl_list -> do_while_stmt"); (yyval.Stmt) = create_do_while_stmt((yyvsp[-2].Block), (yyvsp[-4].Expr)); }
#line 4501 "grammar.tab.cpp"
    break;

  case 263: /* do_until_stmt: DO_KW endl_list opt_block LOOP_KW UNTIL_KW expr endl_list  */
#line 564 "grammar.y"
                                                                                                                              { parser_print("DO_KW endl_list opt_block LOOP_KW UNTIL_KW expr endl_list -> do_until_stmt"); (yyval.Stmt) = create_do_until_stmt((yyvsp[-4].Block), (yyvsp[-1].Expr)); }
#line 4507 "grammar.tab.cpp"
    break;

  case 264: /* do_until_stmt: DO_KW UNTIL_KW expr endl_list opt_block LOOP_KW endl_list  */
#line 565 "grammar.y"
                                                                                                                              { parser_print("DO_KW UNTIL_KW expr endl_list opt_block LOOP_KW endl_list -> do_until_stmt"); (yyval.Stmt) = create_do_until_stmt((yyvsp[-2].Block), (yyvsp[-4].Expr)); }
#line 4513 "grammar.tab.cpp"
    break;

  case 265: /* opt_block: %empty  */
#line 568 "grammar.y"
                               { parser_print("empty -> opt_block"); (yyval.Block) = create_block(); }
#line 4519 "grammar.tab.cpp"
    break;

  case 266: /* opt_block: block  */
#line 569 "grammar.y"
                               { parser_print("block -> opt_block"); (yyval.Block) = (yyvsp[0].Block); }
#line 4525 "grammar.tab.cpp"
    break;

  case 267: /* block: stmt  */
#line 572 "grammar.y"
                               { parser_print("stmt -> block"); (yyval.Block) = create_block(); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4531 "grammar.tab.cpp"
    break;

  case 268: /* block: block stmt  */
#line 573 "grammar.y"
                               { parser_print("block stmt -> block"); (yyval.Block) = (yyvsp[-1].Block); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4537 "grammar.tab.cpp"
    break;

  case 269: /* variable_name: ID  */
#line 576 "grammar.y"
                                              { parser_print("ID -> variable_name"); (yyval.Var) = create_var_declarator((yyvsp[0].Id)); }
#line 4543 "grammar.tab.cpp"
    break;

  case 270: /* variable_name: ID array_modifier  */
#line 577 "grammar.y"
                                              { parser_print("ID array_modifier -> variable_name"); (yyval.Var) = create_array_var_declarator((yyvsp[-1].Id), (yyvsp[0].Expr)); }
#line 4549 "grammar.tab.cpp"
    break;

  case 271: /* array_modifier: '(' opt_endl expr opt_endl ')'  */
#line 580 "grammar.y"
                                               { parser_print("'(' ENDL ')' -> array_modifier"); (yyval.Expr) = (yyvsp[-2].Expr);}
#line 4555 "grammar.tab.cpp"
    break;

  case 272: /* array_modifier: '(' ')'  */
#line 581 "grammar.y"
                                               { parser_print("'(' ')' -> array_modifier"); (yyval.Expr) = nullptr;}
#line 4561 "grammar.tab.cpp"
    break;

  case 273: /* var_declarator: variable_name  */
#line 585 "grammar.y"
                                                                     { parser_print("variable_name -> var_declarator"); (yyval.Var) = (yyvsp[0].Var); }
#line 4567 "grammar.tab.cpp"
    break;

  case 274: /* var_declarator: variable_name AS_KW type_name  */
#line 586 "grammar.y"
                                                                     { parser_print("variable_name AS_KW type_name -> var_declarator"); (yyval.Var) = append_var_declarator((yyvsp[-2].Var), (yyvsp[0].Type), nullptr); }
#line 4573 "grammar.tab.cpp"
    break;

  case 275: /* var_declarator: variable_name '=' expr  */
#line 587 "grammar.y"
                                                                     { parser_print("variable_name '=' expr -> var_declarator"); (yyval.Var) = append_var_declarator((yyvsp[-2].Var), nullptr, (yyvsp[0].Expr)); }
#line 4579 "grammar.tab.cpp"
    break;

  case 276: /* var_declarator: variable_name AS_KW type_name '=' expr  */
#line 588 "grammar.y"
                                                                     { parser_print("variable_name AS_KW type_name '=' expr -> var_declarator"); (yyval.Var) = append_var_declarator((yyvsp[-4].Var), (yyvsp[-2].Type), (yyvsp[0].Expr)); }
#line 4585 "grammar.tab.cpp"
    break;

  case 277: /* var_declaration: DIM_KW var_declarator endl_list  */
#line 591 "grammar.y"
                                                                     { parser_print("DIM_KW var_declarator endl_list -> var_declaration"); (yyval.Stmt) = create_var_declaration((yyvsp[-1].Var), var_type::DIM); }
#line 4591 "grammar.tab.cpp"
    break;

  case 278: /* var_declaration: CONST_KW var_declarator endl_list  */
#line 592 "grammar.y"
                                                                     { parser_print("CONST_KW var_declarator endl_list -> var_declaration"); (yyval.Stmt) = create_var_declaration((yyvsp[-1].Var), var_type::CONST); }
#line 4597 "grammar.tab.cpp"
    break;

  case 279: /* type_name: ID  */
#line 596 "grammar.y"
              {parser_print("ID -> type_name"); (yyval.Type) = create_type(datatype_type::UserType, (yyvsp[0].Id));}
#line 4603 "grammar.tab.cpp"
    break;

  case 280: /* type_name: ID '(' opt_endl OF_KW type_list opt_endl ')'  */
#line 597 "grammar.y"
                                                        {parser_print("ID '(' opt_endl OF_KW type_list opt_endl ')' -> type_name"); (yyval.Type) = create_type(datatype_type::UserType, (yyvsp[-6].Id), (yyvsp[-2].TypeList));}
#line 4609 "grammar.tab.cpp"
    break;

  case 281: /* type_name: primitive_type  */
#line 598 "grammar.y"
                          {parser_print("primitive_type -> type_name"); (yyval.Type) = (yyvsp[0].Type);}
#line 4615 "grammar.tab.cpp"
    break;

  case 282: /* type_name: ID '(' opt_endl ')'  */
#line 599 "grammar.y"
                               {parser_print("ID '(' opt_endl ')' -> type_name"); (yyval.Type) = create_array_type(create_type(datatype_type::UserType, (yyvsp[-3].Id)));}
#line 4621 "grammar.tab.cpp"
    break;

  case 283: /* type_name: ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')'  */
#line 600 "grammar.y"
                                                                         {parser_print("ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')'  -> type_name"); (yyval.Type) = create_array_type(create_type(datatype_type::UserType, (yyvsp[-9].Id), (yyvsp[-5].TypeList)));}
#line 4627 "grammar.tab.cpp"
    break;

  case 284: /* type_name: primitive_type '(' opt_endl ')'  */
#line 601 "grammar.y"
                                           {parser_print("primitive_type '(' opt_endl ')' -> type_name"); (yyval.Type) = create_array_type((yyvsp[-3].Type));}
#line 4633 "grammar.tab.cpp"
    break;

  case 285: /* simple_type_name: ID  */
#line 604 "grammar.y"
                            {parser_print("ID -> simple_type_name"); (yyval.Type) = create_type(datatype_type::UserType, (yyvsp[0].Id));}
#line 4639 "grammar.tab.cpp"
    break;

  case 286: /* simple_type_name: ID '(' opt_endl OF_KW type_list opt_endl ')'  */
#line 605 "grammar.y"
                                                               {parser_print("ID '(' opt_endl OF_KW type_list opt_endl ')' -> simple_type_name"); (yyval.Type) = create_type(datatype_type::UserType, (yyvsp[-6].Id), (yyvsp[-2].TypeList));}
#line 4645 "grammar.tab.cpp"
    break;

  case 287: /* simple_type_name: primitive_type  */
#line 606 "grammar.y"
                                   {parser_print("primitive_type -> simple_type_name"); (yyval.Type) = (yyvsp[0].Type);}
#line 4651 "grammar.tab.cpp"
    break;

  case 288: /* primitive_type: BYTE_KW  */
#line 609 "grammar.y"
                             { parser_print("BYTE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Byte); }
#line 4657 "grammar.tab.cpp"
    break;

  case 289: /* primitive_type: SBYTE_KW  */
#line 610 "grammar.y"
                             { parser_print("SBYTE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::SByte); }
#line 4663 "grammar.tab.cpp"
    break;

  case 290: /* primitive_type: USHORT_KW  */
#line 611 "grammar.y"
                             { parser_print("USHORT_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::UShort); }
#line 4669 "grammar.tab.cpp"
    break;

  case 291: /* primitive_type: SHORT_KW  */
#line 612 "grammar.y"
                             { parser_print("SHORT_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Short); }
#line 4675 "grammar.tab.cpp"
    break;

  case 292: /* primitive_type: UINTEGER_KW  */
#line 613 "grammar.y"
                             { parser_print("UINTEGER_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::UInteger); }
#line 4681 "grammar.tab.cpp"
    break;

  case 293: /* primitive_type: INTEGER_KW  */
#line 614 "grammar.y"
                             { parser_print("INTEGER_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Integer); }
#line 4687 "grammar.tab.cpp"
    break;

  case 294: /* primitive_type: ULONG_KW  */
#line 615 "grammar.y"
                             { parser_print("ULONG_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::ULong); }
#line 4693 "grammar.tab.cpp"
    break;

  case 295: /* primitive_type: LONG_KW  */
#line 616 "grammar.y"
                             { parser_print("LONG_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Long); }
#line 4699 "grammar.tab.cpp"
    break;

  case 296: /* primitive_type: BOOLEAN_KW  */
#line 617 "grammar.y"
                             { parser_print("BOOLEAN_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Boolean); }
#line 4705 "grammar.tab.cpp"
    break;

  case 297: /* primitive_type: DATE_KW  */
#line 618 "grammar.y"
                             { parser_print("DATE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Date); }
#line 4711 "grammar.tab.cpp"
    break;

  case 298: /* primitive_type: CHAR_KW  */
#line 619 "grammar.y"
                             { parser_print("CHAR_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Char); }
#line 4717 "grammar.tab.cpp"
    break;

  case 299: /* primitive_type: STRING_KW  */
#line 620 "grammar.y"
                             { parser_print("STRING_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::String); }
#line 4723 "grammar.tab.cpp"
    break;

  case 300: /* primitive_type: DECIMAL_KW  */
#line 621 "grammar.y"
                             { parser_print("DECIMAL_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Decimal); }
#line 4729 "grammar.tab.cpp"
    break;

  case 301: /* primitive_type: SINGLE_KW  */
#line 622 "grammar.y"
                             { parser_print("SINGLE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Single); }
#line 4735 "grammar.tab.cpp"
    break;

  case 302: /* primitive_type: DOUBLE_KW  */
#line 623 "grammar.y"
                             { parser_print("DOUBLE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Double); }
#line 4741 "grammar.tab.cpp"
    break;

  case 303: /* primitive_type: OBJECT_KW  */
#line 624 "grammar.y"
                             { parser_print("OBJECT_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Object); }
#line 4747 "grammar.tab.cpp"
    break;

  case 304: /* type_list: simple_type_name  */
#line 627 "grammar.y"
                                                              { parser_print("simple_type_name -> type_list"); (yyval.TypeList) = create_type_list(); (yyval.TypeList)->add((yyvsp[0].Type)); }
#line 4753 "grammar.tab.cpp"
    break;

  case 305: /* type_list: type_list ',' opt_endl simple_type_name  */
#line 628 "grammar.y"
                                                              { parser_print("type_list ',' opt_endl simple_type_name -> type_list"); (yyval.TypeList) = (yyvsp[-3].TypeList); (yyval.TypeList)->add((yyvsp[0].Type));  }
#line 4759 "grammar.tab.cpp"
    break;

  case 306: /* id_list: ID  */
#line 631 "grammar.y"
                                                              { parser_print("ID -> id_list"); (yyval.IdList) = create_id_list(); (yyval.IdList)->add(*(yyvsp[0].Id)); }
#line 4765 "grammar.tab.cpp"
    break;

  case 307: /* id_list: id_list ',' opt_endl ID  */
#line 632 "grammar.y"
                                                              { parser_print("id_list ',' opt_endl ID -> id_list"); (yyval.IdList) = (yyvsp[-3].IdList); (yyval.IdList)->add(*(yyvsp[0].Id)); }
#line 4771 "grammar.tab.cpp"
    break;

  case 308: /* function_signature: FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' AS_KW type_name  */
#line 635 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-7].Id), (yyvsp[-4].Vars), (yyvsp[0].Type), false); }
#line 4777 "grammar.tab.cpp"
    break;

  case 309: /* function_signature: FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')'  */
#line 636 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-5].Id), (yyvsp[-2].Vars), object_type(), false); }
#line 4783 "grammar.tab.cpp"
    break;

  case 310: /* function_signature: FUNCTION_KW ID '(' opt_endl ')' AS_KW type_name  */
#line 637 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID '(' opt_endl ')' AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-5].Id), nullptr, (yyvsp[0].Type), false); }
#line 4789 "grammar.tab.cpp"
    break;

  case 311: /* function_signature: FUNCTION_KW ID '(' opt_endl ')'  */
#line 638 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID '(' opt_endl ')' -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-3].Id), nullptr, object_type(), false); }
#line 4795 "grammar.tab.cpp"
    break;

  case 312: /* function_signature: FUNCTION_KW ID AS_KW type_name  */
#line 639 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-2].Id), nullptr, (yyvsp[0].Type), false); }
#line 4801 "grammar.tab.cpp"
    break;

  case 313: /* function_signature: FUNCTION_KW ID  */
#line 640 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID -> function_signature"); (yyval.Procedure) = create_function((yyvsp[0].Id), nullptr, object_type(), false); }
#line 4807 "grammar.tab.cpp"
    break;

  case 314: /* sub_signature: SUB_KW ID '(' opt_endl function_parameters opt_endl ')'  */
#line 643 "grammar.y"
                                                                                          { parser_print("SUB_KW ID '(' opt_endl function_parameters opt_endl ')' -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[-5].Id), (yyvsp[-2].Vars), nullptr, true); }
#line 4813 "grammar.tab.cpp"
    break;

  case 315: /* sub_signature: SUB_KW ID '(' opt_endl ')'  */
#line 644 "grammar.y"
                                                                                          { parser_print("SUB_KW ID '(' opt_endl ')' -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[-3].Id), nullptr, nullptr, true);}
#line 4819 "grammar.tab.cpp"
    break;

  case 316: /* sub_signature: SUB_KW ID  */
#line 645 "grammar.y"
                                                                                          { parser_print("SUB_KW ID -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[0].Id), nullptr, nullptr, true); }
#line 4825 "grammar.tab.cpp"
    break;

  case 317: /* function_declaration: opt_procedure_modifiers function_signature endl_list block END_FUNCTION endl_list  */
#line 648 "grammar.y"
                                                                                                            { parser_print("opt_procedure_modifiers function_signature endl_list block END_FUNCTION endl_list -> function_declaration"); (yyval.Procedure) = (yyvsp[-4].Procedure); (yyval.Procedure)->block = (yyvsp[-2].Block); (yyval.Procedure)->isStatic = (yyvsp[-5].Bool); }
#line 4831 "grammar.tab.cpp"
    break;

  case 318: /* function_declaration: opt_procedure_modifiers function_signature endl_list END_FUNCTION endl_list  */
#line 649 "grammar.y"
                                                                                                            { parser_print("opt_procedure_modifiers function_signature endl_list END_FUNCTION endl_list -> function_declaration"); (yyval.Procedure) = (yyvsp[-3].Procedure); (yyval.Procedure)->block = create_block(); (yyval.Procedure)->isStatic = (yyvsp[-4].Bool); }
#line 4837 "grammar.tab.cpp"
    break;

  case 319: /* sub_declaration: opt_procedure_modifiers sub_signature endl_list block END_SUB endl_list  */
#line 652 "grammar.y"
                                                                                                  { parser_print("opt_procedure_modifiers sub_signature endl_list block END_SUB endl_list -> sub_declaration"); (yyval.Procedure) = (yyvsp[-4].Procedure); (yyval.Procedure)->block = (yyvsp[-2].Block); (yyval.Procedure)->isStatic = (yyvsp[-5].Bool); }
#line 4843 "grammar.tab.cpp"
    break;

  case 320: /* sub_declaration: opt_procedure_modifiers sub_signature endl_list END_SUB endl_list  */
#line 653 "grammar.y"
                                                                                                              { parser_print("opt_procedure_modifiers sub_signature endl_list END_SUB endl_list -> sub_declaration"); (yyval.Procedure) = (yyvsp[-3].Procedure); (yyval.Procedure)->block = create_block(); (yyval.Procedure)->isStatic = (yyvsp[-4].Bool); }
#line 4849 "grammar.tab.cpp"
    break;

  case 321: /* opt_procedure_modifiers: SHARED_KW  */
#line 656 "grammar.y"
                                                    { parser_print("SHARED_KW -> opt_procedure_modifiers"); (yyval.Bool) = true; }
#line 4855 "grammar.tab.cpp"
    break;

  case 322: /* opt_procedure_modifiers: %empty  */
#line 657 "grammar.y"
                                                    { parser_print("empty -> opt_procedure_modifiers"); (yyval.Bool) = false; }
#line 4861 "grammar.tab.cpp"
    break;

  case 323: /* function_parameters: function_parameter  */
#line 660 "grammar.y"
                                                                      { parser_print("function_parameter -> function_parameters"); (yyval.Vars) = new list<typed_value*>(); (yyval.Vars)->add((yyvsp[0].Var)); }
#line 4867 "grammar.tab.cpp"
    break;

  case 324: /* function_parameters: function_parameters ',' function_parameter  */
#line 661 "grammar.y"
                                                                      { parser_print("function_parameters ',' function_parameter -> function_parameters"); (yyval.Vars) = (yyvsp[-2].Vars); (yyval.Vars)->add((yyvsp[0].Var)); }
#line 4873 "grammar.tab.cpp"
    break;

  case 325: /* function_parameter: variable_name AS_KW type_name  */
#line 664 "grammar.y"
                                                                               { parser_print("variable_name AS_KW type_name -> function_parameter"); (yyval.Var) = append_var_declarator((yyvsp[-2].Var), (yyvsp[0].Type), nullptr); }
#line 4879 "grammar.tab.cpp"
    break;

  case 326: /* function_parameter: variable_name  */
#line 665 "grammar.y"
                                                                               { parser_print("variable_name -> function_parameter"); (yyval.Var) = (yyvsp[0].Var); (yyval.Var) = append_var_declarator((yyvsp[0].Var), nullptr, nullptr); }
#line 4885 "grammar.tab.cpp"
    break;

  case 327: /* class_declaration: CLASS_KW ID stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW  */
#line 668 "grammar.y"
                                                                                                                              { parser_print("CLASS_KW ID stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); (yyval.Struct) = parse_struct_body(create_class((yyvsp[-7].Id), nullptr, (yyvsp[-4].Id)), (yyvsp[-2].UnknownBody)); }
#line 4891 "grammar.tab.cpp"
    break;

  case 328: /* class_declaration: CLASS_KW ID endl_list opt_structure_body END_KW CLASS_KW  */
#line 669 "grammar.y"
                                                                                                                              { parser_print("CLASS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); (yyval.Struct) = parse_struct_body(create_class((yyvsp[-4].Id), nullptr, nullptr), (yyvsp[-2].UnknownBody)); }
#line 4897 "grammar.tab.cpp"
    break;

  case 329: /* class_declaration: CLASS_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW  */
#line 670 "grammar.y"
                                                                                                                              { parser_print("CLASS_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); (yyval.Struct) = parse_struct_body(create_class((yyvsp[-8].Id), (yyvsp[-7].IdList), (yyvsp[-4].Id)), (yyvsp[-2].UnknownBody)); }
#line 4903 "grammar.tab.cpp"
    break;

  case 330: /* class_declaration: CLASS_KW ID generic_param_list endl_list opt_structure_body END_KW CLASS_KW  */
#line 671 "grammar.y"
                                                                                                                              { parser_print("CLASS_KW ID generic_param_list endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); (yyval.Struct) = parse_struct_body(create_class((yyvsp[-5].Id), (yyvsp[-4].IdList), nullptr), (yyvsp[-2].UnknownBody)); }
#line 4909 "grammar.tab.cpp"
    break;

  case 331: /* generic_param_list: '(' opt_endl OF_KW id_list opt_endl ')'  */
#line 674 "grammar.y"
                                                                                     { parser_print("ID '(' opt_endl OF_KW id_list opt_endl ')' -> generic_param_list"); (yyval.IdList) = (yyvsp[-2].IdList); }
#line 4915 "grammar.tab.cpp"
    break;

  case 332: /* opt_structure_body: %empty  */
#line 677 "grammar.y"
                                         { parser_print("empty -> opt_structure_body"); (yyval.UnknownBody) = create_node_list(); }
#line 4921 "grammar.tab.cpp"
    break;

  case 333: /* opt_structure_body: structure_body  */
#line 678 "grammar.y"
                                         { parser_print("structure_body -> opt_structure_body"); (yyval.UnknownBody) = (yyvsp[0].UnknownBody); }
#line 4927 "grammar.tab.cpp"
    break;

  case 334: /* structure_body: structure_member  */
#line 681 "grammar.y"
                                                          { parser_print("structure_member -> structure_body"); (yyval.UnknownBody) = create_node_list(); (yyval.UnknownBody)->add((yyvsp[0].Unknown)); }
#line 4933 "grammar.tab.cpp"
    break;

  case 335: /* structure_body: structure_body structure_member  */
#line 682 "grammar.y"
                                                          { parser_print("structure_body structure_member -> structure_body"); (yyval.UnknownBody) = (yyvsp[-1].UnknownBody);  (yyval.UnknownBody)->add((yyvsp[0].Unknown)); }
#line 4939 "grammar.tab.cpp"
    break;

  case 336: /* structure_member: function_declaration  */
#line 685 "grammar.y"
                                                         { parser_print("function_declaration -> structure_member"); (yyval.Unknown) = (yyvsp[0].Procedure); }
#line 4945 "grammar.tab.cpp"
    break;

  case 337: /* structure_member: sub_declaration  */
#line 686 "grammar.y"
                                                         { parser_print("sub_declaration -> structure_member"); (yyval.Unknown) = (yyvsp[0].Procedure); }
#line 4951 "grammar.tab.cpp"
    break;

  case 338: /* structure_member: field_declaration  */
#line 687 "grammar.y"
                                                         { parser_print("field_declaration -> structure_member"); (yyval.Unknown) = (yyvsp[0].Field); }
#line 4957 "grammar.tab.cpp"
    break;

  case 339: /* field_declaration: SHARED_KW DIM_KW var_declarator endl_list  */
#line 690 "grammar.y"
                                                                     { parser_print("SHARED_KW DIM_KW var_declarator endl_list -> field_declaration"); (yyval.Field) = create_field((yyvsp[-1].Var), true, false); new_stmt = true; }
#line 4963 "grammar.tab.cpp"
    break;

  case 340: /* field_declaration: DIM_KW SHARED_KW var_declarator endl_list  */
#line 691 "grammar.y"
                                                                     { parser_print("DIM_KW SHARED_KW var_declarator endl_list -> field_declaration"); (yyval.Field) = create_field((yyvsp[-1].Var), true, false); new_stmt = true; }
#line 4969 "grammar.tab.cpp"
    break;

  case 341: /* field_declaration: DIM_KW var_declarator endl_list  */
#line 692 "grammar.y"
                                                                     { parser_print("DIM_KW var_declarator endl_list -> field_declaration"); (yyval.Field) = create_field((yyvsp[-1].Var), false, false); new_stmt = true; }
#line 4975 "grammar.tab.cpp"
    break;

  case 342: /* field_declaration: SHARED_KW CONST_KW var_declarator endl_list  */
#line 693 "grammar.y"
                                                                       { parser_print("SHARED_KW DIM_KW var_declarator endl_list -> field_declaration"); (yyval.Field) = create_field((yyvsp[-1].Var), true, true); new_stmt = true; }
#line 4981 "grammar.tab.cpp"
    break;

  case 343: /* field_declaration: CONST_KW SHARED_KW var_declarator endl_list  */
#line 694 "grammar.y"
                                                                       { parser_print("DIM_KW SHARED_KW var_declarator endl_list -> field_declaration"); (yyval.Field) = create_field((yyvsp[-1].Var), true, true); new_stmt = true; }
#line 4987 "grammar.tab.cpp"
    break;

  case 344: /* field_declaration: CONST_KW var_declarator endl_list  */
#line 695 "grammar.y"
                                                                       { parser_print("DIM_KW var_declarator endl_list -> field_declaration"); (yyval.Field) = create_field((yyvsp[-1].Var), false, true); new_stmt = true; }
#line 4993 "grammar.tab.cpp"
    break;


#line 4997 "grammar.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 698 "grammar.y"


void runParserTests() {
    yydebug = 0;
    fs::create_directories("parser/tests");
    fs::create_directories("parser/tests/output");
    std::vector<std::string> test_files = find_files("parser/tests", ".vb");
    for (std::string testpath : test_files) {
         yylineno = 1;
         new_stmt = true;
         printf("Testing this file: %s\n\n", testpath.c_str());
         fs::path file_path = testpath;
         fopen_s(&yyin, testpath.c_str(), "r");
         yyparse();
         fclose(yyin);
         outputDot(program, "parser/tests/output/" + file_path.stem().string() + ".png");
    }
}
