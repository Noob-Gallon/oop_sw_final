#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {

	map<string, string> dict;

	string word;
	string meaning;
	int option;

	while (1) {

		cout << " ============================ " << endl;
		cout << " 단어 추가 : 1, 단어 테스트 : 2, 종료 : 3" << endl;
		cout << " ============================ " << endl;
		cout << "하나를 선택하세요. : ";

		cin >> option;
		cin.ignore();

		if (option == 1) {
			cout << "추가할 단어 : ";
			getline(cin, word);

			cout << "추가할 의미 : ";
			getline(cin, meaning);

			dict[word] = meaning;
		}
		else if (option == 2) {

			// map은 iterator를 구하면 key가 오름차순으로 나온다!
			for (auto i = dict.begin(); i != dict.end(); i++) {

				cout << "단어 : " << (*i).first << endl;
				cout << "의미는 무엇입니까? : ";

				string answer;
				getline(cin, answer);

				if ((*i).second == answer) {
					cout << "맞췄습니다." << endl;
				}
				else {
					cout << "틀렸습니다." << endl;
				}
			}
		}
		else if (option == 3) {
			break;
		}
	}

	return 0;
}