#include <iostream>
#include "ai_head.h"
using namespace std;

int MaxSize = 100;

void operate(AdressBook& book, bool& exit);
void menu(AdressBook& book, bool& exit);

void insert(AdressBook& book) {
    string name, tel;
    cout << "姓名：";
    cin >> name;
    cout << "号码：";
    cin >> tel;
    book.Insert(name, tel);
}

void search(AdressBook& book) {
    string name;
    cout << "输入查找的姓名：";
    cin >> name;
    book.SeqSearch(name);
}

void sort(AdressBook& book) {
    book.Sort(-1);
    book.Show();
}

void show(AdressBook& book) {
    book.Show();
}

void operate(AdressBook& book, bool& exit) {
    int input;
    cin >> input;
    switch (input) {
    case 0:
        exit = true;
        break;
    case 1:
        insert(book);
        break;
    case 2:
        search(book);
        break;
    case 3:
        sort(book);
        break;
    case 4:
        show(book);
        break;
    default:
        cout << "输入无效，请重新输入：";
        menu(book, exit);
        break;
    }
}

void menu(AdressBook& book, bool& exit) {
    cout << "--------------------------\n";
    cout << "1. 录入新的信息\n";
    cout << "2. 查询号码\n";
    cout << "3. 根据姓名排序\n";
    cout << "4. 显示所有联系人\n";
    cout << "请输入需要完成的操作(按'0'退出系统): ";
    operate(book, exit);
}

int main() {
    AdressBook book(MaxSize);
    bool exit = false;
    while (!exit)
        menu(book, exit);
    return 0;
}
