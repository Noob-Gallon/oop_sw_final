#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;


int main(void) {

	vector<int> vect;
	
	int in;
	int sum = 0;

	// vector�� ������ �Է¹޴´�.
	while (1) {
		cout << "������ �Է��Ͻÿ�(������ ����): ";
		cin >> in;

		if (in < 0) {
			break;
		}
		vect.push_back(in);
	}

	// ������ ���Ѵ�.
	for (auto& _e : vect) {
		sum += _e;
	}

	// ����� ���Ѵ�.
	cout << "���=" << sum / vect.size() << endl;

	return 0;
}