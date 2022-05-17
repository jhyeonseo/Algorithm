#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

// graph representation and view
void input_adjmatrix(int a[][MAX_NODE], int* v, int* e, FILE *fp)
{
	fscanf(fp, "%d %d", v, e);

	for (int i = 0; i < *v; i++)
	{
		for (int j = 0; j < *v; j++)
			a[i][j] = 0;
	}

	char vertex[3];
	int weight;
	for (int i = 0; i < *e; i++)
	{
		fscanf(fp, "%s %d", vertex, &weight);

		a[name_to_int(vertex[0])][name_to_int(vertex[1])] = weight;
		a[name_to_int(vertex[1])][name_to_int(vertex[0])] = weight;
	}


}
void input_directed_adjmatrix(int a[][MAX_NODE], int* v, int* e, FILE* fp)
{
	fscanf(fp, "%d %d", v, e);

	for (int i = 0; i < *v; i++)
	{
		for (int j = 0; j < *v; j++)
			a[i][j] = 0;
	}

	char vertex[3];
	int weight;
	for (int i = 0; i < *e; i++)
	{
		fscanf(fp, "%s %d", vertex, &weight);

		a[name_to_int(vertex[0])][name_to_int(vertex[1])] = weight;
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
void input_adjlist(node* a[], int* v, int* e, FILE* fp)
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
void input_directed_adjlist(node* a[], int* v, int* e, FILE* fp)
{
	fscanf(fp, "%d %d", v, e);
	for (int i = 0; i < *v; i++)a[i] = NULL;

	char vertex[3];
	int weight;
	for (int i = 0; i < *e; i++)
	{
		fscanf(fp, "%s %d", vertex, &weight);

		node* t = (node *)malloc(sizeof(node));
		t->vertex = name_to_int(vertex[1]);
		t->weight = weight;
		t->next = a[name_to_int(vertex[0])];
		a[name_to_int(vertex[0])] = t;
	}

}
void print_adjlist(node* a[], int v)
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
void input_edge(edge edge[], int* v, int* e, FILE* fp)
{
	char vertex[3];
	fscanf(fp, "%d %d", v, e);

	int weight;
	for (int i = 0; i < *e; i++)
	{
		fscanf(fp, "%s %d", vertex, &weight);

		edge[i].v1 = name_to_int(vertex[0]);
		edge[i].v2 = name_to_int(vertex[1]);
		edge[i].weight = weight;
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
void print_score(int v)
{
	int score = 0;
	for (int i = 0; i < v; i++)
		if ((check[i] > 0) && (check[i] != INT_MAX))
			score += check[i];
		

	printf("score = %d\n", score);
}
// int <-> name
int name_to_int(char c) { return c - 'A'; };
char int_to_name(int i) { return i + 'A'; };
// DFS search
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
void DFS_adjmatrix(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = 0;
		parent[i] = -1;
	}
	top = -1;

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			push(i);
			check[i] = INT_MAX;
			parent[i] = -1;
			int start_flag = 1;

			while (top >= 0)
			{
				int j = pop();
				if (start_flag)
				{
					printf("\nSTART %c", int_to_name(j));
					start_flag = 0;
				}
				else
				printf(" -> %c", int_to_name(j));

				for (int k = 0; k < v; k++)
				{
					if ((a[j][k] != 0) && (check[k] == 0))
					{
						push(k);
						check[k] = a[j][k];
						parent[k] = j;
					}
				}
			}
		}
	}

	printf("\n");
	return;
}
void DFS_directed_adjmatrix(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = 0;
		parent[i] = -1;
	}
	top = -1;

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			check[j] = 0;
			parent[j] = -1;
		}

		push(i);
		check[i] = INT_MAX;
		parent[i] = -1;
		int start_flag = 1;

		while (top >= 0)
		{
			int j = pop();
			if (start_flag)
			{
				printf("\nSTART %c", int_to_name(j));
				start_flag = 0;
			}
			else
				printf(" -> %c", int_to_name(j));

			for (int k = 0; k < v; k++)
			{
				if ((a[j][k] != 0) && (check[k] == 0))
				{
					push(k);
					check[k] = a[j][k];
					parent[k] = j;
				}
			}
		}
	}

	printf("\n");
	return;
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
void DFS_adjlist(node* a[], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = 0;
		parent[i] = -1;
	}
	top = -1;

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			push(i);
			check[i] = INT_MAX;
			parent[i] = -1;
			int start_flag = 1;

			while (top >= 0)
			{
				int j = pop();
				if (start_flag)
				{
					printf("\nSTART %c", int_to_name(j));
					start_flag = 0;
				}
				else
					printf(" -> %c", int_to_name(j));

				for (node* k = a[j]; k != NULL; k = k->next)
				{
					if (check[k->vertex] == 0)
					{
						push(k->vertex);
						check[k->vertex] = k->weight;
						parent[k->vertex] = j;
					}
				}
			}
		}
	}

	printf("\n");
};
void DFS_directed_adjlist(node* a[], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = 0;
		parent[i] = -1;
	}
	top = -1;

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			check[j] = 0;
			parent[j] = -1;
		}

		push(i);
		check[i] = INT_MAX;
		parent[i] = -1;
		int start_flag = 1;

		while (top >= 0)
		{
			int j = pop();
			if (start_flag)
			{
				printf("\nSTART %c", int_to_name(j));
				start_flag = 0;
			}
			else
				printf(" -> %c", int_to_name(j));

			for (node* k = a[j]; k != NULL; k = k->next)
			{
				if (check[k->vertex] == 0)
				{
					push(k->vertex);
					check[k->vertex] = k->weight;
					parent[k->vertex] = j;
				}
			}
		}
		
	}

	printf("\n");
}
// BFS search
void BFS_adjmatrix(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
	{ 
		check[i] = 0;
		parent[i] = -1;
	}
	init_queue();

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			put(i);
			check[i] = INT_MAX;
			parent[i] = -1;
			int start_flag = 1;

			while (!queue_empty())
			{
				int j = get();
				if (start_flag)
				{
					printf("\nSTART %c", int_to_name(j));
					start_flag = 0;
				}
				else
					printf(" -> %c", int_to_name(j));

				for (int k = 0; k < v; k++)
				{
					if ((a[j][k] != 0) && (check[k] == 0))
					{
						put(k);
						check[k] = a[j][k];
						parent[k] = j;
					}
				}
			}
		}
	}
	end_queue();
	printf("\n");
	return;
};
void BFS_directed_adjmatrix(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = 0;
		parent[i] = -1;
	}
	init_queue();

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			check[j] = 0;
			parent[j] = -1;
		}

		put(i);
		check[i] = INT_MAX;
		parent[i] = -1;
		int start_flag = 1;

		while (!queue_empty())
		{
			int j = get();
			if (start_flag)
			{
				printf("\nSTART %c", int_to_name(j));
				start_flag = 0;
			}
			else
				printf(" -> %c", int_to_name(j));

			for (int k = 0; k < v; k++)
			{
				if ((a[j][k] != 0) && (check[k] == 0))
				{
					put(k);
					check[k] = a[j][k];
					parent[k] = j;
				}
			}
		}

		
	}
	end_queue();
	printf("\n");
	return;
}
void BFS_adjlist(node* a[], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = 0;
		parent[i] = -1;
	}
	init_queue();

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
		{
			put(i);
			check[i] = INT_MAX;
			parent[i] = -1;
			int start_flag = 1;

			while (!queue_empty())
			{
				int j = get();
				if (start_flag)
				{
					printf("\nSTART %c", int_to_name(j));
					start_flag = 0;
				}
				else
					printf(" -> %c", int_to_name(j));

				for (node* t = a[j]; t != NULL; t = t->next)
				{
					if (check[t->vertex] == 0)
					{
						put(t->vertex);
						check[t->vertex] = t->weight;
						parent[t->vertex] = j;
					}
				}
			}
		}
	}

	end_queue();
	printf("\n");
	return;
};
void BFS_directed_adjlist(node* a[], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = 0;
		parent[i] = -1;
	}
	init_queue();

	for (int i = 0; i < v; i++)
	{

		for (int j = 0; j < v; j++)
		{
			check[j] = 0;
			parent[j] = -1;
		}

		put(i);
		check[i] = INT_MAX;
		parent[i] = -1;
		int start_flag = 1;

		while (!queue_empty())
		{
			int j = get();
			if (start_flag)
			{
				printf("\nSTART %c", int_to_name(j));
				start_flag = 0;
			}
			else
				printf(" -> %c", int_to_name(j));

			for (node* t = a[j]; t != NULL; t = t->next)
			{
				if (check[t->vertex] == 0)
				{
					put(t->vertex);
					check[t->vertex] = t->weight;
					parent[t->vertex] = j;
				}
			}
		}
		
	}

	end_queue();
	printf("\n");
	return;
}
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
// PFS search
void PFS_adjlist(node* a[], int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = -INT_MAX; // -INT_MAX = UNSEEN, -INT_MAX 제외 음수 = fringe node, 양수 = 방문, 0 = ROOT 노드 
		parent[i] = -1;
	}
	init_heap();

	for (int i = 0; i < v; i++)
	{
		if (check[i] == -INT_MAX)   
		{
			heap_update(i, 0); // ROOT 갱신

			while (heap_size != 0)
			{
				int j = extract();

				check[j] = -check[j]; // 방문 가중치로 변경

				if (check[j] == 0)
					printf("<Root %c>\n", int_to_name(j));
				else
				printf("visit %c(%d)\n", int_to_name(j), check[j]);  // visit

				for (node* t = a[j]; t != NULL; t = t->next)
				{
					if (check[t->vertex] < 0) // 아직 방문 안한 노드일때,
						if (heap_update(t->vertex, -(t->weight))) // 힙, 가중치 갱신 후 변경사항이 있으면 부모를 갱신해줌 (UNSEEN노드면 첫 갱신후 첫 부모 설정) 
							parent[t->vertex] = j;
				}
			}

		}

	}

}
void kruskal(edge edge[], int v, int e)
{
	for (int i = 0; i < v; i++)
		parent[i] = -1;
	init_heap();

	for (int i = 0; i < e; i++)
	{
		check[i] = -edge[i].weight;
		insert(i);
	}
	int val;
	int n = 0;
	while (heap_size != 0)
	{
		val = extract();

		if (!find_set(edge[val].v1, edge[val].v2))
		{
			union_set(edge[val].v1, edge[val].v2);
			printf("Visit Edge between %c %c\n", int_to_name(edge[val].v1), int_to_name(edge[val].v2));
			n++;
		}

		if (n == v - 1)
			break;
	}


}
int find_set(int a, int b)
{
	int i = a;
	int j = b;

	while (parent[i] >= 0)   // a의 조상 찾기
		i = parent[i];            
	
	while (parent[j] >= 0)   // b의 조상 찾기
		j = parent[j];   

	return i == j;           // 조상이 같으면 1 리턴
}
void union_set(int a, int b)
{
	parent[b] = a;
	return;
}
// Shortest path
void shortest_adjlist(node* a[], int start, int v)
{
	for (int i = 0; i < v; i++)
	{
		check[i] = -INT_MAX; // -INT_MAX = UNSEEN, -INT_MAX 제외 음수 = fringe node, 양수 = 방문, INT_MAX = ROOT 노드 
		parent[i] = -1;
	}
	init_heap();

	
	heap_update(start, 0);   // ROOT start로 갱신

	while (heap_size != 0)
	{
		int j = extract();

		check[j] = -check[j]; // 방문 가중치로 변경

		if (check[j] == 0)
			printf("<Root %c>\n", int_to_name(j));
		else
			printf("visit %c(%d)\n", int_to_name(j), check[j]);  // visit

		for (node* t = a[j]; t != NULL; t = t->next)
		{
			if (check[t->vertex] < 0) // 아직 방문 안한 노드일때,
				if (heap_update(t->vertex, -(t->weight)-check[j])) // 힙, 가중치 갱신 후 변경사항이 있으면 부모를 갱신해줌 (UNSEEN노드면 첫 갱신후 첫 부모 설정) 
					parent[t->vertex] = j;
		}
	}

}
void dijkstra(int a[][MAX_NODE], int start, int v)
{
	for (int i = 0; i < v; i++)
		check[i] = 0;
	
	int* distance = (int*)malloc(sizeof(int) * v);
	for (int i = 0; i < v; i++)
	{
		distance[i] = a[start][i];
		parent[i] = start;        
	}

	int x = start;
	check[x] = 1;
	parent[x] = -1;
	//printf("<Root %c>\n", int_to_name(x));
	while (1)
	{
		int d = INT_MAX;
		int flag = 1;
		for (int i = 0; i < v; i++)
			if (distance[i] < d && check[i] == 0 && distance[i]!=0)
			{
				flag = 0;
				d = distance[i];
				x = i;                                      // Start 노드로부터 가장 가까운 노드로 이동 (x = 현재 노드)
			}
		if (flag)
			break;

		check[x] = 1;                                        
		//printf("visit %c(%d)\n", int_to_name(x), distance[x]);

		for(int i=0;i<v;i++)
			if (a[x][i] != 0 && check[i] == 0)
			{
				if (distance[x] + a[x][i] < distance[i] || distance[i] == 0)
				{
					distance[i] = distance[x] + a[x][i];
					parent[i] = x;                          // 현재 노드와 연결되어있는 노드들의 distance, parent 갱신
				}

			}
	}

	printf("<Distance with %c>\n", int_to_name(start));
	for (int i = 0; i < v; i++)
		printf("%c ", int_to_name(i));
	printf("\n");
	for (int i = 0; i < v; i++)
		if (distance[i] != 0)
			printf("%d ", distance[i]);
		else
			printf("X ");
	printf("\n");

	free(distance);
}
// Topological sorting
void set_topology(network net[], node* a[], int v)
{
	for (int i = 0; i < v; i++)
	{
		net[i].next = a[i];
		net[i].indegree = -1;
		net[i].outdegree = -1;
	}
	set_indegree(net, v);
	set_outdegree(net, v);
}
void set_indegree(network net[], int v)
{
	for (int i = 0; i < v; i++)
	{
		int count = 0;
		printf("Indegree of %c : ", int_to_name(i));
		for (int j = 0; j < v; j++)
			for (node* t = net[j].next; t != NULL; t = t->next)
				if (t->vertex == i)
				{
					count++;
					printf("%c ", int_to_name(j));
				}
		net[i].indegree = count;
		printf("\n");
	}

	
}
void set_outdegree(network net[], int v)
{
	for (int i = 0; i < v; i++)
	{
		int count = 0;
		printf("Outdegree of %c : ", int_to_name(i));

		for (node* t = net[i].next; t != NULL; t = t->next)
		{
			count++;
			printf("%c ", int_to_name(t->vertex));
		}
		net[i].outdegree = count;
		printf("\n");
	}

}
void DFS_topsort(network net[], int start, int v)
{
	if (net[start].indegree)
		printf("Warning! Indegree of starting node is not zero\n");

	int* temp_state = (int*)malloc(sizeof(int) * v);
	for (int i = 0; i < v; i++)
	{
		parent[i] = -1;
		temp_state[i] = net[i].indegree;
	}
	top = -1;
	push(start);
	int startflag = 1;

	while (top >= 0)
	{
		int i = pop();
		if (startflag)
		{
			printf("Start %c", int_to_name(start));
			startflag = 0;
		}
		else
			printf(" -> %c", int_to_name(i));

		for (node* t = net[i].next; t != NULL; t = t->next)
		{
			if (--net[t->vertex].indegree == 0)
			{
				push(t->vertex);
				parent[t->vertex] = i;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < v; i++)
		net[i].indegree = temp_state[i];

	free(temp_state);

}
void DFS_revtopsort(network net[], int start, int v)
{
	if (net[start].outdegree)
		printf("Warning! Outdegree of starting node is not zero\n");

	int* temp_state = (int*)malloc(sizeof(int) * v);
	for (int i = 0; i < v; i++)
	{
		parent[i] = -1;
		temp_state[i] = net[i].indegree;
	}
	top = -1;
	push(start);
	int startflag = 1;

	while (top >= 0)
	{
		int i = pop();
		if (startflag)
		{
			printf("Start %c", int_to_name(start));
			startflag = 0;
		}
		else
			printf(" -> %c", int_to_name(i));

		for(int j=0;j<v;j++)
			for(node *t=net[j].next;t!=NULL;t=t->next)
				if (t->vertex == i)
				{
					if (--net[j].outdegree == 0)
						push(j);
					break;
				}
	}
	printf("\n");
	for (int i = 0; i < v; i++)
		net[i].indegree = temp_state[i];

	free(temp_state);
}
// Articulation point
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
int strong_recur_starter(node* a[], int v)
{
	order = son_of_root = 0;
	for (int i = 0; i < v; i++) { check[i] = 0; }

	for (int i = 0; i < v; i++)
	{
		if (check[i] == 0)
			strong_recur(a,i);
	}


}
int strong_recur(node* a[], int i)
{
	int min, m;
	check[i] = min = ++order;
	push(i);

	for (node* t = a[i]; t != NULL; t = t->next)
	{
		if (check[t->vertex] == 0)
			m = strong_recur(a, t->vertex);
		else
			m = check[t->vertex];

		if (m < min)
			min = m;
	}

	if (min == check[i])   // articulation point
	{
		int k;
		int flag = 1;
		while ((k = pop()) != i)
		{
			if (flag)
			{
				printf("%c <strongly connected!> : ",int_to_name(i));
				flag = 0;
			}

			printf("%c ", int_to_name(k));
			check[k] = INT_MAX;
		}
		if (!flag)
			printf("\n");
	}

	return min;

}
// Reachability
void floyd(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			if (a[i][j] != 0)
				for (int k = 0; k < v; k++)
				{
					if (a[j][k] != 0)
					{
						if (a[i][k] == 0)
							a[i][k] = a[i][j] + a[j][k];
						else if (a[i][k] > a[i][j] + a[j][k])
							a[i][k] = a[i][j] + a[j][k];
					}
				}
}
void warshall(int a[][MAX_NODE], int v)
{
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			if (a[i][j] != 0)
				for (int k = 0; k < v; k++)
					if (a[j][k] != 0)
						a[i][j] = 1;
}

