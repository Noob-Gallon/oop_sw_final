#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

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

	srand(time(NULL));
	int num;
	int cnt = 0;
	
	cout << "생성할 원의 개수: ";
	cin >> num;
	cin.ignore();

	Circle* circles = new Circle[num];
	
	for (int i = 0; i < num; i++) {
		Circle c;
		int radius = 1 + (rand() % 100);
		c.setRadius(radius);

		circles[i] = c;

		if (c.getArea() > 100) {
			cnt++;
		}

		cout << "원 " << i << "의 반지름 >> " << radius << endl;
	}

	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다." << endl;
	
	delete[] circles;

	return 0;
}