#include <stdio.h>
#include <string.h>

#define INF 999999999

int edge[1020][1020];

int find_min(int *q, int n, int *visited)
{
	int index = -1, min = INF;
	for (int i = 0; i < n; i++) {
		if (min > q[i] && visited[i] == 0) {
			index = i;
			min = q[i];
		}
	}
	return index;
}

void relax(int u, int v, int *q)
{
	int new_d = q[u] + edge[u][v];
	if (q[v] > new_d) {
		q[v] = new_d;
	}
}

int dijkstra(int s, int n, int max_dist, int *average)
{
	int min = INF;
	int q[1020], visited[1020] = { 0 };
	for (int i = 0; i < n; i++)
		q[i] = INF;
	q[s] = 0;
	for (int i = 1; i < n; i++) {
		int u = find_min(q, n, visited);
		if (u != -1) {
			visited[u] = 1;
			if (u <= 1000) {
				if (q[u] > max_dist)
					return -1;
				else {
					*average += q[u];
					if (min > q[u])
						min = q[u];
				}
			}
			for (int j = 1; j < n; j++) {
				if (edge[u][j] != 0 && visited[j] != 1)
					relax(u, j, q);
			}
		} else
			return min;
	}
	return min;
}

int main()
{
	int n, m, s, d;
	char info[100];
	scanf("%d%d%d%d\n", &n, &m, &s, &d);
	for (int i = 1; i <= s; i++) {
		fgets(info, 100, stdin);
		int len = strlen(info) - 1;
		int space_num = 0, G_num = 0, sum = 0, base = 1;
		int x = 0, y = 0, dist = 0;
		for (int j = len - 1; j >= 0; j--) {
			if (info[j] == ' ') {
				if (space_num == 0)
					dist = sum;
				else if (space_num == 1 && G_num == 0)
					y = sum;
				sum = 0;
				base = 1;
				space_num++;
			} else if (info[j] == 'G') {
				if (j == 0) {
					x = sum + 1000;
					break;
				} else {
					y = sum + 1000;
					sum = 0;
					base = 1;
					G_num = 1;
				}
			} else if (j == 0) {
				x = sum + (info[j] - '0') * base;
				break;
			} else {
				sum += (info[j] - '0') * base;
				base *= 10;
			}
		}
		edge[x][y] = dist;
		edge[y][x] = dist;
	}
	int id = 0, Min = -1, Dist;
	for (int i = 1001; i < 1001 + m; i++) {
		int dist = 0, min = INF;
		min = dijkstra(i, m + 1001, d, &dist);
		if (min != -1) {
			if (Min < min || (Min == min && Dist > dist)) {
				Min = min;
				Dist = dist;
				id = i - 1000;
			}
		}
	}
	if (Min == -1)
		printf("No Solution\n");
	else {
		double average = (double)Dist / (double)n;
		// double average = (double)Dist / (double)n + 0.0499999;
		printf("G%d\n%.1f %.1f\n", id, (double)Min, average);
	}
	return 0;
}
