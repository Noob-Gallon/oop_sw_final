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
	a2->speak(); // Animal! virtual�� �������� �ʴ´ٸ�, upcasting������
	// Animal* type�� class�� ����� speak()�� ����ȴ�.
	// Animal�� speak�� virtual�� �����Ѵٸ�, Dog!�� ���´�.

	return 0;
}