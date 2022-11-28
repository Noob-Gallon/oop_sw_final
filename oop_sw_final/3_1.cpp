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
	Box operator+(const Box& _other) {
		Box temp(length+_other.length,
			width+_other.width,
			height+_other.height);

		return temp;
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

	Box a(10, 10, 10), b(20, 20, 20), c;
	c = a + b;
	cout << endl;

	showBoxInfo(a);
	showBoxInfo(b);
	showBoxInfo(c);

	return 0;
}