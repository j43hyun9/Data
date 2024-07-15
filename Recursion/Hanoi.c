#include <stdio.h>

void h(int n);
void h1(int n);
void h2(int n);
int main(void) {
	printf("h(1) = 1 (if x==1 \n");
	printf("h(x) = h(x-1)\n");
	h(5);
	printf(" FDF h(x) = h(x-1), h(x-1), proceed( H(x) =  h(x-1), print(x), h(x-1) )\n");
	h1(5);
	printf(" FFD h(x) = h(x-1), h(x-1), proceed( H(x) =  h(x-1), h(x-1), print(x) )\n");
	h2(5);
	printf(" DFF h(x) = h(x-1), h(x-1), proceed( H(x) =  print(x), h(x-1), h(x-1) )\n ");
	getchar();
	return 1;
}


void h(int n) {
	if (n == 1) {
		printf("%d", n);
		return;
	}
	h(n - 1);
	printf("%d", n);
	h(n - 1);
}

void h1(int n) {
	if (n == 1) {
		printf("%d", n);
		return;
	}
	h1(n - 1);
	h1(n - 1);
	printf("%d", n);
}

void h2(int n) {
	if (n == 1) {
		printf("%d", n);
		return;
	}
	printf("%d", n);
	h2(n - 1);
	h2(n - 1);
}