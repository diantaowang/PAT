#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int m, n, num = 0;
	int color[500000];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &color[num++]);
	}
	sort(color, color + num);
	printf("%d\n", color[num / 2]);
	return 0;
}
