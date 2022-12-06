#include <iostream>

using namespace std;

class Box {
private:
	double length;
	double width;
	double height;

public:
	Box(double l = 2.0, double w = 2.0, double h = 2.0) {
		cout << "A box created..." << endl;
		length = l;
		width = w;
		height = h;
	}
	double Volume() const {
		return length * width * height;
	}
	double getLength() const {
		return length;
	}
	double getWidth() const {
		return width;
	}
	double getHeight() const {
		return height;
	}
	Box operator+(const Box& _other) const {
		Box temp(length + _other.length,
			width + _other.width,
			height + _other.height);

		return temp;
	}
	// 새롭게 추가된 operator overloading.
	// 기존에 정의한 함수 Volume을 이용하여 두 객체의 부피 비교.
	// 안정성을 위해 const 추가.
	bool operator==(const Box& _other) const {
		return (Volume() == _other.Volume());
	}
};

void showBoxInfo(Box& box) {

	static int k = 1;

	cout << "상자 #" << k << endl;
	cout << "상자의 길이: " << box.getLength() << endl;
	cout << "상자의 너비: " << box.getWidth() << endl;
	cout << "상자의 높이: " << box.getHeight() << endl;
	cout << "상자의 부피: " << box.Volume() << endl << endl;

	k++;
}

int main(void) {

	// + operator overloading을 이용해서 세 객체 생성
	Box a(10, 10, 10), b(10, 10, 10), c;
	c = a + b;
	
	cout << endl;

	showBoxInfo(a);
	showBoxInfo(b);
	showBoxInfo(c);

	// == overloading으로 비교.
	cout << boolalpha;
	cout << "a == b" << endl;
	cout << (a == b) << endl;
	cout << endl;
	cout << "b == c" << endl;
	cout << (b == c) << endl;

	return 0;
}