#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class DataType>
struct Triple {
    int row, col;  // Ԫ�ص�λ��
    DataType value;  // Ԫ�ص�ֵ
};

template <class DataType>
class SparseMatrix {
public:
    SparseMatrix(int rows, int cols);
    SparseMatrix<DataType> operator+(const SparseMatrix<DataType>& other);
    void Change(int row, int col, DataType value);
    void ShowElements() const;

private:
    int NumRow, NumCol;  // ���������������
    vector<Triple<DataType>> elements;  // ���ڴ洢����Ԫ�ص���Ԫ��
};

// ���캯��
template <class DataType>
SparseMatrix<DataType>::SparseMatrix(int rows, int cols) : NumRow(rows), NumCol(cols) {}

// �޸ľ����е�ֵ
template <class DataType>
void SparseMatrix<DataType>::Change(int row, int col, DataType value) {
    // �����ֵΪ0��ɾ�����е�ֵ
    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (it->row == row && it->col == col) {
            if (value == 0) {
                elements.erase(it);  // ɾ����ֵ
            }
            else {
                it->value = value;  // �������еķ���ֵ
            }
            return;
        }
    }

    // ������ֵ
    if (value != 0) {
        Triple<DataType> t = { row, col, value };
        elements.push_back(t);
    }
}

// չʾ�����еķ���Ԫ��
template <class DataType>
void SparseMatrix<DataType>::ShowElements() const {
    if (elements.empty()) {
        cout << "Matrix has no non-zero elements." << endl;
        return;
    }

    cout << "Row\tCol\tValue" << endl;
    for (const auto& e : elements) {
        cout << e.row << "\t" << e.col << "\t" << e.value << endl;
    }
}

// ���� + �������ִ�о���ӷ�
template <class DataType>
SparseMatrix<DataType> SparseMatrix<DataType>::operator+(const SparseMatrix<DataType>& other) {
    if (this->NumRow != other.NumRow || this->NumCol != other.NumCol) {
        throw "�����С��ƥ�䣬�޷�ִ�мӷ�����";
    }

    SparseMatrix<DataType> result(this->NumRow, this->NumCol);

    // �Ȱѵ�ǰ�����е�Ԫ�ز���
    for (const auto& e : this->elements) {
        result.Change(e.row, e.col, e.value);
    }

    // �ٰ���һ�������е�Ԫ�ز��루��ͬλ������ӣ�
    for (const auto& e : other.elements) {
        DataType existingValue = 0;

        // �����Ƿ�����ֵ
        for (const auto& r : result.elements) {
            if (r.row == e.row && r.col == e.col) {
                existingValue = r.value;
                break;
            }
        }

        result.Change(e.row, e.col, existingValue + e.value);
    }

    return result;
}
