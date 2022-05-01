#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include"heap.h"
#include"graph.h"

node* GL[MAX_NODE];
edge Edge[MAX_NODE];
int GM[MAX_NODE][MAX_NODE];

int main()
{
	int v, e;
	FILE* fp = fopen("graph.txt", "rt");

	input_edge(Edge, &v, &e, fp);

	kruskal(Edge, v, e);

	print_tree(v);

	fclose(fp);
	
	return 0;
}
