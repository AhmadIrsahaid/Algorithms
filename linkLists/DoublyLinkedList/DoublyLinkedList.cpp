#include <iostream>
#include"DlistImp.h"
using namespace std;
int main() {
    Dlist<int> list;

    list.insertFirst(10);
    list.insertBack(20);
    list.insertAtPosition(15, 1);

    cout << "List: ";
    list.printList(); 

    cout << "List in reverse: ";
    list.printListInReverse(); 

    list.removeAtPosition(1);
    cout << "After removing at position 1: ";
    list.printList(); 

    return 0;
}

