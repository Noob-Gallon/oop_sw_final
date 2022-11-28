#include <iostream>

using namespace std;

class Shape {
protected:
	int x, y;
	// x,y는 면적을 구하는데 사용될 수 있는 것이 아니므로(좌표라고 할 때)
	// 각각의 class에서 필요한 멤버를 추가한다.
	// interface는 멤버 변수를 가지지 않는 것이 좋지만,
	// 이 문제에서는 예외적으로 처리한다...

	// interface는 모든 경우에 public으로 처리한다.

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

	// upcasting을 통해서 overriding된 메서드에 접근할 수 있음...
	Shape* shape[3];
	shape[0] = &rect;
	shape[1] = &circle;
	shape[2] = &triangle;

	for (int i = 0; i < 3; i++) {
		cout << "도형 #" << i + 1 << "의 면적: " << shape[i]->getArea() << endl;
	}
	
	return 0;
}