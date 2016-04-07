#include "GenericStack.h"
#include <iostream>

using namespace std;

bool checkSymbol(GenericStack s, char ch);

int main() {
  char character;
  GenericStack stack;
  char stackChar;
  cout << "Enter a string; press return." << endl;
  cin.get(character);
  while (character != '\n')
    {
		if (!checkSymbol(stack , character)) {
			stack.push(character);
		} else {
			stack.pop();
		}
		cin.get(character);
    }
	
  while (!stack.isEmpty())
    {
		stackChar = stack.pop();
		cout << stackChar;
    }
	cout << endl;
}

bool checkSymbol(GenericStack s, char ch) {
	char aux = s.pop();
	
	switch (ch) {
		case '}':
			if (aux == '{') return true;
			break;
		case ')':
			if (aux == '(') return true;
			break;
		case ']':
			if (aux == '[') return true;
			break;
		default:
			return false;
	}
}