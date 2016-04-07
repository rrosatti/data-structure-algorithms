#include "GenericQueue.h"

using namespace std;

GenericQueue::GenericQueue() {
	front = 0;
	back = 0;
}

bool GenericQueue::isEmpty() const {
	/*return (front > back);*/
	return (back == 0);
	
}

bool GenericQueue::isFull() const {
	return (back == MAX_ITEMS);
}

void GenericQueue::enqueue(ItemType item) {
	if (!isFull()) {
		items[back] = item;
		back++;
	} 
}

ItemType GenericQueue::dequeue() {
	if(!isEmpty()) {
		ItemType deletedItem = items[0];
		for (int i = 0; i < back - 1; i++) {
			ItemType aux = items[i + 1];
			items[i] = aux;
		}
		back--;
		return  deletedItem;
	} else {
		return 0;
	}
}

/**
void GenericQueue::printQueue() {
	for (int i = 0; i < back; i++) {
		std::cout << items[i] << " - ";
	}
}

*/



