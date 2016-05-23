//this is a header file
struct node
{
	//NODETYPE type of the node like NUM,MUL,DIV etc
	int NODETYPE;
	int val;
	char var;       //to make leaf nodes for variables a-z
	struct node *left, *right;
	//only a single charecter lowercase letter is allowed as variable here
};

typedef struct node tnode;

tnode* makeNumLeafNode(int n);

tnode* makeVarLeafNode(char var);

tnode* makeNameNode(int NODETYPE,tnode* left,tnode* right);

int evaluate(tnode* r);     //r is the root of the tree


