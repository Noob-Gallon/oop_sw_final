#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {

	// key : string, value : string인
	// map dict를 생성한다.
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

		// 1번 메뉴에서는
		// dict에 단어를 추가한다.

		// 사용자가 직접 추가한 단어를 통해 
		// 퀴즈를 구성할 수 있도록 구성한다.
		if (option == 1) {
			cout << "추가할 단어 : ";
			getline(cin, word);

			cout << "추가할 의미 : ";
			getline(cin, meaning);

			dict[word] = meaning;
		}
		else if (option == 2) {

			// map은 iterator를 구하면 key의 오름차순으로 iteration이 동작된다.
			// 따라서, 오름차순으로 퀴즈를 낸다.
			for (auto i = dict.begin(); i != dict.end(); i++) {

				cout << "단어 : " << (*i).first << endl;
				cout << "의미는 무엇입니까? : ";

				string answer;
				getline(cin, answer);

				// map의 iterator는 주소이므로,
				// dereferencing을 통해 객체를 참조하고
				// first(key), second(value)이므로
				// second를 통해 정답을 판별한다.
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