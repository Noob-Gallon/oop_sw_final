#include <iostream>

using namespace std;

class Parent {
public:
	int x;
};

class Child : public Parent {
public:
	int y;
};

int main(void) {

	// superclass type pointer로
	// subclass의 instance를 가리키는 것.
	// 이렇게 하면 Child에서 선언된 메모리 공간은
	// 참조할 수 없고, Parent에 포함된 것만 참조 가능...
	Parent* p = new Child();

	p->x = 10;
	// p->y = 20; // 가리킬 수 없음...

	delete p;

	Parent* p2 = new Parent();
	Child* c = (Child*)p2; 
	// type casting을 이용해 Parent* 타입의 포인터를
	// Child*로 바꿔버린다. 이러면 사용이 가능하지만,
	// 만약 c로 Child 내에 선언된 변수(memory)를 참조하면
	// 소리소문 없이 시스템이 망가진다... (에러 안남)
	c->x = 10;
	cout << c->x << endl;

	return 0;
}