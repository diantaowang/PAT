#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	char *s;
} node;

int IsAlph(char s)
{
	if ((s >= '0' && s <= '9') || (s >= 'a' && s <= 'z'))
		return 1;
	else if (s >= 'A' && s <= 'Z')
		return 2;
	else
		return 0;
}

int comp(const void *a, const void *b)
{
	return strcmp(((node *) a)->s, ((node *) b)->s);
}

int main()
{
	char s[1050000], t[1050000];
	node *key = (node *) malloc(sizeof(node) * 1050000);
	int num = 0;
	fgets(s, 1050000, stdin);
	int i = 0, j = 0, type;
	while (s[i] != '\0') {
		type = IsAlph(s[i]);
		if (type == 1)
			t[j++] = s[i];
		else if (type == 2)
			t[j++] = s[i] + 32;
		else {
			t[j] = '\0';
			int len = strlen(t);
			if (len > 0) {
				key[num].s = (char *)malloc(sizeof(char) * (len + 1));
				strcpy(key[num].s, t);
				num++;
				j = 0;
			}
		}
		i++;
	}
	qsort(key, num, sizeof(node), comp);
	int MAX = 0, max = 1;
	char *word;
	key[num].s = (char *)"";
	for (i = 0; i < num; i++) {
		if (strcmp(key[i].s, key[i + 1].s) == 0)
			max++;
		else if (max > MAX) {
			MAX = max;
			word = key[i].s;
			max = 1;
		} else
			max = 1;
	}
	printf("%s %d\n", word, MAX);
	for (i = 0; i < num; i++)
		free(key[i].s);
	return 0;
}
