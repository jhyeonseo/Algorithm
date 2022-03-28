#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

LARGE_INTEGER freq, start, stop;
double diff;

int GCD_minus(int a, int b);
int GCD_mod(int a, int b);
int GCD_recursion(int a, int b);


int main()
{
	QueryPerformanceFrequency(&freq);       // computer frequency
	QueryPerformanceCounter(&start);        // starting point


	/////////////////////////

	for (int i = 0; i < 10000000; i++)
	{
		GCD_recursion(24666, 24324);
	}
	printf("%d\n", GCD_recursion(24666, 24324));
	////////////////////////


	QueryPerformanceCounter(&stop);        // stopping point
	diff = (double)(stop.QuadPart - start.QuadPart) / freq.QuadPart;
	printf("%f", diff);


	return 0;
}

int GCD_minus(int a, int b)
{
	while (a != b)
	{
		if (a > b)            // a-b
			a = a - b;
		else                  // a b 교체
		{
			int temp = b;
			b = a;
			a = temp;
		}
	}
	return a;  // 최대공약수 리턴
}
int GCD_mod(int a, int b)
{
	while (b!=0)
	{
		if (a >= b)
			a = a % b;
		else
		{
			int temp = b;
			b = a;
			a = temp;
		}
	}

	return a;  // 최대공약수 리턴
}
int GCD_recursion(int a, int b)
{
	if (b == 0)
		return a;
	else
		GCD_recursion(b, a % b);
}