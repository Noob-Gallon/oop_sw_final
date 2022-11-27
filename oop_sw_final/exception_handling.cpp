#include <iostream>

using namespace std;

int main(void) {

	try {
		int person = 0;

		if (person == 0) {
			throw person;
		}
		else {
			throw 'c';
		}
	}
	catch (int e) {
		cout << "Integer Exception catched! : " << e << endl;
	}
	catch (char c) {
		cout << "Character exception catched! : " << c << endl;
	}

	return 0;
}