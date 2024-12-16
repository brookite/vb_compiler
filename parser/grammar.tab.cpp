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
program_node * program = NULL;


#line 99 "grammar.tab.cpp"

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
#define YYLAST   4007

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  332
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  688

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
       0,   219,   219,   220,   223,   226,   227,   230,   231,   234,
     235,   238,   239,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   406,   407,   410,   411,   414,   415,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     453,   456,   457,   460,   461,   462,   463,   464,   465,   468,
     469,   470,   473,   474,   477,   478,   479,   480,   483,   484,
     487,   490,   491,   492,   493,   496,   497,   500,   501,   502,
     503,   506,   507,   510,   511,   514,   515,   518,   519,   522,
     523,   526,   527,   530,   531,   534,   535,   539,   540,   541,
     542,   545,   546,   550,   551,   552,   553,   554,   555,   558,
     559,   560,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   581,   582,
     585,   586,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   603,   604,   605,   606,   607,   608,
     611,   612,   615,   616,   619,   620,   623,   624,   627,   628,
     631,   632,   633,   634,   637,   640,   641,   644,   645,   648,
     649,   650,   653
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

#define YYPACT_NINF (-506)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-327)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    49,    32,  -506,    71,    12,  -506,  -506,  -506,    76,
    -506,    19,    77,  -506,    27,    22,     4,  -506,  -506,    30,
      95,  -506,  -506,  -506,    -9,    72,     7,  -506,  -506,    97,
      27,    39,    99,   -27,   -29,    71,   101,   104,    71,    71,
      46,  -506,    71,    81,   109,  -506,    -6,    20,  -506,   434,
    3352,    76,   -22,   -17,  1081,  1226,  -506,    27,    50,    71,
      77,   -15,  -506,  3352,   -12,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,   -20,   -11,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,    -8,    -7,    -4,   530,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,    -3,  3352,  3352,  3352,    77,    77,  3843,    26,
    -506,   434,    77,   -21,    77,    31,  3442,   120,  2720,    36,
    3352,    33,  3352,    16,    48,  2810,    95,    95,  3352,    71,
    3752,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  1792,
    -506,    71,  1883,    96,  -506,    27,   128,  -506,  3021,    77,
    3352,    77,  3757,  3757,    77,    38,    41,    77,   731,   -85,
     -85,  3352,   751,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,  3757,    77,    77,  -506,
      13,   434,    77,    15,    77,    77,   303,    43,  -506,    -2,
    3352,  3566,    88,   133,    -1,  3566,  3352,  3352,  1979,  3566,
      71,    71,    71,    71,    71,    71,    71,    76,  3566,    71,
      71,  3843,     1,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    71,  -506,    76,    71,    78,
     121,  -506,    51,   -35,  3843,    62,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  3352,    77,    77,  3352,  3021,  -506,     2,  3352,  3352,
    3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,
    3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,
    3352,  -506,   939,  3352,   122,   123,     5,  -506,  -506,    17,
    -506,     5,    18,  3352,    71,    77,    77,    76,  3566,    45,
     434,    77,    77,  1322,  3566,  3566,   135,  2540,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      76,  3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,
    2900,  3352,    76,    76,  -506,   112,  -506,   689,  -506,  -506,
    3785,  2630,  2990,  3814,    63,    66,  3871,  2568,  2568,   731,
     731,    67,    67,    67,    67,    67,    67,    67,    67,   103,
     103,   130,    35,    35,   138,   -64,   -85,   -85,   -75,  -506,
       2,  3021,   434,   434,    95,    70,   134,     5,    74,  -506,
       5,  3473,  1979,  3352,   120,    45,  3082,  -506,   146,  -506,
      92,  -506,   142,  3352,    71,  2070,  1979,  1979,    37,  3352,
    3566,  3566,  3566,  3566,  3566,  3566,  3566,  3566,  3566,    71,
       2,  3566,  -506,    73,  -506,  -506,     9,    77,   689,    75,
       2,    75,     2,    77,  -506,  -506,    85,    89,  -506,  -506,
    -506,   158,   434,   105,  -506,   107,     3,  2540,     2,  -506,
     118,    71,   690,  -506,  -506,    71,  2810,  3629,    76,    71,
     189,   194,  3352,  3352,    76,  3843,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,   110,    76,    77,    77,
     111,  3352,     9,  -506,   113,  -506,   115,   434,  -506,  -506,
     434,  -506,   199,  -506,    71,  3352,    71,    10,   117,    71,
    1979,  3352,  1979,    76,  3172,  3566,  3352,    76,    71,    71,
    3566,  3566,    71,   195,   689,   127,  3502,   139,    75,    75,
      77,  -506,   434,  1418,  3600,    76,    71,    71,  -506,    76,
    -506,  3566,  2540,  3566,  1979,  3537,    76,    76,    76,    76,
      76,   689,  -506,    77,    77,   140,   143,  -506,  -506,   141,
    -506,    71,  2166,    71,  1514,    76,  1979,  1979,   227,  3352,
    1610,     9,   144,  3352,  -506,    77,  -506,    76,    71,  1979,
      71,  2262,  2540,   231,    71,  3566,    71,  2358,   145,  -506,
    3021,  3262,    76,  2540,    76,    71,    71,    76,  1701,    76,
      71,  -506,   147,    75,     2,    76,    76,    71,  2449,    76,
    -506,  -506,   148,    76,    71,    75,    76,  -506
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,     7,     0,     1,     3,     5,     8,
       4,     5,    12,    10,   315,     0,     0,     6,    11,     0,
       0,   314,   329,   330,     0,     0,   315,   327,   331,     0,
     315,     0,     0,   253,   257,     0,     0,     0,     0,     0,
       0,   328,     0,     0,     0,   290,    12,    12,   254,     0,
       0,   332,   297,   306,     0,     0,   321,   315,     0,     0,
      12,     0,   256,     0,   263,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   258,   265,    94,    95,    97,    98,    99,   100,    96,
     101,   102,     0,     0,     0,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,     0,     0,     0,     0,    12,    12,   259,     0,
     154,     0,    12,   303,    12,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   251,   182,   183,   189,   184,   185,   187,   188,     0,
     190,     0,     0,     0,   323,   315,     0,   324,    12,    12,
       0,    12,     0,     0,    12,   139,   149,    12,   127,   125,
     126,     0,     0,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,     0,    12,    12,   296,
       0,     0,    12,     0,    12,    12,     0,     0,   211,     0,
       0,     0,   241,     0,     0,     0,     0,     0,   249,     0,
       0,     0,     0,     0,     0,     0,     0,   201,     0,     0,
       0,   175,     0,   311,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,     0,   252,   313,     0,     0,
       0,   291,     0,     0,   260,     0,   173,    13,    15,    16,
      14,    17,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    60,    58,    59,    61,    62,    63,    64,    65,
      66,    67,    69,    70,    68,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,   174,   137,
     138,     0,    12,    12,     0,    12,   172,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,   295,   319,    12,   316,   302,     0,
     305,    12,     0,     0,     0,    12,    12,   180,     0,   234,
       0,    12,    12,     0,     0,     0,     0,   250,   177,   204,
     205,   203,   209,   207,   208,   206,   202,   261,   262,    12,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,   312,   320,     0,   255,     0,   266,   268,
       0,     0,     0,     0,     0,     0,   121,   120,   119,   117,
     118,   113,   114,   115,   116,   112,   111,   128,   129,   123,
     124,   110,   104,   105,   122,   108,   107,   106,   109,   131,
      12,    12,     0,     0,     0,     0,   301,    12,     0,   308,
      12,    12,   219,     0,     0,   234,     0,   228,   231,   232,
       0,   242,     0,     0,     0,     0,   249,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
      12,     0,   322,   269,   288,   271,    12,    12,     0,   140,
      12,   150,    12,    12,   103,   171,     0,     0,   294,   318,
     317,   293,     0,     0,   304,     0,     0,   219,    12,   212,
       0,     0,     0,   229,   233,     0,     0,     0,   236,     0,
       0,     0,     0,     0,   186,   176,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   179,     0,   191,    12,    12,
       0,     0,    12,   142,     0,   152,     0,     0,   130,   132,
       0,   300,   299,   307,     0,     0,     0,     0,     0,     0,
     249,     0,   225,   222,     0,     0,     0,   235,     0,     0,
       0,     0,   130,     0,     0,   264,    12,     0,   141,   151,
      12,   292,     0,     0,     0,   218,     0,     0,   210,   223,
     230,     0,   224,     0,   249,     0,   246,   248,   245,   247,
     178,     0,   289,    12,    12,     0,   144,   143,   153,     0,
     298,     0,     0,     0,     0,   217,   227,   249,     0,     0,
       0,    12,     0,     0,   135,    12,   133,   216,     0,   221,
       0,     0,   226,     0,     0,     0,     0,     0,     0,   267,
      12,     0,   214,   220,   215,     0,     0,   244,     0,   238,
       0,   270,     0,   145,    12,   213,   243,     0,     0,   237,
     134,   147,     0,   240,     0,   146,   239,   148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -506,  -506,   278,    -5,  -506,   270,   129,  -506,   567,  -506,
    -505,  -122,  -137,  -135,  -185,  -506,  -506,  -236,  -506,  -186,
    -506,  -181,  -177,  -506,  -506,    86,  -506,  -506,  -506,  -479,
     -36,    23,  -506,   -68,  -506,  -120,  -294,   -92,  -498,  -506,
    -506,  -506,  -506,  -506,  -506,  -201,  -163,  -506,    47,     6,
    -506,   299,  -506
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     9,    10,    15,   434,   338,   140,   119,
     120,   339,   232,   141,   208,   209,   142,   526,   143,   477,
     478,   479,   480,   144,   145,   214,   146,   147,   148,   396,
     397,   375,    48,    35,   150,    81,   504,    82,   506,    46,
      38,    39,    22,    23,    24,   376,   377,     4,    16,    25,
      26,    27,    28
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,   199,   381,   166,   563,    18,   565,   540,   541,     8,
     562,    30,     8,    18,   246,    11,    18,   246,   149,   152,
      18,    49,    33,    11,    33,   427,    33,    33,   121,   201,
      51,    18,     6,    54,    55,   347,    43,    57,    17,   574,
     575,   340,  -326,    34,     8,   212,   606,   575,     8,   195,
     196,   197,    36,    37,   155,     1,    17,   220,     5,   221,
     196,   197,  -325,   153,   222,    20,   193,   194,   229,   230,
     195,   196,   197,    32,   371,    32,   216,    21,   213,   217,
     542,   378,     8,   543,   476,    20,   223,    17,    18,   224,
      32,   225,    -9,   627,   628,    29,   226,    21,   576,   123,
     125,   610,   428,     1,    33,   607,    42,    40,    45,    47,
      52,    50,    44,    53,   122,   202,    58,    56,    59,   124,
     160,   154,   157,   641,   159,   161,   218,   162,   163,   207,
     227,   249,   164,   167,   233,   638,    60,   251,   390,   392,
     386,    19,   212,   409,   409,    13,   247,   464,    12,   424,
     374,   559,   380,    13,   466,   469,   425,    62,   653,    34,
      34,   250,   198,   191,   192,   193,   194,   204,   681,   195,
     196,   197,   462,   463,   342,    61,    63,   343,   467,   385,
     687,   470,   488,   502,   522,   476,   535,   536,   426,   156,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   429,
     514,   195,   196,   197,   387,   515,   389,   521,   570,   558,
     393,   524,   579,   117,   398,   399,   400,   401,   402,   403,
     404,   405,   568,   406,   407,   408,   569,   410,   188,   189,
     190,   191,   192,   193,   194,   460,   588,   195,   196,   197,
     422,   589,   572,   423,   573,   171,   172,   592,   595,   602,
     598,   200,   599,   203,   608,   621,   189,   190,   191,   192,
     193,   194,   246,   623,   195,   196,   197,   192,   193,   194,
     481,   654,   195,   196,   197,   666,   626,   644,   646,   645,
       7,   659,   671,   500,   680,   685,    31,   252,   253,   529,
     255,   577,   533,   341,   510,   512,   344,   534,   530,   391,
     622,   520,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,    41,   372,   373,     0,     0,
       0,   379,     0,   382,   383,   505,   528,   384,     0,     0,
       0,     0,   518,   519,     0,     0,     0,     0,     0,     0,
     246,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,     0,     0,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,     0,     0,     0,     0,     0,   472,
       0,     0,     0,   475,     0,     0,     0,     0,     0,   486,
     487,     0,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,   177,   505,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   527,   195,   196,   197,
       0,     0,     0,    64,     0,     0,     0,   600,     0,     0,
     601,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     0,     0,     0,
       0,   431,   432,     0,     0,     0,   435,   246,     0,   538,
       0,     0,   630,   544,     0,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,     0,   557,   246,     0,     0,
       0,     0,   505,     0,     0,   465,     0,     0,     0,     0,
     468,     0,     0,     0,   473,   474,   246,   246,     0,     0,
     482,   483,   246,     0,   674,     0,   580,   582,   246,   505,
     583,   584,     0,     0,   587,     0,     0,     0,   489,   165,
       0,     0,     0,   246,     0,     0,   612,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,     0,     0,     0,     0,   632,     0,   603,
       0,   605,     0,     0,   609,     0,     0,     0,     0,     0,
     614,     0,     0,   616,   617,   618,   619,   620,     0,   516,
     517,     0,     0,     0,     0,     0,   523,     0,   651,   525,
     652,   634,   635,     0,   657,     0,   636,     0,   637,     0,
     640,     0,     0,   663,     0,     0,     0,   118,     0,     0,
       0,     0,     0,     0,     0,     0,   647,     0,   649,   556,
     158,     0,   678,     0,     0,   560,   561,     0,     0,   564,
       0,   566,   567,   662,     0,   664,     0,     0,     0,   667,
     668,   669,     0,     0,     0,     0,     0,   578,     0,     0,
     675,   676,     0,     0,     0,   679,     0,     0,     0,     0,
       0,     0,   683,     0,     0,     0,     0,     0,     0,   686,
     168,   169,   170,     0,     0,     0,     0,   593,   594,     0,
       0,   597,     0,   206,     0,   211,     0,   215,   503,   219,
       0,     8,   228,     0,     0,   231,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,     0,     0,   625,     0,   254,     0,   629,
     581,     0,     0,     0,     0,     0,     0,     0,   345,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   642,   643,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,    92,    93,    94,    95,     0,     0,
     658,     0,     0,     0,   661,     0,     0,   388,     0,     0,
       0,     0,     0,   394,   395,     0,     0,     0,     0,   672,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   174,
     175,   176,   177,   682,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,     0,   195,   196,   197,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   113,   195,   196,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,   117,
     346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   430,     0,
       0,   433,     0,     0,     0,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,     0,   231,
     461,     0,    83,    84,    85,    86,    87,    88,    89,    90,
     471,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   231,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
     231,     0,     0,   532,     0,     0,     0,     0,     0,     0,
     537,     0,   113,     0,     0,     0,   545,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   459,   117,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    17,    91,    92,    93,   126,    95,     0,     0,
       0,     0,     0,   585,     0,     0,     0,     0,     0,   590,
     591,     0,     0,     0,   127,     0,     0,     0,     0,   128,
       0,     0,   129,     0,   130,     0,     0,     0,   596,   131,
       0,     0,   132,     0,   133,   134,     0,   135,     0,   136,
     137,     0,   604,     0,     0,     0,     0,     0,   611,     0,
       0,   613,     0,   615,     0,     0,   138,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   655,   114,   115,     0,
     660,     0,     0,     0,     0,     0,     0,   116,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,   231,    83,
      84,    85,    86,    87,    88,    89,    90,    17,    91,    92,
      93,   126,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,     0,     0,   128,     0,     0,   129,     0,   130,
       0,     0,     0,     0,   131,     0,     0,   132,     0,   133,
     134,     0,   135,     0,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,   151,     0,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    17,    91,    92,    93,   126,    95,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,     0,   127,     0,     0,     0,     0,
     128,     0,   116,   129,   117,   130,     0,     0,     0,     0,
     131,     0,     0,   132,     0,   133,   134,     0,   135,     0,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   484,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    17,
      91,    92,    93,   126,    95,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,   127,     0,     0,     0,     0,   128,     0,   116,   129,
     117,   130,     0,     0,     0,     0,   131,     0,     0,   132,
       0,   133,   134,     0,   135,     0,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,     0,   631,     0,     0,     0,    83,    84,    85,
      86,    87,    88,    89,    90,    17,    91,    92,    93,   126,
      95,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,     0,   127,     0,     0,
       0,     0,   128,     0,   116,   129,   117,   130,     0,     0,
       0,     0,   131,     0,     0,   132,     0,   133,   134,     0,
     135,     0,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,   650,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    17,    91,    92,    93,   126,    95,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,     0,   127,     0,     0,     0,     0,   128,     0,
     116,   129,   117,   130,   656,     0,     0,     0,   131,     0,
       0,   132,     0,   133,   134,     0,   135,     0,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    17,    91,    92,    93,   126,    95,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,   114,   115,     0,   128,
       0,     0,   129,     0,   130,   677,   116,     0,   117,   131,
       0,     0,   132,     0,   133,   134,     0,   135,     0,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,   126,    95,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,   114,   115,     0,
     128,     0,     0,   129,     0,   130,     0,   116,     0,   117,
     131,     0,     0,   132,     0,   133,   134,     0,   135,     0,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   245,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,   126,    95,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,   114,   115,
       0,   128,     0,     0,   129,     0,   130,     0,   116,     0,
     117,   131,     0,     0,   132,     0,   133,   134,     0,   135,
       0,   136,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,     0,     0,   248,
       0,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      17,    91,    92,    93,   126,    95,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,     0,   127,     0,     0,     0,     0,   128,     0,   116,
     129,   117,   130,     0,     0,     0,     0,   131,     0,     0,
     132,     0,   133,   134,     0,   135,     0,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,   126,    95,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,   114,   115,     0,   128,     0,
       0,   129,     0,   130,     0,   116,     0,   117,   131,     0,
       0,   132,     0,   133,   134,     0,   135,     0,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,   539,     0,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,    92,
      93,   126,    95,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,   127,
       0,     0,     0,     0,   128,     0,   116,   129,   117,   130,
       0,     0,     0,     0,   131,     0,     0,   132,     0,   133,
     134,     0,   135,     0,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,   648,     0,     0,     0,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,   126,    95,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,     0,   127,     0,     0,     0,     0,
     128,     0,   116,   129,   117,   130,     0,     0,     0,     0,
     131,     0,     0,   132,     0,   133,   134,     0,   135,     0,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,   665,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    93,   126,    95,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,   127,     0,     0,     0,     0,   128,     0,   116,   129,
     117,   130,   670,     0,     0,     0,   131,     0,     0,   132,
       0,   133,   134,     0,   135,     0,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    93,   126,    95,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,   114,   115,     0,   128,     0,     0,
     129,     0,   130,   684,   116,     0,   117,   131,     0,     0,
     132,     0,   133,   134,     0,   135,     0,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,   126,    95,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,   114,   115,     0,   128,     0,
       0,   129,     0,   130,     0,   116,     0,   117,   131,     0,
       0,   132,     0,   133,   134,     0,   135,     0,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   176,
     177,     0,   178,   179,   180,   181,   182,   183,   184,   185,
     508,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,     0,   195,   196,   197,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,   210,
       0,     0,     0,     0,     0,     0,   116,   509,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    83,    84,    85,    86,    87,    88,    89,
      90,     8,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,    18,     0,     0,     0,   116,   499,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,     0,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   531,     0,
       0,     0,     0,     0,     0,     0,   116,   511,   117,   173,
     174,   175,   176,   177,     0,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,     0,   195,   196,   197,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    83,    84,    85,    86,    87,
      88,    89,    90,    17,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,   116,   673,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,    18,     0,     0,     0,   116,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     8,   205,     0,
     117,   173,   174,   175,   176,   177,   639,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,     0,   195,   196,   197,
     173,   174,   175,   176,   177,   507,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   633,     0,   195,   196,   197,     0,
       0,     0,     0,     0,   624,   173,   174,   175,   176,   177,
       0,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   586,
       0,   195,   196,   197,   173,   174,   175,   176,   177,     0,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,     0,
     195,   196,   197,     0,     0,     0,     0,     0,   173,   174,
     175,   176,   177,     0,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,     0,   195,   196,   197,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,     0,   195,   196,   197,   256,     0,     0,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     173,   174,   175,   176,   177,     0,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,     0,   195,   196,   243,     0,
       0,     0,   244,   173,   174,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,     0,   195,
     196,   197,   173,   174,   175,   176,   177,   507,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,     0,   195,   196,
     197,   173,   174,   175,   176,   177,   513,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,     0,   195,   196,   197,
     174,   175,   176,   177,     0,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,     0,   195,   196,   197
};

