#include <stdio.h>
#include <malloc.h>

int MaxSum = -2 ^ 31;

void SlowMaxSubseqSum(int *A, int N, int B[])
{
	int ThisSum = 0;
	int i, j;
	for (i = 0; i < N; i++) {
		ThisSum = 0;
		for (j = i; j < N; j++) {
			ThisSum += *(A + j);
			if (ThisSum > MaxSum) {
				MaxSum = ThisSum;
				B[0] = *(A + i);
				B[1] = *(A + j);
			}
		}
	}
}

void FastMaxSubseqSum(int *A, int N, int B[])
{
	int i, count = 0, ThisSum = 0;
	B[0] = *A, B[1] = *A;
	for (i = 0; i < N; i++) {
		ThisSum += *(A + i);
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			B[1] = *(A + i);
			B[0] = *(A + i - count);
		}
		count++;
		if (ThisSum < 0) {
			ThisSum = 0;
			count = 0;
		}
	}
}

int main()
{
	int i, K;
	int *ptr, B[3];
	scanf("%d", &K);
	ptr = (int *)malloc(sizeof(int) * K);
	for (i = 0; i < K; i++)
		scanf("%d", ptr + i);
	FastMaxSubseqSum(ptr, K, B);
	if (MaxSum < 0)
		printf("0 %d %d\n", *ptr, *(ptr + K - 1));
	else
		printf("%d %d %d\n", MaxSum, B[0], B[1]);
	return 0;
}
