#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"stack.h"
#include"node.h"
#include"heap.h"

int name_to_int(char c) { return c - 'A'; };
char int_to_name(int i) { return i + 'A'; };
// int <-> name
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
void input_adjlist(int* a[], int* v, int* e, FILE* fp)
{
	fscanf(fp, "%d %d", v, e);
	for (int i = 0; i < *v; i++)a[i] = NULL;

	char vertex[3];
	int weight;
	for (int i = 0; i < *e; i++)
	{
		fscanf(fp, "%s %d", vertex, &weight);

		node* t = malloc(sizeof(node));
		t->vertex = name_to_int(vertex[1]);
		t->weight = weight;
		t->next = a[name_to_int(vertex[0])];
		a[name_to_int(vertex[0])] = t;

		t = malloc(sizeof(node));
		t->vertex = name_to_int(vertex[0]);
		t->weight = weight;
		t->next = a[name_to_int(vertex[1])];
		a[name_to_int(vertex[1])] = t;
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
				printf(" ->%c:%d", int_to_name(temp->vertex),(temp->weight));
				temp = temp->next;
			}
			else
				break;
		}
		printf("\n");

	}
}
void print_tree(int v)
{
	printf("son    ");
	for (int i = 0; i < v; i++)
		printf("%c ", int_to_name(i));
	printf("\nparent ");
	for (int i = 0; i < v; i++)
		if (parent[i] != -1)
			printf("%c ", int_to_name(parent[i]));
		else
			printf("X ");
	printf("\n");
}
// graph representation and view
void DFS_recur_matrix_starter(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
		check[i] = 0;

	for (int i = 0; i < v; i++)
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
			check[i] = 1;
			cnt++;
			while (!queue_empty())
			{
				i = get();
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
void PFS_adjlist(node* a[], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = -INT_MAX; // -INT_MAX = UNSEEN, -INT_MAX 제외 음수 = fringe node, 양수 = 방문
		parent[i] = -1;
	}
	init_heap();

	for (int i = 0; i < v; i++)
	{
		if (check[i] == -INT_MAX)   
		{
			pq_update(i, -INT_MAX); // ROOT 갱신

			while (heap_size != 0)
			{
				int j = extract();

				check[j] = -check[j]; // 방문 가중치로 변경

				if (check[j] == INT_MAX)
					printf("<Root %c>\n", int_to_name(j));
				else
				printf("visit %c(%d)\n", int_to_name(j), check[j]);  // visit

				for (node* t = a[j]; t != NULL; t = t->next)
				{
					if (check[t->vertex] < 0) // 아직 방문 안한 노드일때,
						if (pq_update(t->vertex, -(t->weight))) // 힙, 가중치 갱신 후 변경사항이 있으면 부모를 갱신해줌 (UNSEEN노드면 첫 갱신후 첫 부모 설정) 
							parent[t->vertex] = j;
				}
			}

		}

	}

}
int pq_update(int v, int w)
{
	if (check[v] == -INT_MAX)  // 첫 갱신일때 -> check 설정, 힙에 새로 삽입
	{
		check[v] = w;
		insert(v);
		return 1;
	}
	else if (check[v] < w)  // 첫 갱신은 아니나 가중치 업데이트가 필요할 때 -> check 설정, 힙 재정렬
	{
		check[v] = w;
		adjust_heap(v);
		return 1;
	}
	else            // 첫 갱신도 아니고 가중치 업데이트도 필요 없을때
		return 0;
}
// PFS search
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
		if ((flag_root == 1) && (check[t->vertex] == 0))
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