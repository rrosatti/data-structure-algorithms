#include "Heap.h"
#include <iostream>

Heap::Heap(int max) {
	maxItems = max;
	length = 0;
	items = new ItemType[maxItems];
}

Heap::Heap(int max, ItemType *items, int l) {
	maxItems = max;
	length = 0;
	this->items = new ItemType[maxItems];
	for (int i = 0; i < l; i++) {
		this->enqueue(items[i]);
	}
}

Heap::~Heap() {
	delete items;
}

bool Heap::isEmpty() const {
	return (length == 0);
}

bool Heap::isFull() const {
	return (length == maxItems);
}

void Heap::enqueue(ItemType newItem) {
	if(isEmpty()) {
		items[length] = newItem;
		length++;
	} else if (!isFull()) {
		items[length] = newItem;
		length++;
		subida(length - 1);
	}

}

ItemType Heap::dequeue() {
	if(!isEmpty()) {
		//std::cout << "length: " << length << " " << items[0] << std::endl;
		ItemType removedPos = items[0];
		if (length == 1) {
			length--;
			return removedPos;
		}
		items[0] = items[length - 1]; //MAYBE THIS IS THE PROBLEM - WHATCH THE VIDEO LATER
		length--;
		descida(0);
		return removedPos;
	}
}


void Heap::subida(int pos) {
	int pai = (pos - 1)/2;
	while (items[pos] > items[pai]) {
		ItemType aux = items[pos];
		items[pos] = items[pai];
		items[pai] = aux;
		pos = pai;
		pai = (pai - 1)/2;
		if (pos == 0)
			break;
	}
}

void Heap::descida(int pos) {
	int filho1 = 2*pos + 1;
	int filho2 = 2*pos + 2;
	int son = (items[filho1] > items[filho2]) ? filho1 : filho2;
	//std::cout << "pos: " << pos << " son: " << son << std::endl;
	//std::cout << "items[pos]: " << items[pos] << " items[son]: " << items[son] << std::endl;
	if(son > length) {
		return;
	} else {
		if (items[pos] < items[son]) {
			ItemType aux = items[pos];
			items[pos] = items[son];
			items[son] = aux;
			pos = son;
			descida(pos);
		} else {
			return;
		}
	}
}

/**
void Heap::printHeap() {
	for (int i = 0; i < length; i++) {
		std::cout << items[i] << std::endl;
	}
}
*/
