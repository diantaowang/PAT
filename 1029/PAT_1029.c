#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1, n2, c = 0;
	scanf("%d", &n1);
	long *s1 = (long *)malloc(sizeof(long) * n1);
	for (int i = 0; i < n1; i++)
		scanf("%ld", &s1[i]);
	scanf("%d", &n2);
	long *s2 = (long *)malloc(sizeof(long) * n2);
	for (int i = 0; i < n2; i++)
		scanf("%ld", &s2[i]);
	int mid = (n1 + n2 - 1) / 2;
	long min, i, j;
	for (i = 0, j = 0; i < n1 && j < n2;) {
		if (s1[i] >= s2[j]) {
			min = s2[j];
			j++;
		} else {
			min = s1[i];
			i++;
		}
		if (c == mid) {
			printf("%ld\n", min);
			return 0;
		}
		c++;
	}
	if (i == n1)
		printf("%ld\n", s2[mid - n1]);
	else
		printf("%ld\n", s1[mid - n2]);
	return 0;
}
