#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "node.h"
#include"heap.h"
#include"graph.h"

int main()
{
	int v, e;
	FILE* fp = fopen("graph.txt", "rt");

	input_adjlist(GL, &v, &e,fp);
	print_adjlist(GL, v);

	PFS_adjlist(GL, v);
	print_tree(v);
	print_score(v);

	fclose(fp);
	
	return 0;
}
