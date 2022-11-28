#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
	virtual void speak() = 0;
	virtual ~Animal() {} // �̷� ���� �� ���ִ� �ɱ�?
};

class Dog : public Animal {
public:
	void speak() {
		cout << "�۸�!" << endl;
	}
};

class Cat : public Animal {
	void speak() {
		cout << "�߿�!" << endl;
	}
};

int main(void) {

	vector<Animal*> animal;
	Dog dog;
	Cat cat;

	animal.push_back(&dog);
	animal.push_back(&cat);

	for (auto i = animal.begin(); i != animal.end(); i++) {
		(*i)->speak();
	}

	return 0;
}