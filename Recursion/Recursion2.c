#include <stdio.h>

int fibo1(int n);
int fibo2(int n);

int main(void) {

	//int fib = fibo1(3);
	int fib1 = fibo2(3);

	//printf("%d \n", fib);
	printf("%d \n", fib1);

	return 0;
}

int fibo1(int n) {

	if (n == 0) {
		return 0;
	}
	else if (n <= 1) {
		return 1;
	}

	return fibo1(n + 2) - fibo1(n + 1);
}

int fibo2(int n) {

	if (n == 0) {
		return 0;
	}
	else if (n <= 1) {
		return 1;
	}

	return fibo2(n - 2) + fibo2(n - 1);
}