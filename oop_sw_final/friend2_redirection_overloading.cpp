#include <iostream>

using namespace std;

class Point {
private:
	int x, y;

public:
	Point(int _x, int _y) : x(_x), y(_y) {

	}

	void showPoint() {
		cout << x << ", " << y << endl;
	}
	friend ostream& operator<< (ostream& os, Point& p);
	friend istream& operator>> (istream& is, Point& p);
};

// redirection�� ��ü�� Ŭ������ ���� �����Ƿ�
// �ܺο��� ����?
ostream& operator<<(ostream& os, Point& p) {
	os << p.x << ", " << p.y;
	return os;
}

istream& operator>>(istream& is, Point& p) { // friend�̹Ƿ� ���� ����...
	is >> p.x >> p.y;
	return is;
}

int main(void) {

	Point p(10, 20);
	// p.showPoint();

	// ������ re-direction overloading�� �ȵ��־ �Ұ���
	// cout << p;

	cout << p << endl;

	cin >> p;
	cout << p << endl;

	return 0;
}