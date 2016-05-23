#include "y.tab.h"
int x,ans;
tnode* makeNumLeafNode(int n)
{
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
	leaf->NODETYPE=NUM;
	leaf->val=n;
	leaf->left=NULL;
	leaf->right=NULL;
	return leaf;
}

tnode* makeVarLeafNode(char var)
{
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
	leaf->NODETYPE=ID;
	leaf->var=var;
	leaf->left=NULL;
	leaf->right=NULL;
	return leaf;
}

tnode* makeNameNode(int NODETYPE,tnode* left,tnode* right)
{
	tnode* name_node;
	name_node=(tnode*)malloc(sizeof(tnode));
	name_node->NODETYPE=NODETYPE;
	name_node->left=left;
	name_node->right=right;
	return name_node;
}

int evaluate(tnode* r)
{

	if(r==NULL)
	{
	
		return 0;
	}

	else
	{
		switch(r->NODETYPE)
		{
			case NUM:
				return r->val;

			case ID:
				return array[r->var-97];

			case PLUS:
				return evaluate(r->left)+evaluate(r->right);

			case MINUS:
				return evaluate(r->left)-evaluate(r->right);

			case MUL:
				return evaluate(r->left)*evaluate(r->right);

			case DIV:
				return evaluate(r->left)/evaluate(r->right);

			case MOD:
				return evaluate(r->left)%evaluate(r->right);

			case EQUALS:
				array[r->left->var - 97]=evaluate(r->right);
				return 0;

			case READ:
				scanf("%d",&x);
				array[r->left->var - 97]=x;
				return 0;


			case WRITE:
				ans=evaluate(r->left);
				printf("%d\n",ans);
				return 0;


			case CONNECT:
				evaluate(r->left);
				evaluate(r->right);
				return 0;
		}
	}
}






	
