#include <iostream>

using namespace std;

// Generic을 이용하여 template 함수를 정의한다.
template<typename T>
T getAverage(T list[], int size) {

	// try catch를 이용해 error가 생길경우 에러를 보내고,
	// try에서 list 원소들의 평균을 구한다.
	try {

		T sum = 0;

		for (auto i = 0; i < size; i++) {
			sum += list[i];
		}

		// divide by zero exception을 대비해 try, catch를 선언한다.
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