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
    INT = 276,
    BOOL = 277,
    VOID = 278,
    ELSE = 279,
    CONNECT = 280,
    LT = 281,
    GT = 282,
    LE = 283,
    GE = 284,
    EQ = 285,
    NE = 286,
    PLUS = 287,
    MINUS = 288,
    MUL = 289,
    DIV = 290,
    MOD = 291,
    EQUALS = 292,
    ARRAY = 293,
    AND = 294,
    OR = 295,
    NOT = 296
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
#define INT 276
#define BOOL 277
#define VOID 278
#define ELSE 279
#define CONNECT 280
#define LT 281
#define GT 282
#define LE 283
#define GE 284
#define EQ 285
#define NE 286
#define PLUS 287
#define MINUS 288
#define MUL 289
#define DIV 290
#define MOD 291
#define EQUALS 292
#define ARRAY 293
#define AND 294
#define OR 295
#define NOT 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
