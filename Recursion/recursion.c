#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

unsigned long long fact(unsigned int n);
unsigned long long fibonacci(unsigned int n);
void hanoi(unsigned int n,char a, char b, char c,unsigned long long last);   // height, start, destination, waypoint, 2^n-1(total moving #)


#define canvas_n 15
#define canvas_m 15
int canvas[canvas_n][canvas_m] = { 0, };

void recur_fill(int x, int y);   // 벽 제외 채우기 (대각선 미포함)
void recur_fill_2(int x, int y);  // 벽 채우기 (대각선 포함)
void print_canvas(int x, int y);   // 0 = blank, 1 = O (wall) , 2 = X (painting), (x,y) = S
void canvas_eraser();  // canvas 0으로 초기화
void canvas_border(int x, int y, int option);  // 랜덤으로 벽 만들기, option=0 : 시드자리 비우기, option=1 : 시드자리 벽으로 채우기
void recursive_line(int x1, int y1, int x2, int y2); // (x1,y1)부터 (x2,y2)까지 직선 그리기
//canvas


int main()
{
	srand(time(NULL));
	int menu;

	while (1)
	{
		printf("\n1 = factorial\n2 = fibonacci\n3 = hanoi tower\n4 = canvas\n5 = quit\n");
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
			unsigned long long last = (unsigned long long)pow(2, (double)n) - 1;
			hanoi(n, 'a', 'c', 'b', last);
			printf("last=%d", last);
		}
		else if (menu == 4)
		{
			int menu_canvas;

			while (1)
			{
				canvas_eraser();
				printf("\n1 = fill blank\n2 = fill wall\n3 = make line\n4 = quit\n");
				scanf("%d", &menu_canvas);
				if (menu_canvas == 1)
				{
					printf("seed_x(0~14) = ");
					int seed_x;
					scanf("%d", &seed_x);
					int seed_y;
					printf("seed_y(0~14) = ");
					scanf("%d", &seed_y);

					canvas_border(seed_y, seed_x, 0);
					printf("< Before >\n");
					print_canvas(seed_y, seed_x);
					recur_fill(seed_y, seed_x);
					printf("< After >\n");
					print_canvas(seed_y, seed_x);
					printf("Border = O\nFilled = X\nStart = S\nEmpty = blank\n\n");
				}
				else if (menu_canvas == 2)
				{
					printf("seed_x(0~14) = ");
					int seed_x;
					scanf("%d", &seed_x);
					int seed_y;
					printf("seed_y(0~14) = ");
					scanf("%d", &seed_y);

					canvas_border(seed_y, seed_x, 1);
					printf("< Before >\n");
					print_canvas(seed_y, seed_x);
					recur_fill_2(seed_y, seed_x);
					printf("< After >\n");
					print_canvas(seed_y, seed_x);
					printf("Border = O\nFilled = X\nStart = S\nEmpty = blank\n\n");
				}
				else if (menu_canvas == 3)
				{
					printf("x1 (0~15,y1=x1) = ");
					int x1;
					scanf("%d", &x1);
					int x2;
					printf("x2 (0~15,y2=x2) = ");
					scanf("%d", &x2);

					if (x2 < x1)
						recursive_line(x2, x2, x1, x1);
					else if (x1 < x2)
						recursive_line(x1, x1, x2, x2);
		
					print_canvas(-1, -1);
				}
				else if (menu_canvas == 4)
					break;
			}
		}
		else if (menu == 5)
			break;
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
void hanoi(unsigned int n, char a, char b, char c,unsigned long long last)
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
		hanoi(n - 1, a, c, b, 0);
		i++;
		printf("move block %d %c -> %c (moving #%d)\n", n, a, b, i);
		hanoi(n - 1, c, b, a, 0);
		if (last == i)
			i = 0;
		return;
	}
}
void recur_fill(int x, int y)
{
	if ((canvas[x][y] > 0) || x<0 || x>canvas_n - 1 || y<0 || y>canvas_m - 1)
		return;

	canvas[x][y] = 2;

	recur_fill(x + 1, y);
	recur_fill(x, y - 1);
	recur_fill(x, y + 1);
	recur_fill(x - 1, y);

}
void recur_fill_2(int x, int y)
{
	if (canvas[x][y] != 1 || x<0 || x>canvas_n - 1 || y<0 || y>canvas_m - 1)
		return;

	canvas[x][y] = 2;

	recur_fill_2(x + 1, y);
	recur_fill_2(x - 1, y);
	recur_fill_2(x, y - 1);
	recur_fill_2(x, y + 1);
	recur_fill_2(x + 1, y + 1);
	recur_fill_2(x + 1, y - 1);
	recur_fill_2(x - 1, y - 1);
	recur_fill_2(x - 1, y + 1);


}
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
void canvas_eraser()
{
	for (int i = 0; i < canvas_n; i++)
	{
		for (int j = 0; j < canvas_m; j++)
		{
			canvas[i][j] = 0;
		}
	}
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
void recursive_line(int x1, int y1, int x2, int y2)
{
	if (((x1 + 1) == x2) && ((y1 + 1) == y2))
		return;

	int middlepoint_x = (x1 + x2) / 2;
	int middlepoint_y = (y1 + y2) / 2;
	canvas[middlepoint_y][middlepoint_x] = 2;
	canvas[y1][x1] = 2;
	canvas[y2][x2] = 2;

	recursive_line(x1, y1, middlepoint_x, middlepoint_y);
	recursive_line(middlepoint_x, middlepoint_y, x2, y2);

}