#include <iostream>
#include "Matrix.h"

int main() {
    SparseMatrix<int> matrix1(3, 3);
    SparseMatrix<int> matrix2(3, 3);

    matrix1.Change(2, 1, 3);
    matrix1.Change(1, 2, 6);

    matrix2.Change(1, 1, 4);
    matrix2.Change(2, 2, 2);
    matrix2.Change(2, 1, 1);

    SparseMatrix<int> matrix3 = matrix1 + matrix2;

    matrix3.ShowElements();

    return 0;
}
