#include <iostream>

using namespace std;

class MyOnlyClass {
public:
	static MyOnlyClass* getInstance() {
		if (instance == nullptr) {
			instance = new MyOnlyClass();
		}

		return instance;
	}
	void del_instance() { // �̰��� �ݵ�� instance�� �����ؾ߸� ���� �� �����Ƿ�, static���� �������� ���Ѵ�.
		
		if (this->instance == nullptr) {
			return;
		}

		delete this->instance;
	}
	void setValue(int _value) {
		this->secretValue = _value;
	}
	void showValue() const {
		cout << "value : " << this->secretValue << endl;
	}

private:
	MyOnlyClass() {}
	static MyOnlyClass* instance;
	int secretValue;
};

MyOnlyClass* MyOnlyClass::instance = nullptr;

int main(void) {

	MyOnlyClass* p1 = MyOnlyClass::getInstance();
	p1->setValue(10);
	p1->showValue();

	MyOnlyClass* p2 = MyOnlyClass::getInstance();
	p2->showValue();
	p2->setValue(20);
	p1->showValue();
	p2->showValue();

	p1->del_instance();

	return 0;
}