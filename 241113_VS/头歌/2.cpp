#include "bst.h"   // 引用库函数文件
#include <algorithm>
namespace exa {     //请在命名空间内编写代码，否则后果自负

bst solve(vector<int> a) {
 bst root=new bnode;
 sort(a.begin(),a.end());
 root->data=a[0];
 for(int i=1;i<a.size();i++){
     insert_bst(root,a[i]);
 }
 return root;
}

}
