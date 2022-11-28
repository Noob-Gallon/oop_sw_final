#include <iostream>

using namespace std;

class Box {
private:
	double length;
	double width;
	double height;
	friend void printBox(Box box);

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
	// friend void printBox(Box box);
	// friend 함수의 선언 위치는 크게 상관 없음?

};

void printBox(Box box) {
	
	static int k = 1;

	cout << "상자 #" << k << endl;
	cout << "상자의 길이: " << box.length << endl;
	cout << "상자의 길이: " << box.width << endl;
	cout << "상자의 길이: " << box.height << endl;
	cout << "상자의 부피: " << box.Volume() << endl;

	k++;
}

int main(void) {

	Box a(10, 15, 20);
	printBox(a);

	return 0;
}