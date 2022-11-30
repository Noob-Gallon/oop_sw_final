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
	// ���� default value�� ���������� ������,
	// ������ �⺻ �����ڰ� ���ٰ� ����...
	Student(string _name, string _address, string _ID, string _tel);
	//Student(string _name = "ȫ�浿", string _address ="", string _ID = "00000000", string _tel = "");
	Student();
	void showInfo();
};

class Menu {
private:
	map<string, Student> list;
	bool exitCheck = false;

public:
	void printMenu();

	// ���� ���������� �˻��� �л��� �̸����θ� �� �� �ִٰ� �ϹǷ�
	// �������ο� ���ؼ��� ó������ �ʴ´ٰ� ����.
	// ���� �������ο� ���ؼ� ó���� �ʿ��ϴٸ� �̸� �Ӹ� �ƴ϶�
	// unique�� �߰����� ���� (���� ���, ID) ���� �־����� �Ѵ�.
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

/// Ŭ���� ���� ///

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
	cout << "�̸�: " << this->name << endl;
	cout << "�ּ�: " << this->address << endl;
	cout << "�й�: " << this->ID << endl;
	cout << "��ȭ��ȣ: " << this->tel << endl;
	cout << endl;
}

void Menu::printMenu() {
	cout << "===========================" << endl;
	cout << "�߰�: 1, �˻�: 2, ����: 3, ��κ���: 4, ����: 5" << endl;
	cout << "===========================" << endl;

	int input;
	cout << "�ϳ��� �����ϼ���. : " << endl;
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
		cout << "�߸��� �Է��Դϴ�!" << endl;
	}
}

void Menu::addStudent() {

	string name;
	string address;
	string ID;
	string tel;

	cout << "�̸� : ";
	getline(cin, name);

	cout << "�ּ� : ";
	getline(cin, address);

	cout << "�й� : ";
	getline(cin, ID);

	cout << "��ȭ��ȣ : ";
	getline(cin, tel);

	Student student(name, address, ID, tel);
	list[name] = student;
}

void Menu::searchStudent() {

	string name;
	cout << "�˻��� �л��� �̸��� �Է��ϼ���. : ";
	getline(cin, name);

	Student& std = list[name];
	std.showInfo();
}

void Menu::deleteStudent() {

	string name;
	cout << "��Ͽ��� ������ �л��� �̸��� �Է��ϼ���. : ";
	getline(cin, name);

	list.erase(name);
}

void Menu::printAllStudent() {

	// map �����̹Ƿ�, �⺻�� �̸��� ���������̴�.
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