static const yytype_int16 yycheck[] =
{
       5,   121,   203,    95,   509,    11,   511,   486,   487,    11,
     508,    16,    11,    11,   149,    11,    11,   152,    54,    55,
      11,    50,     9,    11,     9,    60,     9,     9,    50,    50,
      35,    11,     0,    38,    39,   172,    30,    42,    11,    36,
      37,   163,    35,    20,    11,     9,    36,    37,    11,   134,
     135,   136,    61,    62,    59,    71,    11,    41,     9,    43,
     135,   136,    35,    57,    48,    58,   130,   131,   136,   137,
     134,   135,   136,    60,   196,    60,    43,    70,    42,    46,
      43,   201,    11,    46,    39,    58,    38,    11,    11,    41,
      60,    43,    73,   598,   599,    73,    48,    70,    95,    52,
      53,   580,   137,    71,     9,    95,     9,    35,     9,   136,
       9,   140,    73,     9,   136,   136,    35,    71,     9,   136,
     140,    71,   137,   621,   136,   136,   131,   135,   135,     9,
     135,    35,   136,   136,   139,   614,   142,     9,    50,   140,
     142,    12,     9,   142,   142,   141,   151,   142,   136,    71,
     137,   142,   137,   141,   137,   137,    35,   137,   637,   136,
     137,   155,   136,   128,   129,   130,   131,   136,   673,   134,
     135,   136,    50,    50,   136,    46,    47,   136,   379,   136,
     685,   382,    47,    71,    50,    39,    94,    45,   137,    60,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   137,
     137,   134,   135,   136,   209,   139,   211,   137,    50,   136,
     215,   137,    94,   138,   219,   220,   221,   222,   223,   224,
     225,   226,   137,   228,   229,   230,   137,   232,   125,   126,
     127,   128,   129,   130,   131,   372,    47,   134,   135,   136,
     245,    47,   137,   248,   137,   116,   117,   137,   137,    50,
     137,   122,   137,   124,   137,    60,   126,   127,   128,   129,
     130,   131,   397,   136,   134,   135,   136,   129,   130,   131,
     390,    44,   134,   135,   136,    44,   137,   137,   137,   136,
       2,   137,   137,   420,   137,   137,    16,   158,   159,   474,
     161,   527,   478,   164,   431,   432,   167,   478,   475,   213,
     594,   464,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,    26,   197,   198,    -1,    -1,
      -1,   202,    -1,   204,   205,   427,   473,    34,    -1,    -1,
      -1,    -1,   462,   463,    -1,    -1,    -1,    -1,    -1,    -1,
     485,    -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,
      -1,    -1,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,   394,
     395,    -1,   527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   508,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   472,   134,   135,   136,
      -1,    -1,    -1,     9,    -1,    -1,    -1,   567,    -1,    -1,
     570,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,   342,   343,    -1,    -1,    -1,   347,   612,    -1,   484,
      -1,    -1,   602,   488,    -1,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,    -1,   501,   632,    -1,    -1,
      -1,    -1,   594,    -1,    -1,   376,    -1,    -1,    -1,    -1,
     381,    -1,    -1,    -1,   385,   386,   651,   652,    -1,    -1,
     391,   392,   657,    -1,   661,    -1,   531,   532,   663,   621,
     535,   536,    -1,    -1,   539,    -1,    -1,    -1,   409,     9,
      -1,    -1,    -1,   678,    -1,    -1,   582,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,   603,    -1,   574,
      -1,   576,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,
     585,    -1,    -1,   588,   589,   590,   591,   592,    -1,   460,
     461,    -1,    -1,    -1,    -1,    -1,   467,    -1,   634,   470,
     636,   606,   607,    -1,   640,    -1,   611,    -1,   613,    -1,
     615,    -1,    -1,   649,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   631,    -1,   633,   500,
      63,    -1,   668,    -1,    -1,   506,   507,    -1,    -1,   510,
      -1,   512,   513,   648,    -1,   650,    -1,    -1,    -1,   654,
     655,   656,    -1,    -1,    -1,    -1,    -1,   528,    -1,    -1,
     665,   666,    -1,    -1,    -1,   670,    -1,    -1,    -1,    -1,
      -1,    -1,   677,    -1,    -1,    -1,    -1,    -1,    -1,   684,
     113,   114,   115,    -1,    -1,    -1,    -1,   558,   559,    -1,
      -1,   562,    -1,   126,    -1,   128,    -1,   130,     9,   132,
      -1,    11,   135,    -1,    -1,   138,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,   596,    -1,   160,    -1,   600,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   623,   624,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    -1,
     641,    -1,    -1,    -1,   645,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,   216,   217,    -1,    -1,    -1,    -1,   660,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   674,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   113,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,
      -1,   344,    -1,    -1,    -1,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,    -1,   372,
     373,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
     383,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   431,   432,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     473,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
     483,    -1,   113,    -1,    -1,    -1,   489,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,   536,    -1,    -1,    -1,    -1,    -1,   542,
     543,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,   561,    48,
      -1,    -1,    51,    -1,    53,    54,    -1,    56,    -1,    58,
      59,    -1,   575,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,   584,    -1,   586,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   639,   126,   127,    -1,
     643,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   661,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    53,
      54,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    96,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    33,    -1,    -1,    -1,    -1,
      38,    -1,   136,    41,   138,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    97,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    33,    -1,    -1,    -1,    -1,    38,    -1,   136,    41,
     138,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    53,    54,    -1,    56,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    33,    -1,    -1,
      -1,    -1,    38,    -1,   136,    41,   138,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    53,    54,    -1,
      56,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    95,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    33,    -1,    -1,    -1,    -1,    38,    -1,
     136,    41,   138,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    53,    54,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,   126,   127,    -1,    38,
      -1,    -1,    41,    -1,    43,    44,   136,    -1,   138,    48,
      -1,    -1,    51,    -1,    53,    54,    -1,    56,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,   126,   127,    -1,
      38,    -1,    -1,    41,    -1,    43,    -1,   136,    -1,   138,
      48,    -1,    -1,    51,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,   126,   127,
      -1,    38,    -1,    -1,    41,    -1,    43,    -1,   136,    -1,
     138,    48,    -1,    -1,    51,    -1,    53,    54,    -1,    56,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    -1,    96,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    33,    -1,    -1,    -1,    -1,    38,    -1,   136,
      41,   138,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    53,    54,    -1,    56,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,   126,   127,    -1,    38,    -1,
      -1,    41,    -1,    43,    -1,   136,    -1,   138,    48,    -1,
      -1,    51,    -1,    53,    54,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    97,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    33,
      -1,    -1,    -1,    -1,    38,    -1,   136,    41,   138,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    53,
      54,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    33,    -1,    -1,    -1,    -1,
      38,    -1,   136,    41,   138,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    95,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    33,    -1,    -1,    -1,    -1,    38,    -1,   136,    41,
     138,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    53,    54,    -1,    56,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,   126,   127,    -1,    38,    -1,    -1,
      41,    -1,    43,    44,   136,    -1,   138,    48,    -1,    -1,
      51,    -1,    53,    54,    -1,    56,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,   126,   127,    -1,    38,    -1,
      -1,    41,    -1,    43,    -1,   136,    -1,   138,    48,    -1,
      -1,    51,    -1,    53,    54,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
      60,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,   134,   135,   136,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,   136,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,   136,    -1,
     138,   108,   109,   110,   111,   112,    49,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,   134,   135,   136,
     108,   109,   110,   111,   112,   142,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    34,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,   142,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    40,
      -1,   134,   135,   136,   108,   109,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,   108,   109,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,   134,   135,   136,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,    -1,
      -1,    -1,   140,   108,   109,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,   108,   109,   110,   111,   112,   142,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,   108,   109,   110,   111,   112,   142,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,   134,   135,   136,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,   134,   135,   136
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,   144,   145,   190,     9,     0,   145,    11,   146,
     147,    11,   136,   141,   146,   148,   191,    11,    11,   149,
      58,    70,   185,   186,   187,   192,   193,   194,   195,    73,
     146,   148,    60,     9,   174,   176,    61,    62,   183,   184,
      35,   194,     9,   192,    73,     9,   182,   136,   175,    50,
     140,   146,     9,     9,   146,   146,    71,   146,    35,     9,
     142,   149,   137,   149,     9,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   178,   180,     3,     4,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    15,    16,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   113,   126,   127,   136,   138,   151,   152,
     153,    50,   136,   191,   136,   191,    15,    33,    38,    41,
      43,    48,    51,    53,    54,    56,    58,    59,    75,    93,
     151,   156,   159,   161,   166,   167,   169,   170,   171,   173,
     177,    96,   173,   192,    71,   146,   149,   137,   151,   136,
     140,   136,   135,   135,   136,     9,   180,   136,   151,   151,
     151,   149,   149,   108,   109,   110,   111,   112,   114,   115,
     116,   117,   118,   119,   120,   121,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   134,   135,   136,   136,   178,
     149,    50,   136,   149,   136,   136,   151,     9,   157,   158,
      39,   151,     9,    42,   168,   151,    43,    46,   146,   151,
      41,    43,    48,    38,    41,    43,    48,   146,   151,   176,
     176,   151,   155,   146,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   136,   140,    93,   156,   146,    96,    35,
     192,     9,   149,   149,   151,   149,     9,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   150,   154,
     154,   149,   136,   136,   149,   151,   139,   155,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   154,   149,   149,   137,   174,   188,   189,   178,   149,
     137,   188,   149,   149,    34,   136,   142,   146,   151,   146,
      50,   168,   140,   146,   151,   151,   172,   173,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   142,
     146,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   146,   146,    71,    35,   137,    60,   137,   137,
     151,   149,   149,   151,   149,   149,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   137,
     155,   151,    50,    50,   142,   149,   137,   188,   149,   137,
     188,   151,   146,   149,   149,   146,    39,   162,   163,   164,
     165,   178,   149,   149,    97,   173,   146,   146,    47,   149,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   137,
     155,   151,    71,     9,   179,   180,   181,   142,    60,   137,
     155,   137,   155,   142,   137,   139,   149,   149,   178,   178,
     189,   137,    50,   149,   137,   149,   160,   173,   155,   157,
     165,    36,   151,   162,   164,    94,    45,   151,   146,    97,
     172,   172,    43,    46,   146,   151,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   149,   146,   136,   142,
     149,   149,   181,   153,   149,   153,   149,   149,   137,   137,
      50,   178,   137,   137,    36,    37,    95,   160,   149,    94,
     146,    40,   146,   146,   146,   151,    40,   146,    47,    47,
     151,   151,   137,   149,   149,   137,   151,   149,   137,   137,
     178,   178,    50,   146,   151,   146,    36,    95,   137,   146,
     172,   151,   173,   151,   146,   151,   146,   146,   146,   146,
     146,    60,   179,   136,   142,   149,   137,   153,   153,   149,
     178,    95,   173,    34,   146,   146,   146,   146,   172,    49,
     146,   181,   149,   149,   137,   136,   137,   146,    95,   146,
      95,   173,   173,   172,    44,   151,    44,   173,   149,   137,
     151,   149,   146,   173,   146,    95,    44,   146,   146,   146,
      44,   137,   149,   137,   155,   146,   146,    44,   173,   146,
     137,   153,   149,   146,    44,   137,   146,   153
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
     151,   151,   151,   151,   151,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   158,   158,   159,   159,   159,   159,   159,   159,   160,
     160,   160,   161,   161,   162,   162,   162,   162,   163,   163,
     164,   165,   165,   165,   165,   166,   166,   167,   167,   167,
     167,   168,   168,   169,   169,   170,   170,   171,   171,   172,
     172,   173,   173,   174,   174,   175,   175,   176,   176,   176,
     176,   177,   177,   178,   178,   178,   178,   178,   178,   179,
     179,   179,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   181,   181,
     182,   182,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   184,   184,
     185,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     190,   190,   190,   190,   191,   192,   192,   193,   193,   194,
     194,   194,   195
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
       1,     1,     1,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     2,     2,     4,     4,
       6,     4,     6,     9,    12,     9,     3,     3,     3,     2,
       5,     7,     6,     8,     8,    11,    13,    12,    14,     2,
       5,     7,     6,     8,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     1,     1,     1,     4,     3,     7,     5,
       3,     3,     1,     1,     1,     1,     5,     1,     1,     1,
       1,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     1,     4,    11,    10,    10,     9,     8,     7,     0,
       6,     5,     6,     7,     4,     3,     6,     5,     1,     2,
       4,     1,     1,     2,     0,     6,     5,    11,    10,    13,
      12,     1,     3,    11,    10,     7,     7,     7,     7,     0,
       1,     1,     2,     1,     2,     5,     2,     1,     3,     3,
       5,     3,     3,     1,     7,     1,     4,    10,     4,     1,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     4,     9,     7,     7,     5,     4,     2,    10,     8,
       8,     6,     5,     3,     7,     5,     2,     8,     6,     3,
       6,     5,     6,     5,     1,     0,     1,     3,     3,     1,
       9,     6,    10,     7,     6,     0,     1,     1,     2,     1,
       1,     1,     3
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
#line 219 "grammar.y"
                                            {parser_print("program_member -> program"); program = create_program(); program->nodes->add((yyvsp[0].Struct)); (yyval.EntryPoint) = program;}
#line 2764 "grammar.tab.cpp"
    break;

  case 3: /* program: program program_member  */
#line 220 "grammar.y"
                                            {parser_print("program program_member -> program"); program->nodes->add((yyvsp[0].Struct)); (yyval.EntryPoint) = program;}
#line 2770 "grammar.tab.cpp"
    break;

  case 4: /* program_member: class_declaration opt_endl_list  */
#line 223 "grammar.y"
                                                        {parser_print("class_declaration -> program_member"); (yyval.Struct) = (yyvsp[-1].Struct);}
#line 2776 "grammar.tab.cpp"
    break;

  case 5: /* endl_list: ENDL  */
#line 226 "grammar.y"
                                               { parser_print("ENDL -> endl_list");}
#line 2782 "grammar.tab.cpp"
    break;

  case 6: /* endl_list: endl_list ENDL  */
#line 227 "grammar.y"
                                               { parser_print("endl_list ENDL -> endl_list");}
#line 2788 "grammar.tab.cpp"
    break;

  case 9: /* stmt_endl: ENDL  */
#line 234 "grammar.y"
                                               { parser_print("ENDL -> stmt_endl");}
#line 2794 "grammar.tab.cpp"
    break;

  case 10: /* stmt_endl: ':'  */
#line 235 "grammar.y"
                                               { parser_print("':' -> stmt_endl");}
#line 2800 "grammar.tab.cpp"
    break;

  case 11: /* opt_endl: ENDL  */
#line 238 "grammar.y"
                                               { parser_print("ENDL -> opt_endl");}
#line 2806 "grammar.tab.cpp"
    break;

  case 12: /* opt_endl: %empty  */
#line 239 "grammar.y"
                                               { parser_print("empty -> opt_endl"); }
#line 2812 "grammar.tab.cpp"
    break;

  case 13: /* kw: ME_KW  */
#line 242 "grammar.y"
                                        {(yyval.Expr) = create_id("Me");}
#line 2818 "grammar.tab.cpp"
    break;

  case 14: /* kw: IF_KW  */
#line 243 "grammar.y"
                                        {(yyval.Expr) = create_id("If");}
#line 2824 "grammar.tab.cpp"
    break;

  case 15: /* kw: MYBASE_KW  */
#line 244 "grammar.y"
                                        {(yyval.Expr) = create_id("MyBase");}
#line 2830 "grammar.tab.cpp"
    break;

  case 16: /* kw: MYCLASS_KW  */
#line 245 "grammar.y"
                                        {(yyval.Expr) = create_id("MyClass");}
#line 2836 "grammar.tab.cpp"
    break;

  case 17: /* kw: NEW_KW  */
#line 246 "grammar.y"
                                        {(yyval.Expr) = create_id("New");}
#line 2842 "grammar.tab.cpp"
    break;

  case 18: /* kw: REDIM_KW  */
#line 247 "grammar.y"
                                        {(yyval.Expr) = create_id("ReDim");}
#line 2848 "grammar.tab.cpp"
    break;

  case 19: /* kw: THEN_KW  */
#line 248 "grammar.y"
                                        {(yyval.Expr) = create_id("Then");}
#line 2854 "grammar.tab.cpp"
    break;

  case 20: /* kw: END_KW  */
#line 249 "grammar.y"
                                        {(yyval.Expr) = create_id("End");}
#line 2860 "grammar.tab.cpp"
    break;

  case 21: /* kw: ELSE_KW  */
#line 250 "grammar.y"
                                        {(yyval.Expr) = create_id("Else");}
#line 2866 "grammar.tab.cpp"
    break;

  case 22: /* kw: ELSEIF_KW  */
#line 251 "grammar.y"
                                        {(yyval.Expr) = create_id("ElseIf");}
#line 2872 "grammar.tab.cpp"
    break;

  case 23: /* kw: SELECT_KW  */
#line 252 "grammar.y"
                                        {(yyval.Expr) = create_id("Select");}
#line 2878 "grammar.tab.cpp"
    break;

  case 24: /* kw: CASE_KW  */
#line 253 "grammar.y"
                                        {(yyval.Expr) = create_id("Case");}
#line 2884 "grammar.tab.cpp"
    break;

  case 25: /* kw: TO_KW  */
#line 254 "grammar.y"
                                        {(yyval.Expr) = create_id("To");}
#line 2890 "grammar.tab.cpp"
    break;

  case 26: /* kw: FOR_KW  */
#line 255 "grammar.y"
                                        {(yyval.Expr) = create_id("For");}
#line 2896 "grammar.tab.cpp"
    break;

  case 27: /* kw: EACH_KW  */
#line 256 "grammar.y"
                                        {(yyval.Expr) = create_id("Each");}
#line 2902 "grammar.tab.cpp"
    break;

  case 28: /* kw: WHILE_KW  */
#line 257 "grammar.y"
                                        {(yyval.Expr) = create_id("While");}
#line 2908 "grammar.tab.cpp"
    break;

  case 29: /* kw: NEXT_KW  */
#line 258 "grammar.y"
                                        {(yyval.Expr) = create_id("Next");}
#line 2914 "grammar.tab.cpp"
    break;

  case 30: /* kw: IN_KW  */
#line 259 "grammar.y"
                                        {(yyval.Expr) = create_id("In");}
#line 2920 "grammar.tab.cpp"
    break;

  case 31: /* kw: UNTIL_KW  */
#line 260 "grammar.y"
                                        {(yyval.Expr) = create_id("Until");}
#line 2926 "grammar.tab.cpp"
    break;

  case 32: /* kw: LOOP_KW  */
#line 261 "grammar.y"
                                        {(yyval.Expr) = create_id("Loop");}
#line 2932 "grammar.tab.cpp"
    break;

  case 33: /* kw: DO_KW  */
#line 262 "grammar.y"
                                        {(yyval.Expr) = create_id("Do");}
#line 2938 "grammar.tab.cpp"
    break;

  case 34: /* kw: STEP_KW  */
#line 263 "grammar.y"
                                        {(yyval.Expr) = create_id("Step");}
#line 2944 "grammar.tab.cpp"
    break;

  case 35: /* kw: AS_KW  */
#line 264 "grammar.y"
                                        {(yyval.Expr) = create_id("As");}
#line 2950 "grammar.tab.cpp"
    break;

  case 36: /* kw: CALL_KW  */
#line 265 "grammar.y"
                                        {(yyval.Expr) = create_id("Call");}
#line 2956 "grammar.tab.cpp"
    break;

  case 37: /* kw: GOTO_KW  */
#line 266 "grammar.y"
                                        {(yyval.Expr) = create_id("GoTo");}
#line 2962 "grammar.tab.cpp"
    break;

  case 38: /* kw: CONTINUE_KW  */
#line 267 "grammar.y"
                                        {(yyval.Expr) = create_id("Continue");}
#line 2968 "grammar.tab.cpp"
    break;

  case 39: /* kw: EXIT_KW  */
#line 268 "grammar.y"
                                        {(yyval.Expr) = create_id("Exit");}
#line 2974 "grammar.tab.cpp"
    break;

  case 40: /* kw: STOP_KW  */
#line 269 "grammar.y"
                                        {(yyval.Expr) = create_id("Stop");}
#line 2980 "grammar.tab.cpp"
    break;

  case 41: /* kw: RETURN_KW  */
#line 270 "grammar.y"
                                        {(yyval.Expr) = create_id("Return");}
#line 2986 "grammar.tab.cpp"
    break;

  case 42: /* kw: BYTE_KW  */
#line 271 "grammar.y"
                                        {(yyval.Expr) = create_id("Byte");}
#line 2992 "grammar.tab.cpp"
    break;

  case 43: /* kw: SBYTE_KW  */
#line 272 "grammar.y"
                                        {(yyval.Expr) = create_id("SByte");}
#line 2998 "grammar.tab.cpp"
    break;

  case 44: /* kw: USHORT_KW  */
#line 273 "grammar.y"
                                        {(yyval.Expr) = create_id("UShort");}
#line 3004 "grammar.tab.cpp"
    break;

  case 45: /* kw: SHORT_KW  */
#line 274 "grammar.y"
                                        {(yyval.Expr) = create_id("Short");}
#line 3010 "grammar.tab.cpp"
    break;

  case 46: /* kw: UINTEGER_KW  */
#line 275 "grammar.y"
                                        {(yyval.Expr) = create_id("UInteger");}
#line 3016 "grammar.tab.cpp"
    break;

  case 47: /* kw: INTEGER_KW  */
#line 276 "grammar.y"
                                        {(yyval.Expr) = create_id("Integer");}
#line 3022 "grammar.tab.cpp"
    break;

  case 48: /* kw: ULONG_KW  */
#line 277 "grammar.y"
                                        {(yyval.Expr) = create_id("ULong");}
#line 3028 "grammar.tab.cpp"
    break;

  case 49: /* kw: LONG_KW  */
#line 278 "grammar.y"
                                        {(yyval.Expr) = create_id("Long");}
#line 3034 "grammar.tab.cpp"
    break;

  case 50: /* kw: BOOLEAN_KW  */
#line 279 "grammar.y"
                                        {(yyval.Expr) = create_id("Boolean");}
#line 3040 "grammar.tab.cpp"
    break;

  case 51: /* kw: DATE_KW  */
#line 280 "grammar.y"
                                        {(yyval.Expr) = create_id("Date");}
#line 3046 "grammar.tab.cpp"
    break;

  case 52: /* kw: CHAR_KW  */
#line 281 "grammar.y"
                                        {(yyval.Expr) = create_id("Char");}
#line 3052 "grammar.tab.cpp"
    break;

  case 53: /* kw: STRING_KW  */
#line 282 "grammar.y"
                                        {(yyval.Expr) = create_id("String");}
#line 3058 "grammar.tab.cpp"
    break;

  case 54: /* kw: DECIMAL_KW  */
#line 283 "grammar.y"
                                        {(yyval.Expr) = create_id("Decimal");}
#line 3064 "grammar.tab.cpp"
    break;

  case 55: /* kw: SINGLE_KW  */
#line 284 "grammar.y"
                                        {(yyval.Expr) = create_id("Single");}
#line 3070 "grammar.tab.cpp"
    break;

  case 56: /* kw: DOUBLE_KW  */
#line 285 "grammar.y"
                                        {(yyval.Expr) = create_id("Double");}
#line 3076 "grammar.tab.cpp"
    break;

  case 57: /* kw: OBJECT_KW  */
#line 286 "grammar.y"
                                        {(yyval.Expr) = create_id("Object");}
#line 3082 "grammar.tab.cpp"
    break;

  case 58: /* kw: DIM_KW  */
#line 287 "grammar.y"
                                        {(yyval.Expr) = create_id("Dim");}
#line 3088 "grammar.tab.cpp"
    break;

  case 59: /* kw: CONST_KW  */
#line 288 "grammar.y"
                                        {(yyval.Expr) = create_id("Const");}
#line 3094 "grammar.tab.cpp"
    break;

  case 60: /* kw: STATIC_KW  */
#line 289 "grammar.y"
                                        {(yyval.Expr) = create_id("Static");}
#line 3100 "grammar.tab.cpp"
    break;

  case 61: /* kw: OF_KW  */
#line 290 "grammar.y"
                                        {(yyval.Expr) = create_id("Of");}
#line 3106 "grammar.tab.cpp"
    break;

  case 62: /* kw: FUNCTION_KW  */
#line 291 "grammar.y"
                                        {(yyval.Expr) = create_id("Function");}
#line 3112 "grammar.tab.cpp"
    break;

  case 63: /* kw: SUB_KW  */
#line 292 "grammar.y"
                                        {(yyval.Expr) = create_id("Sub");}
#line 3118 "grammar.tab.cpp"
    break;

  case 64: /* kw: BYREF_KW  */
#line 293 "grammar.y"
                                        {(yyval.Expr) = create_id("ByRef");}
#line 3124 "grammar.tab.cpp"
    break;

  case 65: /* kw: BYVAL_KW  */
#line 294 "grammar.y"
                                        {(yyval.Expr) = create_id("ByVal");}
#line 3130 "grammar.tab.cpp"
    break;

  case 66: /* kw: PARAMARRAY_KW  */
#line 295 "grammar.y"
                                        {(yyval.Expr) = create_id("ParamArray");}
#line 3136 "grammar.tab.cpp"
    break;

  case 67: /* kw: OPTIONAL_KW  */
#line 296 "grammar.y"
                                        {(yyval.Expr) = create_id("Optional");}
#line 3142 "grammar.tab.cpp"
    break;

  case 68: /* kw: PUBLIC_KW  */
#line 297 "grammar.y"
                                        {(yyval.Expr) = create_id("Public");}
#line 3148 "grammar.tab.cpp"
    break;

  case 69: /* kw: PRIVATE_KW  */
#line 298 "grammar.y"
                                        {(yyval.Expr) = create_id("Private");}
#line 3154 "grammar.tab.cpp"
    break;

  case 70: /* kw: PROTECTED_KW  */
#line 299 "grammar.y"
                                        {(yyval.Expr) = create_id("Protected");}
#line 3160 "grammar.tab.cpp"
    break;

  case 71: /* kw: SHARED_KW  */
#line 300 "grammar.y"
                                        {(yyval.Expr) = create_id("Shared");}
#line 3166 "grammar.tab.cpp"
    break;

  case 72: /* kw: CLASS_KW  */
#line 301 "grammar.y"
                                        {(yyval.Expr) = create_id("Class");}
#line 3172 "grammar.tab.cpp"
    break;

  case 73: /* kw: STRUCT_KW  */
#line 302 "grammar.y"
                                        {(yyval.Expr) = create_id("Struct");}
#line 3178 "grammar.tab.cpp"
    break;

  case 74: /* kw: INHERITS_KW  */
#line 303 "grammar.y"
                                        {(yyval.Expr) = create_id("Inherits");}
#line 3184 "grammar.tab.cpp"
    break;

  case 75: /* kw: READONLY_KW  */
#line 304 "grammar.y"
                                        {(yyval.Expr) = create_id("Readonly");}
#line 3190 "grammar.tab.cpp"
    break;

  case 76: /* kw: ERASE_KW  */
#line 305 "grammar.y"
                                        {(yyval.Expr) = create_id("Erase");}
#line 3196 "grammar.tab.cpp"
    break;

  case 77: /* kw: CBOOL_KW  */
#line 306 "grammar.y"
                                        {(yyval.Expr) = create_id("CBool");}
#line 3202 "grammar.tab.cpp"
    break;

  case 78: /* kw: CBYTE_KW  */
#line 307 "grammar.y"
                                        {(yyval.Expr) = create_id("CByte");}
#line 3208 "grammar.tab.cpp"
    break;

  case 79: /* kw: CSBYTE_KW  */
#line 308 "grammar.y"
                                        {(yyval.Expr) = create_id("CSByte");}
#line 3214 "grammar.tab.cpp"
    break;

  case 80: /* kw: CUSHORT_KW  */
#line 309 "grammar.y"
                                        {(yyval.Expr) = create_id("CUShort");}
#line 3220 "grammar.tab.cpp"
    break;

  case 81: /* kw: CSHORT_KW  */
#line 310 "grammar.y"
                                        {(yyval.Expr) = create_id("CShort");}
#line 3226 "grammar.tab.cpp"
    break;

  case 82: /* kw: CINTEGER_KW  */
#line 311 "grammar.y"
                                        {(yyval.Expr) = create_id("CInteger");}
#line 3232 "grammar.tab.cpp"
    break;

  case 83: /* kw: CUINTEGER_KW  */
#line 312 "grammar.y"
                                        {(yyval.Expr) = create_id("CUInteger");}
#line 3238 "grammar.tab.cpp"
    break;

  case 84: /* kw: CLONG_KW  */
#line 313 "grammar.y"
                                        {(yyval.Expr) = create_id("CLong");}
#line 3244 "grammar.tab.cpp"
    break;

  case 85: /* kw: CULONG_KW  */
#line 314 "grammar.y"
                                        {(yyval.Expr) = create_id("CULong");}
#line 3250 "grammar.tab.cpp"
    break;

  case 86: /* kw: CDATE_KW  */
#line 315 "grammar.y"
                                        {(yyval.Expr) = create_id("CDate");}
#line 3256 "grammar.tab.cpp"
    break;

  case 87: /* kw: CCHAR_KW  */
#line 316 "grammar.y"
                                        {(yyval.Expr) = create_id("CChar");}
#line 3262 "grammar.tab.cpp"
    break;

  case 88: /* kw: CSTRING_KW  */
#line 317 "grammar.y"
                                        {(yyval.Expr) = create_id("CString");}
#line 3268 "grammar.tab.cpp"
    break;

  case 89: /* kw: CDECIMAL_KW  */
#line 318 "grammar.y"
                                        {(yyval.Expr) = create_id("CDecimal");}
#line 3274 "grammar.tab.cpp"
    break;

  case 90: /* kw: CSINGLE_KW  */
#line 319 "grammar.y"
                                        {(yyval.Expr) = create_id("CSingle");}
#line 3280 "grammar.tab.cpp"
    break;

  case 91: /* kw: CDOUBLE_KW  */
#line 320 "grammar.y"
                                        {(yyval.Expr) = create_id("CDouble");}
#line 3286 "grammar.tab.cpp"
    break;

  case 92: /* kw: COBJECT_KW  */
#line 321 "grammar.y"
                                        {(yyval.Expr) = create_id("CObject");}
#line 3292 "grammar.tab.cpp"
    break;

  case 93: /* kw: CTYPE_KW  */
#line 322 "grammar.y"
                                        {(yyval.Expr) = create_id("CType");}
#line 3298 "grammar.tab.cpp"
    break;

  case 94: /* expr: INT  */
#line 325 "grammar.y"
                                                 {parser_print("INT -> expr"); (yyval.Expr) = create_int((yyvsp[0].Int));}
#line 3304 "grammar.tab.cpp"
    break;

  case 95: /* expr: STR  */
#line 326 "grammar.y"
                                                 {parser_print("STR-> expr"); (yyval.Expr) = create_string((yyvsp[0].Str));}
#line 3310 "grammar.tab.cpp"
    break;

  case 96: /* expr: ID  */
#line 327 "grammar.y"
                                                 {parser_print("ID -> expr"); (yyval.Expr) = create_id((yyvsp[0].Id));}
#line 3316 "grammar.tab.cpp"
    break;

  case 97: /* expr: FLOAT  */
#line 328 "grammar.y"
                                                 {parser_print("FLOAT -> expr"); (yyval.Expr) = create_float((yyvsp[0].Float));}
#line 3322 "grammar.tab.cpp"
    break;

  case 98: /* expr: BOOL  */
#line 329 "grammar.y"
                                                 {parser_print("BOOL -> expr"); (yyval.Expr) = create_bool((yyvsp[0].Bool));}
#line 3328 "grammar.tab.cpp"
    break;

  case 99: /* expr: DATETIME  */
#line 330 "grammar.y"
                                                 {parser_print("DATETIME -> expr"); (yyval.Expr) = create_datetime((yyvsp[0].DateTime));}
#line 3334 "grammar.tab.cpp"
    break;

  case 100: /* expr: CHAR  */
#line 331 "grammar.y"
                                                 {parser_print("CHAR -> expr"); (yyval.Expr) = create_char((yyvsp[0].Char));}
#line 3340 "grammar.tab.cpp"
    break;

  case 101: /* expr: NOTHING  */
#line 332 "grammar.y"
                                                 {parser_print("NOTHING -> expr"); (yyval.Expr) = create_nothing();}
#line 3346 "grammar.tab.cpp"
    break;

  case 102: /* expr: ME_KW  */
#line 333 "grammar.y"
                                                 {parser_print("ME_KW -> expr"); (yyval.Expr) = create_me();}
#line 3352 "grammar.tab.cpp"
    break;

  case 103: /* expr: '(' opt_endl expr opt_endl ')'  */
#line 334 "grammar.y"
                                                 {(yyval.Expr) = (yyvsp[-2].Expr);}
#line 3358 "grammar.tab.cpp"
    break;

  case 104: /* expr: expr '+' opt_endl expr  */
#line 335 "grammar.y"
                                                 {parser_print("expr + opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::AddOp);}
#line 3364 "grammar.tab.cpp"
    break;

  case 105: /* expr: expr '-' opt_endl expr  */
#line 336 "grammar.y"
                                                 {parser_print("expr - opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::SubOp);}
#line 3370 "grammar.tab.cpp"
    break;

  case 106: /* expr: expr '*' opt_endl expr  */
#line 337 "grammar.y"
                                                 {parser_print("expr * opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::MulOp);}
#line 3376 "grammar.tab.cpp"
    break;

  case 107: /* expr: expr '/' opt_endl expr  */
#line 338 "grammar.y"
                                                 {parser_print("expr / opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::DivOp);}
#line 3382 "grammar.tab.cpp"
    break;

  case 108: /* expr: expr '\\' opt_endl expr  */
#line 339 "grammar.y"
                                                  {parser_print("expr \\ opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::FloorDivOp);}
#line 3388 "grammar.tab.cpp"
    break;

  case 109: /* expr: expr '^' opt_endl expr  */
#line 340 "grammar.y"
                                                  {parser_print("expr ^ opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::ExpOp);}
#line 3394 "grammar.tab.cpp"
    break;

  case 110: /* expr: expr '&' opt_endl expr  */
#line 341 "grammar.y"
                                                  {parser_print("expr & opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::StrConcatOp);}
#line 3400 "grammar.tab.cpp"
    break;

  case 111: /* expr: expr '>' opt_endl expr  */
#line 342 "grammar.y"
                                                  {parser_print("expr > opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::GtOp);}
#line 3406 "grammar.tab.cpp"
    break;

  case 112: /* expr: expr '<' opt_endl expr  */
#line 343 "grammar.y"
                                                  {parser_print("expr < opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::LtOp);}
#line 3412 "grammar.tab.cpp"
    break;

  case 113: /* expr: expr EQ opt_endl expr  */
#line 344 "grammar.y"
                                                     {parser_print("expr = opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::EqOp);}
#line 3418 "grammar.tab.cpp"
    break;

  case 114: /* expr: expr NEQ opt_endl expr  */
#line 345 "grammar.y"
                                                  {parser_print("expr NEQ expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::NeqOp);}
#line 3424 "grammar.tab.cpp"
    break;

  case 115: /* expr: expr LEQ opt_endl expr  */
#line 346 "grammar.y"
                                                  {parser_print("expr LEQ expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::LeqOp);}
#line 3430 "grammar.tab.cpp"
    break;

  case 116: /* expr: expr GEQ opt_endl expr  */
#line 347 "grammar.y"
                                                  {parser_print("expr GEQ expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::GeqOp);}
#line 3436 "grammar.tab.cpp"
    break;

  case 117: /* expr: expr AND opt_endl expr  */
#line 348 "grammar.y"
                                                  {parser_print("expr AND expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::AndOp);}
#line 3442 "grammar.tab.cpp"
    break;

  case 118: /* expr: expr AND_ALSO opt_endl expr  */
#line 349 "grammar.y"
                                                  {parser_print("expr AND_ALSO expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::AndAlsoOp);}
#line 3448 "grammar.tab.cpp"
    break;

  case 119: /* expr: expr OR_ELSE opt_endl expr  */
#line 350 "grammar.y"
                                                  {parser_print("expr OR_ELSE expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::OrElseOp);}
#line 3454 "grammar.tab.cpp"
    break;

  case 120: /* expr: expr OR opt_endl expr  */
#line 351 "grammar.y"
                                                  {parser_print("expr OR expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::OrOp);}
#line 3460 "grammar.tab.cpp"
    break;

  case 121: /* expr: expr XOR opt_endl expr  */
#line 352 "grammar.y"
                                                  {parser_print("expr XOR expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::XorOp);}
#line 3466 "grammar.tab.cpp"
    break;

  case 122: /* expr: expr MOD opt_endl expr  */
#line 353 "grammar.y"
                                                  {parser_print("expr MOD expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::ModOp);}
#line 3472 "grammar.tab.cpp"
    break;

  case 123: /* expr: expr LSHIFT opt_endl expr  */
#line 354 "grammar.y"
                                                  {parser_print("expr LSHIFT expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::LshiftOp);}
#line 3478 "grammar.tab.cpp"
    break;

  case 124: /* expr: expr RSHIFT opt_endl expr  */
#line 355 "grammar.y"
                                                  {parser_print("expr RSHIFT expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::RshiftOp);}
#line 3484 "grammar.tab.cpp"
    break;

  case 125: /* expr: '+' expr  */
#line 356 "grammar.y"
                                                  {parser_print("+ expr -> expr"); (yyval.Expr) = create_unary((yyvsp[0].Expr), expr_type::UnaryPlusOp);}
#line 3490 "grammar.tab.cpp"
    break;

  case 126: /* expr: '-' expr  */
#line 357 "grammar.y"
                                                  {parser_print("- expr -> expr"); (yyval.Expr) = create_unary((yyvsp[0].Expr), expr_type::UnaryMinusOp);}
#line 3496 "grammar.tab.cpp"
    break;

  case 127: /* expr: NOT expr  */
#line 358 "grammar.y"
                                                  {parser_print("Not expr"); (yyval.Expr) = create_unary((yyvsp[0].Expr), expr_type::NotOp);}
#line 3502 "grammar.tab.cpp"
    break;

  case 128: /* expr: expr IS opt_endl expr  */
#line 359 "grammar.y"
                                                  {parser_print("expr Is opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::IsOp);}
#line 3508 "grammar.tab.cpp"
    break;

  case 129: /* expr: expr ISNOT opt_endl expr  */
#line 360 "grammar.y"
                                                  {parser_print("expr IsNot opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), expr_type::IsNotOp);}
#line 3514 "grammar.tab.cpp"
    break;

  case 130: /* expr: expr '(' opt_endl expr_list opt_endl ')'  */
#line 361 "grammar.y"
                                                  {parser_print("expr(expr_list) -> expr"); (yyval.Expr) = create_call_expr((yyvsp[-5].Expr), (yyvsp[-2].ExprList));}
#line 3520 "grammar.tab.cpp"
    break;

  case 131: /* expr: expr '(' opt_endl ')'  */
#line 362 "grammar.y"
                                                      {parser_print("expr() -> expr"); (yyval.Expr) = create_call_expr((yyvsp[-3].Expr));}
#line 3526 "grammar.tab.cpp"
    break;

  case 132: /* expr: cast_target '(' opt_endl expr opt_endl ')'  */
#line 363 "grammar.y"
                                                  {parser_print("cast_target (expr) -> expr"); (yyval.Expr) = create_cast((yyvsp[-5].Type), (yyvsp[-2].Expr));}
#line 3532 "grammar.tab.cpp"
    break;

  case 133: /* expr: CTYPE_KW '(' opt_endl expr ',' opt_endl type_name opt_endl ')'  */
#line 364 "grammar.y"
                                                                                    {parser_print("cast_target (expr) -> expr"); (yyval.Expr) = create_cast((yyvsp[-2].Type), (yyvsp[-5].Expr));}
#line 3538 "grammar.tab.cpp"
    break;

  case 134: /* expr: IF_KW '(' opt_endl expr ',' opt_endl expr ',' opt_endl expr opt_endl ')'  */
#line 365 "grammar.y"
                                                                                    {parser_print("if(expr, expr, expr) -> expr"); (yyval.Expr) = create_if_expr((yyvsp[-8].Expr), (yyvsp[-5].Expr), (yyvsp[-2].Expr));}
#line 3544 "grammar.tab.cpp"
    break;

  case 135: /* expr: IF_KW '(' opt_endl expr ',' opt_endl expr opt_endl ')'  */
#line 366 "grammar.y"
                                                                                    {parser_print("if(expr, expr) -> expr"); (yyval.Expr) = create_if_expr((yyvsp[-5].Expr), (yyvsp[-2].Expr));}
#line 3550 "grammar.tab.cpp"
    break;

  case 136: /* expr: expr '.' member_access_member  */
#line 367 "grammar.y"
                                                  {parser_print("expr . member_access_member -> expr"); (yyval.Expr) = create_member_access((yyvsp[-2].Expr), (yyvsp[0].Expr));}
#line 3556 "grammar.tab.cpp"
    break;

  case 137: /* expr: MYBASE_KW '.' member_access_member  */
#line 368 "grammar.y"
                                                  {parser_print("my_base . member_access_member -> expr"); (yyval.Expr) = create_mybase_access((yyvsp[0].Expr));}
#line 3562 "grammar.tab.cpp"
    break;

  case 138: /* expr: MYCLASS_KW '.' member_access_member  */
#line 369 "grammar.y"
                                                  {parser_print("my_base . member_access_member -> expr"); (yyval.Expr) = create_myclass_access((yyvsp[0].Expr));}
#line 3568 "grammar.tab.cpp"
    break;

  case 139: /* expr: NEW_KW ID  */
#line 370 "grammar.y"
                                                               {parser_print("NEW_KW ID -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[0].Id)));}
#line 3574 "grammar.tab.cpp"
    break;

  case 140: /* expr: NEW_KW ID '(' opt_endl ')'  */
#line 371 "grammar.y"
                                                           {parser_print("NEW_KW ID '(' opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-3].Id)));}
#line 3580 "grammar.tab.cpp"
    break;

  case 141: /* expr: NEW_KW ID '(' opt_endl expr_list opt_endl ')'  */
#line 372 "grammar.y"
                                                                   {parser_print("NEW_KW ID '(' opt_endl expr_list opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-5].Id)), (yyvsp[-2].ExprList));}
#line 3586 "grammar.tab.cpp"
    break;

  case 142: /* expr: NEW_KW ID '(' opt_endl ')' collection_initializer  */
#line 373 "grammar.y"
                                                                   {parser_print("NEW_KW ID '(' opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr(create_type(datatype_type::UserType, (yyvsp[-4].Id)), (yyvsp[0].ExprList));}
#line 3592 "grammar.tab.cpp"
    break;

  case 143: /* expr: NEW_KW ID '(' opt_endl expr_list opt_endl ')' collection_initializer  */
#line 374 "grammar.y"
                                                                                       {parser_print("NEW_KW ID '(' opt_endl expr_list opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr(create_type(datatype_type::UserType, (yyvsp[-6].Id)), (yyvsp[-3].ExprList), (yyvsp[0].ExprList));}
#line 3598 "grammar.tab.cpp"
    break;

  case 144: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')'  */
#line 375 "grammar.y"
                                                                                           {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-6].Id), (yyvsp[-2].TypeList)));}
#line 3604 "grammar.tab.cpp"
    break;

  case 145: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')'  */
#line 376 "grammar.y"
                                                                                       {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-9].Id), (yyvsp[-5].TypeList)));}
#line 3610 "grammar.tab.cpp"
    break;

  case 146: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl expr_list opt_endl ')'  */
#line 377 "grammar.y"
                                                                                                             {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl expr_list opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr(create_type(datatype_type::UserType, (yyvsp[-11].Id), (yyvsp[-7].TypeList)), (yyvsp[-2].ExprList));}
#line 3616 "grammar.tab.cpp"
    break;

  case 147: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')' collection_initializer  */
#line 378 "grammar.y"
                                                                                                             {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr(create_type(datatype_type::UserType, (yyvsp[-10].Id), (yyvsp[-6].TypeList)), (yyvsp[0].ExprList));}
#line 3622 "grammar.tab.cpp"
    break;

  case 148: /* expr: NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl expr_list opt_endl ')' collection_initializer  */
#line 379 "grammar.y"
                                                                                                                                 {parser_print("NEW_KW ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl expr_list opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr(create_type(datatype_type::UserType, (yyvsp[-12].Id), (yyvsp[-8].TypeList)), (yyvsp[-3].ExprList), (yyvsp[0].ExprList));}
#line 3628 "grammar.tab.cpp"
    break;

  case 149: /* expr: NEW_KW primitive_type  */
#line 380 "grammar.y"
                                            {parser_print("NEW_KW primitive_type -> expr"); (yyval.Expr) = create_new_expr((yyvsp[0].Type));}
#line 3634 "grammar.tab.cpp"
    break;

  case 150: /* expr: NEW_KW primitive_type '(' opt_endl ')'  */
#line 381 "grammar.y"
                                                         {parser_print("NEW_KW primitive_type '(' opt_endl ')'-> expr"); (yyval.Expr) = create_new_expr((yyvsp[-3].Type));}
#line 3640 "grammar.tab.cpp"
    break;

  case 151: /* expr: NEW_KW primitive_type '(' opt_endl expr_list opt_endl ')'  */
#line 382 "grammar.y"
                                                                               {parser_print("NEW_KW primitive_type '(' opt_endl expr_list opt_endl ')' -> expr"); (yyval.Expr) = create_new_expr((yyvsp[-5].Type), (yyvsp[-2].ExprList));}
#line 3646 "grammar.tab.cpp"
    break;

  case 152: /* expr: NEW_KW primitive_type '(' opt_endl ')' collection_initializer  */
#line 383 "grammar.y"
                                                                               {parser_print("NEW_KW primitive_type '(' opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr((yyvsp[-4].Type), (yyvsp[0].ExprList));}
#line 3652 "grammar.tab.cpp"
    break;

  case 153: /* expr: NEW_KW primitive_type '(' opt_endl expr_list opt_endl ')' collection_initializer  */
#line 384 "grammar.y"
                                                                                                   {parser_print("NEW_KW primitive_type '(' opt_endl expr_list opt_endl ')' collection_initializer -> expr"); (yyval.Expr) = create_arraynew_expr((yyvsp[-6].Type), (yyvsp[-3].ExprList), (yyvsp[0].ExprList));}
#line 3658 "grammar.tab.cpp"
    break;

  case 154: /* expr: collection_initializer  */
#line 385 "grammar.y"
                             {parser_print("collection_initializer -> expr"); (yyval.Expr) = create_array_literal((yyvsp[0].ExprList));}
#line 3664 "grammar.tab.cpp"
    break;

  case 155: /* cast_target: CBOOL_KW  */
#line 388 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Boolean);}
#line 3670 "grammar.tab.cpp"
    break;

  case 156: /* cast_target: CBYTE_KW  */
#line 389 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Byte);}
#line 3676 "grammar.tab.cpp"
    break;

  case 157: /* cast_target: CSBYTE_KW  */
#line 390 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::SByte);}
#line 3682 "grammar.tab.cpp"
    break;

  case 158: /* cast_target: CUSHORT_KW  */
#line 391 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::UShort);}
#line 3688 "grammar.tab.cpp"
    break;

  case 159: /* cast_target: CSHORT_KW  */
#line 392 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Short);}
#line 3694 "grammar.tab.cpp"
    break;

  case 160: /* cast_target: CINTEGER_KW  */
#line 393 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Integer);}
#line 3700 "grammar.tab.cpp"
    break;

  case 161: /* cast_target: CUINTEGER_KW  */
#line 394 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::UInteger);}
#line 3706 "grammar.tab.cpp"
    break;

  case 162: /* cast_target: CLONG_KW  */
#line 395 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Long);}
#line 3712 "grammar.tab.cpp"
    break;

  case 163: /* cast_target: CULONG_KW  */
#line 396 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::ULong);}
#line 3718 "grammar.tab.cpp"
    break;

  case 164: /* cast_target: CDATE_KW  */
#line 397 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Date);}
#line 3724 "grammar.tab.cpp"
    break;

  case 165: /* cast_target: CCHAR_KW  */
#line 398 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Char);}
#line 3730 "grammar.tab.cpp"
    break;

  case 166: /* cast_target: CSTRING_KW  */
#line 399 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::String);}
#line 3736 "grammar.tab.cpp"
    break;

  case 167: /* cast_target: CDECIMAL_KW  */
#line 400 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Decimal);}
#line 3742 "grammar.tab.cpp"
    break;

  case 168: /* cast_target: CSINGLE_KW  */
#line 401 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Single);}
#line 3748 "grammar.tab.cpp"
    break;

  case 169: /* cast_target: CDOUBLE_KW  */
#line 402 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Double);}
#line 3754 "grammar.tab.cpp"
    break;

  case 170: /* cast_target: COBJECT_KW  */
#line 403 "grammar.y"
                                        {(yyval.Type) = create_type(datatype_type::Object, "Object");}
#line 3760 "grammar.tab.cpp"
    break;

  case 171: /* collection_initializer: '{' opt_endl expr_list opt_endl '}'  */
#line 406 "grammar.y"
                                                                    {parser_print("{ opt_endl expr_list opt_endl } -> collection_initializer"); (yyval.ExprList) = (yyvsp[-2].ExprList);}
#line 3766 "grammar.tab.cpp"
    break;

  case 172: /* collection_initializer: '{' opt_endl '}'  */
#line 407 "grammar.y"
                                                                    {parser_print("{ opt_endl } -> collection_initializer"); (yyval.ExprList) = create_expr_list();}
#line 3772 "grammar.tab.cpp"
    break;

  case 173: /* member_access_member: ID  */
#line 410 "grammar.y"
                                        {parser_print("ID -> member_access_member"); (yyval.Expr) = create_id((yyvsp[0].Id));}
#line 3778 "grammar.tab.cpp"
    break;

  case 174: /* member_access_member: kw  */
#line 411 "grammar.y"
                                        {parser_print("kw -> member_access_member"); (yyval.Expr) = (yyvsp[0].Expr);}
#line 3784 "grammar.tab.cpp"
    break;

  case 175: /* expr_list: expr  */
#line 414 "grammar.y"
                                            {parser_print("expr -> expr_list"); (yyval.ExprList) = create_expr_list(); (yyval.ExprList)->add((yyvsp[0].Expr));}
#line 3790 "grammar.tab.cpp"
    break;

  case 176: /* expr_list: expr_list ',' opt_endl expr  */
#line 415 "grammar.y"
                                            {parser_print("expr_list ',' opt_endl expr -> expr_list"); (yyval.ExprList) = (yyvsp[-3].ExprList); (yyval.ExprList)->add((yyvsp[0].Expr));}
#line 3796 "grammar.tab.cpp"
    break;

  case 177: /* stmt: CALL_KW expr endl_list  */
#line 418 "grammar.y"
                                                    {parser_print("CALL_KW expr endl_list -> stmt"); (yyval.Stmt) = create_call_stmt((yyvsp[-1].Expr)); new_stmt = true;}
#line 3802 "grammar.tab.cpp"
    break;

  case 178: /* stmt: expr '(' opt_endl expr_list opt_endl ')' endl_list  */
#line 419 "grammar.y"
                                                               {parser_print("expr(expr_list) -> stmt"); (yyval.Stmt) = create_call_stmt((yyvsp[-6].Expr), (yyvsp[-3].ExprList));}
#line 3808 "grammar.tab.cpp"
    break;

  case 179: /* stmt: expr '(' opt_endl ')' endl_list  */
#line 420 "grammar.y"
                                                                   {parser_print("expr() -> stmt"); (yyval.Stmt) = create_call_stmt((yyvsp[-4].Expr), create_expr_list());}
#line 3814 "grammar.tab.cpp"
    break;

  case 180: /* stmt: REDIM_KW redim_clause_list endl_list  */
#line 421 "grammar.y"
                                                    {parser_print("REDIM_KW redim_clause_list endl_list -> stmt"); (yyval.Stmt) = create_redim((yyvsp[-1].Redim)); new_stmt = true;}
#line 3820 "grammar.tab.cpp"
    break;

  case 181: /* stmt: ERASE_KW expr_list endl_list  */
#line 422 "grammar.y"
                                                    {parser_print("ERASE_KW expr_list endl_list -> stmt"); (yyval.Stmt) = create_erase((yyvsp[-1].ExprList)); new_stmt = true;}
#line 3826 "grammar.tab.cpp"
    break;

  case 182: /* stmt: if_stmt  */
#line 423 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 3832 "grammar.tab.cpp"
    break;

  case 183: /* stmt: select_stmt  */
#line 424 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 3838 "grammar.tab.cpp"
    break;

  case 184: /* stmt: for_stmt  */
#line 425 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 3844 "grammar.tab.cpp"
    break;

  case 185: /* stmt: foreach_stmt  */
#line 426 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 3850 "grammar.tab.cpp"
    break;

  case 186: /* stmt: DO_KW endl_list opt_block LOOP_KW endl_list  */
#line 427 "grammar.y"
                                                    {parser_print("DO_KW endl_list opt_block LOOP_KW endl_list"); (yyval.Stmt) = create_do_infinite_loop((yyvsp[-2].Block)); new_stmt = true;}
#line 3856 "grammar.tab.cpp"
    break;

  case 187: /* stmt: do_while_stmt  */
#line 428 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 3862 "grammar.tab.cpp"
    break;

  case 188: /* stmt: do_until_stmt  */
#line 429 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 3868 "grammar.tab.cpp"
    break;

  case 189: /* stmt: while_stmt  */
#line 430 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 3874 "grammar.tab.cpp"
    break;

  case 190: /* stmt: var_declaration  */
#line 431 "grammar.y"
                                                    {(yyval.Stmt) = (yyvsp[0].Stmt); new_stmt = true;}
#line 3880 "grammar.tab.cpp"
    break;

  case 191: /* stmt: expr '=' opt_endl expr endl_list  */
#line 432 "grammar.y"
                                                    {parser_print("expr '=' opt_endl expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::Assign); new_stmt = true; }
#line 3886 "grammar.tab.cpp"
    break;

  case 192: /* stmt: expr ADD_ASSIGN opt_endl expr endl_list  */
#line 433 "grammar.y"
                                                    {parser_print("expr ADD_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::AddAssign); new_stmt = true;}
#line 3892 "grammar.tab.cpp"
    break;

  case 193: /* stmt: expr SUB_ASSIGN opt_endl expr endl_list  */
#line 434 "grammar.y"
                                                    {parser_print("expr SUB_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::SubAssign); new_stmt = true;}
#line 3898 "grammar.tab.cpp"
    break;

  case 194: /* stmt: expr MUL_ASSIGN opt_endl expr endl_list  */
#line 435 "grammar.y"
                                                    {parser_print("expr MUL_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::MulAssign); new_stmt = true;}
#line 3904 "grammar.tab.cpp"
    break;

  case 195: /* stmt: expr DIV_ASSIGN opt_endl expr endl_list  */
#line 436 "grammar.y"
                                                    {parser_print("expr DIV_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::DivAssign); new_stmt = true;}
#line 3910 "grammar.tab.cpp"
    break;

  case 196: /* stmt: expr FLOORDIV_ASSIGN opt_endl expr endl_list  */
#line 437 "grammar.y"
                                                    {parser_print("expr FLOORDIV_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::FloorDivAssign); new_stmt = true;}
#line 3916 "grammar.tab.cpp"
    break;

  case 197: /* stmt: expr EXP_ASSIGN opt_endl expr endl_list  */
#line 438 "grammar.y"
                                                    {parser_print("expr EXP_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::ExpAssign); new_stmt = true;}
#line 3922 "grammar.tab.cpp"
    break;

  case 198: /* stmt: expr STRCAT_ASSIGN opt_endl expr endl_list  */
#line 439 "grammar.y"
                                                    {parser_print("expr STRCAT_ASSIGN expr endl_list -> stmt");(yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::StrConcatAssign); new_stmt = true;}
#line 3928 "grammar.tab.cpp"
    break;

  case 199: /* stmt: expr LSHIFT_ASSIGN opt_endl expr endl_list  */
#line 440 "grammar.y"
                                                    {parser_print("expr LSHIFT_ASSIGN expr endl_list -> stmt");(yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::LshiftAssign); new_stmt = true;}
#line 3934 "grammar.tab.cpp"
    break;

  case 200: /* stmt: expr RSHIFT_ASSIGN opt_endl expr endl_list  */
#line 441 "grammar.y"
                                                    {parser_print("expr RSHIFT_ASSIGN expr endl_list -> stmt"); (yyval.Stmt) = create_assign((yyvsp[-4].Expr), (yyvsp[-1].Expr), assignment_type::RshiftAssign); new_stmt = true;}
#line 3940 "grammar.tab.cpp"
    break;

  case 201: /* stmt: RETURN_KW endl_list  */
#line 442 "grammar.y"
                                                    {parser_print("RETURN_KW endl_list -> stmt"); (yyval.Stmt) = create_return(); new_stmt = true;}
#line 3946 "grammar.tab.cpp"
    break;

  case 202: /* stmt: RETURN_KW expr endl_list  */
#line 443 "grammar.y"
                                                    {parser_print("RETURN_KW expr endl_list -> stmt"); (yyval.Stmt) = create_return((yyvsp[-1].Expr)); new_stmt = true;}
#line 3952 "grammar.tab.cpp"
    break;

  case 203: /* stmt: CONTINUE_KW DO_KW endl_list  */
#line 444 "grammar.y"
                                                    {parser_print("CONTINUE_KW DO_KW endl_list -> stmt"); (yyval.Stmt) = create_continue(stmt_type::ContinueDo); new_stmt = true;}
#line 3958 "grammar.tab.cpp"
    break;

  case 204: /* stmt: CONTINUE_KW FOR_KW endl_list  */
#line 445 "grammar.y"
                                                    {parser_print("CONTINUE_KW FOR_KW endl_list -> stmt"); (yyval.Stmt) = create_continue(stmt_type::ContinueFor); new_stmt = true;}
#line 3964 "grammar.tab.cpp"
    break;

  case 205: /* stmt: CONTINUE_KW WHILE_KW endl_list  */
#line 446 "grammar.y"
                                                    {parser_print("CONTINUE_KW WHILE_KW endl_list -> stmt"); (yyval.Stmt) = create_continue(stmt_type::ContinueWhile); new_stmt = true;}
#line 3970 "grammar.tab.cpp"
    break;

  case 206: /* stmt: EXIT_KW DO_KW endl_list  */
#line 447 "grammar.y"
                                                    {parser_print("EXIT_KW DO_KW endl_list -> stmt"); (yyval.Stmt) = create_exit(stmt_type::ExitDo); new_stmt = true;}
#line 3976 "grammar.tab.cpp"
    break;

  case 207: /* stmt: EXIT_KW FOR_KW endl_list  */
#line 448 "grammar.y"
                                                    {parser_print("EXIT_KW FOR_KW endl_list -> stmt"); (yyval.Stmt) = create_exit(stmt_type::ExitFor); new_stmt = true;}
#line 3982 "grammar.tab.cpp"
    break;

  case 208: /* stmt: EXIT_KW WHILE_KW endl_list  */
#line 449 "grammar.y"
                                                    {parser_print("EXIT_KW WHILE_KW endl_list -> stmt");(yyval.Stmt) = create_exit(stmt_type::ExitWhile); new_stmt = true;}
#line 3988 "grammar.tab.cpp"
    break;

  case 209: /* stmt: EXIT_KW SELECT_KW endl_list  */
#line 450 "grammar.y"
                                                    {parser_print("EXIT_KW SELECT_KW endl_list -> stmt");(yyval.Stmt) = create_exit(stmt_type::ExitSelect); new_stmt = true;}
#line 3994 "grammar.tab.cpp"
    break;

  case 210: /* redim_clause: ID '(' opt_endl expr_list opt_endl ')'  */
#line 453 "grammar.y"
                                                                     { parser_print("ID '(' opt_endl expr_list opt_endl ')' -> redim_clause"); (yyval.RedimNode) = create_redim_clause((yyvsp[-5].Id), (yyvsp[-2].ExprList)); }
#line 4000 "grammar.tab.cpp"
    break;

  case 211: /* redim_clause_list: redim_clause  */
#line 456 "grammar.y"
                                                                     { parser_print("redim_clause -> redim_clause_list"); (yyval.Redim) = create_redim_clause_list(); (yyval.Redim)->add((yyvsp[0].RedimNode)); }
#line 4006 "grammar.tab.cpp"
    break;

  case 212: /* redim_clause_list: redim_clause_list ',' opt_endl redim_clause  */
#line 457 "grammar.y"
                                                                     { parser_print("redim_clause_list ',' opt_endl redim_clause -> redim_clause_list"); (yyval.Redim) = (yyvsp[-3].Redim); (yyval.Redim)->add((yyvsp[0].RedimNode)); }
#line 4012 "grammar.tab.cpp"
    break;

  case 213: /* if_stmt: IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list block END_IF endl_list  */
#line 460 "grammar.y"
                                                                                                                        { parser_print("IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list block END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-9].Expr), (yyvsp[-6].Block), (yyvsp[-5].Block), (yyvsp[-2].Block)); }
#line 4018 "grammar.tab.cpp"
    break;

  case 214: /* if_stmt: IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list block END_IF endl_list  */
#line 461 "grammar.y"
                                                                                                                            { parser_print("IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list block END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-8].Expr), NULL, (yyvsp[-5].Block), (yyvsp[-2].Block)); }
#line 4024 "grammar.tab.cpp"
    break;

  case 215: /* if_stmt: IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list END_IF endl_list  */
#line 462 "grammar.y"
                                                                                                                            { parser_print("IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-8].Expr), (yyvsp[-5].Block), (yyvsp[-4].Block), NULL); }
#line 4030 "grammar.tab.cpp"
    break;

  case 216: /* if_stmt: IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list END_IF endl_list  */
#line 463 "grammar.y"
                                                                                                                            { parser_print("IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-7].Expr), NULL, (yyvsp[-4].Block), NULL); }
#line 4036 "grammar.tab.cpp"
    break;

  case 217: /* if_stmt: IF_KW expr THEN_KW endl_list block else_if_stmts END_IF endl_list  */
#line 464 "grammar.y"
                                                                                                                        { parser_print("IF_KW expr THEN_KW endl_list block else_if_stmts END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-6].Expr), (yyvsp[-3].Block), (yyvsp[-2].Block), NULL); }
#line 4042 "grammar.tab.cpp"
    break;

  case 218: /* if_stmt: IF_KW expr THEN_KW endl_list else_if_stmts END_IF endl_list  */
#line 465 "grammar.y"
                                                                                                                            { parser_print("IF_KW expr THEN_KW endl_list else_if_stmts END_IF endl_list -> if_stmt"); (yyval.Stmt) = create_if_stmt((yyvsp[-5].Expr), NULL, (yyvsp[-2].Block), NULL); }
#line 4048 "grammar.tab.cpp"
    break;

  case 219: /* else_if_stmts: %empty  */
#line 468 "grammar.y"
                                                                               { parser_print("empty -> else_if_stmts"); (yyval.Block) = create_block(); }
#line 4054 "grammar.tab.cpp"
    break;

  case 220: /* else_if_stmts: else_if_stmts ELSEIF_KW expr THEN_KW endl_list block  */
#line 469 "grammar.y"
                                                                               { parser_print("else_if_stmts ELSEIF_KW expr THEN_KW endl_list block -> else_if_stmts"); (yyval.Block) = (yyvsp[-5].Block); (yyval.Block)->add(create_elseif((yyvsp[-3].Expr), (yyvsp[0].Block))); }
#line 4060 "grammar.tab.cpp"
    break;

  case 221: /* else_if_stmts: else_if_stmts ELSEIF_KW expr THEN_KW endl_list  */
#line 470 "grammar.y"
                                                                                           { parser_print("else_if_stmts ELSEIF_KW expr THEN_KW endl_list -> else_if_stmts"); (yyval.Block) = (yyvsp[-4].Block); (yyval.Block)->add(create_elseif((yyvsp[-2].Expr), NULL)); }
#line 4066 "grammar.tab.cpp"
    break;

  case 222: /* select_stmt: SELECT_KW expr endl_list case_stmts END_SELECT endl_list  */
#line 473 "grammar.y"
                                                                                         { parser_print("SELECT_KW expr endl_list case_stmts END_SELECT endl_list -> select_stmt"); (yyval.Stmt) = create_select_stmt((yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4072 "grammar.tab.cpp"
    break;

  case 223: /* select_stmt: SELECT_KW CASE_KW expr endl_list case_stmts END_SELECT endl_list  */
#line 474 "grammar.y"
                                                                                         { parser_print("SELECT_KW CASE_KW expr endl_list case_stmts END_SELECT endl_list -> select_stmt"); (yyval.Stmt) = create_select_stmt((yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4078 "grammar.tab.cpp"
    break;

  case 224: /* case_condition_branch: CASE_KW expr endl_list block  */
#line 477 "grammar.y"
                                                                                         { parser_print("CASE_KW expr endl_list block -> case_condition_branch"); (yyval.Stmt) = create_case_condition_branch((yyvsp[-2].Expr), (yyvsp[0].Block)); }
#line 4084 "grammar.tab.cpp"
    break;

  case 225: /* case_condition_branch: CASE_KW expr endl_list  */
#line 478 "grammar.y"
                                                                                                             { parser_print("CASE_KW expr endl_list -> case_condition_branch"); (yyval.Stmt) = create_case_condition_branch((yyvsp[-1].Expr), NULL); }
#line 4090 "grammar.tab.cpp"
    break;

  case 226: /* case_condition_branch: CASE_KW expr TO_KW expr endl_list block  */
#line 479 "grammar.y"
                                                                                         { parser_print("CASE_KW expr TO_KW expr endl_list block -> case_condition_branch"); (yyval.Stmt) = create_case_range_branch((yyvsp[-4].Expr), (yyvsp[-2].Expr), (yyvsp[0].Block)); }
#line 4096 "grammar.tab.cpp"
    break;

  case 227: /* case_condition_branch: CASE_KW expr TO_KW expr endl_list  */
#line 480 "grammar.y"
                                                                                                             { parser_print("CASE_KW expr TO_KW expr endl_list -> case_condition_branch"); (yyval.Stmt) = create_case_range_branch((yyvsp[-3].Expr), (yyvsp[-1].Expr), NULL); }
#line 4102 "grammar.tab.cpp"
    break;

  case 228: /* case_condition_branches: case_condition_branch  */
#line 483 "grammar.y"
                                                                                 { parser_print("case_condition_branch -> case_condition_branches"); (yyval.Block) = create_block(); }
#line 4108 "grammar.tab.cpp"
    break;

  case 229: /* case_condition_branches: case_condition_branches case_condition_branch  */
#line 484 "grammar.y"
                                                                                 { parser_print("case_condition_branches case_condition_branch -> case_condition_branches"); (yyval.Block) = (yyvsp[-1].Block); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4114 "grammar.tab.cpp"
    break;

  case 230: /* case_else_stmt: CASE_KW ELSE_KW endl_list opt_block  */
#line 487 "grammar.y"
                                                                                 { parser_print("CASE_KW ELSE_KW endl_list opt_block -> case_else_stmt"); (yyval.Stmt) = create_case_else_stmt((yyvsp[0].Block)); }
#line 4120 "grammar.tab.cpp"
    break;

  case 231: /* case_stmts: case_condition_branches  */
#line 490 "grammar.y"
                                                                                 { parser_print("case_condition_branches -> case_stmts"); (yyval.Block) = (yyvsp[0].Block); }
#line 4126 "grammar.tab.cpp"
    break;

  case 232: /* case_stmts: case_else_stmt  */
#line 491 "grammar.y"
                                                                                 { parser_print("case_else_stmt -> case_stmts"); (yyval.Block) = create_block(); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4132 "grammar.tab.cpp"
    break;

  case 233: /* case_stmts: case_condition_branches case_else_stmt  */
#line 492 "grammar.y"
                                                                                 { parser_print("case_condition_branches case_else_stmt -> case_stmts"); (yyval.Block) = (yyvsp[-1].Block); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4138 "grammar.tab.cpp"
    break;

  case 234: /* case_stmts: %empty  */
#line 493 "grammar.y"
                                                                                 { parser_print("empty -> case_stmts"); (yyval.Block) = create_block();}
#line 4144 "grammar.tab.cpp"
    break;

  case 235: /* while_stmt: WHILE_KW expr endl_list block END_WHILE endl_list  */
#line 496 "grammar.y"
                                                                                 { parser_print("WHILE_KW expr endl_list block END_WHILE endl_list -> while_stmt"); (yyval.Stmt) = create_while_stmt((yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4150 "grammar.tab.cpp"
    break;

  case 236: /* while_stmt: WHILE_KW expr endl_list END_WHILE endl_list  */
#line 497 "grammar.y"
                                                                                 { parser_print("WHILE_KW expr endl_list END_WHILE endl_list -> while_stmt"); (yyval.Stmt) = create_while_stmt((yyvsp[-3].Expr), create_block()); }
#line 4156 "grammar.tab.cpp"
    break;

  case 237: /* for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list block NEXT_KW endl_list  */
#line 500 "grammar.y"
                                                                                                                                { parser_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list block NEXT_KW endl_list -> for_stmt"); (yyval.Stmt) = create_for_stmt((yyvsp[-9].Var)->type, (yyvsp[-9].Var)->varName, (yyvsp[-6].Expr), (yyvsp[-4].Expr), NULL, (yyvsp[-2].Block)); }
#line 4162 "grammar.tab.cpp"
    break;

  case 238: /* for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list NEXT_KW endl_list  */
#line 501 "grammar.y"
                                                                                                                                { parser_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list NEXT_KW endl_list -> for_stmt"); (yyval.Stmt) = create_for_stmt((yyvsp[-8].Var)->type, (yyvsp[-8].Var)->varName, (yyvsp[-5].Expr), (yyvsp[-3].Expr), NULL, create_block()); }
#line 4168 "grammar.tab.cpp"
    break;

  case 239: /* for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list block NEXT_KW endl_list  */
#line 502 "grammar.y"
                                                                                                                                { parser_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list block NEXT_KW endl_list -> for_stmt"); (yyval.Stmt) = create_for_stmt((yyvsp[-11].Var)->type, (yyvsp[-11].Var)->varName, (yyvsp[-8].Expr), (yyvsp[-6].Expr), (yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4174 "grammar.tab.cpp"
    break;

  case 240: /* for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list NEXT_KW endl_list  */
#line 503 "grammar.y"
                                                                                                                                        { parser_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list NEXT_KW endl_list -> for_stmt"); (yyval.Stmt) = create_for_stmt((yyvsp[-10].Var)->type, (yyvsp[-10].Var)->varName, (yyvsp[-7].Expr), (yyvsp[-5].Expr), (yyvsp[-3].Expr), create_block()); }
#line 4180 "grammar.tab.cpp"
    break;

  case 241: /* for_loop_variable: ID  */
#line 506 "grammar.y"
                                                      { parser_print("ID -> for_loop_variable"); (yyval.Var) = create_var_declarator((yyvsp[0].Id)); }
#line 4186 "grammar.tab.cpp"
    break;

  case 242: /* for_loop_variable: ID AS_KW type_name  */
#line 507 "grammar.y"
                                                      { parser_print("ID AS_KW type_name -> for_loop_variable"); (yyval.Var) = create_var_declarator((yyvsp[0].Type), (yyvsp[-2].Id)); }
#line 4192 "grammar.tab.cpp"
    break;

  case 243: /* foreach_stmt: FOR_KW EACH_KW for_loop_variable opt_endl IN_KW endl_list expr endl_list opt_block NEXT_KW endl_list  */
#line 510 "grammar.y"
                                                                                                                              { parser_print("FOR_KW EACH_KW for_loop_variable opt_endl IN_KW endl_list expr endl_list opt_block NEXT_KW endl_list -> foreach_stmt"); (yyval.Stmt) = create_foreach_stmt((yyvsp[-8].Var)->type, (yyvsp[-8].Var)->varName, (yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4198 "grammar.tab.cpp"
    break;

  case 244: /* foreach_stmt: FOR_KW EACH_KW for_loop_variable opt_endl IN_KW expr endl_list opt_block NEXT_KW endl_list  */
#line 511 "grammar.y"
                                                                                                                              { parser_print("FOR_KW EACH_KW for_loop_variable opt_endl IN_KW expr endl_list opt_block NEXT_KW endl_list -> foreach_stmt"); (yyval.Stmt) = create_foreach_stmt((yyvsp[-7].Var)->type, (yyvsp[-7].Var)->varName, (yyvsp[-4].Expr), (yyvsp[-2].Block)); }
#line 4204 "grammar.tab.cpp"
    break;

  case 245: /* do_while_stmt: DO_KW endl_list opt_block LOOP_KW WHILE_KW expr endl_list  */
#line 514 "grammar.y"
                                                                                                                              { parser_print("DO_KW endl_list opt_block LOOP_KW WHILE_KW expr endl_list -> do_while_stmt"); (yyval.Stmt) = create_do_while_stmt((yyvsp[-4].Block), (yyvsp[-1].Expr)); }
#line 4210 "grammar.tab.cpp"
    break;

  case 246: /* do_while_stmt: DO_KW WHILE_KW expr endl_list opt_block LOOP_KW endl_list  */
#line 515 "grammar.y"
                                                                                                                              { parser_print("DO_KW WHILE_KW expr endl_list opt_block LOOP_KW endl_list -> do_while_stmt"); (yyval.Stmt) = create_do_while_stmt((yyvsp[-2].Block), (yyvsp[-4].Expr)); }
#line 4216 "grammar.tab.cpp"
    break;

  case 247: /* do_until_stmt: DO_KW endl_list opt_block LOOP_KW UNTIL_KW expr endl_list  */
#line 518 "grammar.y"
                                                                                                                              { parser_print("DO_KW endl_list opt_block LOOP_KW UNTIL_KW expr endl_list -> do_until_stmt"); (yyval.Stmt) = create_do_until_stmt((yyvsp[-4].Block), (yyvsp[-1].Expr)); }
#line 4222 "grammar.tab.cpp"
    break;

  case 248: /* do_until_stmt: DO_KW UNTIL_KW expr endl_list opt_block LOOP_KW endl_list  */
#line 519 "grammar.y"
                                                                                                                              { parser_print("DO_KW UNTIL_KW expr endl_list opt_block LOOP_KW endl_list -> do_until_stmt"); (yyval.Stmt) = create_do_until_stmt((yyvsp[-2].Block), (yyvsp[-4].Expr)); }
#line 4228 "grammar.tab.cpp"
    break;

  case 249: /* opt_block: %empty  */
#line 522 "grammar.y"
                               { parser_print("empty -> opt_block"); (yyval.Block) = create_block(); }
#line 4234 "grammar.tab.cpp"
    break;

  case 250: /* opt_block: block  */
#line 523 "grammar.y"
                               { parser_print("block -> opt_block"); (yyval.Block) = (yyvsp[0].Block); }
#line 4240 "grammar.tab.cpp"
    break;

  case 251: /* block: stmt  */
#line 526 "grammar.y"
                               { parser_print("stmt -> block"); (yyval.Block) = create_block(); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4246 "grammar.tab.cpp"
    break;

  case 252: /* block: block stmt  */
#line 527 "grammar.y"
                               { parser_print("block stmt -> block"); (yyval.Block) = (yyvsp[-1].Block); (yyval.Block)->add((yyvsp[0].Stmt)); }
#line 4252 "grammar.tab.cpp"
    break;

  case 253: /* variable_name: ID  */
#line 530 "grammar.y"
                                              { parser_print("ID -> variable_name"); (yyval.Var) = create_var_declarator((yyvsp[0].Id)); }
#line 4258 "grammar.tab.cpp"
    break;

  case 254: /* variable_name: ID array_modifier  */
#line 531 "grammar.y"
                                              { parser_print("ID array_modifier -> variable_name"); (yyval.Var) = create_array_var_declarator((yyvsp[-1].Id), (yyvsp[0].Expr)); }
#line 4264 "grammar.tab.cpp"
    break;

  case 255: /* array_modifier: '(' opt_endl expr opt_endl ')'  */
#line 534 "grammar.y"
                                               { parser_print("'(' ENDL ')' -> array_modifier"); (yyval.Expr) = (yyvsp[-2].Expr);}
#line 4270 "grammar.tab.cpp"
    break;

  case 256: /* array_modifier: '(' ')'  */
#line 535 "grammar.y"
                                               { parser_print("'(' ')' -> array_modifier"); (yyval.Expr) = NULL;}
#line 4276 "grammar.tab.cpp"
    break;

  case 257: /* var_declarator: variable_name  */
#line 539 "grammar.y"
                                                                     { parser_print("variable_name -> var_declarator"); (yyval.Var) = (yyvsp[0].Var); }
#line 4282 "grammar.tab.cpp"
    break;

  case 258: /* var_declarator: variable_name AS_KW type_name  */
#line 540 "grammar.y"
                                                                     { parser_print("variable_name AS_KW type_name -> var_declarator"); (yyval.Var) = append_var_declarator((yyvsp[-2].Var), (yyvsp[0].Type), NULL); }
#line 4288 "grammar.tab.cpp"
    break;

  case 259: /* var_declarator: variable_name '=' expr  */
#line 541 "grammar.y"
                                                                     { parser_print("variable_name '=' expr -> var_declarator"); (yyval.Var) = append_var_declarator((yyvsp[-2].Var), NULL, (yyvsp[0].Expr)); }
#line 4294 "grammar.tab.cpp"
    break;

  case 260: /* var_declarator: variable_name AS_KW type_name '=' expr  */
#line 542 "grammar.y"
                                                                     { parser_print("variable_name AS_KW type_name '=' expr -> var_declarator"); (yyval.Var) = append_var_declarator((yyvsp[-4].Var), (yyvsp[-2].Type), (yyvsp[0].Expr)); }
#line 4300 "grammar.tab.cpp"
    break;

  case 261: /* var_declaration: DIM_KW var_declarator endl_list  */
#line 545 "grammar.y"
                                                                     { parser_print("DIM_KW var_declarator endl_list -> var_declaration"); (yyval.Stmt) = create_var_declaration((yyvsp[-1].Var), var_type::DIM); }
#line 4306 "grammar.tab.cpp"
    break;

  case 262: /* var_declaration: CONST_KW var_declarator endl_list  */
#line 546 "grammar.y"
                                                                     { parser_print("CONST_KW var_declarator endl_list -> var_declaration"); (yyval.Stmt) = create_var_declaration((yyvsp[-1].Var), var_type::CONST); }
#line 4312 "grammar.tab.cpp"
    break;

  case 263: /* type_name: ID  */
#line 550 "grammar.y"
              {parser_print("ID -> type_name"); (yyval.Type) = create_type(datatype_type::UserType, (yyvsp[0].Id));}
#line 4318 "grammar.tab.cpp"
    break;

  case 264: /* type_name: ID '(' opt_endl OF_KW type_list opt_endl ')'  */
#line 551 "grammar.y"
                                                        {parser_print("ID '(' opt_endl OF_KW type_list opt_endl ')' -> type_name"); (yyval.Type) = create_type(datatype_type::UserType, (yyvsp[-6].Id), (yyvsp[-2].TypeList));}
#line 4324 "grammar.tab.cpp"
    break;

  case 265: /* type_name: primitive_type  */
#line 552 "grammar.y"
                          {parser_print("primitive_type -> type_name"); (yyval.Type) = (yyvsp[0].Type);}
#line 4330 "grammar.tab.cpp"
    break;

  case 266: /* type_name: ID '(' opt_endl ')'  */
#line 553 "grammar.y"
                               {parser_print("ID '(' opt_endl ')' -> type_name"); (yyval.Type) = create_array_type(create_type(datatype_type::UserType, (yyvsp[-3].Id)));}
#line 4336 "grammar.tab.cpp"
    break;

  case 267: /* type_name: ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')'  */
#line 554 "grammar.y"
                                                                         {parser_print("ID '(' opt_endl OF_KW type_list opt_endl ')' '(' opt_endl ')'  -> type_name"); (yyval.Type) = create_array_type(create_type(datatype_type::UserType, (yyvsp[-9].Id), (yyvsp[-5].TypeList)));}
#line 4342 "grammar.tab.cpp"
    break;

  case 268: /* type_name: primitive_type '(' opt_endl ')'  */
#line 555 "grammar.y"
                                           {parser_print("primitive_type '(' opt_endl ')' -> type_name"); (yyval.Type) = create_array_type((yyvsp[-3].Type));}
#line 4348 "grammar.tab.cpp"
    break;

  case 269: /* simple_type_name: ID  */
#line 558 "grammar.y"
                            {parser_print("ID -> simple_type_name"); (yyval.Type) = create_type(datatype_type::UserType, (yyvsp[0].Id));}
#line 4354 "grammar.tab.cpp"
    break;

  case 270: /* simple_type_name: ID '(' opt_endl OF_KW type_list opt_endl ')'  */
#line 559 "grammar.y"
                                                               {parser_print("ID '(' opt_endl OF_KW type_list opt_endl ')' -> simple_type_name"); (yyval.Type) = create_type(datatype_type::UserType, (yyvsp[-6].Id), (yyvsp[-2].TypeList));}
#line 4360 "grammar.tab.cpp"
    break;

  case 271: /* simple_type_name: primitive_type  */
#line 560 "grammar.y"
                                   {parser_print("primitive_type -> simple_type_name"); (yyval.Type) = (yyvsp[0].Type);}
#line 4366 "grammar.tab.cpp"
    break;

  case 272: /* primitive_type: BYTE_KW  */
#line 563 "grammar.y"
                             { parser_print("BYTE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Byte); }
#line 4372 "grammar.tab.cpp"
    break;

  case 273: /* primitive_type: SBYTE_KW  */
#line 564 "grammar.y"
                             { parser_print("SBYTE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::SByte); }
#line 4378 "grammar.tab.cpp"
    break;

  case 274: /* primitive_type: USHORT_KW  */
#line 565 "grammar.y"
                             { parser_print("USHORT_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::UShort); }
#line 4384 "grammar.tab.cpp"
    break;

  case 275: /* primitive_type: SHORT_KW  */
#line 566 "grammar.y"
                             { parser_print("SHORT_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Short); }
#line 4390 "grammar.tab.cpp"
    break;

  case 276: /* primitive_type: UINTEGER_KW  */
#line 567 "grammar.y"
                             { parser_print("UINTEGER_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::UInteger); }
#line 4396 "grammar.tab.cpp"
    break;

  case 277: /* primitive_type: INTEGER_KW  */
#line 568 "grammar.y"
                             { parser_print("INTEGER_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Integer); }
#line 4402 "grammar.tab.cpp"
    break;

  case 278: /* primitive_type: ULONG_KW  */
#line 569 "grammar.y"
                             { parser_print("ULONG_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::ULong); }
#line 4408 "grammar.tab.cpp"
    break;

  case 279: /* primitive_type: LONG_KW  */
#line 570 "grammar.y"
                             { parser_print("LONG_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Long); }
#line 4414 "grammar.tab.cpp"
    break;

  case 280: /* primitive_type: BOOLEAN_KW  */
#line 571 "grammar.y"
                             { parser_print("BOOLEAN_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Boolean); }
#line 4420 "grammar.tab.cpp"
    break;

  case 281: /* primitive_type: DATE_KW  */
#line 572 "grammar.y"
                             { parser_print("DATE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Date); }
#line 4426 "grammar.tab.cpp"
    break;

  case 282: /* primitive_type: CHAR_KW  */
#line 573 "grammar.y"
                             { parser_print("CHAR_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Char); }
#line 4432 "grammar.tab.cpp"
    break;

  case 283: /* primitive_type: STRING_KW  */
#line 574 "grammar.y"
                             { parser_print("STRING_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::String); }
#line 4438 "grammar.tab.cpp"
    break;

  case 284: /* primitive_type: DECIMAL_KW  */
#line 575 "grammar.y"
                             { parser_print("DECIMAL_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Decimal); }
#line 4444 "grammar.tab.cpp"
    break;

  case 285: /* primitive_type: SINGLE_KW  */
#line 576 "grammar.y"
                             { parser_print("SINGLE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Single); }
#line 4450 "grammar.tab.cpp"
    break;

  case 286: /* primitive_type: DOUBLE_KW  */
#line 577 "grammar.y"
                             { parser_print("DOUBLE_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Double); }
#line 4456 "grammar.tab.cpp"
    break;

  case 287: /* primitive_type: OBJECT_KW  */
#line 578 "grammar.y"
                             { parser_print("OBJECT_KW -> primitive_type"); (yyval.Type) = create_type(datatype_type::Object); }
#line 4462 "grammar.tab.cpp"
    break;

  case 288: /* type_list: simple_type_name  */
#line 581 "grammar.y"
                                                              { parser_print("simple_type_name -> type_list"); (yyval.TypeList) = create_type_list(); (yyval.TypeList)->add((yyvsp[0].Type)); }
#line 4468 "grammar.tab.cpp"
    break;

  case 289: /* type_list: type_list ',' opt_endl simple_type_name  */
#line 582 "grammar.y"
                                                              { parser_print("type_list ',' opt_endl simple_type_name -> type_list"); (yyval.TypeList) = (yyvsp[-3].TypeList); (yyval.TypeList)->add((yyvsp[0].Type));  }
#line 4474 "grammar.tab.cpp"
    break;

  case 290: /* id_list: ID  */
#line 585 "grammar.y"
                                                              { parser_print("ID -> id_list"); (yyval.IdList) = create_id_list(); (yyval.IdList)->add(*(yyvsp[0].Id)); }
#line 4480 "grammar.tab.cpp"
    break;

  case 291: /* id_list: id_list ',' opt_endl ID  */
#line 586 "grammar.y"
                                                              { parser_print("id_list ',' opt_endl ID -> id_list"); (yyval.IdList) = (yyvsp[-3].IdList); (yyval.IdList)->add(*(yyvsp[0].Id)); }
#line 4486 "grammar.tab.cpp"
    break;

  case 292: /* function_signature: FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' AS_KW type_name  */
#line 589 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-7].Id), (yyvsp[-4].Vars), (yyvsp[0].Type), NULL); }
#line 4492 "grammar.tab.cpp"
    break;

  case 293: /* function_signature: FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')'  */
#line 590 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-5].Id), (yyvsp[-2].Vars), object_type(), NULL); }
#line 4498 "grammar.tab.cpp"
    break;

  case 294: /* function_signature: FUNCTION_KW ID '(' opt_endl ')' AS_KW type_name  */
#line 591 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID '(' opt_endl ')' AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-5].Id), NULL, (yyvsp[0].Type), NULL); }
#line 4504 "grammar.tab.cpp"
    break;

  case 295: /* function_signature: FUNCTION_KW ID '(' opt_endl ')'  */
#line 592 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID '(' opt_endl ')' -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-3].Id), NULL, object_type(), NULL); }
#line 4510 "grammar.tab.cpp"
    break;

  case 296: /* function_signature: FUNCTION_KW ID AS_KW type_name  */
#line 593 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-2].Id), NULL, (yyvsp[0].Type), NULL); }
#line 4516 "grammar.tab.cpp"
    break;

  case 297: /* function_signature: FUNCTION_KW ID  */
#line 594 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID -> function_signature"); (yyval.Procedure) = create_function((yyvsp[0].Id), NULL, object_type(), NULL); }
#line 4522 "grammar.tab.cpp"
    break;

  case 298: /* function_signature: FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' AS_KW type_name  */
#line 595 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-8].Id), (yyvsp[-4].Vars), (yyvsp[0].Type), (yyvsp[-7].IdList)); }
#line 4528 "grammar.tab.cpp"
    break;

  case 299: /* function_signature: FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')'  */
#line 596 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-6].Id), (yyvsp[-2].Vars), object_type(), (yyvsp[-5].IdList)); }
#line 4534 "grammar.tab.cpp"
    break;

  case 300: /* function_signature: FUNCTION_KW ID generic_param_list '(' opt_endl ')' AS_KW type_name  */
#line 597 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID generic_param_list '(' opt_endl ')' AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-6].Id), NULL, (yyvsp[0].Type), (yyvsp[-5].IdList)); }
#line 4540 "grammar.tab.cpp"
    break;

  case 301: /* function_signature: FUNCTION_KW ID generic_param_list '(' opt_endl ')'  */
#line 598 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID generic_param_list '(' opt_endl ')' -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-4].Id), NULL, object_type(), (yyvsp[-3].IdList)); }
#line 4546 "grammar.tab.cpp"
    break;

  case 302: /* function_signature: FUNCTION_KW ID generic_param_list AS_KW type_name  */
#line 599 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID generic_param_list AS_KW type_name -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-3].Id), NULL, (yyvsp[0].Type), (yyvsp[-2].IdList)); }
#line 4552 "grammar.tab.cpp"
    break;

  case 303: /* function_signature: FUNCTION_KW ID generic_param_list  */
#line 600 "grammar.y"
                                                                                                                                  { parser_print("FUNCTION_KW ID generic_param_list -> function_signature"); (yyval.Procedure) = create_function((yyvsp[-1].Id), NULL, object_type(), (yyvsp[0].IdList)); }
#line 4558 "grammar.tab.cpp"
    break;

  case 304: /* sub_signature: SUB_KW ID '(' opt_endl function_parameters opt_endl ')'  */
#line 603 "grammar.y"
                                                                                          { parser_print("SUB_KW ID '(' opt_endl function_parameters opt_endl ')' -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[-5].Id), (yyvsp[-2].Vars), NULL, NULL); }
#line 4564 "grammar.tab.cpp"
    break;

  case 305: /* sub_signature: SUB_KW ID '(' opt_endl ')'  */
#line 604 "grammar.y"
                                                                                          { parser_print("SUB_KW ID '(' opt_endl ')' -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[-3].Id), NULL, NULL, NULL);}
#line 4570 "grammar.tab.cpp"
    break;

  case 306: /* sub_signature: SUB_KW ID  */
#line 605 "grammar.y"
                                                                                          { parser_print("SUB_KW ID -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[0].Id), NULL, NULL, NULL); }
#line 4576 "grammar.tab.cpp"
    break;

  case 307: /* sub_signature: SUB_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')'  */
#line 606 "grammar.y"
                                                                                          { parser_print("SUB_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[-6].Id), (yyvsp[-2].Vars), NULL, (yyvsp[-5].IdList));}
#line 4582 "grammar.tab.cpp"
    break;

  case 308: /* sub_signature: SUB_KW ID generic_param_list '(' opt_endl ')'  */
#line 607 "grammar.y"
                                                                                          { parser_print("SUB_KW ID generic_param_list '(' opt_endl ')' -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[-4].Id), NULL, NULL, (yyvsp[-3].IdList)); }
#line 4588 "grammar.tab.cpp"
    break;

  case 309: /* sub_signature: SUB_KW ID generic_param_list  */
#line 608 "grammar.y"
                                                                                          { parser_print("SUB_KW ID generic_param_list -> sub_signature"); (yyval.Procedure) = create_function((yyvsp[-1].Id), NULL, NULL, (yyvsp[0].IdList)); }
#line 4594 "grammar.tab.cpp"
    break;

  case 310: /* function_declaration: opt_procedure_modifiers function_signature endl_list block END_FUNCTION endl_list  */
#line 611 "grammar.y"
                                                                                                            { parser_print("opt_procedure_modifiers function_signature endl_list block END_FUNCTION endl_list -> function_declaration"); (yyval.Procedure) = (yyvsp[-4].Procedure); (yyval.Procedure)->block = (yyvsp[-2].Block); (yyval.Procedure)->isStatic = (yyvsp[-5].Bool); }
#line 4600 "grammar.tab.cpp"
    break;

  case 311: /* function_declaration: opt_procedure_modifiers function_signature endl_list END_FUNCTION endl_list  */
#line 612 "grammar.y"
                                                                                                            { parser_print("opt_procedure_modifiers function_signature endl_list END_FUNCTION endl_list -> function_declaration"); (yyval.Procedure) = (yyvsp[-3].Procedure); (yyval.Procedure)->block = create_block(); (yyval.Procedure)->isStatic = (yyvsp[-4].Bool); }
#line 4606 "grammar.tab.cpp"
    break;

  case 312: /* sub_declaration: opt_procedure_modifiers sub_signature endl_list block END_SUB endl_list  */
#line 615 "grammar.y"
                                                                                                  { parser_print("opt_procedure_modifiers sub_signature endl_list block END_SUB endl_list -> sub_declaration"); (yyval.Procedure) = (yyvsp[-4].Procedure); (yyval.Procedure)->block = (yyvsp[-2].Block); (yyval.Procedure)->isStatic = (yyvsp[-5].Bool); }
#line 4612 "grammar.tab.cpp"
    break;

  case 313: /* sub_declaration: opt_procedure_modifiers sub_signature endl_list END_SUB endl_list  */
#line 616 "grammar.y"
                                                                                                              { parser_print("opt_procedure_modifiers sub_signature endl_list END_SUB endl_list -> sub_declaration"); (yyval.Procedure) = (yyvsp[-3].Procedure); (yyval.Procedure)->block = create_block(); (yyval.Procedure)->isStatic = (yyvsp[-4].Bool); }
#line 4618 "grammar.tab.cpp"
    break;

  case 314: /* opt_procedure_modifiers: SHARED_KW  */
#line 619 "grammar.y"
                                                    { parser_print("SHARED_KW -> opt_procedure_modifiers"); (yyval.Bool) = true; }
#line 4624 "grammar.tab.cpp"
    break;

  case 315: /* opt_procedure_modifiers: %empty  */
#line 620 "grammar.y"
                                                    { parser_print("empty -> opt_procedure_modifiers"); (yyval.Bool) = false; }
#line 4630 "grammar.tab.cpp"
    break;

  case 316: /* function_parameters: function_parameter  */
#line 623 "grammar.y"
                                                                      { parser_print("function_parameter -> function_parameters"); (yyval.Vars) = new list<typed_value*>(); (yyval.Vars)->add((yyvsp[0].Var)); }
#line 4636 "grammar.tab.cpp"
    break;

  case 317: /* function_parameters: function_parameters ',' function_parameter  */
#line 624 "grammar.y"
                                                                      { parser_print("function_parameters ',' function_parameter -> function_parameters"); (yyval.Vars) = (yyvsp[-2].Vars); (yyval.Vars)->add((yyvsp[0].Var)); }
#line 4642 "grammar.tab.cpp"
    break;

  case 318: /* function_parameter: variable_name AS_KW type_name  */
#line 627 "grammar.y"
                                                                               { parser_print("variable_name AS_KW type_name -> function_parameter"); (yyval.Var) = (yyvsp[-2].Var); (yyvsp[-2].Var)->type = (yyvsp[0].Type); }
#line 4648 "grammar.tab.cpp"
    break;

  case 319: /* function_parameter: variable_name  */
#line 628 "grammar.y"
                                                                               { parser_print("variable_name -> function_parameter"); (yyval.Var) = (yyvsp[0].Var); }
#line 4654 "grammar.tab.cpp"
    break;

  case 320: /* class_declaration: CLASS_KW ID stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW  */
#line 631 "grammar.y"
                                                                                                                              { parser_print("CLASS_KW ID stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); (yyval.Struct) = parse_struct_body(create_class((yyvsp[-7].Id), NULL, (yyvsp[-4].Id)), (yyvsp[-2].UnknownBody)); }
#line 4660 "grammar.tab.cpp"
    break;

  case 321: /* class_declaration: CLASS_KW ID endl_list opt_structure_body END_KW CLASS_KW  */
#line 632 "grammar.y"
                                                                                                                              { parser_print("CLASS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); (yyval.Struct) = parse_struct_body(create_class((yyvsp[-4].Id), NULL, NULL), (yyvsp[-2].UnknownBody)); }
#line 4666 "grammar.tab.cpp"
    break;

  case 322: /* class_declaration: CLASS_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW  */
#line 633 "grammar.y"
                                                                                                                              { parser_print("CLASS_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); (yyval.Struct) = parse_struct_body(create_class((yyvsp[-8].Id), (yyvsp[-7].IdList), (yyvsp[-4].Id)), (yyvsp[-2].UnknownBody)); }
#line 4672 "grammar.tab.cpp"
    break;

  case 323: /* class_declaration: CLASS_KW ID generic_param_list endl_list opt_structure_body END_KW CLASS_KW  */
#line 634 "grammar.y"
                                                                                                                              { parser_print("CLASS_KW ID generic_param_list endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); (yyval.Struct) = parse_struct_body(create_class((yyvsp[-5].Id), (yyvsp[-4].IdList), NULL), (yyvsp[-2].UnknownBody)); }
#line 4678 "grammar.tab.cpp"
    break;

  case 324: /* generic_param_list: '(' opt_endl OF_KW id_list opt_endl ')'  */
#line 637 "grammar.y"
                                                                                     { parser_print("ID '(' opt_endl OF_KW id_list opt_endl ')' -> generic_param_list"); (yyval.IdList) = (yyvsp[-2].IdList); }
#line 4684 "grammar.tab.cpp"
    break;

  case 325: /* opt_structure_body: %empty  */
#line 640 "grammar.y"
                                         { parser_print("empty -> opt_structure_body"); (yyval.UnknownBody) = create_node_list(); }
#line 4690 "grammar.tab.cpp"
    break;

  case 326: /* opt_structure_body: structure_body  */
#line 641 "grammar.y"
                                         { parser_print("structure_body -> opt_structure_body"); (yyval.UnknownBody) = (yyvsp[0].UnknownBody); }
#line 4696 "grammar.tab.cpp"
    break;

  case 327: /* structure_body: structure_member  */
#line 644 "grammar.y"
                                                          { parser_print("structure_member -> structure_body"); (yyval.UnknownBody) = create_node_list(); (yyval.UnknownBody)->add((yyvsp[0].Unknown)); }
#line 4702 "grammar.tab.cpp"
    break;

  case 328: /* structure_body: structure_body structure_member  */
#line 645 "grammar.y"
                                                          { parser_print("structure_body structure_member -> structure_body"); (yyval.UnknownBody) = (yyvsp[-1].UnknownBody);  (yyval.UnknownBody)->add((yyvsp[0].Unknown)); }
#line 4708 "grammar.tab.cpp"
    break;

  case 329: /* structure_member: function_declaration  */
#line 648 "grammar.y"
                                                         { parser_print("function_declaration -> structure_member"); (yyval.Unknown) = (yyvsp[0].Procedure); }
#line 4714 "grammar.tab.cpp"
    break;

  case 330: /* structure_member: sub_declaration  */
#line 649 "grammar.y"
                                                         { parser_print("sub_declaration -> structure_member"); (yyval.Unknown) = (yyvsp[0].Procedure); }
#line 4720 "grammar.tab.cpp"
    break;

  case 331: /* structure_member: field_declaration  */
#line 650 "grammar.y"
                                                         { parser_print("field_declaration -> structure_member"); (yyval.Unknown) = (yyvsp[0].Field); }
#line 4726 "grammar.tab.cpp"
    break;

  case 332: /* field_declaration: DIM_KW var_declarator endl_list  */
#line 653 "grammar.y"
                                                           { parser_print("DIM_KW var_declarator endl_list -> field_declaration"); (yyval.Field) = create_field((yyvsp[-1].Var)); }
#line 4732 "grammar.tab.cpp"
    break;


#line 4736 "grammar.tab.cpp"

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

#line 656 "grammar.y"


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

int main(int argc, char** argv) {
    if (argc > 1) {
        if (strcmp(argv[1], "--debug") == 0) {
            PARSER_DEBUG = true;
            LEXER_DEBUG = true;
            runParserTests();
            return 0;
        }
        fopen_s(&yyin, argv[1], "r");
        if (argc > 2 && strcmp(argv[2], "--debug") == 0) {
            DEBUG = true;
        }
        yyparse();
    }
    else {
        printf("File not found");
    }
}
