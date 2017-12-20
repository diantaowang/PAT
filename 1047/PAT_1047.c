#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _student {
	char name[5];
	int id;
	int num;
	int course[22];
} student;

typedef struct _course {
	int num;
	char *name[500];
} course;

student R[40010];
course Cour[2600];

int comp(const void *a, const void *b)
{
	student *p, *n;
	p = (student *) a;
	n = (student *) b;
	int flag = strcmp(p->name, n->name);
	if (flag > 0)
		return 1;
	else
		return -1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", R[i].name, &R[i].num);
		for (int j = 0; j < R[i].num; j++)
			scanf("%d", &R[i].course[j]);
	}
	qsort(R, n, sizeof(student), comp);
	int course_id;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < R[i].num; j++) {
			int num;
			course_id = R[i].course[j];
			num = Cour[course_id].num;
			Cour[course_id].name[num] = R[i].name;
			Cour[course_id].num++;
		}
	}
	for (int i = 1; i <= m; i++) {
		int num = Cour[i].num;
		printf("%d %d\n", i, num);
		for (int j = 0; j < num; j++)
			printf("%s\n", Cour[i].name[j]);
	}
	return 0;
}
