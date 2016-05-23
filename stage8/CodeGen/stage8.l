%{
	//multiline program
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "stage8.h"
	#define YYSTYPE tnode*
	#include "y.tab.h"
	
	int num;

%}

number [0-9]+
variable [a-zA-Z][a-zA-Z0-9]*

%%
"read"  { return READ;}
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
"integer" {yylval=makeNameNode(INT,NULL,NULL,NULL);return INT;}
"boolean" {yylval=makeNameNode(BOOL,NULL,NULL,NULL);return BOOL;}
"else" {return ELSE;}
"<" {return LT;}
">"  {return GT;}
"<=" {return LE;}
">=" {return GE;}
"==" {return EQ;}
"!=" {return NE;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
"=" {return EQUALS;}
"," {return *yytext;}
";" {return *yytext;}
"(" {return *yytext;}
")" {return *yytext;}
"[" {return *yytext;}
"]" {return *yytext;}
" " {}
"\n" {}
[\t] {}
{number} {num=atoi(yytext); yylval=makeNumLeafNode(num);return NUM;}
{variable} {
				yylval=makeVarLeafNode(yytext);
				yylval->Gentry=lookup(yytext);
				if(yylval->Gentry!=NULL)
					yylval->TYPE=yylval->Gentry->TYPE;
				return ID;
		   }
			  
%%

yywrap()
{
	return 1;
}




