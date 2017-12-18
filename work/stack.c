#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR 0
#define OK 1

typedef struct {
	int *base;
	int *top,biaodashi;
	int stacksize;
}SqStack1;

typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStack2;

void IntInitStack(SqStack1 *S)
{
	S->base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if (!S->base)
		exit(ERROR);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

void CharInitStack(SqStack2 *S)
{
	S->base = (char *)malloc(STACK_INIT_SIZE*sizeof(char));
	if (!S->base)
	{
		exit(ERROR);
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

int IntGetTop(SqStack1 *S)
{
	int e;
	if ((*S).top == (*S).base)
		return 0;
	e = *((*S).top - 1);
	return e;
}

char CharGetTop(SqStack2 *S)
{
	char e;
	if ((*S).top == (*S).base)
		return 0;
	e = *((*S).top - 1);
	return e;
}

int IntPush(SqStack1 *S, int e)
{
	*(*S).top++=e;
	return OK;
}

int CharPush(SqStack2 *S, char e)
{
	*(*S).top++ = e;
	return OK;
}

int IntPop(SqStack1 *S)
{
	int e;
	if ((*S).top == (*S).base)
		return 0;
	e = *(--(*S).top);
	return e;
}

char CharPop(SqStack2 *S)
{
	char e;
	if ((*S).top == (*S).base)
		return 0;
	e = *(--(*S).top);
	return e;
}

char Precede(char a, char b)
{
	int i, j;
	char Table[8][8] = {
		' ','+','-','*','/','(',')','#',
		'+','>','>','<','<','<','>','>',
		'-','>','>','<','<','<','>','>',
		'*','>','>','>','>','<','>','>',
		'/','>','>','>','>','<','>','>',
		'(','<','<','<','<','<','=',' ',
		')','>','>','>','>','>','>','>',
		'#','<','<','<','<','<','<','<'
	};
	for ( i = 0; i < 8; i++)
	{
		if (Table[0][i]==a)
		{
			break;
		}
	}
	for ( j = 0; j < 8; j++)
	{
		if (Table[j][0]==b)
		{
			break;
		}
	}
	return Table[j][i];
}

int Operate(int a, char theta, int b)
{
	int c;
	if (theta == '+')
		c = a + b;
	else if (theta == '-')
		c = a - b;
	else if (theta == '*')
		c = a*b;
	else
		c = a / b;
	return c;
}

int In(char c)
{
	if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/' || c == ')' || c == '#' || c == '^')
		return 1;
	else
		return 0;
}

int result(SqStack1 *OPND, SqStack2 *OPTR)
{
	char a = 0;
	char theta;
	int b, c, number=0;
	IntInitStack(OPND);
	CharInitStack(OPTR);
	CharPush(OPTR, '#');
	a = getchar();
	while (a != '#' || CharGetTop(OPTR) != '#')
	{
		printf("输入字符: %c \n", a);
		if (!In(a))
		{
			number = 0;
			while (!In(a))
			{
				number = number * 10 + (a - 48);
				a = getchar();
			}
			IntPush(OPND, number);
			printf("主要操作:  Push(OPND,%d)\n", number);
		}
		else
		{
			switch (Precede(a, CharGetTop(OPTR)))
			{
			case '<':
				CharPush(OPTR, a);
				printf("主要操作:  Push(OPTR,%c)\n",a);
				a = getchar();
				break;
			case '=':
				CharPop(OPTR);
				printf("主要操作:   Pop(OPTR,%c)\n", a);
				a = getchar();
				break;
			case '>':
				theta = CharPop(OPTR);
				c = IntPop(OPND);
				b = IntPop(OPND);
				IntPush(OPND, Operate(b, theta, c));
				printf("主要操作:  Operate(%d,%c,%d)\n", b, theta, c);
				break;
			}
		}
	}
	printf("结果:  %d.\n", IntGetTop(OPND));
	return OK;
}

int main(void)
{
	char a;
	SqStack1 s1, *OPND;
	SqStack2 s2, *OPTR;
	OPND = &s1;
	OPTR = &s2;
	printf("请输入算数表达式并以'#'结尾\n");
	printf("算数表达式:   ");
	result(OPND, OPTR);
	a=getchar();
	return 0;
}
