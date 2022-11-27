#include <iostream>
#include <string>

using namespace std;

int main(void) {

	int num;
	cout << "얼마나 많은 이름을 입력 하시겠습니까? ";
	cin >> num;
	cin.ignore();

	string* name_arr = new string[num];
	string name;

	for (int i = 0; i < num; i++) {
		cout << "이름 입력 # " << i + 1 << ": ";
		getline(cin, name);
		name_arr[i] = name;
	}

	cout << "\n다음은 이름 목록입니다." << endl;

	for (int i = 0; i < num; i++) {
		cout << "이름 #" << i + 1 << ": ";
		cout << name_arr[i] << endl;
	}
	
	delete[] name_arr;
	return 0;
}