#include <iostream>

using namespace std;

int main(void) {

	string str;

	cout << "����, ����, �� �����Դϴ�." << endl;
	cout << "������ ���ðڽ��ϱ�?: ";
	
	try {
		cin >> str;
		
		if (str == "����") {
			cout << "������ ���̽��ϴ�." << endl;
		}
		else if (str == "����") {
			cout << "������ ���̽��ϴ�." << endl;
		}
		else if (str == "��") {
			cout << "���� ���̽��ϴ�." << endl;
		}
		else {
			throw str;
		}
	}
	catch (string& _str) {
		cout << "����: \"����\", \"����\", \"��\" �߿����� �����ϼ���." << endl;
	}

	return 0;
}