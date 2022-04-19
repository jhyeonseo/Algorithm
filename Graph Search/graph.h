#pragma once
#include"graph.h"
#include"stack.h"
#include"node.h"
#include"heap.h"

// graph representation
int GM[MAX_NODE][MAX_NODE];
node* GL[MAX_NODE];
int check[MAX_NODE];
int parent[MAX_NODE];
void input_adjmatrix(int a[][MAX_NODE], int* v, int* e);
void print_adjmatrix(int a[][MAX_NODE], int v);
void input_adjlist(node* a[], int* v, int* e, FILE* fp);
void print_adjlist(node* a[], int v);
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
int pq_update(int v, int w);
// Spanning tree - articulation point
int son_of_root;
int order;
void AP_recur_starter(node* a[], int v);
int AP_recur(node* a[], int i);		
