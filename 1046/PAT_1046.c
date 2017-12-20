#include <stdio.h>

int main()
{
	int n, m, positive[100010], longest;
	int d = 0, dist[100010];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dist[i]);
		d += dist[i];
		positive[i + 1] = d;
	}
	longest = positive[n + 1];
	positive[1] = 0;
	d = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int src, dst;
		int l1, l2;
		scanf("%d %d", &src, &dst);
		if (src > dst) {
			int t;
			t = src;
			src = dst;
			dst = t;
		}
		l1 = positive[dst] - positive[src];
		l2 = longest - l1;;
		if (l1 < l2)
			printf("%d\n", l1);
		else
			printf("%d\n", l2);
	}
	return 0;
}
