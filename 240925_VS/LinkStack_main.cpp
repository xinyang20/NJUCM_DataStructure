#include <iostream>
using namespace std;
#include "LinkStack.h"

int main() {
	LinkStack<int> S;
	if (S.Empty())
		cout << "ջΪ��" << endl;
	else
		cout << "ջ�ǿ�" << endl;
	cout << "��10��15ִ����ջ����" << endl;
	S.Push(10);
	S.Push(15);
	cout << "ջ��Ԫ��Ϊ��" << endl;
	cout << S.GetTop() << endl;
	cout << "ִ��һ�γ�ջ������" << endl;
	cout<<S.Pop()<<endl;
	cout << "ջ��Ԫ��Ϊ��" << endl;
	cout << S.GetTop() << endl;
	return 0;
}