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

// ���캯��
AdressBook::AdressBook(int size) {
    user = new User[size + 5];
    MaxSize = size;
    Num = 0;
}

// �������û�
bool AdressBook::Insert(string name, string tel) {
    if (Num >= MaxSize) {
        cout << "ͨѶ¼�������޷��������ϵ�ˣ�\n";
        return false;
    }
    Num++;
    user[Num].ID = Num;
    user[Num].Name = name;
    user[Num].Telephone = tel;
    cout << "����ɹ�, ��ǰ������" << Num << "/" << MaxSize << "\n";
    return true;
}

// ˳������
void AdressBook::SeqSearch(string name, ll id) {
    bool found = false;
    cout << "����\t\t����\n";
    for (int i = 1; i <= Num; i++) {
        if (user[i].Name == name) {
            found = true;
            cout << user[i].Name << "\t\t" << user[i].Telephone << endl;
        }
    }
    if (!found) {
        cout << "δ�ҵ�������ƥ��ļ�¼��\n";
    }
}

// ��ʾ�����û�
void AdressBook::Show(bool ShowID) {
    if (Num == 0) {
        cout << "ͨѶ¼Ϊ�ա�\n";
        return;
    }
    if (ShowID) cout << "  ID\t\t";
    cout << "����\t\t����\n";
    for (int index = 1; index <= Num; index++) {
        if (ShowID) cout << user[index].ID << "\t\t";
        cout << user[index].Name << "\t\t" << user[index].Telephone << endl;
    }
}

// ������
void AdressBook::Sort(int way) {
    switch (way) {
    case 1:
        QuickSort(1, Num);
        break;
    default:
        std::sort(user + 1, user + Num + 1, [](User a, User b) { return a.Name < b.Name; });
    }
    cout << "ͨѶ¼������\n";
}

// ��������
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
