#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <string>

using namespace std;

// 모든 기능을 Dictionary class로 구현한다.
class Dictionary {
private:
	map<string, string> dict; // 단어와 의미를 추가할 dictionary map
	set<string> questions; // 문제를 출제할 때 보기로 사용될 것을 입력하는 set
	vector<string> meanings; 
	// 문제를 출제할 때 랜덤하게 보기를 선정하기 
	// 위해 의미를 미리 담아두는 vector
	bool operating = true;

public:
	Dictionary() {}

	// 처음 main에서 수행되는 메서드.
	// 무한루프를 돌며 사용자로부터 입력을 받는다.
	void showMenu() {

		while (operating) {

			cout << " ============================ " << endl;
			cout << " 단어 추가 : 1, 단어 테스트 : 2, 종료 : 3" << endl;
			cout << " ============================ " << endl;
			cout << "하나를 선택하세요. : ";

			int in;
			cin >> in;

			// 사용자가 잘못된 입력을 넣는다면
			// 현재 입력을 무시하도록 block한다.
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				continue;
			}
			else {
				// 올바른 입력이 주어졌다면,
				// 입력 버퍼에서 \n을 제거하기 위해
				// cin.ignore()
				cin.ignore();
			}

			// switch를 이용해 사용자의 입력을 판별한다.
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

	// 사용자로부터 입력받아
	// 사전에 단어와 의미를 추가한다.
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

			// 이전에 들어간 답을 삭제하기 위해
			// set을 clear()한다.
			questions.clear();

			answer = (*i).second; // 정답을 먼저 선택. (문제의 정답은 key의 오름차순으로 선택되며, '단어'가 아닌 '의미'가 정답임.)
			questions.insert(answer); // 보기로 출력될 정답을 먼저 set에 넣어둔다.

			while (questions.size() < 4) {

				int random_idx = rand() % meanings.size(); // answers 중에서 정답이 아닌 것들 중 선지로 출력할 것을 선택하기 위한 idx 변수.
				questions.insert(meanings[random_idx]); // set으로 구현하기 때문에, 중복되어 선택된다면 추가되지 않고 그냥 넘어간다.
				// 네 개의 서로 다른 보기가 선택될 때까지 while문이 동작한다.
			} // 이곳을 넘어가면, 정답 이외의 3개의 답이 모두 선택된다.

			// 출력을 편하게 하기 위해 string 배열을 선언하고
			// set에서 답을 옮겨줌.
			string answer_array[4];
			int idx = 0;

			for (auto j = questions.begin(); j != questions.end(); j++) {
				answer_array[idx] = (*j);
				idx++;
			}

			// 보기 출력
			cout << "Q. " << (*i).first << "의 의미는?\n";
			cout << "(1) " << answer_array[0] << " (2) " << answer_array[1] << " (3) " << answer_array[2] << " (4) " << answer_array[3] << endl;

			// 답을 입력받음.
			int answer_number;
			cin >> answer_number;

			// 잘못된 입력을 방지해주는 block
			if (cin.fail()) {
				cout << "잘못된 입력입니다. 오답으로 처리됩니다." << endl;
				cin.clear();
				cin.ignore();
				continue;
			}
			else {
				cin.ignore();
			}

			// 정답과 오답을 판별함.
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
	
	// 보기를 만들 때,
	// 랜덤한 선택을 하기 위해 srand(time(NULL)) 사용.
	srand(time(NULL));
	Dictionary myDict;

	myDict.showMenu();

	return 0;
}