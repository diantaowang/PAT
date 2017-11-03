#include <stdio.h>
#include <stdlib.h>

char str[11][10] =
    { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
"nine" };

int main()
{
	char Num[110];
	int i = 0, sum = 0;

	scanf("%s", Num);
	while (Num[i] != '\0') {
		sum += Num[i++] - '0';
	}
	sprintf(Num, "%d", sum);
	i = 0;
	while (Num[++i] != '\0') {
		printf("%s ", str[Num[i - 1] - '0']);
	}
	printf("%s\n", str[Num[i - 1] - '0']);
	return 0;
}
