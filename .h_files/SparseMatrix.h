//该头文件未完成，无法正常使用，存在众多未知bug。
#pragma once
#include "SeqList.h"

const int SeqListMaxSize = Get_SeqList_MaxSize();

template<class DataType>
struct EDT {
	DataType value;//元素值
	int row, col;//元素坐标
};

template<class DataType>
struct Node {
	EDT<DataType> data;//元素数据，包含行、列、值
	Node<DataType>* down, * right;//优化版十字链表节点，记录右方、下方元素的地址
};

template<class DataType>
class SparseMatrix {
public:
	SparseMatrix(int row, int col);//置空构造函数
	SparseMatrix(DataType* arr, int row, int col);//从数组拷贝构造函数
	~SparseMatrix();//析构函数
	SparseMatrix<DataType> operator+(const SparseMatrix<DataType>& other);//重载+运算符，完成矩阵加法运算功能
	SparseMatrix<DataType> operator-(const SparseMatrix<DataType>& other);//重载-运算符，完成矩阵减法运算功能
	bool operator==(const SparseMatrix<DataType>& other);//重载==运算符，完成矩阵对比运算功能
	SparseMatrix<DataType> operator=(const SparseMatrix<DataType>& other);//重载=运算符，完成矩阵赋值功能
	void Change(int row, int col, DataType new_value);//修改矩阵元素值
	void ShowElements();//展示矩阵中非0元素
	//void ShowMatrix();
	DataType Get(int row, int col);//通过坐标获取矩阵中元素的值
	Node<DataType>* GetIndexRowHead(int row) const;

private:
	int NumRow, NumCol;//记录矩阵的行数列数
	SeqList<Node<DataType>* >RowHead;//利用顺序表结构的行首指针
	SeqList<Node<DataType>* >ColHead;//利用顺序表结构的列首指针
	void InsertNewNode(int row, int col, DataType value);//插入元素函数
};

template<class DataType>
SparseMatrix<DataType>::SparseMatrix(int row, int col)
{
	if (row<0 || row>SeqListMaxSize)throw"行首指针表溢出";
	if (col<0 || col>SeqListMaxSize)throw"列首指针表溢出";
	NumRow = row;
	NumCol = col;
	Node<DataType>* p;
	for (int i = 0; i < row; i++) {
		p = new Node<DataType>;
		p->right = NULL;//通过行首指针仅可向右访问行内元素
		p->down = NULL;
		RowHead.Insert(i, p);
	}
	for (int i = 0; i < col; i++) {
		p = new Node<DataType>;
		p->right = NULL;
		p->down = NULL;//通过列首指针仅可向下访问列内元素
		ColHead.Insert(i, p);
	}
}

template<class DataType>
SparseMatrix<DataType>::SparseMatrix(DataType* arr, int row, int col)
{
	if (row<0 || row>SeqListMaxSize)throw"行首指针表溢出";
	if (col<0 || col>SeqListMaxSize)throw"列首指针表溢出";
	NumRow = row;
	NumCol = col;
	Node<DataType>* p;
	for (int i = 0; i < row; i++) {
		p = new Node<DataType>;
		p->right = NULL;//通过行首指针仅可向右访问行内元素
		p->down = NULL;
		RowHead.Insert(i, p);
	}
	for (int i = 0; i < col; i++) {
		p = new Node<DataType>;
		p->right = NULL;
		p->down = NULL;//通过列首指针仅可向下访问列内元素
		ColHead.Insert(i, p);
	}
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			if (*(arr + (r * col + c)) != 0)//访问r行c列的元素，通过非0则插入
				InsertNewNode(r, c, *(arr + (r * col + c)));
		}
	}
}

