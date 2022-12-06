#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void) {

	// 파일을 만들기 위해 사용했던 코드
	/*
	ofstream os("sample2.txt");
	
	char buffer[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	for (auto& _e : buffer) {
		os << _e;
	}
	os.close();
	*/

	ifstream is("sample2.txt");
	// 하나의 file stream을 열고 다른 file stream을 쓰려면
	// 반드시 close를 해주어야 한다...(자동으로 close되는 것과는 별개)

	is.seekg(0, ios::end);
	int len = is.tellg(); // get current position idx... (eof이므로, file len + 1)
	is.seekg(0, ios::beg); // 파일을 다시 읽기 위해 포인터를 처음으로 돌려놓음.

	char* buf = new char[len];
	// 현재 파일의 길이에 맞추어 버퍼 생성.

	char c;

	int idx = 0;
	while (is >> c) { // char 읽어오기.
		buf[idx] = c;
		idx++;
	}

	for (int i = 0; i < len; i++) {
		cout << buf[i];
	}
	cout << endl;

	is.close();

	ofstream os2("sample2_upper.txt");

	for (int i = 0; i < len; i++) {
		os2 << (char)toupper(buf[i]);
	}
	os2.close();
	delete[] buf;

	return 0;
}