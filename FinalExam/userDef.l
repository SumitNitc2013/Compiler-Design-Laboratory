%{
	//multiline program
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "userDef.h"
	#define YYSTYPE tnode*
	#include "y.tab.h"
	int lineNum=1;
	
	int num;
	//#include "pgm.c"

%}

number [0-9]+
variable [a-zA-Z][a-zA-Z0-9]*

%%
"main" {return MAIN;}
"return" {return RETURN;}
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
"enque" {return ENQUE;}
"deque" {return DEQUE;}
"&&" {return AND;}
"||" {return OR;}
"!" {return NOT;}
"integer" {
			yylval=makeVarLeafNode(yytext);
		  	 //yylval->TYPE=TTLookup(yytext);
			return ID;
		  }

"boolean" {
			yylval=makeVarLeafNode(yytext);
			//yylval->TYPE=TTLookup(yytext);
			return ID;
		  }

"else" {return ELSE;}
"type" {return TYPE1;}
"endtype" {return ENDTYPE1;}
"typedef" {return TYPEDEF;}
"allocate"  {yylval=makeNameNode(ALLOC,NULL,NULL,NULL);return ALLOC;}
"free"  {yylval=makeNameNode(FREE,NULL,NULL,NULL);return FREE;}
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
"[" {return *yytext;}
"]" {return *yytext;}
"," {return *yytext;}
";" {return *yytext;}
"(" {return *yytext;}
")" {return *yytext;}
"{" {return *yytext;}
"}" {return *yytext;}
"&" {return *yytext;}
"." {return DOT;}
" " {}
["//"][^"\n"]* {}
"\n" {lineNum++;}
"\t" {}
{number} {num=atoi(yytext); yylval=makeNumLeafNode(num);return NUM;}
{variable} {
				yylval=makeVarLeafNode(yytext);
				yylval->Lentry=Llookup(yytext);
				if(yylval->Lentry!=NULL)
					yylval->TYPE=yylval->Lentry->TYPE;
				yylval->Gentry=Glookup(yytext);
				if(yylval->Gentry!=NULL)
					yylval->TYPE=yylval->Gentry->TYPE;
				//yylval->TYPE=TTLookup(yytext);
				return ID;
		   }
			  
%%

yywrap()
{
	return 1;
}




