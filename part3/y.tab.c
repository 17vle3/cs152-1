/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 4 "mini_l.y"

#include "heading.h"
//#include <stdio.h>
//#define YY_NO_UNPUT
//int yyparse();
int yyerror(const char* s);
int yylex(void);
stringstream *all_code;
FILE * myin;
void print_test(string output);
void print_test(stringstream o);
string gen_code(string *res, string op, string *val1, string *val2);
string to_string(char* s);
string to_string(int s);
int tempi = 0;
int templ = 0;
string * new_temp();
string * new_label();
string go_to(string *s);
string dec_label(string *s);
string dec_temp(string *s);

/* Line 371 of yacc.c  */
#line 91 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FUNCTION = 258,
     BEGIN_PARAMS = 259,
     END_PARAMS = 260,
     BEGIN_LOCALS = 261,
     END_LOCALS = 262,
     BEGIN_BODY = 263,
     END_BODY = 264,
     INTEGER = 265,
     ARRAY = 266,
     OF = 267,
     IF = 268,
     THEN = 269,
     ENDIF = 270,
     ELSE = 271,
     WHILE = 272,
     DO = 273,
     BEGINLOOP = 274,
     ENDLOOP = 275,
     CONTINUE = 276,
     READ = 277,
     WRITE = 278,
     RETURN = 279,
     AND = 280,
     OR = 281,
     NOT = 282,
     TRUE = 283,
     FALSE = 284,
     SUB = 285,
     ADD = 286,
     MULT = 287,
     DIV = 288,
     MOD = 289,
     EQ = 290,
     NEQ = 291,
     LT = 292,
     GT = 293,
     LTE = 294,
     GTE = 295,
     SEMICOLON = 296,
     COLON = 297,
     COMMA = 298,
     L_PAREN = 299,
     R_PAREN = 300,
     L_SQUARE_BRACKET = 301,
     R_SQUARE_BRACKET = 302,
     ASSIGN = 303,
     NUMBER = 304,
     IDENT = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 27 "mini_l.y"

    int       int_val;
    char str_val[256];

    //enum Type {INT, INT_ARR};

    struct {
        stringstream *code;
    }NonTerminal;


    struct {
       stringstream *code;
       //location
       string *place;
       string *value;
       string *offset;
       // branches
       string *op;
       string *begin;
       string *parent;
       string *end;
       // type
       //uint val;
       Type type;
       int length;
       string *index;
       // idents and vars
       vector<string> *ids;
       vector<Var> *vars; 
    } Terminal;


/* Line 387 of yacc.c  */
#line 218 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 246 "y.tab.c"

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    21,    25,    27,    31,    32,
      36,    37,    40,    44,    48,    54,    55,    57,    59,    61,
      63,    65,    67,    69,    72,    76,    83,    84,    87,    93,
     100,   104,   108,   109,   113,   117,   118,   121,   125,   126,
     129,   133,   134,   136,   139,   143,   145,   147,   151,   153,
     155,   157,   159,   161,   163,   166,   170,   174,   175,   178,
     182,   186,   190,   191,   194,   196,   198,   200,   202,   206,
     211,   214,   215,   218,   219,   222,   226
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    52,    -1,    -1,     3,    50,    41,
       4,    55,     5,     6,    55,     7,     8,    60,    41,    54,
      -1,    60,    41,    54,    -1,     9,    -1,    57,    41,    55,
      -1,    -1,    60,    41,    56,    -1,    -1,    50,    58,    -1,
      43,    50,    58,    -1,    42,    59,    10,    -1,    11,    46,
      49,    47,    12,    -1,    -1,    61,    -1,    62,    -1,    64,
      -1,    65,    -1,    66,    -1,    68,    -1,    21,    -1,    24,
      77,    -1,    86,    48,    77,    -1,    13,    70,    14,    56,
      63,    15,    -1,    -1,    16,    56,    -1,    17,    70,    19,
      56,    20,    -1,    18,    19,    56,    20,    17,    70,    -1,
      22,    86,    67,    -1,    43,    86,    67,    -1,    -1,    23,
      86,    69,    -1,    43,    86,    69,    -1,    -1,    72,    71,
      -1,    26,    72,    71,    -1,    -1,    74,    73,    -1,    25,
      74,    73,    -1,    -1,    75,    -1,    27,    75,    -1,    77,
      76,    77,    -1,    28,    -1,    29,    -1,    44,    70,    45,
      -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,    39,
      -1,    40,    -1,    79,    78,    -1,    31,    79,    78,    -1,
      30,    79,    78,    -1,    -1,    81,    80,    -1,    32,    81,
      80,    -1,    33,    81,    80,    -1,    34,    81,    80,    -1,
      -1,    30,    82,    -1,    82,    -1,    83,    -1,    86,    -1,
      49,    -1,    44,    77,    45,    -1,    50,    44,    84,    45,
      -1,    77,    85,    -1,    -1,    43,    84,    -1,    -1,    50,
      87,    -1,    46,    77,    47,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,   100,   107,   128,   135,   143,   152,   159,
     164,   170,   199,   219,   228,   235,   244,   247,   250,   253,
     256,   259,   262,   267,   275,   298,   319,   324,   331,   343,
     354,   368,   379,   385,   399,   410,   416,   435,   457,   464,
     484,   505,   512,   518,   527,   535,   541,   547,   554,   560,
     566,   572,   578,   584,   592,   611,   633,   654,   661,   684,
     705,   728,   745,   752,   759,   764,   771,   777,   786,   793,
     803,   810,   815,   819,   824,   850,   858
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "RETURN", "AND", "OR", "NOT",
  "TRUE", "FALSE", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT",
  "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN", "NUMBER", "IDENT",
  "$accept", "program", "function", "function_2", "decl_loop", "stmt_loop",
  "declaration", "declaration_2", "declaration_3", "statement",
  "statement_1", "statement_2", "statement_21", "statement_3",
  "statement_4", "statement_5", "statement_51", "statement_6",
  "statement_61", "bool_exp", "bool_exp2", "rel_and_exp", "rel_and_exp2",
  "relation_exp", "relation_exp_s", "comp", "expression", "expression_2",
  "mult_expr", "mult_expr_2", "term", "term_2", "term_3", "term_31",
  "term_32", "var", "var_2", YY_NULL
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
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    54,    54,    55,    55,    56,
      56,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    62,    63,    63,    64,    65,
      66,    67,    67,    68,    69,    69,    70,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    76,    76,
      76,    76,    76,    76,    77,    78,    78,    78,    79,    80,
      80,    80,    80,    81,    81,    81,    82,    82,    82,    83,
      84,    84,    85,    85,    86,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,    13,     3,     1,     3,     0,     3,
       0,     2,     3,     3,     5,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     6,     0,     2,     5,     6,
       3,     3,     0,     3,     3,     0,     2,     3,     0,     2,
       3,     0,     1,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     0,     2,     3,
       3,     3,     0,     2,     1,     1,     1,     1,     3,     4,
       2,     0,     2,     0,     2,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     3,     0,     1,     2,     0,     8,     0,
       0,     0,    15,     0,    11,     0,     8,     0,     0,     0,
       8,     7,     0,    13,    12,     0,     0,     0,     0,     0,
      14,     0,     0,     0,    22,     0,     0,     0,    76,     0,
      16,    17,    18,    19,    20,    21,     0,     0,    45,    46,
       0,     0,    67,    76,     0,    38,    41,    42,     0,    57,
      62,    64,    65,    66,     0,    10,    32,    35,     0,    23,
       0,    74,     0,     0,    43,    63,     0,     0,    71,    10,
       0,    36,     0,    39,    48,    49,    50,    51,    52,    53,
       0,     0,     0,    54,     0,     0,     0,    58,    10,     0,
       0,     0,    30,     0,    33,     0,     0,     6,     4,     0,
      24,    47,    68,    73,     0,    26,    38,    41,    44,    57,
      57,    62,    62,    62,     0,     0,    10,    32,    35,    75,
       0,    71,    70,    69,    10,     0,    37,    40,    56,    55,
      59,    60,    61,    28,     0,     9,    31,    34,     5,    72,
      27,    25,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,    10,    99,    11,    14,    18,   100,
      40,    41,   135,    42,    43,    44,   102,    45,   104,    54,
      81,    55,    83,    56,    57,    90,    58,    93,    59,    97,
      60,    61,    62,   114,   132,    63,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -97
