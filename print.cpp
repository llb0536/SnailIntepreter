#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include "snail.h"

void printcode(char *code)
{
	char *comm;int i;express ex;
	comm=code+6;
	if(strcmp(comm,"newline;")==0)
		printf("\n");
	else if(comm[0]=='"'&&comm[strlen(comm)-1]==';'&&comm[strlen(comm)-2]=='"')
	{
		for(i=1;i<strlen(comm)-2;i++)
			printf("%c",comm[i]);
	}
	else 
	{
		ex=(express)malloc(sizeof(expression));
		strncpy(ex->e,comm,strlen(comm)-1);
		ex->e[strlen(comm)-1]='\0';
		print(ex);
	}
}
void print(express ex)
{
	if(calExpress(ex)!=N)
		printf("%d",calExpress(ex));
	else printf("Error in expression!");
}