#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	ofstream os("sample.txt");

	int buffer[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// os.write((char*)buffer, sizeof(int)*10);
	// write�� ���̳ʸ� ���Ϸ� ����...

	for (auto& _e : buffer) {
		os << _e << " ";
	}

	return 0;
}