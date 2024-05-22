#pragma once
#include <stdlib.h>
#include "node2.h"
#define MAX(a,b) ((a>b)?a:b)

treeNode* LL_rotate(treeNode* parent);
treeNode* RR_rotate(treeNode* parent);
treeNode* LR_rotate(treeNode* parent);
treeNode* RL_rotate(treeNode* parent);
int getHeight(treeNode* p);
int getBF(treeNode* p);
treeNode* reebalance(treeNode** p);
treeNode* insertAVLNode(treeNode** root, element x);