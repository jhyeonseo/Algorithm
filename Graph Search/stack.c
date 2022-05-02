#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

top = -1;

int push(int n)
{
	if (top >= MAX_STACK - 1)
	{
		printf("Stack Overflow!\n");
		return -1;
	}


	stack[++top] = n;
	return n;
};
int pop()
{
	if (top < 0)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
		return stack[top--];
}