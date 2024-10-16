#include <iostream>
using namespace std;
#include "BinaryTree.h"

int main() {
	BinaryTree T;
	cout << "---------前序遍历---------" << endl;
	T.PreOrder();
	cout << endl;
	cout << "---------中序遍历---------" << endl;
	T.InOrder();
	cout << endl;
	cout << "---------后序遍历---------" << endl;
	T.PostOrder();
	cout << endl;
	cout << "前序输出只有一个孩子的结点" << endl;
	T.ShowSingleChildNodes();
	cout << endl;
	cout << "---------镜像并前序输出---------" << endl;
	T.Mirror();
	T.PreOrder();
	cout << endl;
	cout << "---------输出高度---------" << endl;
	T.GetHeight();
	cout << endl;
	return 0;
}