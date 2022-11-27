#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typename T>
class MyCompare {
public:
	bool operator()(T _a, T _b) {
		if (_a > _b) {
			return true;
		}

		return false;
	}
};

int main(void) {

	priority_queue<int, vector<int>, MyCompare<int>> p_que;

	p_que.push(10);
	p_que.push(20);
	p_que.push(30);

	cout << "p_que size : " << p_que.size() << endl;

	while (p_que.empty() == false) {

		cout << p_que.top() << endl;
		p_que.pop();
	}

	cout << "p_que size : " << p_que.size() << endl;
	return 0;
}