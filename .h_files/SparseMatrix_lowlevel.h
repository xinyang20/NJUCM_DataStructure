#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class DataType>
struct Triple {
    int row, col;  // 元素的位置
    DataType value;  // 元素的值
};

template <class DataType>
class SparseMatrix {
public:
    SparseMatrix(int rows, int cols);
    SparseMatrix<DataType> operator+(const SparseMatrix<DataType>& other);
    void Change(int row, int col, DataType value);
    void ShowElements() const;

private:
    int NumRow, NumCol;  // 矩阵的行数和列数
    vector<Triple<DataType>> elements;  // 用于存储非零元素的三元组
};

// 构造函数
template <class DataType>
SparseMatrix<DataType>::SparseMatrix(int rows, int cols) : NumRow(rows), NumCol(cols) {}

// 修改矩阵中的值
template <class DataType>
void SparseMatrix<DataType>::Change(int row, int col, DataType value) {
    // 如果新值为0，删除已有的值
    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (it->row == row && it->col == col) {
            if (value == 0) {
                elements.erase(it);  // 删除零值
            }
            else {
                it->value = value;  // 更新已有的非零值
            }
            return;
        }
    }

    // 插入新值
    if (value != 0) {
        Triple<DataType> t = { row, col, value };
        elements.push_back(t);
    }
}

// 展示矩阵中的非零元素
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

// 重载 + 运算符，执行矩阵加法
template <class DataType>
SparseMatrix<DataType> SparseMatrix<DataType>::operator+(const SparseMatrix<DataType>& other) {
    if (this->NumRow != other.NumRow || this->NumCol != other.NumCol) {
        throw "矩阵大小不匹配，无法执行加法操作";
    }

    SparseMatrix<DataType> result(this->NumRow, this->NumCol);

    // 先把当前矩阵中的元素插入
    for (const auto& e : this->elements) {
        result.Change(e.row, e.col, e.value);
    }

    // 再把另一个矩阵中的元素插入（相同位置则相加）
    for (const auto& e : other.elements) {
        DataType existingValue = 0;

        // 查找是否已有值
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
