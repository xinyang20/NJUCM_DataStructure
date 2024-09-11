#include <iostream>
#include "LinkList.h"

using namespace std;

int main() {
	int a[4] = { 4,1,2,3 }, b[4] = { 5,1,3,6 };

	LinkList<int> A(a, 4), B(b, 4);

	cout << "A:";
	A.PrintList();
	cout << "B:";
	B.PrintList();

	LinkList<int> C(A.Union(B));
	cout << "并集C:";
	C.PrintList();

	LinkList<int> D(A.Intersection(B));
	cout << "交集D:";
	D.PrintList();

	LinkList<int> E(A.Difference(B));
	cout << "差集E:";
	E.PrintList();

	return 0;
}