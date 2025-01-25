#include <iostream>
#include"QueueImp.h"
using namespace std;
int main()
{
	Queue<int> q1(5);
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	q1.printQueue();
	return 0;
}
