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

	vector<string> answers;
	vector<int> selected;

	while (1) {

		cout << " ============================ " << endl;
		cout << " �ܾ� �߰� : 1, �ܾ� �׽�Ʈ : 2, ���� : 3" << endl;
		cout << " ============================ " << endl;
		cout << "�ϳ��� �����ϼ���. : ";

		cin >> option;
		cin.ignore();

		if (option == 1) {
			cout << "�߰��� �ܾ� : ";
			getline(cin, word);

			cout << "�߰��� �ǹ� : ";
			getline(cin, meaning);
			
			answers.push_back(meaning);
			selected.push_back(0);
			dict[word] = meaning;
		}
		else if (option == 2) {

			int len = answers.size();
			string answer;

			for (auto i = dict.begin(); i != dict.end(); i++) {

				answer = (*i).second;

				int checked = 0;
				while (1) {
					
					
				}
			}
		}
		else if (option == 3) {
			break;
		}
	}

	return 0;
}