#include <stdio.h>
#include <string.h>
#include <ctype.h>

char DAY[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main()
{
	char s1[80], s2[80], s3[80], s4[80];
	scanf("%s%s%s%s", s1, s2, s3, s4);
	int i;
	for (i = 0; i < (int)strlen(s1) && i < (int)strlen(s2); i++) {
		if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
			printf("%s ", DAY[s1[i] - 'A']);
			break;
		}
	}
	for (i++; i < (int)strlen(s1) && i < (int)strlen(s2); i++) {
		if (s1[i] == s2[i]) {
			if (s1[i] >= '0' && s1[i] <= '9') {
				printf("%02d:", s1[i] - '0');
				break;
			} else if (s1[i] >= 'A' && s1[i] <= 'N') {
				printf("%02d:", s1[i] - 'A' + 10);
				break;
			}
		}
	}
	for (i = 0; i < (int)strlen(s3) && i < (int)strlen(s4); i++) {
		if (s3[i] == s4[i] && isalpha(s3[i])) {
			printf("%02d\n", i);
			break;
		}
	}
	return 0;
}
