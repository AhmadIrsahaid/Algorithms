#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    int front;
    int rear;
    int len;
    int maxSize;
    T* arr;

public:
    Queue(int size) {
        if (size <= 0) {
            this->maxSize = 100;
        }
        else {
            this->maxSize = size;
        }

        this->front = 0;
        this->rear = this->maxSize - 1;
        this->len = 0;
        arr = new T[maxSize];
    }

    bool isEmpty() const {
        return len == 0;
    }

    bool isFull() const {
        return len == maxSize;
    }

    void enqueue(T value) {
        if (!isFull()) {
            rear = (rear + 1) % maxSize;
            arr[rear] = value;
            len++;
        }
        else {
            cout << "Queue Full! Cannot Enqueue!" << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            front = (front + 1) % maxSize;
            len--;
        }
        else {
            cout << "Queue Empty! Cannot Dequeue!" << endl;
        }
    }

    int getFront() const {
        return front;
    }

    int getRear() const {
        return rear;
    }

    void printQueue() const {
        if (!isEmpty()) {
            for (int i = front, count = 0; count < len; i = (i + 1) % maxSize, count++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "Queue is Empty!" << endl;
        }
    }

    int queueSearch(T value) const {
        if (!isEmpty()) {
            for (int i = front, count = 0; count < len; i = (i + 1) % maxSize, count++) {
                if (arr[i] == value) {
                    return i;
                }
            }
        }
        else {
            cout << "Queue is Empty!" << endl;
        }
        return -1;  
    }

    ~Queue() {
        delete[] arr;
    }
};
