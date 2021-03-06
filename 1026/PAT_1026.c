#include <stdio.h>
#include <stdlib.h>

typedef struct _player {
	int arr, start;
	int play, wait;
	int vip, end;
} player;

typedef struct _table {
	int num, vip;
	int free;
} table;

table T[110];

int comp(const void *a, const void *b)
{
	return ((player *)a)->arr > ((player *)b)->arr ? 1 : -1;
}

int comp2(const void *a, const void *b)
{
	return ((player *)a)->start > ((player *)b)->start ? 1 : -1;
}

/*void updata(player * p, table * t, int type, int i, int j)
{
	p->end = 1;
	if (t->fretime < 75600)
		t->num++;
	if (type == 1) {
		p->stime = p->atime;
		p->wait = 0;
		for (int i = 0; i < 3; i++)
			p->serve[i] = p->arr[i];
		t->fretime = p->stime + p->play * 60;
	} else {
		p->stime = t->fretime;
		p->wait = (p->stime - p->atime + 30) / 60;
		p->serve[0] = p->stime / 3600;
		p->serve[1] = (p->stime % 3600) / 60;
		p->serve[2] = p->stime % 60;
		t->fretime += p->play * 60;
	}
//	printf("-------------type: %d  P_vip:%d   P_id: %d  T_id: %d  P_atime: %d  fretime: %d\n", type, p->vip, i, j, p->atime, t->fretime);
}*/

int insert(player P[], int N, int K, int id)
{
	int min = 100000, index = 0, need = 0, first;
	for (int i = 1; i <= K; i++) {
		if (P[id].atime >= T[i].fretime) {
			if (need == 0) {
				need = 1;
				first = i;
			}
			if (P[id].vip == 0) {
				updata(&P[id], &T[i], 1, id, i);
				return 1;
			} else if (T[i].vip == 1) {
				updata(&P[id], &T[i], 1, id, i);
				return 1;
			}
		} else {
			if (T[i].fretime < min) {
				min = T[i].fretime;
				index = i;
			}
		}
	}
	if (need == 1)
	{
		updata(&P[id], &T[first], 1, id, first);
		return 1;
	}
	if (T[index].vip == 0) {
		updata(&P[id], &T[index], 0, id, index);
	} else {
		int j, flag = 0;
		for (j = id; P[j].atime <= T[index].fretime && j < N; j++) {
			if (P[j].vip == 1 && P[j].end == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			updata(&P[id], &T[index], 0, id, index);
		} else {
			updata(&P[j], &T[index], 0, j, index);
			return -1;
		}
	}
	return 1;
}

int main()
{
	int N, K, M, h, m, s;
	scanf("%d", &N);
	player *P = (player *) malloc(sizeof(player) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d", &h, &m, &s);
		scanf("%d%d", &P[i].play, &P[i].vip);
		if (P[i].play > 120)
			P[i].play = 120;
		P[i].arr = 3600 * h + 60 * m + s;
		P[i].end = 0;
	}
	qsort(P, N, sizeof(player), comp);
	scanf("%d%d", &K, &M);
	for (int i = 1; i <= K; i++)
		T[i].fretime = 28800;
	int vipnum;
	for (int i = 0; i < M; i++) {
		scanf("%d", &vipnum);
		T[vipnum].vip = 1;
	}
	int flag;
	for (int i = 0; i < N;) {
		flag = 1;
		if (P[i].end == 0)
			flag = insert(P, N, K, i);
		if (flag == 1)
			i++;
	}
	qsort(P, N, sizeof(player), comp2);
	for (int i = 0; i < N; i++) {
		if (P[i].stime < 75600) {
			printf("%02d:%02d:%02d ", P[i].arr[0], P[i].arr[1], P[i].arr[2]);
			printf("%02d:%02d:%02d %d\n", P[i].serve[0], P[i].serve[1], P[i].serve[2], P[i].wait);
		} else {
			break;
		}
	}
	for (int i = 1; i < K; i++)
		printf("%d ", T[i].num);
	printf("%d\n", T[K].num);
	return 0;
}
