#pragma once
#include <iostream>
using namespace std;
/*
	创建时间：2024/10/15
	内容：创建二叉树类
*/

struct BinaryNode {
	char data;
	BinaryNode* lchild, * rchild;
};


class BinaryTree {
public:
	BinaryTree() { root = Creat(root); }//无参构造函数
	~BinaryTree() { Release(root); }//析构函数
	void PreOrder() { PreOrder(root); }//前序遍历
	void InOrder() { InOrder(root); }//中序遍历
	void PostOrder() { PostOrder(root); }//后序遍历
	void ShowSingleChildNodes() { SingleChildNodes(root); }//展示单孩子节点
	void Mirror() { Mirror(root); }//镜像二叉树
	void GetHeight() { cout<<GetHeight(root); }//获取二叉树高度（深度）
private:
	BinaryNode* root;
	BinaryNode* Creat(BinaryNode* bt);
	void Release(BinaryNode* bt);
	void PreOrder(BinaryNode* bt);
	void InOrder(BinaryNode* bt);
	void PostOrder(BinaryNode* bt);
	void SingleChildNodes(BinaryNode* bt);
	void Mirror(BinaryNode* bt);
	int GetHeight(BinaryNode* bt);
};

BinaryNode* BinaryTree::Creat(BinaryNode* bt)
{
	//采用前序序列输入二叉树，#代表该结点无数据，即为空
	char ch;
	cout << "请输入一颗二叉树的结点数据" << endl;
	cin >> ch;
	if (ch == '#')return NULL;
	else {
		bt = new BinaryNode;
		//前序序列实现部分
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}

void BinaryTree::Release(BinaryNode* bt)
{
	//采用后序序列遍历删除各个节点
	if (bt != NULL) {
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

void BinaryTree::PreOrder(BinaryNode* bt)//前序遍历
{
	if (bt == NULL)return;
	else {
		cout << bt->data << " ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void BinaryTree::InOrder(BinaryNode* bt)//中序遍历
{
	if (bt == NULL)return;
	else {
		InOrder(bt->lchild);
		cout << bt->data << " ";
		InOrder(bt->rchild);
	}
}

void BinaryTree::PostOrder(BinaryNode* bt)//后序遍历
{
	if (bt == NULL)return;
	else {
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data << " ";
	}
}

void BinaryTree::SingleChildNodes(BinaryNode* bt)//输出单孩子节点的节点数据
{
	if (bt == NULL)return;
	if (bt->lchild == NULL && bt->rchild != NULL ||
		bt->rchild == NULL && bt->lchild != NULL) {
		cout << bt->data << " ";
	}
	SingleChildNodes(bt->lchild);
	SingleChildNodes(bt->rchild);
}

void BinaryTree::Mirror(BinaryNode* bt)//镜像二叉树
{
	if (bt == NULL)return;
	else {
		swap(bt->rchild, bt->lchild);
		Mirror(bt->rchild);
		Mirror(bt->lchild);
	}
}

int BinaryTree::GetHeight(BinaryNode* bt)//获取二叉树高度（深度）
{
	if (bt == NULL)return 0;
	else {
		int lheight = GetHeight(bt->lchild);
		int rheight = GetHeight(bt->rchild);
		return max(lheight, rheight) + 1;
	}
	throw"获取高度时产生未知错误\n";
	return 0;
}