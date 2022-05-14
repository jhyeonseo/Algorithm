#pragma once
#include"stack.h"
#include"queue.h"
#include"heap.h"

#define MAX_NODE 100

// graph representation
typedef struct _node
{
	int vertex;
	int weight;
	struct _node* next;
}node;
typedef struct _edge
{
	int v1, v2;
	int weight;
}edge;
typedef struct _network
{
	int state;
	struct _network* next;
}network;
int check[MAX_NODE];
int parent[MAX_NODE];
// graph making & print
void input_adjmatrix(int a[][MAX_NODE], int* v, int* e, FILE* fp);
void input_directed_adjmatrix(int a[][MAX_NODE], int* v, int* e, FILE* fp);
void print_adjmatrix(int a[][MAX_NODE], int v);
void input_adjlist(node* a[], int* v, int* e, FILE* fp);
void input_directed_adjlist(node* a[], int* v, int* e, FILE* fp);
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
void DFS_adjmatrix(int a[][MAX_NODE], int v);
void DFS_directed_adjmatrix(int a[][MAX_NODE], int v);
void DFS_recur_list_starter(node* a[], int v);
void DFS_recur_list(node* a[], int v, int i);
void DFS_adjlist(node* a[], int v);
void DFS_directed_adjlist(node* a[], int v);
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
// Shortest path
void shortest_adjlist(node* a[], int start, int v);
void dijkstra(int a[][MAX_NODE], int start, int v);
// Topological sorting
void set_topology(network net[], node* a[], int v);
void set_indegree(network net[], int v);
void DFS_topsort(network net[], int start, int v);
// Spanning tree - articulation point
int son_of_root;
int order;
void AP_recur_starter(node* a[], int v);
int AP_recur(node* a[], int i);		
// Reachability
void floyd(int a[][MAX_NODE], int v);
void warshall(int a[][MAX_NODE], int v);