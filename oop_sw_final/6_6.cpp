#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encoding(string str, int interval) {

	ofstream os("file.txt");
	
	// 만약 interval이 26보다 크거나 같다면,
	// 26으로 나눈 나머지로 계산하면 된다.
	// 왜냐면, 26만큼 돌면 원래 자리 그대로이기 때문...
	if (interval >= 26) {
		interval = interval % 26;
	}

	int size = str.size();

	for (int i = 0; i < size; i++) {
		
		cout << "str[" << i << "] : " << str[i] << endl;
		if (str[i] >= 'a' && str[i] <= 'z') {
			
			if ((str[i] + interval) > 'z') {
				int dt = (str[i] + interval) - 'z';
				str[i] = char('A' + dt - 1);
			}
			else {
				str[i] = (char)((str[i] - ' ') + interval);
			}

			os << str[i];
		}
	}

	os.close();
}

void decoding(char interval) {

	ifstream is("file.txt");

	if (interval >= 26) {
		interval = interval % 26;
	}

	// 문제 발생,
	// 이 방식은 스페이스를 글자로 처리하지 못함?
	is.seekg(0, ios::end);
	int size = is.tellg();
	cout << "\nsize is : " << size << endl;

	char* str = new char[size]; // file의 내용 크기만큼 동적할당 arr를 만듦.
	is.seekg(0, ios::beg); // 파일 포인터를 다시 처음 부분으로 돌려놓음.
	
	// a 97 ~ z 122
	// A 65 ~ z 90

	char c;
	int idx = 0;
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

	cout << "\n\n\n";

	for (int i = 0; i < size; i++) {
		cout << str[i];
	}
	cout << endl;
}

int main(void) {

	string str;
	cout << "원문 : ";
	getline(cin, str);

	// interval을 char로 설정하면 오류 발생?
	// 예를 들어, 3을 넣으면 diff가 엄청 커지고,
	// 10을 넣으면 0이 짤려서 1이 됨... 포인터 연산과 관련있음?
	int interval;
	cout << "이동거리 : ";
	cin >> interval;
	cout << "interval : " << interval << endl;
	cin.ignore();

	encoding(str, interval);
	decoding(interval);

	return 0;
}