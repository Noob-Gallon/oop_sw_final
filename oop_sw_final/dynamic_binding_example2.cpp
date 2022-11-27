#include <iostream>

using namespace std;

class P2 {
public:
	virtual ~P2() {
		cout << "P2 소멸자\n";
	}
};

class C2 : public P2 {
public:
	int* p;
	C2() {
		p = new int[40]; // int 40칸 동적 할당...
	}
	~C2() {
		delete[] p;
		cout << "C2 소멸자\n";
	}
};

int main(void) {

	C2* c = new C2();
	delete c; // P2의 소멸자를 virtual로 만들지 않아도, 전혀 문제없이 동작한다.

	P2* p = new C2(); // upcasting...
	delete p; // 만약, 소멸자에 virtual이 선언되어 있지 않다면,
	// 정상적으로 ~C2()를 불러올 수 없다.
	// 따라서 memory leak이 발생하게 된다.
	// 이를 막기 위해 C++에서는 모든 소멸자에 virtual을 선언해주는 것이 좋다.

	return 0;
}