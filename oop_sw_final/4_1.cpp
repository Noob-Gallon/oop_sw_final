#include <iostream>

using namespace std;

class Point {
// ���� �����ڸ� �������� ������ �ڵ����� private�� �Ǳ� ������
// ����� �ϸ鼭 private�� �����ϰ� �ʹٸ�, protected�� �����Ѵ�...
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