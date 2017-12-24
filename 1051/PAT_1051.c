#include <stdio.h>

typedef struct _stack {
	int index;
	int num[1010];
} stack;

stack s;

int main()
{
	int m, n, k, dat = 1;
	int num[1010];
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &num[j]);
		}
		int index, flag;
		index = 0;
		s.index = 0;
		flag = 0;
		dat = 1;
		while (index < n) {
			if (dat <= n) {
				if (s.index == 0) {
					s.num[s.index] = dat;
					s.index++;
					dat++;
				} else if (s.index == m) {
					if (num[index] == s.num[s.index - 1]) {
						s.index--;
						index++;
					} else {
						flag = 1;
						printf("NO\n");
						break;
					}
				} else {
					if (num[index] == s.num[s.index - 1]) {
						s.index--;
						index++;
					} else {
						s.num[s.index] = dat;
						s.index++;
						dat++;
					}
				}
			} else {
				if (num[index] == s.num[s.index - 1]) {
					s.index--;
					index++;
				} else {
					flag = 1;
					printf("NO\n");
					break;
				}
			}
		}
		if (index == n && flag == 0)
			printf("YES\n");
	}
	return 0;
}
