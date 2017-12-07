#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Index;

typedef struct _StrHead {
	char s[90];
	int id;
} StrHead;

typedef struct _NumHead {
	int y;
	int id;
} NumHead;

int comp(const void *a, const void *b)
{
	StrHead *p, *n;
	p = (StrHead *) a;
	n = (StrHead *) b;
	int flag = strcmp(p->s, n->s);
	if (flag > 0)
		return 1;
	else if (flag == 0 && p->id > n->id)
		return 1;
	else
		return 0;
}

int comp_num(const void *a, const void *b)
{
	NumHead *p, *n;
	p = (NumHead *) a;
	n = (NumHead *) b;
	if (p->y > n->y)
		return 1;
	else if (p->y == n->y && p->id > n->id)
		return 1;
	else
		return -1;
}

void find_str(StrHead a[], char s[], int h, int t)
{
	if (h >= t)
		return;
	int mid = (h + t) / 2;
	int flag = strcmp(s, a[mid].s);
	if (flag == 0) {
		Index = mid;
		return;
	} else if (flag < 0)
		find_str(a, s, h, mid - 1);
	else
		find_str(a, s, mid + 1, t);
}

void find_num(NumHead a[], int s, int h, int t)
{
	if (h >= t)
		return;
	int mid = (h + t) / 2;
	int flag = s - a[mid].y;
	if (flag == 0) {
		Index = mid;
		return;
	} else if (flag < 0)
		find_num(a, s, h, mid - 1);
	else
		find_num(a, s, mid + 1, t);
}

void print_num(NumHead a[], int s, int N)
{
	int i;
	Index = -1;
	if (s == a[0].y)
		Index = 0;
	else if (s == a[N - 1].y)
		Index = N - 1;
	else
		find_num(a, s, 0, N - 1);
	if (Index == -1)
		printf("Not Found\n");
	else {
		for (i = Index - 1; i >= 0; i--) {
			if (s != a[i].y)
				break;
		}
		i = i + 1;
		for (; s == a[i].y; i++)
			printf("%d\n", a[i].id);
	}
}

void print(StrHead a[], char s[], int N)
{
	int i;
	Index = -1;
	if (strcmp(a[0].s, s) == 0)
		Index = 0;
	else if (strcmp(a[N - 1].s, s) == 0)
		Index = N - 1;
	else
		find_str(a, s, 0, N - 1);
	if (Index == -1)
		printf("Not Found\n");
	else {
		for (i = Index - 1; i >= 0; i--) {
			if (strcmp(s, a[i].s) != 0)
				break;
		}
		i = i + 1;
		for (; strcmp(s, a[i].s) == 0; i++)
			printf("%d\n", a[i].id);
	}
}

int main()
{
	int N, M, id, n = 0;
	scanf("%d", &N);
	StrHead *title = (StrHead *) malloc(sizeof(StrHead) * N);
	StrHead *auth = (StrHead *) malloc(sizeof(StrHead) * N);
	StrHead *key = (StrHead *) malloc(sizeof(StrHead) * N * 5);
	StrHead *pub = (StrHead *) malloc(sizeof(StrHead) * N);
	NumHead *years = (NumHead *) malloc(sizeof(NumHead) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d\n", &id);
		fgets(title[i].s, 90, stdin);
		title[i].id = id;
		fgets(auth[i].s, 90, stdin);
		auth[i].id = id;
		do {
			scanf("%s", key[n].s);
			key[n].id = id;
			n++;
		} while (getchar() != '\n');
		fgets(pub[i].s, 90, stdin);
		pub[i].id = id;
		scanf("%d", &years[i].y);
		years[i].id = id;
	}
	qsort(title, N, sizeof(StrHead), comp);
	qsort(auth, N, sizeof(StrHead), comp);
	qsort(key, n, sizeof(StrHead), comp);
	qsort(pub, N, sizeof(StrHead), comp);
	qsort(years, N, sizeof(NumHead), comp_num);
	scanf("%d", &M);
	int type, data;
	char str[90];
	for (int i = 0; i < M; i++) {
		scanf("%d: ", &type);
		printf("%d: ", type);
		if (type == 3) {
			scanf("%s", str);
			printf("%s\n", str);
		} else if (type == 5) {
			scanf("%d", &data);
			printf("%d\n", data);
		} else {
			fgets(str, 90, stdin);
			printf("%s", str);
		}
		if (type == 1)
			print(title, str, N);
		else if (type == 2)
			print(auth, str, N);
		else if (type == 3)
			print(key, str, n);
		else if (type == 4)
			print(pub, str, N);
		else
			print_num(years, data, N);
	}
	return 0;
}
