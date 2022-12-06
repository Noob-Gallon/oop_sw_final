#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <string>

using namespace std;

// ��� ����� Dictionary class�� �����Ѵ�.
class Dictionary {
private:
	map<string, string> dict; // �ܾ�� �ǹ̸� �߰��� dictionary map
	set<string> questions; // ������ ������ �� ����� ���� ���� �Է��ϴ� set
	vector<string> meanings; 
	// ������ ������ �� �����ϰ� ���⸦ �����ϱ� 
	// ���� �ǹ̸� �̸� ��Ƶδ� vector
	bool operating = true;

public:
	Dictionary() {}

	// ó�� main���� ����Ǵ� �޼���.
	// ���ѷ����� ���� ����ڷκ��� �Է��� �޴´�.
	void showMenu() {

		while (operating) {

			cout << " ============================ " << endl;
			cout << " �ܾ� �߰� : 1, �ܾ� �׽�Ʈ : 2, ���� : 3" << endl;
			cout << " ============================ " << endl;
			cout << "�ϳ��� �����ϼ���. : ";

			int in;
			cin >> in;

			// ����ڰ� �߸��� �Է��� �ִ´ٸ�
			// ���� �Է��� �����ϵ��� block�Ѵ�.
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				continue;
			}
			else {
				// �ùٸ� �Է��� �־����ٸ�,
				// �Է� ���ۿ��� \n�� �����ϱ� ����
				// cin.ignore()
				cin.ignore();
			}

			// switch�� �̿��� ������� �Է��� �Ǻ��Ѵ�.
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
				cout << "�߸��� �Է��Դϴ�." << endl;
			}
		} 
	}

	// ����ڷκ��� �Է¹޾�
	// ������ �ܾ�� �ǹ̸� �߰��Ѵ�.
	void addWord() {

		string word;
		string meaning;

		cout << "�߰��� �ܾ� : ";
		getline(cin, word);

		cout << "�߰��� �ǹ� : ";
		getline(cin, meaning);

		meanings.push_back(meaning); // ���߿� ���� ����� ���� �ǹ� ����
		dict[word] = meaning; // ������ key : word, value : meaning���� �ܾ� ����.
	}
	void wordTest() {

		if (meanings.size() < 4) {
			cout << "�ܾ �� �� �̻� �Է��ϰ� �ٽ� �õ��Ͻʽÿ�." << endl;
			return;
		}

		string answer; // ���� '�ǹ�' string

		// dict(map)�� key ������������ Ž���Ѵ�...
		for (auto i = dict.begin(); i != dict.end(); i++) {

			// ������ �� ���� �����ϱ� ����
			// set�� clear()�Ѵ�.
			questions.clear();

			answer = (*i).second; // ������ ���� ����. (������ ������ key�� ������������ ���õǸ�, '�ܾ�'�� �ƴ� '�ǹ�'�� ������.)
			questions.insert(answer); // ����� ��µ� ������ ���� set�� �־�д�.

			while (questions.size() < 4) {

				int random_idx = rand() % meanings.size(); // answers �߿��� ������ �ƴ� �͵� �� ������ ����� ���� �����ϱ� ���� idx ����.
				questions.insert(meanings[random_idx]); // set���� �����ϱ� ������, �ߺ��Ǿ� ���õȴٸ� �߰����� �ʰ� �׳� �Ѿ��.
				// �� ���� ���� �ٸ� ���Ⱑ ���õ� ������ while���� �����Ѵ�.
			} // �̰��� �Ѿ��, ���� �̿��� 3���� ���� ��� ���õȴ�.

			// ����� ���ϰ� �ϱ� ���� string �迭�� �����ϰ�
			// set���� ���� �Ű���.
			string answer_array[4];
			int idx = 0;

			for (auto j = questions.begin(); j != questions.end(); j++) {
				answer_array[idx] = (*j);
				idx++;
			}

			// ���� ���
			cout << "Q. " << (*i).first << "�� �ǹ̴�?\n";
			cout << "(1) " << answer_array[0] << " (2) " << answer_array[1] << " (3) " << answer_array[2] << " (4) " << answer_array[3] << endl;

			// ���� �Է¹���.
			int answer_number;
			cin >> answer_number;

			// �߸��� �Է��� �������ִ� block
			if (cin.fail()) {
				cout << "�߸��� �Է��Դϴ�. �������� ó���˴ϴ�." << endl;
				cin.clear();
				cin.ignore();
				continue;
			}
			else {
				cin.ignore();
			}

			// ����� ������ �Ǻ���.
			if (answer_array[answer_number - 1] == answer) {
				cout << "�����Դϴ�!\n";
			}
			else {
				cout << "�����Դϴ�!\n";
			}
		}
	}
};

int main(void) {
	
	// ���⸦ ���� ��,
	// ������ ������ �ϱ� ���� srand(time(NULL)) ���.
	srand(time(NULL));
	Dictionary myDict;

	myDict.showMenu();

	return 0;
}