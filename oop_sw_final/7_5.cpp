#include <iostream>

using namespace std;

// Generic을 이용해 isEqual을 template 함수로 정의한다.
template<typename T>
bool isEqual(T list1, T list2, int size) {

	// 두 개의 객체가 같은지 다른지 비교
	for (int i = 0; i < size; i++) {
		
		if (list1[i] != list2[i])
		{
			return false;
		}
	}

	return true;
}

int main(void) {

	double list1[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	double list2[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };

	cout << boolalpha;
	cout << isEqual(list1, list2, 5) << endl;

	return 0;
}