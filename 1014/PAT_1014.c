#include <stdio.h>

int FinTime[1001];
int UsedTime[1001];
int Queue[20][11];

int FindMinQ(int QT[], int N)
{
	int i, tmp, index, min = 99999999;
	for(i=0; i<N; i++)
	{
		tmp = QT[i] + UsedTime[Queue[i][0]];
		if(min > tmp)
		{
			index = i;
			min = tmp;
		}
	}
	FinTime[Queue[index][0]] = min;
	QT[index] = min;
	return index;
}

int main()
{
	int i, j, N, M, K, Q, count=0;
	int index, CQ[1001];
	int QTime[21] = {0};
	int Num[21] = {0};
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for(i=0; i<K; i++)
		scanf("%d", &UsedTime[i]);
	for(i=0; i<Q; i++)
		scanf("%d", &CQ[i]);
	for(i=0; i<M && count<K; i++)
	{
		for(j=0; j<N && count<K; j++)
		{
			Queue[j][i] = count;
			count++;
			Num[j]++;
		}
	}
	for(i=N*M; i<K; i++)
	{
		index = FindMinQ(QTime, N);
		for(j=0; j<M-1; j++)
			Queue[index][j] = Queue[index][j+1];
		Queue[index][M-1] = i;
	}
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<Num[i]; j++)
		{
			QTime[i] += UsedTime[Queue[i][j]];
			FinTime[Queue[i][j]] = QTime[i]; 
		}
	}
	for(i=0; i<Q; i++)
	{
		if(FinTime[CQ[i]-1] > 540)
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", FinTime[CQ[i]-1]/60+8, FinTime[CQ[i]-1]%60);
	}
	return 0;
}





/*	for(i=0; i<K;)
	{
		if(FULL != N)
		{
			i++;
			InsertCust(i, N);
		}
		else 
			FindMinQ(N,QTime);
	}*/

/*void InsertCust(int id, int N)
{
	int i, index, min=11;
	for(i=0; i<N; i++)
	{
		if(min > NUM[i])
		{
			index = i;
			min = NUM[i];
		}
	}
	NUM[index]++;
	if(NUM[index] == M)
		FULL++;
	Queue[index][NUM[index]] = id;
}

void FindMinQ(int N, int QT[])
{
	int i, index, tmp;
   	int min = 99999999;
	for(i=0; i<N; i++)
	{
		tmp = UsedTime[Queue[i][0]] + QT[i];
		if(min > tmp)
		{
			index = i;
		 	min = tmp;
		}
	}
	QT[index] = min;
	FinTime[Queue[index][0]] = QT[index];
	NUM[index]--;
	if(NUM[index] == M-1)
		FULL--;
	for(i=0; i<N; i++)
		Queue[index][i] = Queue[index][i+1];
}*/
