/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
