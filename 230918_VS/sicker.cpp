#include <iostream>
using namespace std;
#include "LinkQueue.h"

/*
��дһ������ģ�ⲡ�ˣ�������Ϣ�о���ź����������о����ÿ���1��ʼ�ۼƣ���ҽԺ�������Ŷӿ�ҽ�������Ρ�
�ڲ����ŶӵĹ����У���Ҫ���������¡�
1�������˹Һţ��������ſں��
2�����ֵ�ĳ���ţ��úŶ�Ӧ�Ĳ��˽������Ҿ��
Ҫ�������ò˵���ʽ����ѡ�����˵�����£�
1���Һź�������´��ﲡ����Ϣ���¹Һŵĳ��������
2���кž���������������Ĳ��ˣ�����������ǰ��Ĳ��ˣ���Ϣ���ò��˽������Ҿ�����´��ﲡ����Ϣ��
   �Ѿ���Ĳ��˲��ٳ��֡�
3����ѯ�������ǰ����Ҫ�ȵ�������
4�� �˳������˳����С�
*/



class sicker {
public:
	sicker();
	sicker(int num, char* name);
	sicker(const sicker& other);
	int GetNumber() { return number; }
	char* GetName() { return name; }
private:
	int number;//�����
	char* name;//����
};
sicker::sicker()
{
	number = -1;
	char Name[5] = "none";
	name = Name;
}
sicker::sicker(int num, char* name)
{
	number = num;
	this->name = name;
}
sicker::sicker(const sicker& other)
{
	this->name = other.name;
	this->number = other.number;
}

int num = 1;//��ǰ�Һ���+1
LinkQueue<sicker> SL;

void Register(char* name) {
	sicker* s = new sicker(num, name);
	SL.EnQueue(*s);
	cout << "�Һųɹ������ľ����Ϊ��" << num << endl;
	num++;
}

void call() {
	sicker s(SL.GetQueue());
	cout << "��" << s.GetNumber() << "�ţ�" << s.GetName() << "���" << endl;
	SL.DeQueue();
}

int wait_number(int x) {
	sicker shead(SL.GetQueue());
	int count = x - shead.GetNumber();
	return count;
}

void guahao() {
	system("cls");
	char a[10];
	cout << "---------- ��  �� ----------" << endl;
	cout << "������������";
	cin >> a;
	Register(a);
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
	int num;
	cin >> num;
	cout << "�ȴ�������" << wait_number(num) << endl;
	system("pause");
}

void menu(bool &IsRun) {
	int input;
	system("cls");
	cout << "---------- �� �� ----------" << endl;
	cout << "1.���߹Һ�" << endl;
	cout << "2.ҽ���к�" << endl;
	cout << "3.��ѯ�ȴ�����" << endl;
	cout << "0.�˳�ϵͳ" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		guahao();
		break;
	case 2:
		Call();
		break;
	case 3:
		search();
		break;
	default:
		IsRun = false;
		break;
	}
}

int main() {
	bool IsRun = true;
	while (IsRun) {
		menu(IsRun);
	}
	return 0;
}


