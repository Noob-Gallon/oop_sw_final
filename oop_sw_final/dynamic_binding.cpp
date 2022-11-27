#include <iostream>

using namespace std;

class Animal {
public:
	virtual void speak() {
		cout << "Animal!" << endl;
	}
};

class Dog : public Animal {
public:
	void speak() {
		cout << "Dog!" << endl;
	}
};

int main(void) {

	Animal* a = new Dog(); // upcasting
	a->speak(); // virtual이므로, Dog!

	Dog d;
	Animal& aa = d; // reference type으로도 가능.
	aa.speak(); // virtual이므로 마찬가지로 Dog가 나올것.

	// 이 예제는 a2 객체가 Animal의 speak만 가지게 되므로,
	// virtual로 선언된 speak을 사용해도 Dog!를 불러올 수 없다.
	Dog d2;
	Animal a2 = d2;
	a2.speak();

	return 0;
}