#include <stdio.h>

int Post[31], In[31];
int Level[10001];

void treeconv(int start, int mid, int end, int index)
{
	if (start > end)
		return;
	int i;
	for (i = start; i <= end && In[i] != Post[mid]; i++) ;
	Level[index] = In[i];
	treeconv(start, mid - end + i - 1, i - 1, 2 * index + 1);
	treeconv(i + 1, mid - 1, end, 2 * index + 2);
}

int main()
{
	int N, flag = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Post[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &In[i]);
	treeconv(0, N - 1, N - 1, 0);
	for (int i = 0; i < 10000; i++) {
		if (Level[i] > 0 && flag == 0) {
			printf("%d", Level[i]);
			flag = 1;
		} else if (Level[i] > 0)
			printf(" %d", Level[i]);
	}
	printf("\n");
	return 0;
}
