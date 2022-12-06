#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main(void) {

	srand(time(NULL));

	// vector에 100개의 값을 넣기 위해
	// vector를 resize한다.
	vector<int> vect;
	vect.resize(100);

	// random하게 수를 생성한다.
	for (int i = 0; i < 100; i++) {
		vect[i] = rand() % 100;
	}

	// count_if를 이용해서 vector even의 원소들 중
	// 짝수인 것의 개수를 센다.
	// 람다식을 이용한다.
	int even = count_if(vect.begin(), vect.end(),
		[](int _x) {
		return (_x % 2 == 0);
	});

	cout << "값이 짝수인 요소의 개수: " << even << endl;

	return 0;
}