#include <stdio.h>

int main(void) {



	return 1;
}


void h(int x) {
	int num = 1;
	int num2 = 1;
	int cnt = 1;
	int col = 1;
	printf("%d", 1);

	for (int i = 0; i < x; i++) 
		num *= 2;

	for (int i = 0; i < num; i++) {
		num2 *= 2;
		if (cnt % num2 == 0) {
			printf("%d", num / 2);
		}
		cnt++;
		if (cnt > x)
			cnt = 0;
	}

}