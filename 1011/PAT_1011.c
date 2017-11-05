#include <stdio.h>

char STR[4] = { 'W', 'T', 'L' };

int main()
{
	double tmp, profit, WTL[4] = { 0.0 };
	char str[4];
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%lf", &tmp);
			if (tmp > WTL[i]) {
				WTL[i] = tmp;
				str[i] = STR[j];
			}
		}
	}
	profit = (WTL[0] * WTL[1] * WTL[2] * 0.65 - 1) * 2;
	tmp = profit * 100 + 0.5001;
//      printf("%.14lf\n", profit);
	profit = (int)tmp / 100.0;
	printf("%c %c %c %.2lf\n", str[0], str[1], str[2], profit);
	return 0;
}
