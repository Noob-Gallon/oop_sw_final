#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int main(void) {

	srand(time(NULL));
	map<string, string> dict;

	string word;
	string meaning;
	int option;
	int question_idx;

	vector<string> answers;

	while (1) {

		cout << " ============================ " << endl;
		cout << " 단어 추가 : 1, 단어 테스트 : 2, 종료 : 3" << endl;
		cout << " ============================ " << endl;
		cout << "하나를 선택하세요. : ";

		cin >> option;

		// int에 문자를 입력하면 cin.fail() 발생...
		// https://m.blog.naver.com/mirageld/150033109587
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			continue;
		}
		else {
			cin.ignore();
		}

		if (option == 1) {
			cout << "추가할 단어 : ";
			getline(cin, word);

			cout << "추가할 의미 : ";
			getline(cin, meaning);
			
			answers.push_back(meaning);
			dict[word] = meaning;
		}
		else if (option == 2) {

			int len = answers.size();
			if (len < 4) {
				
				cout << "네 개 이상의 단어를 입력해야 합니다." << endl;
				continue;
			}
			
			string question[4]; // 문제에 출력될 '의미'를 담아두는 배열.
			string answer; // 정답 '의미' string

			// dict(map)를 key 오름차순으로 탐색한다...
			for (auto i = dict.begin(); i != dict.end(); i++) {
				
				question_idx = 0;

				for (int i = 0; i < 4; i++) {
					
					question[i] = "";
				}

				answer = (*i).second; // 정답을 먼저 선택. (문제의 정답은 key의 오름차순으로 선택되며, '단어'가 아닌 '의미'가 정답임.)
				int answer_idx = rand() % 4; // 정답이 출력될 번호를 먼저 정한다. 1 ~ 4
				question[answer_idx] = answer; // 정답을 먼저 선지로 표현하기 위해 question 배열에 넣어줌.
				// 예를 들어, 정답으로 선택된 idx가 2 라면,
				// question = { "", "", answer, "" }와 같을 것이다.

				// 선택된 정답 이외의 3개의 답을 골라야 한다.
				for (int i = 0; i < 3; i++) {

					int random_idx; // answers 중에서 정답이 아닌 것중 선지로 출력할 것을 선택하기 위한 idx 변수.

					while (1) {

						// random index를 결정한다. 이 변수는 answers[random_idx]로 일단 벡터에서 선지로 아무 의미나 골라본다.
						// 이것을 question 배열에 넣을 수 있는지 없는지 판단해보고,
						// 만약 넣을 수 있다면, question 배열에 추가한다.
						random_idx = rand() % answers.size();

						// 랜덤으로 선택된 '의미'가 현재 선택된 정답과 같으면 continue;
						if (answers[random_idx] == answer) 
						{
							continue;
						}
						// 랜덤으로 고른 것이 현재 정답과 같지 않다면,
						else {

							// 이미 question 배열에 들어간 것인지 체크한다.
							bool already_in_question = false;

							// 선택된 것 answers[random_idx]가 이미 question 배열에
							// 들어가 있는지 비교하고, 이미 들어가있다면 continue;
							for (int j = 0; j < 4; j++) {
								
								// 정답의 index는 비교할 필요 없으므로, 넘겨준다.
								if (j == answer_idx) {
									continue;
								}

								// 만약 현재 선택된 새로운 '의미'가 정답 배열의 특정 원소와 같으면
								// 이미 정답으로 선택된 것이므로, 다른 것을 고른다.
								if (answers[random_idx] == question[j]) {
									already_in_question = true;
									break;
								}
							}

							if (already_in_question == true) {
								continue;
							}
						}
						
						// 여기까지 왔다는 것은 현재 선택된 answers[random_idx]가 
						// question 배열에 추가해도 된다는 것이다.
						// 따라서, 이것을 question 배열에 앞쪽부터 추가해준다.
						break;
					}

					while (1) {
						
						if (question_idx == answer_idx) {
							question_idx++;
							continue;
						}
						
						question[question_idx] = answers[random_idx];
						question_idx++;
						break;
					}
				} // 이 곳을 넘어가면, 정답 이외의 3개의 답이 모두 선택된다.

				cout << "Q. " << (*i).first << "의 의미는?\n";
				cout << "(1) " << question[0] << " (2) " << question[1] << " (3) " << question[2] << " (4) " << question[3] << endl;

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
				
				
				if (question[answer_number - 1] == (*i).second) {
					cout << "정답입니다!\n";
				}
				else {
					cout << "오답입니다!\n";
				}
			}
		}
		else if (option == 3) {
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
	}

	return 0;
}