#pragma once
#include "graph.h"
#define MAX_HEAP 10000
int heap[MAX_HEAP];
int heap_size;
void init_heap();
void insert(int v);
int extract();
void print_heap();
void copy_heap(int *a,int *n);