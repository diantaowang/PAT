#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
} node;

int V[10010], Leaf[20010];
int MAX = 0, Count = 0, Num = 0;

void dfs_visit(node * T, int s, int deep)
{
	V[s] = 1;
	if (deep > MAX) {
		MAX = deep;
		Count = 0;
		Leaf[Count + Num] = s;
	} else if (deep == MAX) {
		Leaf[(++Count) + Num] = s;
	}
	node *p = (T + s)->next;
	while (p != NULL) {
		if (V[p->data] == 0)
			dfs_visit(T, p->data, deep + 1);
		p = p->next;
	}
}

int dfs(node * T, int N, int s)
{
	int flag = 0;
	for (int i = 1; i <= N; i++)
		V[i] = 0;
	dfs_visit(T, s, 1);
	for (int i = 1; i <= N; i++) {
		if (V[i] == 0) {
			flag++;
			dfs_visit(T, i, 1);
		}
	}
	return flag;
}

void add_node(node * head, int data)
{
	node *newE = (node *) malloc(sizeof(node));
	newE->data = data;
	newE->next = head->next;
	head->next = newE;
}

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

int main()
{
	int N, a, b, flag;
	scanf("%d", &N);
	node *T = (node *) malloc(sizeof(node) * (N + 2));
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &a, &b);
		add_node(&T[a], b);
		add_node(&T[b], a);
	}
	flag = dfs(T, N, 1);
	if (flag != 0) {
		printf("Error: %d components\n", flag + 1);
		return 0;
	} else {
		MAX = 0;
		Num = Count + 1;
		dfs(T, N, Leaf[0]);
		Num += (Count + 1);
		qsort(Leaf, Num, sizeof(int), comp);
		for (int i = 0; i < Num; i++) {
			if (Leaf[i] != Leaf[i + 1])
				printf("%d\n", Leaf[i]);
		}
	}
	return 0;
}
