#include <iostream>

using namespace std;

class P2 {
public:
	virtual ~P2() {
		cout << "P2 �Ҹ���\n";
	}
};

class C2 : public P2 {
public:
	int* p;
	C2() {
		p = new int[40]; // int 40ĭ ���� �Ҵ�...
	}
	~C2() {
		delete[] p;
		cout << "C2 �Ҹ���\n";
	}
};

int main(void) {

	C2* c = new C2();
	delete c; // P2�� �Ҹ��ڸ� virtual�� ������ �ʾƵ�, ���� �������� �����Ѵ�.

	P2* p = new C2(); // upcasting...
	delete p; // ����, �Ҹ��ڿ� virtual�� ����Ǿ� ���� �ʴٸ�,
	// ���������� ~C2()�� �ҷ��� �� ����.
	// ���� memory leak�� �߻��ϰ� �ȴ�.
	// �̸� ���� ���� C++������ ��� �Ҹ��ڿ� virtual�� �������ִ� ���� ����.

	return 0;
}