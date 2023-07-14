#pragma once
#include "assistance.h"
typedef struct DNode {
	int data;
	DNode* next, * prior;
}DNode, *DLinkList;


//双链表的插入
DLinkList DList_Insert(DLinkList& L) {
	DNode* s; int x;
	L = (DNode*)malloc(sizeof(DNode));  //头节点
	L->next = NULL;
	cin >> x;
	for (int i = 0; i < 5; i++) {
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		s->next = L->next;
		s->prior = L;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
		cin >> x;
	}
	return L;
}

DNode* DLinkList_GetElem(DLinkList L, int i) {
	DNode* p = L;
	if (i < 1)
		return NULL;
	int j = 1;
	p = L->next;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//双链表的删除
void DLinkList_Delete(DLinkList& L, int i) {
	DNode* p = DLinkList_GetElem(L, i - 1);
	DNode* q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
}

void ShowDList(DLinkList L) {
	while (L != NULL) {
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;

}




//双链表的删除
