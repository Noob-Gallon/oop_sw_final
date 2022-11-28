#include <iostream>

using namespace std;

class MyObj {
public:
	int* p;
	int size;

	MyObj(int _size) : size(_size) {
		cout << "������" << endl;
		p = new int[_size];

		for (int i = 0; i < this->size; i++) {
			p[i] = i;
		}
	}
	MyObj() {
		cout << "�⺻ ������" << endl;
	}
	MyObj(const MyObj& _other) {
		cout << "���� ������!" << endl;
		this->size = _other.size;
		p = new int[this->size];

		for (int i = 0; i < this->size; i++) {
			p[i] = _other.p[i] + 100;
		}
	}
	MyObj& operator=(const MyObj& _other) {
		cout << "���� ������ �����ε�" << endl;
		this->size = _other.size;
		this->p = new int[this->size];

		for (int i = 0; i < this->size; i++) {
			p[i] = 2*_other.p[i];
		}

		return *this;
	}
	~MyObj() {
		if (p != nullptr) {
			delete[] p;
		}
	}
	void print() {
		for (int i = 0; i < this->size; i++) {
			cout << i << " : " << p[i] << endl;
		}
	}
};

MyObj compare(MyObj obj1, MyObj obj2) {

	cout << "\nobj1\n";
	obj1.print();
	cout << "\n\n\n";

	cout << "\nobj2\n";
	obj2.print();
	cout << "\n\n\n";

	// ���� Ȯ�� �Ϸ�.

	int sum1= 0, sum2 = 0;
	
	for (int i = 0; i < obj1.size; i++) {
		sum1 += obj1.p[i];
	}

	for (int i = 0; i < obj2.size; i++) {
		sum2 += obj2.p[i];
	}

	if (sum1 >= sum2) {
		return obj1;
	}
	else {
		return obj2;
	}

	// ������� �����ϰ� �ѱ� �� �����ڷ� �ѱ�� �Ǹ�,
	// ���, �� �Լ� �ȿ��� obj1�� obj2�� ������� �͵��̱� ������
	// ������ ������ �Ǹ� �߸��� ������ �ȴ�...
}

int main(void) {

	MyObj obj1(5);
	cout << "obj1" << endl;
	obj1.print();

	cout << endl;
	cout << "���� üũ, obj2" << endl;
	MyObj obj2 = obj1;
	obj2.print();


	cout << endl; 
	// compare ��ü�� ���� �����ڸ� �θ�...
	// �׷��� �� ���� �����ڴ� �ƴұ�? Q...

	MyObj obj3;
	compare(obj1, obj2).print();
	obj3 = compare(obj1, obj2);
	obj3.print();

	return 0;
}