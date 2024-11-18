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
#include "../compiler/utils.hpp"

extern int yylineno;
extern FILE* yyin;

int yyparse();
int yylex();

void yyerror(char const* s) {
    fprintf(stderr, "Error: %s on line %d\n", s, yylineno);
    exit(1);
}

bool DEBUG = true;


#line 91 "grammar.tab.cpp"

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
  YYSYMBOL_STRING = 4,                     /* STRING  */
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
  YYSYMBOL_BARE_NEW = 107,                 /* BARE_NEW  */
  YYSYMBOL_XOR = 108,                      /* XOR  */
  YYSYMBOL_OR = 109,                       /* OR  */
  YYSYMBOL_OR_ELSE = 110,                  /* OR_ELSE  */
  YYSYMBOL_AND = 111,                      /* AND  */
  YYSYMBOL_AND_ALSO = 112,                 /* AND_ALSO  */
  YYSYMBOL_NOT = 113,                      /* NOT  */
  YYSYMBOL_114_ = 114,                     /* '='  */
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
  YYSYMBOL_140_ = 140,                     /* ':'  */
  YYSYMBOL_141_ = 141,                     /* ','  */
  YYSYMBOL_YYACCEPT = 142,                 /* $accept  */
  YYSYMBOL_program = 143,                  /* program  */
  YYSYMBOL_program_member = 144,           /* program_member  */
  YYSYMBOL_endl_list = 145,                /* endl_list  */
  YYSYMBOL_stmt_endl = 146,                /* stmt_endl  */
  YYSYMBOL_opt_endl = 147,                 /* opt_endl  */
  YYSYMBOL_kw = 148,                       /* kw  */
  YYSYMBOL_type_name = 149,                /* type_name  */
  YYSYMBOL_expr = 150,                     /* expr  */
  YYSYMBOL_cast_target = 151,              /* cast_target  */
  YYSYMBOL_collection_initializer = 152,   /* collection_initializer  */
  YYSYMBOL_member_access_member = 153,     /* member_access_member  */
  YYSYMBOL_expr_list = 154,                /* expr_list  */
  YYSYMBOL_stmt = 155,                     /* stmt  */
  YYSYMBOL_label_name = 156,               /* label_name  */
  YYSYMBOL_label_stmt = 157,               /* label_stmt  */
  YYSYMBOL_redim_clause = 158,             /* redim_clause  */
  YYSYMBOL_redim_clause_list = 159,        /* redim_clause_list  */
  YYSYMBOL_if_stmt = 160,                  /* if_stmt  */
  YYSYMBOL_else_if_stmts = 161,            /* else_if_stmts  */
  YYSYMBOL_select_stmt = 162,              /* select_stmt  */
  YYSYMBOL_case_condition_branch = 163,    /* case_condition_branch  */
  YYSYMBOL_case_condition_branches = 164,  /* case_condition_branches  */
  YYSYMBOL_case_else_stmt = 165,           /* case_else_stmt  */
  YYSYMBOL_case_stmts = 166,               /* case_stmts  */
  YYSYMBOL_while_stmt = 167,               /* while_stmt  */
  YYSYMBOL_for_stmt = 168,                 /* for_stmt  */
  YYSYMBOL_for_loop_variable = 169,        /* for_loop_variable  */
  YYSYMBOL_foreach_stmt = 170,             /* foreach_stmt  */
  YYSYMBOL_do_while_stmt = 171,            /* do_while_stmt  */
  YYSYMBOL_do_until_stmt = 172,            /* do_until_stmt  */
  YYSYMBOL_opt_block = 173,                /* opt_block  */
  YYSYMBOL_block = 174,                    /* block  */
  YYSYMBOL_variable_name = 175,            /* variable_name  */
  YYSYMBOL_array_modifier = 176,           /* array_modifier  */
  YYSYMBOL_var_declarator = 177,           /* var_declarator  */
  YYSYMBOL_var_declaration = 178,          /* var_declaration  */
  YYSYMBOL_array_type_name = 179,          /* array_type_name  */
  YYSYMBOL_simple_type_name = 180,         /* simple_type_name  */
  YYSYMBOL_primitive_type = 181,           /* primitive_type  */
  YYSYMBOL_type_list = 182,                /* type_list  */
  YYSYMBOL_id_list = 183,                  /* id_list  */
  YYSYMBOL_function_signature = 184,       /* function_signature  */
  YYSYMBOL_sub_signature = 185,            /* sub_signature  */
  YYSYMBOL_constructor_signature = 186,    /* constructor_signature  */
  YYSYMBOL_constructor_declaration = 187,  /* constructor_declaration  */
  YYSYMBOL_function_declaration = 188,     /* function_declaration  */
  YYSYMBOL_sub_declaration = 189,          /* sub_declaration  */
  YYSYMBOL_opt_procedure_modifiers = 190,  /* opt_procedure_modifiers  */
  YYSYMBOL_function_parameters = 191,      /* function_parameters  */
  YYSYMBOL_function_parameter = 192,       /* function_parameter  */
  YYSYMBOL_class_declaration = 193,        /* class_declaration  */
  YYSYMBOL_struct_declaration = 194,       /* struct_declaration  */
  YYSYMBOL_generic_param_list = 195,       /* generic_param_list  */
  YYSYMBOL_opt_structure_body = 196,       /* opt_structure_body  */
  YYSYMBOL_structure_body = 197,           /* structure_body  */
  YYSYMBOL_structure_member = 198,         /* structure_member  */
  YYSYMBOL_const_declaration = 199,        /* const_declaration  */
  YYSYMBOL_field_declaration = 200,        /* field_declaration  */
  YYSYMBOL_field_modifiers = 201,          /* field_modifiers  */
  YYSYMBOL_field_var_modifier = 202        /* field_var_modifier  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3890

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  339
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  696

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   379


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
     136,   137,   131,   126,   141,   127,   135,   130,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   140,     2,
     118,   114,   119,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   115,
     116,   117,   120,   121,   122,   123,   124,   128,   132,   133
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   174,   174,   175,   178,   179,   182,   183,   186,   187,
     190,   191,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   277,   278,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   354,   355,   358,   359,   362,   363,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   403,   404,   407,   410,   413,
     414,   417,   418,   419,   420,   421,   422,   425,   426,   427,
     430,   431,   434,   435,   436,   437,   440,   441,   444,   447,
     448,   449,   452,   453,   456,   457,   458,   459,   462,   463,
     466,   467,   470,   471,   474,   475,   478,   479,   482,   483,
     486,   487,   490,   491,   494,   495,   496,   497,   500,   501,
     502,   505,   508,   509,   510,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   531,   532,   535,   536,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   553,   554,   555,
     556,   557,   558,   561,   562,   563,   566,   567,   570,   571,
     575,   576,   579,   580,   583,   584,   587,   591,   592,   593,
     594,   597,   598,   602,   605,   606,   609,   610,   613,   614,
     615,   616,   617,   620,   623,   627,   628,   631,   632,   633
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
  "end of file", "error", "invalid token", "INT", "STRING", "FLOAT",
  "BOOL", "DATETIME", "CHAR", "ID", "NOTHING", "ENDL", "ME_KW",
  "MYBASE_KW", "MYCLASS_KW", "IF_KW", "NEW_KW", "BYTE_KW", "SBYTE_KW",
  "USHORT_KW", "SHORT_KW", "UINTEGER_KW", "INTEGER_KW", "ULONG_KW",
  "LONG_KW", "BOOLEAN_KW", "DATE_KW", "CHAR_KW", "STRING_KW", "DECIMAL_KW",
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
  "EXP_ASSIGN", "STRCAT_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN",
  "BARE_NEW", "XOR", "OR", "OR_ELSE", "AND", "AND_ALSO", "NOT", "'='",
  "NEQ", "LEQ", "GEQ", "'<'", "'>'", "IS", "ISNOT", "LIKE", "LSHIFT",
  "RSHIFT", "'&'", "'+'", "'-'", "MOD", "'\\\\'", "'/'", "'*'", "UMINUS",
  "UPLUS", "'^'", "'.'", "'('", "')'", "'{'", "'}'", "':'", "','",
  "$accept", "program", "program_member", "endl_list", "stmt_endl",
  "opt_endl", "kw", "type_name", "expr", "cast_target",
  "collection_initializer", "member_access_member", "expr_list", "stmt",
  "label_name", "label_stmt", "redim_clause", "redim_clause_list",
  "if_stmt", "else_if_stmts", "select_stmt", "case_condition_branch",
  "case_condition_branches", "case_else_stmt", "case_stmts", "while_stmt",
  "for_stmt", "for_loop_variable", "foreach_stmt", "do_while_stmt",
  "do_until_stmt", "opt_block", "block", "variable_name", "array_modifier",
  "var_declarator", "var_declaration", "array_type_name",
  "simple_type_name", "primitive_type", "type_list", "id_list",
  "function_signature", "sub_signature", "constructor_signature",
  "constructor_declaration", "function_declaration", "sub_declaration",
  "opt_procedure_modifiers", "function_parameters", "function_parameter",
  "class_declaration", "struct_declaration", "generic_param_list",
  "opt_structure_body", "structure_body", "structure_member",
  "const_declaration", "field_declaration", "field_modifiers",
  "field_var_modifier", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-528)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-326)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    44,    56,    42,  -528,  -528,  -528,     9,    90,  -528,
    -528,   -79,     0,  -528,    47,    39,    11,    11,    96,  -528,
    -528,   110,    41,  -528,  -528,  -528,  -528,    64,    85,    13,
    -528,  -528,  -528,    34,  -528,   113,    47,    59,    47,    70,
    -528,    88,    22,    -4,   139,   152,    58,   139,   139,   139,
      91,  -528,  -528,   139,  -528,   139,   140,   165,   142,   169,
     171,    27,  -528,   861,  3293,  -528,   170,    35,    36,    49,
    1125,  1221,  1317,  -528,   170,    47,   111,   139,   115,   139,
    -528,    -5,    79,  -528,    54,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,    69,  -528,    22,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,    86,    92,    89,   861,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,    94,  3293,  3293,  3293,    96,    96,
    3726,    99,  -528,   861,    96,   -25,    96,   105,    96,   102,
     112,  3383,   179,   139,   739,    46,  3293,    38,  3293,    61,
      52,    53,   139,  2751,   110,   110,   110,  3293,   139,  3629,
    -528,   117,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    1797,  -528,   139,  1893,   139,  1989,   154,  -528,    47,  -528,
      47,    96,   114,  -528,    96,  3293,  -528,  3634,  3634,    96,
     130,    96,  2776,   -59,   -59,  3293,   722,    96,    96,    96,
      96,    96,  2841,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,  3634,    96,    96,  -528,    -7,   861,    96,     8,    96,
      17,    96,  3443,   131,  -528,     3,   170,  3293,  3052,   178,
     263,   159,  3052,  3293,  3293,  2085,  3052,  -528,  -528,   139,
     139,   139,   139,   139,   139,   139,   139,   170,   170,  3052,
     139,   139,   139,  3726,    12,   170,  3293,  3293,  3293,  3293,
    3293,  3293,  3293,  3293,  3293,  2841,  -528,   139,  -528,   170,
     139,   170,   139,   204,   251,   252,   279,  -528,   229,  3726,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  3293,    96,  3293,  3414,  -528,
      18,  3293,  3293,  3293,  3293,  3293,  3293,   305,  3293,  3293,
    3293,  3293,  3293,  3293,  3293,  3293,  3293,  3293,  3293,  3293,
    3293,  3293,  3293,  3293,  3293,  3293,  -528,  2931,  3293,   240,
     241,    19,  -528,  -528,    26,  -528,    19,    32,  -528,    19,
    3293,   139,    96,    96,   170,  3052,    51,   861,    96,    96,
     941,  3052,  3052,   245,  2661,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,    96,   170,
    3052,  3052,  3052,  3052,  3052,  3052,  3052,  3052,  3052,   341,
     170,   170,   170,  -528,   222,   246,  -528,   861,  3658,  3021,
    3692,   182,   187,  3754,  2689,  2689,  2776,  2776,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   134,   134,   352,
     394,   394,   148,   103,   -59,   -59,    -8,  -528,    18,  3414,
     861,   861,   110,   188,   283,    19,   216,  -528,    19,   221,
     186,  2085,  3293,   179,    51,  3113,  -528,   318,  -528,   265,
    -528,   315,  3293,   139,  2181,  2085,  2085,    43,  3293,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,  -528,
    -528,  -528,    29,    96,   224,    18,    96,  -528,  -528,   226,
     228,  -528,   253,  -528,   316,   861,   231,  -528,   232,  -528,
      14,  2661,    18,  -528,   280,   139,   574,  -528,  -528,   139,
    2751,  3506,   170,   139,   329,   330,  3293,  3293,   170,  3726,
      96,   243,  3293,  -528,   244,   861,  -528,  -528,  3293,   861,
    -528,   328,  -528,   139,  3293,   139,    23,   250,   139,  2085,
    3293,  2085,   170,  3203,  3052,  3293,   170,   139,   139,  3052,
    3052,   861,  -528,   220,   224,    96,  3726,  -528,   861,  1413,
    3472,   170,   139,   139,  -528,   170,  -528,  3052,  2661,  3052,
    2085,   274,   170,   170,   170,   170,  -528,    96,   275,  -528,
     276,  -528,   139,  2277,   139,  1509,   170,  2085,  2085,   372,
    3293,  1605,  3293,  -528,  -528,   170,   139,  2085,   139,  2373,
    2661,   376,   139,  3052,   139,  2469,  3414,   170,  2661,   170,
     139,   139,   170,  1701,   170,   139,   284,   170,   170,   139,
    2565,   170,  -528,   170,   139,   170
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     2,     5,     4,     0,     0,     1,
       3,     0,     6,     9,   313,     0,     0,     0,    11,     7,
     337,     0,   339,   338,   332,   328,   329,     0,     0,   313,
     326,   331,   330,     0,   335,     0,   313,     0,   313,     0,
      10,     0,   250,   254,     0,     0,     0,     0,     0,     0,
       0,   327,   339,     0,   336,     0,     0,     0,     0,     0,
       0,     0,   251,     0,     0,     6,   333,   290,   299,   305,
       0,     0,     0,   318,   334,   313,     0,     0,     0,     0,
     283,    11,     0,   253,   262,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   255,    94,    93,   264,    95,    96,    98,    99,   100,
     101,    97,   102,   103,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,     0,     0,    11,    11,
     256,     0,   147,     0,    11,   296,    11,   302,    11,    95,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,     0,   175,   173,   174,   181,   176,   177,   179,   180,
       0,   182,     0,     0,     0,     0,     0,   320,   313,   322,
     313,    11,     0,   252,    11,     0,   261,     0,     0,    11,
     142,    11,   129,   127,   128,     0,     0,    11,    11,    11,
      11,    11,     0,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      11,     0,    11,    11,   289,     0,     0,    11,     0,    11,
       0,    11,     0,     0,   209,     0,   203,     0,     0,   238,
       0,     0,     0,     0,     0,   246,     0,   206,   205,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   193,     0,
       0,     0,     0,   168,     0,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,   249,   311,
       0,   307,     0,     0,     0,     0,     0,   323,     0,   257,
     166,    12,    14,    15,    13,    16,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    59,    57,    58,    60,
      61,    62,    63,    64,    65,    66,    68,    69,    67,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   167,   140,   141,     0,    11,     0,    11,   165,
      11,     0,     0,     0,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,     0,     0,   288,
       0,    11,   314,   295,     0,   298,    11,     0,   304,    11,
       0,     0,    11,    11,   171,     0,     0,     0,    11,    11,
       0,     0,     0,     0,   247,   170,   204,   196,   197,   195,
     201,   199,   200,   198,   194,   258,   259,   260,    11,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     308,   310,   306,   317,     0,     0,   284,     0,     0,     0,
       0,     0,     0,   123,   122,   121,   119,   120,   114,   116,
     117,   118,   113,   112,   130,   131,   132,   125,   126,   111,
     105,   106,   124,   109,   108,   107,   110,   134,    11,    11,
       0,     0,     0,     0,   294,    11,     0,   301,    11,     0,
      11,   217,     0,     0,     0,     0,   226,   229,   230,     0,
     239,     0,     0,     0,     0,   246,   246,     0,     0,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   183,   319,
     321,   281,    11,    11,   143,    11,    11,   104,   164,     0,
       0,   287,     0,   315,   286,     0,     0,   297,     0,   303,
       0,   217,    11,   210,     0,     0,     0,   227,   231,     0,
       0,     0,   233,     0,     0,     0,     0,     0,   178,   169,
      11,     0,     0,   145,     0,     0,   133,   135,     0,     0,
     293,   292,   300,     0,     0,     0,     0,     0,     0,   246,
       0,   223,   220,     0,     0,     0,   232,     0,     0,     0,
       0,     0,   263,    11,   144,    11,   316,   285,     0,     0,
       0,   216,     0,     0,   208,   221,   228,     0,   222,     0,
     246,     0,   243,   245,   242,   244,   282,    11,     0,   146,
       0,   291,     0,     0,     0,     0,   215,   225,   246,     0,
       0,     0,     0,   138,   136,   214,     0,   219,     0,     0,
     224,     0,     0,     0,     0,     0,    11,   212,   218,   213,
       0,     0,   241,     0,   235,     0,     0,   211,   240,     0,
       0,   234,   137,   237,     0,   236
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -528,  -528,   419,   -16,   118,   -15,  -528,  -138,   512,  -528,
    -527,  -151,  -198,  -164,   278,  -528,   -85,  -528,  -528,  -129,
    -528,   -73,  -528,   -72,   -68,  -528,  -528,   208,  -528,  -528,
    -528,  -467,   -61,    -9,   356,   -26,  -528,  -528,  -113,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -204,
     -50,  -528,  -528,    48,   -23,  -528,   434,  -528,  -528,  -528,
     440
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    14,    15,   481,   382,   101,   169,   141,
     142,   383,   274,   170,   171,   172,   244,   245,   173,   570,
     174,   526,   527,   528,   529,   175,   176,   251,   177,   178,
     179,   443,   444,   420,    62,    44,   181,   102,   103,   104,
     552,    81,    47,    48,    49,    24,    25,    26,    27,   421,
     422,     5,     6,    16,    28,    29,    30,    31,    32,    33,
      34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    38,    42,    41,   200,   234,    40,    53,   390,   180,
     183,   185,    43,    56,    65,    58,   288,    42,    11,   288,
      12,   288,    12,    65,    43,   236,    42,   593,    66,    40,
      40,    70,    71,    72,   426,    42,   429,    74,    82,    75,
      40,    42,     9,    42,    11,    11,    63,   384,  -325,    65,
     603,   604,   186,     7,    65,   249,    17,    18,    19,   632,
     604,   188,    19,   190,   257,     8,   192,    68,   584,   585,
     258,    20,    21,    -8,    69,   230,   231,   232,     1,     2,
     416,   253,  -324,    22,   254,   143,   586,    23,   250,   587,
     525,   263,    20,   260,   264,   261,   265,   649,   423,    11,
     262,   266,  -312,  -312,    52,    20,    21,    40,    23,   605,
      64,   237,    35,     1,     2,   145,   147,    22,   633,    42,
      50,    23,    55,   205,   206,    45,    46,   231,   232,   235,
     419,   238,    57,   240,    37,    39,   191,   246,   270,   271,
     272,   255,   636,    59,   433,   425,   267,   268,    60,    13,
      65,    13,   275,   458,   428,    43,    43,    43,    61,   458,
     512,    67,    73,   514,    83,   294,   289,   295,   291,   517,
     590,   144,   146,   659,    77,    76,   296,    78,    79,   298,
      80,    19,   187,   195,   385,   148,   387,   189,   243,   293,
     194,   671,   391,   392,   393,   394,   395,    40,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   193,   417,   418,   508,
     515,   197,   424,   518,   427,   199,   430,   198,   437,   434,
     201,    40,   436,   228,   229,   233,   440,   230,   231,   232,
     445,   239,  -206,   446,   447,   448,   449,   450,   451,   452,
     453,   297,  -205,   454,   455,   456,   457,   286,   459,   223,
     224,   225,   226,   227,   228,   229,   386,   432,   230,   231,
     232,   470,   249,   439,   471,   473,   472,   227,   228,   229,
     288,   555,   230,   231,   232,    65,   474,   475,   476,   477,
     510,   511,   537,   549,   207,   208,   209,   210,   211,   530,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   550,   557,
     230,   231,   232,   660,   572,   564,   558,   553,   207,   208,
     209,   210,   211,   565,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    65,   567,   230,   231,   232,   525,   569,   579,
     580,   647,   139,   596,   551,   597,   599,   598,   601,   602,
     288,   479,   561,   562,   608,   482,   617,   618,   628,   534,
     622,   624,   207,   208,   209,   210,   211,   634,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   513,   288,   230,   231,
     232,   516,   663,   664,   519,   521,   672,   522,   523,   524,
     681,   692,    10,   531,   532,   535,   536,   600,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   259,   573,   230,
     231,   232,   606,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   577,   578,   574,   625,   438,   196,
     571,   627,   563,    51,   221,   222,   223,   224,   225,   226,
     227,   228,   229,    54,   288,   230,   231,   232,   224,   225,
     226,   227,   228,   229,     0,     0,   230,   231,   232,   288,
     651,     0,     0,   559,   560,     0,     0,     0,     0,     0,
     566,     0,     0,   568,     0,   288,   288,     0,   646,     0,
       0,   288,     0,     0,   288,     0,     0,   582,     0,     0,
       0,   588,   226,   227,   228,   229,   288,     0,   230,   231,
     232,     0,     0,     0,     0,     0,     0,   591,   592,     0,
     594,   595,     0,     0,     0,     0,     0,     0,     0,     0,
     638,     0,     0,     0,     0,     0,     0,   607,     0,   609,
     611,     0,     0,   612,   613,     0,     0,   616,   653,     0,
       0,     0,     0,     0,     0,   621,   140,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,   629,     0,   631,
       0,     0,   635,     0,   669,     0,   670,     0,   640,     0,
     675,   642,   643,   644,   645,     0,   678,     0,   648,     0,
     650,     0,     0,     0,   610,     0,   655,   656,     0,     0,
       0,   657,   690,   658,     0,   661,     0,     0,     0,     0,
       0,     0,   662,     0,     0,     0,   665,     0,   667,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,   204,
     677,     0,   679,     0,     0,     0,   682,   683,   684,     0,
       0,   686,     0,   242,   687,   688,   248,     0,   252,   691,
     256,     0,     0,   693,     0,   269,     0,     0,   695,   273,
       0,     0,   207,   208,   209,   210,   211,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   299,   230,   231,
     232,     0,     0,     0,     0,     0,     0,   388,   273,     0,
       0,     0,     0,     0,   397,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   435,
       0,     0,     0,     0,     0,   441,   442,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
       0,     0,   135,     0,     0,     0,     0,     0,   138,     0,
     139,   389,     0,     0,     0,   136,   137,     0,     0,     0,
      84,     0,     0,     0,     0,   138,     0,   139,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,     0,     0,   478,     0,   480,
       0,     0,     0,   483,   484,   485,   486,   487,   488,     0,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,     0,   273,
     509,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   520,     0,   149,   106,   107,   108,   109,   110,
     150,   112,    19,   113,   114,   115,   151,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,   153,     0,     0,   154,
       0,     0,   155,     0,   156,     0,     0,     0,     0,   157,
       0,   273,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   273,     0,     0,   576,   533,     0,
       0,     0,     0,     0,   581,     0,     0,     0,     0,     0,
     589,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,     0,     0,     0,     0,     0,   619,   620,
       0,     0,     0,     0,   623,     0,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,   637,     0,     0,   639,     0,   641,   149,   106,
     107,   108,   109,   110,   150,   112,    19,   113,   114,   115,
     151,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
     153,     0,     0,   154,     0,     0,   155,     0,   156,     0,
       0,     0,   673,   157,   676,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   168,     0,
       0,     0,     0,     0,   149,   106,   107,   108,   109,   110,
     150,   112,    19,   113,   114,   115,   151,   117,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,     0,   152,     0,   153,     0,     0,   154,
       0,   138,   155,   139,   156,     0,     0,     0,     0,   157,
       0,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,     0,     0,     0,   182,     0,     0,
     149,   106,   107,   108,   109,   110,   150,   112,    19,   113,
     114,   115,   151,   117,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
     152,     0,   153,     0,     0,   154,     0,   138,   155,   139,
     156,     0,     0,     0,     0,   157,     0,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       0,     0,     0,   184,     0,     0,   149,   106,   107,   108,
     109,   110,   150,   112,    19,   113,   114,   115,   151,   117,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,   137,     0,   152,     0,   153,     0,
       0,   154,     0,   138,   155,   139,   156,     0,     0,     0,
       0,   157,     0,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,   652,     0,
       0,     0,   149,   106,   107,   108,   109,   110,   150,   112,
      19,   113,   114,   115,   151,   117,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,     0,   152,     0,   153,     0,     0,   154,     0,   138,
     155,   139,   156,     0,     0,     0,     0,   157,     0,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,     0,     0,   668,     0,     0,     0,   149,   106,
     107,   108,   109,   110,   150,   112,    19,   113,   114,   115,
     151,   117,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   137,     0,   152,     0,
     153,     0,     0,   154,     0,   138,   155,   139,   156,   674,
       0,     0,     0,   157,     0,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,   149,   106,   107,   108,   109,   110,
     150,   112,    19,   113,   114,   115,   151,   117,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,     0,   152,     0,   153,     0,     0,   154,
       0,   138,   155,   139,   156,   689,     0,     0,     0,   157,
       0,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,     0,     0,     0,     0,     0,     0,
     149,   106,   107,   108,   109,   110,   150,   112,     0,   113,
     114,   115,   151,   117,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
     152,     0,   153,     0,     0,   154,     0,   138,   155,   139,
     156,     0,     0,     0,     0,   157,     0,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     287,     0,     0,     0,     0,     0,   149,   106,   107,   108,
     109,   110,   150,   112,     0,   113,   114,   115,   151,   117,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,   137,     0,   152,     0,   153,     0,
       0,   154,     0,   138,   155,   139,   156,     0,     0,     0,
       0,   157,     0,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,   290,
       0,     0,   149,   106,   107,   108,   109,   110,   150,   112,
       0,   113,   114,   115,   151,   117,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,     0,   152,     0,   153,     0,     0,   154,     0,   138,
     155,   139,   156,     0,     0,     0,     0,   157,     0,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,     0,     0,     0,   292,     0,     0,   149,   106,
     107,   108,   109,   110,   150,   112,    19,   113,   114,   115,
     151,   117,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   137,     0,   152,     0,
     153,     0,     0,   154,     0,   138,   155,   139,   156,     0,
       0,     0,     0,   157,     0,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,   149,   106,   107,   108,   109,   110,
     150,   112,     0,   113,   114,   115,   151,   117,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,     0,   152,     0,   153,     0,     0,   154,
       0,   138,   155,   139,   156,     0,     0,     0,     0,   157,
       0,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,     0,     0,     0,     0,   583,     0,
     149,   106,   107,   108,   109,   110,   150,   112,     0,   113,
     114,   115,   151,   117,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
     152,     0,   153,     0,     0,   154,     0,   138,   155,   139,
     156,     0,     0,     0,     0,   157,     0,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       0,     0,   666,     0,     0,     0,   149,   106,   107,   108,
     109,   110,   150,   112,     0,   113,   114,   115,   151,   117,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,   137,     0,   152,     0,   153,     0,
       0,   154,     0,   138,   155,   139,   156,     0,     0,     0,
       0,   157,     0,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,   680,     0,
       0,     0,   149,   106,   107,   108,   109,   110,   150,   112,
       0,   113,   114,   115,   151,   117,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,     0,   152,     0,   153,     0,     0,   154,     0,   138,
     155,   139,   156,   685,     0,     0,     0,   157,     0,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,     0,     0,     0,     0,     0,     0,   149,   106,
     107,   108,   109,   110,   150,   112,     0,   113,   114,   115,
     151,   117,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   137,     0,   152,     0,
     153,     0,     0,   154,     0,   138,   155,   139,   156,   694,
       0,     0,     0,   157,     0,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,   149,   106,   107,   108,   109,   110,
     150,   112,     0,   113,   114,   115,   151,   117,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,     0,   152,     0,   153,     0,     0,   154,
       0,   138,   155,   139,   156,     0,     0,     0,     0,   157,
       0,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   105,   106,   107,   108,   109,   110,
     111,   112,    65,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,   139,
     210,   211,     0,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,     0,     0,   230,   231,   232,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   105,   106,   107,   108,   109,   110,
     111,   112,   396,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,   139,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,     0,
     230,   231,   232,     0,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
       0,     0,     0,    65,     0,     0,     0,   138,   507,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   575,
       0,     0,     0,     0,     0,     0,     0,   138,   554,   139,
     207,   208,   209,   210,   211,     0,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,     0,     0,   230,   231,   232,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   105,   106,   107,   108,
     109,   110,   111,   112,    19,   113,   114,   115,   116,   117,
       0,     0,     0,     0,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,     0,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,     0,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,     0,     0,     0,     0,    40,     0,     0,     0,   138,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     0,   431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   654,     0,     0,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,   241,
       0,   139,   207,   208,   209,   210,   211,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   615,     0,   230,   231,
     232,   207,   208,   209,   210,   211,     0,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,     0,     0,   230,   231,   232,
     207,   208,   209,   210,   211,     0,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,     0,     0,   230,   231,   232,     0,
       0,     0,     0,     0,   207,   208,   209,   210,   211,     0,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,     0,
     230,   231,   232,   300,     0,     0,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     0,   207,   208,   209,
     210,   211,     0,   285,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,     0,     0,   230,   231,   232,   207,   208,   209,   210,
     211,     0,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,     0,   230,   231,   232,     0,     0,     0,     0,   553,
     207,   208,   209,   210,   211,     0,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,     0,     0,   230,   231,   232,     0,
       0,     0,     0,   556,   207,   208,   209,   210,   211,     0,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,     0,
     230,   231,   232,   208,   209,   210,   211,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,     0,   230,   231,
     232
};

static const yytype_int16 yycheck[] =
{
      16,    17,     9,    18,   117,   143,    11,    33,   206,    70,
      71,    72,    21,    36,    11,    38,   180,     9,     9,   183,
      11,   185,    11,    11,    33,    50,     9,   554,    44,    11,
      11,    47,    48,    49,   238,     9,   240,    53,    11,    55,
      11,     9,     0,     9,     9,     9,    50,   198,    35,    11,
      36,    37,    75,     9,    11,     9,     8,   136,    11,    36,
      37,    77,    11,    79,     3,     9,    81,     9,   535,   536,
       9,    58,    59,    73,    16,   134,   135,   136,    71,    72,
     231,    43,    35,    70,    46,    50,    43,    74,    42,    46,
      39,    38,    58,    41,    41,    43,    43,   624,   236,     9,
      48,    48,    61,    62,    70,    58,    59,    11,    74,    95,
     114,   136,    73,    71,    72,    67,    68,    70,    95,     9,
      35,    74,     9,   138,   139,    61,    62,   135,   136,   144,
     137,   146,    73,   148,    16,    17,   141,   153,   164,   165,
     166,   157,   609,    73,   141,   137,   162,   163,    60,   140,
      11,   140,   168,   141,   137,   164,   165,   166,   136,   141,
     141,     9,    71,   137,   137,   188,   182,   190,   184,   137,
     141,   136,   136,   640,     9,    35,   191,    35,     9,   194,
       9,    11,    71,   114,   199,   136,   201,    72,     9,    35,
     136,   658,   207,   208,   209,   210,   211,    11,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   137,   232,   233,   417,
     424,   135,   237,   427,   239,   136,   241,   135,    50,   245,
     136,    11,   248,   130,   131,   136,   252,   134,   135,   136,
     256,   136,   140,   259,   260,   261,   262,   263,   264,   265,
     266,   137,   140,   269,   270,   271,   272,   140,   274,   125,
     126,   127,   128,   129,   130,   131,   136,   136,   134,   135,
     136,   287,     9,   114,   290,    71,   292,   129,   130,   131,
     444,   479,   134,   135,   136,    11,    35,    35,     9,    60,
      50,    50,    47,    71,   108,   109,   110,   111,   112,   437,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    72,   137,
     134,   135,   136,    49,   522,   137,   139,   141,   108,   109,
     110,   111,   112,    50,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    11,   137,   134,   135,   136,    39,   137,    94,
      45,   141,   138,   137,   477,   137,    50,   114,   137,   137,
     534,   386,   510,   511,    94,   390,    47,    47,    50,   440,
     137,   137,   108,   109,   110,   111,   112,   137,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   421,   571,   134,   135,
     136,   426,   137,   137,   429,   431,    44,   432,   433,   435,
      44,   137,     3,   438,   439,   441,   442,   565,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   159,   523,   134,
     135,   136,   571,   458,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   527,   527,   524,   595,   250,   103,
     521,   599,   512,    29,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    33,   638,   134,   135,   136,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,   653,
     628,    -1,    -1,   508,   509,    -1,    -1,    -1,    -1,    -1,
     515,    -1,    -1,   518,    -1,   669,   670,    -1,   621,    -1,
      -1,   675,    -1,    -1,   678,    -1,    -1,   533,    -1,    -1,
      -1,   537,   128,   129,   130,   131,   690,    -1,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   552,   553,    -1,
     555,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     611,    -1,    -1,    -1,    -1,    -1,    -1,   572,    -1,   575,
     576,    -1,    -1,   579,   580,    -1,    -1,   583,   629,    -1,
      -1,    -1,    -1,    -1,    -1,   590,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    -1,   603,    -1,   605,
      -1,    -1,   608,    -1,   655,    -1,   657,    -1,   614,    -1,
     661,   617,   618,   619,   620,    -1,   667,    -1,   623,    -1,
     625,    -1,    -1,    -1,    40,    -1,   632,   633,    -1,    -1,
      -1,   637,   683,   639,    -1,   641,    -1,    -1,    -1,    -1,
      -1,    -1,   647,    -1,    -1,    -1,   652,    -1,   654,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     666,    -1,   668,    -1,    -1,    -1,   672,   673,   674,    -1,
      -1,   676,    -1,   151,   680,   681,   154,    -1,   156,   685,
     158,    -1,    -1,   689,    -1,   163,    -1,    -1,   694,   167,
      -1,    -1,   108,   109,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   195,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,    -1,
      -1,    -1,    -1,    -1,   212,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,   136,    -1,   138,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,   385,    -1,   387,
      -1,    -1,    -1,   391,   392,   393,   394,   395,   396,    -1,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,    -1,   417,
     418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   430,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,   479,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   522,    -1,    -1,   525,    97,    -1,
      -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,
     538,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   580,    -1,    -1,    -1,    -1,    -1,   586,   587,
      -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,
     598,    -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,
      -1,    -1,   610,    -1,    -1,   613,    -1,   615,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    41,    -1,    43,    -1,
      -1,    -1,   660,    48,   662,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    33,    -1,    35,    -1,    -1,    38,
      -1,   136,    41,   138,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    96,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      33,    -1,    35,    -1,    -1,    38,    -1,   136,    41,   138,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    -1,    96,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    33,    -1,    35,    -1,
      -1,    38,    -1,   136,    41,   138,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    95,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,   136,
      41,   138,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    33,    -1,
      35,    -1,    -1,    38,    -1,   136,    41,   138,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    33,    -1,    35,    -1,    -1,    38,
      -1,   136,    41,   138,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      33,    -1,    35,    -1,    -1,    38,    -1,   136,    41,   138,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    33,    -1,    35,    -1,
      -1,    38,    -1,   136,    41,   138,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    -1,    96,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,   136,
      41,   138,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    96,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    33,    -1,
      35,    -1,    -1,    38,    -1,   136,    41,   138,    43,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    33,    -1,    35,    -1,    -1,    38,
      -1,   136,    41,   138,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    -1,    97,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      33,    -1,    35,    -1,    -1,    38,    -1,   136,    41,   138,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    33,    -1,    35,    -1,
      -1,    38,    -1,   136,    41,   138,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    95,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,   136,
      41,   138,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    33,    -1,
      35,    -1,    -1,    38,    -1,   136,    41,   138,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    33,    -1,    35,    -1,    -1,    38,
      -1,   136,    41,   138,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,   134,   135,   136,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,   136,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   108,   109,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    40,    -1,   134,   135,
     136,   108,   109,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,   134,   135,   136,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,     9,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,   108,   109,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,   134,   135,   136,   108,   109,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,   141,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,   141,   108,   109,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,   109,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    72,   143,   144,   193,   194,     9,     9,     0,
     144,     9,    11,   140,   145,   146,   195,   195,   136,    11,
      58,    59,    70,    74,   187,   188,   189,   190,   196,   197,
     198,   199,   200,   201,   202,    73,   145,   146,   145,   146,
      11,   147,     9,   175,   177,    61,    62,   184,   185,   186,
      35,   198,    70,   177,   202,     9,   196,    73,   196,    73,
      60,   136,   176,    50,   114,    11,   145,     9,     9,    16,
     145,   145,   145,    71,   145,   145,    35,     9,    35,     9,
       9,   183,    11,   137,     9,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   149,   179,   180,   181,     3,     4,     5,     6,     7,
       8,     9,    10,    12,    13,    14,    15,    16,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   113,   126,   127,   136,   138,
     150,   151,   152,    50,   136,   195,   136,   195,   136,     3,
       9,    15,    33,    35,    38,    41,    43,    48,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    75,    93,   150,
     155,   156,   157,   160,   162,   167,   168,   170,   171,   172,
     174,   178,    96,   174,    96,   174,   196,    71,   145,    72,
     145,   141,   147,   137,   136,   114,   176,   135,   135,   136,
     180,   136,   150,   150,   150,   147,   147,   108,   109,   110,
     111,   112,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     134,   135,   136,   136,   149,   147,    50,   136,   147,   136,
     147,   136,   150,     9,   158,   159,   145,    39,   150,     9,
      42,   169,   150,    43,    46,   145,   150,     3,     9,   156,
      41,    43,    48,    38,    41,    43,    48,   145,   145,   150,
     177,   177,   177,   150,   154,   145,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   114,   140,    93,   155,   145,
      96,   145,    96,    35,   196,   196,   147,   137,   147,   150,
       9,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   148,   153,   153,   147,   136,   147,   150,   139,
     154,   147,   147,   147,   147,   147,    11,   150,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   153,   147,   147,   137,
     175,   191,   192,   149,   147,   137,   191,   147,   137,   191,
     147,    34,   136,   141,   145,   150,   145,    50,   169,   114,
     145,   150,   150,   173,   174,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   141,   145,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     145,   145,   145,    71,    35,    35,     9,    60,   150,   147,
     150,   147,   147,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   137,   154,   150,
      50,    50,   141,   147,   137,   191,   147,   137,   191,   147,
     150,   145,   147,   147,   145,    39,   163,   164,   165,   166,
     149,   147,   147,    97,   174,   145,   145,    47,   147,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,    71,
      72,   180,   182,   141,   137,   154,   141,   137,   139,   147,
     147,   149,   149,   192,   137,    50,   147,   137,   147,   137,
     161,   174,   154,   158,   166,    36,   150,   163,   165,    94,
      45,   150,   145,    97,   173,   173,    43,    46,   145,   150,
     141,   147,   147,   152,   147,   147,   137,   137,   114,    50,
     149,   137,   137,    36,    37,    95,   161,   147,    94,   145,
      40,   145,   145,   145,   150,    40,   145,    47,    47,   150,
     150,   147,   137,   150,   137,   149,   150,   149,    50,   145,
     150,   145,    36,    95,   137,   145,   173,   150,   174,   150,
     145,   150,   145,   145,   145,   145,   180,   141,   147,   152,
     147,   149,    95,   174,    34,   145,   145,   145,   145,   173,
      49,   145,   147,   137,   137,   145,    95,   145,    95,   174,
     174,   173,    44,   150,    44,   174,   150,   145,   174,   145,
      95,    44,   145,   145,   145,    44,   147,   145,   145,    44,
     174,   145,   137,   145,    44,   145
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   142,   143,   143,   144,   144,   145,   145,   146,   146,
     147,   147,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   149,   149,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   156,   156,   157,   158,   159,
     159,   160,   160,   160,   160,   160,   160,   161,   161,   161,
     162,   162,   163,   163,   163,   163,   164,   164,   165,   166,
     166,   166,   167,   167,   168,   168,   168,   168,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   176,   177,   177,   177,   177,   178,   178,
     178,   179,   180,   180,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   182,   182,   183,   183,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   185,   185,   185,
     185,   185,   185,   186,   186,   186,   187,   187,   188,   188,
     189,   189,   190,   190,   191,   191,   192,   193,   193,   193,
     193,   194,   194,   195,   196,   196,   197,   197,   198,   198,
     198,   198,   198,   199,   200,   201,   201,   202,   202,   202
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     2,     2,
       4,     4,     4,     6,     4,     6,     9,    12,     9,     3,
       3,     3,     2,     5,     7,     6,     8,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     1,     1,     1,     4,
       3,     3,     3,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     2,     6,     1,
       4,    11,    10,    10,     9,     8,     7,     0,     6,     5,
       6,     7,     4,     3,     6,     5,     1,     2,     4,     1,
       1,     2,     6,     5,    11,    10,    13,    12,     1,     3,
      11,    10,     7,     7,     7,     7,     0,     1,     1,     2,
       1,     2,     3,     2,     1,     3,     3,     5,     3,     3,
       3,     2,     1,     7,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     4,     9,     7,     7,     5,     4,
       2,    10,     8,     8,     6,     5,     3,     7,     5,     2,
       8,     6,     3,     7,     5,     2,     6,     5,     6,     5,
       6,     5,     1,     0,     1,     3,     5,     9,     6,    10,
       7,    10,     7,     7,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     3,     1,     2,     1,     1,     1
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
  case 95: /* expr: INT  */
#line 281 "grammar.y"
          {debug_print("INT -> expr"); (yyval.Expr) = create_int((yyvsp[0].Int));}
#line 2748 "grammar.tab.cpp"
    break;

  case 105: /* expr: expr '+' opt_endl expr  */
#line 291 "grammar.y"
                             {debug_print("expr + opt_endl expr -> expr"); (yyval.Expr) = create_binary((yyvsp[-3].Expr), (yyvsp[0].Expr), AddOp);}
#line 2754 "grammar.tab.cpp"
    break;


#line 2758 "grammar.tab.cpp"

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

#line 636 "grammar.y"


int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = stdin;
        yyparse();
    }
    else {
        printf("File not found");
    }
}
