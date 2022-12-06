#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void) {

	ifstream is("sample2.txt");

	// seekg�� �д� �������̴�.
	// tellg�� �̿��ؼ� �̸� ���ڼ��� �о���δ�.
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

	// �����Ҵ� ���� string�� algorithm header�� ���ǵ�
	// reverse�� ���� �����´�.
	reverse(str, str+len);

	for (int i = 0; i < len; i++) {
		cout << str[i];
	}

	return 0;
}