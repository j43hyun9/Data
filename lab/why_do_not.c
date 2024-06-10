#include <stdio.h>
#include <stdlib.h>

// Tlqkf stdlib 이 없어서 Tlqkf
// 인접 리스트의 노드 구조를 구조체로 정의
typedef struct graphNode {
	int vertex;						// 정점을 나타내는 데이터 필드
	struct graphNode* link;	
} graphNode;
typedef struct graphType {
	int n;										// 그래프의 정점 개수
	graphNode* adjList_H[30];		// 그래프 정점에 대한 헤드 포인터 배열
}graphType;

int main() {
	graphType* test = (graphType*)malloc(sizeof(graphType));
	test->n = 0;
}