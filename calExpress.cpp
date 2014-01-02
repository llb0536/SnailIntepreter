#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystr.h"
#include "snail.h"
//������ջ�Ķ��弰����
#define max 1000
extern id idH,idp,idr;

typedef struct
{
	double data[max];
	int top;
}SeqStack,*PseqStack;
//��ʼ��һ����ջ
PseqStack Init_Stack(void)
{
	PseqStack s;
	s=(PseqStack)malloc(sizeof(SeqStack));
	if(s)
		s->top=-1;
	return s;
}
//�ж�ջ�Ƿ�Ϊ��
int Empty_Stack(PseqStack s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
//Ԫ����ջ
int Push_Stack(PseqStack s,double x)
{
	if(s->top==max-1)
	{
		printf("ջ����������ջ!\n");
		return 0;          //ջ��������ջ
	}
	else
	{
		s->top++;
		s->data[s->top]=x;	
		return 1;
	}
}
//Ԫ�س�ջ
int Pop_Stack(PseqStack s,double *x)
{
	if(Empty_Stack(s))
	{
		//printf("ջ�գ���Ԫ�س�ջ!\n");
		return 0;
	}
	else
	{
		*x=s->data[s->top];
		s->top--;
		return 1;
	}
}
//ȡջ��Ԫ��
int Get_Stack(PseqStack s,double *x)
{
	if(Empty_Stack(s))
	{
		printf("ջ��!\n");
		return 0;
	}
	else
	{
		*x=s->data[s->top];
		return 1;
	}
}
//����ջ
void Destory_Stack(PseqStack *s)
{
	if(*s)
		free(*s);
	*s=NULL;
}
#define M 1000
//������ջ�Ķ��弰����
typedef struct
{
	char data[M];
	int top;
}seqstack,*pseqstack;
pseqstack Init_stack()
{
	pseqstack s;
	s=(pseqstack)malloc(sizeof(seqstack));
	if(s)
		s->top=-1;
	return s;
}
//�ж�ջ��
int Empty_stack(pseqstack s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
//��ջ
int Push_stack(pseqstack s,char x)
{
	if(s->top==M-1)
	{
		printf("ջ��!");
		exit(0);
	}
	else
	{
		s->top++;
		s->data[s->top]=x;
		return 1;
	}
}
//Ԫ�س�ջ
int Pop_stack(pseqstack s,char *x)
{
	if(Empty_stack(s))
	{
		return 0;
	}
	else
	{
		*x=s->data[s->top];
		s->top--;
		return 1;
	}
}
//��ȡջ��Ԫ��
int Gettop_stack(pseqstack s,char *x)
{
	if(Empty_stack(s))
	{
		return 0;
	}
	else
	{
		*x=s->data[s->top];
		return 1;
	}
}
//����ջ
void Destory_stack(pseqstack *s)
{
	if(*s)
		free(*s);
	*s=NULL;
	return ;
}
//�ж϶�����ַ��Ƿ�������
int IsNum(char c)
{
	if(c>='0'&&c<='9')
		return 1;
	else
		return 0;
}             
//������������ȼ�
int Priority(char op)
{
	switch(op)
	{
	case '<':
	case '>':
	case '!':
	case '=':
	case '$':
	case '@': return 2;
	case '#':return 0;
	case ')':return 1;
	case '+':
	case '-':return 3;
	case '*':
	case '/':return 4;
	case '(':return 5;
	default:return -1;
	}
}
//����׺���ʽֱ����ֵ
double Infix_exp_value(char *infixexp)
{
	PseqStack s1;         //������
	pseqstack s2;         //������
	char w,topelement,ch;
	double a,b,c,sum,result;
	s1=Init_Stack();
	s2=Init_stack();
	if(!s1||!s2)
	{
		printf(" to initialize a stack is false!");
		return 0;
	}
	Push_stack(s2,'#');
	w=*infixexp;
	while((Gettop_stack(s2,&ch),ch)!='#'||w!='#')       //ȡջ��Ԫ�أ��ж��Ƿ�������
	{
		if(IsNum(w))                                     //�����ִ���
		{
			sum=0;
			sum=w-'0';
			infixexp++;
			w=*infixexp;
			while(IsNum(w))
			{
				sum=sum*10+(w-'0');
				infixexp++;
			    w=*infixexp;
			}
			Push_Stack(s1,sum);
		}
		else                                  //��������Ĵ���
		{
			if(Priority((Gettop_stack(s2,&ch),ch))>=Priority(w)&&(Gettop_stack(s2,&ch),ch)!='(') //��ǰ��������ȼ�С��ջ��
				                                                                                //���ȼ��������������"("ʱ����ջ��ȡ����
																								//�������ջ��ȡ������������㣬����������ջ
			{
				Pop_stack(s2,&topelement);
				Pop_Stack(s1,&a);
				Pop_Stack(s1,&b);
				switch(topelement)
				{
					case '<':c=(b<a);break;
					case '>':c=(b>a);break;
        			case '!':c=(b!=a);break;
					case '=':c=(b==a);break;
					case '$':c=(b>=a);break;
					case '@':c=(b<=a);break;
					case '+':c=a+b;break;
					case '-':c=b-a;break;
					case '*':c=a*b;break;
					case '/':c=b/a;break;
				}
				Push_Stack(s1,c);
			}
			else if((Gettop_stack(s2,&ch),ch)=='('&&w==')')    //��ǰ�������")"����ջ��Ԫ����"("ʱ��ȥ����
			{
				Pop_stack(s2,&topelement);
				infixexp++;
				w=*infixexp;
			}
			else                                                //��ǰ����������ȼ�����ջ��Ԫ�����ȼ�������"("ʱ��ֱ���������ջ 
			{
				Push_stack(s2,w);
				infixexp++;
				w=*infixexp;
			}
		}
	}
	Get_Stack(s1,&result);
	Destory_stack(&s2);                //��������ջ 
	Destory_Stack(&s1);
	return result;
}

int calEx(char infixexp[M])
{
	int result;
	int len;
	char string[M];
	idr=idH;
	while(idr->next!=NULL)
	{
		idr=idr->next;
		replace(infixexp,idr->name,itoa(idr->data,string,10));
	}
	replace(infixexp,"!=","!");
	replace(infixexp,"==","=");
	replace(infixexp,"<=","@");
	replace(infixexp,">=","$");
	len=strlen(infixexp);
	infixexp[len]='#';
    infixexp[len+1]='\0';
//	printf("==>%s\n",infixexp);
	result=(int)Infix_exp_value(infixexp);
	return result;
}
