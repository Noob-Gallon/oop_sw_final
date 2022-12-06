#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// MyClass는 전달받은 string을 복사해서
// MyClass 내부의 변수에 저장해야하므로,
// 생성자에서 동적할당을 받아 strcpy로 복사해준다.
class MyClass {
public:
	MyClass(const char* str) {
		int len = strlen(str) + 1;
		stored = new char[len];
		strcpy(stored, str); // strcpy는 공간이 남아있으면 copy한 후, 뒤에 \0을 자동으로 채워줌.
	}
	// 복사 생성자를 정의해서 복사가 올바르게 이루어지도록 한다.
	MyClass(const MyClass& _other) {
		int len = strlen(_other.stored);
		this->stored = new char[len+1];
		strcpy(this->stored, _other.stored);
	}
	// 소멸자에서 동적할당 받은 메모리 해제
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

	// 소멸자에서 메모리 해제가 올바르게 동작하는지 체크
	{
		cout << "\nmyClass2" << endl;
		MyClass myClass2 = myClass1;
		myClass2.printStored();
	}

	cout << "\nmyClass1 again...\n";
	myClass1.printStored();

	return 0;
}