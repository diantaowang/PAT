#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _record {
	int id;
	char name[10];
	int grade;
} record;

int comp(const void *a, const void *b)
{
	return ((record *) a)->id > ((record *) b)->id ? 1 : -1;
}

int comp2(const void *a, const void *b)
{
	record *p, *n;
	p = (record *) a;
	n = (record *) b;
	int flag = strcmp(p->name, n->name);
	if (flag > 0)
		return 1;
	else if (flag == 0 && p->id > n->id)
		return 1;
	else
		return -1;
}

int comp3(const void *a, const void *b)
{
	record *p, *n;
	p = (record *) a;
	n = (record *) b;
	if (p->grade > n->grade)
		return 1;
	else if (p->grade == n->grade && p->id > n->id)
		return 1;
	else
		return -1;
}

int main()
{
	int N, C;
	scanf("%d%d", &N, &C);
	record *R = (record *) malloc(sizeof(record) * N);
	for (int i = 0; i < N; i++)
		scanf("%d%s%d", &R[i].id, R[i].name, &R[i].grade);
	if (C == 1)
		qsort(R, N, sizeof(record), comp);
	else if (C == 2)
		qsort(R, N, sizeof(record), comp2);
	else if (C == 3)
		qsort(R, N, sizeof(record), comp3);
	for (int i = 0; i < N; i++)
		printf("%06d %s %d\n", R[i].id, R[i].name, R[i].grade);
	return 0;
}
