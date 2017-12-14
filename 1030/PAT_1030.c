#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

typedef struct _dist {
	int d;
	int end;
} dist;

typedef struct _node {
	int id;
	struct _node *prev;
} node;

int edge_w[510][510], cost[510][510];
int visited[510];
int path[510], path_tmp[510];
int money = INF, count;
node *G[510];

int find_min(dist Q[], int n)
{
	int index = -1, min = 2 * INF;
	for (int i = 0; i < n; i++) {
		if (min > Q[i].d && Q[i].end == 0) {
			index = i;
			min = Q[i].d;
		}
	}
	return index;
}

void relax(int u, int v, dist Q[])
{
	int new_d = Q[u].d + edge_w[u][v];
	if (Q[v].d > new_d) {
		node *ptr = (node *) malloc(sizeof(node));
		ptr->id = u;
		ptr->prev = NULL;
		if (G[v] != NULL)
			free(G[v]);
		G[v] = ptr;
		Q[v].d = new_d;
	} else if (Q[v].d == new_d) {
		node *ptr = (node *) malloc(sizeof(node));
		ptr->id = u;
		ptr->prev = G[v]->prev;
		G[v]->prev = ptr;
	}
}

void dijkstra(dist Q[], int s, int d, int N)
{
	for (int i = 0; i < N; i++) {
		Q[i].end = 0;
		Q[i].d = INF;
	}
	Q[s].d = 0;
	G[s] = NULL;
	for (int i = 0; i < N; i++) {
		int u = find_min(Q, N);
		visited[u] = 1;
		Q[u].end = 1;
		for (int j = 0; j < N; j++) {
			if (edge_w[u][j] != INF && visited[j] != 1)
				relax(u, j, Q);
		}
		if (u == d)
			break;
	}
}

void dfs(int s, int d, int deep, int m)
{
	node *p = G[s];
	path_tmp[deep] = s;
	if (p->id == d) {
		m += cost[s][d];
		if (money > m) {
			money = m;
			count = deep + 1;
			for (int i = 0; i < count; i++)
				path[i] = path_tmp[i];
			path[count] = d;
		}
	} else {
		while (p != NULL) {
			dfs(p->id, d, deep + 1, m + cost[s][p->id]);
			p = p->prev;
		}
	}
}

int main()
{
	int N, M, s, d, x, y, w, c, distance = 0;
	scanf("%d%d%d%d", &N, &M, &s, &d);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			edge_w[i][j] = INF;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d", &x, &y, &w, &c);
		edge_w[x][y] = w;
		edge_w[y][x] = w;
		cost[x][y] = c;
		cost[y][x] = c;
	}
	dist *vertex_d = (dist *) malloc(sizeof(dist) * N);
	dijkstra(vertex_d, s, d, N);
	dfs(d, s, 0, 0);
	for (int i = count; i > 0; i--) {
		printf("%d ", path[i]);
		distance += edge_w[path[i]][path[i - 1]];
	}
	printf("%d %d %d\n", path[0], distance, money);
	return 0;
}
