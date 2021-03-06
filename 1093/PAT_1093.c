#include <stdio.h>
#include <malloc.h>

int main()
{
	char S[100001];
	int PA[100001];
	int num = 0, N, i, count = 0;
	long long int sum = 0;
	scanf("%s", S);
	for (i = 0; i < 100001 && S[i] != '\0'; i++) {
		if (S[i] == 'A')
			PA[count++] = num;
		else if (S[i] == 'P')
			num++;
	}
	N = i;
	num = 0;
	for (i = N - 1; i >= 0; i--) {
		if (S[i] == 'A')
			sum += PA[--count]*num;
		else if (S[i] == 'T')
			num++;
	}
	printf("%lld\n", sum % 1000000007);
	return 0;
}
