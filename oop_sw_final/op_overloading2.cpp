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
		return !(*this == _other); // == overloading 활용!
	}

	// postfix, prefix...
	// postfix : 모든 동작이 실행된 후에 증가되므로, 복사본을 넘긴다.
	MyVector operator++ (int) {
		cout << "postfix\n";
		MyVector temp = *this;
		this->x += 1;
		this->y += 1;

		return temp; // 복사해서 넘기므로, 살아남는다...
	}

	// prefix, 연산이 된 후 동작해야하므로, 원본을 넘긴다.
	MyVector& operator++ () {
		cout << "prefix\n";
		this->x += 1;
		this->y += 1;

		return *this;
	}
	void showValues() {
		cout << "x : " << this->x << ", y : " << y << endl;
	}

	// 대입 연산자 overloading... 왜 원본을 return해주나면,
	// x = y = z... 이와 같이 연쇄적으로 대입하는 경우를 대비해야 하기 때문이다.
	MyVector& operator= (const MyVector& _other) {
		cout << "대입 연산자\n";
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
	MyVector v2 = ++(v1++); // 이런 식으로 주면, v1++가 먼저 동작하게 된다. 형태가 이상하므로, 대입 연산자가 invoke되지 않는다.
	// 그러면 원본은 2, 2. 반환된 복사본은 1, 1이다.
	// 그 상태에서 prefix가 복사본에 한 번 더 적용되면 복사본은 2, 2가 되고,
	// 원본은 postfix가 적용된 상태 그대로이므로, 2, 2이다.

	v2.showValues();
	v1.showValues();

	(++(++(++v1)));
	v1.showValues();

	MyVector v3 = (++((++(v1++))++)); // 이상한 형태가 오므로, 대입 연산자가 invoke되지 않는다.
	// 어찌됐든 postfix는 복사본을 반환하므로, 
	// 일단 postfix를 한 번 사용하면 더 이상 원본은 바뀌지 않는다.
	v3.showValues();
	v1.showValues();

	MyVector n1(10, 10);
	++(n1++);
	n1.showValues();
	(++n1)++; // n1은 13. 단, 여기서 return 되는 것은 12.
	n1.showValues();

	cout << "\n\n\n";

	MyVector a1(1, 1);
	MyVector a2(1, 1);
	MyVector a3(1, 1);

	// 대입 연산자, 두 배로 늘어남. 
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