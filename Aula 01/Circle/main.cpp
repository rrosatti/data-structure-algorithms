#include <iostream>
#include <string>

#include "Circle.h"

using namespace std;

int main() {

	double r;
	string c;
	
	cout << "Radius: " ;
	cin >> r;
	cout << "Color: ";
	cin >> c;
	
	Circle c1 = Circle(r, c);
	
	cout <<  endl << "The " << c1.getColor() << " circle has a radius of " << c1.getRadius() << "."; 
	cout <<  endl << "The area of this circle is " << c1.getArea() << ".";
	
	return 0;

}