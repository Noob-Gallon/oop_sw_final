#include <iostream>

using namespace std;

template<typename T>
bool isEqual(T list1, T list2, int size) {

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