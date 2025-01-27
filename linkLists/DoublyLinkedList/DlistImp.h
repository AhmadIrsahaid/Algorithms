#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T value;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class Dlist {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    Node<T>* createNode(const T& value) {
        Node<T>* node = new Node<T>();
        node->value = value;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }

public:
    Dlist() : head(nullptr), tail(nullptr), size(0) {}

    bool isEmpty() {
        return size == 0;
    }

    int getSize() const {
        return this->size;
    }

    void insertFirst(const T& value) {
        Node<T>* newNode = createNode(value);

        if (isEmpty()) {
            this->head = this->tail = newNode;
        }
        else {
            newNode->next = this->head;
            head->prev = newNode;
            this->head = newNode;
        }
        size++;
    }

    void insertBack(const T& value) {
        Node<T>* newNode = createNode(value);

        if (isEmpty()) {
            this->head = this->tail = newNode;
        }
        else {
            newNode->prev = this->tail;
            tail->next = newNode;
            this->tail = newNode;
        }
        size++;
    }

    void insertAtPosition(const T& value, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Out of the range ..........!" << endl;
            return;
        }

        if (pos == 0) {
            insertFirst(value);
        }
        else if (pos == size) {
            insertBack(value);
        }
        else {
            Node<T>* newNode = createNode(value);
            Node<T>* current = head;

            for (int i = 1; i < pos; i++) {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;

            size++;
        }
    }

    T getHead() const {
        if (!head) {
            throw runtime_error("List is empty!");
        }
        return this->head->value;
    }

    T getTail() const {
        if (!tail) {
            throw runtime_error("List is empty!");
        }
        return this->tail->value;
    }

    void removeFirst() {
        if (isEmpty()) {
            cout << "Empty List ...........!" << endl;
            return;
        }

        Node<T>* current = head;

        if (getSize() == 1) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete current;
        size--;
    }

    void removeLast() {
        if (isEmpty()) {
            cout << "Empty List ...........!" << endl;
            return;
        }

        Node<T>* current = tail;

        if (getSize() == 1) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete current;
        size--;
    }
    void removeAtPosition(int pos)
    {
        if (pos < 0 || pos >= size) {
            cout << "Out Of Range" << endl;
            return;
        }
        else if (pos == 0)
        {
            removeFirst();
        }
        else if (pos == size - 1)
        {
            removeLast();
        }
        else {
            Node<T>* current = head->next;


            for (int i = 1; i < pos; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        size--;
    }
    void printList() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printListInReverse() const {
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->prev;
        }
        cout << endl;
    }
};
