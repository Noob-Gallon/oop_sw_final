#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(void) {

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

	if (is1.size() != is2.size()) {
		cout << "ǥ���� �ƴմϴ�." << endl;
		return 0;
	}

	for (int i = 0; i < is1.size(); i++) {
		
		if (is1[i] != is2[i]) {
			cout << "ǥ���� �ƴմϴ�." << endl;
			return 0;
		}
	}

	cout << "ǥ���Դϴ�." << endl;

	return 0;
}