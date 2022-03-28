//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


// for stack algorithm
#define Max 10000
int stack[Max];
int top=-1;
int push(int n);
int pop();

// for canvas
#define canvas_n 15
#define canvas_m 15
int canvas[canvas_n][canvas_m] = { 0, };

// non-recursive functions
void hanoi(unsigned int n, char a, char b, char c);   // height, start,  waypoint, destination
void fill(int x, int y); // x = y 좌표, y = x 좌표
void print_canvas(int x, int y);   // 0 = blank, 1 = O (wall) , 2 = X (painting), (x,y) = S
void canvas_border(int x, int y, int option);  // 랜덤으로 벽 만들기, option=0 : 시드자리 비우기, option=1 : 시드자리 벽으로 채우기

int main()
{
	int seed_x = 4;
	int seed_y = 3;

	//hanoi(5, 'a', 'b', 'c');
	canvas_border(seed_y, seed_x, 0);
	fill(seed_y, seed_x);
	print_canvas(seed_y, seed_x);





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
void fill(int x, int y) 
{
	top = -1;
	push(x);
	push(y);
	while (top >= 0)
	{
		y = pop();
		x = pop();
		
		if (!((canvas[x][y] > 0) || x<0 || x>canvas_n - 1 || y<0 || y>canvas_m - 1))
		{
			canvas[x][y] = 2;
			push(x - 1);
			push(y);
			push(x + 1);
			push(y);
			push(x);
			push(y - 1);
			push(x);
			push(y + 1);
		}
	}

};
void print_canvas(int x, int y)
{

	for (int i = 0; i < canvas_n; i++)
	{
		for (int j = 0; j < canvas_m; j++)
		{
			if ((i == x) && (j == y))
			{
				printf("S ");
				continue;
			}

			if (canvas[i][j] == 1)
				printf("O ");
			else if (canvas[i][j] == 2)
				printf("X ");
			else if (canvas[i][j] == 0)
				printf("  ");

		}
		printf("\n");
	}

	printf("\n");
}
void canvas_border(int x, int y, int option)
{
	for (int i = 0; i < canvas_n; i++)
	{
		for (int j = 0; j < canvas_m; j++)
		{
			canvas[i][j] = rand() % 2;
		}
	}
	if (option == 0)
		canvas[x][y] = 0;
	else
		canvas[x][y] = option;
}