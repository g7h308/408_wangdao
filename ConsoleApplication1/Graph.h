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
�Ͻ�˹�����㷨
����˼·��
����ѭ����
	����ѭ����ÿ���ڵ㶼Ҫ����һ��
	�ڲ�������Сѭ����
		��һ��Сѭ�����ҵ�����δ�����ʹ��Ľڵ��о���start������Ǹ��ڵ㣬��������Ϊmiddle
		�ڶ���Сѭ������middle���ڽ����Ϊ�м��㣬��ȥ�����������нڵ�
*/
vector<int> Dijstra(MGraph& graph, int start) {
	int n = graph.weight.size();
	vector<int> visted(n, 0);  //��Ӧ�ڵ��Ƿ񱻷��ʹ�
	vector<int> distance(n); //��ʾ��ʼstart�ڵ�����ľ���
	for (int i = 0; i < n; i++)
		distance[i] = graph.weight[start][i];  //��ʼdistance�����ڽӾ��������
	visted[start] = 1;  //start�Ѿ������ʹ�

	for (int i = 0; i < n; i++) {  //����ѭ��
		int min_dist = INT_MAX;  //��̾���
		int middle = 0; //�м�ڵ�

		for (int j = 0; j < n; j++) {  //�ڲ�ĵ�һ��Сѭ����Ѱ�Ҿ�������Ľ����Ϊmiddle
			if (visted[j] == 0 && min_dist > distance[j]) {
				min_dist = distance[j];
				middle = j;
			}
		}

		for (int j = 0; j < n; j++) {  //�ڲ�ڶ���Сѭ��
			/*
			�����ǰ�������Ľڵ�δ�����ʹ�������ʼ�ڵ�ֱ�ӵ��ýڵ�ľ���distance[j]����distace[middle]+weight[middle][j]����˵��
			�ҵ��˸��̵�·���������滻
			*/
			if (visted[j] == 0 && distance[j] > (distance[middle] + graph.weight[middle][j]))
				distance[j] = distance[middle] + graph.weight[middle][j];
		}
		visted[middle] = 1;  //�ýڵ�����й����Ѿ���ɣ���Ϊ���ʽڵ�
	}
	return distance;
}

/*
���������㷨
����˼·�����������㷨�����������������֮������·����������Ҫһ����ά��������¼
����ѭ����
	��һ��ѭ����ÿ���ڵ㶼Ҫ��Ϊһ��middle
	�ڶ�����ѭ��������һ�����ÿ��d[j][k]�ľ��붼Ҫ����middle����ԭ����ֱ�Ӿ���d[j][k]���бȽ�
	��d[j][i] + d[i][k] < d[j][k]
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


/*  ����ʾ��
vector<string> data = { "����","���","֣��","����","��ɳ","����" };
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
