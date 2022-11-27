#include <iostream>

using namespace std;

class Shape { // interface, 순수 가상 함수(pure virtual function, 구현체가 없다.)
public:
	virtual double getArea() = 0;
};

class Triangle : public Shape {
private:
	int width, height;

public:
	Triangle(int _w, int _h) : width(_w), height(_h) {

	}
	double getArea() {
		return (double)(0.5 * width * height);
	}
};

class Circle : public Shape {
private:
	double r;

public:
	Circle(double _r) : r(_r) {

	}
	double getArea() {
		return (double)(3.14 * r * r);
	}
};

class Rectangle : public Shape {
private:
	int width, height;

public:
	Rectangle(int _w, int _h) : width(_w), height(_h) {

	}
	double getArea() {
		return (double)(width * height);
	}
};

int main(void) {

	Triangle t(10, 10);
	Circle c(10.0);
	Rectangle r(10, 10);

	cout << t.getArea() << endl;
	cout << c.getArea() << endl;
	cout << r.getArea() << endl;

	Shape* s[3];
	s[0] = &t;
	s[1] = &c;
	s[2] = &r;
	// pure virtual function Shape의 포인터를
	// 배열로 선언. 그리고 각각을 t, c, r의 주소를 가리키게 한다.
	// 이렇게 하는 것은 upcasting이라고 볼 수 있고,
	// upcasting이므로 Shape* s를 통해서는
	// getArea()만 불러올 수 있다.

	for (auto& _e : s) {
		cout << _e->getArea() << endl;
	}

	return 0;
}