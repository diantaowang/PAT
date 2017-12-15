#include <stdio.h>
#include <stdlib.h>

typedef struct _call {
	int id[3];
	int tid[3];
	int tim;
} call;

typedef struct _node {
	int num;
	struct _node *next;
} node;

typedef struct _head {
	int tim;
	node *arc;
} head;

int K, Num = 0, visited[2020];

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

int find(int num, int id[], int l, int r)
{
	int mid = (l + r) / 2;
	if (id[mid] == num)
		return mid;
	else if (id[mid] > num)
		return find(num, id, l, mid - 1);
	else
		return find(num, id, mid + 1, r);
}

void CreatGraph(head * G, call * R, int *ID, int N)
{
	int t1, t2;
	node *ptr;
	for (int i = 0; i < Num; i++) {
		G[i].tim = 0;
		G[i].arc = NULL;
	}
	for (int i = 0; i < N; i++) {
		t1 = find(R[i].tid[0], ID, 0, Num - 1);
		t2 = find(R[i].tid[1], ID, 0, Num - 1);
		G[t1].tim += R[i].tim;
		G[t2].tim += R[i].tim;
		ptr = (node *) malloc(sizeof(node));
		ptr->num = t2;
		ptr->next = G[t1].arc;
		G[t1].arc = ptr;
		ptr = (node *) malloc(sizeof(node));
		ptr->num = t1;
		ptr->next = G[t2].arc;
		G[t2].arc = ptr;
	}
}

void dfs_visit(head * G, int index, int *info)
{
	visited[index] = 1;
	info[0] += 1;
	info[1] += G[index].tim;
	if (info[3] < G[index].tim) {
		info[2] = index;
		info[3] = G[index].tim;
	}
	node *ptr = G[index].arc;
	while (ptr != NULL) {
		if (visited[ptr->num] == 0)
			dfs_visit(G, ptr->num, info);
		ptr = ptr->next;
	}
}

void dfs(head * G, int *count, int gang[][2])
{
	int info[5];
	for (int i = 0; i < Num; i++) {
		for (int j = 0; j < 5; j++)
			info[j] = 0;
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs_visit(G, i, info);
			if (info[0] > 2 && info[1] > 2 * K) {
				gang[*count][0] = info[2];
				gang[*count][1] = info[0];
				(*count)++;
			}
		}
	}
}

int main()
{
	int N, ID_t[2020], ID[2020];
	char user[2][4];
	int count = 0, g[2020][2];
	scanf("%d%d", &N, &K);
	call *R = (call *) malloc(sizeof(call) * N);
	for (int i = 0, j = 0; i < N; i++, j += 2) {
		scanf("%s %s %d", user[0], user[1], &R[i].tim);
		R[i].tid[0] = 10000 * user[0][0] + 100 * user[0][1] + user[0][2];
		R[i].tid[1] = 10000 * user[1][0] + 100 * user[1][1] + user[1][2];
		ID_t[j] = R[i].tid[0];
		ID_t[j + 1] = R[i].tid[1];
	}
	qsort(ID_t, 2 * N, sizeof(int), comp);
	ID[0] = ID_t[0];
	for (int i = 1, t = ID[0]; i < 2 * N; i++) {
		if (t != ID_t[i]) {
			t = ID_t[i];
			ID[++Num] = t;
		}
	}
	Num++;
	head *G = (head *) malloc(sizeof(head) * Num);
	CreatGraph(G, R, ID, N);
	dfs(G, &count, g);
	if (count == 0)
		printf("0\n");
	else {
		printf("%d\n", count);
		qsort(g, count, sizeof(int)*2, comp);
		for (int i = 0, t; i < count; i++) {
			t = g[i][0];
			printf("%c%c%c %d\n", ID[t] / 10000, ID[t] % 10000 / 100, ID[t] % 100, g[i][1]);
		}
	}
	return 0;
}
