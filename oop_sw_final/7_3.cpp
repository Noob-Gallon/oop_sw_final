#include <iostream>

using namespace std;

// Generic�� �̿��Ͽ� template �Լ��� �����Ѵ�.
template<typename T>
T getSmallest(T _list[], int _size) {
	
	T least = _list[0];

	// for���� ������ T�� �����ϸ� ���� �߻�...
	// double�� ���´ٸ�, double�� for���� ���� �� ����.
	// ���� auto�� �ݺ������� ����. ���� ���� ���� ���Ѵ�.
	for (auto i = 1; i < _size; i++) {

		if (_list[i] < least) {
			least = _list[i];
		}
	}

	return least;
}

int main(void) {

	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	cout << "double list�� ���� ���� ���� : " << getSmallest(list, 5) << endl;

	int list2[] = { 5, 4, 3, 2, 1 };
	cout << "int list�� ���� ���� ���� : " << getSmallest(list2, 5) << endl;

	return 0;
}