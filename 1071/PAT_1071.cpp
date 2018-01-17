#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

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
	return strcmp((char *)a, (char *)b);
}

int main()
{
	char s[1050000];
	int num = 0;
	fgets(s, 1050000, stdin);
	int i = 0, j = 0, type = 0, pre_type;
	while (s[i] != '\0') {
		pre_type = type;
		type = IsAlph(s[i]);
		if (type == 1)
			key[num][j++] = s[i];
		else if (type == 2)
			key[num][j++] = s[i] + 32;
		else if (pre_type != 0) {
			key[num][j] = '\0';
			num++;
			j = 0;
		}
		i++;
	}
	qsort(key, num, sizeof(char) * 500, comp);
	int MAX = 0, max = 1;
	char *word;
	for(i = 0; i<num; i++) {
		if(strcmp(key[i], key[i+1]) == 0)
			max++;
		else if(max > MAX) {
			MAX = max;
			word = key[i];
			max = 1;
		}
	}
	printf("%s %d\n", word, MAX);
	return 0;
}
