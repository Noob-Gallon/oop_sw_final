#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool my_my_func(int& _i) {
	if (_i % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {

	vector<int> numbers = { 1, 2, 3, 4, 5 };
	auto count = count_if(numbers.begin(), numbers.end(), my_my_func);
	cout << "일반 함수 개수 세기 : " << count << endl;

	auto count2 = count_if(numbers.begin(), numbers.end(),
		[](int _x) { if (_x % 2 == 0) { return true; } else { return false; }}
		);
	cout << "람다 함수 개수 세기 : " << count2 << endl;

	return 0;
}