%{
//if you want the space to be reconized as a token also then put space in single quotes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
extern FILE *yyin;
FILE *fp;
int array[26]={0};
#define YYSTYPE tnode*	
#include "pgm.h"
#include "pgm.c"
int x;	
%}

%token NUM ID READ WRITE IF THEN ENDIF WHILE DO 
%token ENDWHILE BEGIN1 END CONNECT
%token LT GT EQ PLUS MINUS MUL DIV MOD EQUALS
%left LT GT EQ
%left PLUS MINUS
%left MUL DIV MOD

%%  
	start: BEGIN1 start END {CodeGen($2);}
	     | start stmt    {$$=makeNameNode(CONNECT,$1,$2);}
	     | stmt          {$$=$1;}
	     ;
	stmt: ID EQUALS E';'    {$$=makeNameNode(EQUALS,$1,$3);}
	    | READ'('ID')'';' {$$=makeNameNode(READ,$3,NULL);}
	    | WRITE'('E')'';' {$$=makeNameNode(WRITE,$3,NULL);}
	    | IF '('E')' THEN start ENDIF';' 		{$$=makeNameNode(IF,$3,$6);}
	    | WHILE '('E')' DO start ENDWHILE';' 	{$$=makeNameNode(WHILE,$3,$6);}
	    ;

	  E: E PLUS E	{$$=makeNameNode(PLUS,$1,$3);}
	   | E MINUS E	{$$=makeNameNode(MINUS,$1,$3);}
       | E MUL E	{$$=makeNameNode(MUL,$1,$3);}
	   | E DIV E	{$$=makeNameNode(DIV,$1,$3);}
	   | E MOD E   {$$=makeNameNode(MOD,$1,$3);}
	   | E LT E 	{$$=makeNameNode(LT,$1,$3);}
	   | E GT E 	{$$=makeNameNode(GT,$1,$3);}
	   | E EQ E 	{$$=makeNameNode(EQ,$1,$3);}
	   | '('E')'   {$$=$2;}
	   | ID        {$$=$1;}
	   | NUM       {$$=$1;}
	   ;
%%

 yyerror(const char* x)
{
	printf("error %s\n",x);
}

int main(int argc,char* argv[])
{
	fp = fopen("outfile.asm","w");
	fprintf(fp, "START\n");
	if(argc==2)
	{
		yyin=fopen(argv[1],"r");
	}
	yyparse();
	fprintf(fp, "HALT\n");
	fclose(fp);
	return 0;
}

