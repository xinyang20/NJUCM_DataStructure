#pragma once
#include <iostream>
using namespace std;
/*
	2024/9/11
	change files:
		add function : int Length();
		add function : int Empty();
		add function : DataType Get(int i)
		add function : int Equal(LinkList<DataType> x)
		add function : LinkList<DataType> Union(LinkList<DataType> x)
		add function : LinkList<DataType> Intersection(LinkList<DataType> x)
		add function : LinkList<DataType> Difference(LinkList<DataType> x)
		add function : LinkList(const LinkList<DataType>& other)
*/

template<class DataType>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkList {
private:
	Node<DataType>* first;
public:
	LinkList();
	LinkList(DataType a[], int n);
	~LinkList();
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
	int Length();
	int Empty();
	DataType Get(int i);
	int Equal(LinkList<DataType> x);
	LinkList<DataType> Union(LinkList<DataType> x);//并集
	LinkList<DataType> Intersection(LinkList<DataType> x);//交集
	LinkList<DataType> Difference(LinkList<DataType> x);//差集
	LinkList(const LinkList<DataType>& other);
};

template<class DataType>
LinkList<DataType>::LinkList() {
	first = new Node<DataType>;
	first->next = NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n) {
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
LinkList<DataType>::~LinkList() {
	Node<DataType>* q = NULL;
	while (first != NULL) {
		q = first;
		first = first->next;
		delete q;
	}
}

template<class DataType>
int LinkList<DataType>::Locate(DataType x) {
	Node<DataType>* q = first->next;
	int count = 1;
	while (q != NULL) {
		if (q->data == x)return count;
		q = q->next;
		count++;
	}
	return 0;
}

template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x) {
	Node<DataType>* p = first, * s = NULL;
	int count = 0;
	while (p != NULL && count < i - 1) {
		p = p->next;
		count++;
	}
	if (p == NULL)throw"非法位置";
	else {
		s = new Node<DataType>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}

}

template<class DataType>
DataType LinkList<DataType>::Delete(int i) {
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
void LinkList<DataType>::PrintList() {
	Node<DataType>* p = first->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class DataType>
int LinkList<DataType>::Length() {
	Node<DataType>* p = first->next;
	int length = 0;
	while (p != NULL) {
		length++;
		p = p->next;
	}
	return length;
}

template<class DataType>
int LinkList<DataType>::Empty()
{
	if (first->next == NULL)return 1;
	return 0;
}

template<class DataType>
DataType LinkList<DataType>::Get(int i) {
	Node<DataType>* p = first->next;
	int k = 1;
	while (p != NULL && k < i) {
		p = p->next;
		k++;
	}
	if (k == i)return p->data;
}

template<class DataType>
int LinkList<DataType>::Equal(LinkList<DataType> Compare) {
	int len = Length(), clen = Compare.Length();
	if (len != clen)return 0;
	for (int i = 1; i <= len; i++) {
		DataType aelement = Get(i);
		for (int j = 1; j <= clen; j++) {
			DataType celement = Compare.Get(j);
			if (aelement == celement)break;
			if (j == clen)return 0;
		}
	}	
	return 1;
}

template<class DataType>
LinkList<DataType> LinkList<DataType>::Union(LinkList<DataType> x)//并集
{
	LinkList<DataType> C;
	int len = 1;
	Node<DataType>* p = first->next;
	while (p != NULL) {
		C.Insert(len, p->data);
		p = p->next;
		len++;
	}
	p = x.first->next;
	while (p != NULL) {
		DataType xelement = p->data;
		if (Locate(xelement) == 0) {
			C.Insert(len, xelement);
			len++;
		}
		p = p->next;
	}
	return C;
}

template<class DataType>
LinkList<DataType> LinkList<DataType>::Intersection(LinkList<DataType> x)//交集
{
	LinkList<DataType> C;
	int len = 1;
	Node<DataType>* p = first->next;
	while (p != NULL) {
		if (x.Locate(p->data) != 0) {
			C.Insert(len, p->data);
			len++;
		}
		p = p->next;
	}
	return C;
}

template<class DataType>
LinkList<DataType> LinkList<DataType>::Difference(LinkList<DataType> x)//差集
{
	LinkList<DataType> C;
	int len = 1;
	Node<DataType>* p = first->next;
	while (p != NULL) {
		if (x.Locate(p->data) == 0) {
			C.Insert(len, p->data);
			len++;
		}
		p = p->next;
	}
	return C;
}

template<class DataType>
LinkList<DataType>::LinkList(const LinkList<DataType>& other) {
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
