#include <iostream>

using namespace std;

class Employee {
protected:
	string name;
	int salary;

public:
	void computeSalary() {
		cout << "�̸�: " << name << endl;
		cout << "����: " << salary << endl;
	}
	Employee(string _name, int _salary) : name(_name), salary(_salary) {
	}
};

class Manager : public Employee {
private :
	int bonus;

public:
	Manager(string _name, int _salary, int _bonus) : Employee(_name, _salary), bonus(_bonus) {
	}
	int computeSalary() {

		int total = salary + bonus;

		Employee::computeSalary();
		cout << "���ʽ�: " << bonus << endl;
		cout << "��ü �޿�: " << total << endl;

		return total;
	}
};

int main(void) {

	Manager manager("��ö��", 200, 100);

	int total_salary = manager.computeSalary();

	return 0;
}