#include <iostream>

using namespace std;

// �ڽ� Ŭ������ ����� HomeAppliance Ŭ���� ����.
class HomeAppliance {
public:
	double price;

	// ���� ���� �Լ� I_getPrice() ����.
	virtual double I_getPrice() = 0;
};

class Refrigerator : public HomeAppliance {
private:
	// �߰������� �ʿ��� �������� �����ϰ�,
	// ���� ��꿡 ����Ѵ�.
	double discountPercent;

public:
	Refrigerator(double _p, double _dp) {
		this->price = _p;
		this->discountPercent = _dp;
	}
	// ��ӹ��� Ŭ������ I_getPrice()�� �������Ѵ�.
	// �����ڷ� ���޹��� �������� �����ؼ� return�Ѵ�.
	double I_getPrice() {
		return price * (100 - discountPercent)/100;
	}
};

class Television : public HomeAppliance {
private:
	double discountPercent;

public:
	// �߰������� �ʿ��� �������� �����ϰ�,
	// ���� ��꿡 ����Ѵ�.
	Television(double _p, double _dp) {
		this->price = _p;
		this->discountPercent = _dp;
	}
	// ��ӹ��� Ŭ������ I_getPrice()�� �������Ѵ�.
	// �����ڷ� ���޹��� �������� �����ؼ� return�Ѵ�.
	double I_getPrice() {
		return price * (100 - discountPercent) / 100;
	}
};

int main(void) {

	Refrigerator ref(10000, 50);
	Television tel(5000, 30);

	// HomeAppliance�� ref, tel�� �θ� Ŭ�����ε�,
	// ref, tel�� �ּҸ� ����Ű�� �Ǹ� virtual method
	// getPrice()�� ������ �� �ִ�. virtual method�̹Ƿ�
	// �ڽ� Ŭ�������� ���ǵ� getPrice()�� �Ҹ���.
	HomeAppliance* myAppliance[2];
	myAppliance[0] = &ref;
	myAppliance[1] = &tel;

	for (auto& _e : myAppliance) {
		cout << "���� : " << _e->I_getPrice() << endl;
	}

	return 0;
}