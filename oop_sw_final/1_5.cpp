#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string name;

public:
	Student(string _name = "") : name(_name) {
	}
	string getName() {
		return this->name;
	}
	void setName(string _name) {
		this->name = _name;
	}
};

class MyClass {
private:
	string className;
	Student* p = nullptr; // �޾ƿ� �б� ���� �����Ҵ��Ѵ�. �Ҹ��ڿ��� ���� �ʿ�.
	int size; // �����ڷ� �б��� ���� �޾ƿ´�.

public:
	MyClass(string _className, int _size = 0) : className(_className), size(_size) {
		p = new Student[_size];

		cout << "�б� " << _className << "�� �л����� ������ ����." << endl;
		string name;

		for (int i = 0; i < _size; i++) {
			cout << "�л� #" << i + 1 << ": ";
			getline(cin, name);
			
			Student stu;
			stu.setName(name);
			p[i] = stu;
		}
	}
	~MyClass() {
		if (p != nullptr) {
			if (size > 1) {
				delete[] p;
			}
			else if (size == 1) {
				delete p;
			}
		}

		cout << "Safe Delete..." << endl;
	}
	void printStudentsList() {
		
		cout << "\n\n\n";
		for (int i = 0; i < size; i++) {
			cout << "�л� #" << i + 1 << ": " << p[i].getName() << endl;
		}
	}
};

int main(void) {

	MyClass myClass("special", 3);
	myClass.printStudentsList();

	return 0;
}