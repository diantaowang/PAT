#include <stdio.h>
#include <stdlib.h>

int random_int(int minNum, int maxNum)
{
	int delt = maxNum - minNum;
	if(delt <= RAND_MAX)
		return rand() % (delt+1) + minNum;
   	else
		return rand()*delt / RAND_MAX + minNum;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d %d\n", n, n*(n-1)/2);
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			printf("%d %d %d %d\n", i, j, random_int(1,50), random_int(10, 50));
		}
	}
	return 0;
}
