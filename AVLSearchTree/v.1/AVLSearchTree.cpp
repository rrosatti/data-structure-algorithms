#include "AVLSearchTree.h"


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
  if (tree == NULL) {
    Node* newNode = new Node;
    newNode->label = item;
    newNode->direita = NULL;
    newNode->esquerda = NULL;
		newNode->fatorB = 0;
    tree = newNode;

  } else {

    if (item > tree->label) {
			(tree->fatorB)++;
	  	insertItem(tree->direita, item);

			if (tree->fatorB == 2) {
				if ( (tree->direita)->fatorB >= 0 ) {
					rotateToLeft(tree);
				} else if ( (tree->direita)->fatorB == -1 ) {
					rotateToRightAndLeft(tree);
				}
			}

    } else {
			(tree->fatorB)--;
			insertItem(tree->esquerda, item);

			if (tree->fatorB == -2) {
				if ( (tree->esquerda)->fatorB <= 0 ) {
					rotateToRight(tree);
				} else if ( (tree->esquerda)->fatorB == 1 ) {
					rotateToLeftAndRight(tree);
				}
			}

    }

  }

}

void SearchTree::deleteItem(Node*& tree, ItemType item) {
	if (item == tree->label) {
		deleteNode(tree);
	} else if (item > tree->label && tree->direita != NULL) {

		deleteItem(tree->direita, item);

		if (tree->direita == NULL) {
			std::cout << "I've been here! 1" << "tree->label: " << tree->label << std::endl;
			(tree->fatorB)--;
		}

		if (tree->fatorB == -2) {
			if ( (tree->esquerda)->fatorB <= 0 ) {
				rotateToRight(tree);
			} else if ( (tree->esquerda)->fatorB == 1 ) {
				rotateToLeftAndRight(tree);
			}
		}

		// need to verify something here

	} else if (item < tree->label && tree->esquerda != NULL) {


		deleteItem(tree->esquerda, item);

		if (tree->esquerda == NULL) {
			std::cout << "I've been here! 2" << "tree->label: " << tree->label << std::endl;
			(tree->fatorB)++;
		}

		if (tree->fatorB == 2) {
			if ( (tree->direita) >= 0 ) {
				rotateToLeft(tree);
			} else if ( (tree->direita)->fatorB == -1 ) {
				rotateToRightAndLeft(tree);
			}
		}

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

void SearchTree::printInOrder(Node* tree) const {
	if (tree != NULL) {

		printInOrder(tree->esquerda);
		std::cout << tree->label << " height: " << tree->fatorB << std::endl;
		printInOrder(tree->direita);

       }
}

void SearchTree::printPreOrder(Node* tree) const {
	if (tree != NULL) {

		std::cout << tree->label;
		printPreOrder(tree->esquerda);
		printPreOrder(tree->direita);

       }
}

void SearchTree::printPostOrder(Node* tree) const {
	if (tree != NULL) {

		printPostOrder(tree->esquerda);
		printPostOrder(tree->direita);
		std::cout << tree->label;

  }
}

void SearchTree::rotateToLeft(Node*& tree) const {
	std::cout << "Rotate to Left! " << tree->label << std::endl;
	if ( (tree->direita)->esquerda == NULL) {
			(tree->direita)->esquerda = tree;
	} else {
		Node * aux = (tree->direita)->esquerda;
		(tree->direita)->esquerda = tree;
		tree->esquerda = aux;
	}

	(tree->direita)->fatorB--;
	tree = tree->direita;
	(tree->esquerda)->direita = NULL;
	(tree->esquerda)->fatorB--;
	//printInOrder(tree);
}

void SearchTree::rotateToRight(Node*& tree) const {
	std::cout << "Rotate to Right! " << tree->label << std::endl;
	if ( (tree->esquerda)->direita == NULL) {
			(tree->esquerda)->direita = tree;
	} else {
		Node * aux = (tree->esquerda)->direita;
		(tree->esquerda)->direita = tree;
		if (tree->direita == NULL) {
				tree->direita = aux;
		} else {
			(tree->direita)->esquerda = aux;
			std::cout << "I've been here! " << aux->label << std::endl;
		}

	}

	(tree->esquerda)->fatorB++;
	tree = tree->esquerda;
	(tree->direita)->esquerda = NULL;
	(tree->direita)->fatorB++;
	std::cout << "Rotate to Right! " << tree->label << std::endl;
	printInOrder(tree);
}

void SearchTree::rotateToRightAndLeft(Node*& tree) const {
	std::cout << "Rotate to Right and Left! " << tree->label << std::endl;
	rotateToRight(tree->direita);
	rotateToLeft(tree);
}

void SearchTree::rotateToLeftAndRight(Node*& tree) const {
	std::cout << "Rotate to Left and Right! " << tree->label << std::endl;
	rotateToLeft(tree->esquerda);
	rotateToRight(tree);
}
