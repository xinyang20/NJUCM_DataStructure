#include <iostream>
using namespace std;

#include "AdressBook.h"

int MaxSize = 100;
//�����һ���򵥵�ͨѶ¼��ʵ�����¹��ܣ�
//1��¼�룺��ʾ�û����룬ÿ��ͨѶ¼�����������ֻ��š�
//2����ѯ�����Ը�����������ĳ��ͨѶ¼����������ʾ��
//3�����򣺿��Ը���������ͨѶ¼��������
//4���������ʾ����ͨѶ¼��
//
//˼���������ͬ���ģ���ô����
void operate(AdressBook book, bool& exit);
void menu(AdressBook book,bool &exit) {
	cout << "--------------------------\n";
	cout << "1.¼���µ���Ϣ\n";
	cout << "2.��ѯ����\n";
	cout << "3.������������\n";
	cout << "4.��ʾ������ϵ��\n";
	cout << "��������Ҫ��ɵĲ���(��'0'�˳�ϵͳ):";
	operate(book,exit);
}
void insert(AdressBook book) {
	string name, tel;
	cout << "--------------------------\n";
	cout << "������";
	cin >> name;
	cout << "���룺";
	cin >> tel;
	book.Insert(name, tel);
}

void search(AdressBook book) {
	string name;
	cout << "--------------------------\n";
	cout << "������ҵ�������";
	cin >> name;
	cout << "��ȡ������Ϣ��������" << name << '\n';
	book.SeqSearch(name);
}

void sort(AdressBook book) {
	book.Sort(-1);
	book.Show();
}
void show(AdressBook book) {
	book.Show();
}

void operate(AdressBook book,bool &exit) {
	int input;
	cin >> input;
	switch (input)
	{
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
		cout << "������Ч�����������룺";
		menu(book,exit);
		break;
	}
}

int main() {
	AdressBook book(MaxSize);
	bool exit = false;
	while (!exit)
		menu(book, exit);
	return 0;
}