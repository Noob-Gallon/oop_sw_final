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
	// friend �Լ��� ���� ��ġ�� ũ�� ��� ����?

};

void printBox(Box box) {
	
	static int k = 1;

	cout << "���� #" << k << endl;
	cout << "������ ����: " << box.length << endl;
	cout << "������ ����: " << box.width << endl;
	cout << "������ ����: " << box.height << endl;
	cout << "������ ����: " << box.Volume() << endl;

	k++;
}

int main(void) {

	Box a(10, 15, 20);
	printBox(a);

	return 0;
}