#include <stdio.h>

void Hanoi(int x);
void recurHanoi(int num, char from, char by, char to);

int main(void) {
	int x = 5;
	for (int casee = 1; casee <= x; casee++) {
		printf("\ncase %d\n", casee);
		Hanoi(casee);
	}

	for (int casee = 1; casee <= x; casee++) {
		printf("\ncase %d\n", casee);
		recurHanoi(casee, 'A', 'B', 'C');
	}
	getchar();


	// ����ڴ� ���ǿ� 0 < x <= 100 �̳����� x���� ������ ���� �ϳ���ž�� �̵������� ���� �� �ִ�.
	// �� x��° ������ �ֱⰪ�� �������̰� ���� ���� ��ġ�� �ֱⰪ�� -1 �̴� ���� ī������ �ʱ�ȭ �Ͽ� �����ϰ� �����ų �� �������̴�.
 //1248
	//        111 1111
}//1234 5678 9012 3456  
// 1213 1214 1213 1215
// 11
// 1:  1  1,3,5,7,9 .... (1)an = 2n-1
// 2:  2  2,6,10,14 .... (2)an = 2n+4
void Hanoi(int x) {
	// �Է¹��� x�� ��ŭ�� �ڿ��� �������� �����Ǹ� �̵� ������ �ڿ������� �ֱ⸦ �����ִ�.
	int num[100] = { 0, };
	int num_cnt[100] = { 0, };
	int a = 2;
	for (int i = 1; i <= x; i++) {
		num_cnt[i] = a / 2;
		num[i] = a;
		if (i != x) {
			a *= 2;
		}
		else continue;
	}
	for (int i = 1; i <= a-1; i++) { 
		for (int j = 1; j <= x; j++) {
			num_cnt[j]++;
		}
		for (int j = 1; j <= x; j++) {
			if (!(num_cnt[j] % num[j])) {
				printf("%d", j);
				num_cnt[j] = 0;
			}
		}
	}
}

void recurHanoi(int num, char from, char by, char to) {
	if (num == 1) {
		printf("%d %c %c\n", 1, from, to);
		return;
	}
	Hanoi(num - 1, from, to, by);        // ���� n-1���� A���� B�� �Ű��ش�.
	printf("%d %c %c\n", num, from, to); // n-1���� �Ű������� n���� ������ �Ű��ش�.
	Hanoi(num - 1, by, to, from);        // n-1�� ������ �ٽ� �Ű��ش�.
}