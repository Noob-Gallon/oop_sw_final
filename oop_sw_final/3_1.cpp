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
	double Volume() {
		return length * width * height;
	}
	double getLength() {
		return length;
	}
	double getWidth() {
		return width;
	}
	double getHeight() {
		return height;
	}
	// + opeator overloading.
	// 두 객체의 l, w, h를 더한 새 객체를 만들고,
	// 이 객체를 return한다.
	// 만약, Box&로 return하면 생성한 객체가 사라지므로
	// 오류가 발생한다. 따라서 반드시 복사본으로 return한다.
	Box operator+(const Box& _other) {
		Box temp(length+_other.length,
			width+_other.width,
			height+_other.height); // 새로운 객체를 만드므로, constructor가 불림.

		return temp;
	}
};

void showBoxInfo(Box& box) {

	// 생성된 상자의 개수를 세기 위해 함수 내에 static int 선언.
	static int k = 1;

	cout << "상자 #" << k << endl;
	cout << "상자의 길이: " << box.getLength() << endl;
	cout << "상자의 너비: " << box.getWidth() << endl;
	cout << "상자의 높이: " << box.getHeight() << endl;
	cout << "상자의 부피: " << box.Volume() << endl << endl;

	k++;
}

int main(void) {

	Box a(10, 10, 10), b(20, 20, 20), c;

	// + overloading
	c = a + b;
	cout << endl;

	showBoxInfo(a);
	showBoxInfo(b);
	showBoxInfo(c);

	return 0;
}