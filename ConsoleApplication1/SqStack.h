#pragma once
#include "assistance.h"

#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack& S) {
	S.top = -1;   //初始栈顶指针设置为-1；
}

bool StackEmpty(SqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}

//进栈
bool Push(SqStack& S, int x) {
	if (S.top == MaxSize - 1)
		return false;  //栈满
	else {
		S.data[++S.top] = x;
		return true;
	}
}

//出栈

bool Pop(SqStack& S, int& x) {
	if (S.top == -1)
		return false;
	else
	{
		x = S.data[S.top--];
		return true;
	}
}

//读取栈顶元素
bool GetTop(SqStack S, int& x) {
	if (S.top == -1)
		return false;
	else
	{
		x = S.data[S.top];
		return true;
	}
}



