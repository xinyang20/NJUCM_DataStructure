#pragma once
#include <iostream>
using namespace std;
/*
	����ʱ�䣺2024/10/15
	���ݣ�������������
*/

struct BinaryNode {
	char data;
	BinaryNode* lchild, * rchild;
};


class BinaryTree {
public:
	BinaryTree() { root = Creat(root); }//�޲ι��캯��
	~BinaryTree() { Release(root); }//��������
	void PreOrder() { PreOrder(root); }//ǰ�����
	void InOrder() { InOrder(root); }//�������
	void PostOrder() { PostOrder(root); }//�������
	void ShowSingleChildNodes() { SingleChildNodes(root); }//չʾ�����ӽڵ�
	void Mirror() { Mirror(root); }//���������
	void GetHeight() { cout<<GetHeight(root); }//��ȡ�������߶ȣ���ȣ�
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
	//����ǰ�����������������#����ý�������ݣ���Ϊ��
	char ch;
	cout << "������һ�Ŷ������Ľ������" << endl;
	cin >> ch;
	if (ch == '#')return NULL;
	else {
		bt = new BinaryNode;
		//ǰ������ʵ�ֲ���
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}

void BinaryTree::Release(BinaryNode* bt)
{
	//���ú������б���ɾ�������ڵ�
	if (bt != NULL) {
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

void BinaryTree::PreOrder(BinaryNode* bt)//ǰ�����
{
	if (bt == NULL)return;
	else {
		cout << bt->data << " ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void BinaryTree::InOrder(BinaryNode* bt)//�������
{
	if (bt == NULL)return;
	else {
		InOrder(bt->lchild);
		cout << bt->data << " ";
		InOrder(bt->rchild);
	}
}

void BinaryTree::PostOrder(BinaryNode* bt)//�������
{
	if (bt == NULL)return;
	else {
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data << " ";
	}
}

void BinaryTree::SingleChildNodes(BinaryNode* bt)//��������ӽڵ�Ľڵ�����
{
	if (bt == NULL)return;
	if (bt->lchild == NULL && bt->rchild != NULL ||
		bt->rchild == NULL && bt->lchild != NULL) {
		cout << bt->data << " ";
	}
	SingleChildNodes(bt->lchild);
	SingleChildNodes(bt->rchild);
}

void BinaryTree::Mirror(BinaryNode* bt)//���������
{
	if (bt == NULL)return;
	else {
		swap(bt->rchild, bt->lchild);
		Mirror(bt->rchild);
		Mirror(bt->lchild);
	}
}

int BinaryTree::GetHeight(BinaryNode* bt)//��ȡ�������߶ȣ���ȣ�
{
	if (bt == NULL)return 0;
	else {
		int lheight = GetHeight(bt->lchild);
		int rheight = GetHeight(bt->rchild);
		return max(lheight, rheight) + 1;
	}
	throw"��ȡ�߶�ʱ����δ֪����\n";
	return 0;
}