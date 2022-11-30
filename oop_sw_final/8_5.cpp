#include <iostream>
#include <map>
#include <string>

using namespace std;

class Student {
private:
	string name;
	string address;
	string ID;
	string tel;

public:
	// 만약 default value를 설정해주지 않으면,
	// 적절한 기본 생성자가 없다고 나옴...
	Student(string _name, string _address, string _ID, string _tel);
	//Student(string _name = "홍길동", string _address ="", string _ID = "00000000", string _tel = "");
	Student();
	void showInfo();
};

class Menu {
private:
	map<string, Student> list;
	bool exitCheck = false;

public:
	void printMenu();

	// 현재 문제에서는 검색은 학생의 이름으로만 할 수 있다고 하므로
	// 동명이인에 대해서는 처리하지 않는다고 가정.
	// 만약 동명이인에 대해서 처리가 필요하다면 이름 뿐만 아니라
	// unique한 추가적인 정보 (예를 들면, ID) 등이 주어져야 한다.
	void addStudent();
	void searchStudent();
	void deleteStudent();
	void printAllStudent();
	void exitProgram();
	bool checkExitBool();
};

int main(void) {

	Menu menu;

	while (!menu.checkExitBool()) {
		menu.printMenu();
	}

	return 0;
}

/// 클래스 구현 ///

Student::Student(string _name, string _address, string _ID, string _tel) {
	this->name = _name;
	this->address = _address;
	this->ID = _ID;
	this->tel = _tel;
}

Student::Student() {
	// do nothing...
}

void Student::showInfo() {
	cout << "이름: " << this->name << endl;
	cout << "주소: " << this->address << endl;
	cout << "학번: " << this->ID << endl;
	cout << "전화번호: " << this->tel << endl;
	cout << endl;
}

void Menu::printMenu() {
	cout << "===========================" << endl;
	cout << "추가: 1, 검색: 2, 삭제: 3, 모두보기: 4, 종료: 5" << endl;
	cout << "===========================" << endl;

	int input;
	cout << "하나를 선택하세요. : " << endl;
	cin >> input;
	cin.ignore();

	switch (input) {
	case 1:
		addStudent();
		break;
	case 2:
		searchStudent();
		break;
	case 3:
		deleteStudent();
		break;
	case 4:
		printAllStudent();
		break;
	case 5:
		exitProgram();
		break;
	default:
		cout << "잘못된 입력입니다!" << endl;
	}
}

void Menu::addStudent() {

	string name;
	string address;
	string ID;
	string tel;

	cout << "이름 : ";
	getline(cin, name);

	cout << "주소 : ";
	getline(cin, address);

	cout << "학번 : ";
	getline(cin, ID);

	cout << "전화번호 : ";
	getline(cin, tel);

	Student student(name, address, ID, tel);
	list[name] = student;
}

void Menu::searchStudent() {

	string name;
	cout << "검색할 학생의 이름을 입력하세요. : ";
	getline(cin, name);

	Student& std = list[name];
	std.showInfo();
}

void Menu::deleteStudent() {

	string name;
	cout << "목록에서 제거할 학생의 이름을 입력하세요. : ";
	getline(cin, name);

	list.erase(name);
}

void Menu::printAllStudent() {

	// map 구조이므로, 기본은 이름의 오름차순이다.
	for (auto i = list.begin(); i != list.end(); i++) {

		((*i).second).showInfo();
	}
}

void Menu::exitProgram() {
	this->exitCheck = true;
}

bool Menu::checkExitBool() {
	return this->exitCheck;
}