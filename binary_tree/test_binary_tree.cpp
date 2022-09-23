#include "binary_tree.h"

int main() {
	using namespace std;

	cout << "hello" << endl;

	BinaryTree<int>* b1 = new BinaryTree<int>();
	cout << b1->size() << endl;
	delete b1;

	char arr[21] = { 'a', 'b', 'd', 'h', '#', '#', 'i', '#', '#', 'e', '#', '#', 'c', 'f', '#', 'j', '#', '#', 'g', '#', '#' };

	BinaryTree<char>* b2 = new BinaryTree<char>(arr, 19, '#');

	vector<char> pre_vec; //先序遍历序列
	vector<char> in_vec; //中序遍历序列
	vector<char> post_vec; //后序遍历序列
	vector<char> level_vec; //层序遍历序列

	cout << "二叉树b2的高度为：" << b2->height() << endl;

	b2->preOrder(pre_vec);
	cout << "二叉树b2的先序遍历结果为：";
	for (char ch : pre_vec) {
		cout << ch << " ";
	}
	cout << endl;

	b2->inOrder(in_vec);
	cout << "二叉树b2的中序遍历结果为：";
	for (char ch : in_vec) {
		cout << ch << " ";
	}
	cout << endl;

	b2->postOrder(post_vec);
	cout << "二叉树b2的后序遍历结果为：";
	for (char ch : post_vec) {
		cout << ch << " ";
	}
	cout << endl;

	b2->levelOrder(level_vec);
	cout << "二叉树b2的后序遍历结果为：";
	for (char ch : level_vec) {
		cout << ch << " ";
	}
	cout << endl;
	delete b2;

	system("pause");
	return 0;
}
