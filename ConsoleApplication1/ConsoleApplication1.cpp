#include "SqList.h"
#include "LinkList.h"
#include "DoubleLinkList.h"
//#include "chapter2.h"
#include "KMP.h"
#include "BiTree.h"
#include "chapter5.h"
#include "Graph.h"

#include <vector>
#include <stack>



int main()
{
	vector<string> data = { "北京","天津","郑州","济南","长沙","海南" };
	int x = 10000;
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
	//show(graph);
	vector<int> v = Dijstra(graph, 0);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	Floyd(graph);

}

