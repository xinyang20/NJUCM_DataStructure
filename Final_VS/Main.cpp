#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>
//哈希算法应用
// 
//问题描述：
// 蚂蚁王国新建了一批单身公寓共有N套，现有m个蚂蚁战士需要安置（m >= N），
// 国王决定采用哈希的方式进行住房分配。假设哈希函数采用H(key) = key mod N，
// 其中1≤key≤m为战士编号，哈希冲突采用二次探测法解决。假设战士经常出任务，
// 公寓随住随退，即某战士在出任务期间公寓可以自由分配给其他战士居住。
// 
//基本要求：
// 现给定套数N和战士数量m，请随机产生k个战士并分配公寓，
// 随机给x（x < K）个战士分配任务，然后查询某个战士是否住在公寓，
// 如果在住的话给出房间号。
using namespace std;
int N, M, K, X;
int* rooms;
set<int> room_ants, task_ants;


int Hash(int key, int i = 0) {//H(key) = key mod N
	int ans = ((key % N + i * i) % N) + 1;
	return ans;//范围 1 - N
}

void setRooms(int num) {
	for (int i = 0; i < num; i++) {
		int antid = rand() % M + 1;
		while (room_ants.count(antid) != 0) {
			antid = rand() % M + 1;
		}
		room_ants.insert(antid);
		cout << "抽取到蚂蚁战士" << antid << "号";
		cout << "分配房间\n";
		int times = 0; bool succ = false;
		while (!succ) {
			if (rooms[Hash(antid, times)] == -1)
			{
				rooms[Hash(antid, times)] = antid;
				succ = true;
				cout << "分配到房间" << Hash(antid, times) << "号\n";
			}
			times++;
		}
	}
}

void doTask(int num) {
	for (int i = 0; i < num; i++) {
		int antid = rand() % M + 1;
		while (task_ants.count(antid) != 0) {
			antid = rand() % M + 1;
		}
		task_ants.insert(antid);
		cout << "抽取到蚂蚁战士" << antid << "号";
		cout << "执行任务\n";
		int times = 0; bool succ = false;
		while (room_ants.count(antid) != 0 && !succ) {
			if (rooms[Hash(antid, times)] == antid)
			{
				rooms[Hash(antid, times)] = -1;
				succ = true;
				cout << "拥有房间" << Hash(antid, times) << "号\n";
				cout << "房间退还，执行任务\n";
				room_ants.erase(antid);
			}
			else if (rooms[Hash(antid, times)] == -1) {
				succ = true;
				cout << "未拥有房间\n";
				cout << "执行任务\n";
			}
			times++;
			if (times == 5) {
				cout << "二次探测次数已达5次，强制结束该循环进程\n";
				break;
			}
		}
		if (room_ants.count(antid) != 0) {
			cout << "未拥有房间\n";
			cout << "执行任务\n";
		}
	}
}

void SearchAnt(int antid) {
	if (room_ants.count(antid) != 0) {
		int times = 0; bool succ = false;
		while (!succ) {
			if (rooms[Hash(antid, times)] == antid)
			{
				succ = true;
				cout << "拥有房间" << Hash(antid, times) << "号\n";
			}
			times++;
			if (times == 5) {
				cout << "二次探测次数已达5次，强制结束该循环进程\n";
				break;
			}
		}
	}
	else if (task_ants.count(antid) != 0) {
		cout << "执行任务中...\n";
	}
	else {
		cout << "无任务|无房间\n";
	}
}

void check_rooms() {
	cout << "\n-------------当前房间状态-------------\n";
	cout << "房间号\t状态\t住户\n";
	for (int i = 1; i <= N; i++) {
		cout << i << "\t";
		if (rooms[i] == -1)
			cout << "空置\t\\\\\\\\\n";
		else
			cout << "有人\t" << rooms[i] << "\n";
	}
}

void main_task(int n, int m) {
	if (n > m)
	{
		cout << "参数不合法（N > M），程序终止。";
		return;
	}

	N = n;//N间公寓,范围 1 - N
	M = m;//M只蚂蚁,范围 1 - M 
	cout << "蚂蚁数：" << M << "，公寓数：" << N << "\n";

	//构造公寓
	rooms = new int[N + 2];
	rooms[0] = -2; rooms[N + 1] = -2;
	for (int i = 1; i <= N; i++)
		rooms[i] = -1;

	//随机选择K只蚂蚁住进公寓
	cout << "\n------------抽取蚂蚁住公寓------------\n";
	int k_min = N / 3, k_max = N;
	K = k_min + rand() % (k_max - k_min + 1);
	cout << "抽取" << K << "只蚂蚁住公寓\n";
	setRooms(K);
	check_rooms();

	//随机选择X只蚂蚁出任务
	cout << "\n------------抽取蚂蚁出任务------------\n";
	int x_min = K / 3, x_max = K - 1;
	X = x_min + rand() % (x_max - x_min + 1);
	doTask(X);
	check_rooms();

	//查询蚂蚁状态
	cout << "\n-------------当前蚂蚁状态-------------\n";
	cout << "编号\t状态\t房间\n";
	for (int i = 1; i <= M; i++) {
		cout << i << "\t";
		SearchAnt(i);
	}
}

int main() {
	srand(time(nullptr));//设置随机种子
	int m_min = 10, m_max = 100;
	int m = m_min + rand() % (m_max - m_min + 1);
	int n_min = 5, n_max = m;
	int n = n_min + rand() % (n_max - n_min + 1);

	main_task(n, m);

	delete[]rooms;
	return 0;
}