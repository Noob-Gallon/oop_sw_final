#include <iostream>
#include <fstream> // file stream

using namespace std;

int main(void) {

	// ������ redirection�� istream, ostream���� �����ߴ� ��ó��,
	// ifstream, ofstream�� �̿��� �� �ִ�.

	{
		ofstream os("test.txt");

		for (int i = 0; i < 100; i++) {
			os << i << " ";
		}
	}

	ifstream is("test.txt");

	int number;

	while (is >> number) {
		cout << number << endl;
	}

	// file close�� �ڵ����� ifstream, ofstream���� ó�����ֱ� ������
	// �ѹ� ���� close�� �� �ʿ䰡 ����...

	return 0;
}