template<class DataType>
SparseMatrix<DataType> SparseMatrix<DataType>::operator=(const SparseMatrix<DataType>& other)
{
	if (this == &other) {
		return *this;  // 自我赋值保护
	}

	// 清除当前矩阵的数据
	Node<DataType>* p, * q;
	for (int row = 0; row < NumRow; row++) {
		p = RowHead.Get(row);
		while (p != NULL) {
			q = p;
			p = p->right;
			delete q;
		}
	}
	delete RowHead;
	delete ColHead;

	// 初始化新的矩阵结构
	this->NumRow = other.NumRow;
	this->NumCol = other.NumCol;

	RowHead = new SeqList<Node<DataType>*>(NumRow);
	ColHead = new SeqList<Node<DataType>*>(NumCol);

	// 复制 other 矩阵的内容
	for (int row = 0; row < NumRow; row++) {
		Node<DataType>* other_p = other.RowHead.Get(row);
		Node<DataType>* prev = nullptr;
		while (other_p != NULL) {
			// 复制节点
			Node<DataType>* newNode = new Node<DataType>;
			newNode->data.row = other_p->data.row;
			newNode->data.col = other_p->data.col;
			newNode->data.value = other_p->data.value;
			newNode->right = NULL;
			newNode->down = NULL;

			if (prev == NULL) {
				RowHead.Insert(row, newNode);
			}
			else {
				prev->right = newNode;
			}

			if (ColHead.Get(newNode->data.col) == NULL) {
				ColHead.Insert(newNode->data.col, newNode);
			}
			else {
				Node<DataType>* colPrev = ColHead.Get(newNode->data.col);
				while (colPrev->down != NULL) {
					colPrev = colPrev->down;
				}
				colPrev->down = newNode;
			}

			prev = newNode;
			other_p = other_p->right;
		}
	}

	return *this;
}


template<class DataType>
SparseMatrix<DataType>::~SparseMatrix()
{
	Node<DataType>* p, * q;
	for (int row = 0; row < NumRow; row++) {
		p = RowHead.Get(row);
		while (p != NULL) {
			q = p;
			p = p->right;
			delete q;
		}
	}
}

template<class DataType>
SparseMatrix<DataType> SparseMatrix<DataType>::operator+(const SparseMatrix<DataType>& other)
{
	if (this->NumRow != other.NumRow || this->NumCol != other.NumCol)
		throw"矩阵类型不匹配，无法操作";
	SparseMatrix<DataType> result(this->NumRow, this->NumCol);
	Node<DataType>* sp, * op;
	for (int row = 0; row < NumRow; row++) {
		sp = this->RowHead.Get(row);
		op = other.GetIndexRowHead(row);
		while (sp != NULL || op != NULL) {
			if (sp == NULL) {
				result.InsertNewNode(op->data.row, op->data.col, op->data.value);  // 只存在 op
				op = op->right;
			}
			else if (op == NULL) {
				result.InsertNewNode(sp->data.row, sp->data.col, sp->data.value);  // 只存在 sp
				sp = sp->right;
			}
			else if (sp->data.col < op->data.col) {
				result.InsertNewNode(sp->data.row, sp->data.col, sp->data.value);  // sp 先插入
				sp = sp->right;
			}
			else if (sp->data.col > op->data.col) {
				result.InsertNewNode(op->data.row, op->data.col, op->data.value);  // op 先插入
				op = op->right;
			}
			else {
				DataType sum = sp->data.value + op->data.value;
				if (sum != 0) {
					result.InsertNewNode(sp->data.row, sp->data.col, sum);  // 只插入非零值
				}
				sp = sp->right;
				op = op->right;
			}
		}
	}
	return result;
}

template<class DataType>
SparseMatrix<DataType> SparseMatrix<DataType>::operator-(const SparseMatrix<DataType>& other)
{
	if (this->NumRow != other.NumRow || this->NumCol != other.NumCol)
		throw"矩阵类型不匹配，无法操作";
	SparseMatrix<DataType> result(this->NumRow, this->NumCol);
	Node<DataType>* sp, * op;
	for (int row = 0; row < NumRow; row++) {
		sp = this->RowHead.Get(row);
		op = other.GetIndexRowHead(row);
		while (sp != NULL || op != NULL) {
			if (sp == NULL) {
				result.InsertNewNode(op->data.row, op->data.col, -op->data.value);  // 只存在 op，取负
				op = op->right;
			}
			else if (op == NULL) {
				result.InsertNewNode(sp->data.row, sp->data.col, sp->data.value);  // 只存在 sp
				sp = sp->right;
			}
			else if (sp->data.col < op->data.col) {
				result.InsertNewNode(sp->data.row, sp->data.col, sp->data.value);  // sp 先插入
				sp = sp->right;
			}
			else if (sp->data.col > op->data.col) {
				result.InsertNewNode(op->data.row, op->data.col, -op->data.value);  // op 先插入，取负
				op = op->right;
			}
			else {
				DataType diff = sp->data.value - op->data.value;
				if (diff != 0) {
					result.InsertNewNode(sp->data.row, sp->data.col, diff);  // 只插入非零值
				}
				sp = sp->right;
				op = op->right;
			}
		}
	}
	return result;
}

