#include <iostream>
using namespace std;
#include "BinaryTree.h"

int main() {
	BinaryTree T;
	cout << "---------ǰ�����---------" << endl;
	T.PreOrder();
	cout << endl;
	cout << "---------�������---------" << endl;
	T.InOrder();
	cout << endl;
	cout << "---------�������---------" << endl;
	T.PostOrder();
	cout << endl;
	cout << "ǰ�����ֻ��һ�����ӵĽ��" << endl;
	T.ShowSingleChildNodes();
	cout << endl;
	cout << "---------����ǰ�����---------" << endl;
	T.Mirror();
	T.PreOrder();
	cout << endl;
	cout << "---------����߶�---------" << endl;
	T.GetHeight();
	cout << endl;
	return 0;
}