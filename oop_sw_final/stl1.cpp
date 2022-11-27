#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main(void) {

	vector<int> v = { 3, 2, 1, 5, 4 }; // array
	list<int> v2 = { 3, 2, 1, 5, 4 }; // doubly linked list (random access is not possible)

	for (auto& _e : v) {
		cout << _e << endl;
	}

	cout << endl;

	for (auto& _e : v2) {
		cout << _e << endl;
	}

	cout << endl;

	for (auto i = v2.begin(); i != v2.end(); i++) {
		cout << *i << endl;
	}

	cout << endl;

	for (auto i = v.begin(); i != v.end(); i++) {
		cout << *i << endl;
	}

	// list�� random access�� �ȵǹǷ�, ������ range based or iterator�θ�
	// for loop�� ���۽�ų �� ����?

	// rbegin(), rend() => �и� �����ϰ� ����� �� ���� �� ����...
	// i--�� �ؾ� �ɰ� ������, rbegin, rend�� �ϸ� i++�� �ؾ���.

	cout << endl;

	for (auto i = v.rbegin(); i != v.rend(); i++) {
		cout << *i << endl;
	}

	cout << "\n\n\n";

	deque<int> dq = { 1, 2, 3, 4, 5 };
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(100);
	dq.push_front(200);

	for (auto i = dq.begin(); i != dq.end(); i++) {
		cout << *i << endl;
	}

	dq.pop_back();
	dq.pop_front();
	cout << endl;

	for (auto i = dq.begin(); i != dq.end(); i++) {
		cout << *i << endl;
	}

	return 0;
}