#include <stdio.h>
#include <stdlib.h>

#define LEFT  0
#define RIGHT 1

int num[1010], level[1010];
int POWER[12] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

void find(int l, int r, int index)
{
	if (l > r)
		return;
	int l_t = l, r_t = r;
	int k = 0;
	int n = r - l + 1;
	while (k < 13) {
		if (POWER[k] > n)
			break;
		k++;
	}
	int baseNum = POWER[k] - 1 - n;
	int baseHalfNum = POWER[k - 2];
	if (baseNum <= baseHalfNum)
		l_t += baseNum;
	else {
		l_t += baseHalfNum;
		r_t -= (baseNum - baseHalfNum);
	}
	int mid = (r_t - l_t) / 2 + l_t;
	level[index] = num[mid];
	find(l, mid - 1, 2 * index + 1);
	find(mid + 1, r, 2 * index + 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), comp);
	find(0, n - 1, 0);
	for (int i = 0; i < n - 1; i++)
		printf("%d ", level[i]);
	printf("%d\n", level[n - 1]);
	return 0;
}
