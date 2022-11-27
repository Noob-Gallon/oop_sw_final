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
	
	cout << "������ ���� ����: ";
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

		cout << "�� " << i << "�� ������ >> " << radius << endl;
	}

	cout << "������ 100���� ū ���� " << cnt << "�� �Դϴ�." << endl;
	
	delete[] circles;

	return 0;
}