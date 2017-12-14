#include <stdio.h>

typedef struct _user {
	int modify;
	char name[15];
	char password[15];
} user;

user R[1010];

int main()
{
	int N, count = 0, flag;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		flag = 0;
		scanf("%s%s", R[i].name, R[i].password);
		for (int j = 0; R[i].password[j] != '\0'; j++) {
			if (R[i].password[j] == '1') {
				R[i].password[j] = '@';
				flag = 1;
			} else if (R[i].password[j] == '0') {
				R[i].password[j] = '%';
				flag = 1;
			} else if (R[i].password[j] == 'l') {
				R[i].password[j] = 'L';
				flag = 1;
			} else if (R[i].password[j] == 'O') {
				R[i].password[j] = 'o';
				flag = 1;
			}
		}
		if (flag == 1) {
			R[i].modify = 1;
			count++;
		}
	}
	if (count == 0 && N == 1)
		printf("There is 1 account and no account is modified\n");
	else if (count == 0)
		printf("There are %d accounts and no account is modified\n", N);
	else {
		printf("%d\n", count);
		for (int i = 0; i < N; i++) {
			if (R[i].modify == 1)
				printf("%s %s\n", R[i].name, R[i].password);
		}
	}
}
