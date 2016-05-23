/*array out of bound is a runtime problem not a compile time problem at all
no type information for this stage all variables and array are integers*/
#include "y.tab.h"
#include "stdio.h"
int x,ans;
int regCount=-1;
int CodeGen(tnode *t);
int label=0;

idlist* make_id_node(char* NAME,int size)
{
	
	idlist* temp;
	temp=(idlist*)malloc(sizeof(idlist));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->size=size;
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

gsymbol* lookup(char* NAME)
{
	gsymbol* temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->NAME,NAME)==0)
			return temp;
		temp=temp->NEXT;
	}
	return NULL;	
}


void install(gsymbol* node)
{
	gsymbol* temp=lookup(node->NAME);
	if(temp!=NULL)
	{
		printf("Error!!!Variable %s Redeclared\n",node->NAME);
		exit(0);
	}
	
	node->NEXT=head;
	head=node;
	
}


gsymbol* make_gsymbol_node(char* NAME, int size)
{
	
	
	gsymbol* temp;
	temp=(gsymbol*)malloc(sizeof(gsymbol));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->SIZE=size;
	temp->NEXT=NULL;
	temp->BINDING=indxe+1;
	indxe=indxe+size;
	return temp;
	
}

tnode* makeNumLeafNode(int n)
{
	
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
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
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=PLUS;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case MINUS:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=MINUS;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case MUL:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=MUL;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case DIV:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=DIV;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case MOD:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=MOD;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case LT:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=LT;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case GT:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=GT;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;



		case EQ:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=EQ;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case NE:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=NE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case LE:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=LE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case GE:
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			name_node->NODETYPE=GE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case ARRAY:
			if(left->Gentry==NULL)
			{
				printf("Error!! Array Variable %s not declared\n",left->NAME);
				exit(0);
			}
			name_node->NODETYPE=ARRAY;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case EQUALS:
		
		
		
			if(left->NODETYPE==ID && left->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",left->NAME);
				exit(0);
			}
			if(left->NODETYPE==ARRAY && left->left->Gentry==NULL)
			{
				printf("Error!! Array Variable %s not declared\n",left->left->NAME);
				exit(0);
			}
			if(right->NODETYPE==ID && right->Gentry==NULL)
			{
				printf("Error!! Variable %s not declared\n",right->NAME);
				exit(0);
			}
			if(right->NODETYPE==ARRAY && right->left->Gentry==NULL)
			{
				printf("Error!! Arry Variable %s not declared\n",right->left->NAME);
				exit(0);
			}

			else
			{
					if(mid==NULL)
					{
						name_node->NODETYPE=EQUALS;
						name_node->NAME=NULL;
						name_node->left=left;
						name_node->mid=mid;
						name_node->right=right;
					
				
					}
			 	   else
					{
						name_node->NODETYPE=EQUALS;
						name_node->NAME=NULL;
						name_node->left=makeNameNode(ARRAY,left,NULL,mid);
						name_node->mid=NULL;
						name_node->right=right;
					
					}
			}
			break;

		case READ:

				if(left->NODETYPE==ID && left->Gentry==NULL)
					{
						printf("Error!! Variable %s not declared\n",left->NAME);
						exit(0);
					}
				if(left->NODETYPE==ARRAY && left->left->Gentry==NULL)
					{
						printf("Error!! Array Variable %s not declared\n",left->left->NAME);
						exit(0);
					}
				else
				{
					if(mid==NULL)
					{
						name_node->NODETYPE=READ;
						name_node->NAME=NULL;
						name_node->left=left;
						name_node->mid=mid;
						name_node->right=right;
					}
					else
					{
						name_node->NODETYPE=READ;
						name_node->NAME=NULL;
						name_node->left=makeNameNode(ARRAY,left,NULL,mid);
						name_node->mid=NULL;
						name_node->right=right;
					}
				}
				break;

		case WRITE:
		
				if(left->NODETYPE==ID && left->Gentry==NULL)
					{
						printf("Error!! Variable %s not declared\n",left->NAME);
						exit(0);
					}
				if(left->NODETYPE==ARRAY && left->left->Gentry==NULL)
				{
					printf("Error!! Array Variable %s not declared\n",left->left->NAME);
					exit(0);
				}
				else
					{
						name_node->NODETYPE=WRITE;
						name_node->NAME=NULL;
						name_node->left=left;
						name_node->mid=mid;
						name_node->right=right;
					}
				
				
					break;

		case IF:
				name_node->NODETYPE=IF;
				name_node->NAME=NULL;
				name_node->left=left;
				name_node->mid=mid;
				name_node->right=right;
				break;

		case WHILE:
			name_node->NODETYPE=WHILE;
			name_node->NAME=NULL;
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case CONNECT:
			name_node->NODETYPE=CONNECT;
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
	/*returns the number of register which contains binding*/
	if(t->NODETYPE==ARRAY)
	{
			loc=t->left->Gentry->BINDING;
			r=CodeGen(t->right);
			r1=getReg();
			fprintf(fp, "MOV R%d, %d\n",r1,loc);
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

int CodeGen(tnode* t)
{
	int r,r1,r2;
	int value;
	int loc,l1,l2;
	/*r is the root of AST
	returntype of CodeGen is int that is it returns the register Number*/
	switch(t->NODETYPE)
	{

		case NUM:
			value=t->val;
			r=getReg();
			fprintf(fp,"MOV R%d, %d\n",r,value);
			return r;
			break;

		case ID:
			loc=t->Gentry->BINDING;
			r=getReg();
			fprintf(fp, "MOV R%d, [%d]\n",r,loc);
			return r;
			break;

		case ARRAY:
			loc=t->left->Gentry->BINDING;
			r=CodeGen(t->right);
			r1=getReg();
			fprintf(fp, "MOV R%d, %d\n",r1,loc);
			fprintf(fp, "ADD R%d, R%d\n",r,r1);
			fprintf(fp, "MOV R%d, [R%d]\n",r,r);
			freeReg();
			return r;
			break;


		case PLUS:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "ADD R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case MINUS:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "SUB R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case MUL:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "MUL R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case DIV:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "DIV R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case MOD:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "MOD R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case LT:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "LT R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case GT:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "GT R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case EQ:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "EQ R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case NE:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "NE R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case LE:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "LE R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case GE:
			r1=CodeGen(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "GE R%d, R%d\n",r1,r2);
			freeReg();
			return r1;
			break;

		case EQUALS:
			r1=getBinding(t->left);
			r2=CodeGen(t->right);
			fprintf(fp, "MOV [R%d], R%d\n",r1,r2);
			freeReg();
			freeReg();
			return 0;
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
			r=CodeGen(t->left);
			fprintf(fp, "OUT R%d\n",r);
			freeReg();
			return 0;
			break;

		case IF:
			if(t->mid==NULL)
			{
				l1=getLabel();
				r=CodeGen(t->left);
				r1=getReg();
				fprintf(fp, "MOV R%d, 0\n",r1);
				fprintf(fp, "NE R%d, R%d\n",r,r1);
				fprintf(fp, "JZ R%d, L%d\n",r,l1);
				freeReg();
				freeReg();
				CodeGen(t->right);
				fprintf(fp, "L%d:\n",l1);
				return 0;
			}

			else
			{
				l1=getLabel();
				l2=getLabel();
				r=CodeGen(t->left);
				r1=getReg();
				fprintf(fp, "MOV R%d, 0\n",r1);
				fprintf(fp, "NE R%d, R%d\n",r,r1);
				fprintf(fp, "JZ R%d, L%d\n",r,l1);
				freeReg();
				freeReg();
				CodeGen(t->mid);
				fprintf(fp, "JMP L%d\n",l2);
				fprintf(fp, "L%d:\n",l1);
				CodeGen(t->right);
				fprintf(fp, "L%d:\n",l2);
				return 0;
			}
			break;

		case WHILE:
			{
				l1=getLabel();
				l2=getLabel();
				fprintf(fp, "L%d:\n",l1);
				r=CodeGen(t->left);
				r1=getReg();
				fprintf(fp, "MOV R%d, 0\n",r1);
				fprintf(fp, "NE R%d, R%d\n",r,r1);
				fprintf(fp, "JZ R%d, L%d\n",r,l2);
				freeReg();
				freeReg();
				CodeGen(t->right);
				fprintf(fp, "JMP L%d\n",l1);
				fprintf(fp, "L%d:\n",l2);
				return 0;
			}
			break;

		case CONNECT:
			CodeGen(t->left);
			CodeGen(t->right);
			return 0;
			break;
	}


}