#include <iostream>

using namespace std;

class Shape { // interface, ���� ���� �Լ�(pure virtual function, ����ü�� ����.)
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
	// pure virtual function Shape�� �����͸�
	// �迭�� ����. �׸��� ������ t, c, r�� �ּҸ� ����Ű�� �Ѵ�.
	// �̷��� �ϴ� ���� upcasting�̶�� �� �� �ְ�,
	// upcasting�̹Ƿ� Shape* s�� ���ؼ���
	// getArea()�� �ҷ��� �� �ִ�.

	for (auto& _e : s) {
		cout << _e->getArea() << endl;
	}

	return 0;
}