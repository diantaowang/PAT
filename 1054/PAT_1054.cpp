#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int m, n, num = 0;
	int color[500000];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n * m; i++)
		scanf("%d", &color[num++]);
	sort(color, color + num);
	printf("%d\n", color[num / 2]);
	return 0;
}
