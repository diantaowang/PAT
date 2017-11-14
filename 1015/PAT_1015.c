#include <stdio.h>

int Turn(int N, int D)
{
	int i = 0, count, sum = 0, tmp = 1;
	int Num[18];
	while (N > 0) {
		Num[i++] = N % D;
		N = N / D;
	}
	count = i;
	sum = tmp * Num[count - 1];
	for (i = count - 2; i >= 0; i--) {
		tmp *= D;
		sum += tmp * Num[i];
	}
	return sum;
}

int ISPrime(int N)
{
	int i, n = 0;
	for (i = 1; i <= N / 2; i++) {
		if (N % i == 0)
			n++;
	}
	if (n == 1)
		return 1;
	else
		return -1;
}

int main()
{
	int N, D, ReN;
	while (1) {
		scanf("%d", &N);
		if (N < 0)
			break;
		else {
			scanf("%d", &D);
			ReN = Turn(N, D);
			if ((ISPrime(N) == 1) && (ISPrime(ReN) == 1))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
