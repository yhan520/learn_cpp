#ifndef _MYLIST_H_
#define _MYLIST_H_
#include <iostream>

using std::cout;
using std::endl;

template<typename T1>
struct ListNode {
	T1 val;
	ListNode* next;
};

template<typename T>
class MyList {
private:
	ListNode<T>* list;
	//int num;
public:
    int num;
	MyList();
	MyList(T* nums, int len);
	MyList(MyList<T>& l);
	~MyList();

	void show();

};

template<typename T>
MyList<T>::MyList() {
    list = new ListNode<T>;
    list->val = 0;
    list->next = nullptr;

    num = 0;
}

template<typename T>
MyList<T>::MyList(T* nums, int len) {
    list = new ListNode<T>;
    list->val = 0;
    list->next = nullptr;
    ListNode<T>* current = list;
    num = 0;
    for (int i = 0; i < len; i++) {
        num++;
        ListNode<T>* l = new ListNode<T>;
        l->val = nums[i];
        l->next = nullptr;
        current->next = l;
        current = l;
    }
}

template<typename T>
MyList<T>::MyList(MyList<T>& l) {

    list = new ListNode<T>;
    list->val = 0;
    list->next = nullptr;
    ListNode<T>* oldNode = l.list;
    ListNode<T>* current = list;

    while ((l.list)->next != nullptr) {
        ListNode<T>* newNode = new ListNode<T>;
        newNode->val = (l.list)->next->val;
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
        l.list = (l.list)->next;
    }
    l.list = oldNode;
    num = l.num;
}

template<typename T>
MyList<T>::~MyList() {
    ListNode<T>* l;
    while (list != nullptr) {
        l = list;
        list = list->next;
        delete l;
    }
}

template<typename T>
void MyList<T>::show() {
    ListNode<T>* l = list;
    cout << '[';
    if (l->next != nullptr) {
        cout << l->next->val;
        l = l->next;
    }
    while (l->next != nullptr) {
        cout << ", " << l->next->val;
        l = l->next;
    }
    cout << "]\n";
}
#endif // !_MYLIST_H_

