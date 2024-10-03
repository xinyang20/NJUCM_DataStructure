#pragma once
#include "LinkList.h"

/*
	name: Set.h

	basic files:
		LinkList.h

	create time: 2024/9/25


*/

template<class DataType>
class Set {
public:
	Set();
	Set(DataType a[], int n);
	Set(const Set<DataType>& other);
	~Set();
	DataType Get(int i);
	void Show();
	void Insert(DataType x);
	int Locate(DataType x);
	int Length();
	int Empty();
	int Equal(const Set<DataType>& compare);
	Set<DataType> Union(const Set<DataType>& compare);//����
	Set<DataType> Intersection(LinkList<DataType> x);//����
	Set<DataType> Difference(Set<DataType> x);//�
private:
	LinkList<DataType>* Data;
};

template<class DataType>
Set<DataType>::Set()
{
	Data = new LinkList<DataType>();
}

template<class DataType>
Set<DataType>::Set(DataType a[], int n)
{

}

template<class DataType>
Set<DataType>::Set(const Set<DataType>& other)
{

}

