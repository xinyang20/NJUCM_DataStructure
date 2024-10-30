#include <iostream>
#include <string>
using namespace std;

void task();//������
int traverse(int** arr, int size);//����ͼ��������ͨ����
void travel(int** arr, int* visit, int begin, int size);//��begin�㿪ʼ������������ͨ��
bool Delete(int** arr, int x, int y);//ɾ����
bool Ques(int** arr, int x, int y);//�ж��Ƿ���ͨ

int main() {
	task();//����������
}


void task() {//������
	//����ͼ
	//��ʼ����������
	int n, m; //n����ͼ�ĳߴ磬m�������
	cin >> n >> m;
	int** arr = new int* [n + 5];
	for (int i = 0; i <= n + 1; i++) {
		arr[i] = new int[n + 5];
		for (int j = 0; j <= n + 3; j++)
			arr[i][j] = 0;
	}//��ʼ���ڽӱ�
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}//���������¼ͼ�Ĺ�ϵ
	int num = traverse(arr, n);//��ͨ����
	if (num > 1) cout << "����ͨ����ͨ����Ϊ��" << num << endl;
	else if (num == 1)cout << "��ͨ" << endl;

	//��������
	int q, x, y;
	char input;
	string ans;
	cin >> q;
	while (q--) {
		cin >> input >> x >> y;
		if (input == 'D') {//ɾ����
			Delete(arr, x, y);
		}
		else if (input == 'Q') {//�ж��Ƿ���ͨ
			if (Ques(arr, x, y) == true)ans += 'C';
			else ans += 'D';
		}
	}
	if (ans.size() > 0)cout << ans << endl;
}


int traverse(int** arr, int size) {//����ͼ��������ͨ����
	int* visit = new int[size + 3]();//���ʱ�ʶ����ʼ��Ϊ0��δ���ʣ������ʺ���Ϊ1
	int count = 0;
	for (int i = 1; i <= size; i++) {
		visit[i] = 0;
	}
	for (int i = 1; i <= size; i++) {
		if (visit[i] == 0) {
			travel(arr, visit, i, size);//���õ�·�߱���
			count++;//��ͨ������������
		}
	}
	return count;//������ͨ����
}


void travel(int** arr, int* visit, int index, int size) {//��begin�㿪ʼ������������ͨ��
	if (visit[index] != 0)return;//��ǰ��ʼ�ڵ��ѱ����ʣ���������
	for (int i = 1; i <= size; i++)
		if (i != index && arr[index][i] == 1 && visit[i] == 0) {//������ڵ�����������δ������
			visit[index] = 1;
			travel(arr, visit, i, size);//Ƕ�׵��ù����Ľڵ�
			visit[index] = 0;
		}
	visit[index] = 1;
}

bool Delete(int** arr, int x, int y) {//ɾ����
	if (arr[x][y] == 0 && arr[y][x] == 0)return true;//����ǰ�����ڱ�
	else {
		arr[x][y] = 0;
		arr[y][x] = 0;
	}
	return true;
}

bool Ques(int** arr, int x, int y) {//�ж��Ƿ���ͨ
	if (arr[x][y] == 1)return true;
	return false;
}