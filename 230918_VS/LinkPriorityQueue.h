#pragma once
/*
	name: LinkPriorityQueue.h

	change time: 2024/9/19

*/

template<class DataType>
struct Node {
	DataType data;
	int priority;
	Node<DataType>* next;
};

template<class DataType>
class LinkPriorityQueue {
public:
	LinkPriorityQueue();
	LinkPriorityQueue(const LinkPriorityQueue& other);
	~LinkPriorityQueue();
	void Push(DataType x, int priority);
	DataType Pop();
	DataType Get();
	void ResetPriority(const DataType x, int old_priority, int new_priority);
	int Empty();
	void ShowQueue();
private:
	Node<DataType>* front, * rear;
};

template<class DataType>
LinkPriorityQueue<DataType>::LinkPriorityQueue()
{
	Node<DataType>* p = new Node<DataType>;
	p->next = NULL;
	p->priority = -1;
	front = rear = p;
}

template<class DataType>
LinkPriorityQueue<DataType>::LinkPriorityQueue(const LinkPriorityQueue& other)
{
	this->front = other.front;
	this->rear = other.rear;
}

template<class DataType>
LinkPriorityQueue<DataType>::~LinkPriorityQueue()
{
	Node<DataType>* p = new Node<DataType>;
	while (front != NULL) {
		p = front->next;
		delete front;
		front = p;
	}
}

template<class DataType>
void LinkPriorityQueue<DataType>::Push(DataType x, int priority)
{
	Node<DataType>* p = front, * q = new Node<DataType>;
	while (p->priority <= priority)
		p = p->next;
	if (p == NULL)
		rear = q;
	q->data = x;
	q->priority = priority;
	q->next = p->next;
	p->next = q;
}

template<class DataType>
DataType LinkPriorityQueue<DataType>::Pop()
{
	DataType x;
	Node<DataType>* p = NULL;
	p = new Node<DataType>;
	if (rear == front)throw"下溢";
	p = front->next;
	x = p->data;
	front->next = p->next;
	if (p->next == NULL)
		rear = front;
	delete p;
	return x;
}

template<class DataType>
DataType LinkPriorityQueue<DataType>::Get()
{
	if (front == rear)throw"下溢";
	DataType x = front->next->data;
	return x;
}

template<class DataType>
void LinkPriorityQueue<DataType>::ResetPriority(const DataType x, int old_priority, int new_priority)
{
	Node<DataType>* p = front->next;
	while (p->priority < old_priority && p != NULL)
		p = p->next;
	while (p->data != x && p->priority == old_priority && p != NULL) {
		if (p->next->data == x)
			Node<DataType>* q = p;
		p = p->next;
	}
	if (p == NULL)throw"下溢";
	if (p->priority != old_priority)throw"下溢";
	q->next = p->next;
	delete p;
	Push(x, new_priority);
}

template<class DataType>
int LinkPriorityQueue<DataType>::Empty()
{
	if (front == rear)return 1;
	return 0;
}

template<class DataType>
void LinkPriorityQueue<DataType>::ShowQueue()
{
	Node<DataType>* p = front->next;
	cout << "data\tpriority\n";
	while (p != NULL) {
		cout << p->data << "\t" << p->priority << "\n";
		p->next;
	}
}
