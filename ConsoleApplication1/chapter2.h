#pragma once
#include"LinkList.h"
void fun1(LinkList& L, int x,LNode* a) {
	LNode* p;
	if (L == NULL)
		return;
	if (L->data == x) {
		p = L;
		L = L->next; //这一步就已经完成了上一个结点next连接到下一个结点的next
		/*
		* 我们假设上一层递归中的L为L1  则这一层递归中的L=L1->next
		* 所以L=L->next就变成了L1->next = L1->next->next，这样就已经完成了脱链这一操作
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

//第三题由两种思路：将链表逆置，使用栈/递归

void fun3_1(LinkList L) { //逆置
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

//第五题 逆置 

//第六题 排序 递增


/*
如果两个链表有一个公共结点，则这个结点后面的结点也都是公共结点，因为next只有一个出口
所以这都题目的本质是找到两个链表的公共后缀
如果两个链表的长度一样，那就很简单，两个指针分别指向两个链表，一个个扫描，找到的第一个相同指针就是公共后缀的首结点
但如果二者长度不相等，那就需要先计算两个链表的长度（假设为m和n，且m>n），然后将长的那条指针先移动m-n位，
保证二者从同一位置出发（由于公共部分是后缀，所以不必担心移动的这m-n段里有公共结点）
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

	//将两个链表拉回同一起跑线
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

