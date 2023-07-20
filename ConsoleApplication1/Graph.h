#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
class MGraph {

public:
	int verxs;
	vector<string> data;
	vector<vector<int>> weight;

	MGraph() {}

	MGraph(int verxs)
	{
		this->verxs = verxs;
		data.resize(verxs);
		weight.resize(verxs);
		for (int i = 0; i < verxs; i++)
		{
			weight[i].resize(verxs);
		}
	}
	~MGraph() {}

};

void createGraph(MGraph& graph, int verxs, vector<string> data, vector<vector<int>> weight)
{
	for (int i = 0; i < verxs; i++)
	{
		graph.data[i] = data[i];
		for (int j = 0; j < verxs; j++)
		{
			graph.weight[i][j] = weight[i][j];
		}
	}

}

void show(MGraph& graph)
{
	for (int i = 0; i < graph.verxs; i++)
	{
		for (int j = 0; j < graph.verxs; j++)
		{
			cout << graph.weight[i][j] << "\t";
		}
		cout << endl;
	}
}

/*
迪杰斯特拉算法
核心思路：
两层循环：
	外层大循环：每个节点都要遍历一遍
	内层有两个小循环：
		第一个小循环：找到所有未被访问过的节点中距离start最近的那个节点，将其设置为middle
		第二个小循环：以middle所在结点作为中间结点，再去遍历其他所有节点
*/
vector<int> Dijstra(MGraph& graph, int start) {
	int n = graph.weight.size();
	vector<int> visted(n, 0);  //对应节点是否被访问过
	vector<int> distance(n); //表示起始start节点最近的距离
	for (int i = 0; i < n; i++)
		distance[i] = graph.weight[start][i];  //初始distance就是邻接矩阵的数据
	visted[start] = 1;  //start已经被访问过

	for (int i = 0; i < n; i++) {  //外层大循环
		int min_dist = INT_MAX;  //最短距离
		int middle = 0; //中间节点

		for (int j = 0; j < n; j++) {  //内层的第一个小循环，寻找距离最近的结点作为middle
			if (visted[j] == 0 && min_dist > distance[j]) {
				min_dist = distance[j];
				middle = j;
			}
		}

		for (int j = 0; j < n; j++) {  //内层第二个小循环
			/*
			如果当前遍历到的节点未被访问过，且起始节点直接到该节点的距离distance[j]大于distace[middle]+weight[middle][j]，则说明
			找到了更短的路径，进行替换
			*/
			if (visted[j] == 0 && distance[j] > (distance[middle] + graph.weight[middle][j]))
				distance[j] = distance[middle] + graph.weight[middle][j];
		}
		visted[middle] = 1;  //该节点的所有工作已经完成，变为访问节点
	}
	return distance;
}

/*
弗洛伊德算法
核心思路：弗洛伊德算法是求解任意两个顶点之间的最短路径，所以需要一个二维数组来记录
三层循环：
	第一层循环：每个节点都要作为一次middle
	第二三层循环，遍历一遍矩阵，每次d[j][k]的距离都要经过middle，与原本的直接距离d[j][k]进行比较
	即d[j][i] + d[i][k] < d[j][k]
*/
void Floyd(MGraph& graph) {
	int n = graph.verxs;
	vector<vector<int>> d(n, vector<int>(n));
	d = graph.weight;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (d[j][i] + d[i][k] < d[j][k])
					d[j][k] = d[j][i] + d[i][k];
			}
		}
	}
	
}


/*  备用示例
vector<string> data = { "北京","天津","郑州","济南","长沙","海南" };
int x = INT_MAX;
vector<vector<int>> weight = {
	{x   ,  100,  1200,  x,    x,    x},
	{100 ,  x,    900,   300,  x,    x},
	{1200,  900,  x,     400,  500,  x},
	{x,     300,  400,   x,    1300, 1400},
	{x,     x,    500,   1300, x,    1500},
	{x,     x,    x,     1400, 1500, x}
};
MGraph graph(6);
createGraph(graph, 6, data, weight);

*/
