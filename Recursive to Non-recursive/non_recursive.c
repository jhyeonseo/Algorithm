//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


// for stack algorithm
#define Max 10000
int stack[Max];
int top=-1;
int push(int n);
int pop();


void hanoi(unsigned int n, char a, char b, char c);   // height, start,  waypoint, destination


int main()
{

	hanoi(5, 'a', 'b', 'c');







	return 0;
}
int push(int n)
{
	if (top >= Max - 1)
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
void hanoi(unsigned int n, char a, char b, char c)
{
	top = -1;
	int done = 0;
	int i = 0;

	while (!done)
	{
		while (n != 1)  // n==1 : terminal condition 
		{
			push(n);
			push(a);
			push(b);
			push(c);

			push(c);
			c = b;
			b = pop();
			n--;
			//printf("%c ", a);
			//printf("%c ", b);
			//printf("%c \n", c);
		}
		i++;
		printf("move block 1 %c -> %c (moving %d)\n", a, c,i );

		if (top >= 0)
		{
			c = pop();
			b = pop();
			a = pop();
			n = pop();
			i++;
			printf("move block %d %c -> %c (moving %d)\n", n, a, c,i);
			push(a);
			a = b;
			b = pop();

			n--;
		}
		else
			done = 1;

	}


}