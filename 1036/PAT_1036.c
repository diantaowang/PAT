#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _record {
	char name[15];
	char id[15];
	int grade;
} record;

record f, m;

int main()
{
	int n, flag1 = 0, flag2 = 0, grade;
	int max = -1, min = 110;
	char name[15], gender, id[15];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %c %s %d", name, &gender, id, &grade);
		if (gender == 'M') {
			if (grade < min) {
				flag1 = 1;
				min = grade;
				strcpy(m.name, name);
				strcpy(m.id, id);
			}
		} else {
			if (grade > max) {
				flag2 = 1;
				max = grade;
				strcpy(f.name, name);
				strcpy(f.id, id);
			}
		}
	}
	if (flag1 == 0)
		printf("%s %s\nAbsent\nNA\n", f.name, f.id);
	else if (flag2 == 0)
		printf("Absent\n%s %s\nNA\n", m.name, m.id);
	else
		printf("%s %s\n%s %s\n%d\n", f.name, f.id, m.name, m.id,
		       max - min);
	return 0;
}
