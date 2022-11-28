#include <iostream>

using namespace std;

class Point {
// 접근 제어자를 지정하지 않으면 자동으로 private이 되기 때문에
// 상속을 하면서 private을 유지하고 싶다면, protected로 선언한다...
protected:
	int x, y;
	Point(int _x, int _y) : x(_x), y(_y) {
	}
};

class ThreeDPoint : public Point {
private:
	int z;

public:
	ThreeDPoint(int _x, int _y, int _z) : Point(_x, _y), z(_z) {}
	void print() {
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}
	ThreeDPoint operator+(const ThreeDPoint& _other) {
		ThreeDPoint tdp(x+_other.x, y+_other.y, z+_other.z);
		return tdp;
	}
};

int main(void) {

	ThreeDPoint p(10, 10, 10);
	ThreeDPoint p2(20, 20, 20);

	p.print();
	p2.print();

	ThreeDPoint p3 = p + p2;
	p3.print();

	return 0;
}