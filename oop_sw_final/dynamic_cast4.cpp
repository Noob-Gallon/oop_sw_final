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

int main(void) {

	Child* c = new Child(); // 평범한 casting.
	// Parent와 Child는 상속관계이므로, new로 instance 생성시
	// Parent->Child 순으로 생성자가 불림.

	c->show(); // Child type 포인터로 객체를 가리키므로, Child가 나온다.
	cout << "-----\n";

	Parent* p = static_cast<Parent*>(c); // Parent 포인터 p가 Child를 가리키도록 static_cast(upcasting)...
	p->show(); // 현재 show()는 virtual method가 아니므로 Parent가 나온다.
	// 왜냐면, Parent type 포인터로 가리키고 있기 때문...
	// 만약 virtual을 적용하면? Child가 나올 것.

	delete p; // p는 Parent type이므로, destructor는 Parent를 부른다.
	// 이렇게 되면, 상속받은 클래스의 destructor가 불리지 않으므로
	// virtual을 붙여줘야 한다. 그러면 Child -> Parent 순으로
	// destructor가 불린다.

	return 0;
}