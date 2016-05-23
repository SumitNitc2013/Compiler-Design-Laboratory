//this is a header file
struct node
{
	int val;
	int NodeType;
	struct node *left,*right;
};

typedef struct node tnode;

tnode* makeLeafNode(int n);

tnode* makeOperatornode(int op,tnode* left,tnode* right);

int evaluate(tnode* r);     //r is the root of the tree
