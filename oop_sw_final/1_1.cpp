#include <iostream>

using namespace std;

int main(void) {

	int num;
	
	// ������ �Է¹޴´�.
	cout << "�� ���� ������ �Է��մϱ�? ";
	cin >> num;

	// �Է¹��� ũ�⸸ŭ �����Ҵ� �޴´�.
	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		int input;

		cout << "������ �Է��Ͻÿ� : ";
		cin >> input;

		arr[i] = input;
	}

	cout << "�Էµ� ������: ";
	
	for (int i = 0; i < num; i++) {
		cout << arr[i] << ", ";
	}

	// �޸� �Ҵ� ����
	delete[] arr;

	return 0;
}