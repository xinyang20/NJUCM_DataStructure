//#include <iostream>
//#include <string>
//
//struct Node {
//	int data;
//	Node* rchild, * lchild;
//};
//
//class BST {
//public:
//	BST();
//	void operate(std::string input, int value);
//	void PreRoot() { PreRoot(root); }
//	void MidRoot() { MidRoot(root); }
//private:
//	Node* root;
//	Node* Search(Node* root, int value);
//	Node* Insert(Node* root, int value);
//	Node* FindParent(Node* root, int value);
//	//void Remove(Node* root, int value);
//	void Remove(Node* p, Node* f);
//	//void PreRoot(Node* root, bool IsFirst = false);
//	//void MidRoot(Node* root, bool IsFirst = false);
//	void PreRoot(Node* root);
//	void MidRoot(Node* root);
//};
//
//BST::BST() {
//	root = nullptr;
//}
//
//void BST::operate(std::string input, int value)
//{
//	if (input == "Insert") {
//		Insert(root, value);
//	}
//	else if (input == "Remove")
//		Remove(Search(root, value), FindParent(root, value));
//}
//
////Node* BST::Search(Node* root, int value)
////{
////	if (root == nullptr)return nullptr;
////	else if (root->data == value)return root;
////	if (root->data > value)
////		Search(root->lchild, value);
////	else if (root->data < value)
////		Search(root->rchild, value);
////}
//Node* BST::Search(Node* root, int value) {
//	if (root == nullptr) return nullptr;
//	if (root->data == value) return root;
//	if (root->data > value)
//		return Search(root->lchild, value);  // 添加返回值
//	else
//		return Search(root->rchild, value);  // 添加返回值
//}
//
//
//Node* BST::Insert(Node* root, int value)
//{
//	if (root == nullptr) {
//		root = new Node;
//		root->data = value;
//		root->lchild = nullptr;
//		root->rchild = nullptr;
//		return root;
//	}
//	if (root->data > value)
//		root->lchild = Insert(root->lchild, value);
//	else if (root->data < value)
//		root->rchild = Insert(root->rchild, value);
//	return root;
//}
//
////Node* BST::FindParent(Node* root, int value)
////{
////	if (root == nullptr)
////		return nullptr;
////	if (root->lchild->data == value || root->rchild->data == value)
////		return root;
////}
//Node* BST::FindParent(Node* root, int value) {
//	if (root == nullptr || (root->lchild == nullptr && root->rchild == nullptr))
//		return nullptr;
//	if ((root->lchild && root->lchild->data == value) || (root->rchild && root->rchild->data == value))
//		return root;
//	if (root->data > value)
//		return FindParent(root->lchild, value);
//	else
//		return FindParent(root->rchild, value);
//}
//
//
////void BST::Remove(Node* p, Node* f)
////{
////	if (p->lchild == nullptr && p->rchild == nullptr) {
////		f->lchild = nullptr;
////		delete p;
////		return;
////	}
////	if (p->rchild == nullptr) {
////		f->lchild = p->lchild;
////		delete p;
////		return;
////	}
////	if (p->lchild == nullptr) {
////		f->lchild = p->rchild;
////		delete p;
////		return;
////	}
////	Node* par = p, * s = p->rchild;
////	while (s->lchild != nullptr) {
////		par = s;
////		s = s->lchild;
////	}
////	p->data = s->data;
////	if (par == p)par->rchild = s->rchild;
////	else par->lchild = s->rchild;
////	delete s;
////}
//void BST::Remove(Node* p, Node* f) {
//	if (p->lchild == nullptr && p->rchild == nullptr) {
//		if (f->lchild == p)
//			f->lchild = nullptr;
//		else
//			f->rchild = nullptr;
//		delete p;
//		return;
//	}
//	if (p->rchild == nullptr) {
//		if (f->lchild == p)
//			f->lchild = p->lchild;
//		else
//			f->rchild = p->lchild;
//		delete p;
//		return;
//	}
//	if (p->lchild == nullptr) {
//		if (f->lchild == p)
//			f->lchild = p->rchild;
//		else
//			f->rchild = p->rchild;
//		delete p;
//		return;
//	}
//	Node* par = p, * s = p->rchild;
//	while (s->lchild != nullptr) {
//		par = s;
//		s = s->lchild;
//	}
//	p->data = s->data;
//	if (par == p)
//		par->rchild = s->rchild;
//	else
//		par->lchild = s->rchild;
//	delete s;
//}
//
//
////void BST::PreRoot(Node* root, bool IsFirst)
////{
////	if (root == nullptr)
////		return;
////	if (!IsFirst)
////		std::cout << " ";
////	std::cout << root->data;
////	PreRoot(root->lchild);
////	PreRoot(root->rchild);
////}
////
////void BST::MidRoot(Node* root, bool IsFirst)
////{
////	if (root == nullptr)
////		return;
////	if (!IsFirst)
////		std::cout << " ";
////	MidRoot(root->lchild);
////	std::cout << root->data;
////	MidRoot(root->rchild);
////}
//void BST::PreRoot(Node* root) {
//	if (root == nullptr)
//		return;
//	std::cout << root->data << " ";
//	PreRoot(root->lchild);
//	PreRoot(root->rchild);
//}
//
//void BST::MidRoot(Node* root) {
//	if (root == nullptr)
//		return;
//	MidRoot(root->lchild);
//	std::cout << root->data << " ";
//	MidRoot(root->rchild);
//}
//
//
////void BST::Remove(Node* root, int value)
////{
////	if (root == nullptr) {
////		std::cout << "删除值不存在，不可删除\n";
////		return;
////	}
////	Node* p;
////	if (root->data == value && root->rchild == nullptr && root->lchild == nullptr) {
////		p = root;
////
////	}
////
////}
//
//int main() {
//	int n;
//	std::cin >> n;
//	std::string op;
//	int value;
//	BST t;
//	for (int i = 0; i < n-2; i++) {
//		std::cin >> op >> value;
//		std::cout << "操作：" << op << "\t数值：" << value << '\n';
//		t.operate(op, value);
//	}
//	std::cout << "\n------------先根序列--------------\n";
//	t.PreRoot();
//	std::cout << "\n------------中根序列--------------\n";
//	t.MidRoot();
//	std::cout << "\n";
//	return 0;
//}

