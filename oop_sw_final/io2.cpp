#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	ifstream is("test.txt");

	char c;

	while (!is.eof()) { // eof�� ����...
		is.get(c); // char �� ���ھ� �����´�.

		cout << c;
	}

	return 0;
}