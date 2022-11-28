#include <iostream>

using namespace std;

class Shape {
protected:
	int x, y;
	string color;

public:
	virtual double getArea() = 0;
};

class Circle : public Shape {
private:
	int radius;

public:
	Circle(int _x, int _y, int _r, string _color) : radius(_r) {
		this->x = _x;
		this->y = _y;
		this->color = _color;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

int main(void) {

	Circle circle(0, 0, 10, );

	return 0;
}