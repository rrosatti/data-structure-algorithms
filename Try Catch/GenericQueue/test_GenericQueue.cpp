#include "GenericQueue.h"
#include <iostream>

using namespace std;

int main() {
  char character;
  GenericQueue queue;
  char queueChar;
  cout << "Enter a string; press return." << endl;
  cin.get(character);
  try {
    while (character != '\n')
    {
      queue.enqueue(character);
      cin.get(character);
    }
  } catch (FullQueue &) {
    cout << "Queue is full!" << endl;
  }

  try {
    while (!queue.isEmpty())
    {
      queueChar = queue.dequeue();
      cout << queueChar;
    }
  } catch (EmptyQueue &) {
    cout << "Queue is empty!" << endl;
  }
  
	
  cout << endl;
  
}
