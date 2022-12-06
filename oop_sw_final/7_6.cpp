#include <iostream>

using namespace std;

// template을 이용해 class를 정의한다.
// Circle은 T을 이용해서 원의 면적을 구하는 area method를 정의한다.
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

	// Circle은 template으로 선언되었으므로, Circle<double>로
	// instance를 선언한다.
	Circle<double> circleA(0.0, 0.0, 10.0);
	cout << "면적 : " << circleA.area() << endl;

	return 0;
}