#include <iostream>
#include <string>

using namespace std;

int main(void) {

	// �Է¹��� �̸��� ����
	int num;
	cout << "�󸶳� ���� �̸��� �Է� �Ͻðڽ��ϱ�? ";
	cin >> num;
	cin.ignore();

	// �Է¹��� �� ��ŭ string type �迭 �����Ҵ�
	string* name_arr = new string[num];
	string name;

	for (int i = 0; i < num; i++) {
		cout << "�̸� �Է� # " << i + 1 << ": ";
		getline(cin, name);
		name_arr[i] = name;
	}

	cout << "\n������ �̸� ����Դϴ�." << endl;

	for (int i = 0; i < num; i++) {
		cout << "�̸� #" << i + 1 << ": ";
		cout << name_arr[i] << endl;
	}
	
	// �޸� �Ҵ� ����
	delete[] name_arr;
	return 0;
}