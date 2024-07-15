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


	// 사용자는 정의역 0 < x <= 100 이내에서 x개의 원판을 가진 하노이탑의 이동순서를 구할 수 있다.
	// 각 x번째 수들은 주기값을 가질것이고 최초 등장 위치가 주기값의 -1 이다 이후 카운팅을 초기화 하여 일정하게 등장시킬 수 있을것이다.
 //1248
	//        111 1111
}//1234 5678 9012 3456  
// 1213 1214 1213 1215
// 11
// 1:  1  1,3,5,7,9 .... (1)an = 2n-1
// 2:  2  2,6,10,14 .... (2)an = 2n+4
void Hanoi(int x) {
	// 입력받은 x개 만큼의 자연수 서수들이 생성되며 이들 각각의 자연수들은 주기를 갖고있다.
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
	Hanoi(num - 1, from, to, by);        // 원판 n-1개를 A에서 B로 옮겨준다.
	printf("%d %c %c\n", num, from, to); // n-1개가 옮겨졌으니 n번쨰 원반을 옮겨준다.
	Hanoi(num - 1, by, to, from);        // n-1개 원판을 다시 옮겨준다.
}