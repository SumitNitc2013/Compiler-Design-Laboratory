%{
//remember that you are not executing the code, you are only generating the compiled code
/*if you want the space to be reconized as a token also then put space in single quotes*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "userDef.h"
extern FILE *yyin;
FILE *fp;
#define YYSTYPE tnode*
//int array[50000];
extern int lineNum;
/*Gmem points to the last data entry present in the array*/
int Gmem=512;
int Lmem=0;
int ttoffset=-1; //typetable offset
gsymbol* Ghead=NULL;
lsymbol* Lhead=NULL;
TypeTable* TThead=NULL; //typeTable Head pointer
idlist* id_head=NULL;
idlist* id_tail=NULL;
//field* field_head=NULL;
//field* field_tail=NULL;
#include "userDef.c"
%}


%token NUM ID READ WRITE IF THEN ENDIF WHILE DO MAIN RETURN CALL FUNCTION
%token ENDWHILE BEGIN1 END1 DECL ENDDECL ELSE CONNECT
%token LT GT LE GE EQ NE PLUS MINUS MUL DIV MOD EQUALS ARRAY AND OR NOT
%token TYPE1 ENDTYPE1 TYPEDEF FREE ALLOC FLD ENQUE DEQUE//FLD is for field
%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%right DOT


%%
	Prog:TypeDefBlock GDefblock Fdeflist Mainblock {Initialize();Allocate();Free();printf("Successful\n");exit(0);}
		;

	TypeDefBlock: TYPE1 TypeDefList ENDTYPE1
				|
				;

	TypeDefList: TypeDefList TypeDef
			   | TypeDef
			   ;

	TypeDef: HeaDer '{'FieldDeclList'}' {AddFieldsInTT($1->NAME,$3);ttoffset=-1;}
	       ;

	HeaDer: TYPEDEF ID {TTinstall(make_TypeTable_node($2->NAME,NULL));$$=$2;}
		  ;

	 FieldDeclList: FieldDeclList FieldDecl {
	 											if($1==NULL) 
													$$=$2; 
												else 
												{
													$1->mid->right=$2;
													$$=$1;
												}	
	 										}
	 			  | FieldDecl  			{$$=$1;}
	 			  ;

	 FieldDecl: type idlist3';' {    tnode* temp=$2;
										while(temp!=NULL)
												{
														temp->TYPE=$1->TYPE;
														temp=temp->right;
												}
										$$=$2;
	 								}
	 		  ;

	 idlist3: idlist3','id3 {/*checkField($1,$2);*/$1->mid->right=$3;$1->mid=$3;$$=$1;}
	 		| id3 {$$=$1;}
	 		;

	 //here val represents the relative offset, mid is acting as tail pointer of the linked list
	 //and right is acting as the next pointer of the linked list
	 id3: ID {checkName($1->NAME);$1->val=ttoffset+1;ttoffset++;$1->mid=$1;$1->right=NULL;$$=$1;}
	 	;

	 type: ID {$1->TYPE= FieldTypeCheck($1->NAME);$$=$1;}
	     ;

	
	GDefblock: DECL GDefList ENDDECL {StartupCodeGen(Gmem);}
			 | 	{StartupCodeGen(Gmem);}
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

	GIdList:GIdList ',' GId
		   |GId
		   ;

	GId : ID         			{checkName($1->NAME);insert_id(make_id_node($1->NAME,1,NULL));}
		| ID'['NUM']' 			{checkName($1->NAME);insert_id(make_id_node($1->NAME,$3->val,NULL));}
		| ID '('ArgList')' 		{checkName($1->NAME);insert_id(make_id_node($1->NAME,-2,$3));} //-2 means it's a function
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
								$1->mid->Arglist=$2;
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
	      
	id : ID  	{checkName($1->NAME);$1->val=0; $1->mid=$1; $1->Arglist=NULL; $$=$1;}  //value 0 means pass by value, $$ is head and $$->right is tail pointer

	   | '&'ID 	{checkName($2->NAME);$2->val=1; $2->mid=$2; $2->Arglist=NULL; $$=$2;}  //val 1 means pass by refrence, $$ is head and $$->right is tail pointer
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
										checkName($2->NAME);
										$2->TYPE=$1->TYPE;
										$2->NODETYPE=FUNCTION;
										$2->Arglist=$4;
										$$=$2;
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

	id2: ID {checkName($1->NAME);insert_id(make_id_node($1->NAME,1,NULL));} 
	   ;

	Body: BEGIN1 S Ret END1  {$$=makeNameNode(CONNECT,$2,NULL,$3);}
		;

	S: S stmt	 {$$=makeNameNode(CONNECT,$1,NULL,$2);}
	 |        { $$=NULL;}
	 ;

	stmt: ID EQUALS E';'       				{$$=makeNameNode(EQUALS,$1,NULL,$3);}
	    | ID'['E']' EQUALS E ';'   			{$$=makeNameNode(EQUALS,$1,$3,$6);}
	    | FIELD EQUALS E';'					{$1=makeNameNode(FLD,$1,NULL,NULL); $$=makeNameNode(EQUALS,$1,NULL,$3);}
	    | READ'('ID')' ';' 					{$$=makeNameNode(READ,$3,NULL,NULL);}
	    | READ'(' ID'['E']'')' ';'  		{$$=makeNameNode(READ,$3,$5,NULL);}
	    | READ '('FIELD')'   ';'               {$3=makeNameNode(FLD,$3,NULL,NULL);$$=makeNameNode(READ,$3,NULL,NULL);}
	    | WRITE'('E')' ';' 					{$$=makeNameNode(WRITE,$3,NULL,NULL);}
	    | IF '('E')' THEN S ELSE S ENDIF';' {$$=makeNameNode(IF,$3,$6,$8);}
        | IF '('E')' THEN S ENDIF';' 		{$$=makeNameNode(IF,$3,NULL,$6);}
	    | WHILE '('E')' DO S ENDWHILE';' 	{$$=makeNameNode(WHILE,$3,NULL,$6);}
	    | ID EQUALS ALLOC'(' ')'   ';'         {$$=makeNameNode(EQUALS,$1,NULL,$3);}
	    | ID'['E']' EQUALS ALLOC'(' ')'	';'	{$$=makeNameNode(EQUALS,$1,$3,$6);}
	    | FIELD EQUALS ALLOC'(' ')'	';'		{$1=makeNameNode(FLD,$1,NULL,NULL);$$=makeNameNode(EQUALS,$1,NULL,$3);}
	    | FREE'('ID')'				';'		{$1->left=$3;$$=$1;}
	    | FREE '(' ID'['E']' ')'	';'		{$3=makeNameNode(ARRAY,$3,NULL,$5);$1->left=$3;$$=$1;}
	    | FREE'('FIELD')'			';'		{$3=makeNameNode(FLD,$3,NULL,NULL);$1->left=$3;$$=$1;}
	    ;


	  FIELD: FIELD DOT ID       			{$1->mid->Arglist=$3;$1->mid=$3;$$=$1;}
		   | ID DOT ID 						{$1->Arglist=$3;$1->mid=$3; $$=$1;}
		   | ID'['E']' DOT ID                {$6->Arglist=NULL;$1=makeNameNode(ARRAY,$1,NULL,$3);$1->Arglist=$6;$1->mid=$6;$$=$1;}
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
	   | FIELD       {$$=makeNameNode(FLD,$1,NULL,NULL);}
	   | NUM        {$$=$1;}
	   | ID         {$$=$1;} 
	   | ID'['E']'  {$$=makeNameNode(ARRAY,$1,NULL,$3);}
	   ;

	Ret: RETURN E ';' {$$=makeNameNode(RETURN,$2,NULL,NULL);}
	   ;

	Mainblock: type MAIN'(' ')' '{'LDefblock Body'}' {  
														$$=(tnode*)malloc(sizeof(tnode));
														$$->NAME=(char*)malloc(50*sizeof(char));
														$$->TYPE=$1->TYPE;
														strcpy($$->NAME,"main");
														$$->NODETYPE=FUNCTION;
														$$->Arglist=NULL;
														$$->left=$7;
														if(strcmp($1->TYPE->NAME,"integer")!=0)
														{
															printf("Error at line number %d!!!\nReturn type of main must be integer\n",lineNum);
															exit(0);
														}
														if($7->right->TYPE!=$1->TYPE)
														{
															printf("Error at line Number %d !!\nReturn Type of return statement for main function must be integer\n",lineNum);
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
	TTinstall(make_TypeTable_node("integer",NULL));
	TTinstall(make_TypeTable_node("boolean",NULL));
	yyparse();
	fclose(fp);
	return 0;
}

 	

	

