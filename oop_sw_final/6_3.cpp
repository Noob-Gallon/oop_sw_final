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
	// �ϳ��� file stream�� ���� �ٸ� file stream�� ������
	// �ݵ�� close�� ���־�� �Ѵ�...(�ڵ����� close�Ǵ� �Ͱ��� ����)

	// vector<char> contents; // vector�� ���� �����ϴ� �� ���� �� ���� ��� ����?
	// file size �˾Ƴ��� �� ã��!
	is.seekg(0, ios::end);
	int len = is.tellg(); // get current position idx... (eof�̹Ƿ�, file len + 1)
	is.seekg(0, ios::beg); // �ݵ�� ���� �����͸� ó������ �������� ��... �ȱ׷� ����� ������ ����.
	cout << "len : " << len << endl;
	char* buf = new char[len];
	// ���̰� 8�̹Ƿ�, 8ĭ�� ����� ���� ����.

	char c;
	// ������ �ִ� �ڵ�. �̷��� �ۼ��ϸ�, ������ ���ڰ� �� ����Ʈ �� ����.
	// �� �׷���?
	/*while (!is.eof()) {
		is.get(c);
		cout << c << endl;
		
		contents.push_back(c);
	}*/

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