#include <iostream>
#include <string>

struct Node {
	int data;
	Node* rchild;
	Node* lchild;
	Node(int value = 0) {
		data = value;
		rchild = nullptr; 
		lchild = nullptr;
	}
};

class BST {
public:
	BST();
	void operate(std::string input, int value);
	void PreRoot() { PreRoot(root->lchild); }
	void MidRoot() { MidRoot(root->lchild); }
private:
	Node* root;
	Node* Search(Node* root, int value);
	Node* Insert(Node* root, int value);
	Node* FindParent(Node* root, int value);
	void Remove(Node* p, Node* f);
	void PreRoot(Node* root);
	void MidRoot(Node* root);
};

BST::BST() {
	root = new Node();
}

void BST::operate(std::string input, int value) {
	if (input == "Insert") {
		root->lchild = Insert(root->lchild, value);
	}
	else if (input == "Remove") {
		Node* remove = Search(root->lchild, value);
		Node* parent = (remove == root->lchild) ? root : FindParent(root->lchild, value);
		if (remove != nullptr && parent != nullptr) {
			Remove(remove, parent);
		}
		else {
			std::cout << "删除值不存在，不可删除\n";
		}
	}
}

Node* BST::Search(Node* root, int value) {
	if (root == nullptr) return nullptr;
	if (root->data == value) return root;
	if (root->data > value)
		return Search(root->lchild, value);
	else
		return Search(root->rchild, value);
}

Node* BST::Insert(Node* root, int value) {
	if (root == nullptr) {
		return new Node(value);
	}
	if (root->data > value)
		root->lchild = Insert(root->lchild, value);
	else if (root->data < value)
		root->rchild = Insert(root->rchild, value);
	return root;
}

Node* BST::FindParent(Node* root, int value) {
	if (root == nullptr || (root->lchild == nullptr && root->rchild == nullptr))
		return nullptr;
	if ((root->lchild && root->lchild->data == value) || 
		(root->rchild && root->rchild->data == value))
		return root;
	if (root->data > value)
		return FindParent(root->lchild, value);
	else
		return FindParent(root->rchild, value);
}

void BST::Remove(Node* p, Node* f) {
	if (p->lchild == nullptr && p->rchild == nullptr) {
		if (f->lchild == p)
			f->lchild = nullptr;
		else
			f->rchild = nullptr;
		delete p;
		return;
	}
	if (p->rchild == nullptr) {
		if (f->lchild == p)
			f->lchild = p->lchild;
		else
			f->rchild = p->lchild;
		delete p;
		return;
	}
	if (p->lchild == nullptr) {
		if (f->lchild == p)
			f->lchild = p->rchild;
		else
			f->rchild = p->rchild;
		delete p;
		return;
	}
	Node* par = p, * s = p->rchild;
	while (s->lchild != nullptr) {
		par = s;
		s = s->lchild;
	}
	p->data = s->data;
	if (par == p)
		par->rchild = s->rchild;
	else
		par->lchild = s->rchild;
	delete s;
}

void BST::PreRoot(Node* root) {
	if (root == nullptr)
		return;
	std::cout << root->data << " ";
	PreRoot(root->lchild);
	PreRoot(root->rchild);
}

void BST::MidRoot(Node* root) {
	if (root == nullptr)
		return;
	MidRoot(root->lchild);
	std::cout << root->data << " ";
	MidRoot(root->rchild);
}

int main() {
	int n;
	std::cin >> n;
	std::string op;
	int value;
	BST t;
	for (int i = 0; i < n; i++) {
		std::cin >> op >> value;
		//std::cout << "操作：" << op << "\t数值：" << value << '\n';
		t.operate(op, value);
	}
	//std::cout << "\n------------先根序列--------------\n";
	t.MidRoot();
	std::cout << "\n\n";
	//std::cout << "\n------------中根序列--------------\n";
	t.PreRoot();
	//std::cout << "\n";
	return 0;
}
