#include <iostream>
#include <string>
#include <map>
using namespace std;
#include "LinkStack.h"

void solve() {
	LinkStack<char> optr;
	LinkStack<double> opnd;
	string input;
	map<char, int> mp;
	mp['+'] = 1;
	mp['-'] = 1;
	mp['*'] = 2;
	mp['/'] = 2;
	mp['('] = 0;
	int i = 0;
	optr.Push('#');
	cin >> input;

	while (input[i] != '#') {
		if (input[i] >= '0' && input[i] <= '9')
			opnd.Push((double)(input[i] - '0'));
		else if (input[i] == '(') {
			optr.Push('(');
		}
		else if (input[i] == ')') {
			while (optr.GetTop() != '(') {
				char op = optr.Pop();
				double b = opnd.Pop();
				double a = opnd.Pop();
				double c = 0;
				if (op == '+') c = a + b;
				else if (op == '-') c = a - b;
				else if (op == '*') c = a * b;
				else if (op == '/') c = a / b;
				opnd.Push(c);
			}
			optr.Pop();
		}
		else {
			char t = optr.GetTop();
			if (mp[input[i]] <= mp[t]) {
				t = optr.Pop();
				double b = opnd.Pop();
				double a = opnd.Pop();
				double c = 0;
				if (t == '+')c = a + b;
				else if (t == '-')c = a - b;
				else if (t == '*')c = a * b;
				else if (t == '/')c = a / b;
				opnd.Push(c);
			}
			optr.Push(input[i]);
		}
		i++;
	}
	while (optr.GetTop() != '#') {
		char op = optr.Pop();
		double b = opnd.Pop();
		double a = opnd.Pop();
		double c;
		if (op == '+') c = a + b;
		else if (op == '-') c = a - b;
		else if (op == '*') c = a * b;
		else if (op == '/') c = a / b;
		opnd.Push(c);
	}
	cout << opnd.GetTop() << endl;
}

int main() {
	solve();
	return 0;
}