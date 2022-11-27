#include <iostream>

using namespace std;

class A {
private:
	int a;

public:
	friend void showA(A& _a);
	// 이처럼, 클래스 내부에 friend function을 선언하면
	// 해당 function의 구현부에서는 클래스의 private에도 접근이 가능하다.
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
		// friend class B가 A에 선언되었으므로,
		// B에서 A의 private 변수에 접근할 수 있다...
	}
};

int main(void) {

	A obj(20);
	showA(obj);

	B objB;
	objB.showA(obj);

	return 0;
}