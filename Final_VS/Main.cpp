#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>
//��ϣ�㷨Ӧ��
// 
//����������
// ���������½���һ������Ԣ����N�ף�����m������սʿ��Ҫ���ã�m >= N����
// �����������ù�ϣ�ķ�ʽ����ס�����䡣�����ϣ��������H(key) = key mod N��
// ����1��key��mΪսʿ��ţ���ϣ��ͻ���ö���̽�ⷨ���������սʿ����������
// ��Ԣ��ס���ˣ���ĳսʿ�ڳ������ڼ乫Ԣ�������ɷ��������սʿ��ס��
// 
//����Ҫ��
// �ָ�������N��սʿ����m�����������k��սʿ�����乫Ԣ��
// �����x��x < K����սʿ��������Ȼ���ѯĳ��սʿ�Ƿ�ס�ڹ�Ԣ��
// �����ס�Ļ���������š�
using namespace std;
int N, M, K, X;
int* rooms;
set<int> room_ants, task_ants;


int Hash(int key, int i = 0) {//H(key) = key mod N
	int ans = ((key % N + i * i) % N) + 1;
	return ans;//��Χ 1 - N
}

void setRooms(int num) {
	for (int i = 0; i < num; i++) {
		int antid = rand() % M + 1;
		while (room_ants.count(antid) != 0) {
			antid = rand() % M + 1;
		}
		room_ants.insert(antid);
		cout << "��ȡ������սʿ" << antid << "��";
		cout << "���䷿��\n";
		int times = 0; bool succ = false;
		while (!succ) {
			if (rooms[Hash(antid, times)] == -1)
			{
				rooms[Hash(antid, times)] = antid;
				succ = true;
				cout << "���䵽����" << Hash(antid, times) << "��\n";
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
		cout << "��ȡ������սʿ" << antid << "��";
		cout << "ִ������\n";
		int times = 0; bool succ = false;
		while (room_ants.count(antid) != 0 && !succ) {
			if (rooms[Hash(antid, times)] == antid)
			{
				rooms[Hash(antid, times)] = -1;
				succ = true;
				cout << "ӵ�з���" << Hash(antid, times) << "��\n";
				cout << "�����˻���ִ������\n";
				room_ants.erase(antid);
			}
			else if (rooms[Hash(antid, times)] == -1) {
				succ = true;
				cout << "δӵ�з���\n";
				cout << "ִ������\n";
			}
			times++;
			if (times == 5) {
				cout << "����̽������Ѵ�5�Σ�ǿ�ƽ�����ѭ������\n";
				break;
			}
		}
		if (room_ants.count(antid) != 0) {
			cout << "δӵ�з���\n";
			cout << "ִ������\n";
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
				cout << "ӵ�з���" << Hash(antid, times) << "��\n";
			}
			times++;
			if (times == 5) {
				cout << "����̽������Ѵ�5�Σ�ǿ�ƽ�����ѭ������\n";
				break;
			}
		}
	}
	else if (task_ants.count(antid) != 0) {
		cout << "ִ��������...\n";
	}
	else {
		cout << "������|�޷���\n";
	}
}

void check_rooms() {
	cout << "\n-------------��ǰ����״̬-------------\n";
	cout << "�����\t״̬\tס��\n";
	for (int i = 1; i <= N; i++) {
		cout << i << "\t";
		if (rooms[i] == -1)
			cout << "����\t\\\\\\\\\n";
		else
			cout << "����\t" << rooms[i] << "\n";
	}
}

void main_task(int n, int m) {
	if (n > m)
	{
		cout << "�������Ϸ���N > M����������ֹ��";
		return;
	}

	N = n;//N�乫Ԣ,��Χ 1 - N
	M = m;//Mֻ����,��Χ 1 - M 
	cout << "��������" << M << "����Ԣ����" << N << "\n";

	//���칫Ԣ
	rooms = new int[N + 2];
	rooms[0] = -2; rooms[N + 1] = -2;
	for (int i = 1; i <= N; i++)
		rooms[i] = -1;

	//���ѡ��Kֻ����ס����Ԣ
	cout << "\n------------��ȡ����ס��Ԣ------------\n";
	int k_min = N / 3, k_max = N;
	K = k_min + rand() % (k_max - k_min + 1);
	cout << "��ȡ" << K << "ֻ����ס��Ԣ\n";
	setRooms(K);
	check_rooms();

	//���ѡ��Xֻ���ϳ�����
	cout << "\n------------��ȡ���ϳ�����------------\n";
	int x_min = K / 3, x_max = K - 1;
	X = x_min + rand() % (x_max - x_min + 1);
	doTask(X);
	check_rooms();

	//��ѯ����״̬
	cout << "\n-------------��ǰ����״̬-------------\n";
	cout << "���\t״̬\t����\n";
	for (int i = 1; i <= M; i++) {
		cout << i << "\t";
		SearchAnt(i);
	}
}

int main() {
	srand(time(nullptr));//�����������
	int m_min = 10, m_max = 100;
	int m = m_min + rand() % (m_max - m_min + 1);
	int n_min = 5, n_max = m;
	int n = n_min + rand() % (n_max - n_min + 1);

	main_task(n, m);

	delete[]rooms;
	return 0;
}