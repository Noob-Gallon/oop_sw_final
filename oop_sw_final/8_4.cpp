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
		cout << " �ܾ� �߰� : 1, �ܾ� �׽�Ʈ : 2, ���� : 3" << endl;
		cout << " ============================ " << endl;
		cout << "�ϳ��� �����ϼ���. : ";

		cin >> option;

		// int�� ���ڸ� �Է��ϸ� cin.fail() �߻�...
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
			cout << "�߰��� �ܾ� : ";
			getline(cin, word);

			cout << "�߰��� �ǹ� : ";
			getline(cin, meaning);
			
			answers.push_back(meaning);
			dict[word] = meaning;
		}
		else if (option == 2) {

			int len = answers.size();
			if (len < 4) {
				
				cout << "�� �� �̻��� �ܾ �Է��ؾ� �մϴ�." << endl;
				continue;
			}
			
			string question[4]; // ������ ��µ� '�ǹ�'�� ��Ƶδ� �迭.
			string answer; // ���� '�ǹ�' string

			// dict(map)�� key ������������ Ž���Ѵ�...
			for (auto i = dict.begin(); i != dict.end(); i++) {
				
				question_idx = 0;

				for (int i = 0; i < 4; i++) {
					
					question[i] = "";
				}

				answer = (*i).second; // ������ ���� ����. (������ ������ key�� ������������ ���õǸ�, '�ܾ�'�� �ƴ� '�ǹ�'�� ������.)
				int answer_idx = rand() % 4; // ������ ��µ� ��ȣ�� ���� ���Ѵ�. 1 ~ 4
				question[answer_idx] = answer; // ������ ���� ������ ǥ���ϱ� ���� question �迭�� �־���.
				// ���� ���, �������� ���õ� idx�� 2 ���,
				// question = { "", "", answer, "" }�� ���� ���̴�.

				// ���õ� ���� �̿��� 3���� ���� ���� �Ѵ�.
				for (int i = 0; i < 3; i++) {

					int random_idx; // answers �߿��� ������ �ƴ� ���� ������ ����� ���� �����ϱ� ���� idx ����.

					while (1) {

						// random index�� �����Ѵ�. �� ������ answers[random_idx]�� �ϴ� ���Ϳ��� ������ �ƹ� �ǹ̳� ��󺻴�.
						// �̰��� question �迭�� ���� �� �ִ��� ������ �Ǵ��غ���,
						// ���� ���� �� �ִٸ�, question �迭�� �߰��Ѵ�.
						random_idx = rand() % answers.size();

						// �������� ���õ� '�ǹ�'�� ���� ���õ� ����� ������ continue;
						if (answers[random_idx] == answer) 
						{
							continue;
						}
						// �������� �� ���� ���� ����� ���� �ʴٸ�,
						else {

							// �̹� question �迭�� �� ������ üũ�Ѵ�.
							bool already_in_question = false;

							// ���õ� �� answers[random_idx]�� �̹� question �迭��
							// �� �ִ��� ���ϰ�, �̹� ���ִٸ� continue;
							for (int j = 0; j < 4; j++) {
								
								// ������ index�� ���� �ʿ� �����Ƿ�, �Ѱ��ش�.
								if (j == answer_idx) {
									continue;
								}

								// ���� ���� ���õ� ���ο� '�ǹ�'�� ���� �迭�� Ư�� ���ҿ� ������
								// �̹� �������� ���õ� ���̹Ƿ�, �ٸ� ���� ����.
								if (answers[random_idx] == question[j]) {
									already_in_question = true;
									break;
								}
							}

							if (already_in_question == true) {
								continue;
							}
						}
						
						// ������� �Դٴ� ���� ���� ���õ� answers[random_idx]�� 
						// question �迭�� �߰��ص� �ȴٴ� ���̴�.
						// ����, �̰��� question �迭�� ���ʺ��� �߰����ش�.
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
				} // �� ���� �Ѿ��, ���� �̿��� 3���� ���� ��� ���õȴ�.

				cout << "Q. " << (*i).first << "�� �ǹ̴�?\n";
				cout << "(1) " << question[0] << " (2) " << question[1] << " (3) " << question[2] << " (4) " << question[3] << endl;

				int answer_number;
				cin >> answer_number;
				
				if (cin.fail()) {
					cout << "�߸��� �Է��Դϴ�. �������� ó���˴ϴ�." << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
				else {
					cin.ignore();
				}
				
				
				if (question[answer_number - 1] == (*i).second) {
					cout << "�����Դϴ�!\n";
				}
				else {
					cout << "�����Դϴ�!\n";
				}
			}
		}
		else if (option == 3) {
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}

	return 0;
}