#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FLAG (-30)
#define MAX  10000000

typedef struct _node {
	char s[10];
} node;

int comp(const void *a, const void *b)
{
	int flag = strcmp(((node *) a)->s, ((node *) b)->s);
	if (flag > 0)
		return 1;
	else
		return -1;
}

int main()
{
	int n;
	scanf("%d", &n);
	node *str = (node *) malloc(sizeof(node) * (n + 1));
	for (int i = 0; i < n; i++)
		scanf("%s", str[i].s);
	strcpy(str[n].s, "zzzzzzzzz");
	qsort(str, n, sizeof(node), comp);
	for (int i = 0; i < n; i++) {
		int flag, start, end, j;
		flag = strcmp(str[i].s, str[i + 1].s);
		if (flag < FLAG || flag == 0) {
			start = i;
			for (j = i + 1; j < n - 1; j++) {
				int flag2 = strcmp(str[j].s, str[j + 1].s);
				if (flag2 > FLAG && flag2 != 0)
					break;
			}
			end = j;
			for (j = 0; j <= (end - start); j++) {
				for (int k = start; k < end - j; k++) {
					char s1[20], s2[20], t[10];
					strcat(s1, str[k].s);
					strcat(s1, str[k + 1].s);
					strcat(s2, str[k + 1].s);
					strcat(s2, str[k].s);
					if (strcmp(s1, s2) > 0) {
						strcpy(t, str[k].s);
						strcpy(str[k].s, str[k + 1].s);
						strcpy(str[k + 1].s, t);
					}
					for (int i = 0; i < 19; i++) {
						s1[i] = '\0';
						s2[i] = '\0';
					}
				}
			}
		}
	}
	for (int i = 0; str[0].s[i] != '\0'; i++) {
		if (str[0].s[i] != '0')
			printf("%c", str[0].s[i]);
	}
	for (int i = 1; i < n; i++)
		printf("%s", str[i].s);
	printf("\n");
	free(str);
	return 0;
}
