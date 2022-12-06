#include <iostream>

using namespace std;

// Generic�� �̿��Ͽ� template �Լ��� �����Ѵ�.
template<typename T>
T getAverage(T list[], int size) {

	// try catch�� �̿��� error�� ������ ������ ������,
	// try���� list ���ҵ��� ����� ���Ѵ�.
	try {

		T sum = 0;

		for (auto i = 0; i < size; i++) {
			sum += list[i];
		}

		// divide by zero exception�� ����� try, catch�� �����Ѵ�.
		/*
		if (size == 0) {
			throw 0;
		}
		*/
		if (size == 0) {
			throw overflow_error("divide by zero exception");
		}

		return sum/size;
	}
	catch (exception& _e) {
		cout << "error occurred! : " << _e.what() << endl;
		return 0;
	}
}

int main(void) {

	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	double n = getAverage(list, 5);

	cout << "average value : " << n << endl;

	return 0;
}