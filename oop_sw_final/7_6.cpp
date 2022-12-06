#include <iostream>

using namespace std;

// template�� �̿��� class�� �����Ѵ�.
// Circle�� T�� �̿��ؼ� ���� ������ ���ϴ� area method�� �����Ѵ�.
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

	// Circle�� template���� ����Ǿ����Ƿ�, Circle<double>��
	// instance�� �����Ѵ�.
	Circle<double> circleA(0.0, 0.0, 10.0);
	cout << "���� : " << circleA.area() << endl;

	return 0;
}