#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// algorithm에 들어가는 비교 방법은 함수이고,
// container에 들어가는 정렬 방법은 클래스?

template<typename T>
class MyCompare { // priority queue 비교용 class...
	bool operator()(T _a, T _b) {
		if (_a < _b) {
			return true;
		}

		return false;
	}
};

bool myCondition(string _str) {
	if (_str.length() >= 6) {
		return true;
	}
	else {
		return false;
	}
}

bool my_str_sort(string _a, string _b) {
	if (_a < _b) {
		return true;
	}
	else {
		return false;
	}
}

void my_func(string& _str) {
	cout << "과일 : " << _str << endl;
}

int main(void) {

	vector<string> myf = { "감", "사과", "바나나", "토마토", "배", "방울토마토"};

	auto it = find(myf.begin(), myf.end(), "토마토");
	
	if (it == myf.end()) {
		cout << "0" << endl;
	}
	else {
		cout << *it << endl;
	}

	auto it2 = find_if(myf.begin(), myf.end(), myCondition);
	// vector안에 들어있는 원소중
	// 특정 조건을 만족하는 원소의 개수를 세라!

	if (it2 == myf.end()) {
		cout << "0" << endl;
	}
	else {
		cout << *it2 << endl;
	}

	sort(myf.begin(), myf.end(), my_str_sort);
	
	for (auto& _e : myf) {
		cout << _e << endl;
	}

	cout << "\n";
	for_each(myf.begin(), myf.end(), my_func);

	return 0;
}