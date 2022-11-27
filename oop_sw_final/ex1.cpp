#include <iostream>

using namespace std;

int main(void) {

	int num;

	cout << "몇 개의 정수를 입력합니까? ";
	cin >> num;

	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		int input;
		cout << "정수를 입력하시오 : ";
		cin >> input;

		arr[i] = input;
	}

	cout << "입력된 정수는: ";
	
	for (int i = 0; i < num; i++) {
		cout << arr[i] << ", ";
	}

	delete[] arr;

	return 0;
}