#include <stdio.h>
#include <malloc.h>

#define INF 100000

typedef struct _dist{
	int id;
	int d;
} dist;

typedef struct _node{
	int id;
	_node* prev;
} node;

int edge_w[500][501];
int C, N, Sp, M;

void Init_Single_Source(dist v_d[], int s)
{
	for(int i=0; i<=N; i++)
	{
		v_d[i].id = i;
		v_d[i].d = INF;
	}
	v_d[s].d = 0;
}

void swap(int* a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void Min_Heapify()

int main()
{
	int i, x, y, w;
	scanf("%d%d%d%d", &C, &N, &Sp, &M);
	int* vertex_n = (int*)malloc(sizeof(int)*(N+1));
	dist* vertex_d = (dist*)malloc(sizeof(dist)*(N+1));
	for(i=1; i<= N; i++)
		scanf("%d", &vertex_n[i]);
	for(i=0; i<M; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		edge_w[x][y] = w;
		edge_w[y][x] = w;
	}
	return 0;
}
