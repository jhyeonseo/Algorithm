#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

LARGE_INTEGER freq, start, stop;
double diff;


int main()
{
	QueryPerformanceFrequency(&freq);       // computer frequency
	QueryPerformanceCounter(&start);        // starting point

	
	/////////////////////////
	int a = 22442;
	int b = 33254;
	int c = 0;

	for (int i = 0; i < 1000000000; i++)
	{
		while (a)
		{
			if (a % 2 != 0)
				c += b;

			a = a >>1;    // dividing 2
			b = b <<1;    // multipy 2
		}
	}
	printf("%d\n", c);
	////////////////////////


	QueryPerformanceCounter(&stop);        // stopping point
	diff = (double)(stop.QuadPart - start.QuadPart) / freq.QuadPart;
	printf("%f", diff);


	return 0;
}