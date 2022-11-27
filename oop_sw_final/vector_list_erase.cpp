#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {

	vector<int> my_vect;

	my_vect.push_back(1);
	my_vect.push_back(1);
	my_vect.push_back(2);
	my_vect.push_back(1);
	my_vect.push_back(1);

	// vector, deque는 이와 같이 여러 개 erase가능...
	// 이 두 개만 가능한 이유는 array구조로 만들어진 것들만
	// iterator의 증감연산이 먹기 때문인 것으로 보인다.
	my_vect.erase(my_vect.begin(), my_vect.begin()+3);

	//while (1) {
	//	/*auto it = find(my_vect.begin(), my_vect.end(), 1);
	//	if (it == my_vect.end()) {
	//		break;
	//	}*/

	//	auto it = find_if(my_vect.begin(), my_vect.end(), [](int x) {
	//		return (x % 2 != 0);
	//	});
	//	
	//	if (it == my_vect.end()) {
	//		break;
	//	}

	//	my_vect.erase(it);
	//}

	for (auto& _e : my_vect) {
		cout << _e << endl;
	}

	cout << "\n\n\nList\n";

	list<int> my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(4);
	my_list.push_back(5);

	/*while (1) {
		auto it = find_if(my_list.begin(), my_list.end(), [](int x) {
			return (x % 2 != 0);
		});

		if (it == my_list.end()) {
			break;
		}
		
		my_list.erase(it);
	}*/
	
	my_list.pop_front();
	my_list.pop_back();

	for (auto& _e : my_list) {
		cout << _e << endl;
	}

	return 0;
}