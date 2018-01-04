#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int m, n;
	int color[500000];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n * m; i++)
		scanf("%d", &color[i]);
	sort(color, color + n * m);
	printf("%d\n", color[n*m / 2]);
	return 0;
}
