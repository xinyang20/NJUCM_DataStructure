#pragma once

/*
	
*/

const int StackSize = 200;

template<class DataType>
class BothStack {
public:
	BothStack();
	BothStack(const BothStack& other);
	void Push(int i, DataType x);
	DataType Pop(int i);
	DataType GetTop(int i);
	int Empty(int i);
	int Empty();
private:
	DataType Data[StackSize];
	int top1,top2;
};

template<class DataType>
BothStack<DataType>::BothStack()
{
	top1 = -1;
	top2 = StackSize;
}

template<class DataType>
BothStack<DataType>::BothStack(const BothStack& other)
{
	top1 = other.top1;
	top2 = other.top2;
	for (int i = 0; i <= top1; i++)
		Data[i] = other.Data[i];
	for (int i = StackSize - 1; i >= top2; i--)
		Data[i] = other.Data[i];
}

template<class DataType>
void BothStack<DataType>::Push(int i, DataType x)
{
	if (top1 == top2)throw"上溢";
	if (i == 1) {
		top1++;
		Data[top1] = x;
	}
	else if (i == 2) {
		top2--;
		Data[top2] = x;
	}	
}

template<class DataType>
DataType BothStack<DataType>::Pop(int i)
{
	if (i == 1 && top1 == -1)throw"下溢";
	if (i == 2 && top2 == StackSize)throw"下溢";
	
	if (i == 1) {
		DataType x = Data[top1];
		top1--;
	}
	else if (i == 2) {
		DataType x = Data[top2];
		top2++;
	}
	return x;
}

template<class DataType>
DataType BothStack<DataType>::GetTop(int i)
{
	if (i == 1 && top[0] == -1)throw"下溢";
	if (i == 2 && top[1] == StackSize)throw"下溢";
	if (i == 1)
		DataType x = Data[top1];
	if (i == 2)
		DataType x = Data[top2];
	return x;
}

template<class DataType>
int BothStack<DataType>::Empty(int i)
{
	if (i == 1 && top1 == -1)return 1;
	if (i == 2 && top2 == StackSize)return 1;
	return 0;
}

template<class DataType>
inline int BothStack<DataType>::Empty()
{
	if (top1 == -1 && top2 == StackSize)return 1;
	return 0;
}
