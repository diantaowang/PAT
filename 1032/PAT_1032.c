#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int next;
	int flag;
} node;

int main()
{
	int a, b, N, index;
	char c;
	scanf("%d %d %d", &a, &b, &N);
	node *addr = (node *) malloc(sizeof(node) * 100010);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &index);
		scanf("%c %d", &c, &addr[index].next);
	}
	while (a != -1) {
		addr[a].flag = 1;
		a = addr[a].next;
	}
	while (b != -1) {
		if (addr[b].flag == 1) {
			printf("%05d\n", b);
			return 0;
		}
		b = addr[b].next;
	}
	printf("-1\n");
	return 0;
}
