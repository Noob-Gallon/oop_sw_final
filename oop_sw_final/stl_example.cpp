#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {

	vector<int> vect = { 1, 2, 3, 4, 5 };
	vector<int> vect2;
	sort(vect.begin(), vect.end());

	remove(vect.begin(), vect.end(), 10);
	remove_if(vect.begin(), vect.end(), [](int x) {
		return (x % 2 == 0);
	});

	// map 복사하기. 그냥 참고.
	/*map<string, int> map1;
	map1["hey"] = 1;

	map<string, int> map2;
	map2.size();
	copy(map1.begin(), map1.end(), inserter(map2, map2.begin()));*/

	auto cnt = count(vect.begin(), vect.end(), 2);
	auto cnt2 = count_if(vect.begin(), vect.end(), [](int x) {
		return (x % 2 == 0);
	});
	auto it = find(vect.begin(), vect.end(), 10);
	if (it != vect.end()) {
		//do something...
	}



	auto it2 = find_if(vect.begin(), vect.end(), [](int x) {
		return (x % 2 == 0);
	});
	if (it2 != vect.end()) {
		//do something...
	}
	reverse(vect.begin(), vect.end());

	// copy를 받는 방법.
	vect2.resize(vect.size());
	copy(vect.begin(), vect.end(), vect2.begin());

	for (auto& _e : vect2) {
		cout << _e << " ";
	}

	list<int> l = { 1, 2, 3, 4, 5 };

	l.remove(10);
	l.remove_if([](int x) {
		return (x % 2 != 0);
	});

	for (auto& _e : l) {
		cout << _e << endl;
	}

	return 0;
}