template<class DataType>
bool SparseMatrix<DataType>::operator==(const SparseMatrix<DataType>& other)
{
	if (this->NumRow != other.NumRow || this->NumCol != other.NumCol)
		return false;
	Node<DataType>* sp, * op;
	for (int row = 0; row < NumRow; row++) {
		sp = this->RowHead.Get(row);
		op = other.GetIndexRowHead(row);
		while (sp->right != NULL && op->right != NULL) {
			if (sp->right == NULL || op->right == NULL || sp->data.value != op->data.value)
				return false;
			sp = sp->right;
			op = op->right;
		}
	}
	return true;
}

template<class DataType>
void SparseMatrix<DataType>::Change(int row, int col, DataType new_value)
{
	if (Get(row, col) != 0) {//可以优化为一次遍历
		Node<DataType>* p = RowHead.Get(row);
		if (new_value == 0) {
			while (p->right->data.col < col)
				p = p->right;
			p->right = p->right->right;

			p = ColHead.Get(col);
			while (p->down->data.row < row)
				p = p->down;
			Node<DataType>* q = p->down;
			p->down = p->down->down;
			delete q;
		}
		else {
			while (p->data.col < col)
				p = p->right;
			p->data.value = new_value;
		}
	}
	else if (new_value != 0) {
		InsertNewNode(row, col, new_value);
	}
}

template<class DataType>
void SparseMatrix<DataType>::ShowElements()
{
	Node<DataType>* p;
	bool have = false;
	for (int row = 0; row < NumRow; row++) {
		p = RowHead.Get(row);
		if (p == NULL)continue;
		while (p != NULL) {
			if (!have) {
				cout << "Row\tCol\tvalue\n";
				have = true;
			}
			cout << p->data.row << "\t" << p->data.col << "\t" << p->data.value << "\n";
			p = p->right;
		}
	}
	if (!have)cout << "该矩阵全部为空，无非0值\n";
}

template<class DataType>
DataType SparseMatrix<DataType>::Get(int row, int col)
{
	if (row < 0 || row >= NumRow || col < 0 || col >= NumCol)throw"位置非法";
	Node<DataType>* p = RowHead.Get(row);
	if (p == NULL)return 0;
	DataType x = -1;
	while (p->right != NULL && p->right->data.col < col)
		p = p->right;
	if (p->right == NULL || p->right->data.col > col)x = 0;
	else x = p->right->data.value;
	return x;
}

template<class DataType>
Node<DataType>* SparseMatrix<DataType>::GetIndexRowHead(int row) const
{
	Node<DataType>* p = RowHead.Get(row);
	return p;
}

template<class DataType>
void SparseMatrix<DataType>::InsertNewNode(int row, int col, DataType value)
{
	if (row < 0 || row >= NumRow || col < 0 || col >= NumCol)
		throw"下溢";
	Node<DataType>* p = new Node<DataType>;
	p->data.row = row;
	p->data.col = col;
	p->data.value = value;
	p->down = NULL;
	p->right = NULL;

	Node<DataType>* currRowPoint = RowHead.Get(row);
	while (currRowPoint->right != NULL && currRowPoint->right->data.col < col) // 避免解引用 NULL
		currRowPoint = currRowPoint->right;
	p->right = currRowPoint->right;
	currRowPoint->right = p;

	Node<DataType>* currColPoint = ColHead.Get(col);
	while (currColPoint->down != NULL && currColPoint->down->data.row < row) // 避免解引用 NULL
		currColPoint = currColPoint->down;
	p->down = currColPoint->down;
	currColPoint->down = p;
}