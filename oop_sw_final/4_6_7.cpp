#include <iostream>

using namespace std;

class Person {
private:
	int age;

public:
	Person(int _age) : age(_age) {
	}
	void eat() {
		cout << "���� �� ����.\n";
	}
	void talk() {
		cout << "���� �� ����.\n";
	}
	void run() {
		cout << "���� �� ����.\n";
	}
	void myJob() {
		cout << "���� ����: ���\n";
	}
	void myAge() {
		cout << "���� ����: " << age << endl;
	}
};

class Professor : public Person {
public:
	Professor(int _age) : Person(_age) {
	}
	void teach() {
		cout << "����ĥ �� ����.\n";
	}
	void myJob() {
		cout << "���� ����: ����\n";
	}
};

class TennisPlayer : public Person {
public:
	TennisPlayer(int _age) : Person(_age) {
	}
	void playTennis() {
		cout << "�״Ͻ� ��⸦ �� �� ����.\n";
	}
	void myJob() {
		cout << "���� ����: �״Ͻ� ����\n";
	}
};

class Businessman : public Person {
public:
	Businessman(int _age) : Person(_age) {
	}
	void runBusineses() {
		cout << "����� �� �� ����.\n";
	}
	void myJob() {
		cout << "���� ����: �����\n";
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