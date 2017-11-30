#include <stdio.h>
#include <stdlib.h>

typedef struct _record {
	long long int id;
	int score;
	int group;
	int frank;
	int lrank;
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

int main()
{
	int N, K, Num = 0, R, repeat = 0;
	int count[101] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%lld%d", &T[Num].id, &T[Num].score);
			T[Num].group = i + 1;
			Num++;
		}
	}
	qsort(T, Num, sizeof(record), comp);
	T[0].frank = 1;
   	T[0].lrank = 1;	
	R = 1;
	for(int i=1; i<Num; i++)
	{
		if(T[i].score < T[i-1].score)
		{
			R++;
			R += repeat;
			T[i].frank = R;
		}
		else if(T[i].score == T[i-1].score)
		{
			repeat++;
			T[i].frank = R;
		}
		
	}
	printf("%d\n", Num);
	for (int i = 0; i < Num; i++) {
		printf("%lld %d %d %d\n", T[i].id, T[i].frank, T[i].group, T[i].score);
	}
	return 0;
}
