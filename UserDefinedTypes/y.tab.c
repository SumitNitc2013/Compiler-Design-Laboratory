/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "userDef.y" /* yacc.c:339  */

//remember that you are not executing the code, you are only generating the compiled code
/*if you want the space to be reconized as a token also then put space in single quotes*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "userDef.h"
extern FILE *yyin;
FILE *fp;
#define YYSTYPE tnode*
//int array[50000];
extern int lineNum;
/*Gmem points to the last data entry present in the array*/
int Gmem=512;
int Lmem=0;
int ttoffset=-1; //typetable offset
gsymbol* Ghead=NULL;
lsymbol* Lhead=NULL;
TypeTable* TThead=NULL; //typeTable Head pointer
idlist* id_head=NULL;
idlist* id_tail=NULL;
//field* field_head=NULL;
//field* field_tail=NULL;
#include "userDef.c"

#line 93 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    ID = 259,
    READ = 260,
    WRITE = 261,
    IF = 262,
    THEN = 263,
    ENDIF = 264,
    WHILE = 265,
    DO = 266,
    MAIN = 267,
    RETURN = 268,
    CALL = 269,
    FUNCTION = 270,
    ENDWHILE = 271,
    BEGIN1 = 272,
    END1 = 273,
    DECL = 274,
    ENDDECL = 275,
    ELSE = 276,
    CONNECT = 277,
    LT = 278,
    GT = 279,
    LE = 280,
    GE = 281,
    EQ = 282,
    NE = 283,
    PLUS = 284,
    MINUS = 285,
    MUL = 286,
    DIV = 287,
    MOD = 288,
    EQUALS = 289,
    ARRAY = 290,
    AND = 291,
    OR = 292,
    NOT = 293,
    TYPE1 = 294,
    ENDTYPE1 = 295,
    TYPEDEF = 296,
    FREE = 297,
    ALLOC = 298,
    FLD = 299,
    ENQUE = 300,
    DEQUE = 301,
    DOT = 302
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define READ 260
#define WRITE 261
#define IF 262
#define THEN 263
#define ENDIF 264
#define WHILE 265
#define DO 266
#define MAIN 267
#define RETURN 268
#define CALL 269
#define FUNCTION 270
#define ENDWHILE 271
#define BEGIN1 272
#define END1 273
#define DECL 274
#define ENDDECL 275
#define ELSE 276
#define CONNECT 277
#define LT 278
#define GT 279
#define LE 280
#define GE 281
#define EQ 282
#define NE 283
#define PLUS 284
#define MINUS 285
#define MUL 286
#define DIV 287
#define MOD 288
#define EQUALS 289
#define ARRAY 290
#define AND 291
#define OR 292
#define NOT 293
#define TYPE1 294
#define ENDTYPE1 295
#define TYPEDEF 296
#define FREE 297
#define ALLOC 298
#define FLD 299
#define ENQUE 300
#define DEQUE 301
#define DOT 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,     2,
      54,    55,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    47,    48,    51,    52,    55,    58,    61,
      70,    73,    83,    84,    89,    92,    96,    97,   100,   101,
     104,   116,   117,   120,   121,   122,   125,   126,   129,   141,
     150,   153,   164,   165,   168,   170,   174,   186,   187,   190,
     200,   216,   217,   220,   221,   224,   237,   238,   241,   244,
     247,   248,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   270,   271,
     272,   276,   277,   280,   281,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   306,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "READ", "WRITE", "IF",
  "THEN", "ENDIF", "WHILE", "DO", "MAIN", "RETURN", "CALL", "FUNCTION",
  "ENDWHILE", "BEGIN1", "END1", "DECL", "ENDDECL", "ELSE", "CONNECT", "LT",
  "GT", "LE", "GE", "EQ", "NE", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "EQUALS", "ARRAY", "AND", "OR", "NOT", "TYPE1", "ENDTYPE1", "TYPEDEF",
  "FREE", "ALLOC", "FLD", "ENQUE", "DEQUE", "DOT", "'{'", "'}'", "';'",
  "','", "'['", "']'", "'('", "')'", "'&'", "$accept", "Prog",
  "TypeDefBlock", "TypeDefList", "TypeDef", "HeaDer", "FieldDeclList",
  "FieldDecl", "idlist3", "id3", "type", "GDefblock", "GDefList", "GDecl",
  "GIdList", "GId", "ArgList", "Args", "Arg1", "arg", "idlist", "id",
  "Arg2", "Fdeflist", "FDef", "Header", "LDefblock", "LDeflist", "LDecl",
  "idlist2", "id2", "Body", "S", "stmt", "FIELD", "args", "ars", "E",
  "Ret", "Mainblock", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   123,   125,
      59,    44,    91,    93,    40,    41,    38
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -31

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -37,   -29,    30,    50,    45,    27,  -139,    58,  -139,   113,
    -139,  -139,  -139,  -139,   113,  -139,   116,     7,  -139,   113,
      -1,  -139,   127,   -47,    35,  -139,  -139,  -139,    92,  -139,
      84,  -139,  -139,  -139,  -139,    93,  -139,   131,   172,  -139,
     116,   125,   126,   188,  -139,   127,   124,   137,  -139,   113,
    -139,   172,   153,   113,   194,  -139,  -139,  -139,    -3,  -139,
    -139,   157,   166,   211,    13,  -139,  -139,   178,  -139,   238,
     107,  -139,  -139,   188,  -139,   122,  -139,  -139,  -139,    85,
    -139,  -139,  -139,    -3,   194,  -139,   211,    41,   189,   206,
     221,   222,    22,   227,  -139,    37,   229,  -139,   199,  -139,
      12,   276,    22,   349,    22,    22,    22,  -139,    88,    22,
      22,   246,   259,   365,    16,   382,  -139,  -139,   254,   274,
    -139,   193,    67,    74,   123,   138,   158,    22,    22,  -139,
     173,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,  -139,    71,    81,   269,   289,  -139,
     283,  -139,    69,    22,   318,   337,   350,   390,   388,   208,
     346,   351,   319,  -139,   364,   364,   364,   364,   359,   359,
      32,    32,  -139,  -139,  -139,   348,   334,    22,   353,   354,
     352,  -139,   355,    18,   402,   226,  -139,  -139,  -139,  -139,
    -139,   361,  -139,    22,   241,  -139,  -139,   360,  -139,   357,
     304,  -139,    83,    73,    95,   319,    86,  -139,   358,  -139,
     362,   366,  -139,   367,   368,   369,  -139,  -139,   103,  -139,
    -139,  -139,   370,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,    17,     0,     0,     6,     0,     1,     0,
      38,     8,     3,     5,     0,    15,     0,     0,    19,     0,
       0,    10,     0,    23,     0,    22,    16,    18,     0,    37,
       0,     2,     7,     9,    14,     0,    13,     0,    27,    20,
       0,     0,     0,    42,    11,     0,     0,     0,    26,     0,
      21,    27,     0,     0,     0,    12,    24,    25,     0,    29,
      28,     0,     0,     0,     0,    44,    51,     0,    34,     0,
      36,    33,    40,    42,    48,     0,    47,    41,    43,     0,
      39,    35,    31,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,    32,     0,    46,
       0,     0,     0,     0,     0,     0,     0,    92,    93,     0,
       0,    91,     0,     0,     0,     0,    49,    96,     0,     0,
      69,     0,     0,     0,     0,     0,     0,     0,    72,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,    68,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    74,    80,    81,    82,    85,    86,    83,    84,
      75,    76,    77,    78,    79,    87,    88,     0,     0,     0,
       0,    54,     0,     0,     0,     0,    55,    57,    58,    51,
      51,    94,    90,     0,     0,    65,    67,     0,    62,     0,
       0,    70,     0,     0,     0,    73,     0,    64,     0,    53,
       0,     0,    51,     0,     0,     0,    56,    60,     0,    61,
      66,    63,     0,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,   404,  -139,  -139,   394,  -139,   376,
       9,  -139,  -139,   398,  -139,   383,   371,  -139,  -139,  -139,
    -139,   341,  -139,  -139,  -139,  -139,   356,  -139,   363,  -139,
     339,   342,  -138,  -139,   -79,  -139,  -139,   -96,  -139,  -139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,     7,    20,    21,    35,    36,
      16,    10,    17,    18,    24,    25,    47,    48,    49,    59,
      70,    71,    60,    19,    29,    30,    54,    64,    65,    75,
      76,    67,    79,    94,   111,   160,   161,   112,    96,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    68,     1,    15,   119,    37,   121,    38,   124,   125,
     126,    15,     4,   129,   130,   107,   108,    15,   148,   107,
     108,   107,   108,    22,   123,   107,   108,    26,    28,    22,
       8,   159,   162,    77,   146,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    32,    11,
     109,   203,   204,    69,   109,   118,   109,   185,    58,   147,
     109,   199,    63,   139,   140,   141,   110,    12,     4,     9,
     110,   114,   110,    63,   218,   100,   110,    87,    88,    89,
      90,   194,   211,    91,   115,    39,    40,   200,   101,    87,
      88,    89,    90,   102,   212,    91,    41,   205,    92,    87,
      88,    89,    90,   183,    42,    91,    14,    87,    88,    89,
      90,   213,   222,    91,   101,    93,   184,    15,   101,   153,
      23,   115,   154,   177,    95,    95,   178,    93,   115,   155,
     184,    34,    43,   184,    46,   101,   179,    93,   210,    95,
     127,   214,   128,    44,    45,    93,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    82,    83,   142,
     143,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    85,    86,   142,   143,   -30,    56,   156,    51,
      52,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    57,   157,   142,   143,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    53,    62,   142,
     143,    66,    72,   158,    73,    74,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    80,   163,   142,
     143,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    81,   103,   142,   143,   152,   116,   117,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     104,   191,   142,   143,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   105,   106,   142,   143,   202,
     120,   113,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   115,   206,   142,   143,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   150,   144,
     142,   143,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   180,   151,   142,   143,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   182,   181,
     142,   143,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   122,   209,   142,   143,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   186,   145,
     142,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   131,   132,   133,   134,   149,   187,   137,   138,
     139,   140,   141,   137,   138,   139,   140,   141,   189,   190,
     188,   192,   193,   195,   196,   198,   201,   197,   184,    13,
     207,   208,   216,   215,    33,    27,   217,   219,   220,   221,
     223,    55,    61,    50,    97,    99,    98,    78,     0,    84
};

