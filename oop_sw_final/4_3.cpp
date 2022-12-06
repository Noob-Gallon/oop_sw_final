#include <iostream>

using namespace std;

// Employee 클래스는 생성자를 통해
// 멤버 변수 name, salary를 초기화 한다.
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

// Employee 클래스를 public 상속받는다.
// 추가적인 멤버 변수 bonus를 가지며,
// 생성자를 통해 변수를 초기화 한다.
class Manager : public Employee {
private :
	int bonus;

public:
	Manager(string _name, int _salary, int _bonus) : Employee(_name, _salary), bonus(_bonus) {
	}
	// method overloading을 통해
	// Employee에 정의된 computeSalary()를 재정의한다.
	// 이 메서드 안에서는 부모 클래스의 메서드를 불러오고,
	// 추가된 보너스 변수에 대한 동작을 추가한다.
	int computeSalary() {

		int total = salary + bonus;

		Employee::computeSalary();
		cout << "보너스: " << bonus << endl;
		cout << "전체 급여: " << total << endl;

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

	Manager manager("김철수", 200, 100);

	int total_salary = manager.computeSalary();

	return 0;
}