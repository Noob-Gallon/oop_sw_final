#include <iostream>

using namespace std;

class MyClass {
public:
	int x;
	int y;

	MyClass(int _x, int _y) : x(_x), y(_y) {
	}
	void showValues() const {
		cout << "x : " << x << ", y : " << y << endl;
	}
	void setValues(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
	static void setOnlyValue(int _value) {
		MyClass::only_value = _value;
	}
	static void showOnlyValue() {
		cout << "only_value : " << MyClass::only_value << endl;
	}

private:
	static int only_value;
};

int MyClass::only_value = 0;

int main(void) {

	MyClass::showOnlyValue();

	MyClass::setOnlyValue(10);
	MyClass::showOnlyValue();

	MyClass myClass(1, 2);
	myClass.showOnlyValue(); // Class의 namespace 뿐만 아니라, class의 객체로 static method에 접근할 수 있다.
	myClass.showValues();

	myClass.setOnlyValue(50);
	MyClass::showOnlyValue();
	myClass.showOnlyValue();

	return 0;
}