#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	long long a, b, sum, c;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		sum = a + b;
		if (a > 0 && b > 0 && sum <= 0)
			printf("Case #%d: true\n", i);
		else if (a < 0 && b < 0 && sum >= 0)
			printf("Case #%d: false\n", i);
		else if (sum > c)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	return 0;
}
