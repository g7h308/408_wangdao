#include "SqList.h"
#include "LinkList.h"
#include "DoubleLinkList.h"
//#include "chapter2.h"
#include "KMP.h"
#include "BiTree.h"
#include "chapter5.h"
#include <vector>
#include <stack>



int main()
{
	int a[7] = { 4,2,6,7,5,3,1 };
	BiTree root = NULL;
	for (int i = 0; i < 7; i++) {
		BiTree_InsertNode(root, a[i]);
	}
	cout << fun19_1(root);

}

