#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	char s;
	int num, rank;
} node;

node data[80], time[130];
char DAY[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int comp(void const *a, void const *b)
{
	node *p = (node *) a;
	node *n = (node *) b;
	if (p->num != 2)
		return 1;
	else if (n->num != 2)
		return -1;
	else
		return p->rank > n->rank ? 1 : -1;
}

int main()
{
	char s1[80], s2[80], s3[80], s4[80];
	scanf("%s%s%s%s", s1, s2, s3, s4);
	for (int i = 0; i < 60; i++)
		data[i].rank = 100;
	for (int i = 0; i < 130; i++)
		time[i].rank = 100;
	for (int i = 0; i < (int)strlen(s1); i++) {
		int id;
		if (s1[i] >= '0' && s1[i] <= '9') {
			id = s1[i] - '0';
			if (data[id].num == 0) {
				data[id].num = 1;
				data[id].s = s1[i];
				data[id].rank = i;
			}
		} else if (s1[i] >= 'A' && s1[i] <= 'Z') {
			id = s1[i] - 'A' + 10;
			if (data[id].num == 0) {
				data[id].num = 1;
				data[id].s = s1[i];
				data[id].rank = i;
			}
		}
	}
	for (int i = 0; i < (int)strlen(s2); i++) {
		int id;
		if (s2[i] >= '0' && s2[i] <= '9') {
			id = s2[i] - '0';
			if (data[id].num == 1 && data[id].rank <= i) {
				data[id].num++;
				data[id].rank = i;
			}
		} else if (s2[i] >= 'A' && s2[i] <= 'Z') {
			id = s2[i] - 'A' + 10;
			if (data[id].num == 1 && data[id].rank <= i) {
				data[id].num++;
				data[id].rank = i;
			}
		}
	}
	qsort(data, 24, sizeof(node), comp);
	for (int i = 0; i < (int)strlen(s3); i++) {
		int id;
		id = s3[i] - '0';
		if (time[id].num == 0) {
			time[id].num = 1;
			time[id].s = s3[i];
			time[id].rank = i;
		}
	}
	for (int i = 0; i < (int)strlen(s4); i++) {
		int id;
		id = s4[i] - '0';
		if (time[id].num == 1 && time[id].rank <= i) {
			time[id].num++;
			time[id].rank = i;
		}
	}
	int minu = 300;
	for (int i = 0; i < 130; i++) {
		if (minu > time[i].rank && time[i].num == 2)
			minu = time[i].rank;
	}
	int i;
	for (i = 0; i < 24; i++) {
		if (data[i].s >= 'A' && data[i].s <= 'G') {
			printf("%s ", DAY[data[i].s - 'A']);
			break;
		}
	}
	for (int j = i + 1; j < 60; j++) {
		if (data[j].s >= '0' && data[j].s <= '9') {
			printf("%02d:%02d\n", data[j].s - '0', minu);
			break;
		} else if (data[j].s >= 'A' && data[j].s <= 'N') {
			printf("%02d:%02d\n", data[j].s - 'A' + 10, minu);
			break;
		}
	}
	return 0;
}
