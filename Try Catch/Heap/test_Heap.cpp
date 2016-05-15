#include "Heap.h"
#include <iostream>

int main() {
  // Untemplated queue of char
  // Templated heap
  using namespace std;
  char character;
  Heap heap1(5);
  char heapChar;
  cout << "Enter several numbers; press return." << endl;
  cin.get(character);

  try {
    while (character != '\n')
    {
      heap1.enqueue(character);
      cin.get(character);
    }
  } catch (FullHeap &) {
    cout << "Heap is full!" << endl;
  }
	//heap1.printHeap();
  try {
    while (!heap1.isEmpty())
    {
      heapChar = heap1.dequeue();
      cout << heapChar;
    }
  } catch (EmptyHeap &) {
    cout << "Heap is empty!" << endl;
  }
  cout << "\n";


  char* characters   = new char[100];
  int count = 0;

  // This will clear the buffer before use cin.get() again.
  // If we don't use it, the program will finish when the first try throws an exception!
  cin.ignore(1000, '\n');
  cin.clear();
  cout << "Enter several numbers again; press return." << endl;
  cin.get(character);

  while (character != '\n')
    {
      characters[count] = character;
      cin.get(character);
      count++;
    }

  Heap heap2(5, characters, count);
  //heap2.printHeap();
  try {
    while (!heap2.isEmpty())
    {
      heapChar = heap2.dequeue();
      cout << heapChar;
    }
  } catch (EmptyHeap &) {
    cout << "Heap is empty!" << endl;
  }


  cout << endl;
}
