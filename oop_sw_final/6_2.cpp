#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	// ������ �о�鿩�� �ϹǷ�, ifstream ��ü�� ����.
	ifstream is("sample.txt");

	int sum = 0;
	int number = 0;

	// is�� ���ؼ� file�� ���� �о���̰� ���� ��.
	while (is >> number) {
		sum += number;
	}

	cout << "sum : " << sum << endl;

	return 0;
}