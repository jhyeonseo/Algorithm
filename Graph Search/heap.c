#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
// This is just for one heap. If you need more, change is inevitable. ( heap_size -> *N, heap ->  a)

void init_heap() { heap_size = 0; }
void insert(int v)
{
	int k = ++heap_size;
	heap[k] = v;
	
	while ((k / 2) != 0)
	{
		if (check[heap[k / 2]] > check[v])   // 부모랑 자식이 같을때는 자식에게 위로 올라갈 수 있는 우선권 부여
			break;
		else
		{
			heap[k] = heap[k / 2];
			k = k / 2;
		}
	}
	heap[k] = v;
};
int extract()
{
	int k = 1;
	int top = heap[k];

	int v = heap[k] = heap[heap_size--];
	
	while (k <= heap_size / 2)
	{
		int i = k << 1;
		if (check[heap[i]] < check[heap[i + 1]]&&i<heap_size)
			i++;
	
		if (check[heap[i]] <= check[v])
			break;
		else
		{
			heap[k] = heap[i];
			k = i;
		}
	}

	heap[k] = v;
	return top;
};
void adjust_heap(int v)
{
	int k;
	for (int i = 1; i <= heap_size; i++)
		if (heap[i] == v)
		{
			k = i;
			break;
		}

	if (check[heap[k]] > check [heap[k / 2]])   // 변경값이 부모를 넘었을 경우
	{
		while (k / 2 != 0)
		{
			if (check[heap[k / 2]] >= check[v])
				break;
			else
			{
				heap[k] = heap[k / 2];
				k = k / 2;
			}
		}
		heap[k] = v;
	}
	else // 변경값이 그대로 사이에 있거나 자식보다 작아졌을 경우
 	{
		while (k <= heap_size / 2)
		{
			int i = k << 1;

			if ((check[heap[i]] < check[heap[i + 1]]) && i < heap_size)
				i++;

			if (check[heap[i]] <= check[v])
				break;

			else
			{
				heap[k] = heap[i];
				k = i;
			}
		}
		heap[k] = v;
	}

}
void print_heap()
{
	int n = 2;

	for (int i = 1; i <= heap_size; i++)
	{
		printf("%c:%d ", int_to_name(heap[i]), check[heap[i]]);
		if ((i + 1 == n)&&(i!=heap_size))
		{
			printf("\n");
			n = n * 2;
		}
	}
	printf("\n");
}
void copy_heap(int* a, int* n)
{
	a = heap;
	*n = heap_size;
}