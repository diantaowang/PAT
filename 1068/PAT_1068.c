#include <stdio.h>
#include <stdlib.h>

int dp[110], path[10010][110];

int comp(const void *a, const void *b)
{
	return *((int *)a) < *((int *)b) ? 1 : -1;
}

void find(int n, int m, int *v)
{
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j >= v[i - 1] && dp[j - v[i - 1]] + v[i - 1] >= dp[j]) {
				dp[j] = dp[j - v[i - 1]] + v[i - 1];
				path[i][j] = 1;
			}
		}
	}
}

int main()
{
	int n, m, v[10010], flag = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	qsort(v, n, sizeof(int), comp);
	find(n, m, v);
	if (dp[m] < m)
		printf("No Solution\n");
	else {
		for (int i = n, j = m; i > 0; i--) {
			if (path[i][j] == 1) {
				j -= v[i - 1];
				if (flag == 0) {
					flag = 1;
					printf("%d", v[i - 1]);
				} else
					printf(" %d", v[i - 1]);
			}
		}
		printf("\n");
	}
	return 0;
}
