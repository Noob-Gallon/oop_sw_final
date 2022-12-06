#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
	// ���� ���� �Լ� speak ����
	virtual void speak() = 0;
	virtual ~Animal() {}
};

// Animal�� ��ӹ޾� speak�� ������.
class Dog : public Animal {
public:
	void speak() {
		cout << "�۸�!" << endl;
	}
};

// Animal�� ��ӹ޾� speak�� ������.
class Cat : public Animal {
	void speak() {
		cout << "�߿�!" << endl;
	}
};

int main(void) {

	// Animal* �����͸� �����ϴ� vector ����.
	// upcasting�� ���� speak()�� ������ �� ����.
	// virtual method�̹Ƿ�, �ڽ� Ŭ�������� ���ǵ�
	// speak() ���� ����.
	vector<Animal*> barn;
	Dog dog;
	Cat cat;

	barn.push_back(&dog);
	barn.push_back(&cat);

	for (auto i = barn.begin(); i != barn.end(); i++) {
		(*i)->speak();
	}

	return 0;
}