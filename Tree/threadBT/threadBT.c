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
	treeThNode* q = p->right;		// p�� ���� ������ ��ũ�� ���޹޴´�.
	if (q == NULL) return q;		// ���� ������ ��ũ�� NULL�̶�� q(NULL)�� ��ȯ�Ѵ�.
	// �������� �ٷ� Ʈ���� ��� ������ ��ũ�� NULL�� ���� ���� ���������� ������ Ʈ���� �ܸ������ ��ũ�϶����̴�.
	if (p->isThreadRight == 1) return q;
	// isThreadRight���� 1�� ��� ó���� ������ ������ ����Ʈ���� ��Ģ�� ���ؼ� ��ũ�� �����带 ����Ų��.
	// ���� q�� ������ �ִ� ���� �������� ��ũ�̱� ������ �״�� ��ȯ�Ѵ�.
	// �ǹ��� i) NULL�϶� , 1�϶�, 0�ϋ�,�� ���� "�������� ��ũ�� ��" �� ���� �ڿ�� ������ ����� ���°�?
	while (q->left != NULL) q = q->left;
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