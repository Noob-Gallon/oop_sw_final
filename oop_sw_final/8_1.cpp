#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;


int main(void) {

	vector<int> vect;
	
	int in;
	int sum = 0;

	// vector에 정수를 입력받는다.
	while (1) {
		cout << "정수를 입력하시오(음수는 종료): ";
		cin >> in;

		if (in < 0) {
			break;
		}
		vect.push_back(in);
	}

	// 총합을 구한다.
	for (auto& _e : vect) {
		sum += _e;
	}

	// 평균을 구한다.
	cout << "평균=" << sum / vect.size() << endl;

	return 0;
}