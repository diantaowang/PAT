#include <stdio.h>

void CharToInt(unsigned int a[], unsigned char b[], unsigned int *N)
{
	unsigned int i = 0;
	while (b[i] != '\0') {
		if ((b[i] >= '0') && (b[i] <= '9'))
			a[i] = b[i] - '0';
		else
			a[i] = b[i] - 'a' + 10;
		i++;
	}
	*N = --i;
}

unsigned long long int SumRadix10(unsigned int n, unsigned int a[],
				  unsigned long radix)
{
	unsigned int i;
	unsigned long long int p = a[0];
	for (i = 0; i < n; i++)
		p = a[i + 1] + radix * p;
	return p;
}

unsigned int FindMaxElement(unsigned int a[], unsigned int N)
{
	unsigned int MaxElement = 0, i;
	for (i = 0; i <= N; i++)
		if (a[i] > MaxElement)
			MaxElement = a[i];
	return MaxElement;
}

long long FindRadix(unsigned long long NumKnow, unsigned p[],
		    unsigned long long MaxRadix, unsigned long long MinRadix,
		    unsigned N)
{
	unsigned long long MidRadix, tmp;
	if (MaxRadix <= MinRadix + 1)
		return -1;
	MidRadix = (MinRadix + MaxRadix) / 2;
	tmp = SumRadix10(N, p, MidRadix);
	if (tmp == NumKnow)
		return MidRadix;
	else if (tmp > NumKnow)
		return FindRadix(NumKnow, p, MidRadix, MinRadix, N);
	else
		return FindRadix(NumKnow, p, MaxRadix, MidRadix, N);
}

int FindMinRadix(unsigned char knownStr[], unsigned char unknownStr[],
		 unsigned int radix)
{
	unsigned int knownInt[11], unknownInt[11], N1, N2;
	unsigned long long int tmp;
	CharToInt(knownInt, knownStr, &N1);
	CharToInt(unknownInt, unknownStr, &N2);
	tmp = SumRadix10(N1, knownInt, radix);
	return FindRadix(tmp, unknownInt, tmp + 2,
			 FindMaxElement(unknownInt, N2), N2);
}

int main()
{
	unsigned char n1[11], n2[11];
	unsigned int tag, radix;
	long long int flag;
	scanf("%s%s%u%u", n1, n2, &tag, &radix);
	if (tag == 1)
		flag = FindMinRadix(n1, n2, radix);
	else
		flag = FindMinRadix(n2, n1, radix);
	if (flag == -1)
		printf("Impossible\n");
	else
		printf("%lld\n", flag);

	return 0;
}