static const yytype_int8 yypact[] =
{
      28,   -14,    56,    28,     5,   -97,   -97,    68,    21,   -37,
      69,    35,    79,    43,   -97,    95,    21,    61,    98,   -37,
      21,   -97,    60,   -97,   -97,   106,    71,   107,   102,    42,
     -97,    50,    50,   100,   -97,    70,    70,    18,    75,    81,
     -97,   -97,   -97,   -97,   -97,   -97,    76,    67,   -97,   -97,
     -40,    50,   -97,   -23,   109,    99,   101,   -97,     3,   -13,
     -20,   -97,   -97,   -97,   108,    42,    85,    86,    18,   -97,
      18,   -97,    11,    18,   -97,   -97,    87,    46,    18,    42,
      50,   -97,    50,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
      18,    18,    18,   -97,    18,    18,    18,   -97,    42,   110,
      90,    70,   -97,    70,   -97,    88,    89,   -97,   -97,    93,
     -97,   -97,   -97,    92,    94,   121,    99,   101,   -97,   -13,
     -13,   -20,   -20,   -20,   118,   123,    42,    85,    86,   -97,
      11,    18,   -97,   -97,    42,   126,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,    50,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   139,   -97,    14,    -5,   -76,   -97,   124,   -97,   -27,
     -97,   -97,   -97,   -97,   -97,   -97,    19,   -97,    17,   -32,
      31,    72,    32,    66,   103,   -97,   -21,   -66,    13,   -96,
      -7,   104,   -97,    20,   -97,   -28,   -97
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      64,    46,    39,   115,    68,    12,    13,    66,    67,    52,
      38,    21,    94,    95,    96,    25,    69,    91,    92,    76,
     107,    78,   124,    70,    31,   140,   141,   142,    32,    33,
      77,     1,    34,    35,    36,    37,     4,    46,    84,    85,
      86,    87,    88,    89,    46,   109,     7,   105,    50,   106,
     145,    46,   110,   138,   139,    31,     5,   113,   150,    32,
      33,    38,    68,    34,    35,    36,    37,    52,    53,   118,
      46,     9,     8,   127,    15,   128,    16,    47,    48,    49,
      50,    84,    85,    86,    87,    88,    89,   121,   122,   123,
      17,   112,    38,    19,    51,    48,    49,    50,    46,    52,
      53,    20,    46,   109,   119,   120,    46,    22,    23,    26,
     113,    51,   152,    27,    30,    29,    52,    53,    28,    65,
      38,    70,    72,    79,    73,    80,    82,    98,   101,   103,
     125,   126,   111,   112,   130,   131,   129,   134,   143,   133,
     144,   151,     6,    24,   148,   147,   146,   136,   117,   137,
      74,   149,   116,     0,    75
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-97)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      32,    29,    29,    79,    44,    42,    43,    35,    36,    49,
      50,    16,    32,    33,    34,    20,    37,    30,    31,    51,
       9,    44,    98,    46,    13,   121,   122,   123,    17,    18,
      51,     3,    21,    22,    23,    24,    50,    65,    35,    36,
      37,    38,    39,    40,    72,    72,    41,    68,    30,    70,
     126,    79,    73,   119,   120,    13,     0,    78,   134,    17,
      18,    50,    44,    21,    22,    23,    24,    49,    50,    90,
      98,    50,     4,   101,     5,   103,    41,    27,    28,    29,
      30,    35,    36,    37,    38,    39,    40,    94,    95,    96,
      11,    45,    50,    50,    44,    28,    29,    30,   126,    49,
      50,     6,   130,   130,    91,    92,   134,    46,    10,    49,
     131,    44,   144,     7,    12,     8,    49,    50,    47,    19,
      50,    46,    41,    14,    48,    26,    25,    19,    43,    43,
      20,    41,    45,    45,    41,    43,    47,    16,    20,    45,
      17,    15,     3,    19,   130,   128,   127,   116,    82,   117,
      47,   131,    80,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    53,    50,     0,    52,    41,     4,    50,
      55,    57,    42,    43,    58,     5,    41,    11,    59,    50,
       6,    55,    46,    10,    58,    55,    49,     7,    47,     8,
      12,    13,    17,    18,    21,    22,    23,    24,    50,    60,
      61,    62,    64,    65,    66,    68,    86,    27,    28,    29,
      30,    44,    49,    50,    70,    72,    74,    75,    77,    79,
      81,    82,    83,    86,    70,    19,    86,    86,    44,    77,
      46,    87,    41,    48,    75,    82,    70,    77,    44,    14,
      26,    71,    25,    73,    35,    36,    37,    38,    39,    40,
      76,    30,    31,    78,    32,    33,    34,    80,    19,    56,
      60,    43,    67,    43,    69,    77,    77,     9,    54,    60,
      77,    45,    45,    77,    84,    56,    72,    74,    77,    79,
      79,    81,    81,    81,    56,    20,    41,    86,    86,    47,
      41,    43,    85,    45,    16,    63,    71,    73,    78,    78,
      80,    80,    80,    20,    17,    56,    67,    69,    54,    84,
      56,    15,    70
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1792 of yacc.c  */
#line 89 "mini_l.y"
    {
                printf("program -> function program\n");
                //$2 or program should have all functions excecpt newest one
                (yyval.NonTerminal).code = (yyvsp[(1) - (2)].Terminal).code;
                *((yyval.NonTerminal).code) << (yyvsp[(2) - (2)].NonTerminal).code->str();
                //print_test("function:\n" + $1.code->str());
                //print_test("program:\n" + $$.code->str());

                all_code = (yyval.NonTerminal).code;
                //*($$.code) << $1.code->str();
              }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 100 "mini_l.y"
    {
                printf("program -> EPSILON\n");
                //nothing?
                (yyval.NonTerminal).code = new stringstream();
              }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 107 "mini_l.y"
    {
                printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS decl_loop END_PARAMS BEGIN_LOCALS decl_loop END_LOCALS BEGIN_BODY statement SEMICOLON function_2\n");
                //$13 or funtion 2, should have entire function code
                (yyval.Terminal).code = new stringstream(); 
                *((yyval.Terminal).code)  << "func " << (yyvsp[(2) - (13)].str_val) << "\n" << (yyvsp[(5) - (13)].Terminal).code->str() << (yyvsp[(8) - (13)].Terminal).code->str();
                for(int i = 0; i < (yyvsp[(5) - (13)].Terminal).vars->size(); ++i){
                    if((*(yyvsp[(5) - (13)].Terminal).vars)[i].type == INT_ARR){
                        print_test("ERROROROROROROROROROR");
                        //*($$.code) << ".[] " << $1 << ", " <<(*$5.vars)[i].length << "\n";
                    }
                    else if((*(yyvsp[(5) - (13)].Terminal).vars)[i].type == INT){
                        *((yyval.Terminal).code) << "= " << *((*(yyvsp[(5) - (13)].Terminal).vars)[i].place) << ", " << "$"<< to_string(i) << "\n";
                    }else{printf("================ ERRRR\n");}
                }
                 *((yyval.Terminal).code) << (yyvsp[(11) - (13)].Terminal).code->str() << (yyvsp[(13) - (13)].Terminal).code->str();
                //$5 decl_loop should have function params
                //$8 decl_loop should have function local variables
                
            }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 128 "mini_l.y"
    {
                printf("function_2 -> statement SEMICOLON function_2\n");
                //$1 or statement should have line statement
                //$3 or func_2, should have previous statements
                (yyval.Terminal).code = (yyvsp[(1) - (3)].Terminal).code;
                *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
              }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 135 "mini_l.y"
    {
                printf("function_2 -> END_BODY\n");
                //nothing?
                (yyval.Terminal).code = new stringstream();
                *((yyval.Terminal).code) << "endfunc\n";
              }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 143 "mini_l.y"
    {
                    printf("decl_loop -> declaration SEMICOLON decl_loop\n");
                (yyval.Terminal).code = (yyvsp[(1) - (3)].Terminal).code;
                (yyval.Terminal).vars = (yyvsp[(1) - (3)].Terminal).vars;
                for( int i = 0; i < (yyvsp[(3) - (3)].Terminal).vars->size(); ++i){
                    (yyval.Terminal).vars->push_back((*(yyvsp[(3) - (3)].Terminal).vars)[i]);
                }
                *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 152 "mini_l.y"
    {
                printf("decl_loop -> EPSILON\n");
                (yyval.Terminal).code = new stringstream();
                (yyval.Terminal).vars = new vector<Var>();
              }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 159 "mini_l.y"
    {
                printf("stmt_loop -> statement SEMICOLON stmt_loop\n");
                (yyval.Terminal).code = (yyvsp[(1) - (3)].Terminal).code;
                *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
              }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 164 "mini_l.y"
    {
                printf("stmt_loop -> EPSILON\n");
                (yyval.Terminal).code = new stringstream();
              }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 170 "mini_l.y"
    {
                    //printf("declaration -> IDENT declaration_2\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (2)].Terminal).code;
                    (yyval.Terminal).type = (yyvsp[(2) - (2)].Terminal).type;
                    (yyval.Terminal).length = (yyvsp[(2) - (2)].Terminal).length;
                    //TODO: add variable to symbol_table

                    (yyval.Terminal).vars = (yyvsp[(2) - (2)].Terminal).vars;
                    Var v = Var();
                    v.type = (yyvsp[(2) - (2)].Terminal).type;
                    v.length = (yyvsp[(2) - (2)].Terminal).length;
                    v.place = new string();
                    *v.place = (yyvsp[(1) - (2)].str_val);
                    (yyval.Terminal).vars->push_back(v);
                    if((yyvsp[(2) - (2)].Terminal).type == INT_ARR){
                        *((yyval.Terminal).code) << ".[] " << (yyvsp[(1) - (2)].str_val) << ", " << (yyvsp[(2) - (2)].Terminal).length << "\n";
                    }
                    else if((yyvsp[(2) - (2)].Terminal).type == INT){
                        *((yyval.Terminal).code) << ". " << (yyvsp[(1) - (2)].str_val) << "\n";
                    }else{printf("================ ERRRR\n");}
                    //print_test("DECL:\n" + $$.code->str());
                        print_test(to_string((yyval.Terminal).vars->size()));
                    for(int i = 0; i < (yyval.Terminal).vars->size(); ++i){
                        print_test("type:" + to_string((*(yyval.Terminal).vars)[i].type) + "\nlength:" + to_string((*(yyval.Terminal).vars)[i].length) + "\nplace:" + *(*(yyval.Terminal).vars)[i].place);
                    }

                }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 199 "mini_l.y"
    {
                    //printf("declaration_2 -> COMMA IDENT declaration_2\n");
                    (yyval.Terminal).code = (yyvsp[(3) - (3)].Terminal).code;
                    (yyval.Terminal).type = (yyvsp[(3) - (3)].Terminal).type;
                    (yyval.Terminal).length = (yyvsp[(3) - (3)].Terminal).length;
                    //TODO: add variable to symbol_table
                    (yyval.Terminal).vars = (yyvsp[(3) - (3)].Terminal).vars;
                    Var v = Var();
                    v.type = (yyvsp[(3) - (3)].Terminal).type;
                    v.length = (yyvsp[(3) - (3)].Terminal).length;
                    v.place = new string();
                    *v.place = (yyvsp[(2) - (3)].str_val);
                    (yyval.Terminal).vars->push_back(v);
                    if((yyvsp[(3) - (3)].Terminal).type == INT_ARR){
                        *((yyval.Terminal).code) << ".[] " << (yyvsp[(2) - (3)].str_val) << ", " << (yyvsp[(3) - (3)].Terminal).length << "\n";
                    }
                    else if((yyvsp[(3) - (3)].Terminal).type == INT){
                        *((yyval.Terminal).code) << ". " << (yyvsp[(2) - (3)].str_val) << "\n";
                    }else{printf("================ ERRRR\n");}
                }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 219 "mini_l.y"
    {
                    //printf("declaration_2 -> COLON declaration_3 INTEGER\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    (yyval.Terminal).type = (yyvsp[(2) - (3)].Terminal).type;
                    (yyval.Terminal).length = (yyvsp[(2) - (3)].Terminal).length;
                    (yyval.Terminal).vars = (yyvsp[(2) - (3)].Terminal).vars;
                }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 228 "mini_l.y"
    {
                    //printf("declaration_3 -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).vars = new vector<Var>();
                    (yyval.Terminal).type = INT_ARR;
                    (yyval.Terminal).length = (yyvsp[(3) - (5)].int_val);
                }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 235 "mini_l.y"
    {
                    //printf("declaration_3 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).vars = new vector<Var>();
                    (yyval.Terminal).type = INT;
                    (yyval.Terminal).length = 0;
                  }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 244 "mini_l.y"
    {
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 247 "mini_l.y"
    {
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 250 "mini_l.y"
    {
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 253 "mini_l.y"
    {
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 256 "mini_l.y"
    {
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 259 "mini_l.y"
    {
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 262 "mini_l.y"
    {
                    printf("statement -> CONTINUE\n");
                    //TODO: probably add code to jump to start of loop?
                    (yyval.Terminal).code = new stringstream();
                }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 267 "mini_l.y"
    {
                    printf("statement -> RETURN expression\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (2)].Terminal).code;
                    (yyval.Terminal).place = (yyvsp[(2) - (2)].Terminal).place;
                    *((yyval.Terminal).code) << "ret " << *(yyval.Terminal).place << "\n";
                    //print_test($$.code->str());
                }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 275 "mini_l.y"
    {
                    printf("statement -> var ASSIGN expression\n");
                    //TODO: var = x; check symbol table, assign it expression
                    (yyval.Terminal).code = (yyvsp[(1) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    //print_test($$.code->str() + "\n--\n"+  *$1.place + "\n--\n"+ *$3.place);
                    if((yyvsp[(1) - (3)].Terminal).type == INT && (yyvsp[(3) - (3)].Terminal).type == INT){
                       *((yyval.Terminal).code) << "= " << *(yyvsp[(1) - (3)].Terminal).place << ", " << *(yyvsp[(3) - (3)].Terminal).place << "\n";
                    }
                    else if((yyvsp[(1) - (3)].Terminal).type == INT && (yyvsp[(3) - (3)].Terminal).type == INT_ARR){
                        *((yyval.Terminal).code) << gen_code((yyvsp[(1) - (3)].Terminal).place, "=[]", (yyvsp[(1) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                    }
                    else if((yyvsp[(1) - (3)].Terminal).type == INT_ARR && (yyvsp[(3) - (3)].Terminal).type == INT && (yyvsp[(1) - (3)].Terminal).value != NULL){
                        //*($$.code) << gen_code($1.place, "[]=", $1.index, $3.place);
                        *((yyval.Terminal).code) << gen_code((yyvsp[(1) - (3)].Terminal).value, "[]=", (yyvsp[(1) - (3)].Terminal).index, (yyvsp[(3) - (3)].Terminal).place);
                    }
                    else{
                        cout << "\nERROR var op null:\n" ;
                    }
                    //print_test($$.code->str() + "\n--\n"+  *$1.place + "\n--\n"+ *$3.place);
                }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 298 "mini_l.y"
    {
                    printf("statement -> IF bool_exp THEN stmt_loop statement_21 ENDIF\n");
                    //label, bool exp, loop.code, statemtn (else), label
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).begin = new_label();
                    (yyval.Terminal).end = new_label();
                    *((yyval.Terminal).code) << (yyvsp[(2) - (6)].Terminal).code->str() << "?:= " << *(yyval.Terminal).begin << ", " <<  *(yyvsp[(2) - (6)].Terminal).place << "\n";
                    if((yyvsp[(5) - (6)].Terminal).begin != NULL){                       
                        *((yyval.Terminal).code) << go_to((yyvsp[(5) - (6)].Terminal).begin); 
                        *((yyval.Terminal).code) << dec_label((yyval.Terminal).begin)  << (yyvsp[(4) - (6)].Terminal).code->str() << go_to((yyval.Terminal).end);
                        cout << "BEGIN" << endl;
                        *((yyval.Terminal).code) << dec_label((yyvsp[(5) - (6)].Terminal).begin) << (yyvsp[(5) - (6)].Terminal).code->str();
                    }
                    else{
                        *((yyval.Terminal).code) << go_to((yyval.Terminal).end)<< dec_label((yyval.Terminal).begin)  << (yyvsp[(4) - (6)].Terminal).code->str();
                    }
                    *((yyval.Terminal).code) << dec_label((yyval.Terminal).end);
                    //print_test($$.code->str());
                }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 319 "mini_l.y"
    {
                    printf("statement_21 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).begin = NULL;
                }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 324 "mini_l.y"
    {
                    printf("statement_21 -> ELSE stmt_loop\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (2)].Terminal).code;
                    (yyval.Terminal).begin = new_label();
                }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 331 "mini_l.y"
    {
                    printf("statement -> WHILE bool_exp BEGINLOOP stmt_loop ENDLOOP\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).begin = new_label();
                    (yyval.Terminal).parent = new_label();
                    (yyval.Terminal).end = new_label();
                    *((yyval.Terminal).code) << dec_label((yyval.Terminal).parent) << (yyvsp[(2) - (5)].Terminal).code->str() << "?:= " << *(yyval.Terminal).begin << ", " << *(yyvsp[(2) - (5)].Terminal).place << "\n" 
                    << go_to((yyval.Terminal).end) << dec_label((yyval.Terminal).begin) << (yyvsp[(4) - (5)].Terminal).code->str() << go_to((yyval.Terminal).parent) << dec_label((yyval.Terminal).end);
                    //print_test($$.code->str());
                }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 343 "mini_l.y"
    {
                    printf("statement -> DO BEGINLOOP stmt_loop ENDLOOP WHILE bool_exp\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).begin = new_label();
                    (yyval.Terminal).parent = new_label();
                    (yyval.Terminal).end = new_label();
                    *((yyval.Terminal).code) << dec_label((yyval.Terminal).begin) << (yyvsp[(3) - (6)].Terminal).code->str() << (yyvsp[(6) - (6)].Terminal).code->str() << "?:= " << *(yyval.Terminal).begin << ", " << *(yyvsp[(6) - (6)].Terminal).place << "\n" << dec_label((yyval.Terminal).end);
                    //print_test($$.code->str());
                }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 354 "mini_l.y"
    {
                    printf("statement -> READ var statement_51\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    if((yyvsp[(2) - (3)].Terminal).type == INT){
                       *((yyval.Terminal).code) << ".< " << *(yyvsp[(2) - (3)].Terminal).place << "\n"; 
                    }
                    else{
                       *((yyval.Terminal).code) << ".[]< " << *(yyvsp[(2) - (3)].Terminal).place << ", " << (yyvsp[(2) - (3)].Terminal).index << "\n"; 
                    }
                    //print_test($$.code->str());
                }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 368 "mini_l.y"
    {
                    printf("statement_51 -> COMMA var statement_51\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    if((yyvsp[(2) - (3)].Terminal).type == INT){
                       *((yyval.Terminal).code) << ".< " << *(yyvsp[(2) - (3)].Terminal).place << "\n"; 
                    }
                    else{
                       *((yyval.Terminal).code) << ".[]< " << *(yyvsp[(2) - (3)].Terminal).place << ", " << (yyvsp[(2) - (3)].Terminal).index << "\n"; 
                    }
                }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 379 "mini_l.y"
    {
                    printf("statement_51 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                  }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 385 "mini_l.y"
    {
                    printf("statement -> WRITE var statement_61\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    if((yyvsp[(2) - (3)].Terminal).type == INT){
                       *((yyval.Terminal).code) << ".> " << *(yyvsp[(2) - (3)].Terminal).place << "\n"; 
                    }
                    else{
                       *((yyval.Terminal).code) << ".[]> " << *(yyvsp[(2) - (3)].Terminal).value << ", " << *(yyvsp[(2) - (3)].Terminal).index << "\n"; 
                    }
                    //print_test($$.code->str());
                  }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 399 "mini_l.y"
    {
                    printf("statement_61 -> COMMA var statement_61\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    if((yyvsp[(2) - (3)].Terminal).type == INT){
                       *((yyval.Terminal).code) << ".> " << *(yyvsp[(2) - (3)].Terminal).place << "\n"; 
                    }
                    else{
                       *((yyval.Terminal).code) << ".[]> " << *(yyvsp[(2) - (3)].Terminal).value << ", " << *(yyvsp[(2) - (3)].Terminal).index << "\n"; 
                    }
                  }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 410 "mini_l.y"
    {
                    printf("statement_61 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                 }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 416 "mini_l.y"
    {
                    printf("bool_exp -> rel_and_exp bool_exp2\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (2)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(2) - (2)].Terminal).code->str();
                    if((yyvsp[(2) - (2)].Terminal).op != NULL && (yyvsp[(2) - (2)].Terminal).place != NULL)
                    {                        
                        (yyval.Terminal).place = new_temp();
                       *((yyval.Terminal).code) << dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place, *(yyvsp[(2) - (2)].Terminal).op, (yyvsp[(1) - (2)].Terminal).place, (yyvsp[(2) - (2)].Terminal).place);
                    }
                    else{
                        (yyval.Terminal).place = (yyvsp[(1) - (2)].Terminal).place;
                        (yyval.Terminal).op = (yyvsp[(1) - (2)].Terminal).op;
                    }
                    //print_test($$.code->str());
                    //print_test($$.code->str());
 
                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 435 "mini_l.y"
    {
                    printf("bool_exp2 -> OR rel_and_exp bool_exp2\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    //*($$.code) << "*";
                    if((yyvsp[(3) - (3)].Terminal).op == NULL){
                        (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "||";
                    }
                    else{
                        //$3.op temp $2.place $3.place
                        (yyval.Terminal).place = new_temp();
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "||";

                        //*($$.code) << ". " << *$$.place << "\n";
                        *((yyval.Terminal).code) << dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place , *(yyval.Terminal).op, (yyvsp[(2) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                    } 


                }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 457 "mini_l.y"
    {
                    printf("bool_exp2 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = NULL;
                 }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 464 "mini_l.y"
    {
                    printf("rel_and_exp -> relation_exp rel_and_exp2\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (2)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(2) - (2)].Terminal).code->str();
                    if((yyvsp[(2) - (2)].Terminal).op != NULL && (yyvsp[(2) - (2)].Terminal).place != NULL)
                    {                        
                        (yyval.Terminal).place = new_temp();
                        //printf("%s", $1.place);
                       *((yyval.Terminal).code) << dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place, *(yyvsp[(2) - (2)].Terminal).op, (yyvsp[(1) - (2)].Terminal).place, (yyvsp[(2) - (2)].Terminal).place);
                    }
                    else{
                        (yyval.Terminal).place = (yyvsp[(1) - (2)].Terminal).place;
                        (yyval.Terminal).op = (yyvsp[(1) - (2)].Terminal).op;
                    }
                    //print_test($$.code->str());
                    //print_test($$.code->str());
 
                }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 484 "mini_l.y"
    {
                    printf("rel_and_exp2 -> AND relation_exp rel_and_exp2\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    //*($$.code) << "*";
                    if((yyvsp[(3) - (3)].Terminal).op == NULL){
                        (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "&&";
                    }
                    else{
                        //$3.op temp $2.place $3.place
                        (yyval.Terminal).place = new_temp();
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "&&";

                        //*($$.code) << ". " << *$$.place << "\n";
                        *((yyval.Terminal).code) << dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place , *(yyval.Terminal).op, (yyvsp[(2) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                    } 

                }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 505 "mini_l.y"
    {
                    printf("rel_and_exp2 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = NULL;
                 }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 512 "mini_l.y"
    {
                    printf("relation_exp -> relation_exp_s\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                    (yyval.Terminal).place = (yyvsp[(1) - (1)].Terminal).place; 
                    //print_test($$.code->str());
                }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 518 "mini_l.y"
    {
                    printf("relation_exp -> NOT relation_exp_s\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (2)].Terminal).code;
                    (yyval.Terminal).place = new_temp();
                    *((yyval.Terminal).code) << dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place, "!", (yyvsp[(2) - (2)].Terminal).place, NULL);
                    //print_test($$.code->str());
                }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 527 "mini_l.y"
    {
                    printf("relation_exp_s -> expression comp expression\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(2) - (3)].Terminal).code->str();
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    (yyval.Terminal).place = new_temp();
                    *((yyval.Terminal).code)<< dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place, *(yyvsp[(2) - (3)].Terminal).op, (yyvsp[(1) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 535 "mini_l.y"
    {                    
                    printf("relation_exp_s -> TRUE\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).place = new string();
                    *(yyval.Terminal).place = "1";
                    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 541 "mini_l.y"
    {
                    printf("relation_exp_s -> FALSE\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).place = new string();
                    *(yyval.Terminal).place = "0";
                  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 547 "mini_l.y"
    {
                    printf("relation_exp_s -> L_PAREN bool_exp R_PAREN\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 554 "mini_l.y"
    {
                    printf("comp -> EQ\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = new string();
                    *(yyval.Terminal).op = "==";
                  }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 560 "mini_l.y"
    {
                    printf("comp -> NEQ\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = new string();
                    *(yyval.Terminal).op = "!=";
                  }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 566 "mini_l.y"
    {
                    printf("comp -> LT\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = new string();
                    *(yyval.Terminal).op = "<";
                  }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 572 "mini_l.y"
    {
                    printf("comp -> GT\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = new string();
                    *(yyval.Terminal).op = ">";
                  }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 578 "mini_l.y"
    {
                    printf("comp -> LTE\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = new string();
                    *(yyval.Terminal).op = "<=";
                  }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 584 "mini_l.y"
    {
                    printf("comp -> GTE\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = new string();
                    *(yyval.Terminal).op = ">=";
                  }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 592 "mini_l.y"
    {
                    printf("expression -> mult_expr expression_2\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (2)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(2) - (2)].Terminal).code->str();
                    if((yyvsp[(2) - (2)].Terminal).op != NULL && (yyvsp[(2) - (2)].Terminal).place != NULL)
                    {                        
                        (yyval.Terminal).place = new_temp();
                        //printf("%s", $1.place);
                       *((yyval.Terminal).code)<< dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place, *(yyvsp[(2) - (2)].Terminal).op, (yyvsp[(1) - (2)].Terminal).place, (yyvsp[(2) - (2)].Terminal).place);
                    }
                    else{
                        (yyval.Terminal).place = (yyvsp[(1) - (2)].Terminal).place;
                        (yyval.Terminal).op = (yyvsp[(1) - (2)].Terminal).op;
                    }
                    //print_test($$.code->str());
                    //print_test($$.code->str());
                  }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 611 "mini_l.y"
    {
                    printf("expression_2 -> ADD mult_expr expression_2\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    //*($$.code) << "*";
                    if((yyvsp[(3) - (3)].Terminal).op == NULL){
                        (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "+";
                    }
                    else{
                        //$3.op temp $2.place $3.place
                        (yyval.Terminal).place = new_temp();
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "+";

                        //*($$.code) << ". " << *$$.place << "\n";
                        *((yyval.Terminal).code)<< dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place , *(yyval.Terminal).op, (yyvsp[(2) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                    } 

                    //print_test($$.code->str());
                  }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 633 "mini_l.y"
    {
                    printf("expression_2 -> SUB mult_expr expression_2\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    //*($$.code) << "*";
                    if((yyvsp[(3) - (3)].Terminal).op == NULL){
                        (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "-";
                    }
                    else{
                        //$3.op temp $2.place $3.place
                        (yyval.Terminal).place = new_temp();
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "-";

                        //*($$.code) << ". " << *$$.place << "\n";
                        *((yyval.Terminal).code)<< dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place , *(yyval.Terminal).op, (yyvsp[(2) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                    }
                    //print_test($$.code->str());
                  }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 654 "mini_l.y"
    {
                    printf("expression -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = NULL;
                  }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 661 "mini_l.y"
    {
                    printf("mult_expr -> term mult_expr_2\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (2)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(2) - (2)].Terminal).code->str();
                    if((yyvsp[(2) - (2)].Terminal).op != NULL && (yyvsp[(2) - (2)].Terminal).place != NULL)
                    {                        
                        (yyval.Terminal).place = new_temp();
                        //printf("%s", $1.place);
                       *((yyval.Terminal).code)<< dec_temp((yyval.Terminal).place)<< gen_code((yyval.Terminal).place, *(yyvsp[(2) - (2)].Terminal).op, (yyvsp[(1) - (2)].Terminal).place, (yyvsp[(2) - (2)].Terminal).place);
                        //print_test($$.code->str());
                    }
                    else{
                        (yyval.Terminal).place = (yyvsp[(1) - (2)].Terminal).place;
                        (yyval.Terminal).op = (yyvsp[(1) - (2)].Terminal).op;
                    }
                    //print_test($$.code->str());
                    //*$$.code = new stringstream();
                    // *($$.code) << $2.code << " " << term;
                    //print_test($$.code->str());
                  }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 684 "mini_l.y"
    {
                    printf("mult_expr_2 -> MULT mult_expr\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    //*($$.code) << "*";
                    if((yyvsp[(3) - (3)].Terminal).op == NULL){
                        (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "*";
                    }
                    else{
                        //$3.op temp $2.place $3.place
                        (yyval.Terminal).place = new_temp();
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "*";

                        //*($$.code) << ". " << *$$.place << "\n";
                        *((yyval.Terminal).code) << dec_temp((yyval.Terminal).place)<< gen_code((yyval.Terminal).place , *(yyval.Terminal).op, (yyvsp[(2) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                    } 

                  }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 705 "mini_l.y"
    {
                    printf("mult_expr_2 -> DIV mult_expr\n");
                    //cout << "WARN: TERM CODE IS NULL" << endl;
                     (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    if((yyvsp[(3) - (3)].Terminal).op == NULL){
                        (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "/";
                    }
                    else{
                        //$3.op temp $2.place $3.place
                        (yyval.Terminal).place = new_temp();
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "/";

                        //*($$.code) << ". " << *$$.place << "\n";
                        *((yyval.Terminal).code)<< dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place , *(yyval.Terminal).op, (yyvsp[(2) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                    } 
                    //if($$.place != NULL)
                    //print_test("CODE:\n"+ $$.code->str() +"\nplace:" + *$$.place);
                    //print_test($$.code->str());
                  }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 728 "mini_l.y"
    {
                    printf("mult_expr_2 -> MOD mult_expr\n");
                     (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(3) - (3)].Terminal).code->str();
                    if((yyvsp[(3) - (3)].Terminal).op == NULL){
                        (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "%";
                    }
                    else{
                        (yyval.Terminal).place = new_temp();
                        (yyval.Terminal).op = new string();
                        *(yyval.Terminal).op = "%";
                        *((yyval.Terminal).code)<< dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place , *(yyval.Terminal).op, (yyvsp[(2) - (3)].Terminal).place, (yyvsp[(3) - (3)].Terminal).place);
                    } 
                    //print_test($$.code->str());
                  }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 745 "mini_l.y"
    {
                    printf("mult_expr_2 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).op = NULL;
                 }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 752 "mini_l.y"
    {
                    printf("term -> SUB term_2\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (2)].Terminal).code;
                    (yyval.Terminal).place = new_temp();
                    string tmp = to_string("-1");
                    *((yyval.Terminal).code)<< dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place, "*",(yyvsp[(2) - (2)].Terminal).place, &tmp );
                  }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 759 "mini_l.y"
    {
                    printf("term -> term_2\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                    (yyval.Terminal).place = (yyvsp[(1) - (1)].Terminal).place;
                  }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 764 "mini_l.y"
    {
                    printf("term -> term_3\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                    (yyval.Terminal).place = (yyvsp[(1) - (1)].Terminal).place;
                  }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 771 "mini_l.y"
    {
                    printf("term_2 -> var\n");
                    (yyval.Terminal).code = (yyvsp[(1) - (1)].Terminal).code;
                    (yyval.Terminal).place= (yyvsp[(1) - (1)].Terminal).place;
                    (yyval.Terminal).index = (yyvsp[(1) - (1)].Terminal).index;
                  }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 777 "mini_l.y"
    {
                    printf("term_2 -> NUMBER\n");
                    //TODO: probably save number
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).place = new string();
                    *(yyval.Terminal).place = to_string((yyvsp[(1) - (1)].int_val));
                    //printf("%s", &$$.place);
                    //cout << "NUMBER: " << *$$.place << "\n" << $1 << endl;
                  }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 786 "mini_l.y"
    {
                    printf("term_2 -> L_PAREN expression R_PAREN\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    (yyval.Terminal).place = (yyvsp[(2) - (3)].Terminal).place;
                  }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 793 "mini_l.y"
    {
                    printf("term_3 -> IDENT L_PAREN term_31 R_PAREN\n");
                    //cout << "IDENT:" <<  $1 << "\n\n\n\n\n\n";
                    (yyval.Terminal).code = (yyvsp[(3) - (4)].Terminal).code;
                    (yyval.Terminal).place = new_temp();
                    *((yyval.Terminal).code) << dec_temp((yyval.Terminal).place)<< "call " << (yyvsp[(1) - (4)].str_val) << ", " << *(yyval.Terminal).place << "\n";
                    //print_test($$.code->str());
                }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 803 "mini_l.y"
    {
                    printf("term_31-> expression term_32\n");
                    //expression followed by comma of term_31
                    (yyval.Terminal).code = (yyvsp[(1) - (2)].Terminal).code;
                    *((yyval.Terminal).code) << (yyvsp[(2) - (2)].Terminal).code->str();
                    *((yyval.Terminal).code) << "param " << *(yyvsp[(1) - (2)].Terminal).place << "\n";
                }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 810 "mini_l.y"
    {
                    printf("term_31 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream(); 
                  }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 815 "mini_l.y"
    {
                    printf("term_32 -> COMMA term_31\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (2)].Terminal).code;
                }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 819 "mini_l.y"
    {
                    printf("term_32 -> EPSILON\n");
                    (yyval.Terminal).code = new stringstream();
                  }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 824 "mini_l.y"
    {
                    printf("var -> IDENT var_2\n");
                    (yyval.Terminal).code = (yyvsp[(2) - (2)].Terminal).code;
                    (yyval.Terminal).type = (yyvsp[(2) - (2)].Terminal).type;
                    if((yyvsp[(2) - (2)].Terminal).index == NULL){
                        (yyval.Terminal).place = new string();
                        *(yyval.Terminal).place = (yyvsp[(1) - (2)].str_val);
                    }
                    else{
                        //$$.place = new_temp();
                        //*($$.code) << gen_code($$.place, "=[]", &to_string($1), $2.place);
                        (yyval.Terminal).index = (yyvsp[(2) - (2)].Terminal).index;
                        (yyval.Terminal).place = new_temp();
                        string* tmp = new string();
                        *tmp = (yyvsp[(1) - (2)].str_val);
                        *((yyval.Terminal).code) << dec_temp((yyval.Terminal).place) << gen_code((yyval.Terminal).place, "=[]", tmp,(yyvsp[(2) - (2)].Terminal).index);
                        (yyval.Terminal).value = new string();
                        *(yyval.Terminal).value = (yyvsp[(1) - (2)].str_val);
                        //*$$.place = $1;

                        //*$$.place = $1;
                        //print_test($$.code->str());
                    }
                }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 850 "mini_l.y"
    {
                    //$$.code = new stringstream();
                    (yyval.Terminal).code = (yyvsp[(2) - (3)].Terminal).code;
                    (yyval.Terminal).place = NULL;
                    (yyval.Terminal).index = (yyvsp[(2) - (3)].Terminal).place;
                    (yyval.Terminal).type = INT_ARR;
                    //printf("var_2 -> L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");
                }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 858 "mini_l.y"
    {
                    (yyval.Terminal).code = new stringstream();
                    (yyval.Terminal).index = NULL;
                    (yyval.Terminal).place = NULL;
                    (yyval.Terminal).type = INT;
                    //printf("var_2 -> EPSILON\n");
                 }
    break;


/* Line 1792 of yacc.c  */
#line 2658 "y.tab.c"
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


/* Line 2055 of yacc.c  */
#line 867 "mini_l.y"


void print_test(string o){
    cout << "\n---------TEST-----------\n"
        << o
        << "\n----------END -----------\n";
}

//void print_test(stringstream &o){
//    cout << "\n---------TEST-----------\n"
//        << o.str()
//        << "\n----------END -----------\n";
//}

string gen_code(string *res, string op, string *val1, string *val2){
    if(op == "!"){
        return op + " " + *res + ", " + *val1 + "\n";
    }
    else{
        return op + " " + *res + ", " + *val1 + ", "+ *val2 +"\n";
    }
}

string to_string(char* s){
    ostringstream c;
    c << s;
    return c.str();
}

string to_string(int s){
    ostringstream c;
    c << s;
    return c.str();
}
string go_to(string *s){
    return ":= "+ *s + "\n"; 
}
string dec_label(string *s){
    return ": " +*s + "\n"; 
}
string dec_temp(string *s){
    return ". " +*s + "\n"; 
}
string * new_temp(){
    string * t = new string();
    ostringstream conv;
    conv << tempi;
    *t = "__temp__"+ conv.str();
    tempi++;
    return t;
}
string * new_label(){
    string * t = new string();
    ostringstream conv;
    conv << templ;
    *t = "__label__"+ conv.str();
    templ++;
    return t;
}

int main(int argc, char **argv) {

    if ( (argc > 1) && (myin = fopen(argv[1],"r")) == NULL){
        printf("syntax: %s filename\n", argv[0]);
        return 1;
    }

    //    for(int i = 0; i < argc; ++i){
    //        cout << argv[i] << endl;
    //    }

    yyparse();

    //all_code << program_code->str();

    ofstream file;
    file.open("mil_code.mil");
    file << all_code->str();
    file.close();


    return 0;
}


//int main(int argc, char **argv) {
//    if ( (argc > 1) && (yyin = fopen(argv[1],"r")) == NULL){
//        printf("syntax: %s filename\n", argv[0]);
//        return 1;
//    }
//    yyparse();
//    return 0;
//}
//
int yyerror(const char *s)
{
    extern int line_cnt;
    extern int cursor_pos;
    printf(">>> Line %d, position %d: %s\n",line_cnt,cursor_pos,s);
    return -1;
    //return yyerror(string(s));
}


