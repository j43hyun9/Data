#include <stdio.h>
#include <string.h>
#include "stackL.h"
#include "testPair.h"

// 수식의 괄호를 검사하는 연산
int testPair(char* exp) {
	char symbol, open_pair;
	// char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) { // exp의 길이만큼 loop문 돌림. / 수식의 길이만큼 loop문 돌림
		symbol = exp[i]; // exp의 길이를 차례대로 읽어옴.
		switch (symbol) {
			// (1) 왼쪽 괄호는 스택에 삽입한다. 
		case '(':
		case '[':
		case '{':
			push(symbol); break;
			// (2) 오른쪽 괄호를 읽으면,
		case ')':
		case ']':
		case '}':
			if (isStackEmpty()) return 0;	// 닫는 괄호일때, 만약 스택이 비어있다면 수식 오류임 즉 ,원하는대로 동작하는게 아님..
			else {
				// (2)-1 스택에서 마지막으로 읽은 괄호를 꺼냄
				open_pair = pop();
				// (2)-2 괄호 쌍이 맞는지 검사
				if ((open_pair == '(' && symbol != ')') || // open_pair == '(' 일때, true 즉, 정논리 동시에 symbol != ')' 일때, true 즉, 부논리 symbol이 ')' 이 아니라면 true 부논리가 섞일 경우 논리가 헷갈린다.
					(open_pair == '[' && symbol != ']') || // 조건문 처리에 대해서 각각의 특수한 경우에 대해서만 처리하였음.
					(open_pair == '{' && symbol != '}'))
					// (2)-3 괄호 쌍이 틀리면 수식 오류
					return 0;
				// (2)-4 괄호 쌍이 맞으면 다음 symbol 검사를 수행함.
				else
					break;
			}
		}
	}
	
	if (top == NULL) return 1;	// 수식 검사를 마친 후 스택이 공백이면 1을 반환
	else return 0;						// 공백이 아니면 0을 반환(수식 괄호 틀림)
}