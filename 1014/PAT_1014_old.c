#include <stdio.h>
#include <malloc.h>

#define M_LEN 11
#define Q_LEN 10

unsigned M;
unsigned FullNum = 0;
unsigned TIME[21];

typedef struct _Node {
	unsigned UsedTime;
	unsigned StartTime;
	unsigned FinTime;
} Customer;

typedef struct _Queue {
	unsigned data[M_LEN];
	unsigned head;
	unsigned tail;
	unsigned num;
} Queue;

int EndQueue(Queue * Q, unsigned x)
{
	if (Q->num >= M)
		return -1;
	else {
		(Q->num)++;
		if (Q->num == M)
			FullNum++;
		Q->data[Q->tail] = x;
		if (Q->tail == Q_LEN)
			Q->tail = 0;
		else
			Q->tail++;
	}
	return 1;
}

int DeQueue(Queue * Q)
{
	if (Q->num == 0)
		return -1;
	else {
		(Q->num)--;
		if (Q->num == M - 1)
			FullNum--;
		if (Q->head == Q_LEN)
			Q->head = 0;
		else
			Q->head++;
	}
	return 1;
}

unsigned FindMinNum(Queue * Q, unsigned N)
{
	unsigned i, min = 11, index;
	for (i = 0; i < N; i++) {
		if (min > (Q + i)->num) {
			index = i;
			min = (Q + i)->num;
		}
	}
	return index;
}

unsigned FindMinQueue(Queue * Q, Customer * Cust, unsigned N)
{
	unsigned i, j, index, minTime, tmp, id;
	minTime = 10000000;
	for (i = 0; i < N; i++) {
		j = (Q + i)->data[(Q + i)->head];
		tmp = TIME[i] + (Cust + j)->UsedTime;
		if (minTime > tmp) {
			index = i;
			id = j;
			minTime = tmp;
		}
	}
	(Cust + id)->StartTime = TIME[index];
	TIME[index] = minTime;
	(Cust + id)->FinTime = TIME[index];
	return index;
}

void EmptyQ(Queue * Q, Customer * Cust, unsigned N)
{
	unsigned i, j;
	for (i = 0; i < N; i++) {
		while ((Q + i)->num != 0) {
			j = (Q + i)->data[(Q + i)->head];
			(Cust + j)->StartTime = TIME[i];
			TIME[i] += (Cust + j)->UsedTime;
			(Cust + j)->FinTime = TIME[i];
			DeQueue(Q + i);
		}
	}
}

int main()
{
	unsigned N, K, P, i, FTime, index, *CQ;
	Queue *Q;
	Customer *Cust;
	scanf("%d%d%d%d", &N, &M, &K, &P);
	Q = (Queue *) malloc(sizeof(Queue) * N);
	Cust = (Customer *) malloc(sizeof(Customer) * K);
	CQ = (unsigned *)malloc(sizeof(unsigned) * P);
	for (i = 0; i < K; i++)
		scanf("%u", &((Cust + i)->UsedTime));
	for (i = 0; i < P; i++)
		scanf("%u", CQ + i);
	for (i = 0; i < N; i++) {
		(Q + i)->head = 0;
		(Q + i)->tail = 0;
		(Q + i)->num = 0;
	}
	for (i = 0; i < K;) {
		if (FullNum < N) {
			index = FindMinNum(Q, N);
			EndQueue((Q + index), i);
			i++;
		} else {
			index = FindMinQueue(Q, Cust, N);
			DeQueue(Q + index);
		}
	}
	EmptyQ(Q, Cust, N);
	for (i = 0; i < P; i++) {
		int test = (Cust + *(CQ + i) - 1)->StartTime;
		FTime = (Cust + *(CQ + i) - 1)->FinTime;
		if (test >= 540)
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", FTime / 60 + 8, FTime % 60);
	}
	return 0;
}
