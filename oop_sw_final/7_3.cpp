#include <iostream>

using namespace std;

// Generic을 이용하여 template 함수를 정의한다.
template<typename T>
T getSmallest(T _list[], int _size) {
	
	T least = _list[0];

	// for문의 변수를 T로 설정하면 오류 발생...
	// double이 들어온다면, double로 for문을 돌릴 수 없음.
	// 따라서 auto로 반복변수를 선언. 가장 작은 값을 구한다.
	for (auto i = 1; i < _size; i++) {

		if (_list[i] < least) {
			least = _list[i];
		}
	}

	return least;
}

int main(void) {

	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	cout << "double list의 가장 작은 값은 : " << getSmallest(list, 5) << endl;

	int list2[] = { 5, 4, 3, 2, 1 };
	cout << "int list의 가장 작은 값은 : " << getSmallest(list2, 5) << endl;

	return 0;
}