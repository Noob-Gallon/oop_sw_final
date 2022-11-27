#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

// map�� set�� iterator�� ��ȯ�� �� �ִ�.
// map, set�� key ����̱� ������, ��ü������ find�� �����Ѵ�.
// find�� �̿��ϸ� iterator�� ��ȯ�ϴµ�, �̸� erase�� ����� �� �ִ�.
// ��, iterator�� ��ȯ�Ǳ� ������, algorithm�� �ִ� find, find_if�� ��� �����ϴ�.
// map�� set�� iterator�� �̿��� �� ���� ���� ���� ����� ���� �Ұ���?

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

	// �̷������� erasing�� �Ұ���?
	// my_set.erase(my_set.begin(), my_set.begin() + 2);

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	cout << "\n";

	// set�� map�� iterator�� ���´�...
	// �� ���� �ｼ, find�� �����ϰ�,
	// �̸� ���� key�� ���� iterator�� ���� �� �ִ�.
	// ��� ����, erase�� ����� ����.

	my_map["abc"] = 1;
	my_map["def"] = 2;
	my_map["ghi"] = 3;

	// 2�� ������...
	cout << "2 is erased...\n\n";
	auto it = my_set.find(2);
	if (it == my_set.end()) {
		cout << "ã�� ���Ұ� ����." << endl;
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

	// set�� ������ �����Ƿ�, sort�� reverse �Ұ���...
	// �߰��� insert�ص� ���� �׳� �ڷ� ��. (Ȯ�� �ʿ�)
	// reverse(my_set.begin(), my_set.end());

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	cout << "\n\n\nMap\n\n";

	string key = "abc";
	auto it2 = my_map.find(key);
	if (it2 == my_map.end()) {
		cout << "ã�� ���Ұ� ����." << endl;
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

	// ���, map�� set�� reverse �Ұ���!
	// ��� ��״� key : value ������ ���� �͵��̶�
	// sorting�̳� reverse�� �Ǵ� ���� �������� �� �̻��ϱ� ��.
	// reverse(my_map.begin(), my_map.end());
	
	return 0;
}