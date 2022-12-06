#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Circle class는 member variable radius를 가지며,
// getter setter를 정의해줌.
class Circle {
private:
	int radius;

public:
	void setRadius(int _radius) {
		this->radius = _radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

int main(void) {

	// 랜덤 숫자를 위해 srand와 time(NULL) 사용.
	srand(time(NULL));
	int num;
	int cnt = 0;
	
	// 생성할 원의 개수를 입력 받음.
	cout << "생성할 원의 개수: ";
	cin >> num;
	cin.ignore();

	// 입력 받은 개수만큼 동적할당
	Circle* circles = new Circle[num];
	
	// 존재하는 원의 개수만큼 for문 동작
	for (int i = 0; i < num; i++) {
		Circle c;
		int radius = 1 + (rand() % 100);
		c.setRadius(radius);

		circles[i] = c;

		// 면적의 크기가 100보다 크면 개수를 증가시킴
		if (c.getArea() > 100) {
			cnt++;
		}

		cout << "원 " << i << "의 반지름 >> " << radius << endl;
	}

	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다." << endl;
	
	// 메모리 할당 해제
	delete[] circles;

	return 0;
}