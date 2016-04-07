#include <iostream>
#include "GenericArray.h"

GenericArray::GenericArray() {
	length = 0;
}	

bool GenericArray::isFull() const {
	return (length == MAX_ITEMS);
}

int GenericArray::getLength() const {
	return length;
}

void GenericArray::retrieveItem(int &item, bool &found) {
	int location = 0;
	found = false;

	while ( (location < length) && !found ) {
		if (item == info[location]) {
			found = true;
			item = info[location];
		}
		location = location + 1; 
	}
}

void GenericArray::insertItem(int item) {
	info[length] = item;
	length++;
}

void GenericArray::deleteItem(int item) {
	int location = 0;

	while (item != info[location]) {
		location++;
	}

	info[location] = info[length - 1];
	length--;
}

