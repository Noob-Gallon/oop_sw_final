#include <iostream>

using namespace std;

class MyVector {
public:
	MyVector(int _x, int _y) : x(_x), y(_y) {
		cout << "constructor invoked...\n";
	}
	MyVector(){}
	void showXY() {
		cout << "x : " << x << ", y : " << y << endl;
	}
	void setXY(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
	// + overloading
	// + overloading은 반드시 값을 반환해주어야 한다.
	// 새로운 변수를 만들 경우, 또는 cout으로 출력하는 경우에 필요하다? => 이럴 때는 어떻게 해야되지?
	// overloading 예제 연습 필요.
	MyVector operator+(const MyVector& _other) { 
		// parameter로 넘어온 Class의 private에는 접근 가능?
		// 그게 아니라, 넘어온 인자도 결국 MyVector 클래스이고,
		// 이곳은 MyVector class의 내부이므로 public으로 동작하는 것...

		MyVector temp(this->x + _other.x, this->y + _other.y);
		return temp;
	}
	// - overloading, + overloading과 똑같다.
	MyVector operator-(const MyVector& _other) {

		MyVector temp(this->x - _other.x, this->y - _other.y);
		return temp;
	}
	MyVector operator*(const MyVector& _other) {

		MyVector temp(this->x * _other.x, this->y * _other.y);
		return temp;
	}
	MyVector operator/(const MyVector& _other) {

		if (_other.x == 0 || _other.y == 0) {
			MyVector temp(0, 0);
			return temp;
		}

		MyVector temp(this->x / _other.x, this->y / _other.y);
		return temp;
	}
	// 위에서 overloading된 사칙연산의 return type을 pionter 형식으로 하면,
	// pointer로 전달받을 수 있음. 단, return type은 overloading에 관여하지 않으므로,
	// 여러 개의 op_overloading을 만들 수는 없음...
	
	// argument를 pointer type으로 만들어보자.
	// const이냐 아니냐로도 overloading 가능!
	MyVector* operator+(const MyVector* _other) {
		cout << "invoked!\n";
		MyVector* temp = new MyVector(this->x + _other->x, this->y + _other->y);
		// temp.showXY();

		return temp; // temp가 사라지므로, 일반적으로 생성한 temp의 주소를 넘겨줘도 문제가 발생함...
		// 따라서, 동적할당한 MyVector를 넘겨준다. 동적할당하면, MyVector는 delete를 하지 않는 이상
		// 사라지지 않기 때문에, 함수 밖으로 넘어가서도 주소값 참조를 통해 유지될 수 있다.
	}
	// 다른 것은 똑같으므로, 만들지 않음... -, *, /
	bool operator==(const MyVector& _other) {
		
		return (this->x == _other.x) && (this->y == _other.y);
	}
	MyVector(const MyVector& _other) {
		this->x = _other.x;
		this->y = _other.y;
		cout << "copy constructor invoked!\n";
	}


private:
	int x, y;
};

int main(void) {

	MyVector v1(1, 1); // constructor
	MyVector v2(2, 2); // constructor

	MyVector v3 = v1 + v2; // 내부에서 constructor가 불려서 temp 생성. v3에 copy constructor invoked...
	v3.showXY();

	MyVector v4 = v2 - v1;
	v4.showXY();

	cout << boolalpha;
	cout << (v1 == v4) << endl;
	cout << (v1 == v2) << endl;

	MyVector v5 = v2 / v1;
	v5.showXY();

	MyVector v6(0, 0);
	MyVector v7 = v1 / v6;
	v7.showXY();

	cout << "---------------------------\n\n\n";

	MyVector n1(10, 10);
	MyVector n2(20, 20);
	MyVector* n3 = n2 + &n1;
	n3->showXY();

	MyVector* p1 = new MyVector();
	p1->setXY(50, 50);
	MyVector* p2 = n1 + p1;
	p2->showXY();

	return 0;
}