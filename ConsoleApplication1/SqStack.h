#pragma once
#include "assistance.h"

#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack& S) {
	S.top = -1;   //��ʼջ��ָ������Ϊ-1��
}

bool StackEmpty(SqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}

//��ջ
bool Push(SqStack& S, int x) {
	if (S.top == MaxSize - 1)
		return false;  //ջ��
	else {
		S.data[++S.top] = x;
		return true;
	}
}

//��ջ

bool Pop(SqStack& S, int& x) {
	if (S.top == -1)
		return false;
	else
	{
		x = S.data[S.top--];
		return true;
	}
}

//��ȡջ��Ԫ��
bool GetTop(SqStack S, int& x) {
	if (S.top == -1)
		return false;
	else
	{
		x = S.data[S.top];
		return true;
	}
}



