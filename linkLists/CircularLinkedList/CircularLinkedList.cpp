#include<iostream>
#include "CircularLinkedList.h"
using namespace std;
int main() {
    CircularLinkedList cll;

    // Test insertion
    cll.insertAtEmpty(10);
    cll.display();

    cll.insertAtBeginning(5);
    cll.display();

    cll.insertAtEnd(20);
    cll.display();

    cll.insertAtPosition(15, 2);
    cll.display();

    // Test deletion
    cll.deleteFirst();
    cll.display();

    cll.deleteLast();
    cll.display();

    cll.deleteAtPosition(1);
    cll.display();

    // Test search
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cout << "Searching for 30: " << (cll.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for 50: " << (cll.search(50) ? "Found" : "Not Found") << endl;

    // Test size and isEmpty
    cout << "Size of the list: " << cll.getSize() << endl;
    cout << "Is the list empty? " << (cll.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
