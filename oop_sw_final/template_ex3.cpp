#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <queue> // priority queue
#include <algorithm>
#include <set>
#include <map>
#include <time.h>
#include <stdlib.h>

using namespace std;

template<typename T>
class MyCompare {
public:
	bool operator()(T& _a, T& _b) {
		return _a > _b; // �̷��� �ϸ� �⺻�� �ݴ�. ��, ���� ���� �켱 ���� ����.
	}
};

bool condition(int& _e) {
	if (_e % 2 == 0) {
		return true;
	}

	return false;
}

int main(void) {

	srand(time(NULL));
	stack<int> my_stack;
	cout << "Stack\n";

	for (int i = 0; i < 5; i++) {
		my_stack.push(1 + rand() % 10);
	}

	cout << "size : " << my_stack.size() << endl;
	for (int i = 0; i < 5; i++) {
		cout << my_stack.top() << endl;
		my_stack.pop();
	}
	cout << "size : " << my_stack.size() << endl;

	stack<int, vector<int>> vector_stack;
	stack<int, list<int>> list_stack;

	cout << "\n\n\n";
	cout << "Queue\n";

	queue<int> my_queue;

	for (int i = 0; i < 5; i++) {
		my_queue.push(1 + rand() % 10);
	}

	cout << "queue size : " << my_queue.size() << endl;
	for (int i = 0; i < 5; i++) {
		cout << "front : " << my_queue.front() << endl;
		cout << "back : " << my_queue.back() << endl;
		my_queue.pop();
	}
	cout << "queue size : " << my_queue.size() << endl;

	queue<int, vector<int>> vector_queue;
	queue<int, list<int>> list_queue;

	cout << "queue size : " << my_queue.size() << endl;

	cout << "\n\n\n";
	cout << "Deque\n";

	deque<int> my_deque;
	
	for (int i = 0; i < 5; i++) {
		my_deque.push_front(1 + rand() % 10);
	}

	for (int i = 0; i < 5; i++) {
		my_deque.push_back(1 + rand() % 10);
	}

	for (auto& _e : my_deque) {
		cout << _e << endl;
	}

	cout << "deque size : " << my_deque.size() << endl;
	for (int i = 0; i < 5; i++) {
		cout << my_deque.front() << endl;
		my_deque.pop_front();
	}

	for (int i = 0; i < 5; i++) {
		cout << my_deque.back() << endl;
		my_deque.pop_back();
	}
	cout << "deque size : " << my_deque.size() << endl;

	// deque�� ���� vector�� list�� �������� �� ����?
	// vector�� ���ο� ���Ұ� �߰� �ɶ� �޸� ���Ҵ� �� ���� ���Ҹ� �����ϴ� ������� ���Ͽ�,  
	// ���Խÿ� ������ ���� �ϴ� ������ �ֽ��ϴ�.
	// deque�� �̸� �����ϰ��� ������� �����ν�,
	// ���ο� ������ �ʿ������� ������ ũ���� �޸� ����� ���� �Ҵ��Ѵ�.
	// �׷����ν�, ���� ���Ҹ� �������� �ʴ´ٴ� ������ �ִ�.
	// deque�� vector�� ���� array �����̱� ������, at ������ �����ϴ�.
	// �Ǵ� my_deque[0]�� ����, [] ���굵 �����ϴ�...
	// �׷��� ������ ���� vector�� list�� �����ϴ� ����� �������� �ʴ´�.
	
	// deque<int, vector<int>> vector_deque;
	// deque<int, list<int>> list_deque;

	cout << "\n\n\n";
	cout << "Priority Queue\n";

	priority_queue<int> pq1;
	priority_queue<int, vector<int>> pq2;
	priority_queue<int, list<int>> pq3;
	priority_queue<int, vector<int>, MyCompare<int>> pq4;
	
	for (int i = 0; i < 5; i++) {
		pq4.push(1 + rand() % 10);
	}

	for (int i = 0; i < 5; i++) {
		cout << pq4.top() << endl;
		pq4.pop();
	}

	cout << "\n\n\n";
	cout << "Set\n\n";

	set<int> my_set;
	
	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(1);
	my_set.insert(3);
	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(3);
	my_set.insert(5);

	cout << "set size : " << my_set.size() << endl;

	// iterator�� ����� ����.
	// ��, at�̳� []�� indexing�� �Ұ�...
	for (auto i = my_set.begin(); i != my_set.end(); i++) {
		cout << *i << endl;
	}

	// set�� ������ �����Ƿ�, sorting�� �Ұ����ϴ�.
	// sort(my_set.begin(), my_set.end());

	auto it = my_set.find(3);
	if (it != my_set.end()) {
		cout << "find�� ��� : " << *it << endl;
	}

	int len = my_set.size();
	my_set.erase(3); // set�� key�� �����Ƿ�, key�� ���� �� ����...

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	// find�� ���� iterator�� �޾Ƽ� erase�ϱ�
	auto iterator = my_set.find(5);
	my_set.erase(iterator);

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	cout << "\n\n\n";
	cout << "Map\n\n";

	map<string, int> my_map;
	my_map["john"] = 10;
	my_map["tom"] = 20;

	auto it2 = my_map.find("tom");
	if (it2 != my_map.end()) {
		cout << "�ֱ� ����?" << endl;
	}

	my_map.erase("john");
	auto it3 = my_map.find("john");
	if (it3 != my_map.end()) {
		cout << "�ֱ� ����?" << endl;
	}
	else {
		cout << "����\n";
	}

	for (auto i = my_map.begin(); i != my_map.end(); i++) {

	}

	return 0;
}