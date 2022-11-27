#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

// map과 set은 iterator를 반환할 수 있다.
// map, set은 key 기반이기 때문에, 자체적으로 find를 지원한다.
// find를 이용하면 iterator를 반환하는데, 이를 erase에 사용할 수 있다.
// 또, iterator가 반환되기 때문에, algorithm에 있는 find, find_if도 사용 가능하다.
// map과 set은 iterator를 이용해 한 번에 여러 개를 지우는 것은 불가능?

int main(void) {

	cout << "Set\n\n";

	set<int> my_set;
	map<string, int> my_map;

	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(3);
	my_set.insert(4);
	my_set.insert(5);
	my_set.insert(my_set.end(), 10);

	// 이런식으로 erasing은 불가능?
	// my_set.erase(my_set.begin(), my_set.begin() + 2);

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	cout << "\n";

	// set과 map은 iterator가 나온다...
	// 그 말은 즉슨, find가 가능하고,
	// 이를 통해 key에 대한 iterator를 얻을 수 있다.
	// 얻고 나면, erase로 지우기 가능.

	my_map["abc"] = 1;
	my_map["def"] = 2;
	my_map["ghi"] = 3;

	// 2가 지워짐...
	cout << "2 is erased...\n\n";
	auto it = my_set.find(2);
	if (it == my_set.end()) {
		cout << "찾는 원소가 없음." << endl;
	}
	else {
		my_set.erase(it);
	}

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	while (1) {
		auto it = find_if(my_set.begin(), my_set.end(), [](int x) {
			return (x % 2 == 0);
		});

		if (it == my_set.end()) {
			break;
		}

		my_set.erase(it);
	}

	cout << endl;

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	// set은 순서가 없으므로, sort나 reverse 불가능...
	// 중간에 insert해도 값이 그냥 뒤로 들어감. (확인 필요)
	// reverse(my_set.begin(), my_set.end());

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	cout << "\n\n\nMap\n\n";

	string key = "abc";
	auto it2 = my_map.find(key);
	if (it2 == my_map.end()) {
		cout << "찾는 원소가 없음." << endl;
	}
	else {
		my_map.erase(it2);
	}

	for (auto& _e : my_map) {
		cout << "key : " << _e.first << ", value : " << _e.second << endl;
	}

	cout << "\n\n\n";

	for (auto i = my_map.begin(); i != my_map.end(); i++) {
		cout << "key : " << (*i).first << ", value : " << (*i).second << endl;
	}

	// 결론, map과 set은 reverse 불가능!
	// 사실 얘네는 key : value 쌍으로 들어가는 것들이라서
	// sorting이나 reverse가 되는 것이 논리적으로 더 이상하긴 함.
	// reverse(my_map.begin(), my_map.end());
	
	return 0;
}