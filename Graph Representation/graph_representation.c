#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100
int GM[MAX_NODE][MAX_NODE];
int GL[MAX_NODE];
int name_to_int(char c) { return c - 'A'; };
char int_to_name(int i) { return i + 'A'; };

void input_adjmatrix(int a[][MAX_NODE], int* v, int* e);
void print_adjmatrix(int a[][MAX_NODE], int v);

typedef struct _node
{
	int vertex;
	struct _node *next;
}node;
void input_adjlist(int* a[], int* v, int* e);
void print_adjlist(int* a[], int v);
int main()
{
	int v, e;
	input_adjmatrix(GM, &v, &e);
	print_adjmatrix(GM, v);
	input_adjlist(GL, &v, &e);
	print_adjlist(GL, v);


}
void input_adjmatrix(int a[][MAX_NODE], int* v, int* e)
{
	printf("\nInput number of node & edge\n");
	scanf("%d %d", v, e);
	
	for (int i = 0; i < *v; i++)
	{
		for (int j = 0; j < *v; j++)
			a[i][j] = 0;
	}
	for (int i = 0; i < *v; i++)
		a[i][i] = 1;

	char vertex[3];
	for (int i = 0; i < *e; i++)
	{
		printf("\nInput two node consist of edge : ");
		scanf("%s", vertex);

		int v1 = name_to_int(vertex[0]);
		int v2 = name_to_int(vertex[1]);
		a[v1][v2] = 1;
		a[v2][v1] = 1;
	}


}
void print_adjmatrix(int a[][MAX_NODE], int v)
{
	printf("  ");
	for (int i = 0; i < v; i++)
		printf("%c ", int_to_name(i));
	printf("\n");

	for (int i = 0; i < v; i++)
	{
		printf("%c ", int_to_name(i));

		for (int j = 0; j < v; j++)
			printf("%d ", a[i][j]);

		printf("\n");
	}


}
void input_adjlist(int* a[], int* v, int* e)
{
	printf("\nInput number of node & edge\n");
	scanf("%d %d", v, e);
	for (int i = 0; i < *v; i++)
		a[i] = NULL;
	
	char vertex[3];
	for (int i = 0; i < *e; i++)
	{
		printf("\nInput two node consist of edge : ");
		scanf("%s", vertex);
		
		int v0 = name_to_int(vertex[0]);
		int v1 = name_to_int(vertex[1]);

		node* t = (node*)malloc(sizeof(node));
		t->vertex = name_to_int(vertex[0]);
		t->next = a[v1];
		a[v1] = t;

		t = (node*)malloc(sizeof(node));
		t->vertex = name_to_int(vertex[1]);
		t->next = a[v0];
		a[v0] = t;
	}
}
void print_adjlist(int* a[], int v)
{
	for (int i = 0;i < v; i++)
	{
		printf("%c", int_to_name(i));
		node* temp = a[i];
		while (1)
		{
			if (temp != NULL)
			{
				printf("->%c", int_to_name(temp->vertex));
				temp = temp->next;
			}
			else
				break;
		}
		printf("\n");

	}
}