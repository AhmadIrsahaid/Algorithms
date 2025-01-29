#pragma once
#include <iostream>
using namespace std;

class CircularLinkedList {
private:
    class Node { // Changed from struct to class
    public:
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {} // Constructor for Node
    };

    Node* tail; // Points to the last node in the list
    int size;   // Tracks the size of the list

public:
    CircularLinkedList();                // Constructor
    ~CircularLinkedList();               // Destructor

    void insertAtEmpty(int value);       // Insert in an empty list
    void insertAtBeginning(int value);   // Insert at the beginning
    void insertAtEnd(int value);         // Insert at the end
    void insertAtPosition(int value, int position); // Insert at a given position

    void deleteFirst();                  // Delete the first node
    void deleteLast();                   // Delete the last node
    void deleteAtPosition(int position); // Delete a node at a given position

    bool search(int value);              // Search for a value
    bool isEmpty() const;                // Check if the list is empty
    int getSize() const;                 // Get the size of the list

    void display() const;                // Display the list
};

// Constructor
CircularLinkedList::CircularLinkedList() : tail(nullptr), size(0) {}

// Destructor
CircularLinkedList::~CircularLinkedList() {
    while (!isEmpty()) {
        deleteFirst();
    }
}

// Insert in an empty list
void CircularLinkedList::insertAtEmpty(int value) {
    if (!isEmpty()) {
        cout << "List is not empty!\n";
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = newNode; // Points to itself
    tail = newNode;
    size++;
}

// Insert at the beginning
void CircularLinkedList::insertAtBeginning(int value) {
    if (isEmpty()) {
        insertAtEmpty(value);
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = tail->next;
    tail->next = newNode;
    size++;
}

// Insert at the end
void CircularLinkedList::insertAtEnd(int value) {
    if (isEmpty()) {
        insertAtEmpty(value);
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
    size++;
}

// Insert at a given position
void CircularLinkedList::insertAtPosition(int value, int position) {
    if (position < 0 || position > size) {
        cout << "Invalid position!\n";
        return;
    }
    if (position == 0) {
        insertAtBeginning(value);
    }
    else if (position == size) {
        insertAtEnd(value);
    }
    else {
        Node* temp = tail->next;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
}

// Delete the first node
void CircularLinkedList::deleteFirst() {
    if (isEmpty()) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = tail->next;
    if (tail->next == tail) {
        tail = nullptr;
    }
    else {
        tail->next = temp->next;
    }
    delete temp;
    size--;
}

// Delete the last node
void CircularLinkedList::deleteLast() {
    if (isEmpty()) {
        cout << "List is empty!\n";
        return;
    }
    if (tail->next == tail) {
        deleteFirst();
        return;
    }
    Node* temp = tail->next;
    while (temp->next != tail) {
        temp = temp->next;
    }
    temp->next = tail->next;
    delete tail;
    tail = temp;
    size--;
}

// Delete a node at a given position
void CircularLinkedList::deleteAtPosition(int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position!\n";
        return;
    }
    if (position == 0) {
        deleteFirst();
    }
    else {
        Node* temp = tail->next;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        if (delNode == tail) {
            tail = temp;
        }
        delete delNode;
        size--;
    }
}

// Search for a value
bool CircularLinkedList::search(int value) {
    if (isEmpty()) {
        return false;
    }
    Node* temp = tail->next;
    do {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    } while (temp != tail->next);
    return false;
}

// Check if the list is empty
bool CircularLinkedList::isEmpty() const {
    return tail == nullptr;
}

// Get the size of the list
int CircularLinkedList::getSize() const {
    return size;
}

// Display the list
void CircularLinkedList::display() const {
    if (isEmpty()) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