static const yytype_int16 yycheck[] =
{
      79,     4,    39,     4,   100,    52,   102,    54,   104,   105,
     106,     4,    41,   109,   110,     3,     4,     4,   114,     3,
       4,     3,     4,    14,   103,     3,     4,    20,    19,    20,
       0,   127,   128,    20,   113,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    49,     4,
      38,   189,   190,    56,    38,    43,    38,   153,    49,    43,
      38,    43,    53,    31,    32,    33,    54,    40,    41,    19,
      54,    34,    54,    64,   212,    34,    54,     4,     5,     6,
       7,   177,     9,    10,    47,    50,    51,   183,    47,     4,
       5,     6,     7,    52,    21,    10,     4,   193,    13,     4,
       5,     6,     7,    34,    12,    10,    48,     4,     5,     6,
       7,    16,     9,    10,    47,    42,    47,     4,    47,    52,
       4,    47,    55,    52,   203,   204,    55,    42,    47,    55,
      47,     4,    48,    47,     3,    47,    55,    42,    55,   218,
      52,    55,    54,    50,    51,    42,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    50,    51,    36,
      37,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    50,    51,    36,    37,     4,    53,    55,    54,
      54,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    55,    55,    36,    37,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    19,    55,    36,
      37,    17,    55,    55,    48,     4,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    49,    55,    36,
      37,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     4,    54,    36,    37,    53,    18,    49,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      54,    53,    36,    37,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    54,    54,    36,    37,    53,
       4,    54,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    47,    53,    36,    37,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    54,    50,
      36,    37,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    54,    50,    36,    37,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    55,    50,
      36,    37,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     4,    50,    36,    37,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    50,     4,
      36,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    23,    24,    25,    26,     4,    50,    29,    30,
      31,    32,    33,    29,    30,    31,    32,    33,     8,    11,
      50,    55,    51,    50,    50,    50,     4,    55,    47,     5,
      50,    54,    50,    55,    20,    17,    50,    50,    50,    50,
      50,    45,    51,    40,    83,    86,    84,    64,    -1,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    58,    59,    41,    60,    61,    62,     0,    19,
      68,     4,    40,    61,    48,     4,    67,    69,    70,    80,
      63,    64,    67,     4,    71,    72,    20,    70,    67,    81,
      82,    96,    49,    64,     4,    65,    66,    52,    54,    50,
      51,     4,    12,    48,    50,    51,     3,    73,    74,    75,
      72,    54,    54,    19,    83,    66,    53,    55,    67,    76,
      79,    73,    55,    67,    84,    85,    17,    88,     4,    56,
      77,    78,    55,    48,     4,    86,    87,    20,    85,    89,
      49,     4,    50,    51,    83,    50,    51,     4,     5,     6,
       7,    10,    13,    42,    90,    91,    95,    78,    88,    87,
      34,    47,    52,    54,    54,    54,    54,     3,     4,    38,
      54,    91,    94,    54,    34,    47,    18,    49,    43,    94,
       4,    94,     4,    91,    94,    94,    94,    52,    54,    94,
      94,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    36,    37,    50,     4,    91,    43,    94,     4,
      54,    50,    53,    52,    55,    55,    55,    55,    55,    94,
      92,    93,    94,    55,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    52,    55,    55,
      54,    50,    55,    34,    47,    94,    50,    50,    50,     8,
      11,    53,    55,    51,    94,    50,    50,    55,    50,    43,
      94,     4,    53,    89,    89,    94,    53,    50,    54,    50,
      55,     9,    21,    16,    55,    55,    50,    50,    89,    50,
      50,    50,     9,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    62,    63,
      63,    64,    65,    65,    66,    67,    68,    68,    69,    69,
      70,    71,    71,    72,    72,    72,    73,    73,    74,    75,
      75,    76,    77,    77,    78,    78,    79,    80,    80,    81,
      82,    83,    83,    84,    84,    85,    86,    86,    87,    88,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     0,     2,     1,     4,     2,     2,
       1,     3,     3,     1,     1,     1,     3,     0,     2,     1,
       3,     3,     1,     1,     4,     4,     1,     0,     2,     2,
       0,     3,     3,     1,     1,     2,     2,     2,     0,     5,
       5,     3,     0,     2,     1,     3,     3,     1,     1,     4,
       2,     0,     4,     7,     4,     5,     8,     5,     5,    10,
       8,     8,     6,     9,     6,     5,     8,     5,     3,     3,
       6,     1,     0,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       4,     1,     1,     1,     4,     3,     8
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
#line 44 "userDef.y" /* yacc.c:1646  */
    {Initialize();Allocate();Free();printf("Successful\n");exit(0);}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 55 "userDef.y" /* yacc.c:1646  */
    {AddFieldsInTT((yyvsp[-3])->NAME,(yyvsp[-1]));ttoffset=-1;}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 58 "userDef.y" /* yacc.c:1646  */
    {TTinstall(make_TypeTable_node((yyvsp[0])->NAME,NULL));(yyval)=(yyvsp[0]);}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "userDef.y" /* yacc.c:1646  */
    {
	 											if((yyvsp[-1])==NULL) 
													(yyval)=(yyvsp[0]); 
												else 
												{
													(yyvsp[-1])->mid->right=(yyvsp[0]);
													(yyval)=(yyvsp[-1]);
												}	
	 										}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 70 "userDef.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 73 "userDef.y" /* yacc.c:1646  */
    {    tnode* temp=(yyvsp[-1]);
										while(temp!=NULL)
												{
														temp->TYPE=(yyvsp[-2])->TYPE;
														temp=temp->right;
												}
										(yyval)=(yyvsp[-1]);
	 								}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 83 "userDef.y" /* yacc.c:1646  */
    {/*checkField($1,$2);*/(yyvsp[-2])->mid->right=(yyvsp[0]);(yyvsp[-2])->mid=(yyvsp[0]);(yyval)=(yyvsp[-2]);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "userDef.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 89 "userDef.y" /* yacc.c:1646  */
    {checkName((yyvsp[0])->NAME);(yyvsp[0])->val=ttoffset+1;ttoffset++;(yyvsp[0])->mid=(yyvsp[0]);(yyvsp[0])->right=NULL;(yyval)=(yyvsp[0]);}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 92 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[0])->TYPE= FieldTypeCheck((yyvsp[0])->NAME);(yyval)=(yyvsp[0]);}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "userDef.y" /* yacc.c:1646  */
    {StartupCodeGen(Gmem);}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 97 "userDef.y" /* yacc.c:1646  */
    {StartupCodeGen(Gmem);}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 104 "userDef.y" /* yacc.c:1646  */
    {
								while(id_head!=NULL)
									{
											idlist *temp=id_head;
											Ginstall(make_gsymbol_node(id_head->NAME, (yyvsp[-2])->TYPE,id_head->size,id_head->arglst));
											id_head=id_head->next;
											free(temp);
									}
								id_tail=NULL;
							}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "userDef.y" /* yacc.c:1646  */
    {checkName((yyvsp[0])->NAME);insert_id(make_id_node((yyvsp[0])->NAME,1,NULL));}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 121 "userDef.y" /* yacc.c:1646  */
    {checkName((yyvsp[-3])->NAME);insert_id(make_id_node((yyvsp[-3])->NAME,(yyvsp[-1])->val,NULL));}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 122 "userDef.y" /* yacc.c:1646  */
    {checkName((yyvsp[-3])->NAME);insert_id(make_id_node((yyvsp[-3])->NAME,-2,(yyvsp[-1])));}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 125 "userDef.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 126 "userDef.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "userDef.y" /* yacc.c:1646  */
    {
							if((yyvsp[-1])==NULL)
								(yyval)=(yyvsp[0]);
							else
							{
								(yyvsp[-1])->mid->Arglist=(yyvsp[0]);
								(yyval)=(yyvsp[-1]);
							}

						}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 141 "userDef.y" /* yacc.c:1646  */
    {	if((yyvsp[-1])==NULL) 
								(yyval)=(yyvsp[0]); 
							else 
							{
								(yyvsp[-1])->mid->Arglist=(yyvsp[0]);
								(yyval)=(yyvsp[-1]);
							}	
						}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 150 "userDef.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 153 "userDef.y" /* yacc.c:1646  */
    {
								tnode* temp=(yyvsp[-1]);
								while(temp!=NULL)
										{
												temp->TYPE=(yyvsp[-2])->TYPE;
												temp=temp->Arglist;
										}
								(yyval)=(yyvsp[-1]);
							}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 164 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-2])->mid->Arglist=(yyvsp[0]);(yyvsp[-2])->mid=(yyvsp[0]);(yyval)=(yyvsp[-2]);}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 165 "userDef.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "userDef.y" /* yacc.c:1646  */
    {checkName((yyvsp[0])->NAME);(yyvsp[0])->val=0; (yyvsp[0])->mid=(yyvsp[0]); (yyvsp[0])->Arglist=NULL; (yyval)=(yyvsp[0]);}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 170 "userDef.y" /* yacc.c:1646  */
    {checkName((yyvsp[0])->NAME);(yyvsp[0])->val=1; (yyvsp[0])->mid=(yyvsp[0]); (yyvsp[0])->Arglist=NULL; (yyval)=(yyvsp[0]);}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 174 "userDef.y" /* yacc.c:1646  */
    {
							tnode* temp=(yyvsp[0]);
							while(temp!=NULL)
									{
											temp->TYPE=(yyvsp[-1])->TYPE;
											temp=temp->Arglist;
									}
								(yyval)=(yyvsp[0]);
							}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 190 "userDef.y" /* yacc.c:1646  */
    {		
											(yyvsp[-4])->left=(yyvsp[-1]);   //body of function
											(yyval)=(yyvsp[-4]);
											checkReturnType((yyvsp[-4])->NAME, (yyvsp[-4])->TYPE,(yyvsp[-1])->right);
											FunctionCodegen((yyval));
											Lhead=NULL;
											Lmem=0;
									}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 200 "userDef.y" /* yacc.c:1646  */
    {
										checkName((yyvsp[-3])->NAME);
										(yyvsp[-3])->TYPE=(yyvsp[-4])->TYPE;
										(yyvsp[-3])->NODETYPE=FUNCTION;
										(yyvsp[-3])->Arglist=(yyvsp[-1]);
										(yyval)=(yyvsp[-3]);
										/*while(temp!=NULL)
										{
											printf("Argument=%s, type=%d\n",temp->NAME,temp->TYPE);
											temp=temp->Arglist;
										}*/
										functionHeaderCheck((yyvsp[-4])->TYPE,(yyvsp[-3])->NAME,(yyvsp[-1]));
										PutArgumentsInSymTable((yyvsp[-1]));
								}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 224 "userDef.y" /* yacc.c:1646  */
    {
								while(id_head!=NULL)
									{
											idlist *temp=id_head;
											Linstall(make_lsymbol_node(id_head->NAME, (yyvsp[-2])->TYPE));
											id_head=id_head->next;
											free(temp);
									}
								id_tail=NULL;

							}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 241 "userDef.y" /* yacc.c:1646  */
    {checkName((yyvsp[0])->NAME);insert_id(make_id_node((yyvsp[0])->NAME,1,NULL));}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 244 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(CONNECT,(yyvsp[-2]),NULL,(yyvsp[-1]));}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 247 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(CONNECT,(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 248 "userDef.y" /* yacc.c:1646  */
    { (yyval)=NULL;}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 251 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(EQUALS,(yyvsp[-3]),NULL,(yyvsp[-1]));}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 252 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(EQUALS,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1]));}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 253 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-3])=makeNameNode(FLD,(yyvsp[-3]),NULL,NULL); (yyval)=makeNameNode(EQUALS,(yyvsp[-3]),NULL,(yyvsp[-1]));}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 254 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(READ,(yyvsp[-2]),NULL,NULL);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 255 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(READ,(yyvsp[-5]),(yyvsp[-3]),NULL);}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 256 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-2])=makeNameNode(FLD,(yyvsp[-2]),NULL,NULL);(yyval)=makeNameNode(READ,(yyvsp[-2]),NULL,NULL);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 257 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(WRITE,(yyvsp[-2]),NULL,NULL);}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 258 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(IF,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 259 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(IF,(yyvsp[-5]),NULL,(yyvsp[-2]));}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 260 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(WHILE,(yyvsp[-5]),NULL,(yyvsp[-2]));}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 261 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(EQUALS,(yyvsp[-5]),NULL,(yyvsp[-3]));}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 262 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(EQUALS,(yyvsp[-8]),(yyvsp[-6]),(yyvsp[-3]));}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 263 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-5])=makeNameNode(FLD,(yyvsp[-5]),NULL,NULL);(yyval)=makeNameNode(EQUALS,(yyvsp[-5]),NULL,(yyvsp[-3]));}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-4])->left=(yyvsp[-2]);(yyval)=(yyvsp[-4]);}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 265 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-5])=makeNameNode(ARRAY,(yyvsp[-5]),NULL,(yyvsp[-3]));(yyvsp[-7])->left=(yyvsp[-5]);(yyval)=(yyvsp[-7]);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 266 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-2])=makeNameNode(FLD,(yyvsp[-2]),NULL,NULL);(yyvsp[-4])->left=(yyvsp[-2]);(yyval)=(yyvsp[-4]);}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 270 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-2])->mid->Arglist=(yyvsp[0]);(yyvsp[-2])->mid=(yyvsp[0]);(yyval)=(yyvsp[-2]);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 271 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-2])->Arglist=(yyvsp[0]);(yyvsp[-2])->mid=(yyvsp[0]); (yyval)=(yyvsp[-2]);}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 272 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[0])->Arglist=NULL;(yyvsp[-5])=makeNameNode(ARRAY,(yyvsp[-5]),NULL,(yyvsp[-3]));(yyvsp[-5])->Arglist=(yyvsp[0]);(yyvsp[-5])->mid=(yyvsp[0]);(yyval)=(yyvsp[-5]);}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 276 "userDef.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 277 "userDef.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 280 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[-2])->mid->Arglist=(yyvsp[0]);(yyvsp[-2])->mid=(yyvsp[0]);(yyval)=(yyvsp[-2]);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 281 "userDef.y" /* yacc.c:1646  */
    {(yyvsp[0])->Arglist=NULL,(yyvsp[0])->mid=(yyvsp[0]);(yyval)=(yyvsp[0]);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 284 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(PLUS,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 285 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(MINUS,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 286 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(MUL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 287 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(DIV,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 288 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(MOD,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 289 "userDef.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 290 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(LT,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 291 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(GT,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 292 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(EQ,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 293 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(NE,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 294 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(LE,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 295 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(GE,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 296 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(AND,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 297 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(OR,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 298 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(NOT,(yyvsp[0]),NULL,NULL);}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 299 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(CALL,(yyvsp[-3]),NULL,(yyvsp[-1]));}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 300 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(FLD,(yyvsp[0]),NULL,NULL);}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 301 "userDef.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 302 "userDef.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 303 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(ARRAY,(yyvsp[-3]),NULL,(yyvsp[-1]));}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 306 "userDef.y" /* yacc.c:1646  */
    {(yyval)=makeNameNode(RETURN,(yyvsp[-1]),NULL,NULL);}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 309 "userDef.y" /* yacc.c:1646  */
    {  
														(yyval)=(tnode*)malloc(sizeof(tnode));
														(yyval)->NAME=(char*)malloc(50*sizeof(char));
														(yyval)->TYPE=(yyvsp[-7])->TYPE;
														strcpy((yyval)->NAME,"main");
														(yyval)->NODETYPE=FUNCTION;
														(yyval)->Arglist=NULL;
														(yyval)->left=(yyvsp[-1]);
														if(strcmp((yyvsp[-7])->TYPE->NAME,"integer")!=0)
														{
															printf("Error at line number %d!!!\nReturn type of main must be integer\n",lineNum);
															exit(0);
														}
														if((yyvsp[-1])->right->TYPE!=(yyvsp[-7])->TYPE)
														{
															printf("Error at line Number %d !!\nReturn Type of return statement for main function must be integer\n",lineNum);
															exit(0);
														}
														//printf("going to code gen for main\n");
														FunctionCodegen((yyval));
														//printf("gngreated code for main\n");
														Lhead=NULL;
														Lmem=0;
													}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2088 "y.tab.c" /* yacc.c:1646  */
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
#line 335 "userDef.y" /* yacc.c:1906  */


yyerror(const char* x)
{
	printf("%s at line Number %d\n",x,lineNum);
}

int main(int argc,char* argv[])
{
	fp = fopen("outfile.asm","w+");
	if(argc==2)
	{
		yyin=fopen(argv[1],"r");
	}
	TTinstall(make_TypeTable_node("integer",NULL));
	TTinstall(make_TypeTable_node("boolean",NULL));
	yyparse();
	fclose(fp);
	return 0;
}

 	

	

