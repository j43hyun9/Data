#include <stdio.h>
#include "stackL.h"
#include "adjList.h"
#include "dfs.h"
#include <stdlib.h>

int main(void) {
	
	// 그래프 G9의 깊이 우선 탐색을 위한 초기 상태 : 배열 visited를 false로 초기화하고 공백 스택 생성한다.
	int visited[10] = { 0, };

	stackNode* Node = (stackNode*)malloc(sizeof(stackNode));

	Node->data = -1;
	Node->link = NULL;
	top = Node;

	graphType* g1 = createGraph();

	insertVertex(g1); // A1
	insertVertex(g1); // B2
	insertVertex(g1); // C3
	insertVertex(g1); // D4
	insertVertex(g1); // E5
	insertVertex(g1); // F6
	insertVertex(g1); // G7

	insertEdge(g1, 1, 2);
	insertEdge(g1, 1, 3); // A -> B -> C

	insertEdge(g1, 2, 1);
	insertEdge(g1, 2, 4); // B
	insertEdge(g1, 2, 5);

	insertEdge(g1, 3, 1);
	insertEdge(g1, 3, 5); // C

	insertEdge(g1, 4, 2);
	insertEdge(g1, 4, 7); // D

	insertEdge(g1, 5, 2);   // E
	insertEdge(g1, 5, 3);   // E
	insertEdge(g1, 5, 7);   // E

	insertEdge(g1, 6, 7);   // E

	insertEdge(g1, 7, 4);   // E
	insertEdge(g1, 7, 5);   // E
	insertEdge(g1, 7, 6);   // E
	printGraph(g1);
	deepFirstSearch(g1);

	
	getchar();
	return 0;

}