#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void) {

	// ������ ����� ���� ����ߴ� �ڵ�
	/*
	ofstream os("sample2.txt");
	
	char buffer[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	for (auto& _e : buffer) {
		os << _e;
	}
	os.close();
	*/

	ifstream is("sample2.txt");
	// �ϳ��� file stream�� ���� �ٸ� file stream�� ������
	// �ݵ�� close�� ���־�� �Ѵ�...(�ڵ����� close�Ǵ� �Ͱ��� ����)

	is.seekg(0, ios::end);
	int len = is.tellg(); // get current position idx... (eof�̹Ƿ�, file len + 1)
	is.seekg(0, ios::beg); // ������ �ٽ� �б� ���� �����͸� ó������ ��������.

	char* buf = new char[len];
	// ���� ������ ���̿� ���߾� ���� ����.

	char c;

	int idx = 0;
	while (is >> c) { // char �о����.
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