#include <iostream>

using namespace std;

int main(void) {

	int num;
	cin >> num;

	try {
		
		if (num >= 0) {
			cout << "양수입니다." << endl;
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