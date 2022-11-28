#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
	MyClass(const char* str) {
		int len = strlen(str) + 1; // 6...
		stored = new char[len];
		strcpy(stored, str); // null�� �ڵ����� ä����? a b c d e
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

// strcpy�� ���� ������ ������ �ڵ����� \0�� ä���ش�...
// �׷���, strncpy �� ���� ������ �ڵ����� \0�� ä���� ���� ���� �ִ�...
// strlen�� \0�� ������ ���̰� �ƴϴ�.

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