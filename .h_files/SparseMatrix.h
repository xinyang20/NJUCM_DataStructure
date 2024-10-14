//��ͷ�ļ�δ��ɣ��޷�����ʹ�ã������ڶ�δ֪bug��
#pragma once
#include "SeqList.h"

const int SeqListMaxSize = Get_SeqList_MaxSize();

template<class DataType>
struct EDT {
	DataType value;//Ԫ��ֵ
	int row, col;//Ԫ������
};

template<class DataType>
struct Node {
	EDT<DataType> data;//Ԫ�����ݣ������С��С�ֵ
	Node<DataType>* down, * right;//�Ż���ʮ������ڵ㣬��¼�ҷ����·�Ԫ�صĵ�ַ
};

template<class DataType>
class SparseMatrix {
public:
	SparseMatrix(int row, int col);//�ÿչ��캯��
	SparseMatrix(DataType* arr, int row, int col);//�����鿽�����캯��
	~SparseMatrix();//��������
	SparseMatrix<DataType> operator+(const SparseMatrix<DataType>& other);//����+���������ɾ���ӷ����㹦��
	SparseMatrix<DataType> operator-(const SparseMatrix<DataType>& other);//����-���������ɾ���������㹦��
	bool operator==(const SparseMatrix<DataType>& other);//����==���������ɾ���Ա����㹦��
	SparseMatrix<DataType> operator=(const SparseMatrix<DataType>& other);//����=���������ɾ���ֵ����
	void Change(int row, int col, DataType new_value);//�޸ľ���Ԫ��ֵ
	void ShowElements();//չʾ�����з�0Ԫ��
	//void ShowMatrix();
	DataType Get(int row, int col);//ͨ�������ȡ������Ԫ�ص�ֵ
	Node<DataType>* GetIndexRowHead(int row) const;

private:
	int NumRow, NumCol;//��¼�������������
	SeqList<Node<DataType>* >RowHead;//����˳���ṹ������ָ��
	SeqList<Node<DataType>* >ColHead;//����˳���ṹ������ָ��
	void InsertNewNode(int row, int col, DataType value);//����Ԫ�غ���
};

template<class DataType>
SparseMatrix<DataType>::SparseMatrix(int row, int col)
{
	if (row<0 || row>SeqListMaxSize)throw"����ָ������";
	if (col<0 || col>SeqListMaxSize)throw"����ָ������";
	NumRow = row;
	NumCol = col;
	Node<DataType>* p;
	for (int i = 0; i < row; i++) {
		p = new Node<DataType>;
		p->right = NULL;//ͨ������ָ��������ҷ�������Ԫ��
		p->down = NULL;
		RowHead.Insert(i, p);
	}
	for (int i = 0; i < col; i++) {
		p = new Node<DataType>;
		p->right = NULL;
		p->down = NULL;//ͨ������ָ��������·�������Ԫ��
		ColHead.Insert(i, p);
	}
}

template<class DataType>
SparseMatrix<DataType>::SparseMatrix(DataType* arr, int row, int col)
{
	if (row<0 || row>SeqListMaxSize)throw"����ָ������";
	if (col<0 || col>SeqListMaxSize)throw"����ָ������";
	NumRow = row;
	NumCol = col;
	Node<DataType>* p;
	for (int i = 0; i < row; i++) {
		p = new Node<DataType>;
		p->right = NULL;//ͨ������ָ��������ҷ�������Ԫ��
		p->down = NULL;
		RowHead.Insert(i, p);
	}
	for (int i = 0; i < col; i++) {
		p = new Node<DataType>;
		p->right = NULL;
		p->down = NULL;//ͨ������ָ��������·�������Ԫ��
		ColHead.Insert(i, p);
	}
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			if (*(arr + (r * col + c)) != 0)//����r��c�е�Ԫ�أ�ͨ����0�����
				InsertNewNode(r, c, *(arr + (r * col + c)));
		}
	}
}

