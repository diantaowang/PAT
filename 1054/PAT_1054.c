#include <stdio.h>

int main()
{
	int m, n, dominant;
	scanf("%d%d", &m, &n);
	int num = 0, color[500000];
	for (int i = 0; i < m * n; i++)
		scanf("%d", &color[i]);
	for (int i = 0; i < m * n; i++) {
		/*if(num == 0) 
		   dominant = color[i];
		   else if(color[i] == dominant)
		   num++;
		   else
		   num--; */
		if (num == 0) {
			dominant = color[i];
			num = 1;
		} else if (dominant == color[i])
			num++;
		else
			num--;
	}
	printf("%d\n", dominant);
}
