%{
	//multiline program
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
op [-+*^/=]


%%
"read" {return READ;}
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
"integer" {yylval=makeNameNode("INT",NULL,NULL,NULL);return INT;}
"boolean" {yylval=makeNameNode("BOOL",NULL,NULL,NULL);return BOOL;}
"else" {return ELSE;}
" " {}
"," {return *yytext;}
";" {return *yytext;}
[()] {return *yytext;}
"\n" {}
[<] {return *yytext;}
[>]  {return *yytext;}
"==" {return '#';}
"[" {return '[';}
"]" {return ']';}
[\t] {}
{number} {num=atoi(yytext); yylval=makeNumLeafNode(num);return NUM;}
{variable} {gsymbol *temp;
			 temp=lookup(yytext);
			 if(temp==NULL)
			 {
			 	yylval=makeVarLeafNode(yytext);
			 	return ID1;
			 }
			 else
			 {
			 	yylval=temp->nod;
			 	return ID2;
			 }
			}
			  
{op} {return *yytext;}
%%

yywrap()
{
	return 1;
}




