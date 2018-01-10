#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int num;
	double price;
	double unit;
} node;

node cake[1010];

int comp(const void *a, const void *b)
{
	node *p = (node *)a;
	node *r = (node *)b;
		
	
}

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	for(int i=0; i<n; i++) 
		scanf("%d", &cake[i].num);
	for(int i=0; i<n; i++) {
		scanf("%lf", &cake[i].price);
		cake[i].unit = cake[i].price / cake[i].num;
	}
	qsort(cake, n, sizeof(node), comp);
	return 0;
}
