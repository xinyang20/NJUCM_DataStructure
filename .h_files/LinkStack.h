#pragma once

template <class DataType>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template <class DataType>
class LinkStack {
public:
	LinkStack();
	LinkStack(const LinkStack& other);
	~LinkStack();
	void Push(DataType x);
	DataType Pop();
	DataType GetTop();
	int Empty();
private:
	Node<DataType>* top;
};

template<class DataType>
LinkStack<DataType>::LinkStack()
{
	Node<DataType>* p = NULL;
	top = p;
}

template<class DataType>
LinkStack<DataType>::LinkStack(const LinkStack& other)
{
	top = other.top;
}

template<class DataType>
LinkStack<DataType>::~LinkStack()
{
	Node<DataType>* p = top,*q=NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		delete q;
	}
	delete p;
}

template<class DataType>
void LinkStack<DataType>::Push(DataType x)
{
	Node<DataType>* p = NULL;
	p = new Node<DataType>;
	p->data = x;
	p->next = top;
	top = p;
}

template<class DataType>
DataType LinkStack<DataType>::Pop() {
	if (top == NULL)throw"ÏÂÒç";
	Node<DataType>* p = top;
	DataType x = p->data;
	top = p->next;
	delete p;
	return x;
}

template<class DataType>
DataType LinkStack<DataType>::GetTop() {
	if (top == NULL)throw"Õ»Îª¿Õ";
	return top->data;
}

template<class DataType>
int LinkStack<DataType>::Empty() {
	if (top == NULL)return 1;
	return 0;
}