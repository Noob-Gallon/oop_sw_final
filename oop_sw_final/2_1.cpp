#include <iostream>

using namespace std;

class Circle {
public:
	int x, y;
	int radius;
	Circle() : x(0), y(0), radius(0) {}
	Circle(int _x, int _y, int _r) : x(_x), y(_y), radius(_r) {
		cout << "기본 생성자" << endl;
	}
	void print() {
		cout << "Circle(" << radius << ")" << endl;
	}
	Circle(const Circle& _other) {
		this->x = _other.x;
		this->y = _other.y;
		this->radius = _other.radius;
		cout << "복사 생성자" << endl;
	}
	Circle& operator=(const Circle& _other) {
		cout << "대입 연산자" << endl;
		Circle circle(_other.x, _other.y, _other.radius);
		return circle;
	}
};

// parameter로 넘어오는 c1과 c2는 복사되는 것이므로,
// 각각 복사 생성자가 동작된다.
// 그리고 더 큰 것을 return할 때도, return되는 Circle은
// main에 복사본이 넘어가게 된다.
// 따라서 복사 생성자가 동작된다.
Circle getLagerCircle(Circle c1, Circle c2) {
	if (c1.radius >= c2.radius) {
		return c1;
	}
	
	return c2;
}

int main(void) {

	Circle c1(0, 0, 10);	// (0, 0), r = 10
	Circle c2(0, 0, 100); // (0, 0), r = 100

	cout << "getLargerCircle" << endl;
	getLagerCircle(c1, c2); // 이거 자체로도, 복사 생성자를 호출한다.
	// 만약 return을 &로 한다면, 복사 생성자를 호출하지 않는다.
	
	cout << "\n\n\n";
	Circle c3 = getLagerCircle(c1, c2);
	cout << "check here\n";

	/*cout << "c4 = c3" << endl;
	Circle c4 = c3;
	c4.print();*/

	return 0;
}