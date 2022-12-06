#include <iostream>

using namespace std;

class Time {
private:
	int hour, min, sec;

public:
	Time() {
		cout << "Default Constructor" << endl;
	}
	Time(int _h, int _m, int _s) : hour(_h), min(_m), sec(_s) {
		cout << "Hour Min Sec Constructor" << endl;
	}
	~Time() {
		cout << "Destructor" << endl;
		// 소멸자에서 특별히 지정해줄 것이 없으므로, 동작을 구현하지 않는다.
	}

	// getter, setter 정의
	void setHour(int _h) {
		this->hour = _h;
	}
	void setMin(int _m) {
		this->min = _m;
	}
	void setSec(int _s) {
		this->sec = _s;
	}
	int getHour() {
		return hour;
	}
	int getMin() {
		return min;
	}
	int getSec() {
		return sec;
	}

	// 시간을 출력하는 함수
	void print() {
		cout << "Time 객체: " << hour << ":" << min << ":" << sec << endl;
	}
};

// isEqual을 overloading하므로, reference type 인자와
// pointer type 인자 두 개의 함수를 만들어서 overloading 진행.
bool isEqual(Time& t1, Time& t2) {
	return (t1.getHour() == t2.getHour() &&
		t1.getMin() == t2.getMin() &&
		t1.getSec() == t2.getSec());
}

bool isEqual(Time* t1, Time* t2) {
	return (t1->getHour() == t2->getHour() &&
		t1->getMin() == t2->getMin() &&
		t1->getSec() == t2->getSec());
}

int main(void) {

	// create instances
	Time t1(12, 30, 30);
	Time t2(12, 30, 30);
	Time t3(12, 30, 15);

	t1.print();
	t2.print();
	t3.print();

	if (isEqual(t1, t2)) {
		cout << "시간이 일치합니다. - by reference" << endl;
	}
	else {
		cout << "시간이 다릅니다. - by reference" << endl;
	}

	if (isEqual(t1, t3)) {
		cout << "시간이 일치합니다. - by reference" << endl;
	}
	else {
		cout << "시간이 다릅니다. - by reference" << endl;
	}

	// pointer type overloading function checking...
	// create instances
	Time* ptr1 = &t1;
	Time* ptr2 = &t2;
	Time* ptr3 = &t3;

	if (isEqual(ptr1, ptr2)) {
		cout << "시간이 일치합니다. - by pointer" << endl;
	}
	else {
		cout << "시간이 다릅니다. - by pointer" << endl;
	}

	if (isEqual(ptr1, ptr3)) {
		cout << "시간이 일치합니다. - by pointer" << endl;
	}
	else {
		cout << "시간이 다릅니다. - by pointer" << endl;
	}

	return 0;
}