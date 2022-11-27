#include <iostream>

using namespace std;

class Parent {
public:
	int x;
	Parent() {
		cout << "Parent constructor\n";
	}
	virtual ~Parent() {
		cout << "Parent destructor\n";
	}
	void show() {
		cout << "Parent\n";
	}
};

class Child : public Parent {
public:
	int y;
	Child() {
		cout << "Child constructor\n";
	}
	virtual ~Child() {
		cout << "Child destructor\n";
	}
	void show() {
		cout << "Child\n";
	}
};

// dynamic cast
// 부모 클래스의 포인터에서 자식 클래스의 포인터로
// 다운캐스팅 해주는 연산자이다.

int main(void) {

	Parent* p = new Parent();
	p->show();
	
	Child* c = dynamic_cast<Child*>(p);

	if (c == nullptr) {
		cout << "Runtime error\n";
	}
	else {
		p->show();
	}

	delete p;

	return 0;
}