#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// ȫ�ֱ�������
int N, M, K, X;
int* rooms = nullptr;
set<int> room_ants, task_ants;

// ��������
void menu();
int Hash(int key, int i = 0);
void setRooms(int num);
void doTask(int num);
void SearchAnt(int antid);
void check_rooms();
void main_task(int n, int m);
void init();
void About();
void running();
void switch_menu(int op);
void clear();

// ��������
void clear() {
    system("cls");
}

// ��ϣ����ʵ�֣�ʹ�ö���̽��
int Hash(int key, int i) {
    return ((key % N + i * i) % N) + 1; // ���ط�Χ 1 - N
}

// ������亯��
void setRooms(int num) {
    for (int i = 0; i < num; i++) {
        // ���ѡ��δ���䷿�������
        int antid = rand() % M + 1;
        while (room_ants.count(antid) != 0) {
            antid = rand() % M + 1;
        }
        room_ants.insert(antid);
        cout << "��ȡ������սʿ" << antid << "��" << endl;
        cout << "���䷿����..." << endl;

        // ʹ�ö���̽��Ѱ�ҿ��÷���
        int times = 0;
        bool succ = false;
        while (!succ && times < N) { // ������̽���������
            int room = Hash(antid, times);
            if (rooms[room] == -1) {
                rooms[room] = antid;
                succ = true;
                cout << "�ɹ����䵽����" << room << "��" << endl;
            }
            times++;
        }
        if (!succ) {
            cout << "�޷��ҵ����ʵķ��䣬����ʧ��" << endl;
        }
    }
}

// ����������
void doTask(int num) {
    for (int i = 0; i < num; i++) {
        int antid = rand() % M + 1;
        while (task_ants.count(antid) != 0) {
            antid = rand() % M + 1;
        }
        task_ants.insert(antid);
        cout << "��ȡ������սʿ" << antid << "��ִ������" << endl;

        // ����������з��䣬��Ҫ�˷�
        if (room_ants.count(antid) != 0) {
            int times = 0;
            bool found = false;
            while (!found && times < N) {
                int room = Hash(antid, times);
                if (rooms[room] == antid) {
                    rooms[room] = -1;
                    found = true;
                    cout << "�˻�����" << room << "��" << endl;
                    room_ants.erase(antid);
                }
                times++;
            }
        }
        else {
            cout << "�������޷��䣬ֱ��ִ������" << endl;
        }
    }
}

// ��ѯ����״̬
void SearchAnt(int antid) {
    if (room_ants.count(antid) != 0) {
        int times = 0;
        bool found = false;
        while (!found && times < N) {
            int room = Hash(antid, times);
            if (rooms[room] == antid) {
                found = true;
                cout << "ס�ڷ���" << room << "��" << endl;
            }
            times++;
        }
    }
    else if (task_ants.count(antid) != 0) {
        cout << "ִ��������..." << endl;
    }
    else {
        cout << "������|�޷���" << endl;
    }
}

// ��鷿��״̬
void check_rooms() {
    cout << "\n-------------��ǰ����״̬-------------" << endl;
    cout << "�����\t״̬\tס��" << endl;
    for (int i = 1; i <= N; i++) {
        cout << i << "\t";
        if (rooms[i] == -1)
            cout << "����\t--" << endl;
        else
            cout << "����\t" << rooms[i] << endl;
    }
}

// ��Ҫ��������
void main_task(int n, int m) {
    if (n > m) {
        cout << "�������Ϸ���N > M����������ֹ��" << endl;
        return;
    }

    // ��ʼ������
    N = n;
    M = m;
    cout << "��������" << M << "����Ԣ����" << N << endl;

    // ��ʼ����������
    if (rooms != nullptr) {
        delete[] rooms;
    }
    rooms = new int[N + 2];
    fill(rooms, rooms + N + 2, -1);

    // ���ѡ��Kֻ����ס����Ԣ
    system("pause");
    running();
    cout << "\n------------��ȡ����ס��Ԣ------------" << endl;
    K = max(1, min(N, N / 2 + rand() % (N / 2)));
    cout << "��ȡ" << K << "ֻ����ס��Ԣ" << endl;
    setRooms(K);
    check_rooms();

    // ���ѡ��Xֻ���ϳ�����
    system("pause");
    running();
    cout << "\n------------��ȡ���ϳ�����------------" << endl;
    X = max(1, min(K - 1, K / 3 + rand() % (K / 3)));
    doTask(X);
    check_rooms();

    // ��ѯ��������״̬
    system("pause");
    running();
    cout << "\n-------------��ǰ����״̬-------------" << endl;
    cout << "���\t״̬" << endl;
    for (int i = 1; i <= M; i++) {
        cout << i << "\t";
        SearchAnt(i);
    }
    system("pause");
}

// ���ڽ���
void About() {
    cout << setw(25) << "��  ��" << endl << endl;
    cout << "��дʱ�䣺2024/12/4" << endl << endl;
    cout << setw(25) << "��  ��" << endl << endl;
    cout << "��ϣ�㷨Ӧ�� - ���Ϲ�Ԣ����ϵͳ" << endl;
    cout << "\n����������" << endl;
    cout << "    ���������½���һ������Ԣ����N�ף�����m������սʿ��Ҫ���ã�m >= N����\n";
    cout << "�����������ù�ϣ�ķ�ʽ����ס�����䡣����H(key) = key mod N��Ϊ��ϣ������\n";
    cout << "ʹ�ö���̽�ⷨ�����ϣ��ͻ��սʿ���Գ����񣬹�Ԣ��ס���ˡ�" << endl;
    cout << "\n����������ز˵�" << endl;
    system("pause");
    clear();
    menu();
}

// ��ʼ������
void init() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int m, n;
    cout << "���������� M �� N (N < M):\n(����-1���������)" << endl;
    cin >> m;

    if (m > 0) {
        cin >> n;
        while (n >= m) {
            cout << "������Ҫ�󣬵�ǰM=" << m << "������������N (N < M)��";
            cin >> n;
        }
    }
    else if (m == -1) {
        m = 10 + rand() % 91; // 10-100
        n = 5 + rand() % (m - 5); // 5-(m-1)
    }
    else {
        cout << "���벻�Ϸ����˳�����" << endl;
        return;
    }

    main_task(n, m);
    running();
    menu();
}

// ���ض���
void running() {
    const char ch[4] = { '\\','|','/','-' };
    for (int i = 0; i < 5; i++) {
        Sleep(20);
        clear();
        cout << setw(25) << ch[i % 4];
    }
    clear();
}

// �˵�����
void menu() {
    cout << "------------------�˵�-----------------" << endl;
    cout << "1. ��ʼ����" << endl;
    cout << "2. ���ڳ���" << endl;
    cout << "(��0�˳�����)" << endl;
    cout << "������������룺";
    int op;
    cin >> op;
    switch_menu(op);
}

// �˵�ѡ����
void switch_menu(int op) {
    switch (op) {
    case 0:
        running();
        cout << "�˳��ɹ�" << endl;
        return;
    case 1:
        running();
        init();
        break;
    case 2:
        running();
        About();
        break;
    default:
        running();
        cout << "����������������롣" << endl;
        system("pause");
        clear();
        menu();
        break;
    }
}

// ������
int main() {
    menu();
    if (rooms != nullptr) {
        delete[] rooms;
    }
    return 0;
}