#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

int main()
{
	int n, m;
	int num[100010];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), comp);
	int i = 0, j = n - 1, sum;
	while (1) {
		if (i == j) {
			printf("No Solution\n");
			break;
		} else {
			sum = num[i] + num[j];
			if (sum > m)
				j--;
			else if (sum < m)
				i++;
			else {
				printf("%d %d\n", num[i], num[j]);
				break;
			}
		}
	}
	return 0;
}
