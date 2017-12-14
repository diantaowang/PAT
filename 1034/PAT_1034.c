#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _call {
	char s1[4];
	char s2[4];
	int tim;
} call;

int K, Num = 0, visited[2010];
int G[2010][2010], Time[2010];
char Name[2010][4], user[2010][4];

int comp(const void *a, const void *b)
{
	int flag = strcmp((char *)a, (char *)b);
	if (flag > 0)
		return 1;
	else
		return -1;
}

int find(char *key, char user[][4], int l, int r)
{
	int mid = (l + r) / 2;
	int flag = strcmp(key, user[mid]);
	if (flag == 0)
		return mid;
	else if (flag < 0)
		return find(key, user, l, mid - 1);
	else
		return find(key, user, mid + 1, r);
}

void dfs_visit(int G[][2010], int index, int *info)
{
	visited[index] = 1;
	info[0] += 1;
	info[1] += Time[index];
	if (info[3] < Time[index]) {
		info[2] = index;
		info[3] = Time[index];
	}
	for (int i = 0; i <= Num; i++) {
		if (G[index][i] != 0 && visited[i] == 0)
			dfs_visit(G, i, info);
	}
}

void dfs(int G[][2010], int *count, int gang[][3])
{
	int info[5];
	for (int i = 0; i <= Num; i++) {
		for (int j = 0; j < 5; j++)
			info[j] = 0;
		if (visited[i] == 0) {
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
	int N, t1, t2, count = 0, gang[2010][3];
	scanf("%d%d", &N, &K);
	call *R = (call *) malloc(sizeof(call) * N);
	for (int i = 0, j = 0; i < N; i++, j += 2) {
		scanf("%s%s%d", R[i].s1, R[i].s2, &R[i].tim);
		strcpy(Name[j], R[i].s1);
		strcpy(Name[j + 1], R[i].s2);
	}
	qsort(Name, 2 * N, sizeof(char) * 4, comp);
	strcpy(user[0], Name[0]);
	for (int i = 1; i < 2 * N; i++) {
		if (strcmp(user[Num], Name[i]) != 0)
			strcpy(user[++Num], Name[i]);
	}
	for (int i = 0; i < N; i++) {
		t1 = find(R[i].s1, user, 0, Num);
		t2 = find(R[i].s2, user, 0, Num);
		Time[t1] += R[i].tim;
		Time[t2] += R[i].tim;
		G[t1][t2] = 1;
		G[t2][t1] = 1;
	}
	dfs(G, &count, gang);
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
		printf("%s %d\n", user[gang[i][0]], gang[i][1]);
	return 0;
}
