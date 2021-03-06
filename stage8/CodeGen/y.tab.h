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
    ENDWHILE = 267,
    BEGIN1 = 268,
    END1 = 269,
    DECL = 270,
    ENDDECL = 271,
    INT = 272,
    BOOL = 273,
    VOID = 274,
    ELSE = 275,
    CONNECT = 276,
    LT = 277,
    GT = 278,
    LE = 279,
    GE = 280,
    EQ = 281,
    NE = 282,
    PLUS = 283,
    MINUS = 284,
    MUL = 285,
    DIV = 286,
    MOD = 287,
    EQUALS = 288,
    ARRAY = 289
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
#define ENDWHILE 267
#define BEGIN1 268
#define END1 269
#define DECL 270
#define ENDDECL 271
#define INT 272
#define BOOL 273
#define VOID 274
#define ELSE 275
#define CONNECT 276
#define LT 277
#define GT 278
#define LE 279
#define GE 280
#define EQ 281
#define NE 282
#define PLUS 283
#define MINUS 284
#define MUL 285
#define DIV 286
#define MOD 287
#define EQUALS 288
#define ARRAY 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
