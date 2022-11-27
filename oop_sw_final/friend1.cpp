#include <iostream>

using namespace std;

class A {
private:
	int a;

public:
	friend void showA(A& _a);
	// ��ó��, Ŭ���� ���ο� friend function�� �����ϸ�
	// �ش� function�� �����ο����� Ŭ������ private���� ������ �����ϴ�.
	friend class B;

	A(int _a) : a(_a) {

	}
	void setA(int _a) {

		if (_a < 0) {
			a = 0;
		}
		else {
			a = _a;
		}
	}
};

void showA(A& _a) {
	_a.a = -666;
	cout << _a.a << endl;
}

class B {
public:
	B() {

	}
	void showA(A& _a) {
		cout << _a.a << endl; 
		// friend class B�� A�� ����Ǿ����Ƿ�,
		// B���� A�� private ������ ������ �� �ִ�...
	}
};

int main(void) {

	A obj(20);
	showA(obj);

	B objB;
	objB.showA(obj);

	return 0;
}