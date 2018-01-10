#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	double num;
	double price;
	double unit;
} node;

node cake[1010];

int comp(const void *a, const void *b)
{
	return ((node *) a)->unit < ((node *) b)->unit ? 1 : -1;
}

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%lf", &cake[i].num);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &cake[i].price);
		cake[i].unit = cake[i].price / cake[i].num;
	}
	qsort(cake, n, sizeof(node), comp);
	double sum = 0.0, profit = 0.0;
	for (int i = 0; i < n; i++) {
		sum += cake[i].num;
		if (sum > d) {
			int part = d + cake[i].num - sum;
			profit += part * cake[i].unit;
			break;
		} else {
			profit += cake[i].price;
			if (sum - d > -0.000001 && sum - d < 0.000001)
				break;
		}
	}
	printf("%.2f\n", profit);
	return 0;
}
