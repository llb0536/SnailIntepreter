/*************************/
//Copyright By ZhangBowen
//s20131047 
/*************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include "snail.h"
#include "mystr.h"

//#define DEBUG 0
inst orderH;
id idH,idp,idr;

void main()
{
	inst p,r;
	inst x[M];
	int i=0,j=0,k;
	int loc=-1;
	char ss[M][M];
	char temp[M][M];
	int flag=0;

	orderH=(inst)malloc(sizeof(instr));
	r=orderH;
	orderH->next=NULL;

	idH=(id)malloc(sizeof(iden));
	idr=idH;
	idH->next=NULL;
	k=0;
	printf("Snail code:\n");
	do
	{
		gets(ss[i++]);
		trim(ss[i-1]);
		p=(inst)malloc(sizeof(instr));
		if(strstr(ss[i-1],"//")!=NULL)
			loc=strlen(strstr(ss[i-1],"//"));
		if(loc!=-1)
		{
			strncpy(temp[k],ss[i-1],strlen(ss[i-1])-loc);
			temp[k][strlen(ss[i-1])-loc]='\0';
			p->in=temp[k];
			loc=-1;
			trim(p->in);
			k++;
			//printf("--->%s\n",p->in);
		}
		else
		{
			p->in=ss[i-1];
		}
		r->next=p;
		r=p;
	}while(strlen(p->in)!=0);
	i=0;
	r=orderH;
	printf("Results:\n");
	while(strlen(r->next->in)!=0)
	{
		r=r->next;
		if(strnicmp(r->in,"if ",3)==0)
		{
			//printf("%d",j);
			flag++;
			x[j]=(inst)malloc(sizeof(instr));
			x[j]->in=r->in;
			j++;
			while(flag!=0)
			{
				r=r->next;
				x[j]=(inst)malloc(sizeof(instr));
			    x[j]->in=r->in;
				j++;
				if(strnicmp(r->in,"if ",3)==0)flag++;
				if(strnicmp(r->in,"endif",5)==0)flag--;
			}
			//printf("%d",j);
#ifdef DEBUG
			for(k = 0; k<j-1;k++)
			{
				printf("=====xx>%s\n",x[k]->in);
			}
#endif
			ExtractComm(x,j);
			while(flag<j)
			{
				//printf("~free x%d",flag);
				free(x[flag++]);
			}
			j=0;
			flag=0;
		}
		else
			ExtractCommand(r);
		
	}
	//printID();
	printf("\n");
}

int calExpress(express ex)
{
	return calEx(ex->e);
}
