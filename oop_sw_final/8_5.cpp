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
	// Student(string _name = "ȫ�浿", string _address ="", string _ID = "00000000", string _tel = "");
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
	// Student Ŭ������ �����ϱ� ���� map�� ����.
	// map�� key�� string���� �ϸ�, �л��� �̸��� key�� �����Ѵ�.
	// value�δ� Student class�� ��ü�� �����Ѵ�.
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

// Main �Լ��� Ŭ������ instance�� �����ϰ�,
// ���� ������ ���۽�Ų��.
int main(void) {

	Menu menu;

	// ����ڰ� exit�� �������� �ʾ����� ����ؼ� ���۽�Ų��.
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

// �л��� ���� ���
void Student::showInfo() {
	cout << "�̸�: " << this->name << endl;
	cout << "�ּ�: " << this->address << endl;
	cout << "�й�: " << this->ID << endl;
	cout << "��ȭ��ȣ: " << this->tel << endl;
	cout << endl;
}

// �޴��� ���
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

// �л��� map�� �߰��Ѵ�.
// key�� �л��� �̸����� ����.
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

// �л��� �˻��Ѵ�.
void Menu::searchStudent() {

	string name;
	cout << "�˻��� �л��� �̸��� �Է��ϼ���. : ";
	getline(cin, name);

	// �л��� ���� ���� �����Ƿ�,
	// find�� �̿��� �л��� iterator�� ���,
	// iterator�� end��� �л��� ���� ����̱� ������
	// ������� �ʴ´�.
	auto it = list.find(name);
	if (it == list.end()) {
		cout << name << " �л��� �����ϴ�." << endl;
	} else {
		(*it).second.showInfo();
	}
}

// �л��� �����Ѵ�.
// map�̹Ƿ�, erase�� �̿��� ����
void Menu::deleteStudent() {

	string name;
	cout << "��Ͽ��� ������ �л��� �̸��� �Է��ϼ���. : ";
	getline(cin, name);

	list.erase(name);
}

// ��� �л� ���
void Menu::printAllStudent() {

	// map �����̹Ƿ�, �⺻�� �̸��� ���������̴�.
	for (auto i = list.begin(); i != list.end(); i++) {

		((*i).second).showInfo();
	}
}

// ���α׷��� �����Ŵ.
void Menu::exitProgram() {
	this->exitCheck = true;
}

// ���� exitCheck ���¸� return. �ݺ����� condition�� ���.
bool Menu::checkExitBool() {
	return this->exitCheck;
}