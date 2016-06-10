#include "AVLSearchTree.h"


bool AVLSearchTree::isEmpty() const {
	return (root == NULL);
}

bool AVLSearchTree::isFull() const {
	Node* aux;
	try {
		aux = new Node;
		delete aux;
		return false;
	} catch (std::bad_alloc exception) {
		return true;
	}
}

void AVLSearchTree::destroyTree(Node*& tree) {
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

void AVLSearchTree::retrieveItem(Node* tree, ItemType& item, bool& found) const {
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

void AVLSearchTree::insertItem(Node*& tree, ItemType item, bool& isTaller) {
  if (tree == NULL) {
    Node* newNode = new Node;
    newNode->label = item;
    newNode->direita = NULL;
    newNode->esquerda = NULL;
		newNode->fatorB = 0;
    tree = newNode;
		isTaller = true;

  } else {

    if (item > tree->label) { // will add the item to the right

	  	insertItem(tree->direita, item, isTaller);

			if (isTaller) {
				if (tree->fatorB == 1) { // if fatorB is 1, it means that it will be unbalanced after increasing the B factor.
						performRotations(tree);
						isTaller = false;
				} else if (tree->fatorB == 0) { // if fatorB is 0, it means that the tree might be unbalanced. So, isTaller = true;
					tree->fatorB++;
					isTaller = true;
				} else if (tree->fatorB == -1) { // if fatorB is -1, then it won't be taller.
					tree->fatorB++;
					isTaller = false;
				}

      }



    } else { // will add the item to the left
			insertItem(tree->esquerda, item, isTaller);

      if (isTaller) {
				if (tree->fatorB == -1) { // if fatorB is -1, it means that it will be unbalanced after decreasing the B factor.
					performRotations(tree);
					isTaller = false;
				} else if (tree->fatorB == 1) { // if fatorB is 1, then it won't be taller.
					tree->fatorB--;
					isTaller = false;
				} else if (tree->fatorB == 0) { // if fatorB is 0, it means that the tree might be unbalanced. So, isTaller = true;
					tree->fatorB--;
					isTaller = true;
				}
			}

    }

  }

}

void AVLSearchTree::deleteItem(Node*& tree, ItemType item, bool& isShorter) {
	if (item == tree->label) {
		deleteNode(tree, isShorter);
	} else if (item > tree->label && tree->direita != NULL) {

		deleteItem(tree->direita, item, isShorter);

		if (isShorter) {
			if (tree->fatorB == 0) {
				// If fatorB = 0, it means that even after removing one son (right), the three won't need to be balanced.
				// The node on the right was removed, so we need to decrement the fatorB.
				tree->fatorB--;
				isShorter = false;
			} else if (tree->fatorB == 1) {
				// if fatorB = 1 then isShorter = true, because the node above might be unbalanced.
				// The node on the right was removed, so we need to decrement the fatorB.
				tree->fatorB--;
				isShorter = true;
			} else {
				// if fatorB == -1, it means that after removing the right node, the three will be unbalanced.
				// So, we need to perform a rotation to it.
				// isShorter is set to false, because the three will be balanced after the rotation.
				performRotations(tree);
				isShorter = false;
			}
		}

	} else if (item < tree->label && tree->esquerda != NULL) {

		deleteItem(tree->esquerda, item, isShorter);

		if (isShorter) {
			if (tree->fatorB == 0) {
				// If fatorB = 0, it means that even after removing one son (left), the three won't need to be balanced.
				// The node on the left was removed, so we need to increment the fatorB.
				tree->fatorB++;
				isShorter = false;
			} else if (tree->fatorB == -1){
				// if fatorB = -1 then isShorter = true, because the node above might be unbalanced.
				// The node on the left was removed, so we need to increment the fatorB.
				tree->fatorB++;
				isShorter = true;
			} else {
				// if fatorB == 1, it means that after removing the left node, the three will be unbalanced.
				// So, we need to perform a rotation to it.
				// isShorter is set to false, because the three will be balanced after the rotation.
				performRotations(tree);
				isShorter = false;
			}
		}

	} else {
		return;
	}

}

void AVLSearchTree::deleteNode(Node*& tree, bool& isShorter) {
	if (tree->direita == NULL && tree->esquerda == NULL) {
		tree = NULL;
		delete tree;
		isShorter = true;
	} else if (tree->direita != NULL && tree->esquerda != NULL) {
		ItemType data;
		getSuccessor(tree->direita, data);
		Node* newNode = new Node;
		newNode->label = data;
		newNode->direita = tree->direita;
		newNode->esquerda = tree->esquerda;

		/**
		When I tried to delete the node 50 instead of 80(last step), the AVL wasn't corrent the way I had implemented.
		So, I had to verify the B factor of the tree before balance it.
		I don't know if it is the right way to deal with this problem, but it was the only way I thought to solve the problem.
		*/
		if (tree->fatorB == -1) {
				newNode->fatorB = tree->fatorB;
				tree = newNode;
				deleteItem(tree->direita, data, isShorter);
				performRotations(tree);
		} else {
				newNode->fatorB = tree->fatorB - 1;
			  tree = newNode;
				deleteItem(tree->direita, data, isShorter);
		}

		isShorter = false;

	} else if (tree->direita != NULL) {
		tree = tree->direita;
		isShorter = true;
	} else {
		tree = tree->esquerda;
		isShorter = true;
	}

}

void AVLSearchTree::getSuccessor(Node* tree, ItemType& data) {
	if (tree->esquerda == NULL) {
		data = tree->label;
		//deleteItem(tree->label);
	} else {
		getSuccessor(tree->esquerda, data);
	}
}

void AVLSearchTree::printInOrder(Node* tree) const {
    if (tree != NULL) {
        printInOrder(tree->esquerda);
        std::cout << tree->label << "[" << tree->fatorB << "] ";
        printInOrder(tree->direita);
    }
}

void AVLSearchTree::printPreOrder(Node* tree) const {
    if (tree != NULL) {
        std::cout << tree->label << "[" << tree->fatorB << "] ";
        printPreOrder(tree->esquerda);
        printPreOrder(tree->direita);
    }
}


void AVLSearchTree::printPostOrder(Node* tree) const {
    if (tree != NULL) {
        printPostOrder(tree->esquerda);
        printPostOrder(tree->direita);
        std::cout << tree->label << "[" << tree->fatorB << "] ";
    }
}


void AVLSearchTree::rotateToLeft(Node*& tree) const {
	//std::cout << "Rotate to Left! " << tree->label << std::endl;
	Node *treeRight = tree->direita;
	Node *aux = treeRight->esquerda;

	treeRight->esquerda = tree;
	tree->direita = aux;

	tree = treeRight;

}

void AVLSearchTree::rotateToRight(Node*& tree) const {
	//std::cout << "Rotate to Right! " << tree->label << std::endl;
	Node *treeLeft = tree->esquerda;
	Node *aux = treeLeft->direita;

	treeLeft->direita = tree;
	tree->esquerda = aux;

	tree = treeLeft;

}

void AVLSearchTree::rotateToRightAndLeft(Node*& tree) const {
	//std::cout << "Rotate to Right and Left! " << tree->label << std::endl;
	rotateToRight(tree->direita);
	rotateToLeft(tree);
}

void AVLSearchTree::rotateToLeftAndRight(Node*& tree) const {
	//std::cout << "Rotate to Left and Right! " << tree->label << std::endl;
	rotateToLeft(tree->esquerda);
	rotateToRight(tree);
}

void AVLSearchTree::performRotations(Node*& tree) const {

	Node *son;
	if (tree->fatorB == -1) { // Left side of the tree is unbalanced
		son = tree->esquerda; // I need to verify the factor b of the left child in order to perform the correct rotation.


		switch (son->fatorB) {
			case 0: {
				son->fatorB = 1;
				tree->fatorB = -1;
				rotateToRight(tree);
				break;
			}
			case -1: {
				son->fatorB = 0;
				tree->fatorB = 0;
				rotateToRight(tree);
				break;
			}
			case 1: {
				Node *sonSon = son->direita;
				switch (sonSon->fatorB) {
					case 0: {
						tree->fatorB = 0;
						son->fatorB = 0;
						break;
					}
					case -1: {
						tree->fatorB = 1;
						son->fatorB = 0;
						break;
					}
					case 1: {
						tree->fatorB = 0;
						son->fatorB = -1;
						break;
					}

				}

				sonSon->fatorB = 0;
				rotateToLeftAndRight(tree);
			}
		}

	} else {
		// Right side of the tree is unbalanced
		son = tree->direita; // I need to verify the factor b of the right child in order to perform the correct rotation.

		switch (son->fatorB) {
			case 1: {
				tree->fatorB = 0;
				son->fatorB = 0;
				rotateToLeft(tree);
				break;
			}
			case 0: {
				tree->fatorB = 1; // value is the same
				son->fatorB = -1;
				rotateToLeft(tree);
				break;
			}
			case -1: {
				Node *sonSon = son->esquerda;

				switch (sonSon->fatorB) {
					case 1: {
						tree->fatorB = -1;
						son->fatorB = 0;
						break;
					}
					case 0: {
						tree->fatorB = 0;
						son->fatorB = 0;
						break;
					}
					case -1: {
						tree->fatorB = 0;
						son->fatorB = 1;
						break;
					}
				}


				sonSon->fatorB = 0;
				rotateToRightAndLeft(tree);
			}
		}
	}


}
