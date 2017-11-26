#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
} node;

int V[10010], Max_t;

void dfs_visit(node * T, int s, int deep)
{
	V[s] = 1;
	if (deep > Max_t)
		Max_t = deep;
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

int main()
{
	int N, a, b, flag, MAX = 0;
	scanf("%d", &N);
	int *root = (int *)malloc(sizeof(int) * (N + 2));
	node *T = (node *) malloc(sizeof(node) * (N + 2));
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &a, &b);
		add_node(&T[a], b);
		add_node(&T[b], a);
	}
	for (int i = 1; i <= N; i++) {
		Max_t = 0;
		flag = dfs(T, N, i);
		if (flag != 0) {
			printf("Error: %d components\n", flag + 1);
			return 0;
		} else {
			root[i] = Max_t;
			if (MAX < Max_t)
				MAX = Max_t;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (root[i] == MAX) {
			printf("%d\n", i);
		}
	}
	return 0;
}
