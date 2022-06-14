#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


int GM[MAX_NODE][MAX_NODE];
int FLOW[MAX_NODE][MAX_NODE];
node* GL[MAX_NODE];
int main()
{
	int v, e;

	FILE* fp = fopen("capacity.txt", "rt");
	input_directed_adjmatrix(GM, &v, &e, fp);
	print_adjmatrix(GM, v);
	Maximum_flow(GM, FLOW, v, name_to_int('E'), name_to_int('F'));
	print_adjmatrix(FLOW, v);

	fclose(fp);
	
	return 0;
}
