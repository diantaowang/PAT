#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct _node{
	int id;
	int num;
} node;

int mysort(node *p[], int l, int r)
{
	for(int i=l+1; i<=r; i++) {
		int num;
		for(int j = i; j > l && p[j-1]->num > p[j]->num; j--) {
			num = p[j]->num;
			p[j]->num = p[j-1]->num;
			p[j-1]->num = num;
		}
	}
	return l + (l + r) / 2;
}

int partition(node *A[], int l, int r)
{
	return 0;
}

int my_select(node *A[], int l, int r, int index)
{
	if(l == r)
		return A[l]->id;
	int i, n = 0;
	node *p[100000];
	for(i=l; i<=r; i+=5) {
		int id;
		id = mysort(A, i, i+4);
		p[n]->id = id;
		p[n]->num = A[id]->num;
		n++;	
	}
	if(i != r + 1) {

	}
	int q = partition(A, l, r);
	int k = q - l + 1;
	if (k == index)
		return A[q]->num;
	else if (k > index)
		return my_select(A, l, q, index);
	else
		return my_select(A, q + 1, r, index - k);
}

int main()
{
	int m, n;
	node color[500000];
	node *p[500000];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n * m; i++) {
		scanf("%d", &color[i].num);
		color[i].id = i;
		p[i] = &color[i];
	}
	/*mysort(p, 0, n*m-1);
	for(int i=0; i<n*m; i++) 
		printf("%d %d\n", color[i].num, color[i].id);*/
	/*int mid = (n * m) / 2 + 1;
	printf("%d\n", my_select(color, 0, n*m-1, mid));*/
	return 0;
}
