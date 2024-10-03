#include <iostream>
using namespace std;
#include "LinkQueue.h"

int main() {
	LinkQueue<int> Q;
	if (Q.Empty())
		cout << "����Ϊ��" << endl;
	else
		cout << "���зǿ�" << endl;
	cout << "Ԫ��10��15ִ����Ӳ���" << endl;
	try {
		Q.EnQueue(10);
		Q.EnQueue(15);
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
	return  0;
}