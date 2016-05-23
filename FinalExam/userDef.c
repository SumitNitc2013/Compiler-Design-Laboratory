/*array out of bound is a runtime problem not a compile time problem at all*/
#include "y.tab.h"
#include "stdio.h"
int x,ans;
int regCount=-1;
int pushRegCount;
int CodeGen(tnode *t);
void freeReg();
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

TypeTable* make_TypeTable_node(char* NAME, tnode* fields)
{
	TypeTable* temp;
	temp=(TypeTable*)malloc(sizeof(TypeTable));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->fields=fields;
	temp->NEXT=NULL;
	return temp;
}

void TTinstall(TypeTable* node)
{
	TypeTable* temp=TTLookup(node->NAME);
	if(temp!=NULL)
	{
		printf("Error at line number %d !!!\nType %s Redeclared\n",lineNum, node->NAME);
		exit(0);
	}
	
	node->NEXT=TThead;
	TThead=node;
}

TypeTable* TTLookup(char *NAME)
{
	TypeTable* temp=TThead;
	while(temp!=NULL)
	{
		if(strcmp(temp->NAME,NAME)==0)
			return temp;
		temp=temp->NEXT;
	}
	return NULL;
}

void AddFieldsInTT(char* NAME,tnode* fields)
{
	TypeTable* temp=TTLookup(NAME);
	temp->fields=fields;
}

