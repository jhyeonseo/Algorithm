#pragma once
#define MAX_NODE 100
typedef struct _node
{
	int vertex;
	int weight;
	struct _node* next;
}node;
typedef struct _dnode
{
	struct _dnode* prev;
	struct _dnode* next;
	int key;
}dnode;
dnode* head;
dnode* tail;
void init_queue();
void end_queue();
int queue_empty();
int put(int k);
int get();