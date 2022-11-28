#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void) {

	/*ofstream os("sample2.txt");
	
	char buffer[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	for (auto& _e : buffer) {
		os << _e;
	}
	os.close();*/

	ifstream is("sample2.txt");
	// 하나의 file stream을 열고 다른 file stream을 쓰려면
	// 반드시 close를 해주어야 한다...(자동으로 close되는 것과는 별개)

	// vector<char> contents; // vector에 내용 저장하는 것 말고 더 좋은 방법 없음?
	// file size 알아내는 법 찾음!
	is.seekg(0, ios::end);
	int len = is.tellg(); // get current position idx... (eof이므로, file len + 1)
	is.seekg(0, ios::beg); // 반드시 파일 포인터를 처음으로 돌려놔야 함... 안그럼 제대로 읽히지 않음.
	cout << "len : " << len << endl;
	char* buf = new char[len];
	// 길이가 8이므로, 8칸만 만들면 문제 없음.

	char c;
	// 오류가 있는 코드. 이렇게 작성하면, 마지막 글자가 한 바이트 더 읽힘.
	// 왜 그럴까?
	/*while (!is.eof()) {
		is.get(c);
		cout << c << endl;
		
		contents.push_back(c);
	}*/

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