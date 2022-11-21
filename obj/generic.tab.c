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
#line 1 "src/generic.y"

#include <string>
#include <stdexcept>
#include <stdio.h>
#include "../src/type.hpp"
#include "../src/node.hpp"
#include "../src/scope.hpp"
    std::vector<NStatement*> rootStmts; // Main program blocks
    std::vector<NFunctionDeclStatement*> rootFuncStmts;
    std::vector<NAssignment*> rootAssignStmts;
    void yyerror(char const *);
    extern int yylex(void);
    FunctionScope *beginFunctionScope;
    FunctionStack *lastFuncStack;

#line 87 "obj/generic.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EOL = 258,                     /* EOL  */
    FOR = 259,                     /* FOR  */
    IN = 260,                      /* IN  */
    WHILE = 261,                   /* WHILE  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    ELIF = 264,                    /* ELIF  */
    RETURN = 265,                  /* RETURN  */
    PASS = 266,                    /* PASS  */
    CONTINUE = 267,                /* CONTINUE  */
    BREAK = 268,                   /* BREAK  */
    STRING = 269,                  /* STRING  */
    INTEGER = 270,                 /* INTEGER  */
    ID = 271,                      /* ID  */
    LT = 272,                      /* LT  */
    NOT = 273,                     /* NOT  */
    LTE = 274,                     /* LTE  */
    GT = 275,                      /* GT  */
    GTE = 276,                     /* GTE  */
    EQ = 277,                      /* EQ  */
    NEQ = 278,                     /* NEQ  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    SL = 281,                      /* SL  */
    SR = 282,                      /* SR  */
    BA = 283,                      /* BA  */
    BO = 284,                      /* BO  */
    BN = 285,                      /* BN  */
    BX = 286,                      /* BX  */
    DEF = 287,                     /* DEF  */
    RTYPE = 288                    /* RTYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "src/generic.y"

  NBlock *block_p;
  NStatement *stmt;
  NFunctionDeclStatement *funcDeclStmt;
  NForStatement *for_stmt;
  NElifStatement *elif_stmt;
  NElseStatement *else_stmt;
  NAssignment *assign;
  NExpression *expr;
  NInteger *int_val;
  NString *str_val;
  NIdentifier *id_val;
  NArgs *args;
  NExpressionArgs *exprags;
  Type *type;
  std::string *str;

#line 185 "obj/generic.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EOL = 3,                        /* EOL  */
  YYSYMBOL_4_ = 4,                         /* '='  */
  YYSYMBOL_5_ = 5,                         /* '+'  */
  YYSYMBOL_6_ = 6,                         /* '-'  */
  YYSYMBOL_7_ = 7,                         /* '/'  */
  YYSYMBOL_8_ = 8,                         /* '*'  */
  YYSYMBOL_9_ = 9,                         /* '%'  */
  YYSYMBOL_10_ = 10,                       /* ':'  */
  YYSYMBOL_11_ = 11,                       /* ','  */
  YYSYMBOL_12_ = 12,                       /* '{'  */
  YYSYMBOL_13_ = 13,                       /* '}'  */
  YYSYMBOL_14_ = 14,                       /* '['  */
  YYSYMBOL_15_ = 15,                       /* ']'  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_IN = 17,                        /* IN  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_ELIF = 21,                      /* ELIF  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_PASS = 23,                      /* PASS  */
  YYSYMBOL_CONTINUE = 24,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_STRING = 26,                    /* STRING  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_LTE = 31,                       /* LTE  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_GTE = 33,                       /* GTE  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NEQ = 35,                       /* NEQ  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_SL = 38,                        /* SL  */
  YYSYMBOL_SR = 39,                        /* SR  */
  YYSYMBOL_BA = 40,                        /* BA  */
  YYSYMBOL_BO = 41,                        /* BO  */
  YYSYMBOL_BN = 42,                        /* BN  */
  YYSYMBOL_BX = 43,                        /* BX  */
  YYSYMBOL_DEF = 44,                       /* DEF  */
  YYSYMBOL_RTYPE = 45,                     /* RTYPE  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_stmt = 50,                      /* stmt  */
  YYSYMBOL_block = 51,                     /* block  */
  YYSYMBOL_block_p_start = 52,             /* block_p_start  */
  YYSYMBOL_block_p = 53,                   /* block_p  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_list_expr = 55,                 /* list_expr  */
  YYSYMBOL_ret = 56,                       /* ret  */
  YYSYMBOL_assign = 57,                    /* assign  */
  YYSYMBOL_while = 58,                     /* while  */
  YYSYMBOL_for = 59,                       /* for  */
  YYSYMBOL_for_header = 60,                /* for_header  */
  YYSYMBOL_if = 61,                        /* if  */
  YYSYMBOL_elif = 62,                      /* elif  */
  YYSYMBOL_else = 63,                      /* else  */
  YYSYMBOL_def = 64,                       /* def  */
  YYSYMBOL_funcDef = 65,                   /* funcDef  */
  YYSYMBOL_args = 66,                      /* args  */
  YYSYMBOL_arg_list = 67,                  /* arg_list  */
  YYSYMBOL_rtype = 68,                     /* rtype  */
  YYSYMBOL_args2 = 69,                     /* args2  */
  YYSYMBOL_arg_list2 = 70,                 /* arg_list2  */
  YYSYMBOL_function_call = 71,             /* function_call  */
  YYSYMBOL_type = 72                       /* type  */
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
typedef yytype_uint8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   492

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     9,     2,     2,
      46,    47,     8,     5,    11,     6,     2,     7,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    10,     2,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    14,     2,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    12,     2,    13,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    77,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    92,   109,   118,   119,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   156,   160,   161,   163,
     166,   169,   170,   172,   173,   174,   177,   178,   179,   182,
     185,   193,   198,   199,   202,   203,   204,   205,   209,   212,
     217,   218,   220,   221,   224,   228
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EOL", "'='", "'+'",
  "'-'", "'/'", "'*'", "'%'", "':'", "','", "'{'", "'}'", "'['", "']'",
  "FOR", "IN", "WHILE", "IF", "ELSE", "ELIF", "RETURN", "PASS", "CONTINUE",
  "BREAK", "STRING", "INTEGER", "ID", "LT", "NOT", "LTE", "GT", "GTE",
  "EQ", "NEQ", "AND", "OR", "SL", "SR", "BA", "BO", "BN", "BX", "DEF",
  "RTYPE", "'('", "')'", "$accept", "program", "stmt", "block",
  "block_p_start", "block_p", "expr", "list_expr", "ret", "assign",
  "while", "for", "for_header", "if", "elif", "else", "def", "funcDef",
  "args", "arg_list", "rtype", "args2", "arg_list2", "function_call",
  "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -114,    74,  -114,   -21,   177,   177,     3,     8,    15,    17,
       1,    -7,  -114,  -114,    20,  -114,  -114,    16,  -114,  -114,
      29,    18,   177,   177,  -114,  -114,   -12,   177,   177,   177,
     203,  -114,  -114,   219,  -114,   141,  -114,  -114,  -114,   177,
     177,    -4,    16,  -114,    43,    35,  -114,   177,   422,   258,
      36,  -114,   414,   362,    98,   177,   177,   177,   177,   177,
      16,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,    16,  -114,   362,    10,    22,
    -114,  -114,  -114,   271,   177,  -114,  -114,   422,   422,     0,
       0,     0,    60,   310,   154,   154,   154,   154,   154,   154,
     375,   414,   362,   362,   362,   362,   362,    -5,  -114,     2,
      28,  -114,   448,  -114,  -114,  -114,  -114,  -114,    64,   177,
      65,    68,    49,    22,    37,   448,    70,    16,   323,  -114,
    -114,  -114,    73,  -114,    49,    75,  -114,    83,    78,    16,
      22,  -114,  -114,  -114,  -114,    59,  -114,  -114,    81,    82,
    -114,  -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     9,     0,     5,     6,     0,     7,     8,
       0,     0,     0,    70,    23,    21,    22,     0,     0,     0,
       0,    24,    18,     0,    48,     0,    11,    13,    12,     0,
      70,     0,     0,     4,     0,     0,    10,     0,    40,    72,
       0,    71,    38,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    49,     0,    62,
      60,    15,    51,     0,     0,    46,    20,    41,    42,    44,
      43,    45,     0,     0,    25,    26,    27,    28,    30,    29,
      31,    32,    33,    34,    35,    36,    37,     0,    74,    66,
       0,    63,     0,    52,    73,    50,    19,    53,     0,     0,
       0,     0,     0,     0,    68,    17,     0,     0,     0,    54,
      55,    75,    64,    67,     0,     0,    16,     0,     0,     0,
       0,    69,    61,    14,    59,     0,    65,    56,     0,     0,
      57,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,    86,   -38,  -114,   -37,    -3,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,   -45,   -36,  -114,  -114,  -114,  -113,
    -114,    77,    24,    -1,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,   125,    45,   112,   126,    49,    31,    13,    14,
      15,    16,    17,    18,   120,   121,    19,    42,   110,   111,
     135,    50,    51,    32,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    30,    33,    35,    80,    39,    34,    21,   117,    22,
     133,    36,   122,   123,    61,   118,   119,    23,    37,    48,
      38,    41,    92,    43,    52,    53,    54,   146,    44,    24,
      25,    26,    46,    27,    40,    47,    77,   107,    70,    71,
      72,    73,    79,    74,    83,    28,    81,    40,    82,    29,
     109,    85,    87,    88,    89,    90,    91,   108,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   147,   115,     2,   124,   127,   131,   129,   118,
     119,   130,   134,   137,   140,   142,   143,    12,   136,   138,
       3,   144,     4,     5,   150,   151,     6,     7,     8,     9,
     148,   145,    10,    55,    56,    57,    58,    59,   114,   149,
     141,    20,    61,     0,     0,     0,   128,    78,    11,     0,
       0,     0,     0,     0,    20,     0,     0,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,     0,     0,    76,    86,    55,    56,    57,    58,
      59,     0,     0,     0,     0,    61,     0,     0,     0,    55,
      56,    57,    58,    59,     0,     0,     0,     0,    61,     0,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    22,    74,     0,     0,     0,     0,     0,
       0,    23,    70,    71,    72,    73,     0,    74,     0,     0,
       0,     0,     0,    24,    25,    26,     0,    27,    55,    56,
      57,    58,    59,     0,     0,    60,     0,    61,     0,    28,
       0,     0,     0,    29,    55,    56,    57,    58,    59,     0,
       0,    75,    62,    61,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,     0,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    55,    56,    57,    58,    59,     0,    84,
       0,     0,    61,     0,     0,     0,    55,    56,    57,    58,
      59,     0,     0,   113,     0,    61,     0,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      62,    74,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    55,    56,    57,    58,    59,
       0,     0,     0,     0,    61,   116,     0,     0,    55,    56,
      57,    58,    59,     0,     0,   139,     0,    61,     0,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    62,    74,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    55,    56,    57,
      58,    59,     0,     0,     0,     0,    61,     0,     0,     0,
      55,    56,    57,    58,    59,     0,     0,     0,     0,    61,
       0,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    62,    74,    63,    64,    65,    66,
      67,     0,    69,    70,    71,    72,    73,     0,    74,    55,
      56,    57,    58,    59,     0,     0,     0,     0,    61,    57,
      58,    59,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,     0,    62,     0,    63,    64,    65,    66,    67,
       0,     0,    70,    71,    72,    73,     0,    74,     0,     0,
      70,    71,    72,    73,     3,    74,     4,     5,     0,     0,
       6,     7,     8,     9,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11
};

