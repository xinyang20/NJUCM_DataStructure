#pragma once
const int StackSize = 20;

/*
	Stack ջ
	�ص㣺�Ƚ���������Ͱ��

	���ļ�Ϊ˳��ջ����󳤶�Ϊ20��Ԫ�أ�

	����ʱ�䣺2024/9/5
*/

template<class DataType>
class SeqStack {
public:
	SeqStack();
	~SeqStack() {}
	void Push(DataType x);
	DataType Pop();
	DataType GetTop();
	int Empty();
private:
	DataType data[StackSize];
	int top;
};

template<class DataType>
SeqStack<DataType>::SeqStack() {
	top = -1;
}

template<class DataType>
void SeqStack<DataType>::Push(DataType x) {
	if (top == StackSize - 1)throw "����";
	top++;
	data[top] = x;
}

template<class DataType>
DataType SeqStack<DataType>::Pop() {
	if (top == -1)throw "����";
	DataType x = data[top];
	top--;
	return x;
}

template<class DataType>
DataType SeqStack<DataType>::GetTop() {
	if (top != -1) {
		return data[top];
	}
	throw"ջΪ��";
}

template<class DataType>
int SeqStack<DataType>::Empty() {
	if (top == -1)return 1;
	return 0;
}