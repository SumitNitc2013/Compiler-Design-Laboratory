/*array out of bound is a runtime problem not a compile time problem at all
no type information for this stage all variables and array are integers*/

#include "y.tab.h"
#include "stdio.h"
int x,ans;

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

int evaluate(tnode* r)
{
	if(r==NULL)
	{
		return 0;
	}
	switch(r->NODETYPE)
	{
		case NUM:
			return r->val;
			break;

		case ID:
			return array[r->Gentry->BINDING];
			break;

		case ARRAY:
			return array[r->left->Gentry->BINDING + evaluate(r->right)];
			break;

		case PLUS:
			return evaluate(r->left)+evaluate(r->right);
			break;

		case MINUS:
			return evaluate(r->left)- evaluate(r->right);
			break;

		case MUL:
			return evaluate(r->left) * evaluate(r->right);
			break;

		case DIV:
			return evaluate(r->left) / evaluate(r->right);
			break;

		case MOD:
			return evaluate(r->left) % evaluate(r->right);
			break;

		case LT:
			return evaluate(r->left) < evaluate(r->right);
			break;

		case GT:
			return evaluate(r->left) > evaluate(r->right);
			break;

		case EQ:
			return evaluate(r->left) == evaluate(r->right);
			break;

		case NE:
			return evaluate(r->left) != evaluate(r->right);
			break;

		case LE:
			return evaluate(r->left) <= evaluate(r->right);
			break;

		case GE:
			return evaluate(r->left) >= evaluate(r->right);
			break;

		case EQUALS:
			if(r->left->NODETYPE==ARRAY)
			{
				array[r->left->left->Gentry->BINDING + evaluate(r->left->right)]=evaluate(r->right);
			}
			else
			{
				array[r->left->Gentry->BINDING]=evaluate(r->right);
			}
			return 0;
			break;

		case READ:
			scanf("%d",&x);
			if(r->left->NODETYPE==ARRAY)
			{
				array[r->left->left->Gentry->BINDING + evaluate(r->left->right)]=x;
			}
			else
			{
				array[r->left->Gentry->BINDING]=x;
			}
			return 0;
			break;

		case WRITE:
			ans=evaluate(r->left);
			printf("%d\n",ans);
			return 0;
			break;

		case IF:
			if(r->mid==NULL)
			{
				if(evaluate(r->left)==1)
					evaluate(r->right);
			}
		
			else
			{
				if(evaluate(r->left)==1)
					evaluate(r->mid);
				else
					evaluate(r->right);
			}
			return 0;
			break;

		case WHILE:
			while(evaluate(r->left)==1)
					evaluate(r->right);
			return 0;
			break;

		case CONNECT:
			evaluate(r->left);
			evaluate(r->right);
			return 0;
			break;
			
	}
}


