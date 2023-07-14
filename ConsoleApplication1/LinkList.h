#pragma once
#include "assistance.h"
typedef struct LNode {
	int data;
	LNode* next;
	LNode() {
		data = 0;
		next = NULL;
	}
} LNode, *LinkList;   //LNode��ʾ��ͨ�ڵ㣬LinkList��ʾͷ�ڵ�

//ͷ�巨
LinkList List_HeadInsert(LinkList& L) {
	LNode* s; int x;
	L = (LNode*)malloc(sizeof(LNode));  //ͷ�ڵ�
	L->next = NULL;
	cin >> x;
	for (int i = 0; i < 5; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

//β�巨
LinkList List_TailInsert(LinkList& L) {
	LNode* s,* r; int x;
	L = (LNode*)malloc(sizeof(LNode));  //ͷ�ڵ�
	r = L;
	cin >> x;
	for (int i = 0; i < 5; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	s->next = NULL;
	return L;
}

//����Ų���
LNode* GetElem(LinkList L, int i) {
	LNode* p = L;
	if (i < 1)
		return NULL;
	int j = 1;
	p = L->next;
	while (p != NULL && j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//��ֵ����
LNode* LocateElem(LinkList L, int e) {
	L = L->next;
	while (L != NULL&&L->data != e)
		L = L->next;
	return L;
}

//����ڵ�(�����ýڵ�����)
void InsertNode(LinkList& L, int i, LNode* e) { //�ڵ�i�����ǰ�����,ʱ�临�Ӷ�ΪO(n)
	LNode* p = GetElem(L, i-1);  //�ҵ�ǰ���ڵ�
	e->next = p->next;
	p->next = e;
}


//����ڵ�(�����ýڵ�ĵ�ַ)
void InsertNode_by_address(LinkList& L, LNode* s, LNode* p) { //��p���ǰ����s���,ʱ�临�Ӷ�ΪO(1)
	s->next = p->next;
	p->next = s;  //�Ƚ�s����p����
	int temp = s->data;
	s->data = p->data;
	p->data = temp;   //����s��p
}

//ɾ���ڵ�(�����ýڵ�����)
void DeleteNode(LinkList& L, int i) {
	LNode* p = GetElem(L, i - 1); //�ҵ�ǰ���ڵ�
	LNode* q = p->next;
	p->next = p->next->next;
	free(q);
}

//ɾ���ڵ�(�����ýڵ�ĵ�ַ)
void DeleteNode(LinkList& L, LNode* p) {  //ɾ��p��㣬ʱ�临�Ӷ�ΪO(1)
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;  //��p���Ƴɺ�̽�㣬Ȼ��ɾ����̽ڵ�
	free(q);
}

//��ת����,��ͷ�ڵ㲻��ת
void reverse(LinkList& L) {
	LNode* q = L->next;
	L->next = NULL;
	//��ʵ��ת�����ͷ�巨����ֻ������������һ��ָ��
	LNode* r;
	while (q != NULL)
	{
		/*  ͷ�巨
		q->next = L->next;
		L->next = q;
		q = q->next;
		*/

		//��ת
		r = q->next;
		q->next = L->next;
		L->next = q;
		q = r;
	}

}

//����
void Sort(LinkList &L) {
	//������ֳ����ݣ�����һ����Ϊ��ͷ,һ��Ϊ�������е�����
	LNode* p = L->next;
	L->next = NULL;
	
	while (p != NULL)
	{
		LNode* r = p->next; //�洢��̽ڵ�
		LNode* pre = L;
		while (pre->next != NULL && pre->next->data < p->data) //�ҳ���һ����p->data�������
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}

}



void ShowList(LinkList L) {
	while (L->next != NULL){
		cout << L->next->data << " ";
		L = L->next;
	}
	cout << endl;
}




/*����*/

//2009��ͳ����Ŀ��Ѱ�ҵ������е�����k�����
/*˼·
�տ�ʼ˼����ʱ�������߱�������һ�α����õ�������size���ڶ��α���size-k�μ��ɵõ�������k�����
һ�α����ķ���������˫ָ��
����ָ��p��q��һ��ʼp��������p�����k�����ʱ��q��ʼ�ƶ�����p����NULLʱ��q���ﵹ����k�����
*/
LNode* Search_k(LinkList L, int k) {
	LNode* p = L;
	LNode* q = L;
	for (int i = 0; i < k; i++) {
		p = p->next;
	}
	while (p != NULL) {
		p = p->next;
		q = q->next;
	}
	return q;
}
//2015��ͳ����Ŀ��ɾ��������data�ľ���ֵ��ȵĽ�㣬ֻ������һ��
/*
˼·��������ĿֻҪ��ʱ�临�Ӷȵͣ���˵��data<n�����Ժ���Ȼ���뵽��ϣ��
*/

int ABS(int x) {
	if (x < 0)
		return -x;
	else
		return x;
}

void func(LinkList &L, int n) {
	LNode* q = L;
	int* a = (int*)malloc(sizeof(int) * (n + 1)); //c�����в���дa[n]��ֻ�ܶ�̬����ռ�
	for (int i = 0; i < n + 1; i++) {
		*(a + i) = 0;
	}
	while (q->next != NULL)
	{
		int m = ABS(q->next->data);
		if (*(a + m) == 0) {
			*(a + m) = 1;
			q = q->next;
		}
			
		else
		{
			LNode* p = q->next;
			q->next = q->next->next;
			free(p);
		}
		
	}
	free(a);
}



//2019��ͳ����Ŀ����������a1 a2 a3...an-1 an ,�ĳ�a1 an a2 an-1 a3 ...  �ռ临�Ӷȱ���ΪO(1)
/*
˼·��һ��ʼ������ȵõ��ܳ��ȣ�Ȼ��һ��ָ��ָ��a1a2a3  һ��ָ��ָ��an an-1�����β���
����������an an-1 an-2������ģ�ÿһ�ζ�Ҫ����һ�����飬����ʱ�临�Ӷ���O(n2)
Ϊ��ʵ��O(n)����Ҫ����O(n)��ת����
*/

//��ת����,��ͷ�ڵ㲻��ת
void reverse1(LinkList& L) {
	LNode* q = L->next;
	L->next = NULL;
	LNode* r;
	while (q != NULL){
		r = q->next;
		q->next = L->next;
		L->next = q;
		q = r;
	}
}

void change_list(LinkList &L) {
	LNode* p, * q, * r, * s;
	p = q = L;
	//pÿ��һ����q��������
	while (q->next != NULL)
	{
		p = p->next;
		q = q->next;
		if (q->next != NULL)
			q = q->next;
			
	}
	//��ʱp�����м��㣬��p��Ϊ����һ�������ͷ�ڵ㣬�Ϳ���ʵ����ת
	reverse1(p);
	s = L->next; //p��Ϊǰ��εĵ�һ����
	q = p->next; //q��Ϊ���εĵ�һ����
	p->next = NULL; //��ʱp����β���
	while (q !=NULL)  //����ʱ��벿��С��ǰ�벿�֣�������q���ߵ�NULL
	{
		r = q->next;
		q->next = s->next;
		s->next = q;
		s = s->next->next;
		q = r;
	}
}
