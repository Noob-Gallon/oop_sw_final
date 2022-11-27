#include <iostream>

using namespace std;

class A {
public:
	int a, b;

public:
	A() {
		cout << "부모 생성자\n";
		a = 10;
		b = 20;
	}
	void showAB() {
		cout << a << ", " << b << endl;
	}
	~A() {
		cout << "부모 소멸자" << endl;
	}
};

class AA : public A {
public:
	int c;

public:
	void showABSum() {
		cout << a + b << endl;
	}

	AA() {
		cout << "자식 생성자\n";
	}
	~AA() {
		cout << "자식 소멸자" << endl;
	}
};


int main(void) {

	AA aa;
	// 생성자는 소멸자의 반대로 불러진다.

	return 0;
}