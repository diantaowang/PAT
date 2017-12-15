#include <stdio.h>
#include <stdlib.h>

#define INF 999999999

typedef struct _node {
	int num;
	int pre[501];
} node;

int edge_w[510][510], cost[510][510];
int visited[510], dist[510];
int path[510], path_tmp[510];
int money = INF, count, distance;
node G[510];

int find_min(int Q[], int n)
{
	int index = -1, min = INF;
	for (int i = 0; i < n; i++) {
		if (min > Q[i] && visited[i] == 0) {
			index = i;
			min = Q[i];
		}
	}
	return index;
}

void relax(int u, int v, int Q[])
{
	int new_d = Q[u] + edge_w[u][v];
	if (Q[v] > new_d) {
		G[v].num = 1;
		G[v].pre[0] = u;
		Q[v] = new_d;
	} else if (Q[v] == new_d) {
		G[v].pre[G[v].num] = u;
		G[v].num++;
	}
}

void dijkstra(int Q[], int s, int d, int N)
{
	for (int i = 0; i < N; i++)
		Q[i] = INF;
	Q[s] = 0;
	for (int i = 0; i < N; i++) {
		int u = find_min(Q, N);
		visited[u] = 1;
		for (int j = 0; j < N; j++) {
			if (edge_w[u][j] != INF && visited[j] != 1)
				relax(u, j, Q);
		}
		if (u == d)
			break;
	}
}

void dfs(int s, int d, int deep)
{
	path_tmp[deep] = s;
	if (s == d) {
		int m = 0, w = 0;
		for (int i = deep; i > 0; i--) {
			int t1 = path_tmp[i], t2 = path_tmp[i - 1];
			m += cost[t1][t2];
			w += edge_w[t1][t2];
		}
		if (money > m) {
			money = m;
			distance = w;
			count = deep + 1;
			for (int i = 0; i < count; i++)
				path[i] = path_tmp[i];
		}
		return;
	}
	for (int i = 0; i < G[s].num; i++)
		dfs(G[s].pre[i], d, deep + 1);
}

int main()
{
	int N, M, s, d;
	scanf("%d%d%d%d", &N, &M, &s, &d);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			edge_w[i][j] = INF;
	int x, y, w, c;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d", &x, &y, &w, &c);
		edge_w[x][y] = w;
		edge_w[y][x] = w;
		cost[x][y] = c;
		cost[y][x] = c;
	}
	dijkstra(dist, s, d, N);
	dfs(d, s, 0);
	for (int i = count - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d\n", distance, money);
	return 0;
}
