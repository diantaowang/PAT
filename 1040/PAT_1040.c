#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

int longest(char *s, int l, int r, int num)
{
	int len = num;
	while (s[l] == s[r]) {
		len += 2;
		if (l > 0 && r < n - 2) {
			l--;
			r++;
		} else
			break;
	}
	return len;
}

int main()
{
	char s[1010];
	fgets(s, 1010, stdin);
	n = (int)strlen(s);
	int max = 1;
	for (int i = 1; i < n - 1; i++) {
		int len = -1, l, r;
		l = i - 1;
		r = i + 1;
		if (s[l] == s[r])
			len = longest(s, l, r, 1);
		if (len > max)
			max = len;
		if (s[l] == s[i] || s[r] == s[i]) {
			if (s[l] == s[i])
				r = i;
			else
				l = i;
			len = longest(s, l, r, 0);
		}
		if (len > max)
			max = len;
	}
	printf("%d\n", max);
	return 0;
}
