#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	char s[10];
} node;

int comp(const void *a, const void *b)
{
	node *p, *n;
	char s1[20] = "", s2[20] = "";
	p = (node *) a;
	n = (node *) b;
	strcat(s1, p->s);
	strcat(s1, n->s);
	strcat(s2, n->s);
	strcat(s2, p->s);
	int flag = strcmp(s1, s2);
	if (flag > 0)
		return 1;
	else
		return -1;
}

int main()
{
	int n, i, flag = 0;
	unsigned j = 0;
	scanf("%d", &n);
	node *str = (node *) malloc(sizeof(node) * n);
	for (i = 0; i < n; i++)
		scanf("%s", str[i].s);
	qsort(str, n, sizeof(node), comp);
	for (i = 0; i < n; i++) {
		for (j = 0; j < strlen(str[i].s); j++) {
			if (str[i].s[j] != '0') {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (i == n && j == strlen(str[i - 1].s))
		printf("0");
	else {
		while (str[i].s[j] != '\0') {
			printf("%c", str[i].s[j]);
			j++;
		}
		for (i = i + 1; i < n; i++)
			printf("%s", str[i].s);
	}
	printf("\n");
}
