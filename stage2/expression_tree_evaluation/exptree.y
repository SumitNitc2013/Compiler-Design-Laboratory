%{
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define YYSTYPE tnode*	
#include "exptree.h"
#include "exptree.c"
extern FILE *yyin;
%}

%token NUM PLUS MINUS MUL DIV MOD
%left PLUS MINUS
%left MUL DIV
%left MOD

%%  
	start: expr '\n'       {printf("%d\n",evalute($1));}
	     ;
	expr: expr PLUS expr     {$$=makeOperatorNode(PLUS,$1,$3);}
	    | expr MINUS expr     {$$=makeOperatorNode(MINUS,$1,$3);}
	    | expr MUL expr     {$$=makeOperatorNode(MUL,$1,$3);}
        | expr DIV expr     {$$=makeOperatorNode(DIV,$1,$3);}
        | expr MOD expr     {$$=makeOperatorNode(MOD,$1,$3);}
        | '('expr')'     {$$=$2;}
 	    |  NUM				{$$=$1;}
	    ;
%%

 yyerror(const char* x)
{
	printf("error %s\n",x);
}

main(int argc,char* argv[])
{
    if(argc==2)
    {
        yyin=fopen(argv[1],"r");
    }
    yyparse();
    return 0;
}
 	

	