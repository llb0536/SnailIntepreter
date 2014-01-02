#include <stdio.h>
#include <string.h>
#include "snail.h"
int ExtractCommand(inst x)
{
	char *s =x->in;
	
	if(!strnicmp(s,"print ",6))
		printcode(s);
	else
	{
		//printf("%s",s);
		idVal(s);		
	}
	return 1;
}
int ExtractComm(inst x[],int size)
{
	//int m=sizeof(x);
	//int i;
	//for(i=0;i<m;i++)
	//	printf("%s\n",x[0]->in);
	IfElse(x,size);
	return 0;
}
