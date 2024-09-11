#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
/*
	name: Ordered_LinkList.h

	creat_time: 2024/9/11

	based_files: LinkList.h(2024/9/11)

	change:
		add function: void Insert(DataType x)
		delete funtion: void Insert(int i,DataType x)
		rebuild function: int Locate(DataType x)
		rebuild function: int Equal(Ordered_LinkList<DataType> x)
		rebuild function: Ordered_LinkList<DataType> Union(Ordered_LinkList<DataType> x)
		rebuild function: Ordered_LinkList<DataType> Intersection(Ordered_LinkList<DataType> x)
*/

template<class DataType>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class Ordered_LinkList {
private:
	Node<DataType>* first;
public:
	Ordered_LinkList();
	Ordered_LinkList(DataType a[], int n);
	Ordered_LinkList(const Ordered_LinkList<DataType>& other);
	~Ordered_LinkList();
	int Locate(DataType x);
	void Insert(DataType x);
	DataType Delete(int i);
	void PrintList();
	int Length();
	int Empty();
	DataType Get(int i);
	int Equal(Ordered_LinkList<DataType> x);
	Ordered_LinkList<DataType> Union(Ordered_LinkList<DataType> x);//并集
	Ordered_LinkList<DataType> Intersection(Ordered_LinkList<DataType> x);//交集
	Ordered_LinkList<DataType> Difference(Ordered_LinkList<DataType> x);//差集

};

template<class DataType>
Ordered_LinkList<DataType>::Ordered_LinkList() {
	first = new Node<DataType>;
	first->next = NULL;
}

template<class DataType>
Ordered_LinkList<DataType>::Ordered_LinkList(DataType a[], int n) {
	sort(a, a + n);
	Node<DataType>* r, * s;
	first = new Node<DataType>;
	r = first;
	for (int i = 0; i < n; i++) {
		s = new Node<DataType>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

template<class DataType>
Ordered_LinkList<DataType>::~Ordered_LinkList() {
	Node<DataType>* q = NULL;
	while (first != NULL) {
		q = first;
		first = first->next;
		delete q;
	}
}

template<class DataType>
int Ordered_LinkList<DataType>::Locate(DataType x) {
	Node<DataType>* q = first->next;
	int count = 1;
	while (q != NULL) {
		if (q->data > x)return 0;
		if (q->data == x)return count;
		q = q->next;
		count++;
	}
	return 0;
}

template<class DataType>
void Ordered_LinkList<DataType>::Insert(DataType x) {
	Node<DataType>* p = first, * s = NULL;
	while (p->next != NULL) {
		if (p->next->data > x)break;
		p = p->next;
	}
	s = new Node<DataType>;
	s->data = x;
	s->next = p->next;
	p->next = s;
}

template<class DataType>
DataType Ordered_LinkList<DataType>::Delete(int i) {
	Node<DataType>* p = first, * q = NULL;
	DataType x;
	int count = 0;
	while (p != NULL && count < i - 1) {
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL)throw"位置非法";
	else {
		q = p->next;
		x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}

template<class DataType>
void Ordered_LinkList<DataType>::PrintList() {
	Node<DataType>* p = first->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class DataType>
int Ordered_LinkList<DataType>::Length() {
	Node<DataType>* p = first->next;
	int length = 0;
	while (p != NULL) {
		length++;
		p = p->next;
	}
	return length;
}

template<class DataType>
int Ordered_LinkList<DataType>::Empty()
{
	if (first->next == NULL)return 1;
	return 0;
}

template<class DataType>
DataType Ordered_LinkList<DataType>::Get(int i) {
	Node<DataType>* p = first->next;
	int k = 1;
	while (p != NULL && k < i) {
		p = p->next;
		k++;
	}
	if (k == i)return p->data;
}

template<class DataType>
int Ordered_LinkList<DataType>::Equal(Ordered_LinkList<DataType> Compare) {
	int len = Length(), clen = Compare.Length();
	if (len != clen)return 0;
	for (int i = 1; i <= len; i++) {
		DataType aelement = Get(i);
		DataType celement = Compare.Get(i);
		if (aelement != celement)return 0;
	}
	return 1;
}

template<class DataType>
Ordered_LinkList<DataType> Ordered_LinkList<DataType>::Union(Ordered_LinkList<DataType> x)//并集
{
	Ordered_LinkList<DataType> C;
	Node<DataType>* p = first->next, * xp = x.first->next;
	while (p != NULL && xp != NULL) {
		if (p->data > xp->data) {
			C.Insert(xp->data);
			xp = xp->next;
		}
		else if (p->data < xp->data) {
			C.Insert(p->data);
			p = p->next;
		}
		else {
			C.Insert(p->data);
			p = p->next;
			xp = xp->next;
		}
	}
	if (p == NULL)
		while (xp != NULL) {
			C.Insert(xp->data);
			xp = xp->next;
		}
	if (xp == NULL)
		while (p != NULL) {
			C.Insert(p->data);
			p = p->next;
		}
	return C;
}

template<class DataType>
Ordered_LinkList<DataType> Ordered_LinkList<DataType>::Intersection(Ordered_LinkList<DataType> x)//交集
{
	Ordered_LinkList<DataType> C;
	Node<DataType>* p = first->next, * xp = x.first->next;
	while (p->next != NULL) {
		while (p->data != xp->data) {
			if (p->data < xp->data)p = p->next;
			else xp = xp->next;
		}
		if (p->next == NULL || xp->next == NULL)break;
		if (x.Locate(p->data) != 0) {
			C.Insert(p->data);
		}
		p = p->next;
	}
	return C;
}

template<class DataType>
Ordered_LinkList<DataType> Ordered_LinkList<DataType>::Difference(Ordered_LinkList<DataType> x)//差集
{
	Ordered_LinkList<DataType> C;
	Node<DataType>* p = first->next;
	while (p != NULL) {
		if (x.Locate(p->data) == 0) {
			C.Insert(p->data);
		}
		p = p->next;
	}
	return C;
}

template<class DataType>
Ordered_LinkList<DataType>::Ordered_LinkList(const Ordered_LinkList<DataType>& other) {
	if (other.first != NULL) {
		first = new Node<DataType>;
		first->data = other.first->data;
		Node<DataType>* p = first;
		Node<DataType>* otherP = other.first->next;
		while (otherP != NULL) {
			p->next = new Node<DataType>;
			p = p->next;
			p->data = otherP->data;
			otherP = otherP->next;
		}
		p->next = NULL;
	}
	else {
		first = NULL;
	}
}
