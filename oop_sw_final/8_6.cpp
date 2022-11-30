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

		while (numbers.size() < 6) {

			int num = 1 + rand() % 45;
			numbers.insert(num); // set�̱� ������, insert�� �ص� ��ģ�ٸ� �˾Ƽ� ���� �ʴ´�.
		}
	}
	void printNumbers() {

		cout << "������ �ζ� ��ȣ : ";
		for (auto i = numbers.begin(); i != numbers.end(); i++) {
			cout << (*i) << " ";
		}
		
		// �̿� ����, map�� set�� find�� ����ؼ� �ȿ� �����Ͱ� �ִ��� �Ǵ��� �� �ְ�,
		// ���� �ִٸ� iterator�� ��ȯ, �� iterator�� �������� �����͸� ������ �� ����.
		/*auto it = numbers.find(10);
		if (it == numbers.end()) {
			cout << "null!" << endl;
		}*/
	}
};

int main(void) {

	srand(time(NULL));

	Lottery lottery; // lottery()�� �ϸ� �ȵ�?
	lottery.pickNumbers();
	lottery.printNumbers();

	return 0;
}