#include <iostream>

using namespace std;

class MyObj {
public:
	int* p;
	int size;

	MyObj(int _size) : size(_size) {
		cout << "생성자" << endl;
		p = new int[_size];

		for (int i = 0; i < this->size; i++) {
			p[i] = i;
		}
	}
	MyObj() {
		cout << "기본 생성자" << endl;
	}
	MyObj(const MyObj& _other) {
		cout << "복사 생성자!" << endl;
		this->size = _other.size;
		p = new int[this->size];

		for (int i = 0; i < this->size; i++) {
			p[i] = _other.p[i] + 100;
		}
	}
	MyObj& operator=(const MyObj& _other) {
		cout << "대입 연산자 오버로딩" << endl;
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

	// 복사 확인 완료.

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

	// 여기까지 진행하고 넘길 때 참조자로 넘기게 되면,
	// 사실, 이 함수 안에서 obj1과 obj2는 사라지는 것들이기 때문에
	// 밖으로 나가게 되면 잘못된 접근이 된다...
}

int main(void) {

	MyObj obj1(5);
	cout << "obj1" << endl;
	obj1.print();

	cout << endl;
	cout << "복사 체크, obj2" << endl;
	MyObj obj2 = obj1;
	obj2.print();


	cout << endl; 
	// compare 자체가 복사 생성자를 부름...
	// 그런데 왜 대입 연산자는 아닐까? Q...

	MyObj obj3;
	compare(obj1, obj2).print();
	obj3 = compare(obj1, obj2);
	obj3.print();

	return 0;
}