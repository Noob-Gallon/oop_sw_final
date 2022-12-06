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
		// �Ҹ��ڿ��� Ư���� �������� ���� �����Ƿ�, ������ �������� �ʴ´�.
	}

	// getter, setter ����
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

	// �ð��� ����ϴ� �Լ�
	void print() {
		cout << "Time ��ü: " << hour << ":" << min << ":" << sec << endl;
	}
};

// isEqual�� overloading�ϹǷ�, reference type ���ڿ�
// pointer type ���� �� ���� �Լ��� ���� overloading ����.
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
		cout << "�ð��� ��ġ�մϴ�. - by reference" << endl;
	}
	else {
		cout << "�ð��� �ٸ��ϴ�. - by reference" << endl;
	}

	if (isEqual(t1, t3)) {
		cout << "�ð��� ��ġ�մϴ�. - by reference" << endl;
	}
	else {
		cout << "�ð��� �ٸ��ϴ�. - by reference" << endl;
	}

	// pointer type overloading function checking...
	// create instances
	Time* ptr1 = &t1;
	Time* ptr2 = &t2;
	Time* ptr3 = &t3;

	if (isEqual(ptr1, ptr2)) {
		cout << "�ð��� ��ġ�մϴ�. - by pointer" << endl;
	}
	else {
		cout << "�ð��� �ٸ��ϴ�. - by pointer" << endl;
	}

	if (isEqual(ptr1, ptr3)) {
		cout << "�ð��� ��ġ�մϴ�. - by pointer" << endl;
	}
	else {
		cout << "�ð��� �ٸ��ϴ�. - by pointer" << endl;
	}

	return 0;
}