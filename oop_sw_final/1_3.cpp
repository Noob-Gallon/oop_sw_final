#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Circle class�� member variable radius�� ������,
// getter setter�� ��������.
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

	// ���� ���ڸ� ���� srand�� time(NULL) ���.
	srand(time(NULL));
	int num;
	int cnt = 0;
	
	// ������ ���� ������ �Է� ����.
	cout << "������ ���� ����: ";
	cin >> num;
	cin.ignore();

	// �Է� ���� ������ŭ �����Ҵ�
	Circle* circles = new Circle[num];
	
	// �����ϴ� ���� ������ŭ for�� ����
	for (int i = 0; i < num; i++) {
		Circle c;
		int radius = 1 + (rand() % 100);
		c.setRadius(radius);

		circles[i] = c;

		// ������ ũ�Ⱑ 100���� ũ�� ������ ������Ŵ
		if (c.getArea() > 100) {
			cnt++;
		}

		cout << "�� " << i << "�� ������ >> " << radius << endl;
	}

	cout << "������ 100���� ū ���� " << cnt << "�� �Դϴ�." << endl;
	
	// �޸� �Ҵ� ����
	delete[] circles;

	return 0;
}