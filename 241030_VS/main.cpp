#include <iostream>
#include <string>
using namespace std;

void task();//主程序
int traverse(int** arr, int size);//遍历图，返回连通分量
void travel(int** arr, int* visit, int begin, int size);//自begin点开始，遍历所有连通点
bool Delete(int** arr, int x, int y);//删除边
bool Ques(int** arr, int x, int y);//判断是否连通

int main() {
	task();//启动主程序
}


void task() {//主程序
	//无向图
	//初始化创建部分
	int n, m; //n代表图的尺寸，m代表边数
	cin >> n >> m;
	int** arr = new int* [n + 5];
	for (int i = 0; i <= n + 1; i++) {
		arr[i] = new int[n + 5];
		for (int j = 0; j <= n + 3; j++)
			arr[i][j] = 0;
	}//初始化邻接表
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}//根据输入记录图的关系
	int num = traverse(arr, n);//连通分量
	if (num > 1) cout << "不连通，连通分量为：" << num << endl;
	else if (num == 1)cout << "连通" << endl;

	//操作部分
	int q, x, y;
	char input;
	string ans;
	cin >> q;
	while (q--) {
		cin >> input >> x >> y;
		if (input == 'D') {//删除边
			Delete(arr, x, y);
		}
		else if (input == 'Q') {//判断是否连通
			if (Ques(arr, x, y) == true)ans += 'C';
			else ans += 'D';
		}
	}
	if (ans.size() > 0)cout << ans << endl;
}


int traverse(int** arr, int size) {//遍历图，返回连通分量
	int* visit = new int[size + 3]();//访问标识，初始化为0（未访问），访问后置为1
	int count = 0;
	for (int i = 1; i <= size; i++) {
		visit[i] = 0;
	}
	for (int i = 1; i <= size; i++) {
		if (visit[i] == 0) {
			travel(arr, visit, i, size);//调用单路线遍历
			count++;//连通分量数量增加
		}
	}
	return count;//返回连通分量
}


void travel(int** arr, int* visit, int index, int size) {//自begin点开始，遍历所有连通点
	if (visit[index] != 0)return;//当前起始节点已被访问，不做操作
	for (int i = 1; i <= size; i++)
		if (i != index && arr[index][i] == 1 && visit[i] == 0) {//非自身节点且有连接且未被访问
			visit[index] = 1;
			travel(arr, visit, i, size);//嵌套调用关联的节点
			visit[index] = 0;
		}
	visit[index] = 1;
}

bool Delete(int** arr, int x, int y) {//删除边
	if (arr[x][y] == 0 && arr[y][x] == 0)return true;//操作前不存在边
	else {
		arr[x][y] = 0;
		arr[y][x] = 0;
	}
	return true;
}

bool Ques(int** arr, int x, int y) {//判断是否连通
	if (arr[x][y] == 1)return true;
	return false;
}