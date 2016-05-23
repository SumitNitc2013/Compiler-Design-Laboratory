//this is a header file
typedef struct Gsymbol gsymbol;
struct node
{
	//type is data type
	int TYPE;
	//NODETYPE is NUM,ID,READ etc
	int NODETYPE;
	int val;
	char* NAME;
	struct node *left,*mid, *right;
	gsymbol *Gentry;
};

typedef struct node tnode;

struct Gsymbol {

char *NAME; 

int TYPE; 

int SIZE; 

int BINDING; 

struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

struct IDLIST
{
	char* NAME;
	int size;
	struct IDLIST *next;
};

typedef struct IDLIST idlist;

tnode* makeNumLeafNode(int n);

tnode* makeVarLeafNode(char* var);

tnode* makeNameNode(int c,tnode* left,tnode* mid,tnode* right);

int evaluate(tnode* r);     //r is the root of the tree

gsymbol* lookup(char* NAME);

void install(gsymbol* node);

gsymbol* make_gsymbol_node(char* NAME, int type, int size);



