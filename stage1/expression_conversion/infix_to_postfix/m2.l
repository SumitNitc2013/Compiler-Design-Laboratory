%{
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	
%}

number [0-9]+

%%
{number} {yylval=atoi(yytext);
	  return NUM;
	}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return  DIV;}
"%" {return MOD;}
"(" {return *yytext;}
")" {return *yytext;}
"\n" {return *yytext;}
" "  {}
"\t" {}
%%

yywrap()
{
	return 1;
}





