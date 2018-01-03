#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int id;
	int virtue;
	int talent;
	int grade;
} node;

node all[100010], sage[100010];
node noble[100010], fool[100010], small[100010];

int comp(const void *a, const void *b)
{
	node *p = (node *) a;
	node *n = (node *) b;
	if (p->grade < n->grade)
		return 1;
	else if (p->grade == n->grade) {
		if (p->virtue < n->virtue)
			return 1;
		else if (p->virtue == n->virtue && p->id > n->id)
			return 1;
	}
	return -1;
}

void add_node(node * A, int *num, node * a)
{
	A[*num].id = a->id;
	A[*num].virtue = a->virtue;
	A[*num].talent = a->talent;
	A[*num].grade = a->virtue + a->talent;
	(*num)++;
}

int main()
{
	int n, l, h;
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	scanf("%d%d%d", &n, &l, &h);
	for (int i = 0; i < n; i++) {
		node a;
		scanf("%d%d%d", &a.id, &a.virtue, &a.talent);
		if (a.virtue >= l && a.talent >= l) {
			if (a.virtue >= h && a.talent >= h)
				add_node(sage, &n1, &a);
			else if (a.virtue >= h && a.talent < h)
				add_node(noble, &n2, &a);
			else if (a.virtue < h && a.talent < h
				 && a.virtue >= a.talent)
				add_node(fool, &n3, &a);
			else
				add_node(small, &n4, &a);
		}
	}
	qsort(sage, n1, sizeof(node), comp);
	qsort(noble, n2, sizeof(node), comp);
	qsort(fool, n3, sizeof(node), comp);
	qsort(small, n4, sizeof(node), comp);
	printf("%d\n", n1 + n2 + n3 + n4);
	for (int i = 0; i < n1; i++)
		printf("%08d %d %d\n", sage[i].id, sage[i].virtue,
		       sage[i].talent);
	for (int i = 0; i < n2; i++)
		printf("%08d %d %d\n", noble[i].id, noble[i].virtue,
		       noble[i].talent);
	for (int i = 0; i < n3; i++)
		printf("%08d %d %d\n", fool[i].id, fool[i].virtue,
		       fool[i].talent);
	for (int i = 0; i < n4; i++)
		printf("%08d %d %d\n", small[i].id, small[i].virtue,
		       small[i].talent);
	return 0;
}
