#include <stdio.h>

int CUST[10010], UsedTime[10010];
int WaitTime = 0;

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int Partiton(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1, j;
	for (j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(&A[j], &A[i]);
			swap(&UsedTime[j], &UsedTime[i]);
		}
	}
	swap(&A[r], &A[i + 1]);
	swap(&UsedTime[r], &UsedTime[i + 1]);
	return (i + 1);
}

void QuickSort(int A[], int p, int r)
{
	int q;
	if (p >= r)
		return;
	else {
		q = Partiton(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

void CalcTime(int T[], int N, int K)
{
	int i = 0, j, id = 0, min;
	for (i = 0; i < N; i++) {
		min = T[0];
		id = 0;
		for (j = 1; j < K; j++) {
			if (min > T[j]) {
				min = T[j];
				id = j;
			}
		}
		if (CUST[i] <= T[id]) {
			WaitTime += (T[id] - CUST[i]);
			T[id] += UsedTime[i] * 60;
		} else
			T[id] = CUST[i] + UsedTime[i] * 60;
	}
}

int main()
{
	int N, K, i, j = 0, tmp;
	int d[4], T[101];
	char t[4];
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%d%c%d%c", &d[0], &t[0], &d[1], &t[1]);
		scanf("%d%c%d", &d[2], &t[2], &UsedTime[j]);
		tmp = d[2] + 60 * d[1] + 3600 * d[0];
		if (tmp <= 61200) {
			CUST[j] = tmp;
			j++;
		}
	}
	N = j;
	for (i = 0; i < K; i++)
		T[i] = 28800;
	QuickSort(CUST, 0, N - 1);
	CalcTime(T, N, K);
	if (N != 0)
		printf("%.1f\n", (double)WaitTime / (double)N / 60.0);
	else
		printf("0.0\n");
	return 0;
}
