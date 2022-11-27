#include <iostream>

using namespace std;

class Parent {
public:
	int x;
	Parent() {
		cout << "Parent constructor\n";
	}
	virtual ~Parent() {
		cout << "Parent destructor\n";
	}
	void show() {
		cout << "Parent\n";
	}
};

class Child : public Parent {
public:
	int y;
	Child() {
		cout << "Child constructor\n";
	}
	virtual ~Child() {
		cout << "Child destructor\n";
	}
	void show() {
		cout << "Child\n";
	}
};

// �ֿ� ����
// 1. �θ� Ŭ������ �����ͷ� �ڽ� Ŭ������ ����ų �� �ִ�. upcasting
// 2. ���� p�� Child Ŭ������ ����Ű�� ������, virtual�� ����Ǿ� ���� �ʱ� ������
// show�� Parent�� ����Ѵ�.
// 3. p�� ������ ����Ű�� Ŭ������ Child Ŭ�����̹Ƿ�, dynamic_cast�� ���� �ٿ� ĳ������ �����ϴ�.
// �׷��� ������ Parent�� ����ų ���� Child*�� downcasting�� �Ұ�������?

int main(void) {

	Parent* p = new Child(); // Parent, Child constructor�� �Ҹ�.
	p->show(); // show()�� virtual�� �ƴϹǷ�, Child�� ����Ű�� ������ Parent�� �����...
	// ���� show()�� virtual�� �����Ѵٸ�, �翬�ϰԵ� Child�� �Ҹ�.
	cout << "-----\n";

	Child* c = dynamic_cast<Child*>(p); // ���� p�� Child�� ����Ű�� �����Ƿ�, dynamic_cast ����...

	if (c == nullptr) {
		cout << "Runtime error\n";
	}
	else {
		p->show();
	}

	delete p;

	return 0;
}