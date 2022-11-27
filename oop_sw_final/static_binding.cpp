#include <iostream>

using namespace std;

class Animal {
public:
	virtual void speak() {
		cout << "Animal!\n";
	}
};

class Dog : public Animal {
public:
	void speak() {
		cout << "Dog!\n";
	}
};

int main(void) {

	Animal* a = new Animal();
	a->speak(); // Animal!

	Dog* d = new Dog();
	d->speak(); // Dog!

	delete a, d;
	
	Animal* a2 = new Dog(); // upcasting
	a2->speak(); // Animal! virtual로 선언하지 않는다면, upcasting에서는
	// Animal* type의 class에 선언된 speak()가 실행된다.
	// Animal의 speak을 virtual로 선언한다면, Dog!가 나온다.

	return 0;
}