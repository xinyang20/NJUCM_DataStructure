#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// 全局变量声明
int N, M, K, X;
int* rooms = nullptr;
set<int> room_ants, task_ants;

// 函数声明
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

// 清屏函数
void clear() {
    system("cls");
}

// 哈希函数实现，使用二次探测
int Hash(int key, int i) {
    return ((key % N + i * i) % N) + 1; // 返回范围 1 - N
}

// 房间分配函数
void setRooms(int num) {
    for (int i = 0; i < num; i++) {
        // 随机选择未分配房间的蚂蚁
        int antid = rand() % M + 1;
        while (room_ants.count(antid) != 0) {
            antid = rand() % M + 1;
        }
        room_ants.insert(antid);
        cout << "抽取到蚂蚁战士" << antid << "号" << endl;
        cout << "分配房间中..." << endl;

        // 使用二次探测寻找可用房间
        int times = 0;
        bool succ = false;
        while (!succ && times < N) { // 添加最大探测次数限制
            int room = Hash(antid, times);
            if (rooms[room] == -1) {
                rooms[room] = antid;
                succ = true;
                cout << "成功分配到房间" << room << "号" << endl;
            }
            times++;
        }
        if (!succ) {
            cout << "无法找到合适的房间，分配失败" << endl;
        }
    }
}

// 分配任务函数
void doTask(int num) {
    for (int i = 0; i < num; i++) {
        int antid = rand() % M + 1;
        while (task_ants.count(antid) != 0) {
            antid = rand() % M + 1;
        }
        task_ants.insert(antid);
        cout << "抽取到蚂蚁战士" << antid << "号执行任务" << endl;

        // 如果该蚂蚁有房间，需要退房
        if (room_ants.count(antid) != 0) {
            int times = 0;
            bool found = false;
            while (!found && times < N) {
                int room = Hash(antid, times);
                if (rooms[room] == antid) {
                    rooms[room] = -1;
                    found = true;
                    cout << "退还房间" << room << "号" << endl;
                    room_ants.erase(antid);
                }
                times++;
            }
        }
        else {
            cout << "该蚂蚁无房间，直接执行任务" << endl;
        }
    }
}

// 查询蚂蚁状态
void SearchAnt(int antid) {
    if (room_ants.count(antid) != 0) {
        int times = 0;
        bool found = false;
        while (!found && times < N) {
            int room = Hash(antid, times);
            if (rooms[room] == antid) {
                found = true;
                cout << "住在房间" << room << "号" << endl;
            }
            times++;
        }
    }
    else if (task_ants.count(antid) != 0) {
        cout << "执行任务中..." << endl;
    }
    else {
        cout << "无任务|无房间" << endl;
    }
}

// 检查房间状态
void check_rooms() {
    cout << "\n-------------当前房间状态-------------" << endl;
    cout << "房间号\t状态\t住户" << endl;
    for (int i = 1; i <= N; i++) {
        cout << i << "\t";
        if (rooms[i] == -1)
            cout << "空置\t--" << endl;
        else
            cout << "有人\t" << rooms[i] << endl;
    }
}

// 主要任务流程
void main_task(int n, int m) {
    if (n > m) {
        cout << "参数不合法（N > M），程序终止。" << endl;
        return;
    }

    // 初始化参数
    N = n;
    M = m;
    cout << "蚂蚁数：" << M << "，公寓数：" << N << endl;

    // 初始化房间数组
    if (rooms != nullptr) {
        delete[] rooms;
    }
    rooms = new int[N + 2];
    fill(rooms, rooms + N + 2, -1);

    // 随机选择K只蚂蚁住进公寓
    system("pause");
    running();
    cout << "\n------------抽取蚂蚁住公寓------------" << endl;
    K = max(1, min(N, N / 2 + rand() % (N / 2)));
    cout << "抽取" << K << "只蚂蚁住公寓" << endl;
    setRooms(K);
    check_rooms();

    // 随机选择X只蚂蚁出任务
    system("pause");
    running();
    cout << "\n------------抽取蚂蚁出任务------------" << endl;
    X = max(1, min(K - 1, K / 3 + rand() % (K / 3)));
    doTask(X);
    check_rooms();

    // 查询所有蚂蚁状态
    system("pause");
    running();
    cout << "\n-------------当前蚂蚁状态-------------" << endl;
    cout << "编号\t状态" << endl;
    for (int i = 1; i <= M; i++) {
        cout << i << "\t";
        SearchAnt(i);
    }
    system("pause");
}

// 关于界面
void About() {
    cout << setw(25) << "关  于" << endl << endl;
    cout << "编写时间：2024/12/4" << endl << endl;
    cout << setw(25) << "简  介" << endl << endl;
    cout << "哈希算法应用 - 蚂蚁公寓分配系统" << endl;
    cout << "\n问题描述：" << endl;
    cout << "    蚂蚁王国新建了一批单身公寓共有N套，现有m个蚂蚁战士需要安置（m >= N），\n";
    cout << "国王决定采用哈希的方式进行住房分配。采用H(key) = key mod N作为哈希函数，\n";
    cout << "使用二次探测法解决哈希冲突。战士可以出任务，公寓随住随退。" << endl;
    cout << "\n按任意键返回菜单" << endl;
    system("pause");
    clear();
    menu();
}

// 初始化函数
void init() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int m, n;
    cout << "请依次输入 M 和 N (N < M):\n(输入-1则随机产生)" << endl;
    cin >> m;

    if (m > 0) {
        cin >> n;
        while (n >= m) {
            cout << "不符合要求，当前M=" << m << "，请重新输入N (N < M)：";
            cin >> n;
        }
    }
    else if (m == -1) {
        m = 10 + rand() % 91; // 10-100
        n = 5 + rand() % (m - 5); // 5-(m-1)
    }
    else {
        cout << "输入不合法，退出程序" << endl;
        return;
    }

    main_task(n, m);
    running();
    menu();
}

// 加载动画
void running() {
    const char ch[4] = { '\\','|','/','-' };
    for (int i = 0; i < 5; i++) {
        Sleep(20);
        clear();
        cout << setw(25) << ch[i % 4];
    }
    clear();
}

// 菜单界面
void menu() {
    cout << "------------------菜单-----------------" << endl;
    cout << "1. 开始程序" << endl;
    cout << "2. 关于程序" << endl;
    cout << "(按0退出程序)" << endl;
    cout << "请输入操作代码：";
    int op;
    cin >> op;
    switch_menu(op);
}

// 菜单选择处理
void switch_menu(int op) {
    switch (op) {
    case 0:
        running();
        cout << "退出成功" << endl;
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
        cout << "输入错误，请重新输入。" << endl;
        system("pause");
        clear();
        menu();
        break;
    }
}

// 主函数
int main() {
    menu();
    if (rooms != nullptr) {
        delete[] rooms;
    }
    return 0;
}