#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(char *s)
{
	int num = s[3] - '0';
	int k = 1;
	for (int i = 2; i >= 0; i--) {
		k *= 10;
		num += (s[i] - '0') * k;
	}
	return num;
}

int comp(const void *a, const void *b)
{
	return *((char *)a) < *((char *)b) ? 1 : -1;
}

int comp2(const void *a, const void *b)
{
	return *((char *)a) > *((char *)b) ? 1 : -1;
}

int calc(char *s)
{
	qsort(s, 4, sizeof(char), comp);
	int n1 = convert(s);
	qsort(s, 4, sizeof(char), comp2);
	int n2 = convert(s);
	int n = n1 - n2;
	printf("%04d - %04d = %04d\n", n1, n2, n);
	sprintf(s, "%04d", n);
	return n;
}

int main()
{
	char s[5];
	scanf("%s", s);
	int n = (int)strlen(s);
	while (n < 4)
		s[n++] = '0';
	s[4] = '\0';
	int IsAllSame = 1;
	for (int i = 3; i > 0; i--) {
		if (s[i] != s[i - 1])
			IsAllSame = 0;
	}
	if (IsAllSame == 1)
		printf("%s - %s = 0000\n", s, s);
	else {
		int num = 0;
		while (num != 6174)
			num = calc(s);
	}
	return 0;
}
