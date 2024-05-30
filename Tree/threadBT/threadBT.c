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
	treeThNode* q = p->right;		// p가 후속자 노드를 가리킨다면, 후속자 노드의 주소값을 받아온다.
									// XOR , p가 가리키는 right는 NULL이기에 NULL값을 받아온다.
	if (q == NULL) return q;		// q가 NULL 이라면 NULL을 반환한다. if - return이 낄 경우 이후 코드들은 if문안의 내용이 false일떄를 의미한다.
	if (p->isThreadRight == 1) return q;	// q가 주소값을 의미할때 p를 통해 후속자 노드를 확인하고(1) q를 반환한다.
	while (q->left != NULL) q = q->left;    // 받아온 값의 left값이 널이 아니라면 q의 왼쪽의 노드로 이동한다.
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