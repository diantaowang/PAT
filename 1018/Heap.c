#include <stdio.h>

#define PARENT(i) ((i-1)>>1)
#define LEFT(i)   (i<<1)
#define RIGHT(i)  ((i<<1)+1)

int N = 10;
int HeapSize = 10;

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void Min_Heapify(int A[], int i)
{
	int index = i + 1, min;
	int l = LEFT(index);
	int r = RIGHT(index);
	if (l <= HeapSize && A[l - 1] < A[i])
		min = l - 1;
	else
		min = i;
	if (r <= HeapSize && A[r - 1] < A[min])
		min = r - 1;
	if (min != i) {
		swap(&A[i], &A[min]);
		Min_Heapify(A, min);
	}
}

void Build_Min_Heap(int A[])
{
	for (int i = N / 2 - 1; i >= 0; i--)
		Min_Heapify(A, i);
}

int Heap_Extract_Max(int A[])
{
	if (HeapSize < 1)
		return -1;
	int min = A[0];
	A[0] = A[HeapSize - 1];
	HeapSize--;
	Min_Heapify(A, 0);
	return min;
}

int Heap_Increase_Key(int A[], int i, int key)
{
	if (key > A[i])
		return -1;
	A[i] = key;
	while (i > 0 && A[PARENT(i)] > A[i]) {
		swap(&A[i], &A[PARENT(i)]);
		i = PARENT(i);
	}
	return 1;
}

int main()
{
	int A[11];
	for (int i = 0; i < 10; i++)
		scanf("%d", &A[i]);
	Build_Min_Heap(A);
	for (int i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");
	int index, key;
	printf("Please input index and key;\n");
	scanf("%d%d", &index, &key);
	Heap_Increase_Key(A, index, key);
	for (int i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", Heap_Extract_Max(A));
	printf("\n");
	return 0;
}
