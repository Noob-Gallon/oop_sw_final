#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Box Ŭ������ ���ο� ������ instance�� ������ ���� ����
// cnt member�� ����. main���� �ڽ��� ������ ������ boxAdded()�� ����.
class Box {
private:
	double length;
	double width;
	double height;
	static int cnt;

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
	static void boxAdded() {
		Box::cnt++;
	}
	static int getCnt() {
		return Box::cnt;
	}
};

int Box::cnt = 0;

// ���� ������ static int cnt�� �����ص� ������,
// �̷��� �����ϸ� �� ���������� ����� ������ ū ���̰� ���� ������
// Ŭ���� ������ ����
// static int cnt2 = 0;

int main(void) {

	srand(time(NULL));
	cout << Box::getCnt() << endl;

	// �ڽ��� ������ 1~10������ �����ϰ� �����, ������ ����.
	for (int i = 0; i < 1 + rand() % 10; i++) {
		Box box(rand(), rand(), rand());
		Box::boxAdded();
	}
	cout << "The number of boxes : " << Box::getCnt() << endl;

	return 0;
}