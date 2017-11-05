#include <stdio.h>
#include <math.h>

typedef struct _Node {
	int expon;
	double coeff;
} PolyNode;

PolyNode C[110];

int FindPostion(int index, int n, int *count)
{
	int i, j;
	for (i = 0; i < n; i++) {
		if (index == C[i].expon) {
			if (!index)
				(*count)++;
			return i;
		} else if (index > C[i].expon) {
			j = i;
			(*count)++;
			while (C[j++].expon != 0) ;
			for (; j > i; j--) {
				C[j].coeff = C[j - 1].coeff;
				C[j].expon = C[j - 1].expon;
			}
			C[i].coeff = 0.0;
			C[i].expon = 0;
			return i;
		}
	}
	return -1;
}

int main()
{
	PolyNode A[11], B[11];
	int i, j, k1, k2, n = 0;
	int postion, count = 0, Num = 0;
	scanf("%d", &k1);
	for (i = 0; i < k1; i++) {
		scanf("%d", &A[i].expon);
		scanf("%lf", &A[i].coeff);
	}
	scanf("%d", &k2);
	for (i = 0; i < k2; i++) {
		scanf("%d", &B[i].expon);
		scanf("%lf", &B[i].coeff);
	}
	for (i = 0; i < k1; i++) {
		for (j = 0; j < k2; j++) {
			n++;
			postion =
			    FindPostion(A[i].expon + B[j].expon, n, &count);
			C[postion].expon = A[i].expon + B[j].expon;
			C[postion].coeff += A[i].coeff * B[j].coeff;
		}
	}
	for (i = 0; i < count; i++)
		if (C[i].coeff == 0)
			Num++;
	printf("%d ", count - Num);
	for (i = 0; i < count - 1; i++) {
		if (C[i].coeff != 0)
			printf("%d %.1lf ", C[i].expon, C[i].coeff);
	}
	if (C[i].coeff != 0)
		printf("%d %.1lf\n", C[i].expon, C[i].coeff);
	return 0;
}
