#include <iostream>

using namespace std;

class Shape {
protected:
	int x, y;
	
public:
	// ���� ���� �Լ� getArea() ����.
	virtual double getArea() = 0;
};

// x,y�� ������ ���ϴµ� ���� �� �ִ� ���� �ƴϹǷ�(��ǥ��� �� ��)
// ������ class���� ������ ���ϱ� ���� �ʿ��� ����� �߰��Ѵ�.

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
	// getArea�� overriding�ؼ� �������Ѵ�.
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
	// getArea�� overriding�ؼ� �������Ѵ�.
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
	// getArea�� overriding�ؼ� �������Ѵ�.
	double getArea() {
		return 0.5 * width * height;
	}
};

int main(void) {

	Rect rect(0, 0, 10, 10);
	Circle circle(0, 0, 10);
	Triangle triangle(0, 0, 10, 10);

	// Shape* �迭�� ����� rect, circle, triangle�� �ּҸ� ����Ű�� �����
	// upcasting�� ���ؼ� overriding�� �޼��� getArea()�� ������ �� ����.
	// getArea()�� virtual method�̹Ƿ�, ������ �ڽ� Ŭ�������� ���ǵ� getArea()�� �Ҹ���.
	Shape* shape[3];
	shape[0] = &rect;
	shape[1] = &circle;
	shape[2] = &triangle;

	for (int i = 0; i < 3; i++) {
		cout << "���� #" << i + 1 << "�� ����: " << shape[i]->getArea() << endl;
	}
	
	return 0;
}