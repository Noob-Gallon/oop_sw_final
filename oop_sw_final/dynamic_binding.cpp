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
	a->speak(); // virtual�̹Ƿ�, Dog!

	Dog d;
	Animal& aa = d; // reference type���ε� ����.
	aa.speak(); // virtual�̹Ƿ� ���������� Dog�� ���ð�.

	// �� ������ a2 ��ü�� Animal�� speak�� ������ �ǹǷ�,
	// virtual�� ����� speak�� ����ص� Dog!�� �ҷ��� �� ����.
	Dog d2;
	Animal a2 = d2;
	a2.speak();

	return 0;
}