%{
//remember that you are not executing the code, you are only generating the compiled code
/*if you want the space charecter to be reconized as a token also then put space in single quotes*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
extern FILE *yyin;
FILE *fp;
#define YYSTYPE tnode*
//int array[50000];
extern int lineNum;
/*Gmem points to the last data entry present in the array*/
int Gmem=-1;
int Lmem=0;
gsymbol* Ghead=NULL;
lsymbol* Lhead=NULL;
idlist* id_head=NULL;
idlist* id_tail=NULL;
#include "functions.c"
%}


%token NUM ID READ WRITE IF THEN ENDIF WHILE DO MAIN RETURN CALL FUNCTION
%token ENDWHILE BEGIN1 END1 DECL ENDDECL INT BOOL VOID ELSE CONNECT
%token LT GT LE GE EQ NE PLUS MINUS MUL DIV MOD EQUALS ARRAY AND OR NOT
%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT


%%
	Prog: GDefblock Fdeflist Mainblock {/*$$=makeNameNode(CONNECT,$3,$2);*//*Codegen($$);*/printf("Successful\n");exit(0);}
		;
	
	GDefblock: DECL GDefList ENDDECL {StartupCodeGen(Gmem);}
			 |  {StartupCodeGen(Gmem);}
			;

	GDefList: GDefList GDecl
			| GDecl
			;

	GDecl: type GIdList ';' {
								while(id_head!=NULL)
									{
											idlist *temp=id_head;
											Ginstall(make_gsymbol_node(id_head->NAME, $1->TYPE,id_head->size,id_head->arglst));
											id_head=id_head->next;
											free(temp);
									}
								id_tail=NULL;
							}
		 ;

	type: INT {$$=$1;}
	    | BOOL	{$$=$1;}
	    ;

	GIdList:GIdList ',' GId
		   |GId
		   ;

	GId : ID         			{insert_id(make_id_node($1->NAME,1,NULL));}
		| ID'['NUM']' 			{insert_id(make_id_node($1->NAME,$3->val,NULL));}
		| ID '('ArgList')' 		{insert_id(make_id_node($1->NAME,-2,$3));} //-2 means it's a function
		;

	ArgList : Args  {$$=$1;}
		    |		{$$=NULL;}
		    ;

	Args : Arg1 Arg2 {
							if($1==NULL)
								$$=$2;
							else
							{
								$1->mid->Arglist=$2;
								$$=$1;
							}

						} 
	     ;

	Arg1: Arg1 arg 		{	if($1==NULL) 
								$$=$2; 
							else 
							{
								$1->mid->Arglist=$2; //$1->mid is tail so basically $1->mid->Arglist is tail->next
								$$=$1;
							}	
						}

		|  				{$$=NULL;}
		;

	arg: type idlist ';'   {
								tnode* temp=$2;
								while(temp!=NULL)
										{
												temp->TYPE=$1->TYPE;
												temp=temp->Arglist;
										}
								$$=$2;
							} 
		;

	idlist: idlist ',' id {$1->mid->Arglist=$3;$1->mid=$3;$$=$1;}
		  | id 			   {$$=$1;}
		  ;  
	      
	id : ID  	{$1->val=0; $1->mid=$1; $1->Arglist=NULL; $$=$1;}  //value 0 means pass by value, $$ is head and $1->mid is tail pointer,Arglist is next pointer

	   | '&'ID 	{$2->val=1; $2->mid=$2; $2->Arglist=NULL; $$=$2;}  //val 1 means pass by refrence, $$ is head and $1->mid is tail pointer, Arglist is next pointer
	   ;


	Arg2: type idlist  {
							tnode* temp=$2;
							while(temp!=NULL)
									{
											temp->TYPE=$1->TYPE;
											temp=temp->Arglist;
									}
								$$=$2;
							} 
		;


	Fdeflist: Fdeflist FDef
			|
			; 

	FDef: Header '{'LDefblock Body'}' {		
											$1->left=$4;   //body of function
											$$=$1;
											checkReturnType($1->NAME, $1->TYPE,$4->right);
											FunctionCodegen($$);
											Lhead=NULL;
											Lmem=0;
									}
		;

	Header: type ID'('ArgList')' {
										$2->TYPE=$1->TYPE;
										$2->NODETYPE=FUNCTION;
										$2->Arglist=$4;
										$$=$2;
										//tnode* temp=$4;
										/*while(temp!=NULL)
										{
											printf("Argument=%s, type=%d\n",temp->NAME,temp->TYPE);
											temp=temp->Arglist;
										}*/
										functionHeaderCheck($1->TYPE,$2->NAME,$4);
										PutArgumentsInSymTable($4);
								}
		  ;

	LDefblock: DECL LDeflist ENDDECL
			 |
			 ;

	LDeflist: LDeflist LDecl
			| LDecl
			;

	LDecl: type idlist2';' {
								while(id_head!=NULL)
									{
											idlist *temp=id_head;
											Linstall(make_lsymbol_node(id_head->NAME, $1->TYPE));
											id_head=id_head->next;
											free(temp);
									}
								id_tail=NULL;

							}
		;

	idlist2: idlist2',' id2
		  | id2
		  ;

	id2: ID {insert_id(make_id_node($1->NAME,1,NULL));} 
	   ;

	Body: BEGIN1 S Ret END1  {$$=makeNameNode(CONNECT,$2,NULL,$3);}
		;

	S: S stmt	 {$$=makeNameNode(CONNECT,$1,NULL,$2);}
	 |        { $$=NULL;}
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

	 args: ars {$$=$1;}
	 	 | {$$=NULL;}
	 	 ;

	 ars: ars','E {$1->mid->Arglist=$3;$1->mid=$3;$$=$1;}
	 	| E        {$1->Arglist=NULL,$1->mid=$1;$$=$1;}
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
	   | E AND E    {$$=makeNameNode(AND,$1,NULL,$3);}
	   | E OR E     {$$=makeNameNode(OR,$1,NULL,$3);}
	   | NOT E    	{$$=makeNameNode(NOT,$2,NULL,NULL);}
	   | ID'('args')'{$$=makeNameNode(CALL,$1,NULL,$3);}
	   | NUM        {$$=$1;}
	   | ID         {$$=$1;}
	   | ID'['E']'  {$$=makeNameNode(ARRAY,$1,NULL,$3);}
	   ;

	Ret: RETURN E ';' {$$=makeNameNode(RETURN,$2,NULL,NULL);}
	   ;

	Mainblock: INT MAIN'(' ')' '{'LDefblock Body'}' {
														$$=(tnode*)malloc(sizeof(tnode));
														$$->NAME=(char*)malloc(50*sizeof(char));
														$$->TYPE=$1->TYPE;
														strcpy($$->NAME,"main");
														$$->NODETYPE=FUNCTION;
														$$->Arglist=NULL;
														$$->left=$7;
														if($7->right->TYPE!=INT)
														{
															printf("Error at line Number %d !!\nReturn Type for MAIN function must be integer\n",lineNum);
															exit(0);
														}
														//printf("going to code gen for main\n");
														FunctionCodegen($$);
														//printf("gngreated code for main\n");
														Lhead=NULL;
														Lmem=0;
													}
			 ;

%%

yyerror(const char* x)
{
	printf("%s at line Number %d\n",x,lineNum);
}

int main(int argc,char* argv[])
{
	fp = fopen("outfile.asm","w+");
	if(argc==2)
	{
		yyin=fopen(argv[1],"r");
	}
	yyparse();
	fclose(fp);
	return 0;
}

 	

	

