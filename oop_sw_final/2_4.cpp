#include <iostream>

using namespace std;

// Point 클래스는 xval, yval 변수를 입력받음.
// swap을 적용하기 위해 getter 생성.
class Point {
private:
	double xval, yval;

public:
	Point(double x = 0.0, double y = 0.0) {
		this->xval = x;
		this->yval = y;
	}
	double getX() {
		return xval;
	}
	double getY() {
		return yval;
	}
	void showMyPoint() {
		cout << "x : " << getX() << ", y : " << getY() << endl;
	}
	void setXY(double x, double y) {
		this->xval = x;
		this->yval = y;
	}
};

// 인자를 reference로 받아서 효율성 높임.
void swap(Point& p1, Point& p2) {

	double x = p1.getX();
	double y = p1.getY();

	p1.setXY(p2.getX(), p2.getY());
	p2.setXY(x, y);
}

int main(void) {

	Point p1(0, 0);
	Point p2(10, 10);
	
	p1.showMyPoint();
	p2.showMyPoint();

	cout << "\nSwap\n";
	swap(p1, p2);

	p1.showMyPoint();
	p2.showMyPoint();

	return 0;
}