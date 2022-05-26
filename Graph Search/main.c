#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int main()
{
	int Flow[MAX_NODE][MAX_NODE];
	int Capacity[MAX_NODE][MAX_NODE];
	int v, e;

	FILE* fp = fopen("graph2.txt", "rt");
	input_directed_adjmatrix(Capacity, &v, &e, fp);
	print_adjmatrix(Capacity, v);
	Maximum_flow(Capacity,Flow, v, 4, 5);
	print_adjmatrix(Flow, v);

	fclose(fp);
	
	return 0;
}
