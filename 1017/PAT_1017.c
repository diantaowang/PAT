#include <stdio.h>
#include <stdlib.h>

int CUST[10010], UsedTime[10010];
int Num = 0, WaitTime = 0;

void swap(int* a, int* b)
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

int CalcTime(int T[], int N, int K)
{
	int i = 0, j, id = 0, min, t;
	for(i=0; i<N && CUST[i] <= 61200; i++)
	{
		min = T[0];
		id = 0;
		for(j=1; j<K; j++)
		{
			if(min > T[j])
			{
				min = T[j];
				id = j;
			}
		}
		if(CUST[i] < T[id])
			WaitTime += (T[id] - CUST[i]);
		T[id] += UsedTime[i]*60;
		/*t = T[id] - CUST[i];
		if(t < 0)
			t = 0;
		WaitTime += t;
//		printf("------: %d %d %d %d\n", id, T[id], CUST[i], t);
		T[id] += UsedTime[i]*60;*/
	}
	return i;
}

int main()
{
	int N, K, i, count;
	int d[4], T[101];
	char t[4];
	scanf("%d%d", &N, &K);
	for(i=0; i<N; i++)
	{
		scanf("%d%c%d%c", &d[0], &t[0], &d[1], &t[1]);
		scanf("%d%c%d", &d[2], &t[2], &UsedTime[i]);
		if(UsedTime[i] > 60)
			UsedTime[i] = 60;
		CUST[i] = d[2] + 60*d[1] + 3600*d[0];
	}
	for(i=0; i<K; i++)
		T[i] = 28800;
	QuickSort(CUST, 0, N-1);
	count = CalcTime(T, N, K);
	if(count != 0)
		printf("%.1f\n", (double)WaitTime/(double)count/60.0);
	return 0;
}
