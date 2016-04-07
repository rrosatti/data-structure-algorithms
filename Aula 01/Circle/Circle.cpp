#include <string>

#include "Circle.h"

using namespace std;

Circle::Circle(double r, string c) {
	radius = r;
	color = c;
}

double Circle::getRadius() {
	return radius;
}

string Circle::getColor()  {
	return color;
}

double Circle::getArea() {
	return radius * radius * 3.1416;
}