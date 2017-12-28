#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	int money, age;
	char name[10];
} node;

typedef struct _record {
	int num;
	node people[100010];
} record;

record ages[210];

int comp(const void *a, const void *b)
{
	node *p, *n;
	p = (node *) a;
	n = (node *) b;
	if (p->money < n->money)
		return 1;
	else if (p->money == n->money) {
		if (strcmp(p->name, n->name) > 0)
			return 1;
	}
	return -1;
}

int comp2(const void *a, const void *b)
{
	node *p, *n;
	p = (node *) a;
	n = (node *) b;
	if (p->money < n->money)
		return 1;
	else if (p->money == n->money) {
		if (p->age > n->age)
			return 1;
		else if (p->age == n->age) {
			if (strcmp(p->name, n->name) > 0)
				return 1;
		}
	}
	return -1;
}

int main()
{
	int n, k;
	node *rang[110];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		char name[10];
		int id, money, num;
		scanf("%s %d %d", name, &id, &money);
		num = ages[id].num;
		strcpy(ages[id].people[num].name, name);
		ages[id].people[num].money = money;
		ages[id].people[num].age = id;
		ages[id].num++;
	}
	for (int i = 0; i <= 200; i++) {
		if (ages[i].num != 0)
			qsort(ages[i].people, ages[i].num, sizeof(node), comp);
	}
	for (int i = 0; i < k; i++) {
		int num, min, max;
		scanf("%d%d%d", &num, &min, &max);
		for (int i = 0; i < num; i++)
			rang[i] = NULL;
		for (int i = min; i <= max; i++) {
			int count;
			count = 0;
			if (ages[i].num != 0) {
				for (int j = 0; j < ages[i].num; ) {
					if (rang[count] == NULL) {
						rang[count] = &ages[i].people[j];
						count++;
						j++;
					} else {
						int flag = comp2(rang[count], &ages[i].people[j]);
						if (flag == 1) {
							for (int k = num - 1; k > count; k--)
								rang[k] = rang[k - 1];
							rang[count] = &ages[i].people[j];
							count++;
							j++;
						} else
							count++;
					}
					if (count >= num)
						break;
				}
			}
		}
		printf("Case #%d:\n", i+1);
		if(rang[0] == NULL)
			printf("None\n");
		else {
			for(int j=0; j<num; j++) {
				if(rang[j] != NULL)
					printf("%s %d %d\n", rang[j]->name, rang[j]->age, rang[j]->money);
			}
		}
	}
	return 0;
}
