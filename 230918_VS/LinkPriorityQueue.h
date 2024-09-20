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
	DataType Priority_Get(int priority);
	void ResetPriority(const DataType x, int old_priority, int new_priority);
	int Empty();
	int Length();
	int Priority_Length(int priority);
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
	Node<DataType>* q = new Node<DataType>{ x, priority, NULL };
	Node<DataType>* p = front;
	if (front->next == NULL || priority < front->next->priority) {
		q->next = front->next;
		front->next = q;
		if (rear == front) { 
			rear = q;
		}
	}
	else {
		while (p->next != NULL && p->next->priority <= priority) {
			p = p->next;
		}
		q->next = p->next;
		p->next = q;
		if (p->next == NULL)
			rear = q;
	}
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
DataType LinkPriorityQueue<DataType>::Priority_Get(int priority)
{
	if (front == rear)throw"下溢";
	Node<DataType>* p = front->next;
	while (p->priority < priority&&p->next!=NULL)
		p = p->next;
	if (p->priority > priority||p->next==NULL)throw"不存在该优先级";
	DataType x = p->data;
	return x;
}

template<class DataType>
void LinkPriorityQueue<DataType>::ResetPriority(const DataType x, int old_priority, int new_priority)
{
	Node<DataType>* p = front->next, * q = NULL;
	while (p->priority < old_priority && p != NULL)
		p = p->next;
	while (p->data != x && p->priority == old_priority && p != NULL) {
		if (p->next->data == x)
			q = p;
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
int LinkPriorityQueue<DataType>::Length()
{
	int count = 0;
	Node<DataType>* p = front->next;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

template<class DataType>
int LinkPriorityQueue<DataType>::Priority_Length(int priority)
{
	int count = 0;
	Node<DataType>* p = front->next;
	while (p->priority < priority)
		p = p->next;
	while (p->priority == priority) {
		count++;
		p = p->next;
	}
	return count;
}