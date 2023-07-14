#pragma once
#include "assistance.h"
typedef struct LNode {
	int data;
	LNode* next;
	LNode() {
		data = 0;
		next = NULL;
	}
} LNode, *LinkList;   //LNode表示普通节点，LinkList表示头节点

//头插法
LinkList List_HeadInsert(LinkList& L) {
	LNode* s; int x;
	L = (LNode*)malloc(sizeof(LNode));  //头节点
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

//尾插法
LinkList List_TailInsert(LinkList& L) {
	LNode* s,* r; int x;
	L = (LNode*)malloc(sizeof(LNode));  //头节点
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

//按序号查找
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

//按值查找
LNode* LocateElem(LinkList L, int e) {
	L = L->next;
	while (L != NULL&&L->data != e)
		L = L->next;
	return L;
}

//插入节点(给出该节点的序号)
void InsertNode(LinkList& L, int i, LNode* e) { //在第i个结点前面插入,时间复杂度为O(n)
	LNode* p = GetElem(L, i-1);  //找到前驱节点
	e->next = p->next;
	p->next = e;
}


//插入节点(给出该节点的地址)
void InsertNode_by_address(LinkList& L, LNode* s, LNode* p) { //在p结点前插入s结点,时间复杂度为O(1)
	s->next = p->next;
	p->next = s;  //先将s放在p后面
	int temp = s->data;
	s->data = p->data;
	p->data = temp;   //交换s和p
}

//删除节点(给出该节点的序号)
void DeleteNode(LinkList& L, int i) {
	LNode* p = GetElem(L, i - 1); //找到前驱节点
	LNode* q = p->next;
	p->next = p->next->next;
	free(q);
}

//删除节点(给出该节点的地址)
void DeleteNode(LinkList& L, LNode* p) {  //删除p结点，时间复杂度为O(1)
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;  //将p复制成后继结点，然后删除后继节点
	free(q);
}

//逆转链表,但头节点不逆转
void reverse(LinkList& L) {
	LNode* q = L->next;
	L->next = NULL;
	//其实逆转链表和头插法很像，只不过多增加了一个指针
	LNode* r;
	while (q != NULL)
	{
		/*  头插法
		q->next = L->next;
		L->next = q;
		q = q->next;
		*/

		//逆转
		r = q->next;
		q->next = L->next;
		L->next = q;
		q = r;
	}

}

//排序
void Sort(LinkList &L) {
	//将链表分成两份，其中一份作为表头,一份为即将排列的数据
	LNode* p = L->next;
	L->next = NULL;
	
	while (p != NULL)
	{
		LNode* r = p->next; //存储后继节点
		LNode* pre = L;
		while (pre->next != NULL && pre->next->data < p->data) //找出第一个比p->data大的数据
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




/*真题*/

//2009年统考题目：寻找单链表中倒数第k个结点
/*思路
刚开始思考的时候是两边遍历，第一次遍历得到链表长度size，第二次遍历size-k次即可得到倒数第k个结点
一次遍历的方法：快慢双指针
两个指针p和q，一开始p遍历，当p到达第k个结点时，q开始移动，当p到达NULL时，q到达倒数第k个结点
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
//2015年统考题目：删除链表中data的绝对值相等的结点，只保留第一个
/*
思路：由于题目只要求时间复杂度低，且说明data<n，所以很自然联想到哈希表
*/

int ABS(int x) {
	if (x < 0)
		return -x;
	else
		return x;
}

void func(LinkList &L, int n) {
	LNode* q = L;
	int* a = (int*)malloc(sizeof(int) * (n + 1)); //c语言中不能写a[n]，只能动态申请空间
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



//2019年统考题目：将链表由a1 a2 a3...an-1 an ,改成a1 an a2 an-1 a3 ...  空间复杂度必须为O(1)
/*
思路：一开始想的是先得到总长度，然后一个指针指向a1a2a3  一个指针指向an an-1，依次插入
但这样由于an an-1 an-2是逆向的，每一次都要遍历一遍数组，所以时间复杂度是O(n2)
为了实现O(n)，需要掌握O(n)逆转链表
*/

//逆转链表,但头节点不逆转
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
	//p每走一步，q就走两步
	while (q->next != NULL)
	{
		p = p->next;
		q = q->next;
		if (q->next != NULL)
			q = q->next;
			
	}
	//此时p就是中间结点，将p视为后面一半链表的头节点，就可以实现逆转
	reverse1(p);
	s = L->next; //p作为前半段的第一个点
	q = p->next; //q作为后半段的第一个点
	p->next = NULL; //此时p就是尾结点
	while (q !=NULL)  //奇数时后半部分小于前半部分，所以是q先走到NULL
	{
		r = q->next;
		q->next = s->next;
		s->next = q;
		s = s->next->next;
		q = r;
	}
}
