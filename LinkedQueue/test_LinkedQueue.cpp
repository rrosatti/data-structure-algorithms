#include "LinkedQueue.h"
#include <iostream>

int main() {
  // Untemplated queue of char
  // Templated queue
  using namespace std;
  char character;
  GenericQueue queue;
  char queueChar;
  cout << "Enter a string; press return." << endl;
  cin.get(character);
  while (character != '\n')
    {
      queue.enqueue(character);
  	//std::cout << "HEY";
      cin.get(character);
    }
  
  while (!queue.isEmpty())
    {
	//std::cout << "HEY";
      queueChar = queue.dequeue();
      cout << queueChar;
    }
  cout << endl;
}

