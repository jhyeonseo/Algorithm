#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include"heap.h"
#include"graph.h"



int main()
{
	network net[MAX_NODE];
	node* GL[MAX_NODE];
	//int GM[MAX_NODE][MAX_NODE];
	int v, e;

	FILE* fp = fopen("graph.txt", "rt");
	input_directed_adjlist(GL, &v, &e, fp);
	print_adjlist(GL, v);
	for (int i = 0; i < v; i++)
		printf("%p\n", GL[i]);


	set_indegree(GL, v);

	fclose(fp);
	
	return 0;
}
