#pragma once
#include "assistance.h"

//������������ʽ��ѭ������ ��ʽ����




/*-------------˳��-------------*/
#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int front,rear; //ͷָ���βָ��
}SqQueue;

void InitSqQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}

/*
�п�������Q.front == Q.rear
����������(Q.rear+1)%MaxSize == Q.front
�������Ԫ�ظ�����(Q.rear-Q.front+MaxSize)%MaxSize
*/

bool isEmpty(SqQueue& Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

bool EnQueue(SqQueue& Q, int x) {
	if ((Q.rear + 1) % MaxSize == Q.front)
		return false;
	else
	{
		Q.data[Q.rear] = x;
		Q.rear = (Q.rear + 1) % MaxSize;
		return true;
	}
}

bool DeQueue(SqQueue& Q, int& x) {
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}



/*-------------��ʽ-------------*/

typedef struct {
	int data;
	LinkNode* next;
}LinkNode;


typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


/*
�п�������Q.front == NULL && Q.rear == NULL 
����������(Q.rear+1)%MaxSize == Q.front
�������Ԫ�ظ�����(Q.rear-Q.front+MaxSize)%MaxSize
*/

void InitLinkQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) return true;
	else return false;
}

void EnQueue(LinkQueue& Q, int x) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear) //�ն���
		return false;
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (p == Q.rear) //˵����ʱ������ɾ��p֮���ֻʣ��ͷ�����  
		Q.rear = Q.front;
	free(p);
	return true;
}




