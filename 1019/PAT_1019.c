#include <stdio.h>

int NUM[31];

int turn(int N, int b)
{
	int i = 0;
	while (N > 0) {
		NUM[i++] = N % b;
		N = N / b;
	}
	return i;
}

int main()
{
	int N, b, count, flag = 0;
	scanf("%d%d", &N, &b);
	count = turn(N, b);
	if (count == 1)
		printf("Yes\n%d\n", NUM[0]);
	else {
		for (int i = 0; i < count / 2; i++) {
			if (NUM[i] != NUM[count - 1 - i]) {
				flag = -1;
				break;
			}
		}
		if (flag == 0)
			printf("Yes\n");
		else
			printf("No\n");
		for (int i = count - 1; i > 0; i--)
			printf("%d ", NUM[i]);
		printf("%d\n", NUM[0]);
	}
	return 0;
}
