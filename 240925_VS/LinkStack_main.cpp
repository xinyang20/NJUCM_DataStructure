#include <iostream>
using namespace std;
#include "LinkStack.h"

int main() {
	LinkStack<int> S;
	if (S.Empty())
		cout << "栈为空" << endl;
	else
		cout << "栈非空" << endl;
	cout << "对10和15执行入栈操作" << endl;
	S.Push(10);
	S.Push(15);
	cout << "栈顶元素为：" << endl;
	cout << S.GetTop() << endl;
	cout << "执行一次出栈操作：" << endl;
	cout<<S.Pop()<<endl;
	cout << "栈顶元素为：" << endl;
	cout << S.GetTop() << endl;
	return 0;
}