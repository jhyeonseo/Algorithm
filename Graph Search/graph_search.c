#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define Max 10000
int stack[Max];
int top = -1;
int push(int n);
int pop();

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
	struct _node* next;
}node;
void input_adjlist(int* a[], int* v, int* e);
void print_adjlist(int* a[], int v);

int check[MAX_NODE];
void DFS_recur_matrix_starter(int a[][MAX_NODE], int v);  
void DFS_recur_matrix(int a[][MAX_NODE], int v,int i);
void DFS_nonrecur_matrix(int a[][MAX_NODE], int v);
void DFS_recur_list_starter(node* a[], int v);
void DFS_recur_list(node* a[], int v, int i);
void DFS_nonrecur_list(node* a[], int v);
int main()
{
	int v, e;
	
	input_adjmatrix(GM, &v, &e);
	print_adjmatrix(GM, v);
	printf("< Recursive >\n");
	DFS_recur_matrix_starter(GM, v);
	printf("< NonRecursive >\n");
	DFS_nonrecur_matrix(GM, v);
	
	input_adjlist(GL, &v, &e);
	print_adjlist(GL, v);
	printf("< Recursive >\n");
	DFS_recur_list_starter(GL, v);
	printf("< NonRecursive >\n");
	DFS_nonrecur_list(GL, v);
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
	for (int i = 0; i < v; i++)
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
void DFS_recur_matrix_starter(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
		check[i] = 0;

	for (int i = 0;  i< v;i++)
	{
		if (check[i] == 0)
			DFS_recur_matrix(a, v, i);
	}

}
void DFS_recur_matrix(int a[][MAX_NODE], int v, int i)
{
	check[i] = 1;

	printf("Visit %c\n", int_to_name(i));
	for (int j = 0; j < v; j++)
	{
		if ((a[i][j] == 1) & (check[j] == 0))
		{
			DFS_recur_matrix(a, v, j);
		}
	}
};
void DFS_nonrecur_matrix(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
		check[i] = 0;
	top = -1;

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			push(i);
			check[i] = 1;
			while (top >= 0)
			{
				i = pop();                         
				printf("Visit %c\n", int_to_name(i));
				for (int k = 0; k < v; k++)
				{
					if ((a[i][k] == 1) & (check[k] == 0))
					{
						push(k);
						check[k] = 1;
					}
				}
			}
		}
	}





}
void DFS_recur_list_starter(node* a[], int v)
{
	for (int i = 0; i < v; i++)
		check[i] = 0;

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
			DFS_recur_list(a, v, i);
	}
};
void DFS_recur_list(node* a[], int v, int i)
{
	printf("Visit %c\n", int_to_name(i));
	check[i] = 1;

	for (node* j = a[i]; j != NULL; j = j->next)
	{
		if (check[j->vertex] == 0)
			DFS_recur_list(a, v, j->vertex);
	}

};
void DFS_nonrecur_list(node* a[], int v)
{
	for (int i = 0; i < v; i++)
		check[i] = 0;

	top = -1;

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			push(i);
			check[i] = 1;
			while (top >= 0)
			{
				i = pop();
				printf("Visit %c\n", int_to_name(i));
				for (node* k = a[i]; k != NULL; k = k->next)
				{
					if (check[k->vertex] == 0)
					{
						push(k->vertex);
						check[k->vertex] = 1;
					}
				}
			}
		}
	}
};