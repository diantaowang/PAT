#include <stdio.h>
#include <malloc.h>

typedef struct _TreeNode *PtrToNode;

typedef struct _TreeNode {
	PtrToNode Child[100];
} TreeNode;

void bfs(TreeNode * T[], int Num[], int *deep)
{
	int i, j, k = 0;
	TreeNode *NewT[100] = { NULL };
	for (i = 0; T[i] != NULL; i++) {
		if (T[i]->Child[0] == NULL)
			Num[*deep]++;
		for (j = 0; T[i]->Child[j] != NULL; j++) {
			NewT[k++] = T[i]->Child[j];
		}
	}
	if (NewT[0] == NULL)
		return;
	(*deep)++;
	bfs(NewT, Num, deep);
}

int main()
{
	int m, n, i, j, deep = 0;
	int Num[100] = { 0 };
	int FathID, ChildID, ChildNum;
	TreeNode *Nodes[100] = { NULL };
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &FathID, &ChildNum);
		if (Nodes[FathID] == NULL) {
			Nodes[FathID] = (TreeNode *) malloc(sizeof(TreeNode));
		}
		for (j = 0; j < ChildNum; j++) {
			scanf("%d", &ChildID);
			if (Nodes[ChildID] == NULL) {
				Nodes[ChildID] =
				    (TreeNode *) malloc(sizeof(TreeNode));
			}
			Nodes[FathID]->Child[j] = Nodes[ChildID];
		}
	}
	if (m == 0)
		printf("1\n");
	else {
		TreeNode *T[2] = { Nodes[1], NULL };
		bfs(T, Num, &deep);
		for (i = 0; i < deep; i++) {
			printf("%d ", Num[i]);
		}
		printf("%d\n", Num[i]);
	}
	return 0;
}
