#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// algorithm�� ���� �� ����� �Լ��̰�,
// container�� ���� ���� ����� Ŭ����?

template<typename T>
class MyCompare { // priority queue �񱳿� class...
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
	cout << "���� : " << _str << endl;
}

int main(void) {

	vector<string> myf = { "��", "���", "�ٳ���", "�丶��", "��", "����丶��"};

	auto it = find(myf.begin(), myf.end(), "�丶��");
	
	if (it == myf.end()) {
		cout << "0" << endl;
	}
	else {
		cout << *it << endl;
	}

	auto it2 = find_if(myf.begin(), myf.end(), myCondition);
	// vector�ȿ� ����ִ� ������
	// Ư�� ������ �����ϴ� ������ ������ ����!

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