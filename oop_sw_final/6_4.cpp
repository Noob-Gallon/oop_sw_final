#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void) {

	ifstream is("sample2.txt");

	// seekg는 읽는 포인터이다.
	// tellg를 이용해서 미리 글자수를 읽어들인다.
	is.seekg(0, ios::end);
	int len = is.tellg();
	is.seekg(0, ios::beg);
	// tellg() : Get position in input sequence...
	
	char* str = new char[len];

	char c;
	int idx = 0;
	while (is >> c) {
		str[idx++] = c;
	}

	// 동적할당 받은 string을 algorithm header에 정의된
	// reverse를 통해 뒤집는다.
	reverse(str, str+len);

	for (int i = 0; i < len; i++) {
		cout << str[i];
	}

	return 0;
}