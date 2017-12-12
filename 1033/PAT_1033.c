#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int dist;
	double price;
} node;

int comp(const void *a, const void *b)
{
	return ((node *) a)->dist > ((node *) b)->dist ? 1 : -1;
}

int main()
{
	int C, D, Da, N, max_d;
	scanf("%d%d%d%d", &C, &D, &Da, &N);
	node *sta = (node *) malloc(sizeof(node) * (N + 1));
	for (int i = 0; i < N; i++)
		scanf("%lf %d", &sta[i].price, &sta[i].dist);
	sta[N].price = 0;
	sta[N].dist = D;
	max_d = C * Da;
	qsort(sta, N + 1, sizeof(node), comp);
	if (sta[0].dist > 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int h = 0, index = 0, flag;
	double cap_r = 0.0, cap_n = 0.0;
	double p = sta[0].price, cost = 0.0, min_p;
	for (int i = 0; i <= N;) {
		flag = -1;
		min_p = 10000.0;
		for (int j = i + 1; sta[j].dist <= h + max_d; j++) {
			if (sta[j].price < p) {
				index = j;
				flag = 0;
				break;
			} else if (sta[j].price < min_p) {
				min_p = sta[j].price;
				index = j;
				flag = 1;
			}
		}
		if (flag == -1) {
			printf("The maximum travel distance = %.2lf\n",
			       (double)(h + max_d));
			return 0;
		} else if (flag == 0) {
			cap_n = ((double)(sta[index].dist - h)) / Da - cap_r;
			cap_r = 0.0;
		} else if (flag == 1) {
			cap_n = C - cap_r;
			cap_r = C - ((double)(sta[index].dist - h)) / Da;
		}
		i = index;
		cost += cap_n * p;
		p = sta[index].price;
		h = sta[index].dist;
		if (h == D)
			break;
	}
	printf("%.2lf\n", cost);
	return 0;
}
