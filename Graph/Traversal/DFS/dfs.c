#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"
#include "adjList.h"


// dfs를 할때 방문 여부를 알려줄 배열에 대하여 인자로 전달할지 내부로 가질지 정할 수 있을것이다.
// dfs의 내부에는 방문 여부를 기록하는 배열을 포함한다.
// len: 탐색할 배열의 정점의 개수 -> 정점의 개수를 알게되면 불필요한 메모리낭비를 최소화할 수 있을 것이다.

void deepFirstSearch(graphType* graph) {
	// 비어있는 그래프인지 확인
	if (!(graph)) {
		printf("그래프 내부에 탐색할 곳이 없다.");
		return;
	}
	if (!(graph->adjMatrix_H[0])) {
		printf("그래프 내부에 탐색할 정점이 없다.");
		return;
	}
	int travel[MAX_VER] = { 0, };
	int searchToVertex = graph->adjMatrix_H[0]->vertex;
	graphNode* curNode = graph->adjMatrix_H[0]; 		// 탐색 시작은 항상 A부터 시작
	printf("DFS 탐색결과 \n");
	while (curNode) {
		// 다음 경로가 비어있을
		// 그래프 내의 연결 순서는 정렬되어있다 가정함.
		if (!(curNode)) {
			printf("탐색 끝");
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