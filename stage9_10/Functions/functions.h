//this is a header file
typedef struct Gsymbol gsymbol;
typedef struct Lsymbol lsymbol;
typedef struct node tnode;
typedef struct IDLIST idlist;
typedef struct Arglst ArgStruct;

struct node
{
	//Type is the data type
	int TYPE;
	//NODETYPE is NUM, ID , READ etc
	int NODETYPE;
	int val;
	char* NAME;
	struct node *left,*mid, *right;
	struct node *Arglist;
	gsymbol *Gentry;  //for global varibale/functions
	lsymbol *Lentry; //for loacl variable
};

struct Gsymbol {

char *NAME; 

int TYPE; 

int SIZE; 

int BINDING; 

tnode *Arglist;

struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

struct Lsymbol {
char *NAME;
int TYPE;
int BINDING;
int refType;
struct Lsymbol *NEXT;
};

struct IDLIST
{
	char* NAME;
	int size;
	tnode *arglst;
	struct IDLIST *next;
};

/*struct Arglst
{
	char* NAME;
	int TYPE;
	int flag; //flag=0 means pass by value and flag=1 means pass by refrence
	struct Arglst *NEXT;
	//size will be always 1 for each argument according to specification
};*/

tnode* makeNumLeafNode(int n);

tnode* makeVarLeafNode(char* var);

tnode* makeNameNode(int c,tnode* left,tnode* mid,tnode* right);

//int evaluate(tnode* r);     //r is the root of the tree

gsymbol* Glookup(char* NAME);

void Ginstall(gsymbol* node);

gsymbol* make_gsymbol_node(char* NAME, int type, int size,tnode* Arglist);

lsymbol *Llookup(char *NAME);

void Linstall(lsymbol* node);

lsymbol* make_lsymbol_node(char* NAME,int type);

void functionHeaderCheck(int type,char* NAME,tnode* arglst);

