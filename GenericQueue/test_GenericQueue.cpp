#include "GenericQueue.h"
#include <iostream>

using namespace std;

int main() {
  char character;
  GenericQueue queue;
  char queueChar;
  cout << "Enter a string; press return." << endl;
  cin.get(character);
  while (character != '\n')
    {
      queue.enqueue(character);
      cin.get(character);
    }
  while (!queue.isEmpty())
    {
      queueChar = queue.dequeue();
      cout << queueChar;
    }
	
  cout << endl;
  
}


