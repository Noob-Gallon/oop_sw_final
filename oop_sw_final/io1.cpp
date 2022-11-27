#include <iostream>
#include <fstream> // file stream

using namespace std;

int main(void) {

	// 이전에 redirection을 istream, ostream으로 결정했던 것처럼,
	// ifstream, ofstream을 이용할 수 있다.

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

	// file close를 자동으로 ifstream, ofstream에서 처리해주기 때문에
	// 한번 열면 close를 할 필요가 없다...

	return 0;
}