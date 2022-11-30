#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main(void) {

	vector<int> vect;
	
	int in;
	int sum = 0;
	while (1) {
		cout << "정수를 입력하시오(음수는 종료): ";
		cin >> in;

		if (in < 0) {
			break;
		}
		vect.push_back(in);
	}

	for (auto& _e : vect) {
		sum += _e;
	}

	cout << "평균=" << sum / vect.size() << endl;

	return 0;
}