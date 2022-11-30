#include <iostream>

using namespace std;

template<typename T>
T getAverage(T list[], int size) {

	try {

		T sum = 0;

		for (auto i = 0; i < size; i++) {
			sum += list[i];
		}

		return sum/size;
	}
	catch (exception& _e) {
		cout << "error occurred! : " << _e.what() << endl;
	}
}

int main(void) {

	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	double n = getAverage(list, 5);

	cout << "average value : " << n << endl;

	return 0;
}