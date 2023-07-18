#pragma once
/*����������*/

#include "assistance.h"

//ltag:1��ʾleftָ��ǰ����0��ʾleftָ������
//rtag:1��ʾrightָ���̣�0��ʾrightָ���Һ���
typedef struct ThreadNode {
	int data;
	ThreadNode* left, * right;
	int ltag, rtag;
}*ThreadTree;


void InThread(ThreadTree& p, ThreadTree& pre) {
	if (p != NULL) {
		//�������,������
		InThread(p->left, pre); 

		//������������ڵ�
		if (p->left == NULL){ //������Ϊ��			
			p->left = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->right == NULL) {
			pre->right = p;
			pre->rtag = 1;
		}

		//���������������
		pre = p;
		InThread(p->right, pre);
	}
}


