#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Time {
private:
	int hours;
	int minutes;

public:
	Time() : hours(0), minutes(0) {
	}
	Time(int h, int m) : hours(h), minutes(m) {
	}

	void displaytime() {
		cout << hours << ": " << minutes << endl;
	}

	// 여기서는 동작이 논리적으로 prefix나
	// postfix가 아니므로, return은 하지 않는다고 가정한다.
	// 
	// prefix
	void operator++() {
		if (minutes == 59) {

			minutes = 0;

			if (hours == 23) {
				hours = 0;
				return;
			}

			hours++;
		}
		else {
			minutes++;
		}
	}
	// postfix
	void operator++ (int) {
		if (minutes == 59) {

			minutes = 0;

			if (hours == 23) {
				hours = 0;
				return;
			}

			hours++;
		}
		else {
			minutes++;
		}
	}
};

int main(void) {

	srand(time(NULL));

	Time time(rand() % 24, rand() % 60);
	time.displaytime();

	time++;
	time.displaytime();

	cout << endl;

	Time time2(23, 59);
	time2.displaytime();
	time2++;
	time2.displaytime();

	return 0;
}