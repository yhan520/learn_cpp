#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <stack>
#include <vector>
#include <iostream>
#include <deque>
using std::stack;
using std::vector;
using std::deque;

template<typename T>
struct node {
	node* lchild;
	node* rchild;
	T data;
};

template<typename T>
class BinaryTree
{
private:
	node<T>* root;
	T m_end;
	size_t m_size;
	static node<T>* copy(node<T>* oldtree);
	static void delete_node(node<T>* oldtree);
public:
	BinaryTree();
	BinaryTree(T* arr, size_t size, const T& invalid); //按照先序序列建立二叉树
	BinaryTree(const BinaryTree<T>& t1);//复制构造函数
	~BinaryTree();

	BinaryTree<T>& operator=(const BinaryTree<T>& t1); //重载=

	size_t size(); //返回二叉树节点的个数
	size_t height(); //返回二叉树的高度

	//先序遍历二叉树，并将结果保存到参数中，非递归法
	void preOrder(T* arr, size_t size);
	void preOrder(vector<T>& vec);

	//中序遍历二叉树，并将结果保存到参数中，非递归法
	void inOrder(T* arr, size_t size);
	void inOrder(vector<T>& vec);

	//后序遍历二叉树，并将结果保存知道参数中，非递归法
	void postOrder(T* arr, size_t size);
	void postOrder(vector<T>& vec);

	//层序遍历二叉树，并将结果保存到参数中
	void levelOrder(T* arr, size_t size);
	void levelOrder(vector<T>& vec);
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	root = new node<T>;
	root->data = NULL;
	root->lchild = nullptr;
	root->rchild = nullptr;
	m_size = 0;
}

template<typename T>
size_t BinaryTree<T>::size() {
	return this->m_size;
}

template<typename T>
inline size_t BinaryTree<T>::height() {
	node<T>* p_node = this->root;
	size_t index = 0;
	struct record {
		node<T>* t_node;
		int flag;
	};
	stack<record> s;
	size_t max_level = 0;

	while (p_node != nullptr || !s.empty()) {
		while (p_node != nullptr) {
			s.push({ p_node, 1 });
			max_level = max_level > s.size() ? max_level : s.size();
			p_node = p_node->lchild;
		}
		while (!s.empty() && (s.top()).flag == 2) {
			s.pop();
		}
		if (!s.empty()) {
			(s.top()).flag = 2;
			p_node = ((s.top()).t_node)->rchild;
		}
	}

	return max_level;
}

template<typename T>
BinaryTree<T>::BinaryTree(T* arr, size_t size, const T& invalid) {
	node<T>* new_node = nullptr;
	node<T>* p_node = nullptr;
	stack<node<T>*> s;
	size_t index = 0;

	while (index < size) {
		while (index < size && arr[index] != invalid) {
			if (index == 0) {
				root = new node<T>;
				root->data = arr[index++];
				root->lchild = nullptr;
				root->rchild = nullptr;
				m_size = 1;
				p_node = root;
			}
			else {
				new_node = new node<T>;
				new_node->data = arr[index++];
				new_node->lchild = nullptr;
				new_node->rchild = nullptr;
				m_size++;

				p_node->lchild = new_node;
				p_node = new_node;
			}
			s.push(p_node);
		}
		index++;
		node<T>* top = s.top();
		s.pop();
		if (index < size && arr[index] != invalid) {
			p_node = top;

			new_node = new node<T>;
			new_node->data = arr[index++];
			new_node->lchild = nullptr;
			new_node->rchild = nullptr;
			m_size++;

			p_node->rchild = new_node;
			p_node = new_node;
			s.push(p_node);
		}
	}
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& t1)
{
	this->root = copy(t1.root);
}

template<typename T>
inline BinaryTree<T>::~BinaryTree() {
	node<T>* p_node = this->root;
	size_t index = 0;
	struct record {
		node<T>* t_node;
		int flag;
	};
	stack<record> s;

	while (p_node != nullptr || !s.empty()) {
		while (p_node != nullptr) {
			s.push({ p_node, 1 });
			p_node = p_node->lchild;
		}
		while (!s.empty() && (s.top()).flag == 2) {
			delete((s.top()).t_node);
			//index++;
			s.pop();
		}
		if (!s.empty()) {
			(s.top()).flag = 2;
			p_node = ((s.top()).t_node)->rchild;
		}
	}
	//std::cout << index;
}

template<typename T>
inline BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& t1)
{
	if (this == &t1) {
		return *this;
	}
	if (this->root != nullptr) {
		delete_node(root);
	}
	this->root = copy(t1.root);
	return *this;
}

