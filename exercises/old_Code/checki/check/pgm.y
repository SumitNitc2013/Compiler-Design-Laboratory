%{
//if you want the space to be reconized as a token also then put space in single quotes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "pgm.h"
extern FILE *yyin;
#define YYSTYPE tnode*
int array[50000];
//index points to the last data entry present in the array
int indxe=-1;
gsymbol* head=NULL;
idlist* id_head=NULL;
idlist* id_tail=NULL;
#include "pgm.c"
// # is for == operator

%}


%token NUM ID READ WRITE IF THEN ENDIF WHILE DO 
%token ENDWHILE BEGIN1 END1 DECL ENDDECL INT BOOL VOID ELSE DUMMY
%token LT GT LE GE EQ NE PLUS MINUS MUL DIV EXP EQUAL ARRAY
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV
%right EXP

%%
	P: D St {/*printf("going to evaluate\n");*/evaluate($2);/*printf("finished evaluate\n");printf("going to exit\n");*/exit(0);}
	 ;
	
	D: DECL decls ENDDECL 
	 |
	 ;
	
	decls: decl decls  
	     |
	     ;

	decl: type idlist ';'   {
								//printf("making symbol table\n");
								while(id_head!=NULL)
								{
									idlist* temp;
									temp=id_head;
									char* name;
									name=(char*)malloc(50*sizeof(char));
									strcpy(name,id_head->NAME);
									//temp2=lookup(name);
									//if(temp2==NULL)
									//{
										install(make_gsymbol_node(name, $1->TYPE,id_head->size));
										//node=id_head->idPtr;
										//node->Gentry=head;
										//node->TYPE=$1->TYPE;
										//id_head->idPtr->SIZE=id_head->size;
									//}
										//node=id_head->idPtr;
										//node->Gentry=temp2;
										//node->TYPE=$1->TYPE;
										//id_head->idPtr->TYPE=$1->TYPE;
										//id_head->idPtr->SIZE=id_head->size;


									id_head=id_head->next;
									free(temp);
								}
								/*printf("content of symbol table\n");
								gsymbol* temp2;
								temp2=head;
								while(temp2!=NULL)
								{
									printf("name: %s\ntype %d\nsize %d\nbinding %d\n",temp2->NAME,temp2->TYPE,temp2->SIZE,temp2->BINDING);
									printf("address of x in symbol table is %p\n",temp2);
									printf("the tree node content corresponding to x is\n");
									printf("name: %s\nnodetype %d\ntype %d\naddress of gentry %p\n",temp2->nod->NAME,temp2->nod->NODETYPE,temp2->nod->TYPE,temp2->nod->Gentry);
									temp2=temp2->NEXT;

								}*/
								id_tail=NULL;
							}
	    ;
	
	type: INT {$$=$1;}
	    | BOOL	{$$=$1;}
	    ;
	
	idlist: id ',' idlist
		  | id   
	      ;

	id: ID  {insert_id(make_id_node($1->NAME,1));/*if(id_head!=NULL) printf("idlist formed\n");*/}
	  | ID'['NUM']' {insert_id(make_id_node($1->NAME,$3->val));}     
	  ;
	
	St: BEGIN1 S END1  {/*printf("jhaaaaaaaa\n");*/$$=$2;}
	  ;

	S: S stmt	 {$$=makeNameNode(DUMMY,$1,NULL,$2);}
	 | stmt       { $$=$1;}
	 ;

	stmt: ID EQUAL E';'       				{$$=makeNameNode(EQUAL,$1,NULL,$3);}
		| ID'['E']' EQUAL E ';'   			{$$=makeNameNode(EQUAL,$1,$3,$6);}
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
	   | E EXP E    {$$=makeNameNode(EXP,$1,NULL,$3);}
	   | '('E')'    {$$=$2;}
	   | E LT E 	{$$=makeNameNode(LT,$1,NULL,$3);}
	   | E GT E 	{$$=makeNameNode(GT,$1,NULL,$3);}
	   | E EQ E 	{$$=makeNameNode(EQ,$1,NULL,$3);}
	   | E NE E 	{$$=makeNameNode(NE,$1,NULL,$3);}
	   | E LE E 	{$$=makeNameNode(LE,$1,NULL,$3);}
	   | E GE E 	{$$=makeNameNode(GE,$1,NULL,$3);}
	   | NUM        {$$=$1;}
	   | ID         {$$=$1;/*printf("ID2 detected\n");*/}
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

 	

	

