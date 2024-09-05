#include <iostream>
#include "SeqStack.h"
#include "LinkQueue.h"

using namespace std;

int main() {
	SeqStack<int> S;
	if (S.Empty())
		cout << "ջΪ��" << endl;
	else
		cout << "ջ�ǿ�" << endl;

	cout << "��15��10ִ����ջ����" << endl;
	S.Push(15);
	S.Push(10);
	cout << "ջ��Ԫ��Ϊ��" << endl;
	cout << S.GetTop() << endl;
	cout << "ִ��һ�γ�ջ����" << endl;
	S.Pop();
	cout << "ջ��Ԫ��Ϊ��" << endl;
	cout << S.GetTop() << endl;

	cout << "\n\n\n\n\n\n\n";

	LinkQueue<int> Q;
	if (Q.Empty())
		cout << "����Ϊ��" << endl;
	else
		cout << "���зǿ�" << endl;

	cout << "��15��10ִ����Ӳ���" << endl;
	try {
		Q.EnQueue(15);
		Q.EnQueue(10);
	}
	catch (char* wrong) {
		cout << wrong << endl;
	}
	
	cout << "�鿴��ͷԪ�أ�" << endl;
	cout << Q.GetQueue() << endl;
	cout << "ִ�г��Ӳ�����" << endl;
	try {
		Q.DeQueue();
	}
	catch (char* wrong) {
		cout << wrong << endl;
	}
	cout << "�鿴��ͷԪ�أ�" << endl;
	cout << Q.GetQueue() << endl;
	return 0;
}