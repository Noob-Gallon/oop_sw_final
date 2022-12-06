#include <iostream>

using namespace std;

#define PI 3.14
#define myPair pair<double, double>

class Shape {
protected:
	int x, y;
	string color;

// Shape�� ������ ������ �ѷ��� ������ ���Ѵٰ� �ϴµ�,
// ��ǥ�� ��Ÿ���� �������δ� �ѷ��� ������ ���� �� ����.
// ����, x, y�� ���� �� ���� ���̶�� �Ǵ��ߴ�.
// ��, �������� ������ �����̶�� �־�����
// � �������� �־����� �ʴ´ٸ� �ѷ��� ������ ���������� ���� �� ���� ������
// Shape class�� �ϴ� �ƹ����Գ� �����ϰ�, Circle�� ����ؼ�
// �ʿ��� ������ �����ϵ��� �Ѵ�.
public:
	virtual myPair getArea() {
		cout << "useless..." << endl;
		myPair mp1({ 0.0, 0.0 });
		return mp1;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
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
	// ���� pair<double, double>�� ��ȯ������ �ٲٵ��� �Ѵ�.
	myPair getArea() {
		return { PI * radius * radius, PI * 2 * radius };
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
};

int main(void) {

	Circle circle(0, 0, 10, "black");

	myPair area = circle.getArea();
	cout << "���� : " << area.first << "\n�ѷ� : " << area.second << endl;

	return 0;
}