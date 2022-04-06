#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define Max 10000
int stack[Max];
int top = -1;
int push(int n);
int pop();
// stack

typedef struct _dnode
{
	struct _dnode* prev;
	struct _dnode* next;
	int key;
}dnode;
dnode* head;
dnode* tail;
void init_queue();
void end_queue();
int queue_empty();
int put(int k);
int get();
// queue

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
// graph representation

int check[MAX_NODE];
void DFS_recur_matrix_starter(int a[][MAX_NODE], int v);  
void DFS_recur_matrix(int a[][MAX_NODE], int v,int i);
void DFS_nonrecur_matrix(int a[][MAX_NODE], int v);
void DFS_recur_list_starter(node* a[], int v);
void DFS_recur_list(node* a[], int v, int i);
void DFS_nonrecur_list(node* a[], int v);
// DFS search
void BFS_adjmatrix(int a[][MAX_NODE],int v);
void BFS_adjlist(node* a[],int v);
void count_matrix_components(int a[][MAX_NODE], int v);
void count_list_components(node* a[], int v);
// BFS search
int son_of_root;
int order;
void AP_recur_starter(node* a[], int v);
int AP_recur(node* a[], int i);
// Spanning tree - articulation point
int main()
{
	int v, e;
	
	input_adjmatrix(GM, &v, &e);
	print_adjmatrix(GM, v);
	printf("< Recursive >\n");
	DFS_recur_matrix_starter(GM, v);
	printf("< NonRecursive >\n");
	DFS_nonrecur_matrix(GM, v);
	printf("< BFS Search >\n");
	BFS_adjmatrix(GM, v);
	printf("< Graph # count >\n");
	count_matrix_components(GM, v);
	
	input_adjlist(GL, &v, &e);
	print_adjlist(GL, v);
	printf("< Recursive >\n");
	DFS_recur_list_starter(GL, v);
	printf("< NonRecursive >\n");
	DFS_nonrecur_list(GL, v);
	printf("< BFS Search >\n");
	BFS_adjlist(GL, v);
	printf("< Graph # count >\n");
	count_list_components(GL, v);
	printf("< Articulation point >\n");
	AP_recur_starter(GL, v);

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
// stack
int put(int k)
{
	dnode* t = malloc(sizeof(dnode));
	if (t == NULL)
	{
		printf("Out of memory !\n");
		return -1;
	}
	t->key = k;
	
	tail->prev->next = t;
	t->prev = tail->prev;
	tail->prev = t;
	t->next = tail;

	return k;
};
int get()
{
	int k;
	dnode* t = head->next;
	if (t == tail)
	{
		printf("Queue underflow (Que is empty)!\n");
		return -1;
	}
	k = t->key;
	head->next = t->next;
	t->next->prev = head;

	free(t);
	return k;
};
void init_queue()
{
	head = (dnode*)calloc(1, sizeof(dnode));
	tail = (dnode*)calloc(1, sizeof(dnode));

	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}
void end_queue()
{
	dnode* t = head;

	if (head->next == tail)
	{
		free(head);
		free(tail);
	}
	else
	{
		do
		{
			dnode* k = t;
			t = k->next;
			free(k);
		} while (t != tail);
		free(t);
	}
	
}
int queue_empty()
{
	if (head->next == tail)
		return 1;
	else
		return 0;
};
// queue
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
// graph representation
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
		if ((a[i][j] == 1) && (check[j] == 0))
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
					if ((a[i][k] == 1) && (check[k] == 0))
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
// DFS search
void BFS_adjmatrix(int a[][MAX_NODE], int v)
{
	init_queue();
	for (int i = 0; i < v; i++) { check[i] = 0; }
	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			put(i);
			check[i] = 1;
			while (!queue_empty())
			{
				i = get();
				printf("Visit %c\n", int_to_name(i));
				for (int j = 0; j < v; j++)
				{
					if ((a[i][j] == 1) && (check[j] == 0))
					{
						put(j);
						check[j] = 1;
					}
				}
			}
		}
	}
	end_queue();
};
void BFS_adjlist(node* a[], int v)
{
	init_queue();
	for (int i = 0; i < v; i++) { check[i] = 0; }
	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			put(i);
			check[i] = 1;
			while (!queue_empty())
			{
				i = get();
				printf("Visit %c\n", int_to_name(i));
				for (node* t = a[i]; t != NULL; t = t->next)
				{
					if (check[t->vertex] == 0)
					{
						put(t->vertex);
						check[t->vertex] = 1;
					}
				}
			}
		}
	}

	end_queue();
};
void count_matrix_components(int a[][MAX_NODE], int v)
{
	init_queue();
	int cnt = 0;

	for (int i = 0; i < v; i++) { check[i] = 0; }
	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			put(i);
			check[i]=1;
			cnt++;
			while (!queue_empty())
			{
				i = get();
				for (int j = 0; j < v; j++)
				{
					if ((a[i][j] == 1)&& (check[j] == 0))
					{
						put(j);
						check[j] = 1;
					}
				}
			}
		}
	}

	printf("# of CC: %d\n", cnt);
	end_queue();
}
void count_list_components(node* a[], int v)
{
	init_queue();
	int cnt = 0;

	for (int i = 0; i < v; i++) { check[i] = 0; }
	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			put(i);
			check[i] = 1;
			cnt++;

			while (!queue_empty())
			{
				i = get();
				for (node* t = a[i]; t != NULL; t = t->next)
				{
					if (check[t->vertex] == 0)
					{
						put(t->vertex);
						check[t->vertex] = 1;
					}
				}
			}
		}
	}

	printf("# of CC: %d\n", cnt);
	end_queue();
}
// BFS search
void AP_recur_starter(node* a[], int v)
{
	order = son_of_root = 0;
	for (int i = 0; i < v; i++) { check[i] = 0; }

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			AP_recur(a, i);

			if (son_of_root > 1)
				printf("%c has %d son <articulation point!>\n", int_to_name(i), son_of_root);
			else
				printf("Root node %c has %d son\n", int_to_name(i), son_of_root);
		}
		son_of_root = 0;
		order = 0;
	}
	

}
int AP_recur(node* a[], int i)
{
	int min, m;
	int flag_root;
	if (order == 0)
		flag_root = 1;
	else
		flag_root = 0;

	check[i] = min = ++order;

	for (node* t = a[i]; t != NULL; t = t->next)
	{
		if ((flag_root==1) && (check[t->vertex] == 0))
			son_of_root++;

		if (check[t->vertex] == 0)
		{
			m = AP_recur(a, t->vertex);
			if (min > m)
				min = m;

			if (!flag_root)
			{
				if (check[i] <= m)
					printf("%c(order=%d) : %d <articulation point!>\n", int_to_name(i), check[i], m);
				else
					printf("%c(order=%d) : %d \n", int_to_name(i), check[i], m);
			}
		}
		else if (check[t->vertex] < min)
			min = check[t->vertex];
	}

	return min;
};
// Spanning tree - articulation point