#include<stdio.h>
#include<stdlib.h>

int canvas[7][7]=
{
0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 0, 0, 0,
0, 0, 0, 1, 0, 0, 0,
0 ,1, 1, 1, 1, 0, 0,
0, 0, 0, 0, 0, 1, 0,
0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0 };

void recur_fill(int x, int y);


int main()
{
	printf("< Before >\n");
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
			printf("%d ", canvas[i][j]);
		printf("\n");
	}


	recur_fill(3, 1);
	
	printf("< After >\n");
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
			printf("%d ", canvas[i][j]);
		printf("\n");
	}


}
void recur_fill(int x, int y)
{
	if (canvas[y][x] !=1 || y < 0 || y > 6 || x < 0 || x>6)
		return;


	canvas[y][x] = 2;

	recur_fill(x + 1, y);
	recur_fill(x - 1, y);
	recur_fill(x, y - 1);
	recur_fill(x, y + 1);
	recur_fill(x + 1, y + 1);
	recur_fill(x + 1, y - 1);
	recur_fill(x - 1, y - 1);
	recur_fill(x - 1, y + 1);


};
