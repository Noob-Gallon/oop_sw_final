#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	vector<int> years;

	cout << "������ �Է��Ͻÿ�. (�׸��Ϸ��� -999)" << endl;
	int year;

	while (1) {
		cin >> year;

		if (year == -999) {
			break;
		}
		else if (year < 0) {
			cout << "0���� ū ����� �Է��Ͻÿ�." << endl;
			continue;
		}

		years.push_back(year);
	}

	auto it = find_if(years.begin(), years.end(), [](int year) {
		return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? true : false;
	});

	if (it == years.end()) {
		cout << "������ �����ϴ�." << endl;
	}
	else {
		cout << "������ " << (*it) << endl;
	}

	return 0;
}