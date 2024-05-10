#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight) {
	treeThNode* root = (treeThNode*)malloc(sizeof(treeThNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->isThreadRight = isThreadRight;
	return root;
}

// 후속자 노드를 반환하는 연산
treeThNode* findThreadSuccessor(treeThNode* p) {
	treeThNode* q = p->right;		// p를 통해 오른쪽 링크를 전달받는다.
	if (q == NULL) return q;		// 만약 오른쪽 링크가 NULL이라면 q(NULL)을 반환한다.
	// 예제에서 다룬 트리의 경우 오른쪽 링크가 NULL일 때는 오직 마지막이자 오른쪽 트리의 단말노드의 링크일때뿐이다.
	if (p->isThreadRight == 1) return q;
	// isThreadRight값이 1일 경우 처음에 세웠던 스레드 이진트리의 규칙에 의해서 링크는 스레드를 가리킨다.
	// 따라서 q가 가지고 있는 값이 스레드의 링크이기 때문에 그대로 반환한다.
	// 의문점 i) NULL일때 , 1일때, 0일떄,와 같이 "스레드의 링크일 때" 와 같은 자연어에 대응할 방법은 없는가?
	while (q->left != NULL) q = q->left;
	return q;
}

// 스레드 이진 트리의 중위 순회
void threadInorder(treeThNode* root) {
	treeThNode* q;
	q = root;
	while (q->left) q = q->left; // 맨 왼쪽 단말노드까지 내려옴
	do {
		printf("%3c", q->data);		// 1. 최초 단말노드에서 data를 읽고
		q = findThreadSuccessor(q); // 2. q값에 find..(q)값을 반환받음.
	} while (q);
}