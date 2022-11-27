#include <iostream>

using namespace std;

class MyUniquePtr {
public:
	MyUniquePtr(int* _p) : p(_p) {
		cout << "memory allocate p\n";
	}
	~MyUniquePtr() {
		
		if (p != nullptr) {
			cout << "delete p\n";
			delete[] p; // 배열인지 아닌지 체크할 수 있나?
		}
	}
	void setValue(int _idx, int _value) {
		this->p[_idx] = _value;
	}
	int& operator* (void) {
		return *p;
	}

public:
	int* p = nullptr;

};

int main(void) {

	unique_ptr<int> p(new int(40)); // 하나의 변수. 값 바로 적용 가능.
	// unique_ptr, delete가 필요없다.

	MyUniquePtr p1(new int[10]); // 배열로 선언, delete[]... 생성자에 바로 주소를 넣어준다.
	
	for (int i = 0; i < 10; i++) {
		p1.setValue(i, i);
	}

	for (int i = 0; i < 10; i++) {
		cout << "p1[" << i << "] : " << p1.p[i] << endl;
	}

	MyUniquePtr p2(new int(10));
	cout << *p2 << endl; // p2는 내가 임의로 만들어준 객체이다. 스마트 포인터의 기능을 하는 객체일 뿐이다.
	// 따라서, *p2를 해주려면, * overloading을 해줘야 한다...

	// p1과 p2가 destructor가 불려지면서 자동으로 delete된다...

	return 0;
}