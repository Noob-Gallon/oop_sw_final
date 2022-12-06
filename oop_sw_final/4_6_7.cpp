#include <iostream>

using namespace std;

// ������ ���� Ŭ������ ��ӵ� Person Ŭ���� ����.
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

// Person Ŭ������ ��ӹ޾Ƽ� myJob()�� �������ϰ�
// teach �޼��带 �߰��� �����Ѵ�.
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

// Person Ŭ������ ��ӹ޾Ƽ� myJob()�� �������ϰ�
// playTennis �޼��带 �߰��� �����Ѵ�.
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

// Person Ŭ������ ��ӹ޾Ƽ� myJob()�� �������ϰ�
// runBusiness �޼��带 �߰��� �����Ѵ�.
class Businessman : public Person {
public:
	Businessman(int _age) : Person(_age) {
	}
	void runBusiness() {
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