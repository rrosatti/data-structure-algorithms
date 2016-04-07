#include <string>

class Circle{
	private:
		double radius;
		std::string color;
	public:
		Circle(double r = 1.0, std::string color = "red");
		double getRadius();
		std::string getColor();
		double getArea();
};