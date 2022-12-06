#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Box 클래스는 내부에 생성된 instance의 개수를 세기 위해
// cnt member를 가짐. main에서 박스가 생성될 때마다 boxAdded()를 수행.
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

// 전역 변수로 static int cnt를 선언해도 되지만,
// 이렇게 구성하면 이 예제에서는 평범한 변수와 큰 차이가 없기 때문에
// 클래스 내에서 구현
// static int cnt2 = 0;

int main(void) {

	srand(time(NULL));
	cout << Box::getCnt() << endl;

	// 박스의 개수를 1~10개까지 랜덤하게 만들고, 개수를 센다.
	for (int i = 0; i < 1 + rand() % 10; i++) {
		Box box(rand(), rand(), rand());
		Box::boxAdded();
	}
	cout << "The number of boxes : " << Box::getCnt() << endl;

	return 0;
}