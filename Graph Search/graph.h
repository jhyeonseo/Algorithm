#pragma once
#include"stack.h"
#include"queue.h"
#include"heap.h"

#define MAX_NODE 1000

// graph representation
typedef struct _node
{
	int vertex;
	int weight;
	struct _node* next;
}node;
typedef struct edge
{
	int v1, v2;
	int weight;
}edge;
int check[MAX_NODE];
int parent[MAX_NODE];
// graph making & print
void input_adjmatrix(int a[][MAX_NODE], int* v, int* e);
void print_adjmatrix(int a[][MAX_NODE], int v);
void input_adjlist(node* a[], int* v, int* e, FILE* fp);
void print_adjlist(node* a[], int v);
void input_edge(edge edge[], int* v, int* e, FILE* fp);
void print_tree(int v);
void print_score(int v);
// int <-> name
int name_to_int(char c);
char int_to_name(int i);
// DFS search
void DFS_recur_matrix_starter(int a[][MAX_NODE], int v);
void DFS_recur_matrix(int a[][MAX_NODE], int v, int i);
void DFS_nonrecur_matrix(int a[][MAX_NODE], int v);
void DFS_recur_list_starter(node* a[], int v);
void DFS_recur_list(node* a[], int v, int i);
void DFS_nonrecur_list(node* a[], int v);
// BFS search
void BFS_adjmatrix(int a[][MAX_NODE], int v);
void BFS_adjlist(node* a[], int v);
void count_matrix_components(int a[][MAX_NODE], int v);
void count_list_components(node* a[], int v);
// PFS search
void PFS_adjlist(node* a[], int v);
void kruskal(edge edge[], int v, int e);
int find_set(int a, int b);
void union_set(int a, int b);
// Spanning tree - articulation point
int son_of_root;
int order;
void AP_recur_starter(node* a[], int v);
int AP_recur(node* a[], int i);		
