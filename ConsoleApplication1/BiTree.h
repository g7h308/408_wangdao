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



//前序遍历
void PreOrder(BiTree T) {
	if (T != NULL) {
		cout << T->data << " ";
		PreOrder(T->left);
		PreOrder(T->right);
	}
}

//中序遍历
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->left);
		cout << T->data << " ";
		InOrder(T->right);
	}
}

//后序遍历
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->left);
		PostOrder(T->right);
		cout << T->data << " ";
	}
}



//向树中插入节点
void BiTree_InsertNode(BiTree &root, int data)
{
    //如果根节点不存在
    if (root == NULL)
    {
        root = (BiTNode*)malloc(sizeof(BiTNode));
        root->data = data;
        root->left = root->right = NULL;
        return;
    }

    //如果根节点存在
    BiTNode* currNode = root;
    BiTNode* preNode = root;
    bool  isleft = true; //这是一个标记，用来记录数据插入的位置
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

    //创建新节点
    BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    //根据标记来判断新节点插入的位置
    if (isleft)
        preNode->left = newNode; //循环到最左节点为空，插入节点到该位置
    else
        preNode->right = newNode;//循环到最右节点为空，插入节点到该位置
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




