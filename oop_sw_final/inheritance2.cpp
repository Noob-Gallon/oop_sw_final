#include <iostream>

using namespace std;

class A {
public:
	int a, b;

public:
	A() {
		cout << "�θ� ������\n";
		a = 10;
		b = 20;
	}
	void showAB() {
		cout << a << ", " << b << endl;
	}
	~A() {
		cout << "�θ� �Ҹ���" << endl;
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
		cout << "�ڽ� ������\n";
	}
	~AA() {
		cout << "�ڽ� �Ҹ���" << endl;
	}
};


int main(void) {

	AA aa;
	// �����ڴ� �Ҹ����� �ݴ�� �ҷ�����.

	return 0;
}