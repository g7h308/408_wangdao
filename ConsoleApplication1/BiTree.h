#pragma once
#include "assistance.h"

typedef struct BiTNode {
	int data;
	struct BiTNode* left, * right;
    BiTNode() {
        data = 0;
        left = right = NULL;
    }
}*BiTree;



//ǰ�����
void PreOrder(BiTree T) {
	if (T != NULL) {
		cout << T->data << " ";
		PreOrder(T->left);
		PreOrder(T->right);
	}
}

//�������
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->left);
		cout << T->data << " ";
		InOrder(T->right);
	}
}

//�������
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->left);
		PostOrder(T->right);
		cout << T->data << " ";
	}
}



//�����в���ڵ�
void BiTree_InsertNode(BiTree &root, int data)
{
    //������ڵ㲻����
    if (root == NULL)
    {
        root = (BiTNode*)malloc(sizeof(BiTNode));
        root->data = data;
        root->left = root->right = NULL;
        return;
    }

    //������ڵ����
    BiTNode* currNode = root;
    BiTNode* preNode = root;
    bool  isleft = true; //����һ����ǣ�������¼���ݲ����λ��
    while (currNode != NULL)
    {
        preNode = currNode;
        if (data > currNode->data)
        {
            currNode = currNode->left;
            isleft = true;
        }
        else
        {
            currNode = currNode->right;
            isleft = false;
        }
    }

    //�����½ڵ�
    BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    //���ݱ�����ж��½ڵ�����λ��
    if (isleft)
        preNode->left = newNode; //ѭ��������ڵ�Ϊ�գ�����ڵ㵽��λ��
    else
        preNode->right = newNode;//ѭ�������ҽڵ�Ϊ�գ�����ڵ㵽��λ��
}


void LevelOrder(BiTree T) {
    queue<BiTree> q;
    BiTree p;
    q.push(T);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->left != NULL)
            q.push(p->left);
        if (p->right != NULL)
            q.push(p->right);
    }
}




