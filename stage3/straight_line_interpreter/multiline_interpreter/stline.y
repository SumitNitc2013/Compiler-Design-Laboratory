%{
//if you want the space to be reconized as a token also then put space in single quotes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int array[26]={0};
#define YYSTYPE tnode*	
#include "stline.h"
#include "stline.c"
extern FILE *yyin;
int x;	
%}

%token NUM PLUS MINUS MUL DIV MOD ID 
%token BEGIN1 END READ WRITE EQUALS CONNECT
%left PLUS MINUS
%left MUL DIV
%left MOD

%%  
	start: BEGIN1 start END {evaluate($2);}
	     | start stmt    {$$=makeNameNode(CONNECT,$1,$2);}
	     | stmt          {$$=$1;}
	     ;
	stmt: ID EQUALS E';'    {$$=makeNameNode(EQUALS,$1,$3);}
	    | READ'('ID')'';' {$$=makeNameNode(READ,$3,NULL);}
	    | WRITE'('E')'';' {$$=makeNameNode(WRITE,$3,NULL);}
	    ;

	  E: E PLUS E	{$$=makeNameNode(PLUS,$1,$3);}
	   | E MINUS E	{$$=makeNameNode(MINUS,$1,$3);}
       | E MUL E	{$$=makeNameNode(MUL,$1,$3);}
	   | E DIV E	{$$=makeNameNode(DIV,$1,$3);}
	   | E MOD E   {$$=makeNameNode(MOD,$1,$3);}
	   | '('E')'   {$$=$2;}
	   | ID        {$$=$1;}
	   | NUM       {$$=$1;}
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
 	

	

