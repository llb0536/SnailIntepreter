#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "snail.h"
#include "mystr.h"

extern id idH,idp,idr;
void addID(char name[],int num);
int aaa=0;

int idVal(char *s)
{
	char name[M];
	char ex[M];
	express exp;
	int num;
	replace(s," ","");
	
	if(indexOf(s,"=")!=-1)
	{
		substring(name,s,0,indexOf(s,"="));
		if(indexOf(s,";")!=-1)
			substring(ex,s,indexOf(s,"=")+1,indexOf(s,";"));
		exp=(express)malloc(sizeof(expression));
		strcpy(exp->e,ex);
		//printf("%d",calExpress(exp));
		if(calExpress(exp)!=N)
			num=calExpress(exp);
		else return N;
		idr=idH;
		while(idr->next!=NULL)
		{
			idr=idr->next;
			if(strcmp(idr->name,name)==0)
			{
				updateID(idr,num);
				return 1;
			}
		}
		addID(name,num);
	}
	return 1;
}
void updateID(id idr,int num)
{
	idr->data=num;
}
void addID(char nam[],int num)
{
	//printf("%s,%d",nam,num);
	idp=(id)malloc(sizeof(iden));
	strcpy(idp->name,nam);
	idp->data=num;
	idr->next=idp;
	idr=idp;
	idr->next=NULL;
	//printID();
}
void printID()
{
	idr=idH;
	while(idr->next!=NULL)
	{
		idr=idr->next;
		printf("\n%s,%d\n",idr->name,idr->data);
	}
}
