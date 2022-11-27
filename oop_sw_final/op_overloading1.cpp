#include <iostream>

using namespace std;

class MyVector {
public:
	MyVector(int _x, int _y) : x(_x), y(_y) {
		cout << "constructor invoked...\n";
	}
	MyVector(){}
	void showXY() {
		cout << "x : " << x << ", y : " << y << endl;
	}
	void setXY(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
	// + overloading
	// + overloading�� �ݵ�� ���� ��ȯ���־�� �Ѵ�.
	// ���ο� ������ ���� ���, �Ǵ� cout���� ����ϴ� ��쿡 �ʿ��ϴ�? => �̷� ���� ��� �ؾߵ���?
	// overloading ���� ���� �ʿ�.
	MyVector operator+(const MyVector& _other) { 
		// parameter�� �Ѿ�� Class�� private���� ���� ����?
		// �װ� �ƴ϶�, �Ѿ�� ���ڵ� �ᱹ MyVector Ŭ�����̰�,
		// �̰��� MyVector class�� �����̹Ƿ� public���� �����ϴ� ��...

		MyVector temp(this->x + _other.x, this->y + _other.y);
		return temp;
	}
	// - overloading, + overloading�� �Ȱ���.
	MyVector operator-(const MyVector& _other) {

		MyVector temp(this->x - _other.x, this->y - _other.y);
		return temp;
	}
	MyVector operator*(const MyVector& _other) {

		MyVector temp(this->x * _other.x, this->y * _other.y);
		return temp;
	}
	MyVector operator/(const MyVector& _other) {

		if (_other.x == 0 || _other.y == 0) {
			MyVector temp(0, 0);
			return temp;
		}

		MyVector temp(this->x / _other.x, this->y / _other.y);
		return temp;
	}
	// ������ overloading�� ��Ģ������ return type�� pionter �������� �ϸ�,
	// pointer�� ���޹��� �� ����. ��, return type�� overloading�� �������� �����Ƿ�,
	// ���� ���� op_overloading�� ���� ���� ����...
	
	// argument�� pointer type���� ������.
	// const�̳� �ƴϳķε� overloading ����!
	MyVector* operator+(const MyVector* _other) {
		cout << "invoked!\n";
		MyVector* temp = new MyVector(this->x + _other->x, this->y + _other->y);
		// temp.showXY();

		return temp; // temp�� ������Ƿ�, �Ϲ������� ������ temp�� �ּҸ� �Ѱ��൵ ������ �߻���...
		// ����, �����Ҵ��� MyVector�� �Ѱ��ش�. �����Ҵ��ϸ�, MyVector�� delete�� ���� �ʴ� �̻�
		// ������� �ʱ� ������, �Լ� ������ �Ѿ���� �ּҰ� ������ ���� ������ �� �ִ�.
	}
	// �ٸ� ���� �Ȱ����Ƿ�, ������ ����... -, *, /
	bool operator==(const MyVector& _other) {
		
		return (this->x == _other.x) && (this->y == _other.y);
	}
	MyVector(const MyVector& _other) {
		this->x = _other.x;
		this->y = _other.y;
		cout << "copy constructor invoked!\n";
	}


private:
	int x, y;
};

int main(void) {

	MyVector v1(1, 1); // constructor
	MyVector v2(2, 2); // constructor

	MyVector v3 = v1 + v2; // ���ο��� constructor�� �ҷ��� temp ����. v3�� copy constructor invoked...
	v3.showXY();

	MyVector v4 = v2 - v1;
	v4.showXY();

	cout << boolalpha;
	cout << (v1 == v4) << endl;
	cout << (v1 == v2) << endl;

	MyVector v5 = v2 / v1;
	v5.showXY();

	MyVector v6(0, 0);
	MyVector v7 = v1 / v6;
	v7.showXY();

	cout << "---------------------------\n\n\n";

	MyVector n1(10, 10);
	MyVector n2(20, 20);
	MyVector* n3 = n2 + &n1;
	n3->showXY();

	MyVector* p1 = new MyVector();
	p1->setXY(50, 50);
	MyVector* p2 = n1 + p1;
	p2->showXY();

	return 0;
}