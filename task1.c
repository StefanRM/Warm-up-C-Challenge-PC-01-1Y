#include <stdio.h>

int SumDiv(int x)
{
	int s = 1, d = 2;

	while (d <= x / 2) {
		if (x % d == 0) {
			s = s + d;
		}
		d = d + 1;
	}
	return s;
}

int main()
{
	int k, i;

	scanf("%d", &k);
	for (i = 1; i <= k; i++) {
		if (SumDiv(SumDiv(i)) == i && i < SumDiv(i)
		    && SumDiv(i) < k) {
			printf("(%d, %d) \n", i, SumDiv(i));
		}
	}
	return 0;
}
