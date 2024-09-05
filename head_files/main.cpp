#include <iostream>
#include "SeqStack.h"
#include "LinkQueue.h"

using namespace std;

int main() {
	SeqStack<int> S;
	if (S.Empty())
		cout << "栈为空" << endl;
	else
		cout << "栈非空" << endl;

	cout << "对15和10执行入栈操作" << endl;
	S.Push(15);
	S.Push(10);
	cout << "栈顶元素为：" << endl;
	cout << S.GetTop() << endl;
	cout << "执行一次出栈操作" << endl;
	S.Pop();
	cout << "栈顶元素为：" << endl;
	cout << S.GetTop() << endl;

	cout << "\n\n\n\n\n\n\n";

	LinkQueue<int> Q;
	if (Q.Empty())
		cout << "队列为空" << endl;
	else
		cout << "队列非空" << endl;

	cout << "对15和10执行入队操作" << endl;
	try {
		Q.EnQueue(15);
		Q.EnQueue(10);
	}
	catch (char* wrong) {
		cout << wrong << endl;
	}
	
	cout << "查看队头元素：" << endl;
	cout << Q.GetQueue() << endl;
	cout << "执行出队操作：" << endl;
	try {
		Q.DeQueue();
	}
	catch (char* wrong) {
		cout << wrong << endl;
	}
	cout << "查看队头元素：" << endl;
	cout << Q.GetQueue() << endl;
	return 0;
}