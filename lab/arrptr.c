// . . .   char temp[30] = { 10 };

// temp 는 배열이름이고 배열의 이름은 배열의 첫원소를 가리킨다" 이며, &temp 의 경우는 배열 전체에 대한 주소라고 합니다. 

//결국은 같은 값이지만
//
//배열의 타입이 다르다네요.첫번째는 char 의 포인터이고, 두번째는 char[10] 의 포인터.  (이건 저도 이번에 알았네요.)
//
//아래의 소스를 실행해보면 하나는 0x01 이 증가하고 하나는 0x10 이 증가하는 것을 볼 수 있습니다.

#include <cstdio>

int main()
{
	char temp[16] = { 10 };

	printf("%p\n", &temp + 1);
	printf("%p\n", temp + 1);

	return 0;
}