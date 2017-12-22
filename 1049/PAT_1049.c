#include <stdio.h>
#include <math.h>

int mypow(int x, int n)
{
	int sum = 1;
	for (int i = 0; i < n; i++)
		sum *= x;
	return sum;
}

int calc(int x, int n)
{
	int part1, part2, t1, t2;
	int remainder, one_bit;
	t2 = mypow(10, n - 1);
	t1 = t2 * 10;
	part1 = x / t1 * t2;
	remainder = x % t1;
	one_bit = remainder / t2;
	if (one_bit == 0)
		part2 = 0;
	else if (one_bit == 1)
		part2 = remainder % t2 + 1;
	else
		part2 = t2;
	return part1 + part2;
}

int main()
{
	int n, t = 1, i = 1, sum = 0;
	scanf("%d", &n);
	while (n / t > 0) {
		sum += calc(n, i);
		i++;
		t *= 10;
	}
	printf("%d\n", sum);
}
