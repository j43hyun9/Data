#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"

// data�� ��Ʈ ���� �Ͽ� ���� ���� Ʈ���� ������ ���� Ʈ���� �����ϴ� ����
treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight) {
	treeThNode* root = (treeThNode*)malloc(sizeof(treeThNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->isThreadRight = isThreadRight;
	return root;
}

// �ļ��� ��带 ��ȯ�ϴ� ����
treeThNode* findThreadSuccessor(treeThNode* p) {
	treeThNode* q = p->right;		// p�� �ļ��� ��带 ����Ų�ٸ�, �ļ��� ����� �ּҰ��� �޾ƿ´�.
									// XOR , p�� ����Ű�� right�� NULL�̱⿡ NULL���� �޾ƿ´�.
	if (q == NULL) return q;		// q�� NULL �̶�� NULL�� ��ȯ�Ѵ�. if - return�� �� ��� ���� �ڵ���� if������ ������ false�ϋ��� �ǹ��Ѵ�.
	if (p->isThreadRight == 1) return q;	// q�� �ּҰ��� �ǹ��Ҷ� p�� ���� �ļ��� ��带 Ȯ���ϰ�(1) q�� ��ȯ�Ѵ�.
	while (q->left != NULL) q = q->left;    // �޾ƿ� ���� left���� ���� �ƴ϶�� q�� ������ ���� �̵��Ѵ�.
	return q;
}

// ������ ���� Ʈ���� ���� ��ȸ
void threadInorder(treeThNode* root) {
	treeThNode* q;
	q = root;
	while (q->left) q = q->left; // �� ���� �ܸ������� ������
	do {
		printf("%3c", q->data);		// 1. ���� �ܸ���忡�� data�� �а�
		q = findThreadSuccessor(q); // 2. q���� find..(q)���� ��ȯ����.
	} while (q);
}