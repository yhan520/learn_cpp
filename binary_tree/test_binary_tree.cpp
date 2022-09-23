#include "binary_tree.hpp"

int main() {
	using namespace std;

	cout << "hello" << endl;

	BinaryTree<int>* b1 = new BinaryTree<int>();
	cout << b1->size() << endl;
	delete b1;

	char arr[21] = { 'a', 'b', 'd', 'h', '#', '#', 'i', '#', '#', 'e', '#', '#', 'c', 'f', '#', 'j', '#', '#', 'g', '#', '#' };

	BinaryTree<char>* b2 = new BinaryTree<char>(arr, 19, '#');

	vector<char> pre_vec; //�����������
	vector<char> in_vec; //�����������
	vector<char> post_vec; //�����������
	vector<char> level_vec; //�����������

	cout << "������b2�ĸ߶�Ϊ��" << b2->height() << endl;

	b2->preOrder(pre_vec);
	cout << "������b2������������Ϊ��";
	for (char ch : pre_vec) {
		cout << ch << " ";
	}
	cout << endl;

	b2->inOrder(in_vec);
	cout << "������b2������������Ϊ��";
	for (char ch : in_vec) {
		cout << ch << " ";
	}
	cout << endl;

	b2->postOrder(post_vec);
	cout << "������b2�ĺ���������Ϊ��";
	for (char ch : post_vec) {
		cout << ch << " ";
	}
	cout << endl;

	b2->levelOrder(level_vec);
	cout << "������b2�Ĳ���������Ϊ��";
	for (char ch : level_vec) {
		cout << ch << " ";
	}
	cout << endl;

	BinaryTree<char>* b3 = new BinaryTree<char>(*b2);
	vector<char> level_vec_3;
	b3->levelOrder(level_vec_3);
	cout << "������b3�Ĳ���������Ϊ��";
	for (char ch : level_vec_3) {
		cout << ch << " ";
	}
	cout << endl;

	BinaryTree<char>* b4 = new BinaryTree<char>;
	*b4 = *b3;
	vector<char> post_vec_4;
	b2->postOrder(post_vec_4);
	cout << "������b4�ĺ���������Ϊ��";
	for (char ch : post_vec_4) {
		cout << ch << " ";
	}
	cout << endl;

	delete b4;
	delete b3;
	delete b2;

	system("pause");
	return 0;
}
