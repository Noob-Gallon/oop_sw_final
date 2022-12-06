#include <iostream>

using namespace std;

int main(void) {

	int num;
	
	// 정수를 입력받는다.
	cout << "몇 개의 정수를 입력합니까? ";
	cin >> num;

	// 입력받은 크기만큼 동적할당 받는다.
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

	// 메모리 할당 해제
	delete[] arr;

	return 0;
}