#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {

	vector<int> vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(1);

	cout << vect.size() << endl;

	for (auto& _e : vect) {
		cout << _e << endl;
	}

	while (1) {

		auto it = find_if(vect.begin(), vect.end(), [](int _x) {
			return (_x % 2 == 0);
		});

		if (it == vect.end()) {
			break;
		}
		else {
			vect.erase(it);
		}
	}

	cout << "erasing even" << endl;
	for (auto& _e : vect) {
		cout << _e << endl;
	}

	while (1) {
		
		auto it = find(vect.begin(), vect.end(), 1);

		if (it == vect.end()) {
			break;
		}
		else {
			vect.erase(it);
		}
	}

	cout << "erasing 1" << endl;
	for (auto& _e : vect) {
		cout << _e << endl;
	}

	while (1) {

		auto it = find(vect.begin(), vect.end(), 3);

		if (it == vect.end()) {
			break;
		}
		else {
			vect.erase(it);
		}
	}

	cout << "erasing 3" << endl;
	for (auto& _e : vect) {
		cout << _e << endl;
	}

	return 0;
}