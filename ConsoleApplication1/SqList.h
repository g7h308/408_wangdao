#pragma once

#include "assistance.h"

struct SqList{
	int *data;
	int length;  //当前长度
	int MaxSize; //最大长度
};

//初始化，默认长度为0
void InitList(SqList& L) {
	L.data = (int*)malloc(0*sizeof(int));
	L.length = 0;
	L.MaxSize = 50;
}

//新增长度
void IncreaseList(SqList& L,int len) {
	int length = L.length;
	int* p = L.data;   //p暂时复制data
	L.data = (int*)malloc((length + len)*sizeof(int));
	for (int i = 0; i < length; i++){
		L.data[i] = p[i];
	}

	L.length += len;
	free(p);
}

//插入
bool ListInsert(SqList& L, int i, int e) {
	/*
	注意这里是length+1而不是length，比如说现在数组里有3个数，如果我想差到数组的末尾，那就是插入第四位
	如果此时判定条件为i>length，则4>3，显然会返回false
	*/
	if (i<1 || i>L.length + 1)  
		return false;
	if (L.length >= L.MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;

}

//删除
bool ListDelete(SqList& L, int i,int e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}

//按值查找
int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

void ShowList(SqList& L) {
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << "   ";
	cout << "\n打印完毕\n" << endl;
}



