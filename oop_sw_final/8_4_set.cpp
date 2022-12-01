#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <string>

using namespace std;

class Dictionary {
private:
	map<string, string> dict;
	set<string> questions;
	vector<string> meanings;
	bool operating = true;

public:
	Dictionary() {}
	void showMenu() {

		while (operating) {

			cout << " ============================ " << endl;
			cout << " 단어 추가 : 1, 단어 테스트 : 2, 종료 : 3" << endl;
			cout << " ============================ " << endl;
			cout << "하나를 선택하세요. : ";

			int in;
			cin >> in;

			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				continue;
			}
			else {
				cin.ignore();
			}

			switch (in) {
			case 1:
				addWord();
				break;
			case 2:
				wordTest();
				break;
			case 3:
				operating = false;
				break;
			default:
				cout << "잘못된 입력입니다." << endl;
			}
		} 
	}
	void addWord() {

		string word;
		string meaning;

		cout << "추가할 단어 : ";
		getline(cin, word);

		cout << "추가할 의미 : ";
		getline(cin, meaning);

		meanings.push_back(meaning); // 나중에 문제 출력을 위해 의미 저장
		dict[word] = meaning; // 사전에 key : word, value : meaning으로 단어 저장.
	}
	void wordTest() {

		if (meanings.size() < 4) {
			cout << "단어를 네 개 이상 입력하고 다시 시도하십시오." << endl;
			return;
		}

		string answer; // 정답 '의미' string

		// dict(map)를 key 오름차순으로 탐색한다...
		for (auto i = dict.begin(); i != dict.end(); i++) {

			questions.clear();

			answer = (*i).second; // 정답을 먼저 선택. (문제의 정답은 key의 오름차순으로 선택되며, '단어'가 아닌 '의미'가 정답임.)
			questions.insert(answer);

			while (questions.size() < 4) {

				int random_idx = rand() % meanings.size(); // answers 중에서 정답이 아닌 것중 선지로 출력할 것을 선택하기 위한 idx 변수.
				questions.insert(meanings[random_idx]);
			} // 이곳을 넘어가면, 정답 이외의 3개의 답이 모두 선택된다.

			string answer_array[4];
			int idx = 0;

			for (auto j = questions.begin(); j != questions.end(); j++) {
				answer_array[idx] = (*j);
				idx++;
			}

			cout << "Q. " << (*i).first << "의 의미는?\n";
			cout << "(1) " << answer_array[0] << " (2) " << answer_array[1] << " (3) " << answer_array[2] << " (4) " << answer_array[3] << endl;

			int answer_number;
			cin >> answer_number;

			if (cin.fail()) {
				cout << "잘못된 입력입니다. 오답으로 처리됩니다." << endl;
				cin.clear();
				cin.ignore();
				continue;
			}
			else {
				cin.ignore();
			}


			if (answer_array[answer_number - 1] == answer) {
				cout << "정답입니다!\n";
			}
			else {
				cout << "오답입니다!\n";
			}
		}
	}
};

int main(void) {

	srand(time(NULL));
	Dictionary myDict;

	myDict.showMenu();

	return 0;
}