#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	ifstream is("test.txt");

	char c;

	while (!is.eof()) { // eof면 종료...
		is.get(c); // char 한 글자씩 가져온다.

		cout << c;
	}

	return 0;
}