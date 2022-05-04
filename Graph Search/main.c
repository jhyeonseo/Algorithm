#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include"heap.h"
#include"graph.h"



int main()
{
	node* GL[MAX_NODE];
	edge Edge[MAX_NODE];
	int GM[MAX_NODE][MAX_NODE];
	int v, e;

	FILE* fp = fopen("graph.txt", "rt");
	input_directed_adjmatrix(GM, &v, &e, fp);
	print_adjmatrix(GM, v);
	DFS_directed_adjmatrix(GM, v);
	warshall_adjmatrix(GM, v);
	print_adjmatrix(GM, v);


	fclose(fp);
	
	return 0;
}
