#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 암호화를 하는 함수.
void encoding(string str, int interval) {

	ofstream os("file.txt");

	// 만약 interval이 26보다 크거나 같다면,
	// 26으로 나눈 나머지로 계산하면 된다.
	// 왜냐면, 26만큼 돌면 원래 자리 그대로이기 때문...
	if (interval >= 26) {
		interval = interval % 26;
	}

	// 입력할 스트링의 사이즈만큼 반복문을 돌린다.
	int size = str.size();

	// 주어진 알고리즘에 따라서, 암호화를 진행한다.
	// 만약 Z보다 커진다면, 다시 A로 돌아가는 과정을
	// 거친다.
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

// 복호화를 하는 함수.
void decoding(char interval) {

	ifstream is("file.txt");

	if (interval >= 26) {
		interval = interval % 26;
	}

	// 해당 방식은 중간에 스페이스가 있을 경우
	// 스페이스를 처리하지 못한다는 한계가 있지만,
	// 문제에서 스페이스의 처리를 요구하지 않으므로
	// 스페이스 처리는 고려하지 않음.
	// vector를 고려하면 처리할 수 있을 것이다.
	is.seekg(0, ios::end);
	int size = is.tellg();

	char* str = new char[size]; // file의 내용 크기만큼 동적할당 arr를 만듦.
	is.seekg(0, ios::beg); // 파일 포인터를 다시 처음 부분으로 돌려놓음.

	char c;
	int idx = 0;

	// 파일에서 내용을 입력받고
	// 복호화하는 과정을 거친다.
	while (is >> c) {

		if (c >= 'A' && c <= 'Z') {

			// interval을 계산했는데, A보다 작다면,
			// z쪽으로 돌려줘야 한다.
			if ((char)(c - interval) < 'A') {

				int dt = ('A' - (c - interval)); // 차이가 나옴.
				str[idx] = (char)('z' - dt + 1);
			}
			else {
				str[idx] = (c + ' ') - interval;
			}
		}

		idx++;
	}

	cout << "\n\n\n복호화\n";

	// 복호화된 내용을 출력한다.
	for (int i = 0; i < size; i++) {
		cout << str[i];
	}
	cout << endl;
}

int main(void) {

	string str;
	cout << "원문 : ";
	getline(cin, str);

	int interval;
	cout << "이동거리 : ";
	cin >> interval;
	cin.ignore();

	encoding(str, interval);
	decoding(interval);

	return 0;
}