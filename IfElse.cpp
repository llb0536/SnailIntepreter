#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include "snail.h"
#include "mystr.h"

int IfElse(inst x[],int size)
{
	int i=0,j=0,k=0,t=0;
	int flag=0;
	inst xx[M];
	//printf("%s\n",x[0]->in);
	if(strstr(x[0]->in,"if ")!=NULL&&strstr(x[0]->in," then")!=NULL)
	{
		replace(x[0]->in,"if ","");
		replace(x[0]->in," then","");
		if(calEx(x[0]->in)==N)
		{
			//printf("Error IF Expression!\n");
			return (-1);
		}
		flag=0;
		for(i=size-2;i>1;i--)
		{
			if(strnicmp(x[i]->in,"endif",5)==0)
				flag++;
			if(strnicmp(x[i]->in,"if ",3)==0)
				flag--;
			if(flag==0&&strnicmp(x[i]->in,"else",4)==0)
				break;
		}
		//printf("else in line %d",i);
		if(calEx(x[0]->in)!=0)
		{
			if(i==1)
				for(j=1;j<size-1;j++)
				{
					//printf("a\n");
					//¼ÓµÝ¹é°¡¼ÓµÝ¹é£¡£¡£¡£¡£¡£¡
					if(strnicmp(x[j]->in,"if ",3)==0)
					{
						//printf("b\n");
						flag=1;
						k=j;						
						while(flag!=0)
						{
							//printf("c\n");
						
							if(strnicmp(x[k]->in,"endif",5)==0)
								flag--;
							if(strnicmp(x[k]->in,"if ",3)==0)
								flag++;
							k++;
						}
						for(t=0;t<k-j;t++)
						{
							//printf("d\n");
							xx[t]=(inst)malloc(sizeof(instr));
							xx[t]=x[t+j];
						}
						ExtractComm(xx,k-j);
						for(t=0;t<k-j;t++)
						{
							//printf("e\n");
							free(xx[t]);
						}
						//printf("f\n");
						j=k;
						flag=0;
					}
					else
					{
						//printf("g\n");
						ExtractCommand(x[j]);
					}
				}
			else
				for(j=1;j<i;j++)
				{
					//printf("h\n");
					if(strnicmp(x[j]->in,"if ",3)==0)
					{
						//printf("i\n");
						flag=1;
						k=j;
						while(flag!=0)
						{
							//printf("j%s\n",x[k]->in);
							
							if(strnicmp(x[k]->in,"endif",5)==0)
								flag--;
							if(strnicmp(x[k]->in,"if ",3)==0)
								flag++;
							k++;
						}
						for(t=0;t<k-j;t++)
						{
							//printf("k\n");
							xx[t]=(inst)malloc(sizeof(instr));
							xx[t]=x[t+j];
						}
						ExtractComm(xx,k-j);
						for(t=0;t<k-j-1;t++)
						{
							//printf("l\n");
							//free(xx[t]);
						}
						j=k;
						flag=0;
					}
					else
					{
						//printf("m\n");
						ExtractCommand(x[j]);
					}
				}
		}
		else
		{
			if(i!=1)
				for(j=i+1;j<size-1;j++)
				{
					ExtractCommand(x[j]);
				}
		}
	}
	else
	{
		printf("Error IF Expression!\n");
		return -1;
	}
	return 1;
}