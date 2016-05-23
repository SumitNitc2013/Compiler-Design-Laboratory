#include "y.tab.h"
tnode* makeLeafNode(int n)
{
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
	leaf->val=n;
	leaf->NodeType=NUM;
	leaf->left=NULL;
	leaf->right=NULL;
	return leaf;
}

tnode* makeOperatorNode(int op,tnode* left,tnode* right)
{
	tnode* operator_node;
	operator_node=(tnode*)malloc(sizeof(tnode));
	operator_node->NodeType=op;
	operator_node->left=left;
	operator_node->right=right;
	return operator_node;
}

int evalute(tnode* r)
{
	if(r->NodeType==NUM)
		return r->val;
	else
	{
		switch(r->NodeType)
		{
			case PLUS:
				return evalute(r->left)+evalute(r->right);
				break;

			case MINUS:
				return evalute(r->left)-evalute(r->right);
				break;

			case MUL:
				return evalute(r->left)*evalute(r->right);
				break;

			case DIV:
				return evalute(r->left)/evalute(r->right);
				break;

			case MOD:
				return evalute(r->left) % evalute(r->right);
				break;
		}
	}
}