#include <iostream>

using namespace std;

template<typename T>
class Circle {
private:
	T x, y, r;

public:
	Circle(T _x, T _y, T _r) : x(_x), y(_y), r(_r) {
	}
	T area() {
		return 3.14 * r * r;
	}
};

int main(void) {

	Circle<double> circleA(0.0, 0.0, 10.0);
	cout << "¸éÀû : " << circleA.area() << endl;

	return 0;
}