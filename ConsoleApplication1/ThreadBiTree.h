#pragma once
/*线索二叉树*/

#include "assistance.h"

//ltag:1表示left指向前驱，0表示left指向左孩子
//rtag:1表示right指向后继，0表示right指向右孩子
typedef struct ThreadNode {
	int data;
	ThreadNode* left, * right;
	int ltag, rtag;
}*ThreadTree;


void InThread(ThreadTree& p, ThreadTree& pre) {
	if (p != NULL) {
		//中序遍历,左子树
		InThread(p->left, pre); 

		//中序遍历，根节点
		if (p->left == NULL){ //左子树为空			
			p->left = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->right == NULL) {
			pre->right = p;
			pre->rtag = 1;
		}

		//中序遍历，右子树
		pre = p;
		InThread(p->right, pre);
	}
}


