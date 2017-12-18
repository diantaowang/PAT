#include <stdio.h>

typedef struct record {
	int n;
	int index[10000][2];
} record;

record R;

int main()
{
	int n, m, num[100010] = { 0 };
	int start = 1, end = 1;
	int min = 900000000, sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	sum = num[1];
	while (1) {
		if (sum < m) {
			end++;
			sum += num[end];
		} else {
			int t = sum - m;
			if (min > t) {
				min = t;
				R.n = 1;
				R.index[0][0] = start;
				R.index[0][1] = end;
			} else if (min == t) {
				R.index[R.n][0] = start;
				R.index[R.n][1] = end;
				R.n++;
			}
			if (t == 0) {
				end++;
				sum += num[end];
			} else {
				sum -= num[start];
				start++;
			}
		}
		if (end > n)
			break;
	}
	for (int i = 0; i < R.n; i++)
		printf("%d-%d\n", R.index[i][0], R.index[i][1]);
	return 0;
}
