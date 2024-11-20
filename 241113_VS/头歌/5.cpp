#include "bst.h"   // 引用库函数文件
namespace exa {     //请在命名空间内编写代码，否则后果自负

bst create(vector<int>& a, int start, int end) {
    if (start > end) return NULL;
    
    int mid = start + (end - start) / 2;
    bst node = (bst)malloc(sizeof(bnode));
    node->data = a[mid];
    node->lchild = create(a, start, mid - 1);
    node->rchild = create(a, mid + 1, end);
    
    return node;
}

bst solve(vector<int>& a) {
    return create(a, 0, a.size() - 1);
}
}
