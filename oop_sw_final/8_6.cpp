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

		while (numbers.size() < 6) {

			int num = 1 + rand() % 45;
			numbers.insert(num); // set이기 때문에, insert를 해도 겹친다면 알아서 들어가지 않는다.
		}
	}
	void printNumbers() {

		cout << "생성된 로또 번호 : ";
		for (auto i = numbers.begin(); i != numbers.end(); i++) {
			cout << (*i) << " ";
		}
		
		// 이와 같이, map과 set은 find를 사용해서 안에 데이터가 있는지 판단할 수 있고,
		// 만약 있다면 iterator를 반환, 그 iterator를 바탕으로 데이터를 삭제할 수 있음.
		/*auto it = numbers.find(10);
		if (it == numbers.end()) {
			cout << "null!" << endl;
		}*/
	}
};

int main(void) {

	srand(time(NULL));

	Lottery lottery; // lottery()로 하면 안됨?
	lottery.pickNumbers();
	lottery.printNumbers();

	return 0;
}