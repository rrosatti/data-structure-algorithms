#include <iostream>
typedef char ItemType;

const int MAX_ITEMS = 10;

class GenericQueue
{
 public:
  // Constructor
  GenericQueue();

  bool isEmpty() const;
  bool isFull() const;
  
  void enqueue(ItemType);
  // Voce pode retornar '0' caso esteja vazio
  ItemType dequeue();
  
  void printQueue();

  friend std::ostream& operator<<(std::ostream& os, const GenericQueue& st);
  
 private:
  int front;
  int back;
  ItemType items[MAX_ITEMS];
};
