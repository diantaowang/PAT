#include <stdio.h>

int M[210], L[10010];
int MAX[210], P[210];

int main()
{
	int n, m, l, num = 0, max;
	int max_len = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &M[i]);
		P[M[i]] = i;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		int t;
		scanf("%d", &t);
		if (t <= n && P[t] != 0)
			L[num++] = t;
	}
	int index;
	for (int i = num - 1; i >= 0; i--) {
		max = 0;
		index = P[L[i]];
		for (int j = index; j <= m; j++) {
			if (max < MAX[j])
				max = MAX[j];
		}
		MAX[index] = max + 1;
		if (max_len < MAX[index])
			max_len = MAX[index];
	}
	printf("%d\n", max_len);
	return 0;
}
