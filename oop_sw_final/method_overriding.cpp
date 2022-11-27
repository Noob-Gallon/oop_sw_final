#include <iostream>

using namespace std;

class Parent {
public:
	void whoareyou() {
		cout << "Parent" << endl;
	}
};

class Child : public Parent {
public:
	void whoareyou() {
		// super call, ����� ������
		// Child �ȿ��� Parent�� ���� �޸� ������
		// ������ ������ namespace�� �����ؼ�
		// �Ʒ��� ���� call�� �� ����...
		Parent::whoareyou();
		cout << "child" << endl;
	}
};

int main(void) {

	Child child;
	child.whoareyou();
	child.Parent::whoareyou(); // method overriding.

	return 0;
}