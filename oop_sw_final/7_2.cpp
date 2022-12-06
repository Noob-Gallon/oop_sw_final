#include <iostream>

using namespace std;

int main(void) {

	string str;

	cout << "가위, 바위, 보 게임입니다." << endl;
	cout << "무엇을 내시겠습니까?: ";
	
	// try catch를 이용하여 만약 입력된 string이
	// 가위, 바위, 보가 아니라면 str을 throw한다.
	try {
		cin >> str;
		
		if (str == "가위") {
			cout << "가위를 내셨습니다." << endl;
		}
		else if (str == "바위") {
			cout << "바위를 내셨습니다." << endl;
		}
		else if (str == "보") {
			cout << "보를 내셨습니다." << endl;
		}
		else {
			throw str;
		}
	}
	catch (string& _str) {
		cout << "오류: \"가위\", \"바위\", \"보\" 중에서만 선택하세요." << endl;
	}

	return 0;
}