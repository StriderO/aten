/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTCONST = 258,
     ELEMENTCONST = 259,
     DOUBLECONST = 260,
     NEWTOKEN = 261,
     CHARCONST = 262,
     STEPTOKEN = 263,
     VAR = 264,
     LOCALVAR = 265,
     FUNCCALL = 266,
     USERFUNCCALL = 267,
     VTYPE = 268,
     DO = 269,
     WHILE = 270,
     FOR = 271,
     IF = 272,
     RETURN = 273,
     FILTERBLOCK = 274,
     HELP = 275,
     DIOV = 276,
     DUMMY = 277,
     ELSE = 278,
     OR = 279,
     AND = 280,
     DEQ = 281,
     TEQ = 282,
     MEQ = 283,
     PEQ = 284,
     NEQ = 285,
     EQ = 286,
     LEQ = 287,
     GEQ = 288,
     UMINUS = 289,
     MM = 290,
     PP = 291
   };
#endif
/* Tokens.  */
#define INTCONST 258
#define ELEMENTCONST 259
#define DOUBLECONST 260
#define NEWTOKEN 261
#define CHARCONST 262
#define STEPTOKEN 263
#define VAR 264
#define LOCALVAR 265
#define FUNCCALL 266
#define USERFUNCCALL 267
#define VTYPE 268
#define DO 269
#define WHILE 270
#define FOR 271
#define IF 272
#define RETURN 273
#define FILTERBLOCK 274
#define HELP 275
#define DIOV 276
#define DUMMY 277
#define ELSE 278
#define OR 279
#define AND 280
#define DEQ 281
#define TEQ 282
#define MEQ 283
#define PEQ 284
#define NEQ 285
#define EQ 286
#define LEQ 287
#define GEQ 288
#define UMINUS 289
#define MM 290
#define PP 291




/* Copy the first part of user declarations.  */
#line 4 "grammar.yy"


/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "command/commands.h"
#include "parser/parser.h"
#include "parser/tree.h"

/* Prototypes */
int yylex(void);
void yyerror(char *s);

