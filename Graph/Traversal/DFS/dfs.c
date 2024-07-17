#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"
#include "adjList.h"


// dfs�� �Ҷ� �湮 ���θ� �˷��� �迭�� ���Ͽ� ���ڷ� �������� ���η� ������ ���� �� �������̴�.
// dfs�� ���ο��� �湮 ���θ� ����ϴ� �迭�� �����Ѵ�.
// len: Ž���� �迭�� ������ ���� -> ������ ������ �˰ԵǸ� ���ʿ��� �޸𸮳��� �ּ�ȭ�� �� ���� ���̴�.

void deepFirstSearch(graphType* graph) {
	// ����ִ� �׷������� Ȯ��
	if (!(graph)) {
		printf("�׷��� ���ο� Ž���� ���� ����.");
		return;
	}
	if (!(graph->adjMatrix_H[0])) {
		printf("�׷��� ���ο� Ž���� ������ ����.");
		return;
	}
	int travel[MAX_VER] = { 0, };
	int searchToVertex = graph->adjMatrix_H[0]->vertex;
	graphNode* curNode = graph->adjMatrix_H[0]; 		// Ž�� ������ �׻� A���� ����
	printf("DFS Ž����� \n");
	while (curNode) {
		// ���� ��ΰ� �������
		// �׷��� ���� ���� ������ ���ĵǾ��ִ� ������.
		if (!(curNode)) {
			printf("Ž�� ��");
			return;
		}
		while (curNode) {
			if (travel[searchToVertex - 1] != 1) {
				searchVertexPrint(searchToVertex);
				travel[searchToVertex - 1] = 1;
				break;
			}
			else {
				curNode = curNode->link;
				searchToVertex = curNode->vertex;
			}
		}
		
		curNode = graph->adjMatrix_H[searchToVertex-1];
	}

}

void searchVertexPrint(int vertex) {
	printf("{%c}\n", vertex + 64);
}