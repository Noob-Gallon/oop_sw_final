#include <iostream>

using namespace std;

class Circle {
public:
	int x, y;
	int radius;
	Circle() : x(0), y(0), radius(0) {}
	Circle(int _x, int _y, int _r) : x(_x), y(_y), radius(_r) {
		cout << "Circle(" << _r << "), ������" << endl;
	}
	void print() {
		cout << "Circle(" << radius << ")" << endl;
	}
	Circle(const Circle& _other) {
		this->x = _other.x;
		this->y = _other.y;
		this->radius = _other.radius;
		cout << "���� ������" << endl;
	}
	Circle& operator=(const Circle& _other) {
		cout << "���� ������" << endl;
		Circle circle(_other.x, _other.y, _other.radius); // �����ڰ� �Ҹ�.
		return circle;
	}

	/*MyValue& operator= (const MyValue& other) {
		this->x = 2 * other.x;
		return *this;
	}*/
};

// parameter�� �Ѿ���� c1�� c2�� ����Ǵ� ���̹Ƿ�,
// ���� ���� �����ڰ� ���۵ȴ�.
// �׸��� �� ū ���� return�� ����, return�Ǵ� Circle��
// main�� ���纻�� �Ѿ�� �ȴ�.
// ���� ���� �����ڰ� ���۵ȴ�.
Circle getLagerCircle(Circle& c1, Circle& c2) {
	cout << "�� ū ���� ������ ����." << endl;
	if (c1.radius >= c2.radius) {
		cout << "before return\n";
		return c1;
	}
	cout << "before return\n";
	return c2;
}

int main(void) {

	Circle c1(0, 0, 10);	// (0, 0), r = 10
	Circle c2(0, 0, 20); // (0, 0), r = 100
	Circle c_check;
	c_check = c1; // �� �������ΰ�?
	//getLagerCircle(c1, c2); // �̰� ��ü�ε�, ���� �����ڸ� ȣ���Ѵ�.
	// ���� return�� &�� �Ѵٸ�, ���� �����ڸ� ȣ������ �ʴ´�.
	
	cout << "getLargerCircle" << endl;
	Circle c3 = getLagerCircle(c1, c2);
	// c3.print();
	/*cout << "c4 = c3" << endl;
	Circle c4 = c3;
	c4.print();*/

	return 0;
}