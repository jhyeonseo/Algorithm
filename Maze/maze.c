#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 19
#define MOUSE 2
#define UP 1
#define RIGHT 2
#define DOWN 4
#define LEFT 8
int* rec;
int sx = MAZE_SIZE - 1;
int sy = MAZE_SIZE - 2;
int maze[MAZE_SIZE][MAZE_SIZE] =
{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1},
{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };


void forward(int* x, int* y, int dir);
int still_in_maze(int x, int y);
int wall_ahead(int m[][MAZE_SIZE], int x, int y, int dir);
void right(int* dir);
void left(int* dir);
void right_hand_on_wall(int m[][MAZE_SIZE], int x, int y, int dir);
void gotoxy(int x, int y);
void record(int x, int y);
void delay(int n);
void shortest_path(int *rec);
int del_path(int i, int j);

int main()
{
	rec = (int*)calloc(MAZE_SIZE * MAZE_SIZE, sizeof(int));
	int dir = LEFT;

	int x, y;
	for (y = 0; y < MAZE_SIZE; y++)
	{
		if (y == 0) gotoxy(0, 1);
		for (x = 0; x < MAZE_SIZE; x++)
		{
			if (x == 0) printf(" ");
			if (maze[y][x] == 1) printf("% %");
			else printf(" ");
		}
		printf("\n");
	}

	right_hand_on_wall(maze, sx, sy, dir);
	shortest_path(rec);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return 0;
}
void forward(int* x, int* y, int dir)
{
	gotoxy(*x + 1, *y + 1);
	_putch(' ');
	*x = (dir == LEFT) ? --(*x) : (dir == RIGHT) ? ++(*x) : *x;
	*y = (dir == UP) ? --(*y) : (dir == DOWN) ? ++(*y) : *y;
	record(*x, *y);
	gotoxy(*x + 1, *y + 1);
	_putch(MOUSE);
}
int still_in_maze(int x, int y)
{
	if (x > 0 && x < MAZE_SIZE - 1 && y > 0 && y < MAZE_SIZE - 1)
		return 1;
	else
		return 0;
}
int wall_ahead(int m[][MAZE_SIZE], int x, int y, int dir)
{
	x = (dir == LEFT) ? --x : (dir == RIGHT) ? ++x : x;
	y = (dir == UP) ? --y : (dir == DOWN) ? ++y : y;
	return m[y][x];
}
void right(int* dir)
{
	*dir <<= 1;
	*dir = (*dir > LEFT) ? UP : *dir;
}
void left(int* dir)
{
	*dir >>= 1;
	*dir = (*dir == 0) ? LEFT : *dir;
}
void right_hand_on_wall(int m[][MAZE_SIZE], int x, int y, int dir)
{
	gotoxy(x + 1, y + 1);
	_putch(MOUSE);
	forward(&x, &y, dir);
	while (still_in_maze(x, y))
	{
		delay(100); // for display
		right(&dir);
		while (wall_ahead(m, x, y, dir))
			left(&dir);

		forward(&x, &y, dir);

	}
	record(-1, -1);
}
void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void record(int x, int y)
{
	static int index = 0;
	rec[index++] = x;
	rec[index++] = y;
}
void delay(int n)
{
	for (int i = 0; i < 500000*n; i++) 
	{
	}
}
void shortest_path(int *rec)
{
	int i = 0;
	int j;
	while (rec[i] >= 0)
	{
		j = i + 2;
		while (rec[j] >= 0)
		{
			if ((rec[i] == rec[j])&&(rec[i+1]==rec[j+1]))
			{
				i = del_path(i, j);
				j = i + 2;
				break;
			}
			else
				j += 2;
		}

		i = i + 2;
	}

	i = 0;
	int x;
	int y;
	while (rec[i] >= 0)
	{
		x = rec[i++];
		y = rec[i++];
		gotoxy(x + 1, y + 1);
		_putch(MOUSE);
		delay(100);
		gotoxy(x + 1, y + 1);
		_putch(" ");
	}


}
int del_path(int i, int j)
{
	int k = i;
	while (rec[j] >= 0)
		rec[i++] = rec[j++];
	rec[i] = -1;
	return k;
}
