#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ��ȣȭ�� �ϴ� �Լ�.
void encoding(string str, int interval) {

	ofstream os("file.txt");

	// ���� interval�� 26���� ũ�ų� ���ٸ�,
	// 26���� ���� �������� ����ϸ� �ȴ�.
	// �ֳĸ�, 26��ŭ ���� ���� �ڸ� �״���̱� ����...
	if (interval >= 26) {
		interval = interval % 26;
	}

	// �Է��� ��Ʈ���� �����ŭ �ݺ����� ������.
	int size = str.size();

	// �־��� �˰��� ����, ��ȣȭ�� �����Ѵ�.
	// ���� Z���� Ŀ���ٸ�, �ٽ� A�� ���ư��� ������
	// ��ģ��.
	for (int i = 0; i < size; i++) {

		if (str[i] >= 'a' && str[i] <= 'z') {

			if ((str[i] + interval) > 'z') {
				int dt = (str[i] + interval) - 'z';
				str[i] = char('A' + dt - 1);
			}
			else {
				str[i] = (char)((str[i] - ' ') + interval);
			}

			cout << str[i];
			os << str[i];
		}
	}
	cout << endl;

	os.close();
}

// ��ȣȭ�� �ϴ� �Լ�.
void decoding(char interval) {

	ifstream is("file.txt");

	if (interval >= 26) {
		interval = interval % 26;
	}

	// �ش� ����� �߰��� �����̽��� ���� ���
	// �����̽��� ó������ ���Ѵٴ� �Ѱ谡 ������,
	// �������� �����̽��� ó���� �䱸���� �����Ƿ�
	// �����̽� ó���� ������� ����.
	// vector�� ����ϸ� ó���� �� ���� ���̴�.
	is.seekg(0, ios::end);
	int size = is.tellg();

	char* str = new char[size]; // file�� ���� ũ�⸸ŭ �����Ҵ� arr�� ����.
	is.seekg(0, ios::beg); // ���� �����͸� �ٽ� ó�� �κ����� ��������.

	char c;
	int idx = 0;

	// ���Ͽ��� ������ �Է¹ް�
	// ��ȣȭ�ϴ� ������ ��ģ��.
	while (is >> c) {

		if (c >= 'A' && c <= 'Z') {

			// interval�� ����ߴµ�, A���� �۴ٸ�,
			// z������ ������� �Ѵ�.
			if ((char)(c - interval) < 'A') {

				int dt = ('A' - (c - interval)); // ���̰� ����.
				str[idx] = (char)('z' - dt + 1);
			}
			else {
				str[idx] = (c + ' ') - interval;
			}
		}

		idx++;
	}

	cout << "\n\n\n��ȣȭ\n";

	// ��ȣȭ�� ������ ����Ѵ�.
	for (int i = 0; i < size; i++) {
		cout << str[i];
	}
	cout << endl;
}

int main(void) {

	string str;
	cout << "���� : ";
	getline(cin, str);

	int interval;
	cout << "�̵��Ÿ� : ";
	cin >> interval;
	cin.ignore();

	encoding(str, interval);
	decoding(interval);

	return 0;
}