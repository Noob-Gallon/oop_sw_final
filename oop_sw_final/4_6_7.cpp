#include <iostream>

using namespace std;

class Person {
private:
	int age;

public:
	Person(int _age) : age(_age) {
	}
	void eat() {
		cout << "먹을 수 있음.\n";
	}
	void talk() {
		cout << "말할 수 있음.\n";
	}
	void run() {
		cout << "걸을 수 있음.\n";
	}
	void myJob() {
		cout << "나의 직업: 사람\n";
	}
	void myAge() {
		cout << "나의 나이: " << age << endl;
	}
};

class Professor : public Person {
public:
	Professor(int _age) : Person(_age) {
	}
	void teach() {
		cout << "가르칠 수 있음.\n";
	}
	void myJob() {
		cout << "나의 직업: 교수\n";
	}
};

class TennisPlayer : public Person {
public:
	TennisPlayer(int _age) : Person(_age) {
	}
	void playTennis() {
		cout << "테니스 경기를 할 수 있음.\n";
	}
	void myJob() {
		cout << "나의 직업: 테니스 선수\n";
	}
};

class Businessman : public Person {
public:
	Businessman(int _age) : Person(_age) {
	}
	void runBusineses() {
		cout << "사업을 할 수 있음.\n";
	}
	void myJob() {
		cout << "나의 직업: 사업가\n";
	}
};

int main(void) {

	Professor p(39);
	p.myJob();
	p.myAge();
	p.run();
	p.talk();
	p.teach();

	cout << "\n";

	TennisPlayer tp(23);
	tp.myJob();
	tp.myAge();
	tp.run();
	tp.talk();
	tp.playTennis();

	return 0;
}