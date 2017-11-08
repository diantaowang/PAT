#include <stdio.h>

char Str[5] = { 'A', 'C', 'M', 'E' };

typedef struct _Record {
	int ID;
	int Grades;
} Record;

void BestestRank(int A[], int *b, char *c)
{
	int i;
	*b = A[0];
	*c = 'A';
	for (i = 1; i < 4; i++) {
		if (A[i] < *b) {
			*b = A[i];
			*c = Str[i];
		}
	}
}

void swap(Record * src, Record * dst)
{
	int id, grade;
	id = src->ID;
	src->ID = dst->ID;
	dst->ID = id;
	grade = src->Grades;
	src->Grades = dst->Grades;
	dst->Grades = grade;
}

int FindID(int id, Record A[], int n, int *rank)
{
	int i, j;
	for (i = 0; i < n; i++) {
		if (id == A[i].ID) {
			j = i;
			while (A[j].Grades == A[j - 1].Grades) {
				j--;
			}
			*rank = j + 1;
			return 1;
		}
	}
	return -1;
}

int Partiton(Record A[], int p, int r)
{
	int x = A[r].Grades;
	int i = p - 1, j;
	for (j = p; j < r; j++) {
		if (A[j].Grades >= x) {
			i++;
			swap(&A[j], &A[i]);
		}
	}
	swap(&A[r], &A[i + 1]);
	return (i + 1);
}

void QuickSort(Record A[], int p, int r)
{
	int q;
	if (p >= r)
		return;
	else {
		q = Partiton(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int main()
{
	Record A[2001], C[2001], M[2001], E[2001];
	int stdts[2001];
	int i, n, m, id, NoList;
	int BRank[5];
	int BestRank;
	char BestCourse;
	double t;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &id);
		A[i].ID = id;
		C[i].ID = id;
		M[i].ID = id;
		E[i].ID = id;
		scanf("%d%d%d", &C[i].Grades, &M[i].Grades, &E[i].Grades);
		t = (double)(C[i].Grades + M[i].Grades + E[i].Grades) / 3.0;
		A[i].Grades = (int)(t + 0.500001);
	}
	for (i = 0; i < m; i++)
		scanf("%d", &stdts[i]);
	QuickSort(A, 0, n - 1);
	QuickSort(C, 0, n - 1);
	QuickSort(M, 0, n - 1);
	QuickSort(E, 0, n - 1);
	for (i = 0; i < m; i++) {
		NoList = FindID(stdts[i], A, n, &BRank[0]);
		FindID(stdts[i], C, n, &BRank[1]);
		FindID(stdts[i], M, n, &BRank[2]);
		FindID(stdts[i], E, n, &BRank[3]);
		if (NoList == -1)
			printf("N/A\n");
		else {
			BestestRank(BRank, &BestRank, &BestCourse);
			printf("%d %c\n", BestRank, BestCourse);
		}
	}
	return 0;
}
