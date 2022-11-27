#include <iostream>

using namespace std;

class Parent {
public:
	void whoareyou() {
		cout << "Parent" << endl;
	}
};

class Child : public Parent {
public:
	void whoareyou() {
		// super call, 상속을 받으면
		// Child 안에는 Parent에 대한 메모리 공간도
		// 잡히기 때문에 namespace를 지정해서
		// 아래와 같이 call할 수 있음...
		Parent::whoareyou();
		cout << "child" << endl;
	}
};

int main(void) {

	Child child;
	child.whoareyou();
	child.Parent::whoareyou(); // method overriding.

	return 0;
}