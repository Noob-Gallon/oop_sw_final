#include <iostream>
#include <ctime>

#define INTERVAL 1

using namespace std;

class GameCharacter {
public:
	GameCharacter() {} // 생성자 왜있음?
	virtual void draw() = 0;
};

class Hobbit : public GameCharacter {
public:
	void draw() {
		cout << "호빗을 화면에 그립니다..." << endl;
	}
};

class Socerer : public GameCharacter {
public:
	void draw() {
		cout << "주술사를 화면에 그립니다..." << endl;
	}
};

int main(void) {

	GameCharacter* myCharacters[2];
	
	Hobbit h;
	Socerer s;

	myCharacters[0] = &h;
	myCharacters[1] = &s;
	
	while (1) {

		for (auto& _e : myCharacters) {
			_e->draw();
		}
		
		clock_t start = clock();

		// 주기적으로 호출
		while (1) {
			clock_t end = clock();

			if (double(end - start) / CLOCKS_PER_SEC == INTERVAL) {
				break;
			}
		}
	}

	return 0;
}