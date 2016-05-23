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
op [-+*^/=]


%%
{number} {num=atoi(yytext); yylval=makeNumLeafNode(num);return NUM;}
{variable} {var = *yytext;yylval=makeVarLeafNode(var);return ID;}
{op} {return *yytext;}
"read" {return READ;}
"write" {return WRITE;}
"if"	{return IF;}
"then"	{return THEN;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do"    {return DO;}
"endwhile"  {return ENDWHILE;}
" " {}
[;] {return *yytext;}
[()] {return *yytext;}
[\n] {}
"{" {return '{';}
"}" {return '}';}
[<] {return *yytext;}
[>]  {return *yytext;}
"==" {return '#';}
[\t] {}
%%

yywrap()
{
	return 1;
}




