%{
	//multiline program
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "pgm.h"
	#define YYSTYPE tnode*
	#include "y.tab.h"
	int num;
	char var;

%}

number [0-9]+
variable [a-z]


%%
"read" {return READ;}
"write" {return WRITE;}
"if"	{return IF;}
"then"	{return THEN;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do"    {return DO;}
"endwhile"  {return ENDWHILE;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return  DIV;}
"%" {return MOD;}
"=" {return EQUALS;}
"<" {return LT;}
">"  {return GT;}
"==" {return EQ;}
"begin" {return BEGIN1;}
"end" {return END;}
";" {return *yytext;}
"(" {return *yytext;}
")" {return *yytext;}
"\n" {}
" "  {}
"\t" {}
{number} {num=atoi(yytext); yylval=makeNumLeafNode(num);return NUM;}
{variable} {var = *yytext;yylval=makeVarLeafNode(var);return ID;}

%%

yywrap()
{
	return 1;
}




