#include <iostream>

using namespace std;

class HomeAppliance {
public:
	virtual double I_getPrice() = 0;
};

class Refrigerator : public HomeAppliance {
private:
	double price;
	double discountPercent;

public:
	Refrigerator(double _p, double _dp) {
		this->price = _p;
		this->discountPercent = _dp;
	}
	double I_getPrice() {
		return price * (100 - discountPercent)/100;
	}
};

class Television : public HomeAppliance {
private:
	double price;
	double discountPercent;

public:
	Television(double _p, double _dp) {
		this->price = _p;
		this->discountPercent = _dp;
	}
	double I_getPrice() {
		return price * (100 - discountPercent) / 100;
	}
};

int main(void) {

	Refrigerator ref(10000, 50);
	Television tel(5000, 30);

	HomeAppliance* myAppliance[2];
	myAppliance[0] = &ref;
	myAppliance[1] = &tel;

	for (auto& _e : myAppliance) {
		cout << "АЁАн : " << _e->I_getPrice() << endl;
	}

	return 0;
}