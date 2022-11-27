#include <iostream>

using namespace std;

class Parent {
public:
	int x;
	virtual ~Parent() {

	}
};

class Child : public Parent {
public:
	int y;
	virtual ~Child() {

	}
};

int main(void) {

	Parent* p = new Parent();
	Child* c = dynamic_cast<Child*>(p);
	// dynamic cast는 Parent에 virtual이 있어야 사용 가능.
	// dynamic cast는 에러가 발생할 확률이 높으면 casting이 되지 않고
	// nullptr을 반환한다.
	// 위와 같은 경우는 에러가 발생할 확률이 높기 때문에
	// casting을 하지 않고, nullptr을 반환한다.
	
	if (c == nullptr) {
		cout << "nullptr! error...\n";
	}

	Parent* p2 = (Parent*)(new Child()); // 일종의 upcasting...
	Child* c2 = dynamic_cast<Child*>(p2); 

	if (c2 == nullptr) {
		cout << "nullptr! error...\n";
	}

	return 0;
}