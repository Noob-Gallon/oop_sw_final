#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main(void) {

	srand(time(NULL));

	vector<int> vect;
	vect.resize(100);

	for (int i = 0; i < 100; i++) {
		vect[i] = rand() % 100;
	}

	int even = count_if(vect.begin(), vect.end(),
		[](int _x) {
		return (_x % 2 == 0);
	});

	cout << "���� ¦���� ����� ����: " << even << endl;

	return 0;
}