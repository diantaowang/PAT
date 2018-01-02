#include <stdio.h>
#include <string.h>

int change(char *s1, char *s2, int n)
{
	int len, point = 0, pre_num = 0;
	int i = 0, pre_zero = 0, back_zero = 0;
	for (i = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '.') {
			pre_num = i;
			point = 1;
		}
	}
	len = i;
	for (i = 0; i < len; i++) {
		if (s1[i] == '0')
			pre_zero++;
		else
			break;
	}
	if (point == 1) {
		for (int j = i + 1; j < len; j++) {
			if (s1[j] == '0')
				back_zero++;
			else
				break;
		}
	}
	int j = 0;
	for (; j < len; j++) {
		if (s1[j] != '0' && s1[j] != '.')
			break;
	}
	for (i = 0; i < n; j++) {
		if (j < len) {
			if (s1[j] != '.')
				s2[i++] = s1[j];
		} else
			s2[i++] = '0';
	}
	s2[n] = '\0';
	if (point == 0)
		return len - pre_zero;
	else {
		if (pre_zero == pre_num) {
			if (back_zero == 0)
				return 0;
			else
				return 0 - back_zero;
		} else
			return pre_num - pre_zero;
	}
}

int main()
{
	int n, n1 = 0, n2 = 0;
	char s1[110], s2[110];
	char sout1[110], sout2[110];
	scanf("%d %s %s", &n, s1, s2);
	n1 = change(s1, sout1, n);
	n2 = change(s2, sout2, n);
	int same = strcmp(sout1, sout2);
	if (same == 0)
		printf("YES 0.%s*10^%d\n", sout1, n1);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", sout1, n1, sout2, n2);
	return 0;
}
