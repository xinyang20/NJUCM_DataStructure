#include "bst.h"   // 引用库函数文件
namespace exa {     //请在命名空间内编写代码，否则后果自负

bst search(bst t, int x) {
    if (t == NULL) return NULL;
    if (t->data == x) return t;
    if (t->data > x) return search(t->lchild, x);
    return search(t->rchild, x);
}

bst searchParent(bst t, int x) {
    if (t == NULL || (t->lchild == NULL && t->rchild == NULL)) return NULL;
    if ((t->lchild != NULL && t->lchild->data == x) || (t->rchild != NULL && t->rchild->data == x)) return t;
    if (t->data > x) return searchParent(t->lchild, x);
    return searchParent(t->rchild, x);
}

void Remove(bst &p, bst &f) {
    if (p->lchild == nullptr && p->rchild == nullptr) {
        if (f == nullptr) {
            p = nullptr;
        } else if (f->lchild == p) {
            f->lchild = nullptr;
        } else {
            f->rchild = nullptr;
        }
        delete p;
        p = nullptr;
        return;
    }
    if (p->rchild == nullptr) {
        bst temp = p;
        if (f == nullptr) {
            p = p->lchild;
        } else if (f->lchild == p) {
            f->lchild = p->lchild;
        } else {
            f->rchild = p->lchild;
        }
        delete temp;
        return;
    }
    if (p->lchild == nullptr) {
        bst temp = p;
        if (f == nullptr) {
            p = p->rchild;
        } else if (f->lchild == p) {
            f->lchild = p->rchild;
        } else {
            f->rchild = p->rchild;
        }
        delete temp;
        return;
    }
    bst par = p, s = p->rchild;
    while (s->lchild != nullptr) {
        par = s;
        s = s->lchild;
    }
    p->data = s->data;
    if (par->lchild == s) {
        par->lchild = s->rchild;
    } else {
        par->rchild = s->rchild;
    }
    delete s;
}
void solve(bst & t, int x) {
    bst target = search(t, x);
    if(target==NULL)return;
    bst parent=searchParent(t,x);
    Remove(target,parent);
}
}
