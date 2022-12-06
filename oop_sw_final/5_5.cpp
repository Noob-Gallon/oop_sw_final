#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
	// 순수 가상 함수 speak 선언
	virtual void speak() = 0;
	virtual ~Animal() {}
};

// Animal을 상속받아 speak를 정의함.
class Dog : public Animal {
public:
	void speak() {
		cout << "멍멍!" << endl;
	}
};

// Animal을 상속받아 speak를 정의함.
class Cat : public Animal {
	void speak() {
		cout << "야옹!" << endl;
	}
};

int main(void) {

	// Animal* 포인터를 보관하는 vector 선언.
	// upcasting을 통해 speak()를 수행할 수 있음.
	// virtual method이므로, 자식 클래스에서 정의된
	// speak() 수행 가능.
	vector<Animal*> barn;
	Dog dog;
	Cat cat;

	barn.push_back(&dog);
	barn.push_back(&cat);

	for (auto i = barn.begin(); i != barn.end(); i++) {
		(*i)->speak();
	}

	return 0;
}