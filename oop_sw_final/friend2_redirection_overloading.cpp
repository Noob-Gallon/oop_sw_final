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

// redirection은 주체가 클래스가 되지 않으므로
// 외부에서 정의?
ostream& operator<<(ostream& os, Point& p) {
	os << p.x << ", " << p.y;
	return os;
}

istream& operator>>(istream& is, Point& p) { // friend이므로 접근 가능...
	is >> p.x >> p.y;
	return is;
}

int main(void) {

	Point p(10, 20);
	// p.showPoint();

	// 지금은 re-direction overloading이 안돼있어서 불가능
	// cout << p;

	cout << p << endl;

	cin >> p;
	cout << p << endl;

	return 0;
}