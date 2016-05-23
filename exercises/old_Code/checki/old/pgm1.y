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


%token NUM ID READ WRITE IF THEN ENDIF WHILE DO ENDWHILE BEGIN1 END1 DECL ENDDECL INT BOOL ELSE
%left '<' '>' '#'
%left '+' '-'
%left '*' '/'
%right '^'

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
										install(make_gsymbol_node(name, $1->TYPE,id_head->size,id_head->idPtr));
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

	id: ID  {insert_id(make_id_node($1->NAME,1,$1));/*if(id_head!=NULL) printf("idlist formed\n");*/}
	  | ID'['NUM']' {insert_id(make_id_node($1->NAME,$3->val,$1));}     
	  ;
	
	St: BEGIN1 S END1  {/*printf("jhaaaaaaaa\n");*/$$=$2;}
	  ;

	S: S stmt	 {char c[10];strcpy(c,"dummy");$$=makeNameNode(c,$1,NULL,$2);}
	 | stmt       { $$=$1;}
	 ;

	stmt: ID'='E';'       {char c[10];strcpy(c,"=");$$=makeNameNode(c,$1,NULL,$3);}
		| ID'['E']' '=' E ';'   {char c[10];strcpy(c,"=");$$=makeNameNode(c,$1,$3,$6);}
	    | READ'('ID')' ';' { char c[10];strcpy(c,"READ");$$=makeNameNode(c,$3,NULL,NULL);}
	    | READ'(' ID'['E']'')' ';' {char c[10];strcpy(c,"READ");$$=makeNameNode(c,$3,$5,NULL);}
	    | WRITE'('E')' ';' { char c[10];strcpy(c,"WRITE");$$=makeNameNode(c,$3,NULL,NULL);}
	    | IF '('E')' THEN S ELSE S ENDIF';' {char c[10];strcpy(c,"IF");$$=makeNameNode(c,$3,$6,$8);}
        | IF '('E')' THEN S ENDIF';' {char c[10];strcpy(c,"IF");$$=makeNameNode(c,$3,NULL,$6);}
	    | WHILE '('E')' DO S ENDWHILE';' {char c[10];strcpy(c,"WHILE");$$=makeNameNode(c,$3,NULL,$6);}
	    ;

	  E: E '+' E	{char c[10];strcpy(c,"+");$$=makeNameNode(c,$1,NULL,$3);}
	   | E '-' E	{char c[10];strcpy(c,"-");$$=makeNameNode(c,$1,NULL,$3);}
       | E '*' E	{char c[10];strcpy(c,"*");$$=makeNameNode(c,$1,NULL,$3);}
	   | E '/' E	{char c[10];strcpy(c,"/");$$=makeNameNode(c,$1,NULL,$3);}
	   | E '^' E   {char c[10];strcpy(c,"^");$$=makeNameNode(c,$1,NULL,$3);}
	   | '('E')'   {$$=$2;}
	   | E '<' E 	{char c[10];strcpy(c,"<");$$=makeNameNode(c,$1,NULL,$3);}
	   | E '>' E 	{char c[10];strcpy(c,">");$$=makeNameNode(c,$1,NULL,$3);}
	   | E '#' E 	{char c[10];strcpy(c,"#");$$=makeNameNode(c,$1,NULL,$3);}
	   | NUM       {$$=$1;}
	   | ID       {$$=$1;/*printf("ID2 detected\n");*/}
	   | ID'['E']' {char c[10];strcpy(c,"$");$$=makeNameNode(c,$1,NULL,$3);}
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

 	

	

