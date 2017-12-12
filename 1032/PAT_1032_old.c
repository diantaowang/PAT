#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *((int *)a) < *((int *)b) ? 1 : -1;
}

int main()
{
	int head1, head2, N;
	char c;
	scanf("%d %d %d", &head1, &head2, &N);
	int *addr = (int *)malloc(sizeof(int) * N * 2);
	for (int i = 0, j = 0; i < N; i++) {
		scanf("%d %c %d", &addr[j], &c, &addr[j + 1]);
		j += 2;
	}
	qsort(addr, 2 * N, sizeof(int), comp);
	for (int i = 1; i < 2 * N - 1; i++) {
		if (addr[i] == addr[i - 1] && addr[i] == addr[i + 1]) {
			printf("%05d\n", addr[i]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
