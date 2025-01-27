#include <iostream>
#include"DlistImp.h"
using namespace std;
int main()
{
	Dlist<int> list;

	list.insertFirst(33);
	list.insertFirst(23);
	list.insertFirst(13);
	list.insertFirst(53);
	list.insertBack(99);
	cout << "before remove first and last" << endl;
	list.printList();
	list.removeFirst();
	list.removeLast();
	list.removeAtPosition(2);
	cout << "after remove first and last" << endl;
	list.printList();
	list.printList();
	list.printListInReverse();
	list.insertAtPosition(3, 4);
	


}

