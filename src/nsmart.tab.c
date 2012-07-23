
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 14 "nsmart.y"

	#include <stdio.h>
	#include "op.h"
	//#include "symboltable.h"
	// Adding this to avoid microsoft error for alloca
//	#ifdef _MSC_VER
//		#define alloca( x ) malloc( x )
//	#endif
	int yylex(void);
	void yyerror(char *);
	extern FILE *yyin;
	extern char *yytext;
	extern char *literal;
	extern unsigned int literal_length;



/* Line 189 of yacc.c  */
#line 91 "nsmart.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     lower_case_identifier = 258,
     upper_case_identifier = 259,
     TYPE = 260,
     IS = 261,
     END = 262,
     SYMBOLIC = 263,
     RECORD = 264,
     NODE = 265,
     IN = 266,
     OUT = 267,
     INTO = 268,
     FUNC = 269,
     CONNECTION = 270,
     LAYER = 271,
     FROM = 272,
     TO = 273,
     ARRAY = 274,
     OF = 275,
     CONST = 276,
     VAR = 277,
     PROCEDURE = 278,
     EXTERNAL = 279,
     INCLUDED = 280,
     FUNCTION = 281,
     REDUCTION = 282,
     NEURAL = 283,
     WTA = 284,
     MERGE = 285,
     RETURN = 286,
     IOSTYLE = 287,
     CASE = 288,
     GROUP = 289,
     NETWORK = 290,
     KINDS = 291,
     IO_STYLE = 292,
     IOSPEC = 293,
     STYLE = 294,
     IF = 295,
     ELSE = 296,
     ELSEIF = 297,
     THEN = 298,
     REPEAT = 299,
     FOR = 300,
     WHILE = 301,
     UNTIL = 302,
     UPTO = 303,
     DOWNTO = 304,
     BREAK = 305,
     REPLICATE = 306,
     EXTEND = 307,
     BY = 308,
     CONNECT = 309,
     DISCONNECT = 310,
     OR = 311,
     XOR = 312,
     AND = 313,
     BITOR = 314,
     BITXOR = 315,
     BITAND = 316,
     LSHIFT = 317,
     RSHIFT = 318,
     MAXINDEX = 319,
     NOT = 320,
     BITNOT = 321,
     MIN = 322,
     MAX = 323,
     RANDOM = 324,
     ME = 325,
     YOU = 326,
     INDEX = 327,
     INPUT_ASSIGNMENT = 328,
     OUTPUT_ASSIGNMENT = 329,
     LESS_THEN_GREATHER_THEN = 330,
     LESS_THEN_EQUAL = 331,
     GREATHER_THEN_EQUAL = 332,
     ELIPSES = 333,
     EXPONENT_OPERATOR = 334,
     LOGICAL_EQ = 335,
     LOGICAL_LT = 336,
     LOGICAL_LT_EQ = 337,
     LOGICAL_GT = 338,
     LOGICAL_GT_EQ = 339,
     LOGICAL_NEQ = 340,
     LOGICAL_OR = 341,
     LOGICAL_AND = 342,
     INCLUSIVE_OR = 343,
     INCLUSIVE_AND = 344,
     LOGICAL_XOR = 345,
     INTEGER_DENOTER = 346,
     REAL_DENOTER = 347,
     EQUAL = 348,
     PLUS_EQUAL = 349,
     MINUS_EQUAL = 350,
     MULTIPLY_EQUAL = 351,
     DIVIDE_EQUAL = 352,
     MOD_EQUAL = 353,
     STRING_DENOTER = 354,
     PACKAGE = 355,
     PRINT = 356,
     SCAN = 357,
     READ = 358,
     WRITE = 359,
     OPEN = 360,
     CLOSE = 361
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "nsmart.y"

OP    *op;     // opcode
char  *t_sym;  // symbols
int    t_int;  // integer
unsigned int t_uint; //unsigned integer
char  *t_op;   // operator



