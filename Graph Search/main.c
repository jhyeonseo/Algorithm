#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


int GM[MAX_NODE][MAX_NODE];
node* GL[MAX_NODE];
int main()
{
	int v, e;

	FILE* fp = fopen("strongly_connected_test2.txt", "rt");
	input_directed_adjlist(GL, &v, &e, fp);
	print_adjlist(GL, v);

	//strong_recur_starter(GL, v);
	AP_recur_starter(GL, v);

	fclose(fp);
	
	return 0;
}
