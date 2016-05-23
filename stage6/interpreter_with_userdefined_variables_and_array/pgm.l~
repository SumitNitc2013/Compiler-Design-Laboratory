%{
	//multiline program
	//no type infromation for this stage every variable
	//and array is of integer type
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "pgm.h"
	#define YYSTYPE tnode*
	#include "y.tab.h"
	int num;
	//#include "pgm.c"

%}

number [0-9]+
variable [a-zA-Z][a-zA-Z0-9]*

%%
"read"  { return READ;}
"write" {return WRITE;}
"if"	{return IF;}
"then"	{return THEN;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do"    {return DO;}
"endwhile"  {return ENDWHILE;}
"decl" {return DECL;}
"enddecl" {return ENDDECL;}
"begin" {return BEGIN1;}
"end" {return END1;}
"else" {return ELSE;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
"=" {return EQUALS;}
"<" {return LT;}
">"  {return GT;}
"<=" {return LE;}
">=" {return GE;}
"==" {return EQ;}
"!=" {return NE;}
" " {}
"," {return *yytext;}
";" {return *yytext;}
"(" {return *yytext;}
")" {return *yytext;}
"\n" {}
"[" {return *yytext;}
"]" {return *yytext;}
"\t" {}
{number} {num=atoi(yytext); yylval=makeNumLeafNode(num);return NUM;}
{variable} {
				yylval=makeVarLeafNode(yytext);
				yylval->Gentry=lookup(yytext);
				return ID;
		   }
			  
%%

yywrap()
{
	return 1;
}



