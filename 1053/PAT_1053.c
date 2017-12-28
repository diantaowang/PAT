#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int id, wt, num;
	int son[110];
} node;

node tree[110];
int s, path[110];

int comp(const void *a, const void *b)
{
	return ((node *) a)->wt < ((node *) b)->wt ? 1 : -1;
}

void dfs(int id, int deep, int weight)
{
	weight += tree[id].wt;
	path[deep] = tree[id].wt;
	if (tree[id].num == 0) {
		if (weight == s) {
			for (int i = 0; i < deep; i++)
				printf("%d ", path[i]);
			printf("%d\n", path[deep]);
		}
	} else {
		for (int i = 0; i < tree[id].num; i++)
			dfs(tree[id].son[i], deep + 1, weight);
	}
}

int main()
{
	int n, m, weight = 0;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		tree[i].id = i;
		scanf("%d", &tree[i].wt);
	}
	for (int i = 0; i < m; i++) {
		int index, num;
		node t[110];
		scanf("%d%d", &index, &num);
		tree[index].num = num;
		for (int i = 0; i < num; i++) {
			int id;
			scanf("%d", &id);
			t[i].id = id;
			t[i].wt = tree[id].wt;
		}
		qsort(t, num, sizeof(node), comp);
		for (int i = 0; i < num; i++)
			tree[index].son[i] = t[i].id;
	}
	dfs(0, 0, weight);
	return 0;
}

