#pragma once
#include <iostream>
#include <vector> 
using namespace std;
const int maxSize = 100;
template<class T>
class Stack {

private : 
	T array[maxSize];
	int top;

public :

	Stack() : top(-1) {}

	bool isEmpty() {
		return top < 0;
	}

	void push(T value) {
		if (!(top >= maxSize - 1)) {
			top++;
			array[top] = value;
		}
		else {
			cout << "Stack full to push" << endl;
			throw runtime_error("Stack is empty.");
		}
	}

	void pop() {
		if (!isEmpty()) {
			top--;
		}
		else {
			cout <<"Stack empty to pop"<<endl;
			throw runtime_error("Stack is empty.");
		}
	}

	void pop(T &value) { 
		if (!isEmpty()) {
			value = array[top];
			top--;
		}
		else {
			cout << "Stack empty to pop" << endl;
			throw runtime_error("Stack is empty.");
		}
	}

	T getTop() const{
		if (!isEmpty()) {
			return array[top];
		}
		else {
			cout << "Stack is empty; cannot get top element." << endl;
			throw runtime_error("Stack is empty.");
		}
		
	}

	void print() {
		cout << "[ ";
		for (int i = top; i >= 0; i--)
		{
			cout << array[i] << " ";
		}
		cout << "]";
		cout << endl;

	}

	T* convertToArray()  {


		if (isEmpty()) {
			cout << "Stack is empty; returning an empty array." << endl;
			return nullptr;
		}

		T* result = new T[top + 1];

		for (int i = 0; i <= top; i++) {
			result[i] = array[i];
		}

		return result;

	}

	vector<T> convertToVector()  {
		vector<T> result;

		for (int i = 0; i <= top; i++) {
			result.push_back(array[i]);
		}

		return result;
	}

	~Stack() {
		delete[]array;
	}
	
};