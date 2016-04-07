#include "GenericQueue.h"
#include <iostream>

using namespace std;

int main() {
	
	char c[11] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '\0'};
	GenericQueue queue;

	for (int i = 0; i < 10; i++) {
		queue.enqueue(c[i]);
		cout << c[i] << " - ";
	}
	cout << endl;
	queue.printQueue();
	
	queue.enqueue('k');
	cout << endl;
	queue.printQueue();

	ItemType item = queue.dequeue();
	cout << endl << item << endl;
	
	queue.printQueue();
	
	queue.enqueue('k');
	cout << endl;
	queue.printQueue();
	
	
}
