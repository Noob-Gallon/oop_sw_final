#include <iostream>

using namespace std;

class Shape {
protected:
	int x, y;
	// x,y�� ������ ���ϴµ� ���� �� �ִ� ���� �ƴϹǷ�(��ǥ��� �� ��)
	// ������ class���� �ʿ��� ����� �߰��Ѵ�.
	// interface�� ��� ������ ������ �ʴ� ���� ������,
	// �� ���������� ���������� ó���Ѵ�...

	// interface�� ��� ��쿡 public���� ó���Ѵ�.

public:
	virtual double getArea() = 0;
};

class Rect : public Shape {
private:
	int width;
	int height;

public:
	Rect(int _x, int _y, int _w, int _h) {
		this->x = _x;
		this->y = _y;
		this->width = _w;
		this->height = _h;
	}
	double getArea() {
		return width * height;
	}
};

class Circle : public Shape {
private:
	int radius;

public:
	Circle(int _x, int _y, int _r) {
		this->x = _x;
		this->y = _y;
		this->radius = _r;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

class Triangle : public Shape {
private:
	int width;
	int height;

public:
	Triangle(int _x, int _y, int _w, int _h) {
		this->x = _x;
		this->y = _y;
		this->width = _w;
		this->height = _h;
	}
	double getArea() {
		return 0.5 * width * height;
	}
};

int main(void) {

	Rect rect(0, 0, 10, 10);
	Circle circle(0, 0, 10);
	Triangle triangle(0, 0, 10, 10);

	// upcasting�� ���ؼ� overriding�� �޼��忡 ������ �� ����...
	Shape* shape[3];
	shape[0] = &rect;
	shape[1] = &circle;
	shape[2] = &triangle;

	for (int i = 0; i < 3; i++) {
		cout << "���� #" << i + 1 << "�� ����: " << shape[i]->getArea() << endl;
	}
	
	return 0;
}