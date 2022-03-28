#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

unsigned long long fact(unsigned int n);
unsigned long long fibonacci(unsigned int n);
void hanoi(unsigned int n,char a, char b, char c);   // height, start, destination, waypoint
int main()
{

	int menu;
	printf("1 = factorial\n2 = fibonacci\n3 = hanoi tower\n");
	scanf("%d", &menu);

	if (menu == 1)
	{
		unsigned int n;
		printf("find factorial of (maximum=20) : ");
		scanf("%d", &n);
		printf("factorial of %u = %llu\n", n, fact(n));
	}
	else if (menu == 2)
	{
		unsigned int n;
		printf("find fibonacci of (maximum=94, but over 45 is extremly slow!) : ");
		scanf("%d", &n);
		printf("fibonacci of %u = %llu\n", n, fibonacci(n));
	}
	else if (menu == 3)
	{
		unsigned int n; 
		printf("hanoi tower height (maximum=64, but over 45 is extremly slow!) : ");
		scanf("%d", &n);

		hanoi(n, 'a', 'c', 'b');
	}
	









	return 0;
}
unsigned long long fact(unsigned int n)
{
	if (n == 0)
		return 1;

	else
	{
		return fact(n - 1) * n;
	}


}
unsigned long long fibonacci(unsigned int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}
void hanoi(unsigned int n,char a,char b, char c)
{
	static int i = 0;
	if (n == 1)
	{
		i++;
		printf("move block 1 %c -> %c (moving #%d)\n", a, b, i);
		return;
	}
	else
	{
		hanoi(n - 1, a, c, b);
		i++;
		printf("move block %d %c -> %c (moving #%d)\n", n, a, b,i);
		hanoi(n - 1, c, b, a);
		return;
	}
}