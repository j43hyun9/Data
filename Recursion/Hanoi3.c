#include <stdio.h>

int main(void) {
	h(5, 'A', 'B', 'C');
}

void h(int n, char from, char to, char h) {
	int power = 1;
	
	if (n == 1) {
		printf("%d", n);
		return;
	}
	for (int i = 0; i < 5; i++)
		power *= 2;
}