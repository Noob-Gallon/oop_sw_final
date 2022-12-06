#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	// 파일을 생성하고 써야하므로, ofstream 객체 생성.
	ofstream os("sample.txt");

	int buffer[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// 파일에 buffer의 원소를 쓴다.
	for (auto& _e : buffer) {
		os << _e << " ";
	}

	return 0;
}