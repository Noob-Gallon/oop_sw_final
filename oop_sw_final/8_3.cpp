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

			dict[word] = meaning;
		}
		else if (option == 2) {

			// map�� iterator�� ���ϸ� key�� ������������ ���´�!
			for (auto i = dict.begin(); i != dict.end(); i++) {

				cout << "�ܾ� : " << (*i).first << endl;
				cout << "�ǹ̴� �����Դϱ�? : ";

				string answer;
				getline(cin, answer);

				if ((*i).second == answer) {
					cout << "������ϴ�." << endl;
				}
				else {
					cout << "Ʋ�Ƚ��ϴ�." << endl;
				}
			}
		}
		else if (option == 3) {
			break;
		}
	}

	return 0;
}