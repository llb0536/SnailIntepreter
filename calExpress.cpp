#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystr.h"
#include "snail.h"
//操作数栈的定义及操作
#define max 1000
extern id idH,idp,idr;

typedef struct
{
	double data[max];
	int top;
}SeqStack,*PseqStack;
//初始化一个空栈
PseqStack Init_Stack(void)
{
	PseqStack s;
	s=(PseqStack)malloc(sizeof(SeqStack));
	if(s)
		s->top=-1;
	return s;
}
//判断栈是否为空
int Empty_Stack(PseqStack s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
//元素入栈
int Push_Stack(PseqStack s,double x)
{
	if(s->top==max-1)
	{
		printf("栈满，不能入栈!\n");
		return 0;          //栈满不能入栈
	}
	else
	{
		s->top++;
		s->data[s->top]=x;	
		return 1;
	}
}
//元素出栈
int Pop_Stack(PseqStack s,double *x)
{
	if(Empty_Stack(s))
	{
		//printf("栈空，无元素出栈!\n");
		return 0;
	}
	else
	{
		*x=s->data[s->top];
		s->top--;
		return 1;
	}
}
//取栈顶元素
int Get_Stack(PseqStack s,double *x)
{
	if(Empty_Stack(s))
	{
		printf("栈空!\n");
		return 0;
	}
	else
	{
		*x=s->data[s->top];
		return 1;
	}
}
//销毁栈
void Destory_Stack(PseqStack *s)
{
	if(*s)
		free(*s);
	*s=NULL;
}
#define M 1000
//操作符栈的定义及操作
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
//判断栈空
int Empty_stack(pseqstack s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
//入栈
int Push_stack(pseqstack s,char x)
{
	if(s->top==M-1)
	{
		printf("栈满!");
		exit(0);
	}
	else
	{
		s->top++;
		s->data[s->top]=x;
		return 1;
	}
}
//元素出栈
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
//获取栈顶元素
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
//销毁栈
void Destory_stack(pseqstack *s)
{
	if(*s)
		free(*s);
	*s=NULL;
	return ;
}
//判断读入的字符是否是数字
int IsNum(char c)
{
	if(c>='0'&&c<='9')
		return 1;
	else
		return 0;
}             
//返回运算符优先级
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
//对中缀表达式直接求值
double Infix_exp_value(char *infixexp)
{
	PseqStack s1;         //操作数
	pseqstack s2;         //操作符
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
	while((Gettop_stack(s2,&ch),ch)!='#'||w!='#')       //取栈顶元素，判断是否是数字
	{
		if(IsNum(w))                                     //对数字处理
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
		else                                  //对运算符的处理
		{
			if(Priority((Gettop_stack(s2,&ch),ch))>=Priority(w)&&(Gettop_stack(s2,&ch),ch)!='(') //当前运算符优先级小于栈顶
				                                                                                //优先级而且运算符不是"("时从数栈中取数，
																								//从运算符栈中取运算符进行运算，结果入操作数栈
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
			else if((Gettop_stack(s2,&ch),ch)=='('&&w==')')    //当前运算符是")"而且栈顶元素是"("时候去括号
			{
				Pop_stack(s2,&topelement);
				infixexp++;
				w=*infixexp;
			}
			else                                                //当前运算符的优先级大于栈顶元素优先级或者是"("时候直接入操作符栈 
			{
				Push_stack(s2,w);
				infixexp++;
				w=*infixexp;
			}
		}
	}
	Get_Stack(s1,&result);
	Destory_stack(&s2);                //销毁两个栈 
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
