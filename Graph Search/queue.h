#pragma once

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