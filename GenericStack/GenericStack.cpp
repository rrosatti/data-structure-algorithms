#include "GenericStack.h"

GenericStack::GenericStack() {
	top = 0;
}

bool GenericStack::isEmpty() const{
	return (top == 0);
}

bool GenericStack::isFull() const {
	return (top == MAX_ITEMS);
}

void GenericStack::push(ItemType item) {
	if (!isFull()) {
		items[top] = item;
		top++;
	}
}

ItemType GenericStack::pop() {
	if (!isEmpty()) {
		ItemType aux = items[top - 1];
		top--;
		return aux;
	} else {
		return 0;
	}
}
