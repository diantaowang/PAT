#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mysort(int A[], int l, int r)
{
	for (int i = l + 1; i <= r; i++) {
		int num;
		for (int j = i; j > l && A[j - 1] > A[j]; j--) {
			num = A[j];
			A[j] = A[j - 1];
			A[j - 1] = num;
		}
	}
	int mid = l + (r - l) / 2;
	return A[mid];
}

int partition(int A[], int l, int r, int mid)
{
	int i = l - 1;
	for (int j = l; j <= r; j++) {
		if (A[j] <= mid) {
			i++;
			if (i != j) {
				int t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
	return i;
}

int myselect(int A[], int l, int r, int index)
{
	if (l == r)
		return A[l];
	int len = r - l + 1;
	int *medians = (int *)malloc(sizeof(int) * (len / 5 + 1));

	int i, n = 0;
	for (i = l; i + 4 <= r; i += 5)
		medians[n++] = mysort(A, i, i + 4);
	if (i <= r)
		medians[n++] = mysort(A, i, r);
	int mid = myselect(medians, 0, n - 1, (n + 1) / 2);

	free(medians);

	int q = partition(A, l, r, mid);
	int k = q - l + 1;
	if (k == index)
		return A[q];
	else if (k > index)
		return myselect(A, l, q - 1, index);
	else
		return myselect(A, q + 1, r, index - k);
}

int main()
{
	int color[500000], m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n * m; i++)
		scanf("%d", &color[i]);
	//color[i] = rand();
	int mid = (n * m) / 2 + 1;
	printf("%d\n", myselect(color, 0, n * m - 1, mid));
	return 0;
}
