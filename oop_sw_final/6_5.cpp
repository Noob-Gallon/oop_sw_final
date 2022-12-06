#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(void) {

	// 표절 검사를 해야하므로, 두 파일의 내용을 다 읽어와야 한다.
	// 따라서, vector 두 개를 선언하여 두 파일의 내용을 모두 읽어들인다.
	vector<string> is1;
	vector<string> is2;

	ifstream read1("sample2.txt");
	
	string str;
	while (getline(read1, str)) {
		is1.push_back(str);
	}

	read1.close();

	ifstream read2("sample2_copied.txt");

	while (getline(read2, str)) {
		is2.push_back(str);
	}
	
	// 우선 사이즈가 다르면 내용이 다른 것이므로,
	// 사이즈가 다른지 비교한다.
	if (is1.size() != is2.size()) {
		cout << "표절이 아닙니다." << endl;
		return 0;
	}

	// 사이즈가 같다면, for loop을 돌면서 vector의 각 원소(한 줄이 될 것임.)가
	// 같은 내용인지 체크한다.
	for (int i = 0; i < is1.size(); i++) {
		
		// 하나라도 다른 내용이 있다면, 표절이 아니다.
		if (is1[i] != is2[i]) {
			cout << "표절이 아닙니다." << endl;
			return 0;
		}
	}

	cout << "표절입니다." << endl;

	return 0;
}