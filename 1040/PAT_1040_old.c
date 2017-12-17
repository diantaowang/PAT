#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[1010];
	fgets(s, 1010, stdin);
	int n = (int)strlen(s);
	int max = 1;
	for (int i = 1; i < n; i++) {
		int len = -1, l, r;
		l = i - 1;
		r = i + 1;
		if (s[l] == s[r]) {
			len = 1;
			while (s[l] == s[r]) {
				len += 2;
				if (l > 0 && r < n - 1) {
					l--;
					r++;
				} else
					break;
			}
		}
		if (len > max)
			max = len;
		l = i - 1;
		r = i + 1;
		if (s[l] == s[i] || s[r] == s[i]) {
			len = 0;
			if (s[l] == s[i])
				r = i;
			else
				l = i;
			while (s[l] == s[r]) {
				len += 2;
				if (l > 0 && r < n - 1) {
					l--;
					r++;
				} else
					break;
			}
		}
		if (len > max)
			max = len;
	}
	printf("%d\n", max);
	return 0;
}
