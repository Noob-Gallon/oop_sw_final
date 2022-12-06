#include <iostream>

using namespace std;

// Box 내에 friend 함수 printBox 선언.
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
	friend void printBox(Box box);

};

// PrintBox method는 friend 함수이므로,
// Box 클래스의 private member에 외부에서도 접근 가능하다.
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