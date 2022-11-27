#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(void) {

	srand(time(NULL));

	vector<int> vect;

	for (int i = 0; i < 5; i++) {
		int num = 1 + (rand() % 100);
		vect.push_back(num);
	}

	sort(vect.begin(), vect.end(),
		[](int& _x, int& _y) { return _x < _y; });
	
	for (auto& _e : vect) {
		cout << _e << endl;
	}

	cout << "\n\n\n";

	list<int> my_list;

	for (int i = 0; i < 5; i++) {
		int num = 1 + (rand() % 100);
		my_list.push_back(num);
	}

	my_list.sort([](int& _x, int& _y) {
		return _x > _y;
	}); // list�� ������ sort �Լ��� �����ȴ�...
	// ������������ �����ϰ� �ʹٸ� ���� ����
	// ���� ���Լ��� ���� �������ָ� �ȴ�.

	for (auto& _e : my_list) {
		cout << _e << endl;
	}

	cout << "\n\n\n";

	// �Ϲ� �迭�� sort ������ ������.
	int arr[5] = { 5, 4, 3, 2, 1 };
	sort(arr, arr + 5, [](int& _x, int& _y) {
		return _x < _y;
	});
	
	for (auto& _e : arr) {
		cout << _e << endl;
	}

	return 0;
}