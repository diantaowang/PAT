#include <stdio.h>

typedef struct _node {
	int num;
	int id;
} node;

node count[10010];

int main()
{
	int n, min = 100010, result = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		count[a].num++;
		count[a].id = i;
	}
	for (int i = 1; i < 10010; i++) {
		if (count[i].num == 1) {
			if (count[i].id < min) {
				min = count[i].id;
				result = i;
			}
		}
	}
	if (result == -1)
		printf("None\n");
	else
		printf("%d\n", result);
	return 0;
}
