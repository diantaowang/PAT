#include <stdio.h>
#include <string.h>

char str[6] = "SHCDJ";

typedef struct _node {
	char s[5];
} node;

node init[55], result[55];

int main()
{
	int n, key[55], count = 0;
	node *pre = init;
	node *next = result;
	node *tmp;
	scanf("%d", &n);
	for (int i = 0; i < 54; i++)
		scanf("%d", &key[i]);
	for (int i = 0; i < 5; i++) {
		int num = 13;
		if (i == 4)
			num = 2;
		for (int j = 1; j <= num; j++) {
			init[count].s[0] = str[i];
			if (j <= 9)
				init[count].s[1] = '0' + j;
			else {
				init[count].s[1] = '1';
				init[count].s[2] = j % 10 + '0';
			}
			count++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 54; j++) {
			int index = key[j] - 1;
			strcpy(next[index].s, pre[j].s);
		}
		tmp = next;
		next = pre;
		pre = tmp;
	}
	for (int i = 0; i < 54 - 1; i++)
		printf("%s ", pre[i].s);
	printf("%s\n", pre[53].s);
	return 0;
}
