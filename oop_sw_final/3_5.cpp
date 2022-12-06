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

	// ���⼭�� ������ �������� prefix��
	// postfix�� �ƴϹǷ�, ������ ���۰��� �޸� 
	// return�� ���� �ʴ´ٰ� �����Ѵ�.
	
	// prefix
	// ���� 59���� ���¿��� ++�� �ȴٸ�, �ð��� �����ϰ�
	// ���� 0�̵ȴ�. �׷���, �ð��� 23�̰� ���� 59���
	// �ð��� 0�� �Ǿ�� �Ѵ�.
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

	// ������ �ð� ����
	Time time(rand() % 24, rand() % 60);
	time.displaytime();

	time++;
	time.displaytime();

	cout << endl;

	// 23�� 59���� ��� ����� ++�� �Ǵ��� üũ
	Time time2(23, 59);
	time2.displaytime();
	time2++;
	time2.displaytime();

	return 0;
}