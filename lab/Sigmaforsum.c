#include <stdio.h>

int main(void) {

	long long n;
	scanf("%lld", &n);
	printf("%lld", ((n * n * n) - (3 * n * n) + 2 * n) / 6);
	printf("\n%d", 3);
	return 0;
}