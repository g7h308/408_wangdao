#pragma once
#include "assistance.h"
#include "BiTree.h"


/*
��19�⣺��Ȩ·�����ȣ�Ҷ�ӽ�����ȳ���Ȩֵ   ������˼·����������Ͳ�α���
*/
//����Ҫ����ṹ�壬ֻ��Ҫ��BiTree�е�data����weight����

void WPL1(BiTree root, int depth, int& sum) {
	if (root->left == NULL && root->right == NULL)
		sum += root->data * depth;
	if (root->left != NULL)
		WPL1(root->left, depth + 1, sum);
	if (root->right != NULL)
		WPL1(root->right, depth + 1, sum);
}

int WPL2(BiTree root) {
	//��STL��queue�ܺ�д
	/*
	queue<BiTree> q;
	q.push(root);
	int depth = 0;
	int sum = 0;
	while (!q.empty())
	{
		depth++;
		int size = q.size();
		for (int i = 0; i < size(); i++) {
			BiTNode* node = q.front();
			q.pop();
			if (node->left != NULL) q.push(node->left);
			if (node->right != NULL) q.push(node->right);
			if (node->right == NULL && node->left == NULL)
				sum += depth * node->data;
		}
	}
	return sum;
	*/


	//���ǿ��Բ�����STL�⣬Ҫ�Լ�дһ������
	//�Լ�д�Ķ����޷�ʹ��size()������������Ҫ����lastNode��newLastNode���������ʵ�����ƵĹ���

	BiTree q[100];  //�½����У�����Ϊ100
	int front, rear;  //��ͷ����βָ��
	front = rear = 0;
	int sum = 0, depth = 0;  //ע�⣺·������Ϊ��ȼ�һ����������depth��0��ʼ���Ǵӿ�ʼ
	BiTree lastNode;  //��¼��ǰһ������һ�����
	BiTree newlastNode = NULL; //��¼��ǰһ�����һ������һ�����
	lastNode = root;//��ʼ��ǰһ������һ�������Ȼ��root
	q[rear++] = root; //���
	while (front != rear) {  //����Ϊ��ʱѭ������
		BiTree node = q[front++];  //ȡ�������е�һ��Ԫ��
		if (node->left != NULL) {
			q[rear++] = node->left;
			newlastNode = node->left;
		}
		if (node->right != NULL) {
			q[rear++] = node->right;
			newlastNode = node->right;
		}
		if (node->right == NULL && node->left == NULL) 
			sum += depth * node->data;
		if (node == lastNode) {  //˵���Ѿ�����������һ��ĶԺ�һ����㣬depth��+1��
			depth++;
			lastNode = newlastNode;
		}
	}
	return sum;
}


int fun19_1(BiTree root) {
	int sum = 0;
	//WPL1(root, 0, sum);
	sum = WPL2(root);
	return sum;
}


/*
20�⣺���������������
*/
//����Ҫ����ṹ�壬ֻ��Ҫ��BiTree�е�data����char����
//����һ��char���飬����˵char c[10]  ,��ʱ����֪��c���浽���м���Ԫ�أ�ֱ�����cout << c���ɴ�ӡ����ķǿ�Ԫ�أ�c����������printf("%s",c);

void fun20(BiTree root,int depth) { //ע�⵽����������㲻��Ҫ�����ţ�����depthΪ1ʱ�������ţ��������������  
	if (root == NULL)
		return;
	else if(root->left == NULL && root->right == NULL)  //Ҷ�ӽ���������
		cout << root->data;
	else {  //��Ҷ�ӽ�㣬�Ǹ��ڵ�
		if (depth > 1)
			cout << "(";
		fun20(root->left, depth + 1);
		cout << root->data;
		fun20(root->right, depth + 1);
		if (depth > 1)
			cout << ")";
	}
}


/*
21�⣺

˼·1��������������Ҫ���������������1. �������Ƕ��������� 2. �������Ƕ��������� 3. �м������ǰ���ڵ�
˼·1��������������������õ������б����������Կ������������һ��õ����飬�ж���������Ƿ����򼴿�
*/


#define maxsize 50
typedef struct {
	int SqBiTNode[maxsize];
	int ElemNum;    //ʵ��ռ������Ԫ�صĸ���
}SqBiTree;

//˼·һ
int pre = 0;
bool fun21_1(SqBiTree bt, int i) {
	if (bt.SqBiTNode[i] == -1) //�ս��Ҳ�Ƕ���������
		return true;
	if (fun21_1(bt, 2 * i + 1) == false)
		return false;
	if (pre >= bt.SqBiTNode[i])
		return false;
	pre = bt.SqBiTNode[i];
	if (fun21_1(bt, 2 * i + 2) == false)
		return false;
	return true;
}

//˼·���ܼ򵥣��Ͳ�д��
