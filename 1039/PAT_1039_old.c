#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	char id[5];
	int num;
	int course[20];
} node;

typedef struct _record {
	int num;
	char stdnt[210][5];
} record;

typedef struct _name {
	char id[5];
} name;

int comp(const void *a, const void *b)
{
	int flag = strcmp(((node *) a)->id, ((node *) b)->id);
	if (flag > 0)
		return 1;
	else
		return -1;
}

int find(node * s, char key[], int l, int r)
{
	if (l > r)
		return -1;
	int mid = (l + r) / 2;
	int flag = strcmp(key, s[mid].id);
	if (flag == 0)
		return mid;
	else if (flag < 0)
		return find(s, key, l, mid - 1);
	else
		return find(s, key, mid + 1, r);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	node *student = (node *) malloc(sizeof(node) * n);
	name *query = (name *) malloc(sizeof(name) * n);
	record *course = (record *) malloc(sizeof(record) * (k + 1));
	for (int i = 1; i <= k; i++) {
		int course_id, num;
		scanf("%d %d", &course_id, &num);
		course[course_id].num = num;
		for (int j = 0; j < num; j++)
			scanf("%s", course[course_id].stdnt[j]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", query[i].id);
		strcpy(student[i].id, query[i].id);
	}
	qsort(student, n, sizeof(node), comp);
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < course[i].num; j++) {
			int index = find(student, course[i].stdnt[j], 0, n - 1);
			student[index].course[student[index].num] = i;
			student[index].num++;
		}
	}
	for (int i = 0; i < n; i++) {
		int index = find(student, query[i].id, 0, n - 1);
		int num = student[index].num;
		printf("%s %d", query[i].id, num);
		if (num != 0) {
			for (int i = 0; i < num; i++)
				printf(" %d", student[index].course[i]);
		}
		printf("\n");
	}
	return 0;
}
