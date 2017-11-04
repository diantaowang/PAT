#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct _Record {
	char ID_number[20];
	int Sign_in_time[4];
	int Sign_out_time[4];
} Record;

Record unlock = { "wang", {23, 59, 59}, {23, 59, 59} };
Record lock = { "wang", {0, 0, 0}, {0, 0, 0} };

void conversion(char str[], Record * ptr)
{
	int i = 0, j = 0, k = 0, innum = 0, outnum = 0, spaceNum = 0;
	char tmpc[3];
	while (str[i] != '\0') {
		if (str[i] != ' ' && spaceNum == 0)
			ptr->ID_number[j++] = str[i];
		else if (str[i] == ' ')
			spaceNum++;
		else {
			if (str[i] != ':') {
				tmpc[k++] = str[i];
				if (k == 2 && spaceNum == 1)
					ptr->Sign_in_time[innum++] = atoi(tmpc);
				else if (k == 2 && spaceNum == 2)
					ptr->Sign_out_time[outnum++] =
					    atoi(tmpc);
				if (k == 2)
					k = 0;
			}
		}
		i++;
	}
	ptr->ID_number[j] = '\0';
}

void copystr(Record * dst, Record * src)
{
	int i;
	for (i = 0; i < 20; i++)
		dst->ID_number[i] = src->ID_number[i];
	for (i = 0; i < 3; i++) {
		dst->Sign_in_time[i] = src->Sign_in_time[i];
		dst->Sign_out_time[i] = src->Sign_out_time[i];
	}

}

void FindID(Record * ptr, int m)
{
	int i;
	for (i = 0; i < m; i++) {
		if ((ptr + i)->Sign_in_time[0] < unlock.Sign_in_time[0])
			copystr(&unlock, (ptr + i));
		else if ((ptr + i)->Sign_in_time[0] == unlock.Sign_in_time[0]) {
			if ((ptr + i)->Sign_in_time[1] < unlock.Sign_in_time[1])
				copystr(&unlock, (ptr + i));
			else if ((ptr + i)->Sign_in_time[1] ==
				 unlock.Sign_in_time[1]) {
				if ((ptr + i)->Sign_in_time[2] <
				    unlock.Sign_in_time[2])
					copystr(&unlock, (ptr + i));
			}
		}
		if ((ptr + i)->Sign_out_time[0] > lock.Sign_out_time[0])
			copystr(&lock, (ptr + i));
		else if ((ptr + i)->Sign_out_time[0] == lock.Sign_out_time[0]) {
			if ((ptr + i)->Sign_out_time[1] > lock.Sign_out_time[1])
				copystr(&lock, (ptr + i));
			else if ((ptr + i)->Sign_out_time[1] ==
				 lock.Sign_out_time[1]) {
				if ((ptr + i)->Sign_out_time[2] >
				    lock.Sign_out_time[2])
					copystr(&lock, (ptr + i));
			}
		}
	}
}

int main()
{
	int i, m;
	char str[40];
	Record *ptr;
	scanf("%d", &m);
	getchar();
	ptr = (Record *) malloc(m * sizeof(Record));
	for (i = 0; i < m; i++) {
		fgets(str, 40, stdin);
		conversion(str, ptr + i);
	}
	FindID(ptr, m);
	printf("%s ", unlock.ID_number);
	printf("%s\n", lock.ID_number);
	return 0;
}
