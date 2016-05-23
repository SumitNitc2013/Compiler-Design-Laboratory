%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "stline.h"
	#define YYSTYPE tnode*
	#include "y.tab.h"
	int num;
	char var;

%}

number [0-9]+
variable [a-z]

%%
{number} {num=atoi(yytext); yylval=makeNumLeafNode(num);return NUM;}
{variable} {var = *yytext;yylval=makeVarLeafNode(var);return ID;}
"read" {return READ;}
"write" {return WRITE;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return  DIV;}
"%" {return MOD;}
"=" {return EQUALS;}
";" {return *yytext;}
"\n" {return *yytext;}
"(" {return *yytext;}
")" {return *yytext;}
" " {}
"\t" {}
%%

yywrap()
{
	return 1;
}



