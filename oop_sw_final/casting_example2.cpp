#include <iostream>

using namespace std;

class Parent {
public:
	int p;

	Parent() {
		cout << "Parent Constructor\n";
		this->p = 1;
	}
	virtual ~Parent() {
		cout << "Parent Destructor\n";
	}
	void show() {
		cout << "Parent\n";
	}
};

class Child : public Parent{
public:
	int c;

	Child() {
		cout << "Child Constructor\n";
		this->c = 2;
	}
	virtual ~Child() {
		cout << "Child Destructor\n";
	}
	void show() {
		cout << "Child\n";
	}
};

int main(void) {

	// 1. upcasting
	Parent* p = new Child();
	p->show(); // Parent, virtual�� ���δٸ� Child...

	delete p;

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	// 2. down casting
	// Child* c = new Parent(); // �Ұ���. Child*�� Parent�� �׳� ���� ���� ����.
	Parent* p2 = new Parent();
	Child* c = (Child*)p2; // �̷� ������� down casting ����.
	// ������, �� ����� �̿��ϸ� �߸��� �ּҿ� �����ϰ� �� �� ����.
	// �ֳĸ�, ������ Child ��ü�� ������� ���� �ƴϹǷ� 
	// Child�� ������ �޸� ������ ������ �ʾ���. ���� �����ϸ� �̻��� ������.

	// *********************************************************************** //
	// c->show(); ������, �̷��� �ϸ� Child�� ���´ٴ°�... �̰� ���� �𸣰���.//
	// *********************************************************************** //
	cout << "???\n";
	c->Parent::show();
	c->show(); 
	// c�� Child type�̹Ƿ� �翬��, override�� �Լ��� �����ϰ� �ȴ�.
	// �̰��� �ҷ��� �� �ִ� ������, �׳� class�� ���� ��ü�� �޸� ��򰡿� ��ϵǾ� �����Ƿ�
	// �װ����� �ҷ����� ������ ������ ���� ���ΰ�???...

	cout << "p : " << c->p << endl; // Parent �޸� ������ ����.
	cout << "c : " << c->c << endl; // �߸��� ����. �ֳĸ�, Child ������ ��ü�� ��������� �ʾ���.

	delete p2;
	// delete c;
	// delete�� ���� �ƹ��ų� �ص� ������ ����. ����Ű�� �ּҰ� ���� ����...
	// ������ ������� ��ü�� Parent ���̹Ƿ�, destructor�� Parent�� destructor�� �Ҹ���.

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	// 3. dynamic_cast �̿��� down casintg, �߸��� ���.
	Parent* p3 = new Parent();
	Child* c3 = dynamic_cast<Child*>(p3); // Parent(superclass)�� Child(subclass)�� downcasting �õ�.
	// �׷���, �̷��� �ϴ� ���� ����� 2�� ������ ���� ������.
	// ������, dynamic_cast�� �̿��ϸ� �� ����� ������ �߻���ų ���ɼ��� ���ٰ� �Ǵ��Ͽ�
	// c3�� nullptr�� ��ȯ��...

	// �ٽ� �� �� ���� ���ڸ�, c3->c �� �� ���, �̻��� �޸� ��ġ�� �����ϰ� �Ǵ� ����...
	// ������ Ŭ������ �������� �Ҵ���� ���� ������ �ǵ帮�� ��.

	if (c3 == nullptr) {
		cout << "c3 == nullptr!\n";
		delete p3;
	}
	else {
		delete c3;
	}

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	// 4. dynamic_cast �̿��� down casting, �ùٸ� ���.

	Parent* p4 = (Parent*)new Child(); // down casting���� ���� �߸��� ������ �ϴ� ���� ��������,
	// �̿� ���� Child() ��ü�� �����ؼ� ���ʿ� ���� ������ �������� ����������
	// down casting�� �����ؾ߸� �Ѵ�...
	// �����δ� Child Ŭ������ ��� �޸� ������ ����������, Parent*�δ� Child ������ ������ �� ����.
	// down casting�� �����ϸ� ������ �� �ְ� �ȴ�... (���ο� �����͸� ���ؼ�)
	p4->show(); // ���� �����ʹ� Parent type�̹Ƿ�, show()�� Parent�� ����Ѵ�.
	// ����, show()�� virtual�̶��, Child�� ����� ���̴�...

	Child* c4 = dynamic_cast<Child*>(p4);
	c4->show(); // ���� �����ʹ� Child type�̹Ƿ�, show()�� Child�� ����Ѵ�.

	delete c4; // Child -> Parent

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	// 5. static_cast �̿��� up_casting.

	Child* c5 = new Child(); // �긦 upcasting�� �̴ϴ�.
	Parent* p5 = static_cast<Parent*>(c5);
	p5->show(); // �翬��, Parent.
	
	delete p5; // Child -> Parent

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	return 0;
}