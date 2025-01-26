#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T value;      
    Node<T>* next; 
};

template <class T>
class singlyLinkedList {
private:
    Node<T>* first;
    Node<T>* last;
    int size;

public:
    singlyLinkedList() {
        this->first = this->last = nullptr;
        this->size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

  

    int getSize() const {
        return this->size;
    }
    void insertFirst(T value) {
        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        newNode->next = first;

        if (isEmpty()) {
            last = newNode;
        }

        first = newNode;
        size++;
    }

    void insertBack(T value) {
        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
        size++;
    }

    void insertAtPos(int pos, T value) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 0) {
            insertFirst(value);
        }
        else if (pos == size) {
            insertBack(value);
        }
        else {
            Node<T>* newNode = new Node<T>();
            newNode->value = value;

            Node<T>* current = first;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "The list is already empty!" << endl;
            return;
        }

        Node<T>* temp = first;
        first = first->next;
        delete temp;
        size--;

        if (size == 0) {
            last = nullptr;
        }
    }

    T getFront()  {
        return this->first->value;
    }

    T getLast()  {
        return this->last->value;
    }

    void removeBack() {
        if (isEmpty()) {
            cout << "The list is already empty!" << endl;
            return;
        }

        if (size == 1) {
            delete first;
            first = last = nullptr;
        }
        else {
            Node<T>* current = first;
            while (current->next != last) {
                current = current->next;
            }
            delete last;
            last = current;
            last->next = nullptr;
        }
        size--;
    }

    void removeElement(T value) {
        if (isEmpty()) {
            cout << "Cannot remove from an empty list!" << endl;
            return;
        }

        if (first->value == value) {
            removeFront();
            return;
        }

        Node<T>* current = first;
        Node<T>* previous = nullptr;

        while (current != nullptr && current->value != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Element not found!" << endl;
            return;
        }

        previous->next = current->next;
        if (current == last) {
            last = previous;
        }
        delete current;
        size--;
    }

    void reverse() {
        Node<T>* previous = nullptr;
        Node<T>* current = first;
        Node<T>* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        last = first;
        first = previous;
    }

    int search(T value) {
        Node<T>* current = first;
        int pos = 0;

        while (current != nullptr) {
            if (current->value == value) {
                return pos;
            }
            current = current->next;
            pos++;
        }
        return -1;
    }

    void printList() {
        Node<T>* current = first;

        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~singlyLinkedList() {
        Node<T>* current = first;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
