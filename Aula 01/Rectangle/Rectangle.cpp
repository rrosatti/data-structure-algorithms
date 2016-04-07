#include <string>

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double b, double h, string c) {
	base = b;
	height = h;
	color = c;
}

double Rectangle::getBase() {
	return base;
}

double Rectangle::getHeight() {
	return height;
}

string Rectangle::getColor() {
	return color;
}

double Rectangle::getArea() {
	return base * height;
}