#include <stdio.h>
#include <stdlib.h>
#include "adjList.h"


graphType* createGraph() {
	graphType* newNode = (graphType*)malloc(sizeof(graphType));
	newNode->v = 0;
	for (int i = 0; i < MAX_VER; i++) {
		newNode->adjMatrix_H[i] = NULL;
	}
	return newNode;
}
// ����ڰ� ���ϴ� �ɺ��� ������ �� �ֵ��� ������ �� �������̴�.
void insertVertex(graphType* g) {
	if (((g->v) + 1) > MAX_VER) {
		printf("�׷����� �� ������ �����ϴ�");
		return;
	}

	graphNode* Node = (graphNode*)malloc(sizeof(graphNode));
	Node->vertex = (g->v) + 1;
	Node->link = NULL;
	g->adjMatrix_H[(g->v)] = Node;
	printf("adj: %p", g->adjMatrix_H[(g->v)]);
	(g->v)++;
	printf("{%c}\n", g->v + 64);
}

void insertEdge(graphType* g, int from, int to) {
	// A->B->C
	// B->D->E
	// C->E
	// D->G
	// E->G
	// F->G
	// G->D->E->F
	// ����ڷκ��� ������ ��������Ʈ�� �Է¹޴°� �ܿ� �Ϲ������� ����� ���¸� ǥ���� ����� �ִ°�?
	// ����ڰ� '�׷���' ���ο� ���� ������ ���Ͽ� ������ �����Ϸ��� �õ��� �������̴�.
	if ((from > g->v) || (to > g->v)) {
		printf("�׷����� �������� �ʴ� �����Դϴ�.");
		return;
	}
	graphNode* head = g->adjMatrix_H[from-1];
	/*while (head->link) {
		head = head->link;
	}*/
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
	newNode->link = NULL;
	newNode->vertex = to;
	while (head->link) {
		head = head->link;
	}
	head->link = newNode;
	printf("{%c �� %c}\n", head->vertex + 64, head->link->vertex + 64);
}

void printGraph(graphType* g) {
	graphNode* node = NULL;
	graphNode* asd = NULL;
	int i = 0;
	node = g->adjMatrix_H[0];
	for (i = 0; node; i++) {
		node = g->adjMatrix_H[i];
		if (!(node)) {
			return;
		}
		asd = node;
		printf(" %d %p ", i, node);
		while (asd) {
			printf("%c", (asd->vertex + 64)); 
			if (asd->link != NULL)
				printf("��");
			asd=asd->link;
		}
		printf("\n");
	}
}