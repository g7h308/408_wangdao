#pragma once
#include "assistance.h"
#include "BiTree.h"


/*
第19题：带权路径长度：叶子结点的深度乘以权值   有两种思路：先序遍历和层次遍历
*/
//不需要新造结构体，只需要把BiTree中的data当作weight即可

void WPL1(BiTree root, int depth, int& sum) {
	if (root->left == NULL && root->right == NULL)
		sum += root->data * depth;
	if (root->left != NULL)
		WPL1(root->left, depth + 1, sum);
	if (root->right != NULL)
		WPL1(root->right, depth + 1, sum);
}

int WPL2(BiTree root) {
	//用STL的queue很好写
	/*
	queue<BiTree> q;
	q.push(root);
	int depth = 0;
	int sum = 0;
	while (!q.empty())
	{
		depth++;
		int size = q.size();
		for (int i = 0; i < size(); i++) {
			BiTNode* node = q.front();
			q.pop();
			if (node->left != NULL) q.push(node->left);
			if (node->right != NULL) q.push(node->right);
			if (node->right == NULL && node->left == NULL)
				sum += depth * node->data;
		}
	}
	return sum;
	*/


	//但是考试不能用STL库，要自己写一个队列
	//自己写的队列无法使用size()函数，所以需要构造lastNode和newLastNode两个标记来实现类似的功能

	BiTree q[100];  //新建队列，容量为100
	int front, rear;  //队头、队尾指针
	front = rear = 0;
	int sum = 0, depth = 0;  //注意：路径长度为深度减一，所以这里depth从0开始而非从开始
	BiTree lastNode;  //记录当前一层的最后一个结点
	BiTree newlastNode = NULL; //记录当前一层的下一层的最后一个结点
	lastNode = root;//初始当前一层的最后一个结点自然是root
	q[rear++] = root; //入队
	while (front != rear) {  //队列为空时循环结束
		BiTree node = q[front++];  //取出队列中第一个元素
		if (node->left != NULL) {
			q[rear++] = node->left;
			newlastNode = node->left;
		}
		if (node->right != NULL) {
			q[rear++] = node->right;
			newlastNode = node->right;
		}
		if (node->right == NULL && node->left == NULL) 
			sum += depth * node->data;
		if (node == lastNode) {  //说明已经遍历到了这一层的对后一个结点，depth该+1了
			depth++;
			lastNode = newlastNode;
		}
	}
	return sum;
}


int fun19_1(BiTree root) {
	int sum = 0;
	//WPL1(root, 0, sum);
	sum = WPL2(root);
	return sum;
}


/*
20题：采用中序遍历即可
*/
//不需要新造结构体，只需要把BiTree中的data当作char即可
//给了一串char数组，比如说char c[10]  ,此时并不知道c里面到底有几个元素，直接输出cout << c即可打印里面的非空元素，c语言中则是printf("%s",c);

void fun20(BiTree root,int depth) { //注意到此题中最外层不需要加括号，所以depth为1时不加括号，其余层数加括号  
	if (root == NULL)
		return;
	else if(root->left == NULL && root->right == NULL)  //叶子结点输出数据
		cout << root->data;
	else {  //非叶子结点，非根节点
		if (depth > 1)
			cout << "(";
		fun20(root->left, depth + 1);
		cout << root->data;
		fun20(root->right, depth + 1);
		if (depth > 1)
			cout << ")";
	}
}


/*
21题：

思路1：二叉排序树需要满足的三个条件：1. 左子树是二叉搜索树 2. 右子树是二叉搜索树 3. 中间结点大于前驱节点
思路1：二叉排序树中序遍历得到的序列保持升序，所以可以先中序遍历一遍得到数组，判断这个数组是否升序即可
*/


#define maxsize 50
typedef struct {
	int SqBiTNode[maxsize];
	int ElemNum;    //实际占用数组元素的个数
}SqBiTree;

//思路一
int pre = 0;
bool fun21_1(SqBiTree bt, int i) {
	if (bt.SqBiTNode[i] == -1) //空结点也是二叉搜索树
		return true;
	if (fun21_1(bt, 2 * i + 1) == false)
		return false;
	if (pre >= bt.SqBiTNode[i])
		return false;
	pre = bt.SqBiTNode[i];
	if (fun21_1(bt, 2 * i + 2) == false)
		return false;
	return true;
}

//思路二很简单，就不写了
