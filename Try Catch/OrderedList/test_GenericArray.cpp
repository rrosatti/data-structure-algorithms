#include <iostream>
#include "GenericArray.h" 

using namespace std;


ostream& operator<<(ostream& os, const GenericArray& array){
  for (int i = 0; i < array.length; i++) {
    os << array.info[i];
  }
  os << endl;
  return os;
}

int main(){
  GenericArray unsorted;

  int elements[4] = {5, 7, 6, 9};
  
  try {
    for (int i = 0; i <= 3; i++) {
      int item(elements[i]);
      unsorted.insertItem(item);
    }
  } catch (FullArray &) {
    cout << "List is full!" << endl;
  }

  cout << unsorted;
  
  int item(7);
  bool     found = false;

  unsorted.retrieveItem(item, found);
  cout << item << endl;

  unsorted.deleteItem(item);
  cout << unsorted;
  int item2(4);
  unsorted.retrieveItem(item2, found);
  cout << "Found: " << found << endl;
  
  int pos;
  cout << "Position you want to remove: ";
  cin >> pos;
  unsorted.removeItemByPosition(pos);
  
  unsorted.insertItem(7);
  unsorted.insertItem(10);
  cout << unsorted;
  
  cout << "Fim" << endl;
  
}


