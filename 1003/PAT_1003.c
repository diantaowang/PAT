#include <stdio.h>
#include <malloc.h>

#define MAX_VERTEX_NUM 501
#define NIL 2147483647

int SPNum = 0, MaxTeams = 0, ShortPaths = NIL;

typedef struct _Node {
	int nodenum;
	int edge;
	struct _Node *nextarc;
} Node;

typedef struct {
	int vexnum, arcnum;
	int *info;
	Node *vexs[MAX_VERTEX_NUM];
} ALGraph;

void CreatALGraph(ALGraph * G)
{
	int i, t1, t2, t3;
	Node *Ptr;
	G->info = (int *)malloc((G->vexnum) * sizeof(int));
	for (i = 0; i < G->vexnum; i++) {
		scanf("%d", G->info + i);
		G->vexs[i] = (Node *) NULL;
	}
	for (i = 0; i < G->arcnum; i++) {
		scanf("%d%d%d", &t1, &t2, &t3);
		Ptr = (Node *) malloc(sizeof(Node));
		Ptr->nodenum = t2;
		Ptr->edge = t3;
		Ptr->nextarc = G->vexs[t1];
		G->vexs[t1] = Ptr;
		Ptr = (Node *) malloc(sizeof(Node));
		Ptr->nodenum = t1;
		Ptr->edge = t3;
		Ptr->nextarc = G->vexs[t2];
		G->vexs[t2] = Ptr;
	}
}

void DFS(ALGraph * G, int *Visited, int src, int dst, int PATH, int NUM)
{
	Node *Ptr = G->vexs[src];
	Visited[src] = 1;
	if (src == dst) {
		if (ShortPaths > PATH) {
			ShortPaths = PATH;
			SPNum = 1;
			MaxTeams = NUM;
		} else if (ShortPaths == PATH) {
			SPNum++;
			MaxTeams = (MaxTeams > NUM) ? MaxTeams : NUM;
		}
		Visited[src] = 0;
		return;
	}
	while (Ptr != NULL) {
		if (!Visited[Ptr->nodenum])
			DFS(G, Visited, Ptr->nodenum, dst, PATH + Ptr->edge,
			    NUM + *(G->info + Ptr->nodenum));
		Ptr = Ptr->nextarc;
	}
	Visited[src] = 0;
}

int main()
{
	int src, dst;
	int PATH = 0, NUM;
	int Visited[MAX_VERTEX_NUM] = { 0 };
	ALGraph G;
	scanf("%d%d%d%d", &G.vexnum, &G.arcnum, &src, &dst);
	CreatALGraph(&G);
	NUM = *(G.info + src);
	DFS(&G, Visited, src, dst, PATH, NUM);
	printf("%d %d\n", SPNum, MaxTeams);
	return 0;
}
