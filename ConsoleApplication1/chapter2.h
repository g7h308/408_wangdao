#pragma once
#include"LinkList.h"
void fun1(LinkList& L, int x,LNode* a) {
	LNode* p;
	if (L == NULL)
		return;
	if (L->data == x) {
		p = L;
		L = L->next; //��һ�����Ѿ��������һ�����next���ӵ���һ������next
		/*
		* ���Ǽ�����һ��ݹ��е�LΪL1  ����һ��ݹ��е�L=L1->next
		* ����L=L->next�ͱ����L1->next = L1->next->next���������Ѿ������������һ����
		*/
		free(p);
		fun1(L, x, a);
	}
	else{
		fun1(L->next, x, a);
	}
}


void fun2(LinkList& L, int x) {
	LNode* p = L;
	while (p != NULL && p->next != NULL)
	{
		if (p->next->data == x)
		{
			LNode* q = p->next;
			p->next = q->next;
			free(q);
		}
		p = p->next;
	}
}

//������������˼·�����������ã�ʹ��ջ/�ݹ�

void fun3_1(LinkList L) { //����
	LNode* p = L->next;
	L->next = NULL;
	LNode* r;
	while (p !=NULL)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	while (L->next != NULL)
	{
		cout << L->next->data << " ";
		L = L->next;
	}
	cout << endl;

}

void fun3_2(LinkList L) {
	if (L->next != NULL)
		fun3_2(L->next);
	if (L != NULL) cout << L->data << " ";
}


void fun4(LinkList& L) {
	LNode* p = L;
	LNode* min = NULL;
	int mindata = INT_MAX;
	while (p->next != NULL)
	{
		if (p->next->data < mindata) {
			min = p;
			mindata = p->next->data;
		}
			
		p = p->next;
	}
	LNode* q = min->next;
	min->next = q->next;
	free(q);
}

//������ ���� 

//������ ���� ����


/*
�������������һ��������㣬�����������Ľ��Ҳ���ǹ�����㣬��Ϊnextֻ��һ������
�����ⶼ��Ŀ�ı������ҵ���������Ĺ�����׺
�����������ĳ���һ�����Ǿͺܼ򵥣�����ָ��ֱ�ָ����������һ����ɨ�裬�ҵ��ĵ�һ����ָͬ����ǹ�����׺���׽��
��������߳��Ȳ���ȣ��Ǿ���Ҫ�ȼ�����������ĳ��ȣ�����Ϊm��n����m>n����Ȼ�󽫳�������ָ�����ƶ�m-nλ��
��֤���ߴ�ͬһλ�ó��������ڹ��������Ǻ�׺�����Բ��ص����ƶ�����m-n�����й�����㣩
*/

int GetLength(LinkList L) {
	int len = 0;
	while (L->next !=NULL)
	{
		len++;
		L = L->next;
	}
	return len;
}
LinkList fun8(LinkList L1,LinkList L2) {
	int m = GetLength(L1);
	int n = GetLength(L2);
	int dist = abs(m-n);

	//��������������ͬһ������
	if (m > n) {
		while (dist != 0) {
			L1 = L1->next;
			dist--;
		}
			
	}
	else{
		while (dist != 0) {
			L2 = L2->next;
			dist--;
		}
			
	}
	while (L1->next != NULL)
	{
		if (L1->next == L2->next)
			return L1->next;
		else
		{
			L1 = L1->next;
			L2 = L2->next;
		}
	}
	return NULL;
}

