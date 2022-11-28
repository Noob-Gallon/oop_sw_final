#include <iostream>

using namespace std;

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