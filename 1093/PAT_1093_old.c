#include <stdio.h>
#include <malloc.h>

int main()
{
	char S[100001];
	int PA[100001];
	int *AT;
	int num = 0, N, n, i, count = 0;
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
	n = count - 1;
	AT = (int *)malloc(sizeof(int) * count);
	for (i = N - 1; i >= 0; i--) {
		if (S[i] == 'A')
			AT[n--] = num;
		else if (S[i] == 'T')
			num++;
	}
	for (i = 0; i < count; i++)
		sum += PA[i] * AT[i];
	printf("%lld\n", sum % 1000000007);
	return 0;
}