template<typename T>
inline node<T>* BinaryTree<T>::copy(node<T>* oldtree)
{
	node<T>* temp;
	if (oldtree != nullptr) {
		temp = new node<T>;
		temp->data = oldtree->data;
		temp->lchild = copy(oldtree->lchild);
		temp->rchild = copy(oldtree->rchild);
		return temp;
	}
	return nullptr;
}

template<typename T>
inline void BinaryTree<T>::delete_node(node<T>* oldtree)
{
	if (oldtree == nullptr)
		return;
	delete_node(oldtree->lchild);
	delete_node(oldtree->rchild);
	delete oldtree;
}

template<typename T>
void BinaryTree<T>::preOrder(T* arr, size_t size) {
	stack<node<T>*> s;
	node<T>* p_node = this->root;
	size_t index = 0;
	while (p_node != nullptr || !s.empty()) {
		while (p_node != nullptr) {
			*(arr + (index++)) = p_node->data;
			s.push(p_node);
			p_node = p_node->lchild;
		}
		if (!s.empty()) {
			p_node = s.top();
			p_node = p_node->rchild;
			s.pop();
		}
	}
}

template<typename T>
void BinaryTree<T>::preOrder(vector<T>& vec) {
	stack<node<T>*> s;
	node<T>* p_node = this->root;
	while (p_node != nullptr || !s.empty()) {
		while (p_node != nullptr) {
			vec.push_back(p_node->data);
			s.push(p_node);
			p_node = p_node->lchild;
		}
		if (!s.empty()) {
			p_node = s.top();
			p_node = p_node->rchild;
			s.pop();
		}
	}
}

template<typename T>
void BinaryTree<T>::inOrder(T* arr, size_t size) {
	stack<node<T>*> s;
	node<T>* p_node = this->root;
	size_t index = 0;
	while (p_node != nullptr || !s.empty()) {
		while (p_node != nullptr) {
			s.push(p_node);
			p_node = p_node->lchild;
		}
		if (!s.empty()) {
			p_node = s.top();
			s.pop();
			*(arr + (index++)) = p_node->data;
			p_node = p_node->rchild;
		}
	}
}

template<typename T>
void BinaryTree<T>::inOrder(vector<T>& vec) {
	stack<node<T>*> s;
	node<T>* p_node = this->root;
	while (p_node != nullptr || !s.empty()) {
		while (p_node != nullptr) {
			s.push(p_node);
			p_node = p_node->lchild;
		}
		if (!s.empty()) {
			p_node = s.top();
			s.pop();
			vec.push_back(p_node->data);
			p_node = p_node->rchild;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::postOrder(T* arr, size_t size) {

	node<T>* p_node = this->root;
	size_t index = 0;
	struct record {
		node<T>* t_node;
		int flag;
	};
	stack<record> s;

	while (p_node != nullptr || !s.empty()) {
		while (p_node != nullptr) {
			s.push({ p_node, 1 });
			p_node = p_node->lchild;
		}
		while (!s.empty() && (s.top()).flag == 2) {
			*(arr + (index++)) = (s.top()).t_node->data;
			s.pop();
		}
		if (!s.empty()) {
			(s.top()).flag = 2;
			p_node = ((s.top()).t_node)->rchild;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::postOrder(vector<T>& vec)
{
	node<T>* p_node = this->root;
	struct record {
		node<T>* t_node;
		int flag;
	};
	stack<record> s;

	while (p_node != nullptr || !s.empty()) {
		while (p_node != nullptr) {
			s.push({ p_node, 1 });
			p_node = p_node->lchild;
		}

		while (!s.empty() && (s.top()).flag == 2) {
			vec.push_back((s.top()).t_node->data);
			s.pop();
		}
		if (!s.empty()) {
			(s.top()).flag = 2;
			p_node = ((s.top()).t_node)->rchild;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::levelOrder(T* arr, size_t size) {
	deque<node<T>*> d;
	int index = 0;
	node<T>* p_node = this->root;
	if (p_node != nullptr) {
		d.push_back(p_node);
	}
	while (!d.empty()) {
		p_node = d.front();
		d.pop_front();
		*(arr + (index++)) = p_node->data;
		if (p_node->lchild != nullptr)
			d.push_back(p_node->lchild);
		if (p_node->rchild != nullptr)
			d.push_back(p_node->rchild);
	}
}

template<typename T>
inline void BinaryTree<T>::levelOrder(vector<T>& vec) {
	deque<node<T>*> d;
	node<T>* p_node = this->root;
	if (p_node != nullptr) {
		d.push_back(p_node);
	}
	while (!d.empty()) {
		p_node = d.front();
		d.pop_front();
		vec.push_back(p_node->data);
		if (p_node->lchild != nullptr)
			d.push_back(p_node->lchild);
		if (p_node->rchild != nullptr)
			d.push_back(p_node->rchild);
	}
}

#endif




