#include <iostream>
#include <string>

using namespace std;

// MyClass에 상속할 부모 클래스 Student 정의
class Student {
private:
	string name;

public:
	Student(string _name = "") : name(_name) {
	}
	// getter와 setter 정의
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
	Student* p = nullptr; // 받아온 학급 수로 동적할당한다. 소멸자에서 해제 필요.
	int size; // 생성자로 학급의 수를 받아온다.

public:
	// 생성자로 입력받은 수만큼 학생의 instance를 동적할당 받은 배열에 추가.
	MyClass(string _className, int _size = 0) : className(_className), size(_size) {
		p = new Student[_size];

		cout << "학급 " << _className << "의 학생들은 다음과 같다." << endl;
		string name;

		for (int i = 0; i < _size; i++) {
			cout << "학생 #" << i + 1 << ": ";
			getline(cin, name);
			
			Student stu;
			stu.setName(name);
			p[i] = stu;
		}
	}
	// 소멸자에서 동적할당된 배열을 해제
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
			cout << "학생 #" << i + 1 << ": " << p[i].getName() << endl;
		}
	}
};

int main(void) {

	MyClass myClass("special", 3);
	myClass.printStudentsList();

	return 0;
}