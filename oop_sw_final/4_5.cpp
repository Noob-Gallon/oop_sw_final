#include <iostream>

using namespace std;

#define PI 3.14

class Shape {
protected:
	int x, y;
	string color;

// Shape�� ������ ������ �ѷ��� ������ ���Ѵٰ� �ϴµ�,
// ��ǥ�� ��Ÿ���� �������δ� �ѷ��� ������ ���� �� ����.
// ����, x, y�� ���� �� ���� ���̶�� �Ǵ��ߴ�.
// ��, �������� ������ �����̶�� �־�����
// � �������� �־����� �ʴ´ٸ� �ѷ��� ������ ���������� ���� �� ���� ������
// Shape class�� �Լ��� ���� ���� �ʰ� Circle�� ����ؼ�
// �ʿ��� ������ �����ϵ��� �Ѵ�.
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
};

class Circle : public Shape {
private:
	// ���� ������ �ѷ��� ���Ϸ���, radius�� �ʿ���.
	// ��ǥ�� �ʿ����� ����.
	int radius;

public:
	Circle(int _x, int _y, int _r, string _color) : radius(_r) {
		this->x = _x;
		this->y = _y;
		this->color = _color;
	}
	// ���� �Լ��� ��ȯ���� double�� �Ǿ��ִµ�,
	// �̷��� �ϸ� ������ ���� ó�� ������ �ѷ��� ���ÿ� ��ȯ�� �� ����.
	// ���� ������ getPerimeter() �Լ��� ���� �ѷ��� ��ȯ�ϵ��� �Ѵ�.
	double getArea() {
		return PI * radius * radius;
	}
	double getPerimeter() {
		return PI * 2 * radius;
	}
};

int main(void) {

	Circle circle(0, 0, 10, "black");

	cout << "���� : " << circle.getArea() << endl;
	cout << "�ѷ� : " << circle.getPerimeter() << endl;

	return 0;
}