#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main(void) {

	vector<int> vect;
	
	int in;
	int sum = 0;
	while (1) {
		cout << "������ �Է��Ͻÿ�(������ ����): ";
		cin >> in;

		if (in < 0) {
			break;
		}
		vect.push_back(in);
	}

	for (auto& _e : vect) {
		sum += _e;
	}

	cout << "���=" << sum / vect.size() << endl;

	return 0;
}