static const yytype_int16 yycheck[] =
{
       1,     4,     5,     6,    42,     4,     3,    28,    13,     6,
     123,     3,    10,    11,    14,    20,    21,    14,     3,    22,
       3,    28,    60,     3,    27,    28,    29,   140,    12,    26,
      27,    28,     3,    30,    46,    17,    39,    75,    38,    39,
      40,    41,    46,    43,    47,    42,     3,    46,    13,    46,
      28,    15,    55,    56,    57,    58,    59,    47,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    13,    13,     0,    47,    12,    28,    13,    20,
      21,    13,    45,    13,    11,    10,     3,     1,   125,   127,
      16,    13,    18,    19,    13,    13,    22,    23,    24,    25,
     145,   139,    28,     5,     6,     7,     8,     9,    84,   145,
     134,   112,    14,    -1,    -1,    -1,   119,    40,    44,    -1,
      -1,    -1,    -1,    -1,   125,    -1,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    -1,     3,    47,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     6,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    38,    39,    40,    41,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    14,    -1,    42,
      -1,    -1,    -1,    46,     5,     6,     7,     8,     9,    -1,
      -1,    12,    29,    14,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    -1,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    14,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      29,    43,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    14,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    29,    43,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    29,    43,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    41,    -1,    43,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,     7,
       8,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    31,    32,    33,    34,    35,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    -1,    -1,
      38,    39,    40,    41,    16,    43,    18,    19,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,     0,    16,    18,    19,    22,    23,    24,    25,
      28,    44,    50,    56,    57,    58,    59,    60,    61,    64,
      71,    28,     6,    14,    26,    27,    28,    30,    42,    46,
      54,    55,    71,    54,     3,    54,     3,     3,     3,     4,
      46,    28,    65,     3,    12,    51,     3,    17,    54,    54,
      69,    70,    54,    54,    54,     5,     6,     7,     8,     9,
      12,    14,    29,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    43,    12,     3,    54,    69,    46,
      51,     3,    13,    54,    11,    15,    47,    54,    54,    54,
      54,    54,    51,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    51,    47,    28,
      66,    67,    52,    12,    70,    13,    15,    13,    20,    21,
      62,    63,    10,    11,    47,    50,    53,    12,    54,    13,
      13,    28,    72,    67,    45,    68,    53,    13,    51,    12,
      11,    72,    10,     3,    13,    51,    67,    13,    62,    63,
      13,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    52,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    56,    56,    57,
      58,    59,    60,    61,    61,    61,    62,    62,    62,    63,
      64,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     6,     0,     2,     1,     1,     4,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       5,     3,     5,     5,     6,     6,     5,     6,     6,     4,
       3,     6,     0,     1,     3,     5,     1,     3,     0,     2,
       0,     1,     1,     3,     4,     1
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
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
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* program: program stmt  */
#line 77 "src/generic.y"
                  { (yyvsp[0].stmt)->addToRootStmts(); }
#line 1671 "obj/generic.tab.c"
    break;

  case 4: /* stmt: assign EOL  */
#line 80 "src/generic.y"
                 { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1677 "obj/generic.tab.c"
    break;

  case 5: /* stmt: while  */
#line 81 "src/generic.y"
            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1683 "obj/generic.tab.c"
    break;

  case 6: /* stmt: for  */
#line 82 "src/generic.y"
          { (yyval.stmt) = (yyvsp[0].for_stmt); }
#line 1689 "obj/generic.tab.c"
    break;

  case 7: /* stmt: if  */
#line 83 "src/generic.y"
         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1695 "obj/generic.tab.c"
    break;

  case 8: /* stmt: def  */
#line 84 "src/generic.y"
          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1701 "obj/generic.tab.c"
    break;

  case 9: /* stmt: ret  */
#line 85 "src/generic.y"
          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1707 "obj/generic.tab.c"
    break;

  case 10: /* stmt: function_call EOL  */
#line 86 "src/generic.y"
                        { (yyval.stmt) = new NExpressionStatement((yyvsp[-1].expr)); }
#line 1713 "obj/generic.tab.c"
    break;

  case 11: /* stmt: PASS EOL  */
#line 87 "src/generic.y"
               { (yyval.stmt) = new NPassStatement(); }
#line 1719 "obj/generic.tab.c"
    break;

  case 12: /* stmt: BREAK EOL  */
#line 88 "src/generic.y"
                { (yyval.stmt) = new NBreakStatement(); }
#line 1725 "obj/generic.tab.c"
    break;

  case 13: /* stmt: CONTINUE EOL  */
#line 89 "src/generic.y"
                   { (yyval.stmt) = new NContinueStatement(); }
#line 1731 "obj/generic.tab.c"
    break;

  case 14: /* block: '{' EOL block_p_start block_p '}' EOL  */
#line 92 "src/generic.y"
                                             {
  (yyval.stmt) = (yyvsp[-2].block_p);

  // Note: Don't deallocate the scope yet, just in case a block latched on
  currentScope = currentScope->next;

  // Pop off the function stack, as appropriate
  int depth = currentScope->depth();
  if (funcStack && funcStack->level >= depth) {
    // Keep this fellow around for type implications
    lastFuncStack = funcStack;
    funcStack = lastFuncStack->parent;
  }
}
#line 1750 "obj/generic.tab.c"
    break;

  case 15: /* block_p_start: %empty  */
#line 109 "src/generic.y"
                           {
  if (beginFunctionScope != NULL) {
    currentScope = beginFunctionScope;
    beginFunctionScope = NULL;
  } else {
    currentScope = new Scope(currentScope);
  }
}
#line 1763 "obj/generic.tab.c"
    break;

  case 16: /* block_p: stmt block_p  */
#line 118 "src/generic.y"
                      { (yyval.block_p) = new NBlock((yyvsp[-1].stmt), (yyvsp[0].block_p)); }
#line 1769 "obj/generic.tab.c"
    break;

  case 17: /* block_p: stmt  */
#line 119 "src/generic.y"
           { (yyval.block_p) = new NBlock((yyvsp[0].stmt), NULL); }
#line 1775 "obj/generic.tab.c"
    break;

  case 18: /* expr: function_call  */
#line 122 "src/generic.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1781 "obj/generic.tab.c"
    break;

  case 19: /* expr: expr '[' expr ']'  */
#line 123 "src/generic.y"
                        { (yyval.expr) = new NListIndex((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1787 "obj/generic.tab.c"
    break;

  case 20: /* expr: '(' expr ')'  */
#line 124 "src/generic.y"
                   { (yyval.expr) = (yyvsp[-1].expr); }
#line 1793 "obj/generic.tab.c"
    break;

  case 21: /* expr: INTEGER  */
#line 125 "src/generic.y"
              { (yyval.expr) = (yyvsp[0].int_val); }
#line 1799 "obj/generic.tab.c"
    break;

  case 22: /* expr: ID  */
#line 126 "src/generic.y"
         { (yyval.expr) = (yyvsp[0].id_val); }
#line 1805 "obj/generic.tab.c"
    break;

  case 23: /* expr: STRING  */
#line 127 "src/generic.y"
             { (yyval.expr) = (yyvsp[0].str_val); }
#line 1811 "obj/generic.tab.c"
    break;

  case 24: /* expr: list_expr  */
#line 128 "src/generic.y"
                { (yyval.expr) = (yyvsp[0].expr); }
#line 1817 "obj/generic.tab.c"
    break;

  case 25: /* expr: expr LT expr  */
#line 129 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_LT, (yyvsp[0].expr)); }
#line 1823 "obj/generic.tab.c"
    break;

  case 26: /* expr: expr LTE expr  */
#line 130 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_LTE, (yyvsp[0].expr)); }
#line 1829 "obj/generic.tab.c"
    break;

  case 27: /* expr: expr GT expr  */
#line 131 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_GT, (yyvsp[0].expr)); }
#line 1835 "obj/generic.tab.c"
    break;

  case 28: /* expr: expr GTE expr  */
#line 132 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_GTE, (yyvsp[0].expr)); }
#line 1841 "obj/generic.tab.c"
    break;

  case 29: /* expr: expr NEQ expr  */
#line 133 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_NEQ, (yyvsp[0].expr)); }
#line 1847 "obj/generic.tab.c"
    break;

  case 30: /* expr: expr EQ expr  */
#line 134 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_EQ, (yyvsp[0].expr)); }
#line 1853 "obj/generic.tab.c"
    break;

  case 31: /* expr: expr AND expr  */
#line 135 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_AND, (yyvsp[0].expr)); }
#line 1859 "obj/generic.tab.c"
    break;

  case 32: /* expr: expr OR expr  */
#line 136 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_OR, (yyvsp[0].expr)); }
#line 1865 "obj/generic.tab.c"
    break;

  case 33: /* expr: expr SL expr  */
#line 137 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_SL, (yyvsp[0].expr)); }
#line 1871 "obj/generic.tab.c"
    break;

  case 34: /* expr: expr SR expr  */
#line 138 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_SR, (yyvsp[0].expr)); }
#line 1877 "obj/generic.tab.c"
    break;

  case 35: /* expr: expr BA expr  */
#line 139 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_BA, (yyvsp[0].expr)); }
#line 1883 "obj/generic.tab.c"
    break;

  case 36: /* expr: expr BO expr  */
#line 140 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_BO, (yyvsp[0].expr)); }
#line 1889 "obj/generic.tab.c"
    break;

  case 37: /* expr: expr BX expr  */
#line 141 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_BX, (yyvsp[0].expr)); }
#line 1895 "obj/generic.tab.c"
    break;

  case 38: /* expr: NOT expr  */
#line 142 "src/generic.y"
                    { (yyval.expr) = new NUnaryOperator(N_NOT, (yyvsp[0].expr)); }
#line 1901 "obj/generic.tab.c"
    break;

  case 39: /* expr: BN expr  */
#line 143 "src/generic.y"
                    { (yyval.expr) = new NUnaryOperator(N_BN, (yyvsp[0].expr)); }
#line 1907 "obj/generic.tab.c"
    break;

  case 40: /* expr: '-' expr  */
#line 144 "src/generic.y"
                    { (yyval.expr) = new NUnaryOperator(N_SUB, (yyvsp[0].expr)); }
#line 1913 "obj/generic.tab.c"
    break;

  case 41: /* expr: expr '+' expr  */
#line 145 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_ADD, (yyvsp[0].expr)); }
#line 1919 "obj/generic.tab.c"
    break;

  case 42: /* expr: expr '-' expr  */
#line 146 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_SUB, (yyvsp[0].expr)); }
#line 1925 "obj/generic.tab.c"
    break;

  case 43: /* expr: expr '*' expr  */
#line 147 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_MUL, (yyvsp[0].expr)); }
#line 1931 "obj/generic.tab.c"
    break;

  case 44: /* expr: expr '/' expr  */
#line 148 "src/generic.y"
                    { (yyval.expr) = new NBinaryOperator((yyvsp[-2].expr), N_DIV, (yyvsp[0].expr)); }
#line 1937 "obj/generic.tab.c"
    break;

  case 45: /* expr: expr '%' expr  */
#line 149 "src/generic.y"
                    {
      // Since modulus is different in C++ than in Python
      (yyval.expr) = new NFunctionCallExpression(new NIdentifier("javelin::modulus"),
          new NExpressionArgs((yyvsp[-2].expr), new NExpressionArgs((yyvsp[0].expr), NULL)));
    }
#line 1947 "obj/generic.tab.c"
    break;

  case 46: /* list_expr: '[' args2 ']'  */
#line 156 "src/generic.y"
                         {
  (yyval.expr) = new NList((yyvsp[-1].exprags));
}
#line 1955 "obj/generic.tab.c"
    break;

  case 47: /* ret: RETURN expr EOL  */
#line 160 "src/generic.y"
                     { (yyval.stmt) = new NReturn((yyvsp[-1].expr)); }
#line 1961 "obj/generic.tab.c"
    break;

  case 48: /* ret: RETURN EOL  */
#line 161 "src/generic.y"
                { (yyval.stmt) = new NReturn(NULL); }
#line 1967 "obj/generic.tab.c"
    break;

  case 49: /* assign: ID '=' expr  */
#line 163 "src/generic.y"
                    { (yyval.stmt) = new NAssignment((yyvsp[-2].id_val), (yyvsp[0].expr)); }
#line 1973 "obj/generic.tab.c"
    break;

  case 50: /* while: WHILE expr '{' block '}'  */
#line 166 "src/generic.y"
                                { (yyval.stmt) = new NWhileStatement((yyvsp[-3].expr), (yyvsp[-1].stmt)); }
#line 1979 "obj/generic.tab.c"
    break;

  case 51: /* for: for_header block '}'  */
#line 169 "src/generic.y"
                          { (yyval.for_stmt) = (yyvsp[-2].for_stmt); (yyval.for_stmt)->stmt = (yyvsp[-1].stmt); }
#line 1985 "obj/generic.tab.c"
    break;

  case 52: /* for_header: FOR ID IN expr '{'  */
#line 170 "src/generic.y"
                               { (yyval.for_stmt) = new NForStatement((yyvsp[-3].id_val), (yyvsp[-1].expr), NULL); }
#line 1991 "obj/generic.tab.c"
    break;

  case 53: /* if: IF expr '{' block '}'  */
#line 172 "src/generic.y"
                          { (yyval.stmt) = new NIfStatement((yyvsp[-3].expr), (yyvsp[-1].stmt), NULL, NULL); }
#line 1997 "obj/generic.tab.c"
    break;

  case 54: /* if: IF expr '{' block elif '}'  */
#line 173 "src/generic.y"
                                 { (yyval.stmt) = new NIfStatement((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[-1].elif_stmt), NULL); }
#line 2003 "obj/generic.tab.c"
    break;

  case 55: /* if: IF expr '{' block else '}'  */
#line 174 "src/generic.y"
                                 { (yyval.stmt) = new NIfStatement((yyvsp[-4].expr), (yyvsp[-2].stmt), NULL, (yyvsp[-1].else_stmt)); }
#line 2009 "obj/generic.tab.c"
    break;

  case 56: /* elif: ELIF expr '{' block '}'  */
#line 177 "src/generic.y"
                              { (yyval.elif_stmt) = new NElifStatement((yyvsp[-3].expr), (yyvsp[-1].stmt), NULL, NULL); }
#line 2015 "obj/generic.tab.c"
    break;

  case 57: /* elif: ELIF expr '{' block elif '}'  */
#line 178 "src/generic.y"
                                   { (yyval.elif_stmt) = new NElifStatement((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[-1].elif_stmt), NULL); }
#line 2021 "obj/generic.tab.c"
    break;

  case 58: /* elif: ELIF expr '{' block else '}'  */
#line 179 "src/generic.y"
                                   { (yyval.elif_stmt) = new NElifStatement((yyvsp[-4].expr), (yyvsp[-2].stmt), NULL, (yyvsp[-1].else_stmt)); }
#line 2027 "obj/generic.tab.c"
    break;

  case 59: /* else: ELSE '{' block '}'  */
#line 182 "src/generic.y"
                         { (yyval.else_stmt) = new NElseStatement((yyvsp[-1].stmt)); }
#line 2033 "obj/generic.tab.c"
    break;

  case 60: /* def: DEF funcDef block  */
#line 185 "src/generic.y"
                       {
  (yyvsp[-1].funcDeclStmt)->stmt = (yyvsp[0].stmt);
  // In case the type has been implied
  Type *type = lastFuncStack->get_type();
  (yyvsp[-1].funcDeclStmt)->type = type->isUnset() ? new VoidType() : type;
  (yyval.stmt) = (yyvsp[-1].funcDeclStmt);
}
#line 2045 "obj/generic.tab.c"
    break;

  case 61: /* funcDef: ID '(' args ')' rtype ':'  */
#line 193 "src/generic.y"
                                   {
    (yyval.funcDeclStmt) = new NFunctionDeclStatement((yyvsp[-5].id_val), (yyvsp[-3].args), (yyvsp[-1].type), NULL);
    funcStack->stmt = (yyval.funcDeclStmt);
    beginFunctionScope = new FunctionScope(currentScope, (yyval.funcDeclStmt));
}
#line 2055 "obj/generic.tab.c"
    break;

  case 62: /* args: %empty  */
#line 198 "src/generic.y"
                  { (yyval.args) = NULL; }
#line 2061 "obj/generic.tab.c"
    break;

  case 63: /* args: arg_list  */
#line 199 "src/generic.y"
               { (yyval.args) = (yyvsp[0].args); }
#line 2067 "obj/generic.tab.c"
    break;

  case 64: /* arg_list: ID ':' type  */
#line 202 "src/generic.y"
                  { (yyval.args) = new NArgs((yyvsp[-2].id_val), (yyvsp[0].type), NULL); }
#line 2073 "obj/generic.tab.c"
    break;

  case 65: /* arg_list: ID ':' type ',' arg_list  */
#line 203 "src/generic.y"
                               { (yyval.args) = new NArgs((yyvsp[-4].id_val), (yyvsp[-2].type), (yyvsp[0].args)); }
#line 2079 "obj/generic.tab.c"
    break;

  case 66: /* arg_list: ID  */
#line 204 "src/generic.y"
         { (yyval.args) = new NArgs((yyvsp[0].id_val), new UnsetType(), NULL); }
#line 2085 "obj/generic.tab.c"
    break;

  case 67: /* arg_list: ID ',' arg_list  */
#line 205 "src/generic.y"
                      { (yyval.args) = new NArgs((yyvsp[-2].id_val), new UnsetType(), (yyvsp[0].args)); }
#line 2091 "obj/generic.tab.c"
    break;

  case 68: /* rtype: %empty  */
#line 209 "src/generic.y"
                   {
  (yyval.type) = new UnsetType();
  funcStack = new FunctionStack(currentScope->depth(), funcStack, (yyval.type));
}
#line 2100 "obj/generic.tab.c"
    break;

  case 69: /* rtype: RTYPE type  */
#line 212 "src/generic.y"
               {
  (yyval.type) = (yyvsp[0].type);
  funcStack = new FunctionStack(currentScope->depth(), funcStack, (yyval.type));
}
#line 2109 "obj/generic.tab.c"
    break;

  case 70: /* args2: %empty  */
#line 217 "src/generic.y"
                   { (yyval.exprags) = NULL; }
#line 2115 "obj/generic.tab.c"
    break;

  case 71: /* args2: arg_list2  */
#line 218 "src/generic.y"
                { (yyval.exprags) = (yyvsp[0].exprags); }
#line 2121 "obj/generic.tab.c"
    break;

  case 72: /* arg_list2: expr  */
#line 220 "src/generic.y"
                { (yyval.exprags) = new NExpressionArgs((yyvsp[0].expr), NULL); }
#line 2127 "obj/generic.tab.c"
    break;

  case 73: /* arg_list2: expr ',' arg_list2  */
#line 221 "src/generic.y"
                         { (yyval.exprags) = new NExpressionArgs((yyvsp[-2].expr), (yyvsp[0].exprags)); }
#line 2133 "obj/generic.tab.c"
    break;

  case 74: /* function_call: ID '(' args2 ')'  */
#line 224 "src/generic.y"
                                { (yyval.expr) = new NFunctionCallExpression((yyvsp[-3].id_val), (yyvsp[-1].exprags)); }
#line 2139 "obj/generic.tab.c"
    break;

  case 75: /* type: ID  */
#line 228 "src/generic.y"
         {if ((yyvsp[0].id_val)->name == "str") (yyval.type) =  new StringType();
          else (yyval.type) = new BasicType((yyvsp[0].id_val)->name);}
#line 2146 "obj/generic.tab.c"
    break;


#line 2150 "obj/generic.tab.c"

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
          = {yyssp, yytoken};
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 230 "src/generic.y"


#include "../obj/generic.yy.c"
int main() {
  try {
    currentScope = new RootScope();
    funcStack = NULL;

    yyin = stdin;
    yyparse();

    // One header to rule them all
    cout << "#include \"inc/generic.h\"\n";

    // Generate the headers first, so we don't run into annoying mutuality conflicts
    for (NFunctionDeclStatement *stmt : rootFuncStmts) {
      stmt->generateHeader();
    }

    cout << "int main() {\n";
    for (NStatement *stmt : rootStmts) {
      stmt->generate(1);
    }
    cout << "}\n";
    for (NFunctionDeclStatement *stmt : rootFuncStmts) {
      stmt->generate(0);
    }

    // All root function & class declarations should be before main().
    return 0;
  } catch (const std::runtime_error& error) {
    yyerror(error.what());
  }
}

void yyerror(char const *m) {
    fprintf(stderr, "Parse error: %s on line %d\n", m, yylineno);
    exit(1);
}
