#include <stdio.h>

int N;

void creat_new_num(int Num[])
{
	int neg[100], c[100];
	for (int i = 0; i < N; i++) {
		neg[i] = Num[N - 1 - i];
	}
	int t = neg[N - 1] + Num[N - 1];
	Num[N - 1] = t % 10;
	c[N - 1] = t / 10;
	for (int i = N - 2; i >= 0; i--) {
		t = neg[i] + Num[i] + c[i + 1];
		Num[i] = t % 10;
		c[i] = t / 10;
	}
	if (c[0] > 0) {
		for (int i = N; i > 0; i--) {
			Num[i] = Num[i - 1];
		}
		Num[0] = c[0];
		N++;
	}
}

int is_palindromic_num(int Num[])
{
	for (int i = 0; i < (N + 1) / 2; i++) {
		if (Num[i] != Num[N - 1 - i]) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int K, Num[100], i;
	char num_tmp[100];
	scanf("%s%d", num_tmp, &K);
	for (i = 0; num_tmp[i] != '\0'; i++) {
		Num[i] = num_tmp[i] - '0';
	}
	N = i;
	if (is_palindromic_num(Num) == 1) {
		for (int j = 0; j < N; j++) {
			printf("%d", Num[j]);
		}
		printf("\n0\n");
		return 0;
	}
	for (i = 0; i < K; i++) {
		creat_new_num(Num);
		if (is_palindromic_num(Num) == 1 || i == K - 1) {
			for (int j = 0; j < N; j++) {
				printf("%d", Num[j]);
			}
			printf("\n%d\n", i + 1);
			return 0;
		}
	}
	return 0;
}
