#include <stdio.h>
#include <string.h>

typedef struct _Record {
	char id[21];
	int data[5];
	char status[10];
	int time;
} Record;

Record CUST[1010] = { {{"||||||"}, {}, {}, 0} };

int PRICE[25], NUM = 1;

void CopyStr(char src[], char dst[])
{
	int i = 0;
	while (src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	while (dst[i] != '\0')
		dst[i++] = '\0';
}

int CompRecord(Record * oldR, Record * newR)
{
	int i = 0, flag = 0;
	while (oldR->id[i] != '\0' && newR->id[i] != '\0') {
		if (newR->id[i] < oldR->id[i]) {
			flag = 1;
			break;
		} else if (newR->id[i] > oldR->id[i]) {
			flag = -1;
			break;
		}
		i++;
	}
	if (flag == 0 && newR->id[i] == '\0' && oldR->id[i] != '\0')
		flag = 1;
	else if (flag == 0 && newR->id[i] != '\0' && oldR->id[i] == '\0')
		flag = -1;
	else if (flag == 0) {
		if (newR->time < oldR->time)
			flag = 1;
		else
			flag = -1;
	}
	return flag;
}

void CopyRecord(Record * src, Record * dst)
{
	int i;
	CopyStr(src->id, dst->id);
	CopyStr(src->status, dst->status);
	dst->time = src->time;
	for (i = 0; i < 4; i++)
		dst->data[i] = src->data[i];
}

void RecordSort(Record * NewEle)
{
	int i, j, flag = 0;
	for (i = 0; i < NUM; i++) {
		flag = CompRecord(CUST + i, NewEle);
		if (flag == 1) {
			NUM++;
			break;
		}
	}
	if (flag == 1) {
		for (j = NUM - 1; j > i; j--)
			CopyRecord(CUST + j - 1, CUST + j);
		CopyRecord(NewEle, CUST + i);
	}
}

int CalcCharge(int a[], int b[])
{
	int sum = 0;
	sum += b[3] * PRICE[b[2]];
	sum -= a[3] * PRICE[a[2]];
	while (a[1] != b[1] || a[2] != b[2]) {
		sum += 60 * PRICE[a[2]];
		a[2]++;
		if (a[2] == 24) {
			a[2] = 0;
			a[1]++;
		}
	}
	return sum;
}

void PrintCall(Record CUST[])
{
	int i, flag = 0, time = 0;
	int price = 0, charge = 0;
	for (i = 0; i < NUM - 1; i++) {
		if (strcmp(CUST[i].id, CUST[i + 1].id) == 0) {
			if (CUST[i].status[1] == 'n'
			    && CUST[i + 1].status[1] == 'f') {
				if (flag == 0)
					printf("%s %02d\n", CUST[i].id,
					       CUST[i].data[0]);
				time = (CUST[i + 1].time - CUST[i].time);
				printf("%02d:%02d:%02d ", CUST[i].data[1],
				       CUST[i].data[2], CUST[i].data[3]);
				printf("%02d:%02d:%02d ", CUST[i + 1].data[1],
				       CUST[i + 1].data[2],
				       CUST[i + 1].data[3]);
				price =
				    CalcCharge(CUST[i].data, CUST[i + 1].data);
				charge += price;
				printf("%d $%.2lf\n", time,
				       (double)price / 100.0);
				flag = 1;
			}
		} else {
			if (flag == 1) {
				printf("Total amount: $%.2lf\n",
				       (double)charge / 100.0);
				flag = 0;
			}
			charge = 0;
		}
	}
}

int main()
{
	int i, N;
	char tmp[4];
	Record Cust;
	for (i = 0; i < 24; i++)
		scanf("%d", &PRICE[i]);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s%d%c", Cust.id, &Cust.data[0], &tmp[0]);
		scanf("%d%c%d%c", &Cust.data[1], &tmp[1], &Cust.data[2],
		      &tmp[2]);
		scanf("%d%c%s", &Cust.data[3], &tmp[3], Cust.status);
		Cust.time =
		    Cust.data[3] + 60 * Cust.data[2] + 1440 * Cust.data[1];
		RecordSort(&Cust);
	}
	PrintCall(CUST);
	return 0;
}
