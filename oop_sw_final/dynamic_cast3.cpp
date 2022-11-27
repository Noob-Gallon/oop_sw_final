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

// 주요 개념
// 1. 부모 클래스의 포인터로 자식 클래스를 가리킬 수 있다. upcasting
// 2. 현재 p는 Child 클래스를 가리키고 있지만, virtual로 선언되어 있지 않기 때문에
// show는 Parent를 출력한다.
// 3. p가 실제로 가리키는 클래스는 Child 클래스이므로, dynamic_cast를 통해 다운 캐스팅이 가능하다.
// 그래서 이전에 Parent를 가리킬 때는 Child*로 downcasting이 불가능했음?

int main(void) {

	Parent* p = new Child(); // Parent, Child constructor가 불림.
	p->show(); // show()는 virtual이 아니므로, Child를 가리키고 있지만 Parent를 출력함...
	// 만약 show()를 virtual로 선언한다면, 당연하게도 Child가 불림.
	cout << "-----\n";

	Child* c = dynamic_cast<Child*>(p); // 현재 p는 Child를 가리키고 있으므로, dynamic_cast 가능...

	if (c == nullptr) {
		cout << "Runtime error\n";
	}
	else {
		p->show();
	}

	delete p;

	return 0;
}