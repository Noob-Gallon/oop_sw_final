#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	// 파일을 읽어들여야 하므로, ifstream 객체를 생성.
	ifstream is("sample.txt");

	int sum = 0;
	int number = 0;

	// is를 통해서 file의 값을 읽어들이고 합을 셈.
	while (is >> number) {
		sum += number;
	}

	cout << "sum : " << sum << endl;

	return 0;
}