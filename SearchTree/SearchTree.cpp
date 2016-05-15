#include "SearchTree.h"


bool SearchTree::isEmpty() const {
	return (root == NULL);
}

bool SearchTree::isFull() const {
	Node* aux;
	try {
		aux = new Node;
		delete aux;
		return false;
	} catch (std::bad_alloc exception) {
		return true;
	}
}

void SearchTree::destroyTree(Node*& tree) {
	if (tree == NULL) {
		return;
	} else if (tree->esquerda != NULL) {
		destroyTree(tree->esquerda);
	} else if (tree->direita != NULL) {
		destroyTree(tree->direita);
	}
	else {
		tree = NULL;
		delete tree;
	}
}

void SearchTree::retrieveItem(Node* tree, ItemType& item, bool& found) const {
	if (item == tree->label) {
		found = true;
		return;
	} else if (item > tree->label && tree->direita != NULL) {
		return retrieveItem(tree->direita, item, found);
	} else if (item < tree->label && tree->esquerda != NULL) {
		return retrieveItem(tree->esquerda, item, found);
	} else {
		found = false;
		return;
	}
}

void SearchTree::insertItem(Node*& tree, ItemType item) {
  if (isEmpty()) {
    Node* newNode = new Node;
    newNode->label = item;
    newNode->direita = NULL;
    newNode->esquerda = NULL;
    tree = newNode;
  } else {
    if (item >= tree->label) {
  		if (tree->direita == NULL) {
  			Node* newNode = new Node;
  			newNode->label = item;
        newNode->esquerda = NULL;
        newNode->direita = NULL;
  			tree->direita = newNode;
  		} else {
  			insertItem(tree->direita, item);
  		}
  	} else {
  		if (tree->esquerda == NULL) {
  			Node* newNode = new Node;
  			newNode->label = item;
        newNode->direita = NULL;
        newNode->esquerda = NULL;
  			tree->esquerda = newNode;
  		} else {
  			insertItem(tree->esquerda, item);
  		}
  	}
  }

}

void SearchTree::deleteItem(Node*& tree, ItemType item) {
	if (item == tree->label) {
		deleteNode(tree);
	} else if (item > tree->label && tree->direita != NULL) {
		deleteItem(tree->direita, item);
	} else if (item < tree->label && tree->esquerda != NULL) {
		deleteItem(tree->esquerda, item);
	} else {
		return;
	}
}

void SearchTree::deleteNode(Node*& tree) {
	if (tree->direita == NULL && tree->esquerda == NULL) {
		tree = NULL;
		delete tree;
	} else if (tree->direita != NULL && tree->esquerda != NULL) {
		ItemType data;
		getSuccessor(tree->direita, data);
		Node* newNode = new Node;
		newNode->label = data;
		newNode->direita = tree->direita;
		newNode->esquerda = tree->esquerda;

		tree = newNode;
	} else if (tree->direita != NULL) {
		tree = tree->direita;
	} else {
		tree = tree->esquerda;
	}
}

void SearchTree::getSuccessor(Node* tree, ItemType& data) {
	if (tree->esquerda == NULL) {
		data = tree->label;
		deleteItem(root, tree->label);
	} else {
		getSuccessor(tree->esquerda, data);
	}
}
