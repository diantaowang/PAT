#include <stdio.h>
#include <stdlib.h>

typedef struct _record {
	long long int id;
	int score, group, frank, lrank;
} record;

record T[30010];

int comp(const void *a, const void *b)
{
	record *p, *n;
	p = (record *) a;
	n = (record *) b;
	if (p->score < n->score) {
		return 1;
	} else if (p->score == n->score && p->id > n->id) {
		return 1;
	} else {
		return -1;
	}
}

void pta_rank(record * h, int n, int type)
{
	int i = 0, R = 1, repeat = 0, rank;
	qsort(h, n, sizeof(record), comp);
	(h + i)->frank = 1;
	(h + i)->lrank = 1;
	for (i = 1; i < n; i++) {
		R++;
		if ((h + i)->score < (h + i - 1)->score) {
			repeat = 0;
		} else if ((h + i)->score == (h + i - 1)->score) {
			repeat++;
		}
		rank = (repeat == 0) ? R : R - repeat;
		if (type == 0)
			(h + i)->lrank = rank;
		else
			(h + i)->frank = rank;
	}
}

int main()
{
	int N, Num = 0, t = 0, K[110];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &K[i]);
		for (int j = 0; j < K[i]; j++) {
			scanf("%lld%d", &T[Num].id, &T[Num].score);
			T[Num].group = i + 1;
			Num++;
		}
	}
	for (int i = 0; i < N; i++) {
		pta_rank(T + t, K[i], 0);
		t += K[i];
	}
	pta_rank(T, Num, 1);
	printf("%d\n", Num);
	for (int i = 0; i < Num; i++) {
		printf("%013lld %d %d %d\n", T[i].id, T[i].frank, T[i].group,
		       T[i].lrank);
	}
	return 0;
}
