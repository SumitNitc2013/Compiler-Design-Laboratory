#include "y.tab.h"
#include <stdio.h>
int x,ans;
int regCount=-1;
int CodeGen(tnode *t);
int label=0;
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
	//always free the heigher numbered register
	regCount--;
}

int getBinding(tnode* t)
{
	int loc,r,r1;
	loc=t->var-'a';
	r=getReg();
	fprintf(fp, "MOV R%d, %d\n",r,loc);
	return r;

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
	//r is the root of AST
	//returntype of CodeGen is int that is it returns the register Number
	switch(t->NODETYPE)
	{

		case NUM:
			value=t->val;
			r=getReg();
			fprintf(fp,"MOV R%d, %d\n",r,value);
			return r;
			break;

		case ID:
			loc=t->var-'a';
			r=getReg();
			fprintf(fp, "MOV R%d, [%d]\n",r,loc);
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

		case CONNECT:
			CodeGen(t->left);
			CodeGen(t->right);
			return 0;
			break;
	}


}





	
