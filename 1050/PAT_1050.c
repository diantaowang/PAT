#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s1[10010] = "", s2[10010] = "";
char s[10010];

int comp(const void *a, const void *b)
{
	return *((char *)a) > *((char *)b) ? 1 : -1;
}

int find(char key, int l, int r)
{
	if (l > r)
		return 0;
	int mid = (l + r) / 2;
	if (key == s2[mid])
		return 1;
	else if (key < s2[mid])
		return find(key, l, mid - 1);
	else
		return find(key, mid + 1, r);
}

int main()
{
	int len1, len2, n = 0;
	fgets(s1, 10010, stdin);
	fgets(s2, 10010, stdin);
	len1 = (int)strlen(s1) - 1;
	len2 = (int)strlen(s2) - 1;
	qsort(s2, len2, sizeof(char), comp);
	int flag;
	for (int i = 0; i < len1; i++) {
		if (s1[i] < s2[0] || s1[i] > s2[len2 - 1]) {
			s[n++] = s1[i];
		} else {
			flag = find(s1[i], 0, len2 - 1);
			if (flag == 0)
				s[n++] = s1[i];
		}
	}
	s[n] = '\0';
	printf("%s\n", s);
	return 0;
}
