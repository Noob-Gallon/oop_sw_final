#include <iostream>

using namespace std;

class Parent {
public:
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
	int p;
};

class Child : public Parent {
public:
	Child() {
		cout << "Child Constructor\n";
		this->c = 2;
	}
	virtual ~Child() {
		cout << "Child Constructor\n";
	}
	void show() {
		cout << "Child\n";
	}
	void showC() {
		cout << "this->c : " << this->c << endl;
	}
	int c;
};

int main(void) {

	// -------------------------------------------------------------------------------- //

	// upcasting.
	// �� ��쿡�� �Ҹ��ڿ� virtual�� ���������� ������
	// Parent Ÿ�� �������̹Ƿ�, �ڽ� Ŭ������ �޸𸮰� �������� ����...
	// ���� �߻�!!!
	Parent* p = new Child();
	p->show();
	// cout << p->c << endl; p�� Child�� �޸𸮿��� ���� �Ұ���. ����, c ��� �Ұ�!
	cout << p->p << endl;
	delete p; // child, parent

	// -------------------------------------------------------------------------------- //
	cout << "\n\n\n";

	// down casting.
	// Child* c = new Parent(); �̷��� ���������� down casting�� �Ұ���.
	Parent* p2 = new Parent(); // Parent type pointer�� �����,
	Child* c2 = (Child*)p2; // Child*�� type casting�ؼ� c�� ��������...
	cout << c2->p << endl; // ��� �չ�.
	cout << c2->c << endl; // �׷���, ��� ����������, ��ǻ� �ҹ���. �ֳĸ�, �����Ǳ⸦ �ٺ��� Parent()�ε�, c�� �ڱ� ������ �ƴ�.
	c2->showC();
	// �׷��ٸ�, show()�� �� ������ ���ΰ�???
	c2->Parent::show();
	c2->show(); // ��� �� ������ ���ϱ�?
	
	// c2->c = 100; // ������. ������ ������ �õ���, ���� Ŭ������ �޸� ������ �ƴ� ���� �ǵ帮�� ����.
	// cout << c2->c << endl;
	// pointer type�� Child�̹Ƿ�, virtual�� �������� �ʴ´�.
	// ��, �̰� �����ҵ�?
	
	delete c2; // Child type pointer�� ����Ű�� ������, ������ �Ҵ�� �޸𸮴� Parent �ۿ� ���, Parent destructor�� �Ҹ���...
	// Parent

	// -------------------------------------------------------------------------------- //
	cout << "\n\n\n";

	Parent* p3 = new Parent();
	Child* c3 = dynamic_cast<Child*>(p3); // ���� �������� �õ���, �̷��� casting�� �ϸ�
	// �����δ� Parent�� �޸𸮸� ������ ����������, Child�� �޸𸮿� ������ �ϰ� �Ǹ鼭
	// ������ �߻��� ���ɼ��� �����Ƿ�, nullptr�� ��ȯ�Ѵ�...

	// Parent type�� Child�� casting�ϴ� ����
	// ������ �߻���ų ���ɼ��� �����Ƿ�,
	// dynamic_cast ������ nullptr�� ��ȯ�Ѵ�...

	if (c3 == nullptr) {
		cout << "Error!\n";
	}
	else {
		delete c3;
	}

	// -------------------------------------------------------------------------------- //
	cout << "\n\n\n";

	// ����, dynamic casting�� �̿� ���� ���־�� �Ѵ�.
	Parent* p4 = new Child(); // �̰� �չ�. upcasting...
	// p4->showC(); �ƹ��� Child�� upcasting�� �ߴٰ� �ص�,
	// Child�� �޸� ������ Parent type���� ���� ������ �Ұ�����...

	Child* c4 = dynamic_cast<Child*>(p4); 
	// Parent* p4�� Child* �� �ٲ���.
	// ������ ��쿡�� Parent* p = new Parent() �� �� Child*�� casting�� �õ��ߴµ�,
	// �̷��� �ϸ� �߸��� �ּҿ� ������ Ȯ���� �����Ƿ�, nullptr�� ��ȯ�Ѵ�.
	// ������ �̹� ��쿡�� p4�� Parent*������, Child()�� ����Ű�� �����Ƿ�,
	// Child()�� ������ �޸𸮿��� ������ �Ұ���������, Child() ���� �����
	// Parent()�� �޸𸮿��� ������ ������ ����̴�.
	// �� ��쿡, p4�� Child*�� down casting���ָ�, casting�� �����ϴ�...

	// �̷��� �ϸ�, ������ Child ��ü�� ��� ���������.
	// �׷��� �ñ��� ����... �̷��� �ҰŸ� �׳� Child ��ü�� ���������� �Ǵ°� �ƴұ�?
	// dynamic_cast�� �ʿ��� ��츦 �����غ��ٸ�...?
	c4->show(); // Child* �̹Ƿ�, Child�� ���´�.
	c4->showC(); // Child instance�̹Ƿ�, c�� ���� ����. 2
	cout << c4->c << endl; // �翬�� c ���� ����. 2

	delete c4; // Child -> Parent ������ destructor ȣ���.

	// -------------------------------------------------------------------------------- //
	cout << "\n\n\n";

	// static cast, upcasting...
	// Child type�� Parent type���� casting�ؼ�
	// Parent type �����ͷ� ����ų �� �ְ� ��.
	Child* c5 = new Child();
	Parent* p5 = static_cast<Parent*>(c5);

	// p5�� Parent�̹Ƿ�, Child ��ü�� ����Ǿ��ٰ�� ������,
	// ���� c���� ������ �� ���� ��.
	// p5->c = 10; �ҷ��� �� ����.

	p5->show(); // Parent
	// ���� show�� virtual�� �ٲ۴ٸ�, Child�� ����.

	delete p5; // destructor�� virtual�̹Ƿ�, Child -> Parent�� �Ҹ�.
	return 0;
}