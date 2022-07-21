#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


int GM[MAX_NODE][MAX_NODE];
int FLOW[MAX_NODE][MAX_NODE];
node* GL[MAX_NODE];
network NET[MAX_NODE];
int main()
{
	int v, e;

	FILE* fp = fopen("aoe_grpah.txt", "rt");
	input_directed_adjlist(GL, &v, &e, fp);
	print_adjlist(GL, v);

	set_topology(NET, GL, v);
	critical_activity(NET, v);

	fclose(fp);
	
	return 0;
}
