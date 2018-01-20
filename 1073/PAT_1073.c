#include <stdio.h>
#include <string.h>

int main()
{
	char s[20010];
	scanf("%s", s);
	int len = strlen(s);
	int n = 0, base = 1, i;
	for (i = len - 1; s[i] != '-' && s[i] != '+'; i--) {
		n += (s[i] - '0') * base;
		base *= 10;
	}
	if (s[0] == '-')
		printf("%c", '-');
	if (s[i] == '-') {
		if (n == 0) {
			int j = 1;
			while (s[j] != 'E')
				printf("%c", s[j++]);
		} else {
			printf("0.");
			for (int j = 1; j < n; j++)
				printf("0");
			for (int j = 1; s[j] != 'E'; j++) {
				if (s[j] != '.')
					printf("%c", s[j]);
			}
		}
	} else {
		int pre_num = 0;
		while (s[pre_num] != 'E')
			pre_num++;
		s[2] = s[1];
		for (int j = 2; j <= n + 2; j++) {
			if (j < pre_num)
				printf("%c", s[j]);
			else
				printf("0");
		}
		if (pre_num > n + 3) {
			printf(".");
			for (int j = n + 3; j < pre_num; j++)
				printf("%c", s[j]);
		}
	}
	printf("\n");
	return 0;
}
