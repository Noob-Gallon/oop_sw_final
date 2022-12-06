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
	Student(string _name, string _address, string _ID, string _tel);
	// Student(string _name = "홍길동", string _address ="", string _ID = "00000000", string _tel = "");
	Student();
	void showInfo();
	string getName() {
		return name;
	}
	string getAddress() {
		return address;
	}
	string getID() {
		return ID;
	}
	string getTel() {
		return tel;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setID(string ID) {
		this->ID = ID;
	}
	void setTel(string tel) {
		this->tel = tel;
	}
};

class Menu {
private:
	// Student 클래스를 저장하기 위해 map을 선언.
	// map은 key를 string으로 하며, 학생의 이름을 key로 지정한다.
	// value로는 Student class의 객체를 저장한다.
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

// Main 함수는 클래스의 instance를 선언하고,
// 무한 루프를 동작시킨다.
int main(void) {

	Menu menu;

	// 사용자가 exit를 선택하지 않았으면 계속해서 동작시킨다.
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

// 학생의 정보 출력
void Student::showInfo() {
	cout << "이름: " << this->name << endl;
	cout << "주소: " << this->address << endl;
	cout << "학번: " << this->ID << endl;
	cout << "전화번호: " << this->tel << endl;
	cout << endl;
}

// 메뉴를 출력
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

// 학생을 map에 추가한다.
// key는 학생의 이름으로 지정.
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

// 학생을 검색한다.
void Menu::searchStudent() {

	string name;
	cout << "검색할 학생의 이름을 입력하세요. : ";
	getline(cin, name);

	// 학생이 없을 수도 있으므로,
	// find를 이용해 학생의 iterator를 얻고,
	// iterator가 end라면 학생이 없는 경우이기 때문에
	// 출력하지 않는다.
	auto it = list.find(name);
	if (it == list.end()) {
		cout << name << " 학생이 없습니다." << endl;
	} else {
		(*it).second.showInfo();
	}
}

// 학생을 제거한다.
// map이므로, erase를 이용해 제거
void Menu::deleteStudent() {

	string name;
	cout << "목록에서 제거할 학생의 이름을 입력하세요. : ";
	getline(cin, name);

	list.erase(name);
}

// 모든 학생 출력
void Menu::printAllStudent() {

	// map 구조이므로, 기본은 이름의 오름차순이다.
	for (auto i = list.begin(); i != list.end(); i++) {

		((*i).second).showInfo();
	}
}

// 프로그램을 종료시킴.
void Menu::exitProgram() {
	this->exitCheck = true;
}

// 현재 exitCheck 상태를 return. 반복문의 condition에 사용.
bool Menu::checkExitBool() {
	return this->exitCheck;
}