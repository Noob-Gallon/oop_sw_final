#include <iostream>

using namespace std;

// 자식 클래스에 상속할 HomeAppliance 클래스 정의.
class HomeAppliance {
public:
	double price;

	// 순수 가상 함수 I_getPrice() 선언.
	virtual double I_getPrice() = 0;
};

class Refrigerator : public HomeAppliance {
private:
	// 추가적으로 필요한 할인율을 선언하고,
	// 가격 계산에 사용한다.
	double discountPercent;

public:
	Refrigerator(double _p, double _dp) {
		this->price = _p;
		this->discountPercent = _dp;
	}
	// 상속받은 클래스의 I_getPrice()를 재정의한다.
	// 생성자로 전달받은 할인율을 적용해서 return한다.
	double I_getPrice() {
		return price * (100 - discountPercent)/100;
	}
};

class Television : public HomeAppliance {
private:
	double discountPercent;

public:
	// 추가적으로 필요한 할인율을 선언하고,
	// 가격 계산에 사용한다.
	Television(double _p, double _dp) {
		this->price = _p;
		this->discountPercent = _dp;
	}
	// 상속받은 클래스의 I_getPrice()를 재정의한다.
	// 생성자로 전달받은 할인율을 적용해서 return한다.
	double I_getPrice() {
		return price * (100 - discountPercent) / 100;
	}
};

int main(void) {

	Refrigerator ref(10000, 50);
	Television tel(5000, 30);

	// HomeAppliance는 ref, tel의 부모 클래스인데,
	// ref, tel의 주소를 가리키게 되면 virtual method
	// getPrice()를 수행할 수 있다. virtual method이므로
	// 자식 클래스에서 정의된 getPrice()가 불린다.
	HomeAppliance* myAppliance[2];
	myAppliance[0] = &ref;
	myAppliance[1] = &tel;

	for (auto& _e : myAppliance) {
		cout << "가격 : " << _e->I_getPrice() << endl;
	}

	return 0;
}