#include "LinkedQueue.h"
#include <cstddef>
#include <iostream>
#include <new>


GenericQueue::GenericQueue() {
	front = NULL;
	rear = NULL;
}

GenericQueue::~GenericQueue() {
	if (!isEmpty()) {
		NodeType* aux = new NodeType;
		while (front != NULL) {
			aux = front;
			front = front->next;
			delete aux;
		}
	}
	
}

bool GenericQueue::isEmpty() const {
	return (front == NULL);
}

bool GenericQueue::isFull() const {
	NodeType* aux;
	try {
		aux = new NodeType;
		delete aux;
		return false;			
	} catch (std::bad_alloc exception) {
		return true;
	}
}

void GenericQueue::enqueue(ItemType item) {
	if (isEmpty()) {
		NodeType* newItem = new NodeType;
		newItem->info = item;
		newItem->next = NULL;
		front = newItem;
		rear = newItem;
	} else {
		if (!isFull()) {
			NodeType* newItem = new NodeType;
			newItem->info = item;
			newItem->next = NULL;
			rear->next = newItem;
			rear = newItem;
			
			//std::cout << "rear : " << newItem->info << " front: " << (front->next)->info << std::endl;
		}
	}
}

ItemType GenericQueue::dequeue() {
		//std::cout << "teste" << std::endl;
	if (!isEmpty()) {
		//std::cout << "teste" << std::endl;
		NodeType* temp = new NodeType;
		temp = front;
		front = front->next;
		ItemType item;
		item = temp->info;
		
		temp = NULL;
		delete temp;
		return item;
	}
}


