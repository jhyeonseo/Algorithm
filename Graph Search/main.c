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
	//input_adjmatrix(GM, &v, &e, fp);
	//print_adjmatrix(GM, v);
	input_adjlist(GL, &v, &e, fp);
	print_adjlist(GL, v);

	//dijkstra(GM, name_to_int('F'), v);
	shortest_adjlist(GL, name_to_int('F'), v);
	


	print_tree(v);
	fclose(fp);
	
	return 0;
}
