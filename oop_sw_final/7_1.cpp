#include <iostream>

using namespace std;

int main(void) {

	int num;
	cin >> num;

	// try, catch�� �̿��Ͽ�
	// num�� ������ �� ��� num�� throw�Ѵ�.
	try {
		
		if (num >= 0) {
			cout << "����Դϴ�." << endl;
		}
		else if (num < 0) {
			throw num;
		}
	}
	catch (int& _e) {
		cout << "error : " << _e << endl;
	}

	return 0;
}