#include <iostream>
#include "Ordered_LinkList.h"

using namespace std;

int main() {
	int a[4] = { 4,1,2,3 }, b[4] = { 5,1,3,6 };
	
	Ordered_LinkList<int> OA(a, 4), OB(b, 4);

	cout << "OA:";
	OA.PrintList();
	cout << "OB:";
	OB.PrintList();

	Ordered_LinkList<int> OC(OA.Union(OB));
	cout << "����OC:";
	OC.PrintList();

	Ordered_LinkList<int> OD(OA.Intersection(OB));
	cout << "����OD:";
	OD.PrintList();

	Ordered_LinkList<int> OE(OA.Difference(OB));
	cout << "�OE:";
	OE.PrintList();

	return 0;
}