/* Line 214 of yacc.c  */
#line 243 "nsmart.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 255 "nsmart.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   608

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  124
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  207

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   361

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   115,     2,     2,     2,     2,   112,     2,
     118,   119,   109,   107,   120,   108,     2,   110,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   121,
       2,   114,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   122,     2,   123,   113,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   116,   111,   117,     2,     2,     2,     2,
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
     105,   106
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    18,    20,    22,
      24,    26,    28,    30,    39,    48,    54,    63,    69,    78,
      80,    89,    92,    97,   101,   103,   106,   109,   111,   113,
     115,   117,   119,   121,   124,   126,   130,   134,   136,   138,
     140,   142,   144,   146,   148,   154,   162,   168,   171,   177,
     181,   183,   185,   187,   191,   193,   197,   199,   203,   205,
     209,   211,   215,   217,   221,   223,   227,   229,   233,   235,
     239,   241,   245,   247,   251,   253,   257,   259,   263,   265,
     269,   271,   275,   277,   282,   287,   289,   291,   293,   295,
     298,   302,   304,   308,   310,   312,   314,   318,   320,   323,
     326,   328,   330,   332,   334,   336,   338,   340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     125,     0,    -1,   126,    -1,   127,    -1,   140,    -1,   126,
     127,    -1,   100,   128,   116,   140,   117,    -1,     3,    -1,
     130,    -1,   131,    -1,   133,    -1,   135,    -1,   137,    -1,
      14,   176,   118,   173,   119,   116,   140,   117,    -1,    15,
     176,   118,   132,   119,   116,   140,   117,    -1,   176,   176,
     120,   176,   176,    -1,    10,   176,   118,   134,   119,   116,
     140,   117,    -1,   176,   176,   120,   176,   176,    -1,    16,
     176,   118,   136,   119,   116,   140,   117,    -1,   176,    -1,
      35,   176,   118,   138,   119,   116,   140,   117,    -1,   176,
     176,    -1,   138,   120,   176,   176,    -1,   116,   140,   117,
      -1,   141,    -1,   140,   141,    -1,   101,     3,    -1,   142,
      -1,   146,    -1,   147,    -1,   139,    -1,   129,    -1,   148,
      -1,   143,   121,    -1,   144,    -1,   143,   120,   144,    -1,
     174,   145,   150,    -1,   150,    -1,   114,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,    98,    -1,    40,   118,
     143,   119,   141,    -1,    40,   118,   143,   119,   141,    41,
     141,    -1,    46,   118,   143,   119,   141,    -1,    31,   121,
      -1,    31,   118,   143,   119,   121,    -1,   118,   143,   119,
      -1,   171,    -1,   172,    -1,   151,    -1,   150,   107,   151,
      -1,   152,    -1,   151,   108,   152,    -1,   153,    -1,   152,
     109,   153,    -1,   154,    -1,   153,   110,   154,    -1,   155,
      -1,   154,    86,   155,    -1,   156,    -1,   155,    87,   156,
      -1,   157,    -1,   156,    88,   157,    -1,   158,    -1,   157,
      89,   158,    -1,   159,    -1,   158,    90,   159,    -1,   160,
      -1,   159,    81,   160,    -1,   161,    -1,   160,    83,   161,
      -1,   162,    -1,   161,    82,   162,    -1,   163,    -1,   162,
      84,   163,    -1,   164,    -1,   163,    80,   164,    -1,   165,
      -1,   164,    85,   165,    -1,   166,    -1,   176,   118,   170,
     119,    -1,   175,   118,   170,   119,    -1,   167,    -1,   174,
      -1,   149,    -1,   169,    -1,   168,   169,    -1,   122,   143,
     123,    -1,   144,    -1,   170,   120,   144,    -1,    91,    -1,
      99,    -1,   174,    -1,   173,   120,   174,    -1,   176,    -1,
     176,   168,    -1,    89,   176,    -1,   101,    -1,   102,    -1,
     103,    -1,   104,    -1,   105,    -1,   106,    -1,   177,    -1,
       3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    72,    73,    74,    78,    82,    94,    95,
      96,    97,    98,   102,   106,   110,   114,   118,   122,   126,
     130,   134,   135,   139,   143,   144,   148,   149,   150,   151,
     152,   153,   154,   158,   162,   163,   167,   168,   172,   173,
     174,   175,   176,   177,   181,   182,   186,   190,   191,   199,
     200,   201,   205,   206,   210,   211,   215,   216,   220,   221,
     225,   226,   230,   231,   235,   236,   240,   241,   245,   246,
     250,   251,   255,   256,   260,   261,   265,   266,   270,   271,
     275,   276,   280,   281,   282,   286,   287,   291,   303,   304,
     308,   312,   313,   318,   327,   335,   336,   340,   341,   342,
     346,   347,   348,   349,   350,   351,   354,   359
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "lower_case_identifier",
  "upper_case_identifier", "TYPE", "IS", "END", "SYMBOLIC", "RECORD",
  "NODE", "IN", "OUT", "INTO", "FUNC", "CONNECTION", "LAYER", "FROM", "TO",
  "ARRAY", "OF", "CONST", "VAR", "PROCEDURE", "EXTERNAL", "INCLUDED",
  "FUNCTION", "REDUCTION", "NEURAL", "WTA", "MERGE", "RETURN", "IOSTYLE",
  "CASE", "GROUP", "NETWORK", "KINDS", "IO_STYLE", "IOSPEC", "STYLE", "IF",
  "ELSE", "ELSEIF", "THEN", "REPEAT", "FOR", "WHILE", "UNTIL", "UPTO",
  "DOWNTO", "BREAK", "REPLICATE", "EXTEND", "BY", "CONNECT", "DISCONNECT",
  "OR", "XOR", "AND", "BITOR", "BITXOR", "BITAND", "LSHIFT", "RSHIFT",
  "MAXINDEX", "NOT", "BITNOT", "MIN", "MAX", "RANDOM", "ME", "YOU",
  "INDEX", "INPUT_ASSIGNMENT", "OUTPUT_ASSIGNMENT",
  "LESS_THEN_GREATHER_THEN", "LESS_THEN_EQUAL", "GREATHER_THEN_EQUAL",
  "ELIPSES", "EXPONENT_OPERATOR", "LOGICAL_EQ", "LOGICAL_LT",
  "LOGICAL_LT_EQ", "LOGICAL_GT", "LOGICAL_GT_EQ", "LOGICAL_NEQ",
  "LOGICAL_OR", "LOGICAL_AND", "INCLUSIVE_OR", "INCLUSIVE_AND",
  "LOGICAL_XOR", "INTEGER_DENOTER", "REAL_DENOTER", "EQUAL", "PLUS_EQUAL",
  "MINUS_EQUAL", "MULTIPLY_EQUAL", "DIVIDE_EQUAL", "MOD_EQUAL",
  "STRING_DENOTER", "PACKAGE", "PRINT", "SCAN", "READ", "WRITE", "OPEN",
  "CLOSE", "'+'", "'-'", "'*'", "'/'", "'|'", "'&'", "'^'", "'='", "'!'",
  "'{'", "'}'", "'('", "')'", "','", "';'", "'['", "']'", "$accept",
  "root", "nsmart_program", "nsmart_package", "package_name",
  "nsmart_procedure", "simple_procedure", "connection_procedure",
  "conn_parameter", "node_procedure", "node_parameter", "layer_procedure",
  "layer_parameter", "network_procedure", "network_parameter",
  "compound_statement", "statement_list", "statement",
  "expression_statement", "expression", "assignment_expression",
  "assign_operator", "selection", "itiration", "return_statement", "e1",
  "e2", "e3", "e4", "e5", "e6", "e7", "e8", "e9", "e10", "e11", "e12",
  "e13", "e14", "e15", "e16", "e17", "e18", "e19", "array_exp_list",
  "array_exp", "argument_expression_list", "number", "literal_string",
  "object_parameter", "object_category", "const_proc_object", "object",
  "object_name", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,    43,    45,    42,
      47,   124,    38,    94,    61,    33,   123,   125,    40,    41,
      44,    59,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   124,   125,   126,   126,   126,   127,   128,   129,   129,
     129,   129,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   138,   139,   140,   140,   141,   141,   141,   141,
     141,   141,   141,   142,   143,   143,   144,   144,   145,   145,
     145,   145,   145,   145,   146,   146,   147,   148,   148,   149,
     149,   149,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156,   157,   157,   158,   158,
     159,   159,   160,   160,   161,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   165,   166,   166,   167,   168,   168,
     169,   170,   170,   171,   172,   173,   173,   174,   174,   174,
     175,   175,   175,   175,   175,   175,   176,   177
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     5,     1,     1,     1,
       1,     1,     1,     8,     8,     5,     8,     5,     8,     1,
       8,     2,     4,     3,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     5,     2,     5,     3,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     4,     4,     1,     1,     1,     1,     2,
       3,     1,     3,     1,     1,     1,     3,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,     0,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     2,     3,    31,     8,     9,    10,    11,
      12,    30,     4,    24,    27,     0,    34,    28,    29,    32,
      87,    37,    52,    54,    56,    58,    60,    62,    64,    66,
      68,    70,    72,    74,    76,    78,    80,    82,    85,    50,
      51,    86,     0,    97,   106,     0,     0,     0,     0,     0,
      47,     0,     0,     0,    99,     7,     0,    26,     0,   100,
       0,     1,     5,    25,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    38,     0,     0,     0,
       0,    98,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    49,    35,    53,    86,    55,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    75,    77,    79,
      81,    36,    91,     0,     0,     0,    89,     0,     0,     0,
      95,    97,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    84,     0,    83,    90,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    21,    44,    46,     6,
      92,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    45,
      16,    17,    13,    14,    15,    18,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    76,    25,    26,    27,   152,    28,
     147,    29,   154,    30,   157,    31,    32,    33,    34,    35,
      36,   107,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   111,   112,   143,    59,    60,   149,
      61,    62,    63,    64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
      26,   -93,     6,     6,     6,     6,   -90,     6,   -91,   -58,
       6,   -93,   -93,    59,    68,   -93,   -93,   -93,   -93,   -93,
     490,   438,    77,   -22,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   490,   -93,   -93,   -83,   -93,   -93,   -93,   -93,
     -93,   -27,   -26,   -28,   -25,    -3,    -1,    -4,     2,     0,
       7,     4,    13,    12,    17,    14,   -93,   -93,   -93,   -93,
     -93,   -51,   -20,   -92,   -93,   -18,   -16,   -15,   -14,   438,
     -93,   -12,   438,   438,   -93,   -93,   -11,   -93,   186,   -93,
     -70,   -93,   -93,   -93,   438,   -93,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   -93,   -93,   -93,   -93,   -93,   -93,   438,   438,   438,
     438,   -21,   -93,     6,     3,     6,     6,   -66,     6,   -61,
     -55,   490,   -93,   -93,   -93,   -26,   -93,   -28,   -25,    -3,
      -1,    -4,     2,     0,     7,     4,    13,    12,    17,    14,
     -93,   -27,   -93,   -52,   -50,   -72,   -93,   -10,     6,   -46,
     -93,   -21,    -9,     6,     5,   -93,    15,   -44,     6,   490,
     490,   208,   -93,   438,   -93,   -93,    18,    19,    21,     3,
      22,    20,    25,   -93,    27,     6,   -93,    66,   -93,   -93,
     -93,   490,     6,   490,   -93,   490,     6,   490,   490,     6,
     490,   230,     6,   327,   349,     6,   371,   468,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,    95,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -13,     1,   -93,   -17,
     -74,   -93,   -93,   -93,   -93,   -93,    16,    33,    34,    32,
      44,    45,    31,    53,    54,    55,    57,    52,    56,    60,
      51,    63,   -93,   -93,   -93,    43,    46,   -93,   -93,   -93,
     -75,   -93,    -2,   -93
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      65,    66,    67,    68,    80,    71,     1,    78,    74,     1,
     124,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   109,    72,    69,     1,
     110,    70,   126,    83,   142,   142,     2,    84,    85,   150,
       3,     4,     5,   101,   102,   103,   104,   105,    84,   123,
      84,   165,   117,   156,    84,   119,   120,     6,   159,    84,
      73,     7,    75,   106,   160,    84,     8,   162,   163,   164,
     163,    77,     9,   168,   169,   174,   175,    81,    13,    83,
      86,    88,    87,    90,    92,    89,    91,    96,    95,   180,
      94,    93,    10,   145,   184,    97,    98,    99,   108,   100,
     113,   110,   114,   115,   116,   121,   118,   190,   161,   166,
     170,   148,   151,   153,   155,    10,   158,    11,    82,   125,
     128,   127,   131,   141,   172,    12,    13,    14,    15,    16,
      17,    18,    19,   129,   181,   130,   173,   183,   185,   182,
     186,   187,    20,   188,    21,   132,   167,   133,   136,   134,
     139,   171,   135,   137,   146,   144,   176,     0,   138,     0,
     177,   178,    83,   140,     0,     0,     0,   151,   191,     0,
     193,     0,   194,   189,   196,   197,     0,     0,     0,     0,
     192,     0,     0,     0,   195,     0,     0,   198,     0,     1,
     201,   199,    83,   204,    83,    83,     2,    83,    83,     0,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     6,     2,     0,
       0,     7,     3,     4,     5,     0,     8,     0,     0,     0,
       0,     0,     9,     1,     0,     0,     0,     0,     0,     6,
       2,     0,     0,     7,     3,     4,     5,     0,     8,     0,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     7,     0,     0,     0,     0,
       8,     0,     0,     0,     0,    10,     9,    11,     0,     0,
       0,     0,     0,     0,     0,    12,     0,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,    10,     0,    11,
       0,     0,    20,   122,    21,     0,     0,    12,     0,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,    10,
       0,    11,     0,     0,    20,   179,    21,     0,     0,    12,
       1,    14,    15,    16,    17,    18,    19,     2,     0,     0,
       0,     3,     4,     5,     0,     0,    20,   200,    21,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     6,     2,
       0,     0,     7,     3,     4,     5,     0,     8,     0,     0,
       0,     0,     0,     9,     1,     0,     0,     0,     0,     0,
       6,     2,     0,     0,     7,     3,     4,     5,     0,     8,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     7,     0,     0,     0,
       0,     8,     0,     0,     0,     0,    10,     9,    11,     0,
       0,     0,     0,     0,     0,     0,    12,     0,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,    10,     0,
      11,     1,     0,    20,   202,    21,     0,     0,    12,     0,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
      10,     0,    11,     0,     0,    20,   203,    21,     0,     0,
      12,     1,    14,    15,    16,    17,    18,    19,     2,     0,
       0,     0,     3,     4,     5,     0,     0,    20,   205,    21,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     6,
       2,     0,     0,     7,     3,     4,     5,     0,     8,     0,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     7,     0,    10,     0,    11,
       8,     0,     0,     0,     0,     0,     9,    12,     0,    79,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    10,     0,    11,
       0,     0,     0,     0,     0,     0,     0,    12,     0,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,    10,
       0,    11,     0,     0,    20,   206,    21,     0,     0,    12,
       0,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,    21
};

