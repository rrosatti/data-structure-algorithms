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

  try {
    while (!queue.isEmpty())
    {
	//std::cout << "HEY";
      queueChar = queue.dequeue();
      cout << queueChar;
    }
    // This line below let you test the 'throw EmptyQueue();' inside the dequeue method!
    //queueChar = queue.dequeue();
  } catch (EmptyQueue &) {
    cout << endl << "Queue is empty!" << endl;
  }
  cout << endl;
}
