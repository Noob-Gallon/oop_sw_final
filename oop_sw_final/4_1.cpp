#include <iostream>

using namespace std;

class Point {
	// ���� �����ڸ� �������� ������ �ڵ����� private�� �Ǳ� ������
	// ����� �ϸ鼭 private�� �����ϰ� �ʹٸ�, protected�� �����Ѵ�.
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
	// �ڽ� Ŭ�������� �߰��� ����
	int z;

public:
	ThreeDPoint(int _x, int _y, int _z) : Point(_x, _y), z(_z) {}
	void print() {
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}
	// + operator overloading ����.
	// �� ��ü�� x, y, z�� ���� ���� ���纻�� ����, �ٽ� main����
	// ���纻���� �Ѱ��ش�. (�ֳĸ�, ���ο� ��ü�� ������� ������)
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