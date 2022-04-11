#include<stdio.h>
#include<stdlib.h>
#include"node.h"

int put(int k)
{
	dnode* t = malloc(sizeof(dnode));
	if (t == NULL)
	{
		printf("Out of memory !\n");
		return -1;
	}
	t->key = k;

	tail->prev->next = t;
	t->prev = tail->prev;
	tail->prev = t;
	t->next = tail;

	return k;
};
int get()
{
	int k;
	dnode* t = head->next;
	if (t == tail)
	{
		printf("Queue underflow (Que is empty)!\n");
		return -1;
	}
	k = t->key;
	head->next = t->next;
	t->next->prev = head;

	free(t);
	return k;
};
void init_queue()
{
	head = (dnode*)calloc(1, sizeof(dnode));
	tail = (dnode*)calloc(1, sizeof(dnode));

	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}
void end_queue()
{
	dnode* t = head;

	if (head->next == tail)
	{
		free(head);
		free(tail);
	}
	else
	{
		do
		{
			dnode* k = t;
			t = k->next;
			free(k);
		} while (t != tail);
		free(t);
	}

}
int queue_empty()
{
	if (head->next == tail)
		return 1;
	else
		return 0;
};