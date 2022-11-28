#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	ifstream is("sample.txt");

	int sum = 0;
	int number = 0;

	while (is >> number) {
		sum += number;
	}

	cout << "sum : " << sum << endl;

	return 0;
}