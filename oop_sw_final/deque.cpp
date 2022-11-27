#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {

	deque<int> my_deque;

	my_deque.push_front(1);
	my_deque.push_front(2);
	my_deque.push_front(3);
	my_deque.push_front(2);
	my_deque.push_front(1);

	for (auto i = my_deque.begin(); i != my_deque.end(); i++) {
		cout << *i << endl;
	}

	my_deque.erase(my_deque.begin(), my_deque.begin()+3); // last 전까지 자름...

	cout << "\n";
	my_deque.push_back(2);

	for (auto& _e : my_deque) {
		cout << _e << endl;
	}

	cout << "\n\n\neven numbers erased...\n";
	while (1) {
		auto it = find_if(my_deque.begin(), my_deque.end(), [](int x) {
			return (x % 2 == 0);
		});

		if (it == my_deque.end()) {
			break;
		}

		my_deque.erase(it);
	}

	my_deque.push_front(100);
	my_deque.push_back(-100);

	for (auto& _e : my_deque) {
		cout << _e << endl;
	}

	reverse(my_deque.begin(), my_deque.end());
	
	cout << "reversed...\n";

	for (auto& _e : my_deque) {
		cout << _e << endl;
	}

	return 0;
}