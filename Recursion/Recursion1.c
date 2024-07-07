#include <stdio.h>

int recursive(int a);

void main() {
	int recur = recursive(10);
	int com = recur_commonpress(10);
	printf("%d \n", recur);
	printf("%d \n", com);
}

int recursive(int a) {

	if (a == 1) {
		return 1;
	}

	return recursive(a - 1) + 2 * (a - 1);


}

int recur_commonpress(int a) {
	return a * a - a + 1;
}