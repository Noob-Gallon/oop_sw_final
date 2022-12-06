#include <iostream>

using namespace std;

// Employee Ŭ������ �����ڸ� ����
// ��� ���� name, salary�� �ʱ�ȭ �Ѵ�.
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
	// getter, setter
	string getName() {
		return name;
	}
	int getSalary() {
		return salary;
	}
	void setName(string name) {
		this->name = name;
	}
	void setSalary(int salary) {
		this->salary = salary;
	}
};

// Employee Ŭ������ public ��ӹ޴´�.
// �߰����� ��� ���� bonus�� ������,
// �����ڸ� ���� ������ �ʱ�ȭ �Ѵ�.
class Manager : public Employee {
private :
	int bonus;

public:
	Manager(string _name, int _salary, int _bonus) : Employee(_name, _salary), bonus(_bonus) {
	}
	// method overloading�� ����
	// Employee�� ���ǵ� computeSalary()�� �������Ѵ�.
	// �� �޼��� �ȿ����� �θ� Ŭ������ �޼��带 �ҷ�����,
	// �߰��� ���ʽ� ������ ���� ������ �߰��Ѵ�.
	int computeSalary() {

		int total = salary + bonus;

		Employee::computeSalary();
		cout << "���ʽ�: " << bonus << endl;
		cout << "��ü �޿�: " << total << endl;

		return total;
	}
	// getter, setter
	int getBonus() {
		return bonus;
	}
	void setBonus(int bonus) {
		this->bonus = bonus;
	}
};

int main(void) {

	Manager manager("��ö��", 200, 100);

	int total_salary = manager.computeSalary();

	return 0;
}