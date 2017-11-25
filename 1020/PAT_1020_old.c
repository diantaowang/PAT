#include <stdio.h>
#include <stdlib.h>

#define LEFT  0
#define RIGHT 1

typedef struct _node {
	int data;
	struct _node *left, *right;
} node;

int Post[31], In[31];

node *add_node(node * f, int flag)
{
	node *child = (node *) malloc(sizeof(node));
	child->left = NULL;
	child->right = NULL;
	if (flag == LEFT)
		f->left = child;
	else if (flag == RIGHT)
		f->right = child;
	return child;
}

void make_tree(int start, int root, int end, node * f)
{
	int i;
	for (i = start; i <= end && In[i] != Post[root]; i++) ;
	f->data = In[i];
	if (start <= i - 1) {
		node *l = add_node(f, LEFT);
		make_tree(start, root - end + i - 1, i - 1, l);
	}
	if (i + 1 <= end) {
		node *r = add_node(f, RIGHT);
		make_tree(i + 1, root - 1, end, r);
	}
}

void bfs(node * T[], int L[], int N, int index)
{
	int j = 0;
	node *NewT[31] = { NULL };
	for (int i = 0; i < N; i++) {
		L[index++] = T[i]->data;
		if (T[i]->left != NULL)
			NewT[j++] = T[i]->left;
		if (T[i]->right != NULL)
			NewT[j++] = T[i]->right;
	}
	if (j <= 0)
		return;
	bfs(NewT, L, j, index);
}

int main()
{

	int N, Level[31];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Post[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &In[i]);
	node *tree = (node *) malloc(sizeof(node));
	tree->left = NULL;
	tree->right = NULL;
	make_tree(0, N - 1, N - 1, tree);
	bfs(&tree, Level, 1, 0);
	for (int i = 0; i < N - 1; i++)
		printf("%d ", Level[i]);
	printf("%d\n", Level[N - 1]);
	return 0;
}
