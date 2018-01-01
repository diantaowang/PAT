#include <stdio.h>

int main()
{
	long int N, n;
	long int p[60] = { 0 }, k[60] = { 0 };
	int num = 0;
	scanf("%ld", &N);
	n = N;
	for (long int i = 2; i <= n; i++) {
		while (n > 1) {
			if (n % i == 0) {
				n = n / i;
				int index, find;
				find = 0;
				for (index = 0; index < num; index++) {
					if (p[index] == i) {
						find = 1;
						break;
					}
				}
				if (find == 0) {
					p[index] = i;
					k[index] = 1;
					num++;
				} else {
					k[index]++;
				}
			} else {
				break;
			}
		}
	}
	if (num == 0) {
		printf("1=1\n");
		return 0;
	}
	printf("%ld=", N);
	for (int i = 0; i < num; i++) {
		if (i == num - 1) {
			if (k[i] == 1)
				printf("%ld\n", p[i]);
			else
				printf("%ld^%ld\n", p[i], k[i]);
		} else {
			if (k[i] == 1)
				printf("%ld*", p[i]);
			else
				printf("%ld^%ld*", p[i], k[i]);
		}
	}
	return 0;
}
