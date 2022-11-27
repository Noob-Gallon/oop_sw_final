#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main(void) {

	set<int> my_set;

	my_set.insert(10);
	my_set.insert(20);
	my_set.insert(30);

	for (auto i = my_set.begin(); i != my_set.end(); i++) {
		cout << *i << endl;
	}

	cout << "\n\n\n";

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	cout << "\n\n\n";

	map<string, int> my_map;
	my_map["john"] = 20;
	my_map["tom"] = 19;

	cout << "john age : " << my_map["john"] << endl;
	cout << "tom age : " << my_map["tom"] << endl;

	cout << "\n\n\n";

	stack<int> my_stack;
	my_stack.push(10);
	my_stack.push(20);
	my_stack.push(30);
	cout << my_stack.top() << "\n\n\n"; // 맨 위의 값을 보여줌. pop은 안함.

	cout << "my_stack size : " << my_stack.size() << endl;

	while (!my_stack.empty()) {
		cout << my_stack.top() << endl;
		my_stack.pop(); // 반환을 하지 않음...
	}

	cout << "my_stack size : " << my_stack.size() << endl;

	cout << "\n\n\n";

	stack<int, list<int>> my_list_stack;

	queue<int> my_q;
	// queue<int, list<int>> my_list_queue;
	// queue<int, vector<int>> my_vector_queue;
	my_q.push(10);
	my_q.push(20);
	my_q.push(30);
	cout << my_q.front() << " " << my_q.back() << endl;

	cout << "my queue size : " << my_q.size() << endl;
	while (!my_q.empty()) {
		cout << my_q.front() << endl;
		my_q.pop();
	}
	cout << "my queue size : " << my_q.size() << endl;

	cout << "\n\n\n";

	priority_queue<int, vector<int>> p_que;
	// priority_queue<int> my_p_que;

	p_que.push(10);
	p_que.push(20);
	p_que.push(30);

	while (!p_que.empty()) {
		cout << p_que.top() << endl;
		p_que.pop();
	}

	return 0;
}