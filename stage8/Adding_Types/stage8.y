%{
/*if you want the space to be reconized as a token also then put space in single quotes*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "stage8.h"
extern FILE *yyin;
#define YYSTYPE tnode*
int array[50000];
/*index points to the last data entry present in the array*/
int indxe=-1;
gsymbol* head=NULL;
idlist* id_head=NULL;
idlist* id_tail=NULL;
#include "stage8.c"

%}


%token NUM ID READ WRITE IF THEN ENDIF WHILE DO 
%token ENDWHILE BEGIN1 END1 DECL ENDDECL INT BOOL VOID ELSE CONNECT
%token LT GT LE GE EQ NE PLUS MINUS MUL DIV MOD EQUALS ARRAY
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV MOD


%%
	P: D St {evaluate($2);}
	 ;
	
	D: DECL decls ENDDECL 
	 |
	 ;
	
	decls: decl decls  
	     |
	     ;

	decl: type idlist ';'   {
								while(id_head!=NULL)
									{
											idlist *temp=id_head;
											install(make_gsymbol_node(id_head->NAME, $1->TYPE,id_head->size));
											id_head=id_head->next;
											free(temp);
									}
								id_tail=NULL;
							}
	    ;
	
	type: INT {$$=$1;}
	    | BOOL	{$$=$1;}
	    ;
	
	idlist: id ',' idlist
		  | id   
	      ;

	id: ID  {insert_id(make_id_node($1->NAME,1));}
	  | ID'['NUM']' {insert_id(make_id_node($1->NAME,$3->val));}     
	  ;
	
	St: BEGIN1 S END1  {$$=$2;}
	  ;

	S: S stmt	 {$$=makeNameNode(CONNECT,$1,NULL,$2);}
	 | stmt       { $$=$1;}
	 ;

	stmt: ID EQUALS E';'       				{$$=makeNameNode(EQUALS,$1,NULL,$3);}
	    | ID'['E']' EQUALS E ';'   			{$$=makeNameNode(EQUALS,$1,$3,$6);}
	    | READ'('ID')' ';' 					{$$=makeNameNode(READ,$3,NULL,NULL);}
	    | READ'(' ID'['E']'')' ';'  		{$$=makeNameNode(READ,$3,$5,NULL);}
	    | WRITE'('E')' ';' 					{$$=makeNameNode(WRITE,$3,NULL,NULL);}
	    | IF '('E')' THEN S ELSE S ENDIF';' {$$=makeNameNode(IF,$3,$6,$8);}
            | IF '('E')' THEN S ENDIF';' 		{$$=makeNameNode(IF,$3,NULL,$6);}
	    | WHILE '('E')' DO S ENDWHILE';' 	{$$=makeNameNode(WHILE,$3,NULL,$6);}
	    ;

	  E: E PLUS E	{$$=makeNameNode(PLUS,$1,NULL,$3);}
	   | E MINUS E	{$$=makeNameNode(MINUS,$1,NULL,$3);}
       | E MUL E	{$$=makeNameNode(MUL,$1,NULL,$3);}
	   | E DIV E	{$$=makeNameNode(DIV,$1,NULL,$3);}
	   | E MOD E    {$$=makeNameNode(MOD,$1,NULL,$3);}
	   | '('E')'    {$$=$2;}
	   | E LT E 	{$$=makeNameNode(LT,$1,NULL,$3);}
	   | E GT E 	{$$=makeNameNode(GT,$1,NULL,$3);}
	   | E EQ E 	{$$=makeNameNode(EQ,$1,NULL,$3);}
	   | E NE E 	{$$=makeNameNode(NE,$1,NULL,$3);}
	   | E LE E 	{$$=makeNameNode(LE,$1,NULL,$3);}
	   | E GE E 	{$$=makeNameNode(GE,$1,NULL,$3);}
	   | NUM        {$$=$1;}
	   | ID         {$$=$1;}
	   | ID'['E']'  {$$=makeNameNode(ARRAY,$1,NULL,$3);}
	   ;
%%

yyerror(const char* x)
{
	printf("error %s\n",x);
}

int main(int argc,char* argv[])
{
	if(argc==2)
	{
		yyin=fopen(argv[1],"r");
	}
	yyparse();
	return 0;
}

 	

	

