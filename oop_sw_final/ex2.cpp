#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

// algorithm
// sort
// find, find_if
// count, count_if
// remove, remove_if
// copy
// reverse
// for_each
// 모두다 iterator 기반. 따라서, stack, queue, priority_queue는 불가.

#define myPair pair<string, int>

using namespace std;

template<typename T>
class MyCompare {
public:
	bool operator()(T a, T b) {
		if (a < b) {
			return false;
		}
		
		return true;
	} 
};

template <typename T, typename K>
void forEachFunc(T _t, K _k) {
	cout << _t << " " << _k << endl;
}

int main(void) {

	/*
	list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_front(10);
	list.push_back(10);

	// list는 indexing이 불가.
	for (auto& _e : list) {
		cout << _e << endl;
	}

	while (1) {

		auto it = find_if(list.begin(), list.end(), [](int _x) {
			return (_x % 2 == 0);
		});

		if (it == list.end()) {
			break;
		}
		else {
			list.erase(it);
		}
	}

	cout << "erasing even" << endl;
	for (auto& _e : list) {
		cout << _e << endl;
	}

	while (1) {

		auto it = find_if(list.begin(), list.end(), [](int _x) {
			return (_x % 2 != 0);
		});

		if (it == list.end()) {
			break;
		}
		else {
			list.erase(it);
		}
	}

	cout << "erasing odd" << endl;
	for (auto& _e : list) {
		cout << _e << endl;
	}

	cout << "\n\n\n";
	*/

	cout << "Stack" << endl;
	stack<int> my_stack;
	stack<int, vector<int>> vect_stack;
	stack<int, list<int>> list_stack;

	my_stack.push(1);
	my_stack.push(2);
	my_stack.push(3);
	my_stack.push(4);
	my_stack.push(5);

	cout << my_stack.top() << endl;
	my_stack.pop(); // pop은 return하지 않음.
	cout << my_stack.top() << endl;
	
	// stack은 iterator 반환이 불가능.
	cout << "\n\n\n";

	cout << "Queue" << endl;
	queue<int> my_queue;
	queue<int, vector<int>> vect_queue;
	queue<int, list<int>> list_queue;
	my_queue.push(1);
	my_queue.push(2);
	my_queue.push(3);
	my_queue.push(4);
	my_queue.push(5); 
	cout << "front : " << my_queue.front() << " back : " << my_queue.back() << endl;
	my_queue.pop();
	cout << "front : " << my_queue.front();
	
	// queue는 iterator 반환이 불가능.
	cout << "\n\n\n";

	cout << "Priority_Queue" << endl;

	priority_queue<int> pq;
	priority_queue<int, vector<int>> vect_pq;

	for (int i = 5; i > 0; i--) {
		pq.push(i);
		vect_pq.push(i);
	}	
	
	while (pq.empty() == false) {
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << endl;
	while (vect_pq.empty() == false) {
		cout << vect_pq.top() << endl;
		vect_pq.pop();
	}

	cout << "pq size : " << pq.size() << endl;
	cout << "vect_pq size : " << vect_pq.size() << endl;
	cout << "\n\n\n";

	// vector로 지정하지 않으면 priority queue 함수 지정 불가능.
	// Compare<int> class를 만들고, public:으로 () overloading, bool return compare 함수 생성.
	priority_queue<int, vector<int>, MyCompare<int>> r_pq;
	for (int i = 5; i > 0; i--) {
		r_pq.push(i);
	}

	while (r_pq.empty() == false) {
		cout << r_pq.top() << endl;
		r_pq.pop();
	}

	// pq는 iterator 반환이 불가능...
	cout << "r_pq size : " << r_pq.size() << endl;
	cout << "\n\n\n";

	cout << "Deque" << endl;
	// deque은 iterator반환 가능!
	deque<int> dq = { 3, 2, 1, 5, 4 };
	dq.push_front(10);
	dq.push_back(20);

	for (auto& _e : dq) {
		cout << _e << endl;
	}

	sort(dq.begin(), dq.end(), [](int& _v1, int& _v2) {
		return (_v1 > _v2);
	});

	cout << endl;
	for (auto& _e : dq) {
		cout << _e << endl;
	}

	reverse(dq.begin(), dq.end());
	cout << endl;
	for (auto& _e : dq) {
		cout << _e << endl;
	}

	cout << "dq size : " << dq.size() << endl;
	cout << "the num of even : " << count_if(dq.begin(), dq.end(), [](int _x) {
		return (_x % 2 == 0);
	}) << endl;

	while (1) {

		static int cnt = 0;

		auto it = find_if(dq.begin(), dq.end(), [](int _x) {
			return (_x % 2 == 0);
		});

		if (it == dq.end()) {
			break;
		}
		else {
			dq.erase(it);
			cnt++;
			cout << "erasing #" << cnt << endl;
		}
	}

	cout << endl;
	for (auto& _e : dq) {
		cout << _e << endl;
	}

	deque<int> cp_dq;
	// copy는 쓰지말고, iterator로 돌면서
	// 복사해주는 것이 좋겠다. => 써도 되는데, resize 원본과 똑같이 필요.

	cout << endl;
	cp_dq.resize(dq.size()); // size를 변경해주고 복사한다.
	/*for (int i = 0; i < dq.size(); i++) {
		cp_dq[i] = dq[i];
	}*/
	copy(dq.begin(), dq.end(), cp_dq.begin());

	for (auto& _e : cp_dq) {
		cout << _e << endl;
	}

	for_each(dq.begin(), dq.end(), [](int _x) {
		cout << _x << " + " << _x << " = " << 2 * _x << endl;
	});

	cout << "\n\n\n";

	cout << "Map" << endl;
	// map과 set은 순서가 없다.
	map<string, int> my_map;

	my_map["apple"] = 10;
	my_map["banana"] = 20;
	my_map["arape"] = 30;
	my_map["biwi"] = 40;
	my_map["aelon"] = 50;

	vector<myPair> myVect;
	myVect.resize(my_map.size());
	cout << "Check!\n";
	for (auto i = my_map.begin(); i != my_map.end(); i++) {
		myPair mp;
		mp.first = (*i).first;
		mp.second = (*i).second;
		
		myVect.push_back(mp);
	}

	sort(myVect.begin(), myVect.end(), [](myPair& _a, myPair _b) {
		return(_a.second > _b.second);
	});

	for (auto& _e : myVect) {
		cout << _e.first << " " << _e.second << endl;
	}

	// my_map.erase(my_map.begin());
	for (auto& _e : my_map) {
		cout << _e.first << "의 가격은 : " << _e.second << endl;
	}

	// map은 algorithm STL 사용이 힘들다. key : value 쌍이어서...
	// 그냥 iterator 돌면서 custom으로 만드는게 나을듯.
	cout << endl;
	for (auto i = my_map.begin(); i != my_map.end(); i++) {
		
		if ( ((*i).first)[0] < 'c') {
			cout << (*i).first << " " << (*i).second << endl;
		}
	}
	for (auto& _e : my_map) {
		cout << _e.first << "의 가격은 : " << _e.second << endl;
	}
	// reverse 불가.
	/*reverse(my_map.begin(), my_map.end());
	for (auto& _e : my_map) {
		cout << _e.first << "의 가격은 : " << _e.second << endl;
	}*/
	// 만약, 역순으로 탐색하고 싶다면, iterator를 거꾸로 만들어서 하면 됨.

	// auto it = my_map.find("apple");
	// if (auto it != my_map.end()) my_map.erase(it);

	// my_map.count("apple");

	cout << "\n\n\n";
	cout << "Set" << endl;

	set<int> my_set; // set은 insert이다.
	my_set.insert(1);
	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(2);
	my_set.insert(3);
	my_set.insert(3);

	for (auto& _e : my_set) {
		cout << _e << endl;
	}

	my_set.erase(my_set.find(1));
	cout << my_set.count(2) << endl;

	// map과 set은 이전의 container들에 적용되던
	// algorithm 헤더에 있는 count, remove, find, reverse, sort 적용 불가능. for_each는 가능할 것(map은 불가)
	// 그냥, range based for loop돌면 됨...

	cout << endl;
	for_each(my_set.begin(), my_set.end(), [](int _x) {
		cout << _x << endl;
	});

	string str = "abcdefg";
	cout << str << endl;

	/*str.erase(0, str.size()-1);
	cout << str << endl;*/

	str.insert(3, "AAA");
	cout << str << endl;
	str.insert(str.size(), "Last!");
	cout << str << endl;

	reverse(str.begin(), str.end());
	cout << str << endl;

	return 0;
}