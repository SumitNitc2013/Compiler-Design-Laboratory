/*array out of bound is a runtime problem not a compile time problem at all*/
#include "y.tab.h"
#include "stdio.h"
int x,ans;
int regCount=-1;
int pushRegCount;
int StatementsCodeGen(tnode* t);
int label=0;

idlist* make_id_node(char* NAME,int size,tnode* arglst)
{
	idlist* temp;
	temp=(idlist*)malloc(sizeof(idlist));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->size=size;
	temp->arglst=arglst;
	temp->next=NULL;
	return temp;
}

void insert_id(idlist* node)
{
	
	if(id_tail==NULL && id_head==NULL)
	{
		id_head=node;
		id_tail=node;
	}

	else
	{
		id_tail->next=node;
		id_tail=node;
	}
	
}

gsymbol* Glookup(char* NAME)
{
	gsymbol* temp=Ghead;
	while(temp!=NULL)
	{
		if(strcmp(temp->NAME,NAME)==0)
			return temp;
		temp=temp->NEXT;
	}
	return NULL;	
}


void Ginstall(gsymbol* node)
{
	gsymbol* temp=Glookup(node->NAME);
	if(temp!=NULL)
	{
		printf("Error at line Number %d !!!\nVariable %s Redeclared\n",lineNum,node->NAME);
		exit(0);
	}
	
	node->NEXT=Ghead;
	Ghead=node;
	
}


gsymbol* make_gsymbol_node(char* NAME, int type, int size,tnode* arglst)
{
	gsymbol* temp;
	temp=(gsymbol*)malloc(sizeof(gsymbol));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->TYPE=type;
	temp->SIZE=size;
	temp->Arglist=arglst;
	temp->NEXT=NULL;
	if(size!=-2)
	{
		temp->BINDING=Gmem+1;
		Gmem=Gmem+size;
	}
	return temp;
}


lsymbol* Llookup(char *NAME)
{
	lsymbol* temp=Lhead;
	while(temp!=NULL)
	{
		if(strcmp(temp->NAME,NAME)==0)
			return temp;
		temp=temp->NEXT;
	}
	return NULL;
}


void Linstall(lsymbol* node)
{
	//printf("Linstall called with %s\n",node->NAME);
	lsymbol* temp=Llookup(node->NAME);
	if(temp!=NULL)
	{
		printf("Error at line Number %d !!!\nVariable %s Redeclared\n",lineNum, node->NAME);
		//printf("binding=%d\n",temp->BINDING);
		exit(0);
	}
	
	node->NEXT=Lhead;
	Lhead=node;
}

lsymbol* make_lsymbol_node(char* NAME,int type)
{
	lsymbol* temp;
	temp=(lsymbol*)malloc(sizeof(lsymbol));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->TYPE=type;
	temp->refType=0;
	temp->NEXT=NULL;
	temp->BINDING=Lmem+1;
	Lmem=Lmem+1;
	return temp;
}


void checkReturnType(char* NAME, int type,tnode* node)
{
	if(type!=node->TYPE)
	{
		printf("Error at line Number %d !!!\nReturn Type missmatch for function %s\n",lineNum,NAME);
		exit(0);
	}
}

void matchActualArguments(char* NAME,tnode* l1,tnode* l2)
{

	while(1)
	{
		if(l1==NULL && l2==NULL)
			break;
		else if(l1==NULL && l2!=NULL)
		{
			printf("Error at line Number %d !!\nNumber of Aruguments missmatched for function %s\n",lineNum, NAME);
			exit(0);
		}
		else if(l2==NULL && l1!=NULL)
		{
			printf("Error at line Number %d !!\nNumber of  Aruguments missmatched for function %s\n",lineNum, NAME);
			exit(0);
		}

		else
		{
			if(l1->TYPE!=l2->TYPE)
			{
				printf("Error at line Number %d !!\nActual Arugument type missmatch for function %s\n",lineNum, NAME);
				exit(0);
			}

			if(l1->val==1 && l2->NODETYPE!=ID && l2->NODETYPE!=ARRAY)
			{
				printf("Error at line Number %d !!\nActual Arugument refrence type missmatch for function %s\n",lineNum, NAME);
				exit(0);
			}

			else
			{
				l1=l1->Arglist;
				l2=l2->Arglist;
			}

		}
	}
}

