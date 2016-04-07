#include <iostream>
typedef char ItemType;

const int MAX_ITEMS = 100;

class GenericStack
{
 public:
  // Constructor
  GenericStack();

  bool isEmpty() const;
  bool isFull() const;
  
  void push(ItemType);
  // Voce pode retornar '0' caso esteja vazio
  ItemType pop();

  friend std::ostream& operator<<(std::ostream& os, const GenericStack& st);
  
 private:
  int top;
  ItemType items[MAX_ITEMS];
};

