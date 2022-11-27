#include <iostream>

using namespace std;

class A {
public:
	int a, b;

public:
	A() {
		a = 10;
		b = 20;
	}
	void showAB() {
		cout << a << ", " << b << endl;
	}
};

class AA : public A {
public:
	int c;

public:
	void showABSum() {
		cout << a + b << endl;
	}
};

class AAA : public AA {
public:
};

int main(void) {

	AAA aaa;
	aaa.showAB();
	aaa.showABSum();
	aaa.a = 100;
	aaa.b = 200;
	aaa.c = 300;

	AA aa;
	cout << aa.a << ", " << aa.b << endl;
	aa.showAB();
	aa.showABSum();

	A a;
	a.showAB();

	return 0;
}