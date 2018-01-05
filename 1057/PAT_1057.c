#include <stdio.h>

#define MaxVal  100010
#define BitMask 65536

int top, stack[100010];
int tree[100010], f[100010];

void update(int idx, int val)
{
	while (idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int read(int idx)
{
	int sum = 0;
	while (idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

int find(int cumFre)
{
	int idx = 0, bitmask = BitMask;
	while (bitmask != 0 && idx < MaxVal) {
		int tIdx = idx + bitmask;
		if (cumFre == tree[tIdx] && f[tIdx] != 0)
			return tIdx;
		else if (cumFre > tree[tIdx]) {
			idx = tIdx;
			cumFre -= tree[tIdx];
		}
		bitmask >>= 1;
	}
	return idx + 1;
}

int main()
{
	int n;
	char str[20];
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%s", str);
		if (str[1] == 'u') {
			scanf("%d", &num);
			stack[top++] = num;
			f[num] += 1;
			update(num, 1);
		} else if (str[1] == 'o') {
			if (top == 0)
				printf("Invalid\n");
			else {
				printf("%d\n", stack[--top]);
				f[stack[top]] -= 1;
				update(stack[top], -1);
			}
		} else {
			if (top == 0)
				printf("Invalid\n");
			else
				printf("%d\n", find((top + 1) / 2));
		}
	}
	return 0;
}
