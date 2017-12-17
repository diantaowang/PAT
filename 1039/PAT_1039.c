#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int num;
	int course[10];
} node;

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b);
}

/*int convert(char s[])
{
	int id;
	id = 676 * (s[0] - 'A') + 26 * (s[1] - 'A') + (s[2] - 'A');
	id = (id * 10 + (s[3] - '0'));
	return id;
}*/

int convert(char s[])
{
	int id;
	id = 17576 * (s[0] - 'A') + 676 * (s[1] - 'A');
	id += (26 * (s[2] - 'A') + (s[3] - '0'));
	return id;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	node *student = (node *) malloc(sizeof(node) * 460000);
	for (int i = 0; i < k; i++) {
		int course_id, num;
		scanf("%d %d", &course_id, &num);
		for (int j = 0; j < num; j++) {
			char s[5];
			scanf("%s", s);
			int id = convert(s);
			student[id].course[student[id].num] = course_id;
			student[id].num++;
		}
	}
	for (int i = 0; i < n; i++) {
		char s[5];
		scanf("%s", s);
		int id = convert(s);
		int num = student[id].num;
		printf("%s %d", s, num);
		int *addr = student[id].course;
		qsort(addr, num, sizeof(int), comp);
		for (int i = 0; i < num; i++)
			printf(" %d", student[id].course[i]);
		printf("\n");
	}
	free(student);
	return 0;
}
