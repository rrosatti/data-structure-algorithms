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

	if (info[length/2] == item){
		found = true;	
	} else if(info[length/2] > item) {
		
	}
}

void GenericArray::insertItem(int item) {
	
	int i;
	for (i = 0; i < getLength(); i++) {
		if (info[i] > item)
			break;
	}

	for (int j = getLength()+1; j > i; j--) {
		info[j]= info[j-1];	
	}
	info[i] = item;
	length++;
}

void GenericArray::deleteItem(int item) {
	int location = 0;

	while (item != info[location]) {
		location++;
	}

	for (int i = location; i < getLength() - 1; i++) {
		info[i] = info[i+1];
	}
	length--;

}

