#pragma once

template<class DataType>
struct Node {
	DataType data;
	Node<DataType>* next, * prev;
};

template<class DataType>
class DoubleQueue {
public:
	DoubleQueue();
	DoubleQueue(DataType a[],int n);
	DoubleQueue(const DoubleQueue& other);
	~DoubleQueue();
	void EnQueueHead(DataType x);
	void EnQueueTail(DataType x);
	DataType DeQueueHead();
	DataType DeQueueTail();
	DataType GetHead();
	DataType GetTail();
	int Empty();
private:
	Node<DataType>* front, * rear;
};

template<class DataType>
DoubleQueue<DataType>::DoubleQueue() {
	Node<DataType>* s = NULL;
	s = new Node<DataType>;
	s->next = NULL;
	s->prev = NULL;
	front = rear = s;
}

template<class DataType>
DoubleQueue<DataType>::DoubleQueue(DataType a[], int n) {

}

template<class DataType>
DoubleQueue<DataType>::DoubleQueue(const DoubleQueue& other) {

}

template<class DataType>
DoubleQueue<DataType>::~DoubleQueue() {
	Node<DataType>* p = NULL;
	while (front != NULL) {
		p = front->next;
		delete front;
		front = p;
	}
}

template<class DataType>
void DoubleQueue<DataType>::EnQueueHead(DataType x)
{

}

template<class DataType>
void DoubleQueue<DataType>::EnQueueTail(DataType x)
{
	Node<DataType>* p = NULL;
	p = new Node<DataType>;
	p->data = x;
	p->next = NULL;
	p->prev = rear;
	rear->next = p;
	rear = p;
}

template<class DataType>
DataType DoubleQueue<DataType>::DeQueueHead()
{
	Node<DataType>* p = NULL;
	DataType x;
	if (rear == front)throw"下溢";
	p = front->next;
	x = p->data;
	front->next = p->next;
	p->next->prev = front;
	if (p->next == NULL)
		rear = front;
	delete p;
	return x;
}

template<class DataType>
DataType DoubleQueue<DataType>::DeQueueTail()
{
	Node<DataType>* p = NULL;
	DataType x;
	if (rear == front)throw"下溢";
	p = rear;
	x = p->data;
	rear = p->prev;
	rear->next = NULL;
	if (p->next == NULL)
		rear = front;
	delete p;
	return x;
}

template<class DataType>
DataType DoubleQueue<DataType>::GetHead()
{
	if (front == rear)throw"下溢";
	return front->next->data;
}

template<class DataType>
DataType DoubleQueue<DataType>::GetTail()
{
	if (front == rear)throw"下溢";
	return rear->data;
}

template<class DataType>
int DoubleQueue<DataType>::Empty()
{
	if (front == rear)return 1;
	return 0;
}
