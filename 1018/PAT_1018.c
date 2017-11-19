#include <stdio.h>

#define INF 100000

struct dist{
	int id;
	int d;
};

struct dist vertex_d[501];
int edge_w[500][501];
int vertex_n[501];
int C, N, Sp, M;

int main()
{
	int i, x, y, w;
	scanf("%d%d%d%d", &C, &N, &Sp, &M);
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
