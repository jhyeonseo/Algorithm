#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "node.h"
#include"heap.h"
#include"graph.h"

int main()
{
	/*
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		insert(rand() % 50);
	for (int i = 0; i < heap_size; i++)
	{
		print_heap();
		printf("\n");
		printf("<%d>\n", extract());
	}
	*/ // FOR HEAP TEST!

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
