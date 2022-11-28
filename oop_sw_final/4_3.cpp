#include <iostream>

using namespace std;

class Employee {
protected:
	string name;
	int salary;

public:
	void computeSalary() {
		cout << "이름: " << name << endl;
		cout << "월급: " << salary << endl;
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
		cout << "보너스: " << bonus << endl;
		cout << "전체 급여: " << total << endl;

		return total;
	}
};

int main(void) {

	Manager manager("김철수", 200, 100);

	int total_salary = manager.computeSalary();

	return 0;
}