/* Local Variables */
Dnchar tokenName;
Dnchar stepName;
Dnchar varName;
VTypes::DataType declaredType;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "grammar.yy"
{
	int functionId;			/* Function enum id */
	Dnchar *name;			/* character pointer for names */
	TreeNode *node;			/* node pointer */
	Variable *variable;		/* variable pointer */
	Tree *functree;			/* user-defined function (tree) pointer */
	VTypes::DataType vtype;		/* variable type for next declarations */
	int intconst;			/* integer constant value */
	double doubleconst;		/* double constant value */
}
/* Line 187 of yacc.c.  */
#line 201 "grammar.cc"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 214 "grammar.cc"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   875

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,    41,     2,     2,
      51,    52,    39,    37,    50,    38,    55,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
      32,    26,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      25,    27,    28,    29,    30,    33,    34,    35,    36,    42,
      43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     9,    11,    13,    19,    22,
      23,    24,    26,    29,    32,    34,    36,    41,    48,    55,
      56,    58,    61,    64,    66,    69,    71,    73,    81,    87,
      98,   105,   113,   115,   117,   119,   121,   123,   125,   134,
     143,   144,   146,   150,   155,   162,   163,   165,   169,   173,
     176,   179,   183,   187,   191,   195,   200,   204,   208,   215,
     222,   224,   227,   230,   234,   238,   244,   250,   252,   254,
     258,   261,   263,   268,   270,   275,   277,   278,   283,   286,
     288,   292,   295,   297,   299,   301,   303,   307,   311,   315,
     319,   323,   327,   331,   334,   337,   340,   343,   346,   348,
     352,   356,   360,   364,   368,   372,   376,   380,   384,   388,
     392,   396,   400,   404,   408,   411,   413,   417,   421,   426,
     428,   433,   437,   439,   440,   441,   442,   443
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    -1,    58,    -1,    57,    58,    -1,    62,
      -1,    65,    -1,    47,    60,    62,    48,    61,    -1,    47,
      48,    -1,    -1,    -1,    63,    -1,    62,    63,    -1,    67,
      49,    -1,    59,    -1,    69,    -1,     6,    91,    26,    70,
      -1,    64,    50,     6,    91,    26,    70,    -1,    19,    66,
      51,    64,    52,    59,    -1,    -1,    68,    -1,    20,    11,
      -1,    18,    86,    -1,    18,    -1,    67,    68,    -1,    79,
      -1,    86,    -1,    17,    51,    86,    52,    63,    23,    63,
      -1,    17,    51,    86,    52,    63,    -1,    16,    60,    51,
      68,    49,    86,    49,    86,    52,    63,    -1,    15,    60,
      51,    86,    52,    63,    -1,    14,    60,    63,    15,    51,
      86,    52,    -1,    71,    -1,    72,    -1,     3,    -1,     5,
      -1,     7,    -1,     4,    -1,    13,    92,     6,    51,    75,
      73,    52,    59,    -1,    21,    93,     6,    51,    75,    73,
      52,    59,    -1,    -1,    74,    -1,    73,    50,    74,    -1,
      13,    92,     6,    91,    -1,    13,    92,     6,    91,    26,
      86,    -1,    -1,    77,    -1,    76,    50,    77,    -1,    76,
      50,    70,    -1,    76,    77,    -1,    76,     1,    -1,    76,
      50,    11,    -1,    76,    50,    10,    -1,    76,    50,    12,
      -1,    76,    50,    13,    -1,    78,    53,    86,    54,    -1,
      78,    26,    86,    -1,    78,    26,    88,    -1,    78,    53,
      86,    54,    26,    86,    -1,    78,    53,    86,    54,    26,
      88,    -1,    78,    -1,     9,    94,    -1,     6,    91,    -1,
      13,    92,    76,    -1,    13,    92,     1,    -1,     8,    95,
      53,    86,    54,    -1,     8,    95,    53,    70,    54,    -1,
       8,    -1,    80,    -1,    81,    55,    80,    -1,    81,     1,
      -1,    83,    -1,     9,    53,    86,    54,    -1,     9,    -1,
      10,    53,    86,    54,    -1,    10,    -1,    -1,    83,    55,
      84,    81,    -1,    83,    51,    -1,    86,    -1,    85,    50,
      86,    -1,    85,    86,    -1,    87,    -1,    70,    -1,    89,
      -1,    90,    -1,    82,    26,    86,    -1,    82,    26,    88,
      -1,    82,    26,     1,    -1,    82,    30,    86,    -1,    82,
      29,    86,    -1,    82,    28,    86,    -1,    82,    27,    86,
      -1,    38,    86,    -1,    82,    44,    -1,    82,    43,    -1,
      44,    82,    -1,    43,    82,    -1,    82,    -1,    86,    37,
      86,    -1,    86,    38,    86,    -1,    86,    39,    86,    -1,
      86,    40,    86,    -1,    86,    46,    86,    -1,    86,    41,
      86,    -1,    86,    34,    86,    -1,    86,    33,    86,    -1,
      86,    31,    86,    -1,    86,    36,    86,    -1,    86,    32,
      86,    -1,    86,    35,    86,    -1,    86,    25,    86,    -1,
      86,    24,    86,    -1,    51,    86,    52,    -1,    45,    86,
      -1,     6,    -1,    47,    85,    48,    -1,    11,    51,    52,
      -1,    11,    51,    85,    52,    -1,    11,    -1,    12,    51,
      85,    52,    -1,    12,    51,    52,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    69,    73,    74,    80,    81,    85,
      89,    93,    94,    98,    99,   100,   106,   107,   111,   115,
     121,   122,   123,   124,   125,   129,   130,   134,   135,   136,
     137,   138,   139,   140,   146,   147,   148,   149,   156,   160,
     164,   165,   166,   170,   171,   175,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   193,   194,   195,   196,   197,
     198,   199,   203,   207,   208,   214,   215,   216,   220,   221,
     222,   226,   230,   231,   232,   233,   234,   234,   236,   242,
     243,   244,   248,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   290,   296,   297,   298,
     302,   303,   304,   310,   314,   318,   322,   326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONST", "ELEMENTCONST",
  "DOUBLECONST", "NEWTOKEN", "CHARCONST", "STEPTOKEN", "VAR", "LOCALVAR",
  "FUNCCALL", "USERFUNCCALL", "VTYPE", "DO", "WHILE", "FOR", "IF",
  "RETURN", "FILTERBLOCK", "HELP", "DIOV", "DUMMY", "ELSE", "OR", "AND",
  "'='", "DEQ", "TEQ", "MEQ", "PEQ", "'>'", "'<'", "NEQ", "EQ", "LEQ",
  "GEQ", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "MM", "PP", "'!'",
  "'^'", "'{'", "'}'", "';'", "','", "'('", "')'", "'['", "']'", "'.'",
  "$accept", "programlist", "program", "block", "pushscope", "popscope",
  "statementlist", "blockment", "optlist", "filter", "pushfilter",
  "statement", "decexpr", "fstatement", "constant", "userfuncdef",
  "userstatementdef", "args", "arg", "pushfunc", "namelist", "newname",
  "newvar", "declaration", "step", "steplist", "var", "rawvar", "@1",
  "exprlist", "expr", "rawexpr", "ARRAYCONST", "func", "userfunc",
  "savetokenname", "savetype", "cleartype", "savevarname", "savestepname", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    61,   281,   282,   283,
     284,    62,    60,   285,   286,   287,   288,    43,    45,    42,
      47,    37,   289,   290,   291,    33,    94,   123,   125,    59,
      44,    40,    41,    91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    62,    62,    63,    63,    63,    64,    64,    65,    66,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    71,    72,
      73,    73,    73,    74,    74,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    79,    80,    80,    80,    81,    81,
      81,    82,    83,    83,    83,    83,    84,    83,    83,    85,
      85,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    89,    89,    89,
      90,    90,    90,    91,    92,    93,    94,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     1,     1,     5,     2,     0,
       0,     1,     2,     2,     1,     1,     4,     6,     6,     0,
       1,     2,     2,     1,     2,     1,     1,     7,     5,    10,
       6,     7,     1,     1,     1,     1,     1,     1,     8,     8,
       0,     1,     3,     4,     6,     0,     1,     3,     3,     2,
       2,     3,     3,     3,     3,     4,     3,     3,     6,     6,
       1,     2,     2,     3,     3,     5,     5,     1,     1,     3,
       2,     1,     4,     1,     4,     1,     0,     4,     2,     1,
       3,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     3,     3,     4,     1,
       4,     3,     1,     0,     0,     0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    34,    37,    35,   115,    36,    73,    75,   119,   122,
     124,     9,     9,     9,     0,    23,    19,     0,   125,     0,
       0,     0,     0,     9,     0,     0,     3,    14,     5,    11,
       6,     0,    20,    15,    83,    32,    33,    25,    98,    71,
      26,    82,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,    21,     0,    93,    97,    96,
     114,     8,     0,     0,     1,     4,    12,   124,    13,    24,
       0,     0,     0,     0,     0,    95,    94,    78,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,     0,    79,   121,     0,
      64,   123,   126,     0,    46,    60,     0,     0,     0,     0,
       0,     0,     0,   113,     0,    88,     0,    86,    87,    92,
      91,    90,    89,     0,   112,   111,   107,   109,   106,   105,
     110,   108,    99,   100,   101,   102,   104,   103,    72,    74,
       0,   118,    81,   120,    45,    62,    61,    50,   123,     0,
      49,     0,     0,     0,     0,     0,     0,   123,     0,    45,
      10,     0,    67,    68,     0,    80,    40,    52,    51,    53,
      54,    48,    47,    56,    57,     0,     0,     0,     0,    28,
       0,     0,     0,    40,     7,   116,     0,    70,     0,   124,
       0,    41,    55,     0,    30,     0,     0,     0,   123,    18,
       0,     0,    69,     0,     0,     0,     0,    31,     0,    27,
      16,     0,     0,    83,     0,   123,    42,    38,    58,    59,
       0,     0,    39,    66,    65,    43,     0,    17,     0,    29,
      44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    49,   184,    28,    29,   158,    30,
      54,    31,    32,    33,    34,    35,    36,   190,   191,   166,
     103,   104,   105,    37,   163,   164,    38,    39,   123,    96,
      40,    41,   118,    42,    43,   145,    48,    56,   146,   186
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
     385,  -153,  -153,  -153,  -153,  -153,   -42,   -36,   -13,   -12,
    -153,  -153,  -153,  -153,    -1,     9,  -153,    22,  -153,     9,
      14,    14,     9,    30,     9,   244,  -153,  -153,   453,  -153,
    -153,   502,  -153,  -153,  -153,  -153,  -153,  -153,   381,    48,
     784,  -153,  -153,  -153,     9,     9,   325,   375,    39,   453,
       0,    11,     9,   784,    47,  -153,    84,    54,  -153,  -153,
      54,  -153,   453,   669,  -153,  -153,  -153,  -153,  -153,  -153,
     265,     9,     9,     9,     9,  -153,  -153,  -153,  -153,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,   573,   597,  -153,   295,   784,  -153,   314,
    -153,    53,  -153,   104,  -153,   -18,   107,     9,   551,   692,
     126,    83,   434,  -153,    82,  -153,     9,   818,  -153,   818,
     818,   818,   818,   127,   802,   802,    56,    56,    56,    56,
      56,    56,     3,     3,    54,    54,    54,    54,  -153,  -153,
       9,  -153,   784,  -153,  -153,  -153,  -153,  -153,  -153,   862,
    -153,   532,     9,    87,   715,    90,   453,  -153,    68,  -153,
    -153,   483,    88,  -153,   191,   784,   130,  -153,  -153,  -153,
    -153,  -153,  -153,   784,  -153,   621,     9,   453,     9,   117,
     118,   139,   105,   130,  -153,  -153,    98,  -153,   127,  -153,
      71,  -153,   131,   738,  -153,   141,   453,   123,  -153,  -153,
      81,     9,  -153,   150,   130,   105,   532,  -153,     9,  -153,
    -153,   132,   105,   106,   645,  -153,  -153,  -153,   784,  -153,
     761,   123,  -153,  -153,  -153,   133,   453,  -153,     9,  -153,
     784
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   137,   -93,    13,  -153,   102,   -27,  -153,  -153,
    -153,  -153,   -28,  -153,  -115,  -153,  -153,   -16,   -34,    12,
    -153,   -62,  -153,  -153,   -20,  -153,     7,  -153,  -153,   -37,
     -15,  -153,  -145,  -153,  -153,  -152,   -65,  -153,  -153,  -153
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -128
static const yytype_int16 yytable[] =
{
      53,    66,   114,    69,    57,   180,   174,    60,   151,    63,
      99,    44,     1,     2,     3,     4,     5,    45,     6,     7,
       8,     9,   106,     6,     7,    50,    51,    58,    59,    93,
      94,    97,    97,    55,   171,   152,    62,   109,    46,    47,
     100,   150,    89,    90,    91,   101,   211,    19,   102,    92,
      52,   107,    20,    21,    22,   117,   119,   120,   121,   122,
      24,   219,   108,   225,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    61,   161,
     155,   142,   210,   100,   142,    66,   213,   172,   148,   199,
     111,   102,   154,    87,    88,    89,    90,    91,   110,    77,
      92,    97,    92,    78,   144,   147,   227,   -63,   -63,   -63,
     148,   -63,   217,   102,   -63,   -63,   -63,   -63,   181,   222,
     182,   204,   153,   205,   203,   165,     1,     2,     3,   179,
       5,   204,   157,   212,   159,   162,   173,   175,   176,   178,
     196,  -127,   -63,   189,   197,   198,   142,   -63,   -63,   -63,
     194,   201,    23,   -63,   149,   -63,   215,   206,   221,   228,
     223,   193,    65,   195,   112,    79,    80,   200,   202,   209,
     216,   183,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,   214,    92,     0,     0,
     208,   218,   187,   220,   -77,   -77,   -77,   -77,   -77,   229,
     -77,   -77,   -77,   -77,   -77,     0,     0,     0,     0,     0,
       0,     0,     0,   230,     0,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,     0,   -77,   -77,   -77,   -77,     0,   -77,
     -77,   -77,   -77,   -77,    64,   -77,   188,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   115,     0,     1,     2,
       3,     4,     5,     0,     6,     7,     8,     9,     0,     0,
       0,     0,    19,     0,     0,     0,     0,    20,    21,    22,
       0,    23,     0,     0,     0,    24,     0,     0,     1,     2,
       3,     4,     5,    19,     6,     7,     8,     9,    20,    21,
      22,     0,   116,     0,     0,     0,    24,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,     0,     1,     2,
       3,     4,     5,    19,     6,     7,     8,     9,    20,    21,
      22,     0,     0,     0,     0,   140,    24,   141,     0,     0,
       0,     0,    19,     0,     0,     0,     0,    20,    21,    22,
       0,     0,     0,    19,   140,    24,   143,     0,    20,    21,
      22,     0,     0,     0,     0,     0,    24,    95,     1,     2,
       3,     4,     5,     0,     6,     7,     8,     9,     1,     2,
       3,     4,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    70,    71,    72,
      73,    74,     0,    19,     0,     0,     0,     0,    20,    21,
      22,     0,     0,    19,    75,    76,    24,    98,    20,    21,
      22,     0,    23,     0,     0,     0,    24,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    17,    18,     1,     2,     3,     4,
       5,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    19,    17,    18,     0,     0,    20,    21,    22,
       0,    23,   160,     0,     0,    24,     1,     2,     3,     4,
       5,    19,     6,     7,     8,     9,    20,    21,    22,     0,
      23,     0,     0,     0,    24,     1,     2,     3,     4,     5,
       0,     6,     7,     8,     9,    67,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,    21,    22,     0,
       0,   185,     0,   140,    24,     1,     2,     3,     4,     5,
      19,     6,     7,     8,     9,    20,    21,    22,     0,     0,
       0,    68,     0,    24,     1,     2,     3,     4,     5,     0,
       6,     7,     8,     9,    67,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    20,    21,    22,     0,   116,
       0,     0,     0,    24,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,    20,    21,    22,    79,    80,     0,
       0,     0,    24,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,    92,
       0,    79,    80,     0,     0,     0,     0,   138,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,    92,     0,    79,    80,     0,     0,     0,
       0,   139,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,    92,     0,    79,
      80,     0,     0,     0,     0,   192,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,    92,     0,    79,    80,     0,     0,     0,     0,   224,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,    92,    79,    80,     0,     0,
       0,   113,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,    92,    79,
      80,     0,     0,     0,   156,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,    92,    79,    80,     0,     0,     0,   177,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,    92,    79,    80,     0,     0,     0,
     207,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,    92,    79,    80,
       0,     0,     0,   226,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,  -128,  -128,     0,     0,
      92,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,    92,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,    92,     1,     2,     3,   148,     5,
       0,   102,   167,   168,   169,   170
};

