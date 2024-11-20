#include "bst.h"   // 引用库函数文件

using namespace std;

namespace exa { //请在命名空间内编写代码，否则后果自负

  int solve(vector < int > a, int x) {
    int left = 0;
    int right = a.size() - 1;
    int result = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (a[mid] >= x) {
        result = a[mid];
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return result;
  }

}
