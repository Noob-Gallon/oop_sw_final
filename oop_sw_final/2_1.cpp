#include <iostream>

using namespace std;

class Circle {
public:
	int x, y;
	int radius;
	Circle() : x(0), y(0), radius(0) {}
	Circle(int _x, int _y, int _r) : x(_x), y(_y), radius(_r) {
		cout << "Circle(" << _r << "), 생성자" << endl;
	}
	void print() {
		cout << "Circle(" << radius << ")" << endl;
	}
	// 복사 생성자 정의
	Circle(const Circle& _other) {
		this->x = _other.x;
		this->y = _other.y;
		this->radius = _other.radius;
		cout << "복사 생성자" << endl;
	}
};

// parameter로 넘어오는 c1과 c2는 복사되는 것이므로,
// 각각 복사 생성자가 동작된다.
// 그리고 더 큰 것을 return할 때도, return되는 Circle은
// main에 복사본이 넘어가게 된다.
// 따라서 복사 생성자가 동작된다.
Circle getLagerCircle(Circle c1, Circle c2) {
	cout << "더 큰 원은 다음과 같다." << endl;
	if (c1.radius >= c2.radius) {
		return c1;
	}

	return c2;
}

int main(void) {

	Circle c1(0, 0, 10);	// (0, 0), r = 10
	Circle c2(0, 0, 20); // (0, 0), r = 100
	
	cout << "getLargerCircle" << endl;
	Circle c3 = getLagerCircle(c1, c2);
	// 이 과정에서 복사 생성자는 두 번불리는 것이 아니라 한 번만 불리게 되는데,
	// 컴파일러가 getLargerCircle에서 복사되어 반환되는 instance를 다시 c3로 복사하는 것이 아니라
	// 바로 c3의 메모리에 할당해주기 때문에 복사생성자가 한 번만 불리게 된다.
	// 따라서, 복사 생성자는 총 세 번 불리게 된다.

	return 0;
}