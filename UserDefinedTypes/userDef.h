//this is a header file
typedef struct Gsymbol gsymbol;
typedef struct Lsymbol lsymbol;
typedef struct node tnode;
typedef struct IDLIST idlist;
typedef struct TypeTable TypeTable;
struct node
{
	//Type is the data type
	//char* TYPE;
	//NODETYPE is NUM, ID , READ etc
	int NODETYPE;
	TypeTable *TYPE;
	int val;
	char* NAME;
	struct node *left,*mid, *right;
	struct node *Arglist;
	gsymbol *Gentry;  //for global varibale/functions
	lsymbol *Lentry; //for loacl variable
};

struct Gsymbol {

char *NAME; 

TypeTable* TYPE; 

int SIZE; 

int BINDING; 

tnode *Arglist;

struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

struct Lsymbol {
char *NAME;
TypeTable* TYPE;
int BINDING;
int refType;
struct Lsymbol *NEXT;
};

struct TypeTable
{
	char *NAME;  // Name is name of the type. its an string
	tnode *fields;
	struct TypeTable *NEXT;
};

struct IDLIST
{
	char* NAME;
	int size;
	tnode *arglst;
	struct IDLIST *next;
};

tnode* makeNumLeafNode(int n);

tnode* makeVarLeafNode(char* var);

tnode* makeNameNode(int c,tnode* left,tnode* mid,tnode* right);

gsymbol* Glookup(char* NAME);

void Ginstall(gsymbol* node);

gsymbol* make_gsymbol_node(char* NAME,TypeTable* TYPE, int size,tnode* arglst);

lsymbol* Llookup(char *NAME);

void Linstall(lsymbol* node);

void TTinstall(TypeTable* node);

TypeTable* TTLookup(char *NAME);

TypeTable* make_TypeTable_node(char* NAME, tnode* fields);

lsymbol* make_lsymbol_node(char* NAME,TypeTable* TYPE);

void functionHeaderCheck(TypeTable* TYPE,char* NAME,tnode* arglst);

