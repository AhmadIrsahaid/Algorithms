#include <iostream>
#include"LinkedListImp.h"
using namespace std;
int main() {
    singlyLinkedList<int> list;

    list.insertFirst(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertAtPos(1, 15);

    cout << "Original List: ";
    list.printList(); // Output: 10 15 20 30

    list.reverse();
    cout << "Reversed List: ";
    list.printList(); 

    list.removeElement(20);
    cout << "After Removing 20: ";
    list.printList(); 

    cout << "Position of 15: " << list.search(15) << endl; 

   cout << list.getFront()<<"\t";
   cout << list.getLast();

    return 0;
}


