#include <stdio.h>
#include <stdlib.h>

void double_num(int S[], int D[], int N)
{
	int t, c[30];
	t = 2 * S[N - 1];
	D[N - 1] = t % 10;
	c[N - 1] = t / 10;
	for (int i = N - 2; i >= 0; i--) {
		t = 2 * S[i] + c[i + 1];
		D[i] = t % 10;
		c[i] = t / 10;
	}
}

int comp(const void *a, const void *b)
{
	return *((int *)a) < *((int *)b) ? 1 : -1;
}

int main()
{
	char src[30];
	int S[30], D[30], T[30], i, flag = 0;
	scanf("%s", src);
	S[0] = 0;
	for (i = 0; src[i] != '\0'; i++) {
		S[i + 1] = (int)(src[i] - '0');
	}
	int n = i + 1;
	double_num(S, D, n);
	if (D[0] != 0)
		flag = 1;
	for (i = 0; i < n; i++)
		T[i] = D[i];
	if (flag == 0) {
		qsort(S, n, sizeof(int), comp);
		qsort(T, n, sizeof(int), comp);
		for (i = 0; i < n - 1; i++) {
			if (T[i] != S[i]) {
				flag = 1;
			}
		}
	}
	if (flag == 1)
		printf("No\n");
	else
		printf("Yes\n");
	if (D[0] != 0)
		printf("%d", D[0]);
	for (i = 1; i < n; i++)
		printf("%d", D[i]);
	printf("\n");
	return 0;
}
