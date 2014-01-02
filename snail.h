#define M 100
#define N -10000
#define MAX 10000
typedef struct node 
{
	char e[10000];
}expression,*express;

typedef struct ordernode
{
	char *in;
	struct ordernode *next;
}instr,*inst;

typedef struct idnode
{
	char name[M];
	int data;
	struct idnode *next;
}iden,*id;

//typedef struct  
void printcode(char *code);
void print(express ex);

void printID();
void updateID(id idr,int num);

int calExpress(express ex);
int calEx(char infixexp[M]);

int ExtractCommand(inst x);
int ExtractComm(inst x[],int size);
int idVal(char *s);
int IfElse(inst x[],int size);