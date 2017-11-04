#include <stdio.h>

int main()
{
	int i, n, sum = 0;
	int lastfloor = 0, nowfloor;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &nowfloor);
		if (nowfloor > lastfloor)
			sum += (5 + (nowfloor - lastfloor) * 6);
		else
			sum += (5 + (lastfloor - nowfloor) * 4);
		lastfloor = nowfloor;
	}
	printf("%d\n", sum);
	return 0;
}
