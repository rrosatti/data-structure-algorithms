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

void GenericArray::insertItem(int item) {
	
	int pos;
	
	if (!isFull()) {
		
		for (pos = 0; pos < getLength(); pos++) {
			if (info[pos] > item) 
				break;
		}
		
		for (int i = getLength() + 1; i > pos; i--) {
			info[i] = info[i - 1];
		}
		info[pos] = item;
		length++;
		
	} else {
		//std::cout << "List is full!" << std::endl;
	}
	
}

void GenericArray::deleteItem(int item) {
	
	int pos = -1;
	
	for (int i = 0; i < getLength(); i++) {
		if (info[i] == item)
			pos = i;
	}
	
	if (pos != -1) {
			for (int i = pos; i < getLength() - 1; i++) {
				info[i] = info[i+1];
			}
			length--;
	}
	
}

/**
	Remove a i-nésima posição na lista ordenada.
*/
void GenericArray::removeItemByPosition(int pos) {
	
	if (pos < 0 || pos > getLength()) {
		//std::cout << "Invalid position" << std::endl;
	} else {
		
		for (int i = pos; i < getLength(); i++) {
			info[i] = info[i + 1];
		}
		length--;
		
	}
	
}

void GenericArray::retrieveItem(int &item, bool &found) {
	
	found = false;
	
	if (info[length/2] == item) {
		found = true;
	} else if (info[length/2] > item) {
		
		for (int i = 0; i < length/2; i++) {
			if (info[i] == item)
				found = true;
		}
		
	} else {
		for (int i = length/2; i < length; i++) {
			if (info[i] == item) 
				found = true;
		}
	}
	
}

