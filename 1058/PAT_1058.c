#include <stdio.h>

int main()
{
	int a[4], b[4], c[4];
	int num[4] = { 10000001, 17, 29 };
	char s;
	for (int i = 0; i < 3; i++)
		scanf("%d%c", &a[i], &s);
	for (int i = 0; i < 3; i++)
		scanf("%d%c", &b[i], &s);
	int carry = 0;
	for (int i = 2; i >= 1; i--) {
		c[i] = (a[i] + b[i] + carry) % num[i];
		carry = (a[i] + b[i] + carry) / num[i];
	}
	c[0] = a[0] + b[0] + carry;
	printf("%d.%d.%d\n", c[0], c[1], c[2]);
	return 0;
}
