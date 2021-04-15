/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 25 Jul 19   */

/* Copyright (c) 2019 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */
/* 30 Jul 13 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;


#line 129 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    STRING = 259,
    NUMBER = 260,
    PLUS = 261,
    MINUS = 262,
    TIMES = 263,
    DIVIDE = 264,
    ASSIGN = 265,
    EQ = 266,
    NE = 267,
    LT = 268,
    LE = 269,
    GE = 270,
    GT = 271,
    POINT = 272,
    DOT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    DIV = 277,
    MOD = 278,
    IN = 279,
    COMMA = 280,
    SEMICOLON = 281,
    COLON = 282,
    LPAREN = 283,
    RPAREN = 284,
    LBRACKET = 285,
    RBRACKET = 286,
    DOTDOT = 287,
    ARRAY = 288,
    BEGINBEGIN = 289,
    CASE = 290,
    CONST = 291,
    DO = 292,
    DOWNTO = 293,
    ELSE = 294,
    END = 295,
    FILEFILE = 296,
    FOR = 297,
    FUNCTION = 298,
    GOTO = 299,
    IF = 300,
    LABEL = 301,
    NIL = 302,
    OF = 303,
    PACKED = 304,
    PROCEDURE = 305,
    PROGRAM = 306,
    RECORD = 307,
    REPEAT = 308,
    SET = 309,
    THEN = 310,
    TO = 311,
    TYPE = 312,
    UNTIL = 313,
    VAR = 314,
    WHILE = 315,
    WITH = 316
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 299 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    84,    85,    87,    88,    90,    92,    94,
      95,    97,    98,   101,   102,   105,   106,   107,   108,   109,
     110,   112,   115,   116,   118,   120,   121,   123,   124,   127,
     128,   129,   131,   132,   134,   135,   136,   137,   140,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   152,   153,
     155,   156,   158,   159,   161,   162,   164,   166,   167,   168,
     170,   171,   172,   173,   174,   175,   176,   178,   179,   180,
     182,   183,   185,   186,   187,   188,   189,   191,   192,   195,
     196,   197,   198,   200,   202,   203,   205,   207,   208,   210,
     211,   213,   214,   215,   216,   217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "id_list", "varspecs", "vargroup", "block", "vblock", "cblock", "sign",
  "constant", "cdef", "cdef_list", "tdef", "tdef_list", "tblock",
  "simpletype", "simTL", "type", "funcall", "statement", "state_list",
  "exp_list", "endpart", "endif", "assignment", "plus_op", "compare_op",
  "inner_exp", "exp", "times_op", "term", "variable", "fields",
  "field_list", "label", "num_list", "lblock", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,    16,    22,    -1,  -107,    21,     3,    30,    21,    36,
    -107,    48,    33,    60,    75,    62,    21,  -107,  -107,  -107,
    -107,    63,    55,    58,    33,    85,    84,   160,    33,   160,
    -107,   -14,  -107,   117,  -107,    80,    73,    11,    83,    87,
     104,    92,   -13,    94,    88,    93,  -107,   160,    33,   -14,
    -107,    72,  -107,   260,  -107,  -107,  -107,  -107,   160,   160,
    -107,   180,  -107,  -107,    90,    19,   171,   123,  -107,   107,
      78,   204,    33,  -107,  -107,   160,  -107,   127,   160,    45,
      60,  -107,    75,    66,   145,    62,  -107,   145,  -107,    21,
     108,   251,  -107,  -107,   160,    53,  -107,   231,   260,  -107,
     171,  -107,  -107,  -107,   160,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,    33,   160,  -107,  -107,  -107,  -107,  -107,   160,
      33,   160,    33,   -14,   257,  -107,   111,  -107,  -107,  -107,
    -107,  -107,   112,   136,    21,   115,    21,   114,  -107,  -107,
    -107,  -107,  -107,  -107,   160,   224,  -107,  -107,  -107,   171,
     118,    90,  -107,  -107,   257,  -107,  -107,  -107,  -107,   125,
     206,   142,   144,   131,    45,  -107,    33,    33,  -107,  -107,
     147,   143,   145,    21,  -107,  -107,  -107,  -107,   206,   128,
    -107,  -107,  -107,   145,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     4,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,    10,    28,    90,
      12,     0,    79,     0,     0,     0,     0,     0,     0,     0,
      43,     0,    42,     0,    44,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
      79,     0,    47,    16,    18,    17,    13,    14,     0,     0,
      20,     0,    95,    92,    71,     0,    69,    93,    78,    49,
       0,     0,     0,    53,     8,     0,    81,     0,     0,     0,
      23,    11,     0,     0,     0,    26,    27,     0,     9,     6,
       0,    51,    86,    39,     0,     0,    94,     0,    15,    17,
      68,    57,    58,    59,     0,    60,    66,    61,    62,    63,
      65,    64,     0,     0,    72,    73,    76,    74,    75,     0,
       0,     0,     0,     0,    56,    82,     0,    16,    21,    22,
      87,    89,    29,     0,     0,     0,     0,     0,    34,    24,
      25,     7,     5,    38,     0,     0,    15,    19,    91,    67,
      55,    70,    77,    48,    45,    46,    52,    80,    35,     0,
       0,     0,    85,     0,     0,    50,     0,     0,    40,    31,
      33,     0,     0,     0,    37,    30,    41,    54,     0,     0,
      83,    84,    32,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,    -5,    86,  -107,   133,   140,   106,   -18,   -40,
    -107,   116,  -107,   110,   154,  -106,    20,   -85,    -8,    -6,
      79,   -71,   -44,  -107,   175,  -107,  -107,    89,    -4,  -107,
     -51,   -11,  -107,    31,  -107,   121,  -107,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    43,    44,    45,    17,    18,    19,    95,    62,
      36,    37,    41,    42,    20,   138,   171,   139,    63,    69,
      70,    90,    74,   168,    32,   104,   113,    64,    91,   119,
      66,    67,   162,   163,    34,    39,    21,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    33,   141,    10,    30,    93,    31,   126,    96,    61,
     100,    61,    72,    33,    33,     1,    30,    33,    49,     3,
      30,    12,     4,    65,     6,    71,    73,     5,     8,    61,
     105,   106,   107,   108,   109,   110,    22,    33,    23,   128,
      30,    61,    92,   111,   137,    12,    16,   137,   127,    54,
      55,    56,    57,   149,   170,    97,   146,    61,   147,     9,
      61,    33,    11,    35,    30,    40,   123,    24,    15,   152,
      16,   124,   170,   165,   112,    25,    61,    26,    27,   156,
      38,    46,    12,    47,    13,    48,    28,   180,    50,    52,
     145,    79,    60,    29,    14,    61,   101,   102,   184,    80,
      12,    33,    13,    61,    30,    15,   150,    16,    82,    33,
     103,    33,    30,    83,    30,    84,   155,   154,    85,    89,
     137,    87,    12,    15,   175,    16,    61,    75,    94,   159,
     125,   161,   137,   120,    76,    77,   121,   143,   137,   158,
      76,    77,   157,   137,   -16,   160,   164,    78,   132,    54,
      55,    56,    57,    78,   169,    33,    33,   167,    30,    30,
     176,   177,   133,    53,    54,    55,    56,    57,   161,   172,
     173,   174,   178,   134,   179,   142,   183,    88,   135,   114,
     115,    58,    86,    98,    54,    99,    56,    57,    59,   131,
     116,    81,    60,   117,   118,   140,   129,   136,   182,   153,
      51,    58,   151,   130,   181,     0,     0,    60,    59,   132,
      54,    55,    56,    57,     0,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,    60,   111,     0,
       0,     0,     0,     0,   134,   105,   106,   107,   108,   109,
     110,   122,   105,   106,   107,   108,   109,   110,   111,     0,
       0,     0,     0,    60,     0,   111,     0,     0,     0,     0,
     148,   166,   105,   106,   107,   108,   109,   110,   105,   106,
     107,   108,   109,   110,     0,   111,   144,   -79,   -79,     0,
       0,   111,     0,     0,     0,     0,     0,     0,    47,     0,
     -79
};

static const yytype_int16 yycheck[] =
{
       5,    12,    87,     8,    12,    49,    12,    78,    58,    27,
      61,    29,    26,    24,    25,    51,    24,    28,    24,     3,
      28,    34,     0,    27,     3,    29,    40,    28,    25,    47,
      11,    12,    13,    14,    15,    16,     3,    48,     5,    79,
      48,    59,    48,    24,    84,    34,    59,    87,     3,     4,
       5,     6,     7,   104,   160,    59,     3,    75,     5,    29,
      78,    72,    26,     3,    72,     3,    72,    34,    57,   119,
      59,    75,   178,   144,    55,    42,    94,    44,    45,   123,
       5,    18,    34,    28,    36,    27,    53,   172,     3,     5,
      94,    11,    47,    60,    46,   113,     6,     7,   183,    26,
      34,   112,    36,   121,   112,    57,   112,    59,    25,   120,
      20,   122,   120,    26,   122,    11,   122,   121,    26,    26,
     160,    27,    34,    57,   164,    59,   144,    10,    56,   134,
       3,   136,   172,    26,    17,    18,    58,    29,   178,     3,
      17,    18,    31,   183,    32,    30,    32,    30,     3,     4,
       5,     6,     7,    30,    29,   166,   167,    39,   166,   167,
     166,   167,    17,     3,     4,     5,     6,     7,   173,    27,
      26,    40,    25,    28,    31,    89,    48,    44,    33,     8,
       9,    21,    42,     3,     4,     5,     6,     7,    28,    83,
      19,    37,    47,    22,    23,    85,    80,    52,   178,   120,
      25,    21,   113,    82,   173,    -1,    -1,    47,    28,     3,
       4,     5,     6,     7,    -1,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    47,    24,    -1,
      -1,    -1,    -1,    -1,    28,    11,    12,    13,    14,    15,
      16,    37,    11,    12,    13,    14,    15,    16,    24,    -1,
      -1,    -1,    -1,    47,    -1,    24,    -1,    -1,    -1,    -1,
      29,    37,    11,    12,    13,    14,    15,    16,    11,    12,
      13,    14,    15,    16,    -1,    24,    25,    17,    18,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    64,    25,    29,
      64,    26,    34,    36,    46,    57,    59,    67,    68,    69,
      76,    98,     3,     5,    34,    42,    44,    45,    53,    60,
      80,    81,    86,    93,    96,     3,    72,    73,     5,    97,
       3,    74,    75,    64,    65,    66,    18,    28,    27,    81,
       3,    86,     5,     3,     4,     5,     6,     7,    21,    28,
      47,    70,    71,    80,    89,    90,    92,    93,    99,    81,
      82,    90,    26,    40,    84,    10,    17,    18,    30,    11,
      26,    76,    25,    26,    11,    26,    68,    27,    67,    26,
      83,    90,    81,    84,    56,    70,    99,    90,     3,     5,
      92,     6,     7,    20,    87,    11,    12,    13,    14,    15,
      16,    24,    55,    88,     8,     9,    19,    22,    23,    91,
      26,    58,    37,    81,    90,     3,    83,     3,    71,    73,
      97,    69,     3,    17,    28,    33,    52,    71,    77,    79,
      75,    79,    65,    29,    25,    90,     3,     5,    29,    92,
      81,    89,    99,    82,    90,    81,    84,    31,     3,    64,
      30,    64,    94,    95,    32,    83,    37,    39,    85,    29,
      77,    78,    27,    26,    40,    71,    81,    81,    25,    31,
      79,    95,    78,    48,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    73,    73,    74,    75,    75,    76,    76,    77,
      77,    77,    78,    78,    79,    79,    79,    79,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    92,    92,    93,
      93,    93,    93,    94,    95,    95,    96,    97,    97,    98,
      98,    99,    99,    99,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     3,     1,     3,     2,     3,     3,     3,
       1,     3,     1,     1,     1,     2,     1,     1,     1,     2,
       1,     3,     3,     2,     3,     3,     2,     3,     1,     1,
       3,     3,     3,     1,     1,     2,     6,     3,     4,     3,
       5,     6,     1,     1,     1,     4,     4,     2,     3,     1,
       3,     1,     3,     1,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       4,     2,     3,     3,     3,     1,     3,     3,     1,     4,
       1,     3,     1,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 82 "parse.y" /* yacc.c:1646  */
    { parseresult = makeprogram((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1])); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 84 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "parse.y" /* yacc.c:1646  */
    { instvars((yyvsp[-2]), (yyvsp[0])); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeprogn((yyvsp[-2]),cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 94 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 97 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 105 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "parse.y" /* yacc.c:1646  */
    { (yyval) = findid((yyvsp[0])); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 109 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 112 "parse.y" /* yacc.c:1646  */
    { instconst((yyvsp[-2]), (yyvsp[0])); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 118 "parse.y" /* yacc.c:1646  */
    { insttype((yyvsp[-2]), (yyvsp[0])); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 127 "parse.y" /* yacc.c:1646  */
    { (yyval) = findtype((yyvsp[0])); }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 128 "parse.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 129 "parse.y" /* yacc.c:1646  */
    { (yyval) = instenum((yyvsp[-1])); }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 131 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 132 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 134 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 135 "parse.y" /* yacc.c:1646  */
    { (yyval) = instpoint((yyvsp[-1]), (yyvsp[0])); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 136 "parse.y" /* yacc.c:1646  */
    { (yyval) = instarray((yyvsp[-3]), (yyvsp[0])); }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 137 "parse.y" /* yacc.c:1646  */
    { (yyval) = instrec((yyvsp[-2]), (yyvsp[-1])); }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 140 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((yyvsp[-2]), (yyvsp[-3]), (yyvsp[-1])); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 142 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeprogn((yyvsp[-2]),cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 143 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeif((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0])); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 144 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefor(1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 148 "parse.y" /* yacc.c:1646  */
    { (yyval) = makerepeat((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 149 "parse.y" /* yacc.c:1646  */
    { (yyval) = makewhile((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 150 "parse.y" /* yacc.c:1646  */
    { (yyval) = dogoto((yyvsp[-1]), (yyvsp[0])); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 152 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 153 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 155 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 158 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-1]), (yyvsp[0])); }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 159 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 161 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 162 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 164 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 178 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 179 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 182 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 191 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 195 "parse.y" /* yacc.c:1646  */
    { (yyval) = findid((yyvsp[0])); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 196 "parse.y" /* yacc.c:1646  */
    { (yyval) = arrayref((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 197 "parse.y" /* yacc.c:1646  */
    { (yyval) = dopoint((yyvsp[-1]), (yyvsp[0])); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 198 "parse.y" /* yacc.c:1646  */
    { (yyval) = reducedot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 200 "parse.y" /* yacc.c:1646  */
    { (yyval) = instfields((yyvsp[-2]), (yyvsp[0])); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 202 "parse.y" /* yacc.c:1646  */
    { (yyval) = nconc((yyvsp[-2]), (yyvsp[0])); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 205 "parse.y" /* yacc.c:1646  */
    { (yyval) = dolabel((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 207 "parse.y" /* yacc.c:1646  */
    { instlabel((yyvsp[-2])); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 208 "parse.y" /* yacc.c:1646  */
    { instlabel((yyvsp[0])); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 210 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 213 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 216 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1849 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 221 "parse.y" /* yacc.c:1906  */


/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG        255             /* set bits here for debugging, 0 = off  */
#define DB_CONS       1             /* bit to trace cons */
#define DB_BINOP      2             /* bit to trace binop */
#define DB_MAKEIF     4             /* bit to trace makeif */
#define DB_MAKEPROGN  8             /* bit to trace makeprogn */
#define DB_PARSERES  16             /* bit to trace parseresult */
#define DB_PRGM  32          
#define DB_MAKEFC  64  
#define DB_MAKEFOR  128 
#define DB_MAKEF  3
#define DB_INSTARR  5
#define DB_INSTREC  7
#define DB_MAKEREF  9


 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labelArray[128];
   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    
    if (lhs->basicdt == REAL && rhs->basicdt == REAL) {
      op->basicdt = REAL;     
    } else if (lhs->basicdt == REAL && rhs->basicdt == INTEGER) {
      op->basicdt = REAL;
      cons(lhs,  makefloat(rhs));
    } else if (lhs->basicdt == INTEGER && rhs->basicdt == REAL) {
      if (op->whichval == ASSIGNOP) {
        op->basicdt = INTEGER;
        TOKEN fixtok = makefix(rhs);
        cons(lhs, fixtok);
      } else {
        op->basicdt = REAL;
        cons(makefloat(lhs), rhs);
      }
    } 
   return op;
  }


TOKEN findid(TOKEN tok) {    
    SYMBOL sym = searchst(tok->stringval);
    tok->symentry = sym;
    if (sym->kind == CONSTSYM) {
      if (sym->basicdt == REAL || sym->basicdt == INTEGER) {
        tok->tokentype = NUMBERTOK;
        tok->basicdt = sym->basicdt;
        if (sym->basicdt == REAL) {
          tok->realval = sym->constval.realnum;
        } else {
          tok->intval = sym->constval.intnum;
        }
      }
    } else {
      SYMBOL symtp = sym->datatype;
      tok->symtype = symtp;
      if ( symtp->kind == POINTERSYM || symtp->kind == BASICTYPE) {
         tok->basicdt = symtp->basicdt;
      }
    }
    return tok;
  }


TOKEN makefix(TOKEN tok) {
  if(tok->tokentype == NUMBERTOK) {
    tok->intval = (int) tok->realval;
    tok->basicdt = INTEGER;
    return tok;
  } 
  TOKEN fixtok = makeop(FIXOP);
  fixtok->operands = tok;
  return fixtok;
}


TOKEN makefloat(TOKEN tok) {
  if(tok->tokentype == NUMBERTOK) {
    tok->realval = (double) tok->intval;
    tok->basicdt = REAL;
    return tok;
  }
  TOKEN flotok = makeop(FLOATOP);
  flotok->operands = tok;
  return flotok;
}


TOKEN unaryop(TOKEN op, TOKEN lhs) {
  op->operands = lhs;
  lhs->link = NULL;
  return op;  
}

TOKEN findtype(TOKEN tok) {
	SYMBOL sym = searchst(tok->stringval);
	tok->symentry = sym;	
	tok->symtype = sym;
	return tok;
}

/* similar idea to mkae for */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokbody, TOKEN exp) {

   TOKEN label = makelabel();
   tok = makeprogn(tok, label);
   TOKEN body = tokbody;
   body = makeprogn(body, statements);
   cons(label,body);

   int cur = labelnumber - 1;
   TOKEN newtok = makeprogn((TOKEN) talloc(), NULL);
   TOKEN gototok = makegoto(cur);
   cons(newtok, gototok);
   TOKEN bool = talloc();
   bool = makeif(bool, exp, newtok, gototok);
   cons(body, bool);
   if (DEBUG) {
         printf("makerepeat\n");
         dbugprinttok(tok);
   }
   return tok;  
}


TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  
    tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
  tok->tokentype = OPERATOR;
  tok->whichval = FUNCALLOP;
  tok->operands = fn;
  fn->link=args;
  if (DEBUG & DB_MAKEFC) {
         printf("fun call\n");
         dbugprinttok(tok);
  }
  return tok;
}

TOKEN makeint(int num) {
	TOKEN tok = talloc();
	tok->tokentype = NUMBERTOK;
	tok->intval = num;
	tok->basicdt = INTEGER;
	return tok;
}

TOKEN makeop(int opnum) {
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = opnum;
  return tok;
}

TOKEN makelabel() {
	TOKEN label_tok = makeop(LABELOP);
	TOKEN lablenum = makeint(labelnumber++);	
	label_tok->operands = lablenum;
	return label_tok;
}

TOKEN makegoto(int label) {
	TOKEN goto_tok = makeop(GOTOOP);
	TOKEN lablenum = makeint(label);
	goto_tok->operands = lablenum;	
	return goto_tok;
}

TOKEN copytok(TOKEN target) {
  TOKEN copy = talloc();
  copy->basicdt = target->basicdt;
	copy->tokentype = target->tokentype;
	copy->symtype = target->symtype;
	copy->symentry = target->symentry;
  copy->whichval = target->whichval;
  copy->intval = target->intval;
  copy->realval = target->realval;
  copy->operands = target->operands;
	copy->link = target->link;
  return copy;
}

void insttype(TOKEN typen, TOKEN typetok){
    SYMBOL sym;
    SYMBOL typesym = typetok->symtype;
    sym = searchins(typen->stringval);
    sym->kind = TYPESYM;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    sym->size = typesym->size;
}

TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexp,
              TOKEN tokc, TOKEN statement) {
  TOKEN stop_tok = makeop(LEOP);
	TOKEN iterate_tok = makeop(PLUSOP);
	if (sign == -1) { 
		stop_tok ->whichval = GEOP;
		iterate_tok -> whichval = MINUSOP;
	}

  TOKEN first_i = copytok(asg->operands);
	TOKEN second_i = copytok(first_i);
	TOKEN third_i = copytok(first_i);
	stop_tok = binop(stop_tok, first_i, endexp);
  tokb->tokentype = NUMBERTOK;
  tokb->intval = 1;
  tokb->basicdt = INTEGER;
	binop(iterate_tok, second_i, tokb);
  TOKEN tok_var_incr = makeop(ASSIGNOP);
	binop(tok_var_incr, third_i, iterate_tok); 

  TOKEN goto_tok = makegoto(labelnumber); 
	cons(statement, cons(tok_var_incr, goto_tok)); 
	makeprogn(tokc, statement);
	tok = makeif(tok, stop_tok, tokc, 0);
  TOKEN label_tok = makelabel();
	cons(label_tok, tok);
	cons(asg, label_tok);  
  TOKEN out = makeprogn(talloc(), asg);
   if (DEBUG & DB_MAKEFOR){ 
     printf("makefor\n");
      dbugprinttok(out);
    };
	return out;
}


TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
	TOKEN tok_program = makeop(PROGRAMOP);
  TOKEN tok = makeprogn(talloc(), args);
	tok_program->operands = name;
  tok_program->tokentype = OPERATOR;
	name->link = tok;
	tok->link = statements;
  if (DEBUG & DB_PRGM) {
    printf("make prgm\n");
      dbugprinttok(tok_program);
  }
	return tok_program;
}

/* install variables in symbol table from the handout*/
void instvars(TOKEN idlist, TOKEN typetok)
{
    SYMBOL sym, typesym;
    int align;
    typesym = typetok->symtype;
    while(typesym && typesym->kind == TYPESYM){
        typesym = typesym->datatype;
    }
    align = alignsize(typesym);
    while ( idlist != NULL ) /* for each id */
    {
        sym = insertsym(idlist->stringval);
        sym->kind = VARSYM;
        sym->offset = /* "next" */
            wordaddress(blockoffs[blocknumber], align);
        sym->size = typesym->size;
        blockoffs[blocknumber] = /* "next" */
            sym->offset + sym->size;
        sym->datatype = typesym;
        sym->basicdt = typesym->basicdt;
        //idlist->basicdt = typesym->basicdt;
        idlist = idlist->link;
    };
}


void  instconst(TOKEN idtoken, TOKEN constok) {
  SYMBOL sym;
  sym = insertsym (idtoken->stringval);
  if (constok->basicdt == REAL) {
     sym->constval.realnum = constok->realval;
     sym-> basicdt = REAL;
  }
  if (constok->basicdt == INTEGER) {
     sym->constval.intnum = constok->intval;
     sym-> basicdt = INTEGER;
  }
  sym-> kind = CONSTSYM;
}


void  instlabel (TOKEN num){
    labelArray[labelnumber] = num->intval;
    labelnumber++;
}


TOKEN instfields(TOKEN idlist, TOKEN typetok){
    int flag = 0;
    TOKEN tok = idlist;
    SYMBOL sym = typetok->symtype;
    while(flag == 0){
        if (tok != NULL) {
          tok->symtype = sym;
          if(sym->kind != TYPESYM){
            tok->basicdt = sym->basicdt;
          }
          tok = tok->link;
        } else {
          flag = 1;
        }
    }
    if (DB_MAKEF) {
        printf("instfields\n");
        dbugprinttok(tok);
    }
    return idlist;
}


TOKEN nconc(TOKEN firstL, TOKEN secondL){
    TOKEN tok = firstL;
    while(tok->link){
        tok = tok->link;
    }
    tok->link = secondL;
    return tok;
}

TOKEN instenum(TOKEN idlist){
    TOKEN tok = idlist;
    int size = 0;
    while(tok != NULL){
        TOKEN intTok = makeint(size);
        instconst(tok, intTok);
        tok = tok->link;
        size++;
    }
    SYMBOL sym = symalloc();
    sym->kind = SUBRANGE;
    sym->basicdt = INTEGER;
    sym->size = sizeof(int);
    sym->lowbound = 0;
    sym->highbound = size - 1;
    idlist -> symtype = sym;

    if (DEBUG) {
        printf("instenum\n");
        dbugprinttok(idlist);
    }
    return idlist;
}


TOKEN maketok(int type, int val, TOKEN op){
    TOKEN tok = talloc();
    tok->tokentype = type;
    tok->whichval = val;
    tok->operands = op;
    return tok;
}


TOKEN instpoint(TOKEN tok, TOKEN typename){
    SYMBOL sym = symalloc();
    sym->basicdt = POINTER;
    sym->kind = POINTERSYM;
	  sym->size = basicsizes[POINTER];
    sym->datatype = searchins(typename->stringval);;
    tok->symtype = sym;
    return tok;
}


TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement){
  int labeln = labeltok->intval;
    int found = 0;
    int index =0;
    for (;index<labeln; index++) {
       if (labelArray[index] == labeln)
          found = 1;
    }
    if(found == 1){
        TOKEN numtok = makeint(index);
        labeltok = maketok(OPERATOR, LABELOP, numtok);
        labeltok->link = statement;
        TOKEN result = maketok(OPERATOR, PROGNOP, labeltok);
        return result;
    }
    printf("no such label in the list\n");
    return NULL;
}

TOKEN instrec(TOKEN rectok, TOKEN argstok){
    int curoffset = 0;
    SYMBOL sym = symalloc();
    sym->kind = RECORDSYM;
    rectok->symtype = sym;
    TOKEN args = argstok;
    TOKEN prevArg = NULL;
    int size = 0;
    SYMBOL newsym;
    while(args != NULL){
	      size = args->symtype->size;
        newsym = makesym(args->stringval);
        newsym->offset = wordaddress(curoffset, size);
        newsym->datatype = args->symtype;
        newsym->size = size;
        args->symtype = newsym;       
        if(!prevArg){
            sym->datatype = newsym;
        }else{
            prevArg->symtype->link = newsym;
        }
        curoffset = newsym->offset + size;
        prevArg = args;
        args = args->link;
    }
    sym->size = wordaddress(curoffset, 16);
    if (DB_INSTREC) {
        printf("instrec\n");
        dbugprinttok(rectok);
        printsymbol(sym);
    }
    return rectok;
}

TOKEN instdotdot(TOKEN low, TOKEN dottok, TOKEN high){
    SYMBOL sym = symalloc();
    sym->basicdt = INTEGER;
    sym->kind = SUBRANGE;
    sym->lowbound = low->intval;
    sym->highbound = high->intval;
    sym->size = sizeof(int);
    dottok->symtype = sym;
    return dottok;
}


int arraySizeHelper(SYMBOL sym, SYMBOL type){
    SYMBOL symdt = sym->datatype;
    if(symdt == type && symdt->datatype != type){
        return sym->size;
    }
    sym->size =((sym->highbound)-(sym->lowbound)+1)*arraySizeHelper(symdt, type);
    return sym->size;
}


TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
    int found = 0;
    SYMBOL recsym = var->symtype;
    if(recsym->kind == POINTERSYM) {
        recsym = recsym->datatype;
        while(recsym->kind == TYPESYM) {
            recsym = recsym->datatype;
        }
        found = 1;
    }

    SYMBOL temp = recsym;
    if(temp->kind == RECORDSYM){
        temp = recsym->datatype;
    }
    int curoffset = 0;

    while(temp) {
        if(strcmp(temp->namestring, field->stringval) == 0){
            curoffset = temp->offset;
            break;
        }
        temp = temp->link;
    }
  
    if(found==0 && var->whichval==AREFOP  && var->tokentype==OPERATOR 
            && var->operands->link->tokentype==NUMBERTOK){
        dot = var;
        dot->operands->link = makeint(curoffset+var->operands->link->intval);
        dot->basicdt = temp->datatype->basicdt;
	      return dot;
    }

    if (var->tokentype==OPERATOR && var->whichval==AREFOP){
          int offset = makeint(curoffset)->intval;
          var->operands->link->operands->intval += offset;
          dot = var;
    } else {
          dot = makeop(AREFOP);
          dot->operands = var;
          var->link =  makeint(curoffset);
    }
  
    temp = temp->datatype;
    while(temp->kind == TYPESYM) {
        temp = temp->datatype;
    }

    dot->basicdt = temp->basicdt;
    dot->symtype = temp->datatype;

    return dot;
}


TOKEN instarray(TOKEN bounds, TOKEN typetok){ 
    TOKEN tok = bounds;
    TOKEN nexttok = tok->link;
    SYMBOL preArray = NULL;
    SYMBOL range = tok->symtype;
    while(tok != NULL){
        SYMBOL arraySym = symalloc();
        arraySym->kind = ARRAYSYM;
	      SYMBOL range = tok->symtype;
        while(range->kind == TYPESYM){
            range = range->datatype;
        }
	      arraySym->lowbound = range->lowbound;
        arraySym->highbound = range->highbound;
        if(nexttok == NULL){
          arraySym->datatype = searchst(typetok->stringval);
	        arraySym->size = ((arraySym->highbound)-(arraySym->lowbound)+1)*(searchst(typetok->stringval)->size);
	      }
	      if(!preArray){
	        typetok->symtype = arraySym;
	      }else{
          preArray->datatype = arraySym;
	      }
        preArray = arraySym;
        tok = tok->link;
	      if(nexttok) 
          nexttok = nexttok->link;
    }
    arraySizeHelper(typetok->symtype, searchst(typetok->stringval));
    if (DB_INSTARR) {
        printf("instarry\n");
        dbugprinttok(typetok);
	      printsymbol(typetok->symtype);
    }
    return typetok;
}


TOKEN arrayref(TOKEN arrayTok, TOKEN tok, TOKEN subs, TOKEN tokb) {
    TOKEN offsetTok = NULL;
    TOKEN temp = subs;
    SYMBOL arraySymbol = arrayTok->symtype;
    while(temp != NULL) {
        int size = arraySymbol->datatype->size;
        TOKEN timed;
        TOKEN next = temp->link;
        TOKEN added;
        if(temp->tokentype != NUMBERTOK) {
            timed = binop(makeop(TIMESOP), makeint(size), temp);
        }else{
            timed = makeint((temp->intval) * size);
        }
        int newsize = -size * arraySymbol->lowbound;
        if(timed->tokentype == NUMBERTOK){
            added = makeint(newsize+(timed->intval));
        }else{
            added = binop(makeop(PLUSOP), makeint(newsize), timed);
        }
        if(offsetTok) {
            if(added->tokentype == NUMBERTOK){
                offsetTok->operands->intval += added->intval;
            }else{
                offsetTok = binop(makeop(PLUSOP), offsetTok, added);
            }
        } else {
            offsetTok = added;
        }
        temp = next;
        arraySymbol = arraySymbol->datatype;
    }
    while(arraySymbol->kind == TYPESYM){
        arraySymbol = arraySymbol->datatype;
    }
    tok = maketok(OPERATOR, AREFOP, arrayTok);
    tok->basicdt = 0;
    tok->operands->link = offsetTok;
    tok->symtype = arraySymbol;
    return tok;
}



TOKEN dogoto(TOKEN tok, TOKEN labeltok){
   int labeln = labeltok->intval;
    int found = 0;
    int index =0;
    for (;index<labeln; index++) {
       if (labelArray[index] == labeln)
          found = 1;
    }
    if (found == 1) {
      tok = makegoto(index);
    } else{
      printf("no such index in dogoto");
    }
    return tok;
}

TOKEN dopoint(TOKEN var, TOKEN tok){
    SYMBOL sym = var->symtype;
    while(sym->kind == TYPESYM)
        sym = sym->datatype;
    tok = maketok(OPERATOR, POINTEROP, var);
    tok->symtype = sym;
    return tok;
}


TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement){
    TOKEN label_tok = makelabel();
    TOKEN if_token = talloc();
    if_token = makeif(if_token, expr, statement, NULL);
    tok = makeprogn(tok, label_tok);
    label_tok->link = if_token;
    TOKEN statement_tok = statement->operands;
    while(statement_tok->link != NULL) {
        statement_tok = statement_tok->link;
    }
    statement_tok->link = makegoto(label_tok->operands->intval);
    return tok;
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void)          /*  */
  { int res;
    initsyms();
    res = yyparse();
    printst();       /* to shorten, change to:  printstlevel(1);  */
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
     /* 
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
 */
  }