void matchFormalArguments(char* NAME, tnode* l1,tnode* l2)
{
	while(1)
	{
		if(l1==NULL && l2==NULL)
			break;
		else if(l1==NULL && l2!=NULL)
		{
			printf("Error at line Number %d !!\nNumber of Aruguments missmatched for function %s\n",lineNum, NAME);
			exit(0);
		}
		else if(l2==NULL && l1!=NULL)
		{
			printf("Error at line Number %d !!\nNumber of  Aruguments missmatched for function %s\n",lineNum, NAME);
			exit(0);
		}

		else
		{
			if(strcmp(l1->NAME,l2->NAME)!=0)
			{
				printf("Error at line Number %d !!\nArugument name missmatch for function %s\n",lineNum, NAME);
				exit(0);
			}
			else if(l1->TYPE!=l2->TYPE)
			{
				printf("Error at line Number %d !!\nArugument type missmatch for function %s\n",lineNum, NAME);
				exit(0);
			}
			else if(l1->val!=l2->val)
			{
				printf("Error at line Number %d !!\nArugument passing mechanism missmatch for function %s\n",lineNum, NAME);
				exit(0);
			}
			else
			{
				l1=l1->Arglist;
				l2=l2->Arglist;
			}

		}
	}
}

void functionHeaderCheck(int type,char* NAME,tnode* arglst)
{
	gsymbol* temp=Glookup(NAME);
	if(temp==NULL || temp->SIZE!=-2)
		{
			printf("Error at line Number %d !!\nFunction %s is not Declared in Global Declaration Area\n",lineNum, NAME);
			exit(0);
		}
	else if(temp->TYPE!=type)
		{
			printf("Error at line Number %d !!\nReturn type missmatch for function %s\n",lineNum, NAME);
			exit(0);
		}
	else
		{
			matchFormalArguments(NAME, temp->Arglist,arglst);
		}
}

void PutArgumentsInSymTable(tnode* t)
{
	//counting the number of arguments
	int count=0;
	tnode* temp=t;
	while(temp!=NULL)
	{
		count++;
		//printf("in PutArgumentsInSymTable arguments=%s\n",temp->NAME);
		temp=temp->Arglist;
	}
	//puting arguments into local symbol table
	temp=t;
	int binding;
	for(binding=-3-count+1;binding<=-3;binding++)
	{
		//installing arguments into local symbol table
		lsymbol* node;
		node=(lsymbol*)malloc(sizeof(lsymbol));
		node->NAME=(char*)malloc(50*sizeof(char));
		strcpy(node->NAME,temp->NAME);
		node->TYPE=temp->TYPE;
		node->refType=temp->val;  //0 means pass by value and 1 means pass by refrence. already set at the time of parsing
		node->NEXT=NULL;
		node->BINDING=binding;
		//printf("in PutArgumentsInSymTable function %s is put in symbol table\n",node->NAME);
		Linstall(node);
		temp=temp->Arglist;
	}
}



tnode* makeNumLeafNode(int n)
{
	
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
	leaf->TYPE=INT;
	leaf->NODETYPE=NUM;
	leaf->val=n;
	leaf->NAME=NULL;
	leaf->left=NULL;
	leaf->mid=NULL;
	leaf->right=NULL;
	return leaf;
}

tnode* makeVarLeafNode(char* var)
{
	
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
	leaf->NODETYPE=ID;
	leaf->NAME=(char*)malloc(50*sizeof(char));
	strcpy(leaf->NAME,var);
	leaf->val=0;
	leaf->left=NULL;
	leaf->mid=NULL;
	leaf->right=NULL;
	return leaf;
}

