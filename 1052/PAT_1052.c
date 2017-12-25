#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int addr;
	int key;
	int visited;
	int next;
} node;

node list[100010];

int comp(const void *a, const void *b)
{
	node *p = (node *) a;
	node *n = (node *) b;
	if (p->visited == 0)
		return 1;
	else if (n->visited == 0)
		return -1;
	else
		return p->key > n->key ? 1 : -1;
}

int main()
{
	int n, start;
	scanf("%d%d", &n, &start);
	for (int i = 0; i < 100010; i++)
		list[i].key = 999999;
	for (int i = 0; i < n; i++) {
		int addr;
		scanf("%d", &addr);
		scanf("%d%d", &list[addr].key, &list[addr].next);
		list[addr].addr = addr;
	}
	if (start == -1) {
		printf("0 -1\n");
		return 0;
	}
	for (int i = start;;) {
		list[i].visited = 1;
		if (list[i].next == -1)
			break;
		i = list[i].next;
	}
	qsort(list, 100010, sizeof(node), comp);
	int num = 0;
	while (list[num].key < 999999 && list[num].visited == 1 && num < n) {
		num++;
	}
	printf("%d %05d\n", num, list[0].addr);
	for (int i = 0; i < num - 1; i++)
		printf("%05d %d %05d\n", list[i].addr, list[i].key,
		       list[i + 1].addr);
	printf("%05d %d -1\n", list[num - 1].addr, list[num - 1].key);
	return 0;
}
