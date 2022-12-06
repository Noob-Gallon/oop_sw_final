#include <iostream>
#include <set> // 중복되지 않아야 하는 데이터들의 집합은 set을 사용하면 된다.
#include <ctime>

using namespace std;

class Lottery {
private:
	set<int> numbers;

public:
	Lottery() {};
	void pickNumbers() {

		// numbers가 set으로 선언되어 있으므로,
		// insert를 이용해 계속해서 난수를 추가하면
		// 이미 set에 들어가 있는 값은 추가되지 않는다.
		while (numbers.size() < 6) {

			int num = 1 + rand() % 45;
			numbers.insert(num);
		}
	}
	void printNumbers() {

		cout << "생성된 로또 번호 : ";
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