tnode* makeNameNode(int c,tnode* left,tnode* mid,tnode* right)
{
	tnode* name_node;
	name_node=(tnode*)malloc(sizeof(tnode));
	switch(c)
	{
		case PLUS:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=INT;
			name_node->NODETYPE=PLUS;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case MINUS:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=INT;
			name_node->NODETYPE=MINUS;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case MUL:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=INT;
			name_node->NODETYPE=MUL;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case DIV:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=INT;
			name_node->NODETYPE=DIV;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case MOD:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=INT;
			name_node->NODETYPE=MOD;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case LT:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=LT;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case GT:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=GT;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;



		case EQ:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=EQ;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case NE:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=NE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case LE:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=LE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case GE:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=INT || right->TYPE!=INT)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=GE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case AND:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=BOOL || right->TYPE!=BOOL)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=AND;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case OR:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
			{
				printf("Error at line Number %d !!\nError!! Variable %s not declared\n",lineNum, right->NAME);
				exit(0);
			}
			if(left->TYPE!=BOOL || right->TYPE!=BOOL)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=OR;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case NOT:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line number %d !!\n Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(left->TYPE!=BOOL)
			{
				printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=BOOL;
			name_node->NODETYPE=NOT;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case ARRAY:
			if(left->Gentry==NULL)
			{
				printf("Error at line number %d!!\n Array Variable %s not declared\n",lineNum, left->NAME);
				exit(0);
			}
			if(right->TYPE!=INT)
			{
				printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->NODETYPE=ARRAY;
			name_node->TYPE=left->TYPE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case EQUALS:
		
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
				{
					printf("Error at line number %d!!\n Variable %s not declared\n",lineNum, left->NAME);
					exit(0);
				}
			if(left->NODETYPE==ARRAY && left->left->Gentry==NULL)
				{
					printf("Error at line number %d!!\n Array Variable %s not declared\n",lineNum, left->left->NAME);
					exit(0);
				}

			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
				{
					printf("Error at line number %d!!\n Variable %s not declared\n",lineNum, right->NAME);
					exit(0);
				}
			if(right->NODETYPE==ARRAY && right->left->Gentry==NULL)
				{
					printf("Error at line number %d!!\n Array Variable %s not declared\n",lineNum, right->left->NAME);
					exit(0);
				}

			if(left->TYPE!=right->TYPE)
				{
					printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
					exit(0);
				}

			else
			{
					if(mid==NULL)
					{
						name_node->TYPE=VOID;
						name_node->NODETYPE=EQUALS;
						name_node->NAME=NULL;
						name_node->left=left;
						name_node->mid=mid;
						name_node->right=right;
					
				
					}
			 	   else
					{
						name_node->TYPE=VOID;
						name_node->NODETYPE=EQUALS;
						name_node->NAME=NULL;
						name_node->left=makeNameNode(ARRAY,left,NULL,mid);
						name_node->mid=NULL;
						name_node->right=right;
					
					}
			}
			break;

		case READ:

				if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
					{
						printf("Error at line number %d!!\n Variable %s not declared\n",lineNum, left->NAME);
						exit(0);
					}
				if(left->NODETYPE==ARRAY &&  left->left->Gentry==NULL)
					{
						printf("Error at line number %d!!\n Array Variable %s not declared\n",lineNum, left->left->NAME);
						exit(0);
					}
				
				if(left->TYPE!=INT)
					{
						printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
						exit(0);
					}
				else
				{
					if(mid==NULL)
					{
						name_node->TYPE=VOID;
						name_node->NODETYPE=READ;
						name_node->NAME=NULL;
						name_node->left=left;
						name_node->mid=mid;
						name_node->right=right;
					}
					else
					{
						name_node->TYPE=VOID;
						name_node->NODETYPE=READ;
						name_node->NAME=NULL;
						name_node->left=makeNameNode(ARRAY,left,NULL,mid);
						name_node->mid=NULL;
						name_node->right=right;
					}
				}
				break;

		case WRITE:
		
				if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
					{
						printf("Error at line number %d!!\n Variable %s not declared\n",lineNum, left->NAME);
						exit(0);
					}
				if(left->TYPE!=INT)
					{
						printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
						exit(0);
					}
				else
					{
						name_node->TYPE=VOID;
						name_node->NODETYPE=WRITE;
						name_node->NAME=NULL;
						name_node->left=left;
						name_node->mid=mid;
						name_node->right=right;
					}
				
				
					break;

		case IF:	
				if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
				{
						printf("Error at line number %d!!\n Variable %s not declared\n",lineNum, left->NAME);
						exit(0);
				}

				if(left->TYPE!=BOOL)
				{
					printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
					exit(0);
				}
				name_node->TYPE=VOID;
				name_node->NODETYPE=IF;
				name_node->NAME=NULL;
				name_node->left=left;
				name_node->mid=mid;
				name_node->right=right;
				break;

		case WHILE:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
				{
						printf("Error at line number %d!!\n Variable %s not declared\n",lineNum, left->NAME);
						exit(0);
				}
			if(left->TYPE!=BOOL)
			{
				printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=VOID;
			name_node->NODETYPE=WHILE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case CONNECT:
			name_node->TYPE=VOID;
			name_node->NODETYPE=CONNECT;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;
	

		case INT:
			
			name_node->TYPE=INT;			
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case BOOL:
			name_node->TYPE=BOOL;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case CALL:
				if(left->Gentry==NULL || left->Gentry->SIZE!=-2)
				{
					printf("Error at line number %d!!\nFucntion %s not declared in the Global Declaration Section\n",lineNum, left->NAME);
					exit(0);
				}
				matchActualArguments(left->NAME,left->Gentry->Arglist,right);
				name_node->TYPE=left->Gentry->TYPE;
				name_node->NODETYPE=CALL;
				name_node->NAME=NULL;
				name_node->left=left;
				name_node->mid=mid;
				name_node->right=right;
				break;

		case RETURN:
			if(left->NODETYPE==ID && left->Lentry==NULL && left->Gentry==NULL)
				{
						printf("Error at line number %d!!\n Variable %s not declared\n",lineNum, left->NAME);
						exit(0);
				}
			name_node->TYPE=left->TYPE;
			name_node->NODETYPE=RETURN;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
				break;

		default:
				break;
	}
return name_node;
}

int getReg()
{
	if(regCount<7)
		{
			regCount++;
			return regCount;
		}
	else
		{
			printf("REGSITER NOT AVALIABLE TO USE\n");
			exit(0);
		}
}

void freeReg()
{
	/*always free the heigher numbered register*/
	regCount--;
}

int getBinding(tnode* t)
{
	int loc,r,r1;
	/*returns the number of the register which contains binding*/
	if(t->NODETYPE==ARRAY)
	{
			loc=t->left->Gentry->BINDING;
			r=StatementsCodeGen(t->right);
			r1=getReg();
			fprintf(fp, "MOV R%d, %d\n",r1,loc);
			fprintf(fp, "ADD R%d, R%d\n",r,r1);
			freeReg();
			return r;
	}

	else if(t->Lentry!=NULL)
	{
			loc=t->Lentry->BINDING;
			r=getReg();
			fprintf(fp, "MOV R%d, %d\n",r,loc);
			r1=getReg();
			fprintf(fp, "MOV R%d, BP\n",r1);
			fprintf(fp, "ADD R%d, R%d\n",r,r1);
			freeReg();
			return r;	
	}
	else
	{
			loc=t->Gentry->BINDING;
			r=getReg();
			fprintf(fp, "MOV R%d, %d\n",r,loc);
			return r;
	}

}

int getLabel()
{
	label++;
	return label;
}


void StartupCodeGen(int Gmem)
{

	fprintf(fp, "START\n");
	fprintf(fp, "MOV BP, 0\n");
	fprintf(fp, "MOV SP, %d\n",Gmem); //Gmem+1
 	fprintf(fp, "CALL main\n");
	fprintf(fp, "HALT\n");
}


void FunctionCodegen(tnode* t)
{
	int r,r1,r2;
	//saving BP
	fprintf(fp, "%s:\n",t->NAME);
	fprintf(fp, "PUSH BP\n");
	fprintf(fp, "MOV BP, SP\n");
	//reserving space for local variables
	r=getReg();
	fprintf(fp,"MOV R%d, %d\n",r,Lmem);
	r1=getReg();
	fprintf(fp, "MOV R%d, SP\n",r1);
	fprintf(fp, "ADD R%d, R%d \n",r1,r);
	fprintf(fp, "MOV SP, R%d\n",r1);
	freeReg();
	freeReg();
	//Code Generation for body except return statement
	StatementsCodeGen(t->left->left);
	//codegeneration for return statement
	//printf("Going to generate return code\n");
	r=StatementsCodeGen(t->left->right);
	//printf("After to generate return code\n");
	//Saving return values
	r1=getReg();
	fprintf(fp, "MOV R%d, %d\n",r1,-2);
	r2=getReg();
	fprintf(fp, "MOV R%d, BP\n",r2);
	fprintf(fp, "ADD R%d, R%d\n",r1,r2);
	fprintf(fp, "MOV [R%d], R%d\n",r1,r);
	freeReg();
	freeReg();
	freeReg();
	//poping off local variables 
	r=getReg();
	fprintf(fp,"MOV R%d, %d\n",r,Lmem);
	r1=getReg();
	fprintf(fp, "MOV R%d, SP\n",r1);
	fprintf(fp, "SUB R%d, R%d \n",r1,r);
	fprintf(fp, "MOV SP, R%d\n",r1);
	freeReg();
	freeReg();
	//poping off BP
	fprintf(fp, "POP BP\n");
	//returnning
	fprintf(fp, "RET\n");
}

int StatementsCodeGen(tnode* t)
{
	int r,r1,r2,retReg;
	int value;
	int loc,l1,l2;
	tnode* temp;
	tnode* dp;
	lsymbol* ptr;
	if(t==NULL)
		return 0;
	/*r is the root of AST
	returntype of CodeGen is int that is it returns the register Number where the result of the expression is going to be*/
	switch(t->NODETYPE)
	{
		case NUM:
			value=t->val;
			r=getReg();
			fprintf(fp,"MOV R%d, %d\n",r,value);
			return r;
			break;

		case ID:
			if(t->Lentry!=NULL)
			{

				loc=t->Lentry->BINDING;
				r=getReg();
				fprintf(fp, "MOV R%d, %d\n",r,loc);
				r1=getReg();
				fprintf(fp, "MOV R%d, BP\n",r1);
				fprintf(fp, "ADD R%d, R%d\n",r,r1);
				freeReg();
				if(t->Lentry->refType==1)
					fprintf(fp, "MOV R%d, [R%d]\n",r,r);
				fprintf(fp, "MOV R%d, [R%d]\n",r,r);
				return r;
			}
			else
			{
				loc=t->Gentry->BINDING;
				r=getReg();
				fprintf(fp, "MOV R%d, [%d]\n",r,loc);
				return r;
			}
			break;

		case ARRAY:
				loc=t->left->Gentry->BINDING;
				r=StatementsCodeGen(t->right);
				r1=getReg();
				fprintf(fp, "MOV R%d, %d\n",r1,loc);
				fprintf(fp, "ADD R%d, R%d\n",r,r1);
				fprintf(fp, "MOV R%d, [R%d]\n",r,r);
				freeReg();
				return r;
				break;

		case PLUS:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "ADD R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case MINUS:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "SUB R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case MUL:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "MUL R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case DIV:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "DIV R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case MOD:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "MOD R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case LT:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "LT R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case GT:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "GT R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case EQ:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "EQ R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case NE:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "NE R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case LE:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "LE R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case GE:
			r1=StatementsCodeGen(t->left);
			r2=StatementsCodeGen(t->right);
			fprintf(fp, "GE R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case AND:
			l1=getLabel();
			l2=getLabel();
			r=StatementsCodeGen(t->left);
			r1=getReg();
			fprintf(fp, "MOV R%d, 0\n",r1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			r=StatementsCodeGen(t->right);
			r1=getReg();
			fprintf(fp, "MOV R%d, 0\n",r1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			//other wise result is 1
			fprintf(fp, "MOV R%d, 1\n",r);
			fprintf(fp, "JMP L%d\n",l2);
			//at l1 result is 0
			fprintf(fp, "L%d:\n",l1);
			fprintf(fp, "MOV R%d, 0\n",r);
			fprintf(fp, "L%d:\n",l2);
			freeReg();
			return r;
			break;

		case OR:
			l1=getLabel();
			l2=getLabel();
			r=StatementsCodeGen(t->left);
			r1=getReg();
			fprintf(fp, "MOV R%d, 1\n",r1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			r=StatementsCodeGen(t->right);
			r1=getReg();
			fprintf(fp, "MOV R%d, 1\n",r1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			//other wise result is 0
			fprintf(fp, "MOV R%d, 0\n",r);
			fprintf(fp, "JMP L%d\n",l2);
			//at l1 is result is 1
			fprintf(fp, "L%d:\n",l1);
			fprintf(fp, "MOV R%d, 1\n",r);
			fprintf(fp, "L%d:\n",l2);
			freeReg();
			return r;
			break;

		case NOT:
			l1=getLabel();
			l2=getLabel();
			r=StatementsCodeGen(t->left);
			r1=getReg();
			fprintf(fp, "MOV R%d, 0\n",r1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			//otherwise result is 0
			fprintf(fp, "MOV R%d, 0\n",r);
			fprintf(fp, "JMP L%d\n",l2);
			//at l1 result is 1
			fprintf(fp, "L%d:\n",l1);
			fprintf(fp, "MOV R%d, 1\n",r);
			fprintf(fp, "L%d:\n",l2);
			freeReg();
			return r;
			break;

		case EQUALS:
			r1=getBinding(t->left);
			r2=StatementsCodeGen(t->right);	
			if(t->left->Lentry!=NULL && t->left->Lentry->refType==1)
				fprintf(fp, "MOV R%d, [R%d]\n",r1,r1);
			fprintf(fp, "MOV [R%d], R%d\n",r1,r2);
			freeReg();
			freeReg();
			return 0;
			break;

		case CALL:
			retReg=getReg();
			pushRegCount=regCount-1;
			//pushes registers in revesre order so that at the time of poping we can directly
			//pop in increasing order of register number
			for(r=pushRegCount;r>=0;r--)
			{
				fprintf(fp, "PUSH R%d\n",r);
				//freeReg();
			}

				
			//pushing actual arguments
			dp=t->left->Gentry->Arglist;
			temp=t->right;
			while(temp!=NULL)
			{
				if(dp->val==0)
					r=StatementsCodeGen(temp);
				else
				{
					//this is the case of pass by refrence
					//dp->val=1 here
					//now here we can have two cases temp which is a id is a normal id or 
					//a id which is again passed by refrence in the caller function
					if(temp->NODETYPE==ID)
					{
						ptr=Llookup(temp->NAME);
						if(ptr!=NULL && ptr->refType==1)
						{

							r=getBinding(temp);
							fprintf(fp, "MOV R%d, [R%d]\n",r,r);	
						}
						else
							r=getBinding(temp);
					}
					else
						r=getBinding(temp);
				}
				fprintf(fp, "PUSH R%d\n",r);
				freeReg();
				temp=temp->Arglist;
				dp=dp->Arglist;	
			}

			//pushing return value
			fprintf(fp, "PUSH R%d\n",retReg);

			//writing call statement
			fprintf(fp, "CALL %s\n",t->left->NAME);

			//poping off return value
			fprintf(fp, "POP R%d\n",retReg);

			//poppign off Actual arguments
			temp=t->right;
			while(temp!=NULL)
			{
				r=getReg();
				fprintf(fp, "POP R%d\n",r);
				freeReg();
				temp=temp->Arglist;
			}

			//restoring registers
			for(r=0;r<=pushRegCount;r++)
			{
				fprintf(fp, "POP R%d\n",r);
			}
			regCount=pushRegCount+1;

			return retReg;
			 
			break;

		case RETURN:
			r=getReg();
			r=StatementsCodeGen(t->left);
			return r;
			break;

		case READ:
			r=getBinding(t->left);
			r1=getReg();
			fprintf(fp, "IN R%d\n",r1);
			fprintf(fp, "MOV [R%d], R%d\n",r,r1);
			freeReg();
			freeReg();
			return 0;
			break;

		case WRITE:
			r=StatementsCodeGen(t->left);
			fprintf(fp, "OUT R%d\n",r);
			freeReg();
			return 0;
			break;

		case IF:
			if(t->mid==NULL)
			{
				l1=getLabel();
				r=StatementsCodeGen(t->left);
				r1=getReg();
				fprintf(fp, "MOV R%d, 0\n",r1);
				fprintf(fp, "NE R%d, R%d\n",r,r1);
				fprintf(fp, "JZ R%d, L%d\n",r,l1);
				freeReg();
				freeReg();
				StatementsCodeGen(t->right);
				fprintf(fp, "L%d:\n",l1);
				return 0;
			}

			else
			{
				l1=getLabel();
				l2=getLabel();
				r=StatementsCodeGen(t->left);
				r1=getReg();
				fprintf(fp, "MOV R%d, 0\n",r1);
				fprintf(fp, "NE R%d, R%d\n",r,r1);
				fprintf(fp, "JZ R%d, L%d\n",r,l1);
				freeReg();
				freeReg();
				StatementsCodeGen(t->mid);
				fprintf(fp, "JMP L%d\n",l2);
				fprintf(fp, "L%d:\n",l1);
				StatementsCodeGen(t->right);
				fprintf(fp, "L%d:\n",l2);
				return 0;
			}
			break;

		case WHILE:
			{
				l1=getLabel();
				l2=getLabel();
				fprintf(fp, "L%d:\n",l1);
				r=StatementsCodeGen(t->left);
				r1=getReg();
				fprintf(fp, "MOV R%d, 0\n",r1);
				fprintf(fp, "NE R%d, R%d\n",r,r1);
				fprintf(fp, "JZ R%d, L%d\n",r,l2);
				freeReg();
				freeReg();
				StatementsCodeGen(t->right);
				fprintf(fp, "JMP L%d\n",l1);
				fprintf(fp, "L%d:\n",l2);
				return 0;
			}
			break;

		case CONNECT:
			StatementsCodeGen(t->left);
			StatementsCodeGen(t->right);
			return 0;
			break;
	}
}



