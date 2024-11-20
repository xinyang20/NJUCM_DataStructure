#include "bst.h"   // 引用库函数文件

namespace exa { //请在命名空间内编写代码，否则后果自负

  bool solve(bst t, int x) {
    if (t  == NULL) return false;
    if (t -> data == x) return true;
    if (t -> data > x) return solve(t -> lchild, x);
    if (t -> data < x) return solve(t -> rchild, x);
  }

}
