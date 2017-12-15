#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

int main()
{
	int n1, n2, sum = 0;
	scanf("%d", &n1);
	int *nc = (int *)malloc(sizeof(int) * n1);
	for (int i = 0; i < n1; i++)
		scanf("%d", &nc[i]);
	scanf("%d", &n2);
	int *np = (int *)malloc(sizeof(int) * n2);
	for (int i = 0; i < n2; i++)
		scanf("%d", &np[i]);
	qsort(nc, n1, sizeof(int), comp);
	qsort(np, n2, sizeof(int), comp);
	for (int i = 0; nc[i] < 0 && nc[i] < 0; i++)
		sum += nc[i] * np[i];
	for (int i = n1 - 1, j = n2 - 1; nc[i] > 0 && np[j] > 0; i--, j--)
		sum += nc[i] * np[j];
	printf("%d\n", sum);
	return 0;
}
