#include <iostream>

using namespace std;

class Point {
	// 접근 제어자를 지정하지 않으면 자동으로 private이 되기 때문에
	// 상속을 하면서 private을 유지하고 싶다면, protected로 선언한다.
protected:
	int x, y;
	Point(int _x, int _y) : x(_x), y(_y) {
	}
	// getter, setter
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
};

class ThreeDPoint : public Point {
private:
	// 자식 클래스에서 추가된 변수
	int z;

public:
	ThreeDPoint(int _x, int _y, int _z) : Point(_x, _y), z(_z) {}
	void print() {
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}
	// + operator overloading 정의.
	// 두 객체의 x, y, z의 값을 더한 복사본을 만들어서, 다시 main으로
	// 복사본으로 넘겨준다. (왜냐면, 새로운 객체가 사라지기 때문에)
	ThreeDPoint operator+(const ThreeDPoint& _other) {
		ThreeDPoint tdp(x+_other.x, y+_other.y, z+_other.z);
		return tdp;
	}
	// getter, setter
	int getZ() {
		return z;
	}
	void setZ(int z) {
		this->z = z;
	}
};

int main(void) {

	ThreeDPoint p(10, 10, 10);
	ThreeDPoint p2(20, 20, 20);

	p.print();
	p2.print();

	// overloading checking
	ThreeDPoint p3 = p + p2;
	p3.print();

	return 0;
}