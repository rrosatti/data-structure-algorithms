#include "HeapSort.h"
#include <iostream>

int main() {
  // Untemplated queue of char
  // Templated heap
  using namespace std;
  char character;
  char* characters   = new char[100];
  int count = 0;

  cout << "Enter several numbers again; press return." << endl;
  cin.get(character); 
  while (character != '\n')
    {
      characters[count] = character;
      cin.get(character);
      count++;
    }

  HeapSort heap(100, characters, count);
  heap.printHeapSort();
  heap.sort();
  while (!heap.isEmpty())
    {
      character = heap.dequeue();
      cout << character;
    }
  
  cout << endl;
}
