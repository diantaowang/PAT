#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void exchange(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int partition(int *A, int l, int r)
{
	int rand_num = rand() % (r - l + 1) + l;
	exchange(&A[rand_num], &A[r]);
	int x = A[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (A[j] <= x) {
			i++;
			if (i != j)
				exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i + 1], &A[r]);
	return i + 1;
}

int my_select(int *A, int l, int r, int index)
{
	if (l == r)
		return A[l];
	int q = partition(A, l, r);
	int k = q - l + 1;
	if (k == index)
		return A[q];
	else if (k > index)
		return my_select(A, l, q - 1, index);
	else
		return my_select(A, q + 1, r, index - k);
}

int main()
{
	int m, n, color[500000];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n * m; i++)
		scanf("%d", &color[i]);
	int mid = (n * m) / 2 + 1;
	printf("%d\n", my_select(color, 0, n * m - 1, mid));
	return 0;
}
