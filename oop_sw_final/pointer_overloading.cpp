#include <iostream>

using namespace std;

class MyUniquePtr {
public:
	MyUniquePtr(int* _p) : p(_p) {
		cout << "memory allocate p\n";
	}
	~MyUniquePtr() {
		
		if (p != nullptr) {
			cout << "delete p\n";
			delete[] p; // �迭���� �ƴ��� üũ�� �� �ֳ�?
		}
	}
	void setValue(int _idx, int _value) {
		this->p[_idx] = _value;
	}
	int& operator* (void) {
		return *p;
	}

public:
	int* p = nullptr;

};

int main(void) {

	unique_ptr<int> p(new int(40)); // �ϳ��� ����. �� �ٷ� ���� ����.
	// unique_ptr, delete�� �ʿ����.

	MyUniquePtr p1(new int[10]); // �迭�� ����, delete[]... �����ڿ� �ٷ� �ּҸ� �־��ش�.
	
	for (int i = 0; i < 10; i++) {
		p1.setValue(i, i);
	}

	for (int i = 0; i < 10; i++) {
		cout << "p1[" << i << "] : " << p1.p[i] << endl;
	}

	MyUniquePtr p2(new int(10));
	cout << *p2 << endl; // p2�� ���� ���Ƿ� ������� ��ü�̴�. ����Ʈ �������� ����� �ϴ� ��ü�� ���̴�.
	// ����, *p2�� ���ַ���, * overloading�� ����� �Ѵ�...

	// p1�� p2�� destructor�� �ҷ����鼭 �ڵ����� delete�ȴ�...

	return 0;
}