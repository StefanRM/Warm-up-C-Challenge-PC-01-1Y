#include <stdio.h>

int isPalindrome(long long x)
{
	long long y = 0, z = x;

	while (x > 0) {
		y = y * 10 + x % 10;
		x = x / 10;
	}
	if (y == z) {
		return 1;
	} else {
		return 0;
	}
}

int power(int x, int y)
{
	return (y >= 1) ? x * power(x, y - 1) : 1;
}

int main()
{
	long long x, i, nr = 0;
	int p, min, max;

	scanf("%d %lli", &p, &x);
	min = power(10, p - 1);
	max = power(10, p);
	if (min < 10) {
		nr = 1;
	}
	for (i = 1; i < x; i++) {
		if (isPalindrome(i)) {
			int j, exit = 0;

			for (j = min; j <= max; j++) {
				int k;

				if (i % j == 0) {
					int k = i / j;

					if ((min <= k) && (max >= k)
					    && (k != j)) {
						nr = nr + 1;
						exit = 1;
					}
				}
				if (exit == 1) {
					break;
				}
			}
		}
	}
	printf("%lli \n", nr);
	return 0;
}
