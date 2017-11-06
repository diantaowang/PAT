#include <stdio.h>

int main()
{
	int Grades[2001][10];		
	int A[2001][3] = {0}, C[2001][3] = {0};
	int M[2001][3] = {0}, E[2001][3] = {0};	
	int i, j, n, m;
	double t;
	scanf("%d%d", &n, &m);
	for(i=0; i<n; i++)
	{
		scanf("%d%d%d%d", &Grades[i][0], &Grades[i][1], &Grades[i][2], &Grades[i][3]);
		t = (double)(Grades[i][0] + Grades[i][1] + Grades[i][2] + Grades[i][3]) / 4.0;
		Grades[i][4] = (int)(t + 0.500001);
	}

	return 0;
}
