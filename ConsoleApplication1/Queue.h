#pragma once
#include "assistance.h"

//队列有两种形式：循环队列 链式队列




/*-------------顺序-------------*/
#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int front,rear; //头指针和尾指针
}SqQueue;

void InitSqQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}

/*
判空条件：Q.front == Q.rear
判满条件：(Q.rear+1)%MaxSize == Q.front
队列里的元素个数：(Q.rear-Q.front+MaxSize)%MaxSize
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



/*-------------链式-------------*/

typedef struct {
	int data;
	LinkNode* next;
}LinkNode;


typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


/*
判空条件：Q.front == NULL && Q.rear == NULL 
判满条件：(Q.rear+1)%MaxSize == Q.front
队列里的元素个数：(Q.rear-Q.front+MaxSize)%MaxSize
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
	if (Q.front == Q.rear) //空队列
		return false;
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (p == Q.rear) //说明此时链表中删除p之后就只剩下头结点了  
		Q.rear = Q.front;
	free(p);
	return true;
}




