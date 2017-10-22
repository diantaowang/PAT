#include <stdio.h>

#define MaxNum 11

typedef struct _Node {
	unsigned int index;
	float coeff;
} Node;

void InsertionSort(Node A[], Node newElement, unsigned int N);

Node k1Ploynomials[MaxNum];
Node k2Ploynomials[MaxNum];
Node Ploynomials[2 * MaxNum];

int main()
{
	unsigned int k1, k2;
	unsigned int i = 0;
	unsigned int count1 = 0, count2 = 0;
	Node newElement;

	scanf("%u", &k1);
	while (k1--) {
		count1++;
		scanf("%d %f", &newElement.index, &newElement.coeff);
		InsertionSort(k1Ploynomials, newElement, count1);
	}

	scanf("%u", &k2);
	while (k2--) {
		count2++;
		scanf("%d %f", &newElement.index, &newElement.coeff);
		InsertionSort(k2Ploynomials, newElement, count2);
	}

	for (k1 = 0, k2 = 0;
	     k1Ploynomials[k1].index != 0 || k2Ploynomials[k2].index != 0;) {
		if (k1Ploynomials[k1].index > k2Ploynomials[k2].index) {
			Ploynomials[i++] = k1Ploynomials[k1++];
		} else if (k1Ploynomials[k1].index == k2Ploynomials[k2].index) {
			Ploynomials[i].coeff =
			    k1Ploynomials[k1].coeff + k2Ploynomials[k2].coeff;
			if (Ploynomials[i].coeff != 0) {
				Ploynomials[i++].index =
				    k1Ploynomials[k1].index;
			}
			k1++;
			k2++;
		} else {
			Ploynomials[i++] = k2Ploynomials[k2++];
		}
	}

	if (k1Ploynomials[k1].coeff != 0 || k2Ploynomials[k2].coeff != 0) {
		Ploynomials[i].coeff =
		    k1Ploynomials[k1].coeff + k2Ploynomials[k2].coeff;
		if (Ploynomials[i].coeff != 0) {
			Ploynomials[i].index = 0;
			i++;
		}
	}

	unsigned int j;
	printf("%d", i);
	for (j = 0; j < i; j++) {
		printf(" %d %.1f", Ploynomials[j].index, Ploynomials[j].coeff);
	}
	printf("\n");

	return 0;
}

void InsertionSort(Node A[], Node newElement, unsigned int N)
{
	unsigned int i = 0, j = 0;

	if (newElement.coeff != 0) {
		for (i = 0; i < N && newElement.index < A[i].index; i++) ;

		for (j = N - 1; j > i; j--) {
			A[j] = A[j - 1];
		}

		A[i] = newElement;
	}
}
