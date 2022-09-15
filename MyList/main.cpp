#include <iostream>
#include "MyList.hpp"
using namespace std;

int main() {

	int nums[3] = { 1,2,3 };

	MyList<int>* list1 = new MyList<int>();
	MyList<int>* list2 = new MyList<int>(nums, 3);
	MyList<int>* list3 = new MyList<int>(*list2);

	list1->show();
	list2->show();
	list3->show();

	cout << list1->num << endl;
	cout << list2->num << endl;
	cout << list3->num << endl;

	delete list1;
	delete list2;
	delete list3;

	return 0;
}