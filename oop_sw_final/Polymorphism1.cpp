#include <iostream>

using namespace std;

class Parent {
public:
	int x;
};

class Child : public Parent {
public:
	int y;
};

int main(void) {

	// superclass type pointer��
	// subclass�� instance�� ����Ű�� ��.
	// �̷��� �ϸ� Child���� ����� �޸� ������
	// ������ �� ����, Parent�� ���Ե� �͸� ���� ����...
	Parent* p = new Child();

	p->x = 10;
	// p->y = 20; // ����ų �� ����...

	delete p;

	Parent* p2 = new Parent();
	Child* c = (Child*)p2; 
	// type casting�� �̿��� Parent* Ÿ���� �����͸�
	// Child*�� �ٲ������. �̷��� ����� ����������,
	// ���� c�� Child ���� ����� ����(memory)�� �����ϸ�
	// �Ҹ��ҹ� ���� �ý����� ��������... (���� �ȳ�)
	c->x = 10;
	cout << c->x << endl;

	return 0;
}