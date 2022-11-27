#include <iostream>

using namespace std;

class Parent {
public:
	int x;
	virtual ~Parent() {

	}
};

class Child : public Parent {
public:
	int y;
	virtual ~Child() {

	}
};

int main(void) {

	Parent* p = new Parent();
	Child* c = dynamic_cast<Child*>(p);
	// dynamic cast�� Parent�� virtual�� �־�� ��� ����.
	// dynamic cast�� ������ �߻��� Ȯ���� ������ casting�� ���� �ʰ�
	// nullptr�� ��ȯ�Ѵ�.
	// ���� ���� ���� ������ �߻��� Ȯ���� ���� ������
	// casting�� ���� �ʰ�, nullptr�� ��ȯ�Ѵ�.
	
	if (c == nullptr) {
		cout << "nullptr! error...\n";
	}

	Parent* p2 = (Parent*)(new Child()); // ������ upcasting...
	Child* c2 = dynamic_cast<Child*>(p2); 

	if (c2 == nullptr) {
		cout << "nullptr! error...\n";
	}

	return 0;
}