static const yytype_int16 yycheck[] =
{
       2,     3,     4,     5,    21,     7,     3,    20,    10,     3,
      84,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   118,   118,   118,     3,
     122,   121,   107,    32,   108,   109,    10,   120,   121,   114,
      14,    15,    16,    94,    95,    96,    97,    98,   120,   119,
     120,   123,    69,   119,   120,    72,    73,    31,   119,   120,
     118,    35,     3,   114,   119,   120,    40,   119,   120,   119,
     120,     3,    46,   119,   120,   119,   120,     0,   100,    78,
     107,   109,   108,    86,    88,   110,    87,    83,    81,   163,
      90,    89,    89,   110,   169,    82,    84,    80,   118,    85,
     118,   122,   118,   118,   118,   116,   118,    41,   121,   119,
     119,   113,   114,   115,   116,    89,   118,    91,    23,    86,
      88,    87,    91,   107,   119,    99,   100,   101,   102,   103,
     104,   105,   106,    89,   116,    90,   121,   116,   116,   120,
     120,   116,   116,   116,   118,    92,   148,    93,    96,    94,
      99,   153,    95,    97,   111,   109,   158,    -1,    98,    -1,
     159,   160,   161,   100,    -1,    -1,    -1,   169,   181,    -1,
     183,    -1,   185,   175,   187,   188,    -1,    -1,    -1,    -1,
     182,    -1,    -1,    -1,   186,    -1,    -1,   189,    -1,     3,
     192,   190,   191,   195,   193,   194,    10,   196,   197,    -1,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    31,    10,    -1,
      -1,    35,    14,    15,    16,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,     3,    -1,    -1,    -1,    -1,    -1,    31,
      10,    -1,    -1,    35,    14,    15,    16,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    89,    46,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,
     104,   105,   106,    -1,    -1,    -1,    -1,    89,    -1,    91,
      -1,    -1,   116,   117,   118,    -1,    -1,    99,    -1,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    89,
      -1,    91,    -1,    -1,   116,   117,   118,    -1,    -1,    99,
       3,   101,   102,   103,   104,   105,   106,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,   116,   117,   118,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    31,    10,
      -1,    -1,    35,    14,    15,    16,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,     3,    -1,    -1,    -1,    -1,    -1,
      31,    10,    -1,    -1,    35,    14,    15,    16,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    89,    46,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    89,    -1,
      91,     3,    -1,   116,   117,   118,    -1,    -1,    99,    -1,
     101,   102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
      89,    -1,    91,    -1,    -1,   116,   117,   118,    -1,    -1,
      99,     3,   101,   102,   103,   104,   105,   106,    10,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,   116,   117,   118,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    31,
      10,    -1,    -1,    35,    14,    15,    16,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    35,    -1,    89,    -1,    91,
      40,    -1,    -1,    -1,    -1,    -1,    46,    99,    -1,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    89,
      -1,    91,    -1,    -1,   116,   117,   118,    -1,    -1,    99,
      -1,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    14,    15,    16,    31,    35,    40,    46,
      89,    91,    99,   100,   101,   102,   103,   104,   105,   106,
     116,   118,   125,   126,   127,   129,   130,   131,   133,   135,
     137,   139,   140,   141,   142,   143,   144,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   171,
     172,   174,   175,   176,   177,   176,   176,   176,   176,   118,
     121,   176,   118,   118,   176,     3,   128,     3,   140,   101,
     143,     0,   127,   141,   120,   121,   107,   108,   109,   110,
      86,    87,    88,    89,    90,    81,    83,    82,    84,    80,
      85,    94,    95,    96,    97,    98,   114,   145,   118,   118,
     122,   168,   169,   118,   118,   118,   118,   143,   118,   143,
     143,   116,   117,   119,   144,   151,   174,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   150,   144,   170,   170,   143,   169,   134,   176,   173,
     174,   176,   132,   176,   136,   176,   119,   138,   176,   119,
     119,   140,   119,   120,   119,   123,   119,   176,   119,   120,
     119,   176,   119,   121,   119,   120,   176,   141,   141,   117,
     144,   116,   120,   116,   174,   116,   120,   116,   116,   176,
      41,   140,   176,   140,   140,   176,   140,   140,   176,   141,
     117,   176,   117,   117,   176,   117,   117
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 69 "nsmart.y"
    {(yyval.op) = create_root_op((yyvsp[(1) - (1)].op));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 72 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 73 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 74 "nsmart.y"
    {(yyval.op) = create_program_op((yyvsp[(1) - (2)].op), (yyvsp[(2) - (2)].op));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 78 "nsmart.y"
    {(yyval.op) = create_package_op((yyvsp[(2) - (5)].op),(yyvsp[(4) - (5)].op));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 83 "nsmart.y"
    { 
			CONST_VAL	value;
			value.type = SYM_TYPE_STRING;
			value.u.s_val = create_const_str_value(literal);	
			(yyval.op) = create_const_op(value);
		;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 94 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 95 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 96 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 97 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 98 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 102 "nsmart.y"
    {(yyval.op) = create_simple_proc((yyvsp[(2) - (8)].op),(yyvsp[(4) - (8)].op),(yyvsp[(7) - (8)].op));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 106 "nsmart.y"
    {(yyval.op) = create_conn_proc((yyvsp[(2) - (8)].op),(yyvsp[(4) - (8)].op),(yyvsp[(7) - (8)].op));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 110 "nsmart.y"
    {(yyval.op) = create_conn_param((yyvsp[(1) - (5)].op),(yyvsp[(2) - (5)].op),(yyvsp[(4) - (5)].op),(yyvsp[(5) - (5)].op));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 114 "nsmart.y"
    {(yyval.op) = create_node_proc((yyvsp[(2) - (8)].op),(yyvsp[(4) - (8)].op),(yyvsp[(7) - (8)].op));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 118 "nsmart.y"
    { (yyval.op) = create_node_param((yyvsp[(1) - (5)].op),(yyvsp[(2) - (5)].op),(yyvsp[(4) - (5)].op),(yyvsp[(5) - (5)].op));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 122 "nsmart.y"
    {(yyval.op) = create_layer_proc((yyvsp[(2) - (8)].op), (yyvsp[(4) - (8)].op), (yyvsp[(7) - (8)].op));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 126 "nsmart.y"
    { (yyval.op) = create_layer_param((yyvsp[(1) - (1)].op));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 130 "nsmart.y"
    {(yyval.op) = create_network_proc((yyvsp[(2) - (8)].op),(yyvsp[(4) - (8)].op),(yyvsp[(7) - (8)].op));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 134 "nsmart.y"
    { (yyval.op) = create_network_param((yyvsp[(1) - (2)].op),(yyvsp[(2) - (2)].op));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 135 "nsmart.y"
    { (yyval.op) = create_network_param_list((yyvsp[(1) - (4)].op),(yyvsp[(3) - (4)].op),(yyvsp[(4) - (4)].op));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 139 "nsmart.y"
    {(yyval.op) = (yyvsp[(2) - (3)].op);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 143 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 144 "nsmart.y"
    {(yyval.op) = create_statement_list_op((yyvsp[(1) - (2)].op),(yyvsp[(2) - (2)].op));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 148 "nsmart.y"
    {(yyval.op) = create_op();;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 149 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 150 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 151 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 152 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 153 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 154 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 158 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (2)].op);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 162 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 163 "nsmart.y"
    { (yyval.op) = create_expression_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 167 "nsmart.y"
    {(yyval.op) = create_assign_op((yyvsp[(1) - (3)].op),(yyvsp[(2) - (3)].t_uint),(yyvsp[(3) - (3)].op));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 168 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 172 "nsmart.y"
    { (yyval.t_uint) = EQUAL_TO;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 173 "nsmart.y"
    { (yyval.t_uint) = PLUS_EQUAL_TO;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 174 "nsmart.y"
    { (yyval.t_uint) = MINUS_EQUAL_TO;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 175 "nsmart.y"
    { (yyval.t_uint) = MULTIPLY_EQUAL_TO;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 176 "nsmart.y"
    { (yyval.t_uint) = DIVIDE_EQUAL_TO; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 177 "nsmart.y"
    { (yyval.t_uint) = MOD_EQUAL_TO;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 181 "nsmart.y"
    {(yyval.op) = create_if_op((yyvsp[(3) - (5)].op),(yyvsp[(5) - (5)].op));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 182 "nsmart.y"
    {(yyval.op) = create_if_else_op((yyvsp[(3) - (7)].op),(yyvsp[(5) - (7)].op),(yyvsp[(7) - (7)].op));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 186 "nsmart.y"
    {(yyval.op) = create_while_op((yyvsp[(3) - (5)].op),(yyvsp[(5) - (5)].op));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 190 "nsmart.y"
    {(yyval.op) = create_return_stmt_op(NULL);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 191 "nsmart.y"
    {(yyval.op) = create_return_stmt_op((yyvsp[(3) - (5)].op));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 199 "nsmart.y"
    {(yyval.op) = (yyvsp[(2) - (3)].op);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 200 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 201 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 205 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 206 "nsmart.y"
    {(yyval.op) = create_add_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 210 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 211 "nsmart.y"
    {(yyval.op) = create_sub_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 215 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 216 "nsmart.y"
    {(yyval.op) = create_mult_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 220 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 221 "nsmart.y"
    {(yyval.op) = create_div_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 225 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 226 "nsmart.y"
    { (yyval.op) = create_logical_or_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 230 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 231 "nsmart.y"
    { (yyval.op) = create_logical_and_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 235 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 236 "nsmart.y"
    { (yyval.op) = create_inclusive_or_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 240 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 241 "nsmart.y"
    { (yyval.op) = create_inclusive_and_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 246 "nsmart.y"
    { (yyval.op) = create_exclusive_or_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 250 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 251 "nsmart.y"
    { (yyval.op) = create_lt_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 255 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 256 "nsmart.y"
    { (yyval.op) = create_gt_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 260 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 261 "nsmart.y"
    { (yyval.op) = create_lt_eq_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 265 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 266 "nsmart.y"
    { (yyval.op) = create_gt_eq_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 270 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 271 "nsmart.y"
    { (yyval.op) = create_eq_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 275 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 276 "nsmart.y"
    { (yyval.op) = create_neq_op((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 280 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 281 "nsmart.y"
    {(yyval.op) = create_proc_call((yyvsp[(1) - (4)].op),(yyvsp[(3) - (4)].op));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 282 "nsmart.y"
    {(yyval.op) = create_const_proc_call((yyvsp[(1) - (4)].op),(yyvsp[(3) - (4)].op));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 286 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 287 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 291 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 303 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 304 "nsmart.y"
    {(yyval.op) = create_array_exp_list_op((yyvsp[(1) - (2)].op),(yyvsp[(2) - (2)].op));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 308 "nsmart.y"
    { (yyval.op) = create_array_exp_op((yyvsp[(2) - (3)].op));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 312 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 313 "nsmart.y"
    {(yyval.op) = create_param_expression_list((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 318 "nsmart.y"
    { 
				CONST_VAL	value;
				value.type = SYM_TYPE_INT;
				value.u.i_val =   atoi(literal); 
				(yyval.op) = create_const_op(value);
			;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 327 "nsmart.y"
    {
			CONST_VAL value;
			value.type = SYM_TYPE_STRING;
			value.u.s_val = create_const_str_value(literal);
			(yyval.op) = create_const_op(value);
		;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 335 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 336 "nsmart.y"
    {(yyval.op) = create_proc_param((yyvsp[(1) - (3)].op),(yyvsp[(3) - (3)].op));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 340 "nsmart.y"
    {(yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 341 "nsmart.y"
    {(yyval.op) = create_obj_array((yyvsp[(1) - (2)].op),(yyvsp[(2) - (2)].op));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 342 "nsmart.y"
    {(yyval.op) = update_as_ref_const_op((yyvsp[(2) - (2)].op));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 346 "nsmart.y"
    { (yyval.op) = create_const_object_print_op();;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 347 "nsmart.y"
    { (yyval.op) = create_const_object_scan_op();;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 348 "nsmart.y"
    { (yyval.op) = create_const_object_read_op();;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 349 "nsmart.y"
    { (yyval.op) = create_const_object_write_op();;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 350 "nsmart.y"
    { (yyval.op) = create_const_object_open_op();;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 351 "nsmart.y"
    { (yyval.op) = create_const_object_close_op();;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 354 "nsmart.y"
    { (yyval.op) = (yyvsp[(1) - (1)].op);;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 360 "nsmart.y"
    { 
			CONST_VAL	value;
			value.type = SYM_TYPE_SYMBOL;
			value.u.s_val = create_const_str_value(literal);	
			(yyval.op) = create_const_op(value);
		;}
    break;



/* Line 1455 of yacc.c  */
#line 2504 "nsmart.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 369 "nsmart.y"

extern unsigned int line_num;
void yyerror(char *s)
{
	fprintf(stderr, "WHAT IS WRONG %s at line number %d\n", s, line_num);
}


	

