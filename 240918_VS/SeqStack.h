#pragma once
const int StackSize = 20;

/*
	Stack 栈
	特点：先进后出（类比桶）

	该文件为顺序栈（最大长度为20个元素）

	创建时间：2024/9/5
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
	if (top == StackSize - 1)throw "下溢";
	top++;
	data[top] = x;
}

template<class DataType>
DataType SeqStack<DataType>::Pop() {
	if (top == -1)throw "下溢";
	DataType x = data[top];
	top--;
	return x;
}

template<class DataType>
DataType SeqStack<DataType>::GetTop() {
	if (top != -1) {
		return data[top];
	}
	throw"栈为空";
}

template<class DataType>
int SeqStack<DataType>::Empty() {
	if (top == -1)return 1;
	return 0;
}