#include <stdio.h>
#include <stdlib.h>

// Tlqkf stdlib �� ��� Tlqkf
// ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct graphNode {
	int vertex;						// ������ ��Ÿ���� ������ �ʵ�
	struct graphNode* link;	
} graphNode;
typedef struct graphType {
	int n;										// �׷����� ���� ����
	graphNode* adjList_H[30];		// �׷��� ������ ���� ��� ������ �迭
}graphType;

int main() {
	graphType* test = (graphType*)malloc(sizeof(graphType));
	test->n = 0;
}