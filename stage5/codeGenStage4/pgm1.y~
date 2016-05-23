%{
//if you want the space to be reconized as a token also then put space in single quotes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int array[26]={0};
#define YYSTYPE tnode*	
#include "pgm.h"
#include "pgm.c"
int x;	
%}

%token NUM ID READ WRITE IF THEN ENDIF WHILE DO ENDWHILE
%left '{' '}'
%right '='
%left '<' '>' '#'
%left '+' '-'
%left '*' '/'
%right '^'

%%  
	start: '{' start '}'     {evaluate($2);exit(0);}
	     | start stmt  	 {char c[10];strcpy(c,"pt");$$=makeNameNode(c,$1,$2);}
	     | stmt          {$$=$1;}
	     ;
	stmt: ID'='E';'       {char c[10];strcpy(c,"=");$$=makeNameNode(c,$1,$3);}
	    | READ'('ID')'';' {char c[10];strcpy(c,"READ");$$=makeNameNode(c,$3,NULL);}
	    | WRITE'('E')'';' {char c[10];strcpy(c,"WRITE");$$=makeNameNode(c,$3,NULL);}
        | IF '('E')' THEN start ENDIF';' {char c[10];strcpy(c,"IF");$$=makeNameNode(c,$3,$6);}
	    | WHILE '('E')' DO start ENDWHILE';' {char c[10];strcpy(c,"WHILE");$$=makeNameNode(c,$3,$6);}
	    | E
	    ;

	  E: E '+' E	{char c[10];strcpy(c,"+");$$=makeNameNode(c,$1,$3);}
	   | E '-' E	{char c[10];strcpy(c,"-");$$=makeNameNode(c,$1,$3);}
       | E '*' E	{char c[10];strcpy(c,"*");$$=makeNameNode(c,$1,$3);}
	   | E '/' E	{char c[10];strcpy(c,"/");$$=makeNameNode(c,$1,$3);}
	   | E '^' E   {char c[10];strcpy(c,"^");$$=makeNameNode(c,$1,$3);}
	   | '('E')'   {$$=$2;}
	   | E '<' E {char c[10];strcpy(c,"<");$$=makeNameNode(c,$1,$3);}
	   | E '>' E {char c[10];strcpy(c,">");$$=makeNameNode(c,$1,$3);}
	   | E '#' E {char c[10];strcpy(c,"==");$$=makeNameNode(c,$1,$3);}
	   | ID        {$$=$1;}
	   | NUM       {$$=$1;}
	   | ';'      {exit(0);}
	   ;
%%

 yyerror(const char* x)
{
	printf("error %s\n",x);
}

main()
{
	yyparse();
	return 0;
}

 	

	

