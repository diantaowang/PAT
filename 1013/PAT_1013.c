#include <stdio.h>
#include <malloc.h>

#define MAX_VERTEX 1001

typedef struct _Graph {
	int vertexs[MAX_VERTEX];
	int AdjMatrix[MAX_VERTEX][MAX_VERTEX];
} Graph;

int N, Visited[MAX_VERTEX];
Graph G;

void DFS_VISIT(int i)
{
	Visited[i] = 1;
	for (int j = 0; j <= N; j++) {
		if (Visited[j] == 0 && G.AdjMatrix[i][j] == 1)
			DFS_VISIT(j);
	}
}

void DFS(int *R)
{
	*R = -1;
	for (int i = 0; i <= N; i++) {
		if (G.vertexs[i] == 1 && Visited[i] == 0) {
			(*R)++;
			DFS_VISIT(i);
		}
	}
}

int main()
{
	int M, K, *R;
	int i, j, t1, t2;
	int Losted[MAX_VERTEX];
	scanf("%d%d%d", &N, &M, &K);
	R = (int *)malloc(sizeof(int) * K);
	for (i = 1; i <= N; i++)
		G.vertexs[i] = 1;
	for (i = 0; i < M; i++) {
		scanf("%d%d", &t1, &t2);
		G.AdjMatrix[t1][t2] = 1;
		G.AdjMatrix[t2][t1] = 1;
	}
	for (i = 0; i < K; i++)
		scanf("%d", &Losted[i]);
	for (i = 0; i < K; i++) {
		for (j = 0; j <= N; j++)
			Visited[j] = 0;
		Visited[Losted[i]] = 1;
		DFS(R + i);
	}
	for (i = 0; i < K; i++)
		printf("%d\n", *(R + i));
	return 0;
}
