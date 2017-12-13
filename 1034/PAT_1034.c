#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

typedef struct _call{
	int id[3];
	int tid[3];
	int time;
} call;

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

int find(int num, int id[], int l, int r)
{
	int mid = (l+r)/2;
	if(l > r)
		return -1;
	else if(id[mid] == num)
		return mid;
	else if(id[mid] > num)
		find(num, id, l, mid-1);
	else
		find(num, id, mid+1, r);
	return -1;
}

int main()
{
	int N, K, Num = 0;
	char user[2][4];
	scanf("%d%d", &N, &K);
	call *R=(call *)malloc(sizeof(call)*N);
	int *ID_t = (int *)malloc(sizeof(int)*N*2);
	int *ID = (int *)malloc(sizeof(int)*N*2);
	for(int i=0, j=0; i<N; i++, j += 2)
	{		
		scanf("%s %s %d", user[0], user[1], &R[i].time);
		R[i].tid[0] = 10000*user[0][0] + 100*user[0][1] + user[0][2];
		R[i].tid[1] = 10000*user[1][0] + 100*user[1][1] + user[1][2];
		ID_t[j] = R[i].tid[0];
		ID_t[j+1] = R[i].tid[1];
	}
	qsort(ID_t, 2*N, sizeof(int), comp);
	ID[0] = ID_t[0];
	for(int i = 1, t = ID[0]; i<2*N; i++)
	{
		if(t != ID_t[i])
		{
			t = ID_t[i];
			ID[++Num] = t;
		}
	}
	return 0;
}

//	for(int i=0; i<Num; i++)
//		printf("%d:%c%c%c\n", ID_t[i], ID[i]/10000, ID[i]%10000/100, ID[i]%100);
//	for(int i=0; i<2*N; i++)
//		printf("%d:%c%c%c\n", ID_t[i], (char)(ID_t[i]/10000), (char)(ID_t[i]%10000/100), (char)(ID_t[i]%100));
