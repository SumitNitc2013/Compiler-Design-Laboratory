%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exptree.h"
	#define YYSTYPE tnode*
	#include "y.tab.h"
	int num;

%}

number [0-9]+


%%
{number} {num=atoi(yytext); yylval=makeLeafNode(num);return NUM;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return  DIV;}
"%" {return MOD;}
"(" {return *yytext;}
")" {return *yytext;}
"\n" {return *yytext;}
" " {}
"\t" {}
%%

yywrap()
{
	return 1;
}


