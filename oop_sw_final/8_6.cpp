#include <iostream>
#include <set> // �ߺ����� �ʾƾ� �ϴ� �����͵��� ������ set�� ����ϸ� �ȴ�.
#include <ctime>

using namespace std;

class Lottery {
private:
	set<int> numbers;

public:
	Lottery() {};
	void pickNumbers() {

		// numbers�� set���� ����Ǿ� �����Ƿ�,
		// insert�� �̿��� ����ؼ� ������ �߰��ϸ�
		// �̹� set�� �� �ִ� ���� �߰����� �ʴ´�.
		while (numbers.size() < 6) {

			int num = 1 + rand() % 45;
			numbers.insert(num);
		}
	}
	void printNumbers() {

		cout << "������ �ζ� ��ȣ : ";
		for (auto i = numbers.begin(); i != numbers.end(); i++) {
			cout << (*i) << " ";
		}
	}
};

int main(void) {

	srand(time(NULL));

	Lottery lottery;
	lottery.pickNumbers();
	lottery.printNumbers();

	return 0;
}