void checkName(char* NAME)
{
	TypeTable* temp=TTLookup(NAME);
	if(temp!=NULL)
	{
		printf("ERROR at line number %d!!!\n%s is a Type!!\nName of variable should not be same as name of type\n",lineNum,NAME);
		exit(0);
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


gsymbol* make_gsymbol_node(char* NAME,TypeTable* TYPE, int size,tnode* arglst)
{
	gsymbol* temp;
	temp=(gsymbol*)malloc(sizeof(gsymbol));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->TYPE=TYPE;
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

/*void print_Gsymbol()
{
	gsymbol* temp=Ghead;
	while(temp!=NULL)
	{
		printf("NAME=%s, TYPE=%p, size=%d ",temp->NAME,temp->TYPE,temp->SIZE);
		printf("binding=%d\n",temp->BINDING);
		temp=temp->NEXT;
	}
}*/

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

lsymbol* make_lsymbol_node(char* NAME,TypeTable* TYPE)
{
	lsymbol* temp;
	temp=(lsymbol*)malloc(sizeof(lsymbol));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->TYPE=TYPE;
	temp->refType=0;
	temp->NEXT=NULL;
	temp->BINDING=Lmem+1;
	Lmem=Lmem+1;
	return temp;
}

TypeTable* FieldTypeCheck(char* NAME)
{

	TypeTable* temp=TTLookup(NAME);
	if(temp==NULL)
	{
		printf("Error at line numebr %d!!type %s is not defined\n",lineNum,NAME);
		exit(0);
	}
	return temp;
}

void checkReturnType(char* NAME, TypeTable* TYPE,tnode* node)
{
	if(TYPE!=node->TYPE)
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

			if(l1->val==1 && l2->NODETYPE!=ID && l2->NODETYPE!=ARRAY && l2->NODETYPE!=FLD)
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

void functionHeaderCheck(TypeTable* TYPE,char* NAME,tnode* arglst)
{
	gsymbol* temp=Glookup(NAME);
	if(temp==NULL || temp->SIZE!=-2)
		{
			printf("Error at line Number %d !!\nFunction %s is not Declared in Global Declaration Area\n",lineNum, NAME);
			exit(0);
		}
	else if(temp->TYPE!=TYPE)
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

void SetFieldType(TypeTable* TYPE,tnode** node)
{
	tnode* temp= TYPE->fields;
	while(temp!=NULL)
	{
		if(strcmp(temp->NAME,(*node)->NAME)==0)
		{
			(*node)->TYPE=temp->TYPE;
			(*node)->val=temp->val;   //val is acting as offset of the field in that particular type definition
			return;
		}
		temp=temp->right; //right is acting as next pointer of the linked list
	}
	printf("Error!! No field name %s in type %s!!!\n Error at line number %d\n",(*node)->NAME,TYPE->NAME,lineNum);
	exit(0);
}


void checkField(tnode* node1, tnode* node2)
{
	while(node1!=NULL)
	{
		if(strcmp(node1->NAME,node2->NAME)==0)
		{
			printf("Error!!! Same field name can not be declared twice\n");
			exit(0);
		}
		node1=node1->right;
	}
}

tnode* makeNumLeafNode(int n)
{
	
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
	leaf->TYPE=TTLookup("integer");
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

tnode* makeNameNode(int c,tnode* left,tnode* mid,tnode* right)   //here c represents NodeType
{
	tnode* name_node;
	tnode* ptr;
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=left->TYPE;  //or right->type is also fine
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=left->TYPE;  //or right->type is also fine
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=left->TYPE;  //or right->type is also fine
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=left->TYPE;  //or right->type is also fine
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=left->TYPE;  //or right->type is also fine
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=TTLookup("boolean");
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=TTLookup("boolean");
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
			if(strcmp(left->TYPE->NAME,"boolean")==0 || strcmp(right->TYPE->NAME,"boolean")==0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			if(left->TYPE!=right->TYPE)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=TTLookup("boolean");
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
			if(strcmp(left->TYPE->NAME,"boolean")==0 || strcmp(right->TYPE->NAME,"boolean")==0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			if(left->TYPE!=right->TYPE)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=TTLookup("boolean");
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=TTLookup("boolean");
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
			if(strcmp(left->TYPE->NAME,"integer")!=0 || strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=TTLookup("boolean");
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
			if(strcmp(left->TYPE->NAME,"boolean")!=0 || strcmp(right->TYPE->NAME,"boolean")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=left->TYPE;
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
			if(strcmp(left->TYPE->NAME,"boolean")!=0 || strcmp(right->TYPE->NAME,"boolean")!=0)
			{
				printf("Error at line Number %d !!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=left->TYPE;
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
			if(strcmp(left->TYPE->NAME,"boolean")!=0)
			{
				printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=left->TYPE;
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
			if(strcmp(right->TYPE->NAME,"integer")!=0)
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


		case DEQUE:
			if(strcmp(left->TYPE->NAME,"queue")!=0)
			{
				printf("Error at line number %d,\n We must have a queue variable to deque\n",lineNum);
				exit(0);
			}
			if(left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line number %d!!Queue variable %s not decalred\n",lineNum,left->NAME);
				exit(0);
			}
			name_node->NODETYPE=DEQUE;
			name_node->TYPE=left->TYPE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case ENQUE:
			if(strcmp(left->TYPE->NAME,"queue")!=0)
			{
				printf("Error at line number %d,\n We must have a queue variable to ENQUE\n",lineNum);
				exit(0);
			}
			if(strcmp(right->TYPE->NAME,"integer")!=0)
			{
				printf("Error at line number %d,\n We can only enqueue integer variable\n",lineNum);
				exit(0);
			}
			if(left->Lentry==NULL && left->Gentry==NULL)
			{
				printf("Error at line number %d!!Queue variable %s not decalred\n",lineNum,left->NAME);
				exit(0);
			}
			name_node->NODETYPE=ENQUE;
			name_node->TYPE=NULL;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case FLD:
				ptr=left;
				left->Lentry=Llookup(left->NAME);
				while(ptr->Arglist!=NULL)
				{
					if(ptr->Arglist->NODETYPE==ARRAY)
					{
						printf("Error,,!! Wrong fields at line number %d\n",lineNum);
						exit(0);
					}
					SetFieldType(ptr->TYPE,&(ptr->Arglist));
					ptr=ptr->Arglist;
				}
				name_node->TYPE=left->mid->TYPE;  //type of the tail element
				name_node->NODETYPE=FLD;
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
			if(right->NODETYPE==ID && right->Lentry==NULL && right->Gentry==NULL)
				{
					printf("Error at line number %d!!\n Variable %s not declared\n",lineNum, right->NAME);
					exit(0);
				}
				/*if(lineNum==29)
				{
					printf("TYPE1=%p, TYPE2=%p\n",left->TYPE,right->TYPE);
				}*/

			/*if()
			{
				if(strcmp(right->TYPE->NAME,"integer")!=0)
				{
					printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
					exit(0);
				}
			}*/

			/*if(right->NODETYPE==ALLOC && (strcmp(left->TYPE->NAME,"integer")==0 || strcmp(right->TYPE->NAME,"boolean")==0))
			{
				printf("Error at line number %d!!\n value returned by allocate can not be assigned to to %s type\n",lineNum,left->TYPE->NAME);
				exit(0);
			}


			 if(!(left->NODETYPE==ID && strcmp(left->NAME,"NUL")==0) && right->NODETYPE!=ALLOC && left->TYPE!=right->TYPE)
				{
					printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
					exit(0);
				}*/

			
			else
			{
					if(mid==NULL)
					{
						name_node->TYPE=NULL;
						name_node->NODETYPE=EQUALS;
						name_node->NAME=NULL;
						name_node->left=left;
						name_node->mid=mid;
						name_node->right=right;
					}
			 	   else
					{
						name_node->TYPE=NULL;
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
				
				if(strcmp(left->TYPE->NAME,"integer")!=0)
					{
						printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
						exit(0);
					}
				else
				{
					if(mid==NULL)
					{
						name_node->TYPE=NULL;
						name_node->NODETYPE=READ;
						name_node->NAME=NULL;
						name_node->left=left;
						name_node->mid=mid;
						name_node->right=right;
					}
					else
					{
						name_node->TYPE=NULL;
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
				if(strcmp(left->TYPE->NAME,"boolean")==0)
					{
						printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
						exit(0);
					}
				else
					{
						name_node->TYPE=NULL;
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

				if(strcmp(left->TYPE->NAME,"boolean")!=0)
				{
					printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
					exit(0);
				}
				name_node->TYPE=NULL;
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
			if(strcmp(left->TYPE->NAME,"boolean")!=0)
			{
				printf("Error at line number %d!!\nCompilation Error!!!! TYPE missmatch\n",lineNum);
				exit(0);
			}
			name_node->TYPE=NULL;
			name_node->NODETYPE=WHILE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case CONNECT:
			name_node->TYPE=NULL;
			name_node->NODETYPE=CONNECT;
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

		case ALLOC:
			name_node->NODETYPE=ALLOC;
			name_node->TYPE=TTLookup("integer");
			name_node->left=left;
			name_node->right=right;
			name_node->mid=mid;
			break;

		case FREE:
			name_node->NODETYPE=FREE;
			name_node->TYPE=NULL;
			name_node->left=left;
			name_node->right=right;
			name_node->mid=mid;
			break;

		default:
				break;
	}
return name_node;
}

void Initialize()
{
	int i,r;
	r=getReg();
	fprintf(fp, "Initialize:\n");
	//saving BP
	fprintf(fp, "PUSH BP\n");
	fprintf(fp, "MOV BP, SP\n");
	//making heap
	for(i=0;i<504;i=i+16)
	{
		//changes made
		fprintf(fp, "MOV R%d, %d\n",r,i+13);
		fprintf(fp, "MOV [R%d], %d\n",r,-1);
		//changes made
		fprintf(fp, "MOV R%d, %d\n",r,i+13+1);
		fprintf(fp, "MOV [R%d], %d\n",r,-1);

		fprintf(fp, "MOV R%d, %d\n",r,i+15);
		fprintf(fp, "MOV [R%d], %d\n",r,i+15+1);
	}
	//putting -1 at [511]
	fprintf(fp, "MOV R%d, %d\n",r,-1);
	fprintf(fp, "MOV [511], R%d\n",r);
	//putting 0 at [512]
	fprintf(fp, "MOV R%d, %d\n",r,0);
	fprintf(fp, "MOV [512], R%d\n",r);
	//freeing the register used
	freeReg();
	//poping off BP
	fprintf(fp, "POP BP\n");
	//returnning
	fprintf(fp, "RET\n");
}

void Allocate()
{

	int r,r1,r2;
	r=getReg();
	fprintf(fp, "Allocate:\n");
	//saving BP
	fprintf(fp, "PUSH BP\n");
	fprintf(fp, "MOV BP, SP\n");
	//saving the return block number
	fprintf(fp, "MOV R%d, [512]\n",r);
	r1=getReg();
	r2=getReg();
	//putting the new first free block at address at [512]
	fprintf(fp, "MOV R%d, [512]\n",r1);
	fprintf(fp, "MOV R%d, %d\n",r2,15);
	fprintf(fp, "ADD R%d, R%d\n",r1,r2);
	fprintf(fp, "MOV R%d, [R%d]\n",r1,r1);
	fprintf(fp, "MOV [512], R%d\n",r1);
	freeReg();
	freeReg();
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
	//poping off BP
	fprintf(fp, "POP BP\n");
	//returnning
	fprintf(fp, "RET\n");
}



void Free()
{
	//whoever calls free will put the blockNumber to be freed to be the actual 
	//argument on the top of stack
	int r,r1,r2;
	//making label of the function
	fprintf(fp, "Free:\n");
	//saving BP
	fprintf(fp, "PUSH BP\n");
	fprintf(fp, "MOV BP, SP\n");
	//the block which is going to be freed make that first free block
	//so put [512]=blockNumber AND whatever was there at [512] intially 
	//put it in the next free block of the bolck nummber which is going
	//to be freed
	//fetching the block number to be freed
	r=getReg();
	r1=getReg();
	fprintf(fp, "MOV R%d, %d\n",r1,-3);
	r2=getReg();
	fprintf(fp, "MOV R%d, BP\n",r2);
	fprintf(fp, "ADD R%d, R%d\n",r1,r2);
	fprintf(fp, "MOV R%d, [R%d]\n",r,r1);
	freeReg();
	freeReg();
	//now in r we have the block number to be freed

	r1=getReg();
	r2=getReg();
	fprintf(fp, "MOV R%d, R%d\n",r1,r);
	fprintf(fp, "MOV R%d, %d\n",r2,15);
	fprintf(fp, "ADD R%d, R%d\n",r1,r2);
	fprintf(fp, "MOV [R%d], [512]\n",r1);
	fprintf(fp, "MOV [512], R%d\n",r);
	freeReg();
	freeReg();
	freeReg();
	//putting the return value
	r1=getReg();
	fprintf(fp, "MOV R%d, %d\n",r1,-2);
	r2=getReg();
	fprintf(fp, "MOV R%d, BP\n",r2);
	fprintf(fp, "ADD R%d, R%d\n",r1,r2);
	fprintf(fp, "MOV [R%d], R%d\n",r1,0);   //0 return value means success
	freeReg();
	freeReg();

	//poping off BP
	fprintf(fp, "POP BP\n");
	//returnning
	fprintf(fp, "RET\n");
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
	tnode* dp;
	/*returns the number of the register which contains binding*/
	if(t->NODETYPE==FLD)
	{
		r=getBinding(t->left);
		dp=t->left;
		//r=getReg();
		r1=getReg();
		//fprintf(fp, "MOV R%d, %d\n",r,loc);
		while(dp->Arglist!=NULL)
		{
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r);
			fprintf(fp, "MOV R%d, %d\n",r,dp->Arglist->val);  //loc=Rr+ offset
			fprintf(fp, "ADD R%d, R%d\n",r,r1);
			dp=dp->Arglist;
		}
		freeReg();
		return r;
	}

	else if(t->NODETYPE==ARRAY)
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
			if(t->Lentry->refType==1)
				fprintf(fp, "MOV R%d, [R%d]\n",r,r);
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
	int i;
	int r;
	r=getReg();
	fprintf(fp, "START\n");
	fprintf(fp, "MOV BP, 513\n");
	for(i=513;i<=Gmem;i++)
	{
		fprintf(fp, "MOV R%d, %d\n",r,i);
		fprintf(fp, "MOV [R%d], -1\n",r);
	}
	freeReg();
	fprintf(fp, "MOV SP, %d\n",Gmem+1);
	fprintf(fp, "CALL Initialize\n");
	fprintf(fp, "CALL main\n");
	fprintf(fp, "HALT\n");
}


void FunctionCodegen(tnode* t)
{
	int r,r1,r2;
	int i;
	//saving BP
	fprintf(fp, "%s:\n",t->NAME);
	fprintf(fp, "PUSH BP\n");
	fprintf(fp, "MOV BP, SP\n");
	//reserving space for local variables
	r=getReg();
	r1=getReg();
	for(i=1;i<=Lmem;i++)
	{
		fprintf(fp, "MOV R%d, BP\n",r);
		fprintf(fp, "MOV R%d, %d\n",r1,i);
		fprintf(fp, "ADD R%d, R%d\n",r,r1);
		fprintf(fp, "MOV [R%d], %d\n",r,-1);
	}
	freeReg();
	freeReg();

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
	int r,r1,r2,r3,retReg;
	int value;
	int i;
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
			r=getBinding(t);
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			return r;
			break;

		case FLD:
			r=getBinding(t);
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			return r;
			break;

		case ARRAY:
			r=getBinding(t);
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
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
			r=StatementsCodeGen(t->left);
			r1=StatementsCodeGen(t->right);
			fprintf(fp, "MUL R%d, R%d\n",r,r1);
			freeReg();
			return r;
			break;
			/*l1=getLabel();
			l2=getLabel();
			r=StatementsCodeGen(t->left);
			r1=getReg();
			fprintf(fp, "MOV R%d, 0\n",r1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			//freeReg();
			r=StatementsCodeGen(t->right);
			//r1=getReg();
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
			break;*/

		case OR:
			l1=getLabel();
			l2=getLabel();
			r=StatementsCodeGen(t->left);
			r1=StatementsCodeGen(t->right);
			fprintf(fp, "ADD R%d, R%d\n",r,r1);
			fprintf(fp, "MOV R%d, %d\n",r1,2);
			fprintf(fp, "EQ R%d, R%d\n",r1,r);
			fprintf(fp, "JNZ R%d, L%d\n",r1,l1);
			fprintf(fp, "JMP L%d\n",l2);
			fprintf(fp, "L%d:\n",l1);
			fprintf(fp, "MOV R%d, %d\n",r,1);
			fprintf(fp, "L%d:\n",l2);
			freeReg();
			return r;
			break;
			/*l1=getLabel();
			l2=getLabel();
			r=StatementsCodeGen(t->left);
			r1=getReg();
			fprintf(fp, "MOV R%d, 1\n",r1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			r=StatementsCodeGen(t->right);
			//r1=getReg();
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
			break;*/

		case NOT:
			r=StatementsCodeGen(t->left);
			r1=getReg();
			fprintf(fp, "MOV R%d, %d\n",r1,1);
			fprintf(fp, "SUB R%d, R%d\n",r1,r);
			fprintf(fp, "MOV R%d, R%d\n",r,r1);
			freeReg();
			return r;
			break;
			/*l1=getLabel();
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
			break;*/

		case DEQUE:
			//check if queue has not been allocated
			r=getBinding(t->left);
			r1=getReg();
			l1=getLabel();
			l2=getLabel();
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			fprintf(fp, "MOV R%d, %d\n",r1,-1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			freeReg();
			freeReg();

			//check if head is -1
			r=getBinding(t->left);
			r1=getReg();
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			fprintf(fp, "MOV R%d, %d\n",r1,13);
			fprintf(fp, "ADD R%d, R%d\n",r1,r);
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r1);
			fprintf(fp, "MOV R%d, R%d\n",r,r1);
			fprintf(fp, "MOV R%d, %d\n",r1,-1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JNZ R%d, L%d\n",r,l1);
			freeReg();
			freeReg();


			//check if head>tail
			r=getBinding(t->left);
			r1=getReg();
			r2=getReg();
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			fprintf(fp, "MOV R%d, %d\n",r1,13);
			fprintf(fp, "ADD R%d, R%d\n",r1,r);
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r1);

			fprintf(fp, "MOV R%d, %d\n",r2,14);
			fprintf(fp, "ADD R%d, R%d\n",r2,r);
			fprintf(fp, "MOV R%d, [R%d]\n",r2,r2);

			fprintf(fp, "GT R%d, R%d\n",r1,r2);
			fprintf(fp, "JNZ R%d, L%d\n",r1,l1);
			freeReg();
			freeReg();
			freeReg();

			//Dequeu process starts
			r=getBinding(t->left);
			r1=getReg();
			r2=getReg();
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			fprintf(fp, "MOV R%d, %d\n",r1,13);
			fprintf(fp, "ADD R%d, R%d\n",r1,r);
			fprintf(fp, "MOV R%d, [R%d]\n",r2,r1);
			fprintf(fp, "ADD R%d, R%d\n",r2,r);
			fprintf(fp, "MOV R%d, [R%d]\n",r2,r2);
			fprintf(fp, "MOV R%d, R%d\n",r,r2);    //return value is in r
			freeReg();
			freeReg();
			//now increment the head
			r1=getBinding(t->left);
			r2=getReg();
			r3=getReg();
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r1);
			fprintf(fp, "MOV R%d, %d\n",r2,13);
			fprintf(fp, "ADD R%d, R%d\n",r2,r1);
			fprintf(fp, "MOV R%d, [R%d]\n",r2,r2);
			fprintf(fp, "INR R%d\n",r2);
			fprintf(fp, "MOV R%d, %d\n",r3,13);
			fprintf(fp, "ADD R%d, R%d\n",r3,r1);
			fprintf(fp, "MOV [R%d], R%d\n",r3,r2);
			freeReg();
			freeReg();
			freeReg();
			//put return value in r and jump
			fprintf(fp, "JMP L%d\n",l2);

			//print label1 to return 0
			fprintf(fp, "L%d:\n",l1);
			fprintf(fp, "MOV R%d, %d\n",r,0);

			//print label 2
			fprintf(fp, "L%d:\n",l2);
			return r;
			break;

		case ENQUE:
			r=getBinding(t->left);
			r1=getReg();
			l1=getLabel();
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			fprintf(fp, "MOV R%d, %d\n",r1,-1);
			fprintf(fp, "EQ R%d, R%d\n",r,r1);
			fprintf(fp, "JZ R%d, L%d\n",r,l1);
			freeReg();
			freeReg();
			//call allocate function
			retReg=getReg();
			pushRegCount=regCount-1;
			//pushes registers in revesre order so that at the time of poping we can directly
			//pop in increasing order of register number
			for(i=pushRegCount;i>=0;i--)
			{
				fprintf(fp, "PUSH R%d\n",i);
				//freeReg();
			}

			//now all the registers are avaliable for the calle function
			regCount=-1;

			//no actual arguments to push

			//pushing return value
			fprintf(fp, "PUSH R%d\n",retReg);

			//writing call statement
			fprintf(fp, "CALL Allocate\n");

			//poping off return value
			fprintf(fp, "POP R%d\n",retReg);

			//No actual argumens to pop off

			//restoring registers
			for(i=0;i<=pushRegCount;i++)
			{
				fprintf(fp, "POP R%d\n",i);
			}
			regCount=pushRegCount+1;
			
			r=getBinding(t->left);
			//now in retreg we have the block assigned
			//r1=getBinding(t->left);
			fprintf(fp, "MOV [R%d], R%d\n",r,retReg);
			freeReg();
			//so now in register we have the block number
			//fprintf(fp, "MOV R%d, R%d\n",r,retReg);
			//freeReg();

			//making label and start enqueue process
			fprintf(fp, "L%d:\n",l1);
			 //freeing r
			//enqueue process starts
			r=getBinding(t->left);
			r1=getReg();
			r2=getReg();
			l2=getLabel();
			//check if head is -1
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			fprintf(fp, "MOV R%d, %d\n",r1,13);
			fprintf(fp, "ADD R%d, R%d\n",r1,r);
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r1);
			fprintf(fp, "MOV R%d, %d\n",r2,-1);
			fprintf(fp, "EQ R%d, R%d\n",r1,r2);
			fprintf(fp, "JZ R%d, L%d\n",r1,l2);
			//store 0 relative address in front
			fprintf(fp, "MOV R%d, %d\n",r1,13);
			fprintf(fp, "ADD R%d, R%d\n",r1,r);
			fprintf(fp, "MOV [R%d], %d\n",r1,0);

			//increment the tail and put the value
			fprintf(fp, "L%d:\n",l2);
			fprintf(fp, "MOV R%d, %d\n",r1,14);
			fprintf(fp, "ADD R%d, R%d\n",r1,r);
			fprintf(fp, "MOV R%d, [R%d]\n",r2,r1);
			fprintf(fp, "INR R%d\n",r2);
			fprintf(fp, "MOV [R%d], R%d\n",r1,r2);
			//now put the result of the expression at the tail
			fprintf(fp, "MOV R%d, %d\n",r1,14);
			fprintf(fp, "ADD R%d, R%d\n",r1,r);
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r1);
			fprintf(fp, "ADD R%d, R%d\n",r1,r);
			fprintf(fp, "MOV R%d, R%d\n",r,r1);
			freeReg();
			freeReg();
			//at the address r1 store the vlue of expr
			r1=StatementsCodeGen(t->right);
			fprintf(fp, "MOV [R%d], R%d\n",r,r1);
			freeReg();
			freeReg();
			return 0;
			break;

		case EQUALS:
				r1=getBinding(t->left);
				r2=StatementsCodeGen(t->right);	
				fprintf(fp, "MOV [R%d], R%d\n",r1,r2);
				freeReg();
				freeReg();
				return 0;
				break;

		case ALLOC:
			retReg=getReg();
			pushRegCount=regCount-1;
			//pushes registers in revesre order so that at the time of poping we can directly
			//pop in increasing order of register number
			for(r=pushRegCount;r>=0;r--)
			{
				fprintf(fp, "PUSH R%d\n",r);
				//freeReg();
			}

			//now all the registers are avaliable for the calle function
			regCount=-1;

			//no actual arguments to push

			//pushing return value
			fprintf(fp, "PUSH R%d\n",retReg);

			//writing call statement
			fprintf(fp, "CALL Allocate\n");

			//poping off return value
			fprintf(fp, "POP R%d\n",retReg);

			//No actual argumens to pop off

			//restoring registers
			for(r=0;r<=pushRegCount;r++)
			{
				fprintf(fp, "POP R%d\n",r);
			}
			regCount=pushRegCount+1;
			return retReg;
			break;

		case FREE:
			retReg=getReg();
			pushRegCount=regCount-1;
			//pushes registers in revesre order so that at the time of poping we can directly
			//pop in increasing order of register number
			for(r=pushRegCount;r>=0;r--)
			{
				fprintf(fp, "PUSH R%d\n",r);
				//freeReg();
			}

			//now all the registers are avaliable for the calle function
			regCount=-1;

			//pushing actual arguments
			r=getBinding(t->left);
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			fprintf(fp, "PUSH R%d\n",r);
			freeReg();

			//pushing return value
			fprintf(fp, "PUSH R%d\n",retReg);

			//writing call statement
			fprintf(fp, "CALL Free\n");

			//poping off return value
			fprintf(fp, "POP R%d\n",retReg);

			//poping off the only actual argument
			r=getReg();
			fprintf(fp, "POP R%d\n",r);
			freeReg();

			//restoring registers
			for(r=0;r<=pushRegCount;r++)
			{
				fprintf(fp, "POP R%d\n",r);
			}
			regCount=pushRegCount+1;

			return retReg;
			 
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

			//now all the registers are avaliable for the calle function
			regCount=-1;

				
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
					/*if(temp->NODETYPE==ID)
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
						r=getBinding(temp);*/
					//temp->Lentry=Llookup(temp->NAME);
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



