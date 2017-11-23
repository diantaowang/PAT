#include <stdio.h>
#include <stdlib.h>

#define INF       10000000
#define PARENT(i) ((i-1)>>1)
#define LEFT(i)   (i<<1)
#define RIGHT(i)  ((i<<1)+1)

typedef struct _dist {
	int id;
	int d;
} dist;

typedef struct _node {
	int id;
	struct _node *prev;
} node;

int edge_w[510][510];
int vertex_n[510], visited[510];
int path[510], path_tmp[510];
int C, N, Sp, M, HeapSize;
int NEED = 100000000, REST = 100000000;
node *G[510];

void Init_Single_Source(dist v_d[], int s)
{
	for (int i = 0; i <= N; i++) {
		v_d[i].id = i;
		v_d[i].d = INF;
	}
	v_d[s].d = 0;
}

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void Min_Heapify(dist A[], int i)
{
	int index = i + 1, min;
	int l = LEFT(index);
	int r = RIGHT(index);
	if (l <= HeapSize && A[l - 1].d < A[i].d)
		min = l - 1;
	else
		min = i;
	if (r <= HeapSize && A[r - 1].d < A[min].d)
		min = r - 1;
	if (min != i) {
		swap(&A[i].d, &A[min].d);
		swap(&A[i].id, &A[min].id);
		Min_Heapify(A, min);
	}
}

void Build_Min_Heap(dist A[])
{
	for (int i = N / 2 - 1; i >= 0; i--)
		Min_Heapify(A, i);
}

int Heap_Extract_Min(dist A[], int *u_d)
{
	if (HeapSize < 1)
		return -1;
	int index = A[0].id;
	*u_d = A[0].d;
	A[0].d = A[HeapSize - 1].d;
	A[0].id = A[HeapSize - 1].id;
	HeapSize--;
	Min_Heapify(A, 0);
	return index;
}

int Heap_Increase_Key(dist A[], int i, int key)
{
	if (key > A[i].d)
		return -1;
	A[i].d = key;
	while (i > 0 && A[PARENT(i)].d > A[i].d) {
		swap(&A[i].d, &A[PARENT(i)].d);
		swap(&A[i].id, &A[PARENT(i)].id);
		i = PARENT(i);
	}
	return 1;
}

void relax(int u, int *u_d, int v, dist Q[])
{
	int index = 0;
	for (int i = 0; i < 501; i++) {
		if (Q[i].id == v) {
			index = i;
			break;
		}
	}
	int new_d = *u_d + edge_w[u][v];
	if (Q[index].d > new_d) {
		Heap_Increase_Key(Q, index, new_d);
		node *ptr = (node *) malloc(sizeof(node));
		ptr->id = u;
		ptr->prev = NULL;
		if (G[v] != NULL)
			free(G[v]);
		G[v] = ptr;
	} else if (Q[index].d == new_d) {
		node *ptr = (node *) malloc(sizeof(node));
		ptr->id = u;
		ptr->prev = G[v]->prev;
		G[v]->prev = ptr;
	}
}

void dijkstra(dist Q[], int s)
{
	int u;
	int *u_d = (int *)malloc(sizeof(int));
	Init_Single_Source(Q, s);
	Build_Min_Heap(Q);
	for (int i = 0; i <= N; i++) {
		u = Heap_Extract_Min(Q, u_d);
		visited[u] = 1;
		for (int j = 0; j < 500; j++) {
			if (edge_w[u][j] != 0 && visited[j] != 1)
				relax(u, u_d, j, Q);
		}
		if (u == Sp)
			break;
	}
}

void dfs(int id, int deep)
{
	node *p = G[id];
	path_tmp[deep] = id;
	if (p->id == -1) {
		int need = 0, rest = 0;
		for (int i = deep - 1; i >= 0; i--) {
			if (rest + vertex_n[path_tmp[i]] < C / 2) {
				need += (C / 2 - rest - vertex_n[path_tmp[i]]);
				rest = 0;
			} else
				rest += (vertex_n[path_tmp[i]] - C / 2);
		}
		if (NEED > need || (NEED == need && REST > rest)) {
			int j = 0;
			for (int i = deep; i >= 0; i--)
				path[j++] = path_tmp[i];
			path[deep + 1] = -1;
			NEED = need;
			REST = rest;
		}
		return;
	} else {
		while (p != NULL) {
			dfs(p->id, deep + 1);
			p = p->prev;
		}
	}
}

int main()
{
	int i, x, y, w;
	scanf("%d%d%d%d", &C, &N, &Sp, &M);
	HeapSize = N + 1;
	G[0] = (node *) malloc(sizeof(node));
	G[0]->prev = NULL;
	G[0]->id = -1;
	dist *vertex_d = (dist *) malloc(sizeof(dist) * (N + 2));
	for (i = 1; i <= N; i++)
		scanf("%d", &vertex_n[i]);
	for (i = 0; i < M; i++) {
		scanf("%d%d%d", &x, &y, &w);
		edge_w[x][y] = w;
		edge_w[y][x] = w;
	}
	dijkstra(vertex_d, 0);
	dfs(Sp, 0);
	printf("%d ", NEED);
	i = 1;
	while (path[i] >= 0) {
		printf("%d->", path[i - 1]);
		i++;
	}
	printf("%d %d\n", path[i - 1], REST);
	return 0;
}