template<class DataType>
SparseMatrix<DataType> SparseMatrix<DataType>::operator=(const SparseMatrix<DataType>& other)
{
	if (this == &other) {
		return *this;  // ���Ҹ�ֵ����
	}

	// �����ǰ���������
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

	// ��ʼ���µľ���ṹ
	this->NumRow = other.NumRow;
	this->NumCol = other.NumCol;

	RowHead = new SeqList<Node<DataType>*>(NumRow);
	ColHead = new SeqList<Node<DataType>*>(NumCol);

	// ���� other ���������
	for (int row = 0; row < NumRow; row++) {
		Node<DataType>* other_p = other.RowHead.Get(row);
		Node<DataType>* prev = nullptr;
		while (other_p != NULL) {
			// ���ƽڵ�
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
		throw"�������Ͳ�ƥ�䣬�޷�����";
	SparseMatrix<DataType> result(this->NumRow, this->NumCol);
	Node<DataType>* sp, * op;
	for (int row = 0; row < NumRow; row++) {
		sp = this->RowHead.Get(row);
		op = other.GetIndexRowHead(row);
		while (sp != NULL || op != NULL) {
			if (sp == NULL) {
				result.InsertNewNode(op->data.row, op->data.col, op->data.value);  // ֻ���� op
				op = op->right;
			}
			else if (op == NULL) {
				result.InsertNewNode(sp->data.row, sp->data.col, sp->data.value);  // ֻ���� sp
				sp = sp->right;
			}
			else if (sp->data.col < op->data.col) {
				result.InsertNewNode(sp->data.row, sp->data.col, sp->data.value);  // sp �Ȳ���
				sp = sp->right;
			}
			else if (sp->data.col > op->data.col) {
				result.InsertNewNode(op->data.row, op->data.col, op->data.value);  // op �Ȳ���
				op = op->right;
			}
			else {
				DataType sum = sp->data.value + op->data.value;
				if (sum != 0) {
					result.InsertNewNode(sp->data.row, sp->data.col, sum);  // ֻ�������ֵ
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
		throw"�������Ͳ�ƥ�䣬�޷�����";
	SparseMatrix<DataType> result(this->NumRow, this->NumCol);
	Node<DataType>* sp, * op;
	for (int row = 0; row < NumRow; row++) {
		sp = this->RowHead.Get(row);
		op = other.GetIndexRowHead(row);
		while (sp != NULL || op != NULL) {
			if (sp == NULL) {
				result.InsertNewNode(op->data.row, op->data.col, -op->data.value);  // ֻ���� op��ȡ��
				op = op->right;
			}
			else if (op == NULL) {
				result.InsertNewNode(sp->data.row, sp->data.col, sp->data.value);  // ֻ���� sp
				sp = sp->right;
			}
			else if (sp->data.col < op->data.col) {
				result.InsertNewNode(sp->data.row, sp->data.col, sp->data.value);  // sp �Ȳ���
				sp = sp->right;
			}
			else if (sp->data.col > op->data.col) {
				result.InsertNewNode(op->data.row, op->data.col, -op->data.value);  // op �Ȳ��룬ȡ��
				op = op->right;
			}
			else {
				DataType diff = sp->data.value - op->data.value;
				if (diff != 0) {
					result.InsertNewNode(sp->data.row, sp->data.col, diff);  // ֻ�������ֵ
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
	if (Get(row, col) != 0) {//�����Ż�Ϊһ�α���
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
	if (!have)cout << "�þ���ȫ��Ϊ�գ��޷�0ֵ\n";
}

template<class DataType>
DataType SparseMatrix<DataType>::Get(int row, int col)
{
	if (row < 0 || row >= NumRow || col < 0 || col >= NumCol)throw"λ�÷Ƿ�";
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
		throw"����";
	Node<DataType>* p = new Node<DataType>;
	p->data.row = row;
	p->data.col = col;
	p->data.value = value;
	p->down = NULL;
	p->right = NULL;

	Node<DataType>* currRowPoint = RowHead.Get(row);
	while (currRowPoint->right != NULL && currRowPoint->right->data.col < col) // ��������� NULL
		currRowPoint = currRowPoint->right;
	p->right = currRowPoint->right;
	currRowPoint->right = p;

	Node<DataType>* currColPoint = ColHead.Get(col);
	while (currColPoint->down != NULL && currColPoint->down->data.row < row) // ��������� NULL
		currColPoint = currColPoint->down;
	p->down = currColPoint->down;
	currColPoint->down = p;
}