#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
	virtual void speak() = 0;
	virtual ~Animal() {} // 捞繁 巴篮 恐 秦林绰 吧鳖?
};

class Dog : public Animal {
public:
	void speak() {
		cout << "港港!" << endl;
	}
};

class Cat : public Animal {
	void speak() {
		cout << "具克!" << endl;
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