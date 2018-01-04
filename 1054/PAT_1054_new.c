#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n, rand_num, num, x;
	int color[500000];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n * m; i++)
		scanf("%d", &color[i]);
	while (1) {
		num = 0;
		rand_num = rand() % (m * n);
		x = color[rand_num];
		for (int i = 0; i < n * m; i++) {
			if (color[i] == x)
				num++;
			if (num >= n * m / 2 + 1)
				break;
		}
		if (num >= n * m / 2 + 1)
			break;
	}
	printf("%d\n", x);
	return 0;
}
