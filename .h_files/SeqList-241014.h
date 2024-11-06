#pragma once

const int MaxSize = 50;

template<class DataType>
class SeqList {
private:
	DataType data[MaxSize];
	int length;
public:
	SeqList() { length = 0; }
	SeqList(DataType a[], int n);
	~SeqList(){}
	void Insert(int i, DataType x);
	DataType Delete(int i);
	int Locate(DataType x);
	DataType operator[](int i);
	DataType Get(int i);
	void PrintList();
};

template<class DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
	if (n > MaxSize)throw"参数非法";
	for (int i = 0; i < n; i++) {
		data[i] = a[i];
	}
	length = n;
}

template<class DataType>
void SeqList<DataType>::Insert(int i, DataType x) {
	if (length > MaxSize)throw"上溢";
	if (i<1 || i>length + 1)throw"位置非法";
	for (int j = length; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	length++;
}

template<class DataType>
DataType SeqList<DataType>::Delete(int i) {
	if (length == 0)throw"下溢";
	if (i<1 || i>length)throw"位置非法";
	DataType x = data[i - 1];
	for (int j = i; j < length; j++) {
		data[j - 1] = data[j];
	}
	length--;
	return x;
}

template<class DataType>
int SeqList<DataType>::Locate(DataType x) {
	for (int i = 0; i < length; i++) {
		if (data[i] == x)return i + 1;
	}
	return 0;
}

template<class DataType>
DataType SeqList<DataType>::operator[](int i)
{
	if (i >= length)throw"位置非法";
	return data[i];
}

template<class DataType>
DataType SeqList<DataType>::Get(int i)
{
	if (i >= length)throw"位置非法";
	return data[i];
}

template<class DataType>
void SeqList<DataType>::PrintList() {
	for (int i = 0; i < length; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}


int Get_SeqList_MaxSize() { return MaxSize; };