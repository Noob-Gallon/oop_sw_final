#include <iostream>

using namespace std;

#define PI 3.14

class Shape {
protected:
	int x, y;
	string color;

// Shape가 이차원 도형의 둘레와 면적을 구한다고 하는데,
// 좌표를 나타내는 값만으로는 둘레와 면적을 구할 수 없다.
// 따라서, x, y는 쓰일 수 없는 값이라고 판단했다.
// 또, 조건으로 이차원 도형이라고만 주어지고
// 어떤 도형인지 주어지지 않는다면 둘레와 면적을 실질적으로 구할 수 없기 때문에
// Shape class는 함수를 구현 하지 않고 Circle에 상속해서
// 필요한 내용을 구현하도록 한다.
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
};

class Circle : public Shape {
private:
	// 원의 면적과 둘레를 구하려면, radius가 필요함.
	// 좌표는 필요하지 않음.
	int radius;

public:
	Circle(int _x, int _y, int _r, string _color) : radius(_r) {
		this->x = _x;
		this->y = _y;
		this->color = _color;
	}
	// 현재 함수의 반환형이 double로 되어있는데,
	// 이렇게 하면 문제의 조건 처럼 면적과 둘레를 동시에 반환할 수 없다.
	// 따라서 별도의 getPerimeter() 함수를 만들어서 둘레를 반환하도록 한다.
	double getArea() {
		return PI * radius * radius;
	}
	double getPerimeter() {
		return PI * 2 * radius;
	}
};

int main(void) {

	Circle circle(0, 0, 10, "black");

	cout << "면적 : " << circle.getArea() << endl;
	cout << "둘레 : " << circle.getPerimeter() << endl;

	return 0;
}