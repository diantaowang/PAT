#include <stdio.h>

int next[100010], finish[100010];

int travel(int n, int finish_num)
{
	int start = 1;
	int swap_num = 0;
	while (finish_num < n - 1) {
		if (next[0] != 0) {
			finish_num++;
			int id = next[0];
			finish[id] = 1;
			next[0] = next[id];
		} else {
			while (finish[start++] == 1) ;
			next[0] = next[start - 1];
			next[start - 1] = 0;
		}
		swap_num++;
	}
	return swap_num;
}

int main()
{
	int n, data, finish_num = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		next[data] = i;
		if (data == i && i != 0) {
			finish[i] = 1;
			finish_num++;
		}
	}
	printf("%d\n", travel(n, finish_num));
	return 0;
}
