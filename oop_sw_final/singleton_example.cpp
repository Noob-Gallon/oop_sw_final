#include <iostream>

using namespace std;

class SingletonClass {
public:
	static SingletonClass* getInstance() {
		if (instance == nullptr) {
			instance = new SingletonClass();
		}

		return instance;
	}
	void setValue(int _value) {
		this->value = _value;
	}
	void showValue() {
		cout << "value : " << this->value << endl;
	}

private:
	int value;

private:
	SingletonClass() {}
	static SingletonClass* instance;
};

SingletonClass* SingletonClass::instance = nullptr;

int main(void) {

	SingletonClass* p1 = SingletonClass::getInstance();
	SingletonClass* p2 = SingletonClass::getInstance();

	p1->setValue(10);
	p1->showValue();
	p2->showValue();

	return 0;
}