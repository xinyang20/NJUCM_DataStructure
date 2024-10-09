#pragma once
template<class DataType>
struct Data {
	DataType data;
	Node<DataType>* down,*right;
};

template<class DataType>
class SparseMatrix {
public:
	SparseMatrix(int row,int col);
	SparseMatrix(DataType arr[], int row, int col);
	operator+(const SparseMatrix& ohther);
	operator-(const SparseMatrix& ohther);
	operator==(const SparseMatrix& ohther);
	Change(int row, int col, DataType new_value);
private:

};