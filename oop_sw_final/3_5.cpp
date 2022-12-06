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
	// postfix가 아니므로, 실제의 동작과는 달리 
	// return은 하지 않는다고 가정한다.
	
	// prefix
	// 만약 59분인 상태에서 ++가 된다면, 시간이 증가하고
	// 분은 0이된다. 그런데, 시간이 23이고 분이 59라면
	// 시간도 0이 되어야 한다.
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

	// 랜덤한 시각 생성
	Time time(rand() % 24, rand() % 60);
	time.displaytime();

	time++;
	time.displaytime();

	cout << endl;

	// 23시 59분의 경우 제대로 ++가 되는지 체크
	Time time2(23, 59);
	time2.displaytime();
	time2++;
	time2.displaytime();

	return 0;
}