#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	vector<int> years;

	cout << "연도를 입력하시오. (그만하려면 -999)" << endl;
	int year;

	while (1) {
		cin >> year;

		if (year == -999) {
			break;
		}
		else if (year < 0) {
			cout << "0보다 큰 양수를 입력하시오." << endl;
			continue;
		}

		years.push_back(year);
	}

	// find_if를 이용해서 years vector에 들어있는 연도가
	// 윤년인지 판단한다. 삼항 연산자를 활용해 람다 함수를 find_if의 조건으로 넘긴다.
	auto it = find_if(years.begin(), years.end(), [](int year) {
		return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? true : false;
	});

	if (it == years.end()) {
		cout << "윤년이 없습니다." << endl;
	}
	else {
		cout << "윤년은 " << (*it) << endl;
	}

	return 0;
}