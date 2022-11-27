#include <iostream>

using namespace std;

class MyVector {
private:
	int x, y;

public:
	MyVector(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
	bool operator== (MyVector& _other) {
		return ((this->x == _other.x) && (this->y == _other.y));
	}
	bool operator!= (MyVector& _other) {
		return !(*this == _other); // == overloading Ȱ��!
	}

	// postfix, prefix...
	// postfix : ��� ������ ����� �Ŀ� �����ǹǷ�, ���纻�� �ѱ��.
	MyVector operator++ (int) {
		cout << "postfix\n";
		MyVector temp = *this;
		this->x += 1;
		this->y += 1;

		return temp; // �����ؼ� �ѱ�Ƿ�, ��Ƴ��´�...
	}

	// prefix, ������ �� �� �����ؾ��ϹǷ�, ������ �ѱ��.
	MyVector& operator++ () {
		cout << "prefix\n";
		this->x += 1;
		this->y += 1;

		return *this;
	}
	void showValues() {
		cout << "x : " << this->x << ", y : " << y << endl;
	}

	// ���� ������ overloading... �� ������ return���ֳ���,
	// x = y = z... �̿� ���� ���������� �����ϴ� ��츦 ����ؾ� �ϱ� �����̴�.
	MyVector& operator= (const MyVector& _other) {
		cout << "���� ������\n";
		this->x = _other.x * 2;
		this->y = _other.y * 2;

		return *this;
	}
	int operator[] (int _idx) {
		if (_idx > 10) {
			return 10;
		}
		else {
			return 0;
		}
	}

};

int main(void) {

	MyVector v1(1, 1);
	MyVector v2 = ++(v1++); // �̷� ������ �ָ�, v1++�� ���� �����ϰ� �ȴ�. ���°� �̻��ϹǷ�, ���� �����ڰ� invoke���� �ʴ´�.
	// �׷��� ������ 2, 2. ��ȯ�� ���纻�� 1, 1�̴�.
	// �� ���¿��� prefix�� ���纻�� �� �� �� ����Ǹ� ���纻�� 2, 2�� �ǰ�,
	// ������ postfix�� ����� ���� �״���̹Ƿ�, 2, 2�̴�.

	v2.showValues();
	v1.showValues();

	(++(++(++v1)));
	v1.showValues();

	MyVector v3 = (++((++(v1++))++)); // �̻��� ���°� ���Ƿ�, ���� �����ڰ� invoke���� �ʴ´�.
	// ����Ƶ� postfix�� ���纻�� ��ȯ�ϹǷ�, 
	// �ϴ� postfix�� �� �� ����ϸ� �� �̻� ������ �ٲ��� �ʴ´�.
	v3.showValues();
	v1.showValues();

	MyVector n1(10, 10);
	++(n1++);
	n1.showValues();
	(++n1)++; // n1�� 13. ��, ���⼭ return �Ǵ� ���� 12.
	n1.showValues();

	cout << "\n\n\n";

	MyVector a1(1, 1);
	MyVector a2(1, 1);
	MyVector a3(1, 1);

	// ���� ������, �� ��� �þ. 
	a3 = a2 = a1;
	a3.showValues(); // 4
	a2.showValues(); // 2
	a1.showValues(); // 1

	int value = a1[15];
	cout << value << endl;

	value = a1[5];
	cout << value << endl;

	MyVector ex1(10, 10);
	MyVector ex2 = ex1++;
	ex2.showValues();
	ex1.showValues();

	return 0;
}