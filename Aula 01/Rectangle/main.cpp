#include <iostream>
#include <string>

#include "Rectangle.h"

using namespace std;

int main() {

	double b, h;
	string c;
	
	cout << "Base: ";
	cin >> b;
	cout << "Height: ";
	cin >> h;
	cout << "Color: ";
	cin >> c;
	
	Rectangle r1 = Rectangle(b, h, c);
	
	cout << endl << "Area: " << r1.getArea() << endl;

	return 0;

}