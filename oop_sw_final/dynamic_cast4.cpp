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

int main(void) {

	Child* c = new Child(); // ����� casting.
	// Parent�� Child�� ��Ӱ����̹Ƿ�, new�� instance ������
	// Parent->Child ������ �����ڰ� �Ҹ�.

	c->show(); // Child type �����ͷ� ��ü�� ����Ű�Ƿ�, Child�� ���´�.
	cout << "-----\n";

	Parent* p = static_cast<Parent*>(c); // Parent ������ p�� Child�� ����Ű���� static_cast(upcasting)...
	p->show(); // ���� show()�� virtual method�� �ƴϹǷ� Parent�� ���´�.
	// �ֳĸ�, Parent type �����ͷ� ����Ű�� �ֱ� ����...
	// ���� virtual�� �����ϸ�? Child�� ���� ��.

	delete p; // p�� Parent type�̹Ƿ�, destructor�� Parent�� �θ���.
	// �̷��� �Ǹ�, ��ӹ��� Ŭ������ destructor�� �Ҹ��� �����Ƿ�
	// virtual�� �ٿ���� �Ѵ�. �׷��� Child -> Parent ������
	// destructor�� �Ҹ���.

	return 0;
}