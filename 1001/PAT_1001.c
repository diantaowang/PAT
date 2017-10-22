#include <stdio.h>

int main()
{
	int a, b, c;
	int i = 0, count = 0;
	unsigned char string[10];
	scanf("%d %d", &a, &b);
	c = a + b;
	if (c == 0) {
		printf("0");
	} else if (c < 0) {
		c = -c;
		printf("-");
	}
	while (c > 0) {
		count++;
		string[i++] = c % 10 + '0';
		c = c / 10;
		if (count % 3 == 0 && c > 0) {
			string[i++] = ',';
		}
	}
	string[i] = '\n';
	while ((--i) >= 0) {
		printf("%c", string[i]);
	}
	printf("\n");
	return 0;
}
