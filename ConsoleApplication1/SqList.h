#pragma once

#include "assistance.h"

struct SqList{
	int *data;
	int length;  //��ǰ����
	int MaxSize; //��󳤶�
};

//��ʼ����Ĭ�ϳ���Ϊ0
void InitList(SqList& L) {
	L.data = (int*)malloc(0*sizeof(int));
	L.length = 0;
	L.MaxSize = 50;
}

//��������
void IncreaseList(SqList& L,int len) {
	int length = L.length;
	int* p = L.data;   //p��ʱ����data
	L.data = (int*)malloc((length + len)*sizeof(int));
	for (int i = 0; i < length; i++){
		L.data[i] = p[i];
	}

	L.length += len;
	free(p);
}

//����
bool ListInsert(SqList& L, int i, int e) {
	/*
	ע��������length+1������length������˵������������3������������������ĩβ���Ǿ��ǲ������λ
	�����ʱ�ж�����Ϊi>length����4>3����Ȼ�᷵��false
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

//ɾ��
bool ListDelete(SqList& L, int i,int e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}

//��ֵ����
int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

void ShowList(SqList& L) {
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << "   ";
	cout << "\n��ӡ���\n" << endl;
}



