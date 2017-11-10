#include <stdio.h>
#include <malloc.h>

#define MAX_VERTEX 80

typedef struct _Graph{
	int vertexs[MAX_VERTEX];
	int AdjMatrix[MAX_VERTEX][MAX_VERTEX];
} Graph;

int Visited[MAX_VERTEX] = {0};

void DFS_VISIT(Graph G, int i)
{
	Visited[i] = 1;
	for(int j=0; j<MAX_VERTEX-1; j++)
	{
		if(Visited[j] == 0 && G.AdjMatrix[i][j] == 1)
		{
//			printf("JJJJJJJJJJJJJJJ:  %d\n", j);
			DFS_VISIT(G, j);
		}
	}
}

void DFS(Graph G, int *R, int index)
{
	*R = -2;
	int i;
	for(i=0; i<MAX_VERTEX-1; i++)
	{
		G.AdjMatrix[index][i] = 0;
		G.AdjMatrix[i][index] = 0;
	}
/*	printf("---------------------------\n");
	for(int j=0; j<MAX_VERTEX-1; j++)
	{
		for(int k=0; k<MAX_VERTEX-1; k++)
			printf("%d ", G.AdjMatrix[j][k]);
		printf("\n");
	}*/
	for(i=0; i<MAX_VERTEX-1; i++)
		Visited[i] = 0;
	for(i=0; i<MAX_VERTEX-1; i++)	
	{
		if(G.vertexs[i] == 1 && Visited[i] == 0)
		{
			(*R)++;
	//		printf("XXXXXXXXXXXX  %d\n", i);
			DFS_VISIT(G, i);
		}
	}
}

int main()
{
	int N, M, K;
	int i, j, t1, t2, index;
	int Losted[MAX_VERTEX];
	int *R;
	Graph G = {{0},{0}};
	scanf("%d%d%d", &N, &M, &K);
	R = (int*)malloc(sizeof(int)*K);
	for(i=0; i<M; i++)
	{
		scanf("%d%d", &t1, &t2);
		G.vertexs[t1] = 1;
		G.vertexs[t2] = 1;
		G.AdjMatrix[t1][t2] = 1;
		G.AdjMatrix[t2][t1] = 1;
	}
	for(i=0; i<K; i++)
		scanf("%d", &Losted[i]);
	/*for(i=0; i<MAX_VERTEX-1; i++)
	{
		for(j=0; j<MAX_VERTEX-1; j++)
			printf("%d ", G.AdjMatrix[i][j]);
		printf("\n");
	}*/
	for(i=0; i<K; i++)
	{
		index = Losted[i];
		DFS(G, R+i, index);
	}
	for(i=0; i<K; i++)
		printf("%d\n", *(R+i));
	return 0;
}
