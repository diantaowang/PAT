#include <stdio.h>

char tochar[14] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int main()
{
	int A[4], c = 0;
	char r[8];
	scanf("%d%d%d", &A[0], &A[1], &A[2]);
	for(int i=0; i<3; i++)
	{
		r[c++] = tochar[A[i]/13*13];
		r[c++] = tochar[A[i]%13];
	}
	printf("%s\n", tochar);
	return 0;
}
