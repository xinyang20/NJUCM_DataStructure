#include <iostream>
#include <string.h>
using namespace std;
#include "LinkPriorityQueue.h"

/*
��дһ������ģ�ⲡ�ˣ�������Ϣ�о���ź����������о����ÿ���1��ʼ�ۼƣ���ҽԺ�������Ŷӿ�ҽ�������Ρ��ڲ����ŶӵĹ����У���Ҫ���������¡�
1�������˹Һţ��������ſں��
2�����ֵ�ĳ���ţ��úŶ�Ӧ�Ĳ��˽������Ҿ��
Ҫ�������ò˵���ʽ����ѡ�����˵�����£�
1���Һź�������´��ﲡ����Ϣ���¹Һŵĳ��������
2���кž���������������Ĳ��ˣ�����������ǰ��Ĳ��ˣ���Ϣ���ò��˽������Ҿ�����´��ﲡ����Ϣ,�Ѿ���Ĳ��˲��ٳ��֡�
3����ѯ�������ǰ����Ҫ�ȵ�������
4�� �˳������˳����С�
*/



class sicker {
public:
	sicker();
	sicker(string num, string name);
	sicker(const sicker& other);
	string GetNumber() { return number; }
	string GetName() { return name; }
private:
	string number;//�����
	string name;//����
};
sicker::sicker()
{
	number = "None";
	name = "None";
}
sicker::sicker(string num, string name)
{
	this->number = num;
	this->name = name;
}
sicker::sicker(const sicker& other)
{
	this->name = other.name;
	this->number = other.number;
}
const string priority_char[4] = { "","Σ","��","��" };
int num[4] = { 0,1,1,1 };
LinkPriorityQueue<sicker> SL;

void Register(string name, int priority) {
	string number = priority_char[priority];
	number += (char)(num[priority] + (int)('0'));
	num[priority]++;
	sicker s(number, name);
	SL.Push(s, priority);
	cout << "�Һųɹ������ľ����Ϊ��" << number << endl;
}

void call() {
	sicker s(SL.Get());
	cout << "��" << s.GetNumber() << "�ţ�" << s.GetName() << "���" << endl;
	SL.Pop();
}

int wait_number(string x) {
	int priority;
	if (x.substr(0, 2) == "Σ")priority = 1;
	else if (x.substr(0, 2) == "��")priority = 2;
	else if (x.substr(0, 2) == "��")priority = 3;
	else throw"����Ų��Ϸ�";
	int np = 1, count = 0;
	while (np < priority) {
		count = SL.Priority_Length(np);
		np++;
	}
	int now_num = 0, num = 0;
	for (int i = 2; x[i] != '\0'; i++)
		num = num * 10 + (int)(x[i] - (int)('0'));
	string nx = SL.Priority_Get(priority).GetNumber();
	for (int i = 2; nx[i] != '\0'; i++)
		now_num = now_num * 10 + (int)(nx[i] - (int)('0'));
	count += num - now_num;
	return count;
}

void guahao() {
	system("cls");
	string name;
	int priority;
	cout << "---------- ��  �� ----------" << endl;
	cout << "������������";
	cin >> name;
	cout << "����������̶ȣ�1ΪΣ�أ�2Ϊ������3Ϊ��ͨ����";
	cin >> priority;
	Register(name, priority);
	system("pause");
}

void Call() {
	call();
	system("pause");
}

void search() {
	system("cls");
	cout << "---------- ��  �� ----------" << endl;
	cout << "���������ţ�";
	string num;
	cin >> num;
	cout << "�ȴ�������" << wait_number(num) << endl;
	system("pause");
}

void test() {
	Register("����", 1);
	Register("����", 2);
	Register("����", 2);
	Register("����", 3);
	call();
	call();
	Register("����", 3);
	Register("Ǯ��", 2);
	Register("���", 2);
	cout << "����Σ2ǰ����3ǰ�滹�У�" << wait_number("��3") << "��" << endl;
	Register("��ʮ", 1);
	cout << "����Σ2�󣬼�3ǰ�滹�У�" << wait_number("��3") << "��" << endl;
	Register("�߾�", 2);
	call();
	call();
	Register("��ʮ", 2);
	Register("�ķ�", 3);
	system("pause");
}

void menu(bool& IsRun, bool clear = true) {
	int input;
	if (clear)system("cls");
	cout << "---------- �� �� ----------" << endl;
	cout << "1.���߹Һ�" << endl;
	cout << "2.ҽ���к�" << endl;
	cout << "3.��ѯ�ȴ�����" << endl;
	cout << "4.���в���" << endl;
	cout << "0.�˳�ϵͳ" << endl;
	cin >> input;
	switch (input)
	{
	case 0:
		IsRun = false;
		break;
	case 1:
		guahao();
		break;
	case 2:
		Call();
		break;
	case 3:
		search();
		break;
	case 4:
		test();
		break;
	default:
		system("cls");
		cout << "����Ƿ�,���������룺" << endl;
		menu(IsRun, false);
		break;
	}
}

int main() {
	bool IsRun = true;
	while (IsRun)
		menu(IsRun);
	return 0;
}