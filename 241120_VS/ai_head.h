#pragma once
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

struct User {
    ll ID;
    string Name;
    string Telephone;
    User& operator=(const User& other) {
        if (this != &other) {
            ID = other.ID;
            Name = other.Name;
            Telephone = other.Telephone;
        }
        return *this;
    }
};

class AdressBook {
public:
    AdressBook(int MaxSize);
    bool Insert(string name, string tel);
    void SeqSearch(string name, ll id = -1);
    void Show(bool ShowID = false);
    void Sort(int way);
private:
    User* user;
    int Num;
    int MaxSize;
    void QuickSort(int left, int right);
};

// 构造函数
AdressBook::AdressBook(int size) {
    user = new User[size + 5];
    MaxSize = size;
    Num = 0;
}

// 插入新用户
bool AdressBook::Insert(string name, string tel) {
    if (Num >= MaxSize) {
        cout << "通讯录已满，无法添加新联系人！\n";
        return false;
    }
    Num++;
    user[Num].ID = Num;
    user[Num].Name = name;
    user[Num].Telephone = tel;
    cout << "插入成功, 当前数量：" << Num << "/" << MaxSize << "\n";
    return true;
}

// 顺序搜索
void AdressBook::SeqSearch(string name, ll id) {
    bool found = false;
    cout << "姓名\t\t号码\n";
    for (int i = 1; i <= Num; i++) {
        if (user[i].Name == name) {
            found = true;
            cout << user[i].Name << "\t\t" << user[i].Telephone << endl;
        }
    }
    if (!found) {
        cout << "未找到与姓名匹配的记录。\n";
    }
}

// 显示所有用户
void AdressBook::Show(bool ShowID) {
    if (Num == 0) {
        cout << "通讯录为空。\n";
        return;
    }
    if (ShowID) cout << "  ID\t\t";
    cout << "姓名\t\t号码\n";
    for (int index = 1; index <= Num; index++) {
        if (ShowID) cout << user[index].ID << "\t\t";
        cout << user[index].Name << "\t\t" << user[index].Telephone << endl;
    }
}

// 排序功能
void AdressBook::Sort(int way) {
    switch (way) {
    case 1:
        QuickSort(1, Num);
        break;
    default:
        std::sort(user + 1, user + Num + 1, [](User a, User b) { return a.Name < b.Name; });
    }
    cout << "通讯录已排序。\n";
}

// 快速排序
void AdressBook::QuickSort(int left, int right) {
    if (left >= right) return;
    User pivot = user[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && user[j].Name >= pivot.Name) j--;
        if (i < j) user[i++] = user[j];
        while (i < j && user[i].Name <= pivot.Name) i++;
        if (i < j) user[j--] = user[i];
    }
    user[i] = pivot;
    QuickSort(left, i - 1);
    QuickSort(i + 1, right);
}
