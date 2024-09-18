#include <iostream>
using namespace std;
#include "SeqStack.h"

void Decimal_Convertion(int number, int decimal) {
	char chars[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	SeqStack<char> S;
	while (number != 0) {
		int c = number % decimal;
		S.Push(chars[c]);
		number = number / decimal;
	}
	while (!S.Empty())
		cout << S.Pop();
	cout << endl;
}

int main() {
	int number, decimal;
	cin >> number >> decimal;
	Decimal_Convertion(number, decimal);
	return 0;
}