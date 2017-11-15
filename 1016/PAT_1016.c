#include <stdio.h>

typedef struct _Record{
	char id[21];
	int  data[5];
	char status[10]; 
} Record;

Record CUST[1010] = {{{"||||||"}}};
char ID[1010][21] = {"|||||"};
int PRICE[25], NUM = 1;

int CompareStr(char src[], char dst[])
{
	int i=0, flag = 0;
	while(src[i] != '\0' && dst[i] != '\0')
	{
		if(dst[i] < src[i])
		{
			flag = 1;
			break;
		}
		else if(dst[i] > src[i])
		{
			flag = -1;
			break;
		}
		i++;
	}
	if(flag == 0 && dst[i] == '\0' && src[i] != '\0')
		flag = 1;
	else if(flag == 0 && dst[i] != '\0' && src[i] == '\0')
		flag = -1;
	return flag;
}

void CopyStr(char src[], char dst[])
{
	int i=0;
	while(src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while(dst[i] != '\0')
		dst[i++] = '\0';
}

void IDSort(char id[])
{
	int i, j, flag = 0;
	for(i=0; i<NUM; i++)
	{
		flag = CompareStr(ID[i], id);
		if(flag == 0)
			break;
		if(flag == 1)
		{
			NUM++;
			break;
		}
	}
	if(flag == 1)
	{
		for(j=NUM-1; j>i; j--)
			CopyStr(ID[j-1], ID[j]);
		CopyStr(id, ID[j]);
	}
}

int CompRecord(Record* oldR, Record* newR)
{
	int i=0, flag = 0;
	while(oldR->id[i] != '\0' && newR->id[i] != '\0')
	{
		if(newR->id[i] < oldR->id[i])
		{
			flag = 1;
			break;
		}
		else if(newR->id[i] > oldR->id[i])
		{
			flag = -1;
			break;
		}
		i++;
	}
	if(flag == 0 && newR->id[i] == '\0' && oldR->id[i] != '\0')
		flag = 1;
	else if(flag == 0 && newR->id[i] != '\0' && oldR->id[i] == '\0')
		flag = -1;
	else if(flag == 0)
	{
		
	}
	return flag;
}

void RecordSort(Record* NewEle)
{
	int i, j, flag = 0;
	for(i=0; i<NUM; i++)
	{
		flag = CompRecord(CUST+i, NewEle);
		if(flag == 1)
		{
			NUM++;
			break;
		}
	}
	if(flag == 1)
	{
		for(j=NUM-1; j>i; j--)
			CopyRecord();
		CopyRecord();
	}
	
}

int main()
{
	int i, N;
	char tmp[4];
	Record Cust;
	for(i=0; i<24; i++)
		scanf("%d", &PRICE[i]);
	scanf("%d", &N);
	for(i=0; i<N; i++)
	{
		scanf("%s%d%c", Cust.id, &Cust.data[0], &tmp[0]);
		scanf("%d%c%d%c", &Cust.data[1], &tmp[1], &Cust.data[2], &tmp[2]);
		scanf("%d%c%s", &Cust.data[3], &tmp[3], Cust.status);
//		IDSort(CUST[i].id);
		RecordSort(&Cust);
	}	
//	for(i=0; i<10; i++)
//		printf("%s\n", CUST[i].id);
	return 0;
}
