#include <stdio.h>
#include <stdlib.h>

int m[60], num[51][10010];

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

double calc(int n1, int n2)
{
	int common = 0, distinct = 0;
	int i, j;
	for (i = 0, j = 0; i < m[n1] && j < m[n2];) {
		while (num[n1][i] == num[n1][i + 1]) {
			i++;
			if (i == m[n1] - 1)
				break;
		}
		while (num[n2][j] == num[n2][j + 1]) {
			j++;
			if (j == m[n2] - 1)
				break;
		}
		if (num[n1][i] < num[n2][j]) {
			distinct++;
			i++;
		} else if (num[n1][i] > num[n2][j]) {
			distinct++;
			j++;
		} else {
			common++;
			i++;
			j++;
		}
	}
	if (j < m[n2]) {
		i = j;
		n1 = n2;
	}
	while (i < m[n1]) {
		while (num[n1][i] == num[n1][i + 1]) {
			i++;
			if (i == m[n1] - 1)
				break;
		}
		distinct++;
		i++;
	}
	return (double)common / (double)(common + distinct);
}

int main()
{
	int n, k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m[i]);
		for (int j = 0; j < m[i]; j++)
			scanf("%d", &num[i][j]);
		qsort(num[i], m[i], sizeof(int), comp);
	}
	scanf("%d", &k);
	int n1, n2;
	double per;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &n1, &n2);
		per = calc(n1, n2);
		printf("%.1lf%%\n", per * 100);
	}
	return 0;
}
