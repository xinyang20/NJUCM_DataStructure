#pragma once
/*
	Queue ����
	�ص㣺�Ƚ��ȳ�����ȶ��飩

	���ļ�Ϊ������

	����ʱ�䣺2024/9/5
*/

template<class DataType>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkQueue {
public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(DataType x);
	DataType DeQueue();
	DataType GetQueue();
	int Empty();
private:
	Node<DataType>* front, * rear;
};

template<class DataType>
LinkQueue<DataType>::LinkQueue() {
	Node<DataType>* s = NULL;
	s = new Node<DataType>;
	s->next = NULL;
	front = rear = s;
}

template<class DataType>
LinkQueue<DataType>::~LinkQueue() {
	Node<DataType>* p = NULL;
	while (front != NULL) {
		p = front->next;
		delete front;
		front = p;
	}
}

template<class DataType>
void LinkQueue<DataType>::EnQueue(DataType x) {
	Node<DataType>* p = NULL;
	p = new Node<DataType>;
	p->data = x;
	p->next = NULL;
	rear->next = p;
	rear = p;
}

template<class DataType>
DataType LinkQueue<DataType>::DeQueue() {
	Node<DataType>* p = NULL;
	DataType x;
	if (rear == front)throw"����";
	p = front->next;
	x = p->data;
	front->next = p->next;
	if (p->next == NULL)
		rear = front;
	delete p;
	return x;
}

template<class DataType>
DataType LinkQueue<DataType>::GetQueue() {
	if (front == rear)throw"����";
	return front->next->data;
}

template<class DataType>
int LinkQueue<DataType>::Empty() {
	if (front == rear)return 1;
	return 0;
}