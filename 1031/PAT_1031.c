#include <stdio.h>

int main()
{
	int N, i;
	char s[100];
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++) ;
	N = i;
	int a1 = (N + 2) / 3;
	int a2 = (N + 2) - a1 * 2;
	for (i = 0; i < (a1 - 1); i++) {
		printf("%c", s[i]);
		for (int j = 0; j < a2 - 2; j++) {
			printf(" ");
		}
		printf("%c\n", s[N - 1 - i]);
	}
	for (int j = i; j < (i + a2); j++) {
		printf("%c", s[j]);
	}
	printf("\n");
	return 0;
}
