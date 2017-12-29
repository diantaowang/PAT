#include <stdio.h>

int main()
{
	int n, m, w[1010], new_e[1010], old_e[1010];
	int rank[1010] = { 1 };
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &old_e[i]);
	int *new_p = new_e;
	int *old_p = old_e;
	int num = n, max = -1, index = 0;
	while (num > 1) {
		int num_n = 0, count;
		count = num / m;
		if (num % m > 0)
			count++;
		for (int i = 0; i < num; i++) {
			if (max < w[old_p[i]]) {
				max = w[old_p[i]];
				index = old_p[i];
			}
			if (i == num - 1 || (i + 1) % m == 0) {
				new_p[num_n++] = index;
				max = -1;
				index = 0;
			}
			rank[old_p[i]] = count + 1;
		}
		if (num_n == 1)
			rank[new_p[0]] = 1;
		num = num_n;
		num_n = 0;
		int *t = new_p;
		new_p = old_p;
		old_p = t;
	}
	for (int i = 0; i < n - 1; i++)
		printf("%d ", rank[i]);
	printf("%d\n", rank[n - 1]);
	return 0;
}