static const yytype_int16 yycheck[] =
{
      15,    28,    67,    31,    19,   157,   151,    22,    26,    24,
      47,    53,     3,     4,     5,     6,     7,    53,     9,    10,
      11,    12,    49,     9,    10,    12,    13,    20,    21,    44,
      45,    46,    47,    11,   149,    53,    23,    52,    51,    51,
       1,   103,    39,    40,    41,     6,   198,    38,     9,    46,
      51,    51,    43,    44,    45,    70,    71,    72,    73,    74,
      51,   206,    51,   215,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    48,   116,
     108,    96,   197,     1,    99,   112,   201,   149,     6,   182,
       6,     9,   107,    37,    38,    39,    40,    41,    51,    51,
      46,   116,    46,    55,    51,     1,   221,     3,     4,     5,
       6,     7,   205,     9,    10,    11,    12,    13,    50,   212,
      52,    50,    15,    52,   189,   140,     3,     4,     5,   156,
       7,    50,     6,    52,    51,     8,   151,   152,    51,    49,
      23,    53,    38,    13,    26,     6,   161,    43,    44,    45,
     177,    53,    47,    49,    50,    51,     6,    26,    26,    26,
      54,   176,    25,   178,    62,    24,    25,   183,   188,   196,
     204,   159,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,   201,    46,    -1,    -1,
      49,   206,     1,   208,     3,     4,     5,     6,     7,   226,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   228,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,     0,    54,    55,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,    47,    -1,    -1,    -1,    51,    -1,    -1,     3,     4,
       5,     6,     7,    38,     9,    10,    11,    12,    43,    44,
      45,    -1,    47,    -1,    -1,    -1,    51,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    -1,     3,     4,
       5,     6,     7,    38,     9,    10,    11,    12,    43,    44,
      45,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,    -1,    -1,    38,    50,    51,    52,    -1,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    51,    52,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    26,    27,    28,
      29,    30,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,
      45,    -1,    -1,    38,    43,    44,    51,    52,    43,    44,
      45,    -1,    47,    -1,    -1,    -1,    51,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    38,    20,    21,    -1,    -1,    43,    44,    45,
      -1,    47,    48,    -1,    -1,    51,     3,     4,     5,     6,
       7,    38,     9,    10,    11,    12,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    51,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    48,    -1,    50,    51,     3,     4,     5,     6,     7,
      38,     9,    10,    11,    12,    43,    44,    45,    -1,    -1,
      -1,    49,    -1,    51,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,    47,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,    45,    24,    25,    -1,
      -1,    -1,    51,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,
      -1,    24,    25,    -1,    -1,    -1,    -1,    54,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    -1,    24,    25,    -1,    -1,    -1,
      -1,    54,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    24,
      25,    -1,    -1,    -1,    -1,    54,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    -1,    24,    25,    -1,    -1,    -1,    -1,    54,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    46,    24,    25,    -1,    -1,
      -1,    52,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    24,
      25,    -1,    -1,    -1,    52,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    24,    25,    -1,    -1,    -1,    52,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    46,    24,    25,    -1,    -1,    -1,
      52,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    24,    25,
      -1,    -1,    -1,    52,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    24,    25,    -1,    -1,
      46,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    46,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    38,
      43,    44,    45,    47,    51,    57,    58,    59,    62,    63,
      65,    67,    68,    69,    70,    71,    72,    79,    82,    83,
      86,    87,    89,    90,    53,    53,    51,    51,    92,    60,
      60,    60,    51,    86,    66,    11,    93,    86,    82,    82,
      86,    48,    60,    86,     0,    58,    63,    13,    49,    68,
      26,    27,    28,    29,    30,    43,    44,    51,    55,    24,
      25,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    46,    86,    86,    52,    85,    86,    52,    85,
       1,     6,     9,    76,    77,    78,    63,    51,    51,    86,
      51,     6,    62,    52,    92,     1,    47,    86,    88,    86,
      86,    86,    86,    84,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    54,    54,
      50,    52,    86,    52,    51,    91,    94,     1,     6,    50,
      77,    26,    53,    15,    86,    68,    52,     6,    64,    51,
      48,    85,     8,    80,    81,    86,    75,    10,    11,    12,
      13,    70,    77,    86,    88,    86,    51,    52,    49,    63,
      91,    50,    52,    75,    61,    48,    95,     1,    55,    13,
      73,    74,    54,    86,    63,    86,    23,    26,     6,    59,
      73,    53,    80,    92,    50,    52,    26,    52,    49,    63,
      70,    91,    52,    70,    86,     6,    74,    59,    86,    88,
      86,    26,    59,    54,    54,    91,    52,    70,    26,    63,
      86
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 67 "grammar.yy"
    { }
    break;

  case 3:
#line 68 "grammar.yy"
    { }
    break;

  case 4:
#line 69 "grammar.yy"
    { }
    break;

  case 5:
#line 73 "grammar.yy"
    { if (!cmdparser.addStatement((yyvsp[(1) - (1)].node))) YYABORT; }
    break;

  case 6:
#line 74 "grammar.yy"
    { }
    break;

  case 7:
#line 80 "grammar.yy"
    { (yyval.node) = cmdparser.joinCommands((yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node)); }
    break;

  case 8:
#line 81 "grammar.yy"
    { (yyval.node) = cmdparser.addFunction(Command::NoFunction); }
    break;

  case 9:
#line 85 "grammar.yy"
    { (yyval.node) = cmdparser.pushScope(); if ((yyval.node) == NULL) YYABORT; }
    break;

  case 10:
#line 89 "grammar.yy"
    { if (!cmdparser.popScope()) YYABORT; }
    break;

  case 11:
#line 93 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:
#line 94 "grammar.yy"
    { (yyval.node) = cmdparser.joinCommands((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 13:
#line 98 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 14:
#line 99 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 15:
#line 100 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); if ((yyval.node) == NULL) YYABORT; }
    break;

  case 16:
#line 106 "grammar.yy"
    { if (!cmdparser.setFilterOption(&tokenName, (yyvsp[(4) - (4)].node))) YYABORT; }
    break;

  case 17:
#line 107 "grammar.yy"
    { if (!cmdparser.setFilterOption(&tokenName, (yyvsp[(6) - (6)].node))) YYABORT; }
    break;

  case 18:
#line 111 "grammar.yy"
    { if (!cmdparser.addStatement((yyvsp[(6) - (6)].node))) YYABORT; cmdparser.popTree(); }
    break;

  case 19:
#line 115 "grammar.yy"
    { cmdparser.pushTree(TRUE); }
    break;

  case 20:
#line 121 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 21:
#line 122 "grammar.yy"
    { (yyval.node) = cmdparser.addFunction(Command::Help, cmdparser.addConstant((yyvsp[(2) - (2)].functionId))); }
    break;

  case 22:
#line 123 "grammar.yy"
    { (yyval.node) = cmdparser.addFunction(Command::Return,(yyvsp[(2) - (2)].node)); }
    break;

  case 23:
#line 124 "grammar.yy"
    { (yyval.node) = cmdparser.addFunction(Command::Return); }
    break;

  case 24:
#line 125 "grammar.yy"
    { msg.print("Error: Expected ';' before current expression.\n"); YYABORT; }
    break;

  case 25:
#line 129 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 26:
#line 130 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 27:
#line 134 "grammar.yy"
    { (yyval.node) = cmdparser.addFunction(Command::If,(yyvsp[(3) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(7) - (7)].node)); }
    break;

  case 28:
#line 135 "grammar.yy"
    { (yyval.node) = cmdparser.addFunction(Command::If,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)); }
    break;

  case 29:
#line 136 "grammar.yy"
    { (yyval.node) = cmdparser.joinCommands((yyvsp[(2) - (10)].node), cmdparser.addFunction(Command::For, (yyvsp[(4) - (10)].node),(yyvsp[(6) - (10)].node),(yyvsp[(8) - (10)].node),(yyvsp[(10) - (10)].node))); cmdparser.popScope(); }
    break;

  case 30:
#line 137 "grammar.yy"
    { (yyval.node) = cmdparser.joinCommands((yyvsp[(2) - (6)].node), cmdparser.addFunction(Command::While, (yyvsp[(4) - (6)].node),(yyvsp[(6) - (6)].node))); cmdparser.popScope(); }
    break;

  case 31:
#line 138 "grammar.yy"
    { (yyval.node) = cmdparser.joinCommands((yyvsp[(2) - (7)].node), cmdparser.addFunction(Command::DoWhile, (yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node))); cmdparser.popScope(); }
    break;

  case 32:
#line 139 "grammar.yy"
    { if (!cmdparser.addStatement((yyvsp[(1) - (1)].node))) YYABORT; }
    break;

  case 33:
#line 140 "grammar.yy"
    { if (!cmdparser.addStatement((yyvsp[(1) - (1)].node))) YYABORT; }
    break;

  case 34:
#line 146 "grammar.yy"
    { (yyval.node) = cmdparser.addConstant((yyvsp[(1) - (1)].intconst)); }
    break;

  case 35:
#line 147 "grammar.yy"
    { (yyval.node) = cmdparser.addConstant((yyvsp[(1) - (1)].doubleconst)); }
    break;

  case 36:
#line 148 "grammar.yy"
    { (yyval.node) = cmdparser.addConstant((yyvsp[(1) - (1)].name)->get()); }
    break;

  case 37:
#line 149 "grammar.yy"
    { (yyval.node) = cmdparser.addElementConstant((yyvsp[(1) - (1)].intconst)); }
    break;

  case 38:
#line 156 "grammar.yy"
    { if (!cmdparser.addStatement((yyvsp[(8) - (8)].node))) YYABORT; (yyval.node) = cmdparser.addFunction(Command::NoFunction); cmdparser.popTree(); declaredType = VTypes::NoData; }
    break;

  case 39:
#line 160 "grammar.yy"
    { if (!cmdparser.addStatement((yyvsp[(8) - (8)].node))) YYABORT; (yyval.node) = cmdparser.addFunction(Command::NoFunction); cmdparser.popTree(); declaredType = VTypes::NoData; }
    break;

  case 40:
#line 164 "grammar.yy"
    { }
    break;

  case 41:
#line 165 "grammar.yy"
    { }
    break;

  case 42:
#line 166 "grammar.yy"
    { }
    break;

  case 43:
#line 170 "grammar.yy"
    { (yyval.node) = cmdparser.addVariableAsArgument(declaredType, &tokenName); }
    break;

  case 44:
#line 171 "grammar.yy"
    { (yyval.node) = cmdparser.addVariableAsArgument(declaredType, &tokenName, (yyvsp[(6) - (6)].node)); }
    break;

  case 45:
#line 175 "grammar.yy"
    { cmdparser.pushFunction(yylval.name->get(), declaredType); }
    break;

  case 46:
#line 181 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); if ((yyvsp[(1) - (1)].node) == NULL) YYABORT; }
    break;

  case 47:
#line 182 "grammar.yy"
    { if ((yyvsp[(3) - (3)].node) == NULL) YYABORT; (yyval.node) = Tree::joinArguments((yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node)); }
    break;

  case 48:
#line 183 "grammar.yy"
    { msg.print("Error: Constant value found in declaration.\n"); YYABORT; }
    break;

  case 49:
#line 184 "grammar.yy"
    { msg.print("Error: Missing comma between declarations?\n"); YYABORT; }
    break;

  case 50:
#line 185 "grammar.yy"
    { YYABORT; }
    break;

  case 51:
#line 186 "grammar.yy"
    { msg.print("Error: Existing function name cannot be redeclared as a variable.\n"); YYABORT; }
    break;

  case 52:
#line 187 "grammar.yy"
    { msg.print("Error: Existing variable in local scope cannot be redeclared.\n"); YYABORT; }
    break;

  case 53:
#line 188 "grammar.yy"
    { msg.print("Error: Existing user-defined function name cannot be redeclared.\n"); YYABORT; }
    break;

  case 54:
#line 189 "grammar.yy"
    { msg.print("Error: Type-name used in variable declaration.\n"); YYABORT; }
    break;

  case 55:
#line 193 "grammar.yy"
    { (yyval.node) = cmdparser.addArrayVariable(declaredType, &tokenName, (yyvsp[(3) - (4)].node)); }
    break;

  case 56:
#line 194 "grammar.yy"
    { (yyval.node) = cmdparser.addVariable(declaredType, &tokenName, (yyvsp[(3) - (3)].node)); }
    break;

  case 57:
#line 195 "grammar.yy"
    { (yyval.node) = cmdparser.addVariable(declaredType, &tokenName, (yyvsp[(3) - (3)].node)); }
    break;

  case 58:
#line 196 "grammar.yy"
    { (yyval.node) = cmdparser.addArrayVariable(declaredType, &tokenName,(yyvsp[(3) - (6)].node),(yyvsp[(6) - (6)].node)); }
    break;

  case 59:
#line 197 "grammar.yy"
    { (yyval.node) = cmdparser.addArrayVariable(declaredType, &tokenName,(yyvsp[(3) - (6)].node),(yyvsp[(6) - (6)].node)); }
    break;

  case 60:
#line 198 "grammar.yy"
    { (yyval.node) = cmdparser.addVariable(declaredType, (yyvsp[(1) - (1)].name)); }
    break;

  case 61:
#line 199 "grammar.yy"
    { (yyval.node) = cmdparser.addVariable(declaredType, &varName); }
    break;

  case 62:
#line 203 "grammar.yy"
    { if (declaredType == VTypes::NoData) { msg.print("Token '%s' is undeclared.\n", tokenName.get()); YYABORT; } (yyval.name) = (yyvsp[(1) - (2)].name); }
    break;

  case 63:
#line 207 "grammar.yy"
    { (yyval.node) = cmdparser.addDeclarations((yyvsp[(3) - (3)].node)); declaredType = VTypes::NoData; }
    break;

  case 64:
#line 208 "grammar.yy"
    { msg.print("Illegal use of reserved word '%s'.\n", VTypes::dataType(declaredType)); YYABORT; }
    break;

  case 65:
#line 214 "grammar.yy"
    { if (!cmdparser.expandPath(&stepName, (yyvsp[(4) - (5)].node))) YYABORT; }
    break;

  case 66:
#line 215 "grammar.yy"
    { if (!cmdparser.expandPath(&stepName, (yyvsp[(4) - (5)].node))) YYABORT; }
    break;

  case 67:
#line 216 "grammar.yy"
    { if (!cmdparser.expandPath((yyvsp[(1) - (1)].name))) YYABORT; }
    break;

  case 68:
#line 220 "grammar.yy"
    { }
    break;

  case 69:
#line 221 "grammar.yy"
    { }
    break;

  case 70:
#line 222 "grammar.yy"
    { msg.print("Error formulating path.\n"); YYABORT; }
    break;

  case 71:
#line 226 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); if ((yyval.node) == NULL) YYABORT; }
    break;

  case 72:
#line 230 "grammar.yy"
    { (yyval.node) = cmdparser.wrapVariable((yyvsp[(1) - (4)].variable),(yyvsp[(3) - (4)].node)); }
    break;

  case 73:
#line 231 "grammar.yy"
    { (yyval.node) = cmdparser.wrapVariable((yyvsp[(1) - (1)].variable)); }
    break;

  case 74:
#line 232 "grammar.yy"
    { (yyval.node) = cmdparser.wrapVariable((yyvsp[(1) - (4)].variable),(yyvsp[(3) - (4)].node)); }
    break;

  case 75:
#line 233 "grammar.yy"
    { (yyval.node) = cmdparser.wrapVariable((yyvsp[(1) - (1)].variable)); }
    break;

  case 76:
#line 234 "grammar.yy"
    { cmdparser.createPath((yyvsp[(1) - (2)].node)); }
    break;

  case 77:
#line 235 "grammar.yy"
    { (yyval.node) = cmdparser.finalisePath(); }
    break;

  case 78:
#line 236 "grammar.yy"
    { msg.print("Can't use a variable as a function. Did you mean '[' instead?\n"); (yyval.node) = NULL; }
    break;

  case 79:
#line 242 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); if ((yyval.node) == NULL) YYABORT; }
    break;

  case 80:
#line 243 "grammar.yy"
    { (yyval.node) = Tree::joinArguments((yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node)); }
    break;

  case 81:
#line 244 "grammar.yy"
    { msg.print("Error: Missing comma between items.\n"); YYABORT; }
    break;

  case 82:
#line 248 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); if ((yyval.node) == NULL) YYABORT; }
    break;

  case 83:
#line 252 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 84:
#line 253 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 85:
#line 254 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 86:
#line 255 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignment,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 87:
#line 256 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignment,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 88:
#line 257 "grammar.yy"
    { msg.print("Mangled expression used in assignment.\n"); YYABORT; }
    break;

  case 89:
#line 258 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignmentPlus,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 90:
#line 259 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignmentSubtract,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 91:
#line 260 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignmentMultiply,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 92:
#line 261 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignmentDivide,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 93:
#line 262 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorNegate, (yyvsp[(2) - (2)].node)); }
    break;

  case 94:
#line 263 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPostfixIncrease, (yyvsp[(1) - (2)].node));  }
    break;

  case 95:
#line 264 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPostfixDecrease, (yyvsp[(1) - (2)].node)); }
    break;

  case 96:
#line 265 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPrefixIncrease, (yyvsp[(2) - (2)].node)); }
    break;

  case 97:
#line 266 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPrefixDecrease, (yyvsp[(2) - (2)].node)); }
    break;

  case 98:
#line 267 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 99:
#line 268 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAdd, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 100:
#line 269 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorSubtract, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 101:
#line 270 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorMultiply, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 102:
#line 271 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorDivide, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 103:
#line 272 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPower, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 104:
#line 273 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorModulus, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 105:
#line 274 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorEqualTo, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 106:
#line 275 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorNotEqualTo, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 107:
#line 276 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorGreaterThan, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 108:
#line 277 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorGreaterThanEqualTo, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 109:
#line 278 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorLessThan, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 110:
#line 279 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorLessThanEqualTo, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 111:
#line 280 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAnd, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 112:
#line 281 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorOr, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 113:
#line 282 "grammar.yy"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 114:
#line 283 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorNot, (yyvsp[(2) - (2)].node)); }
    break;

  case 115:
#line 284 "grammar.yy"
    { msg.print("Error: '%s' has not been declared as a function or a variable.\n", yylval.name->get()); YYABORT; }
    break;

  case 116:
#line 290 "grammar.yy"
    { (yyval.node) = cmdparser.addArrayConstant((yyvsp[(2) - (3)].node)); }
    break;

  case 117:
#line 296 "grammar.yy"
    { (yyval.node) = cmdparser.addFunction( (Command::Function) (yyvsp[(1) - (3)].functionId)); }
    break;

  case 118:
#line 297 "grammar.yy"
    { (yyval.node) = cmdparser.addFunctionWithArglist( (Command::Function) (yyvsp[(1) - (4)].functionId),(yyvsp[(3) - (4)].node)); }
    break;

  case 119:
#line 298 "grammar.yy"
    { (yyval.node) = cmdparser.addFunction( (Command::Function) (yyvsp[(1) - (1)].functionId)); }
    break;

  case 120:
#line 302 "grammar.yy"
    { (yyval.node) = cmdparser.addUserFunction((yyvsp[(1) - (4)].functree),(yyvsp[(3) - (4)].node)); }
    break;

  case 121:
#line 303 "grammar.yy"
    { (yyval.node) = cmdparser.addUserFunction((yyvsp[(1) - (3)].functree)); }
    break;

  case 122:
#line 304 "grammar.yy"
    { (yyval.node) = cmdparser.addUserFunction((yyvsp[(1) - (1)].functree)); }
    break;

  case 123:
#line 310 "grammar.yy"
    { tokenName = *yylval.name; }
    break;

  case 124:
#line 314 "grammar.yy"
    { declaredType = yylval.vtype; }
    break;

  case 125:
#line 318 "grammar.yy"
    { declaredType = VTypes::NoData; }
    break;

  case 126:
#line 322 "grammar.yy"
    { varName = yylval.variable->name(); }
    break;

  case 127:
#line 326 "grammar.yy"
    { stepName = *yylval.name; }
    break;


/* Line 1267 of yacc.c.  */
#line 2385 "grammar.cc"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 329 "grammar.yy"


void yyerror(char *s)
{
}
