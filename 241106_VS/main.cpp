#include <iostream>
#include <map>

using namespace std;

#include "SeqList.h"

void Task();//主程序
void Task1(int**& digraph, const int size);
void Task2(int**& digraph, const int size, const map<char, int>& node);
//int min(int arr[], int start, int end, int* way);
void Check(int**& paths, int size, bool& IsAllMin);

int main() {
	Task();//启动主程序
	return 0;
}

void Task() {
	int n;
	cout << "请输入节点数：";
	cin >> n;
	int** digraph = new int* [n + 3];//初始化有向网（邻接矩阵）
	for (int i = 0; i < n + 3; i++) {
		digraph[i] = new int[n + 3];
		for (int j = 0; j < n + 3; j++)
			digraph[i][j] = 1e8 + 5;
	}
	int m,v;
	map<char, int> node;
	for (int i = 1; i <= n; i++) {
		node[(char)('a' + i - 1)] = i;
	}
	char a, b;
	cout << "请输入边数：";
	cin >> m;
	cout << "请按照以下格式逐一填写有向边：\n起点\t终点\t边权\n";
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> v;
		digraph[node[a]][node[b]] = v;
	}
	cout << "------------------------------------\n";
	cout << "任务1：判断该有向网中是否有有向环存在\n";
	Task1(digraph, n);
	cout << "------------------------------------\n";
	cout << "任务2：求顶点A到其余顶点的最短路径\n";
	Task2(digraph, n,node);
}

void Task1(int**& digraph, const int size)
{
	int* in_degree = new int[size + 3];
	//int* visit = new int[size + 3];
	for (int to = 1; to <= size; to++) {//获取原入度
		int ind = 0;
		for (int from = 1; from <= size; from++)
			if (digraph[from][to] != 0)ind++;
		in_degree[to] = ind;
		//visit[to] = 1;//初始化访问标记
	}

	//SeqList<int> out;
	int zero_point = -1, out_length = 0;
	do {
		zero_point = -1;
		for (int i = 1; i <= size; i++) {
			//if (visit[i] == 0)continue;
			if (in_degree[i] == -1)continue;
			if (in_degree[i] == 0) {
				zero_point = i;
				//out.Insert(out_length, zero_point);
				//visit[zero_point] = 0;
				for (int j = 1; j <= size; j++) {
					if (digraph[zero_point][j] != 0 &&
						//visit[j] == 1 && 
						in_degree[j] > 0) {
						in_degree[j]--;
					}
				}
				out_length++;
				in_degree[i] = -1;
			}
		}
	} while (zero_point != -1);
	if (out_length < size)cout << "存在有向环\n";
	else cout << "不存在有向环\n";
}

void Task2(int**& digraph, const int size, const map<char, int>& mp) {
	int** paths = new int* [size + 5];
	int* values = new int[size + 5];
	int length = size + 4;
	int IsMin = 0;
	for (int i = 0; i < size + 5; i++) {//路径初始化
		paths[i] = new int[size + 5];
		paths[i][length] = 1;
		paths[i][1] = 1;
		paths[i][IsMin] = 0;
		values[i] = 1e8 + 5;
	}
	values[1] = 0;
	paths[1][IsMin] = 1;//到达节点1的路径已为最优
	bool IsAllMin;
	Check(paths, size, IsAllMin);
	while (!IsAllMin) {
		for (int from = 1; from <= size; from++) {//更新当前最小路径值
			for (int to = 2; to <= size; to++) {
				if (values[from] + digraph[from][to] < values[to] && digraph[from][to] != 0) {//经过from路径的代价小于当前路径
					values[to] = values[from] + digraph[from][to];//更新代价
					//更新更优路径
					for (int i = 1; i <= paths[from][length]; i++) {
						paths[to][i] = paths[from][i];
					}
					paths[to][length] = paths[from][length] + 1;
					paths[to][paths[to][length]] = to;
					//检测是否为最优路径
					bool ThisIsMin = true;
					for (int i = 1; i <= size; i++) {
						if (paths[i][IsMin] == 1)continue;//跳过已有的最优路径
						if (values[i] < values[to]) {//检测是否为当前最短路径（此时则不是）
							ThisIsMin = false;
							break;
						}
					}
					if (ThisIsMin)paths[to][IsMin] = 1;
				}
			}
		}
		Check(paths, size, IsAllMin);
	}
	map<char, int> node;//反转映射关系
	//cout << "first\tsecond\n";
	for (auto& i : mp) {
		//cout<< i.second<<"\t"<<i.first << endl;
		node[i.second] = i.first;
	}
	cout << "路径\t最小权值\t详细路径\n";
	for (int i = 1; i <= size; i++) {
		cout << char(node[i]) << "\t\t" << values[i] << "\t\t";
		for (int j = 1; j < paths[i][length]; j++)
			cout << char(node[paths[i][j]]) << " ";
		cout << char(node[paths[i][paths[i][length]]]) << "\n";
	}
}

void Check(int**& paths, int size, bool& IsAllMin) {
	for (int i = 1; i <= size; i++) {
		if (paths[i][0] == 0) {
			IsAllMin = false;
			return;
		}
	}
	IsAllMin = true;
}