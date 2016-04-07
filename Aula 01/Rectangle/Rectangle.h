#include <string>

class Rectangle {
	private: 
		double base;
		double height;
		std::string color;
	public:
		Rectangle(double base = 1.0, double height = 1.0, std::string color = "red");
		double getBase();
		double getHeight();
		std::string getColor();
		double getArea();
};