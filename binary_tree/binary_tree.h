#pragma once

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
public:
	BinaryTree();
	BinaryTree(T* arr, int num,T end);

};

template<typename T>
BinaryTree<T>::BinaryTree() {
	root = new node<T>;
	root->data = nullptr;
	root->lchild = nullptr;
	root->rchild = nullptr;
}

template<typename T>
BinaryTree<T>::BinaryTree(T* arr, int num, T end) {
	int i, j;
	T data;

	root->data = 

}

