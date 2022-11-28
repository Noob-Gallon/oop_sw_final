#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
	MyClass(const char* str) {
		int len = strlen(str) + 1; // 6...
		stored = new char[len];
		strcpy(stored, str); // null을 자동으로 채워줌? a b c d e
	}
	MyClass(const MyClass& _other) {
		int len = strlen(_other.stored);
		this->stored = new char[len+1];
		strcpy(this->stored, _other.stored);
	}
	~MyClass() {
		cout << "Destructor Called!" << endl;
		delete[] stored;
	}
	void printStored() {

		for (int i = 0; i < strlen(stored); i++) {
			cout << stored[i];
		}

		cout << endl;
	}

private:
	char* stored;
};

// strcpy는 남는 공간이 있으면 자동으로 \0로 채워준다...
// 그러나, strncpy 는 남는 공간을 자동으로 \0로 채우지 않을 수도 있다...
// strlen은 \0을 포함한 길이가 아니다.

int main(void) {

	MyClass myClass1("abcde");
	cout << "myClass1" << endl;
	myClass1.printStored();

	{
		cout << "\nmyClass2" << endl;
		MyClass myClass2 = myClass1;
		myClass2.printStored();
	}

	cout << "\nmyClass1 again...\n";
	myClass1.printStored();

	return 0;
}